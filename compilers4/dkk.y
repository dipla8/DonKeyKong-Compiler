%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "dkk.tab.h"


extern int yylineno;
int yylex(void);
void dfs_post_order(const asd_t *node);
static void print_tree_rec(const asd_t *node, const char *prefix, int is_left);
asd_t *create_node(const char *s, asd_t *lleaf, asd_t *rleaf);
char *print_ir(const asd_t *root);
void print_tree(const asd_t *root);
void yyerror(const char *s);
int scope = 0;
int dim_count = 0;
HASHTBL *symtb;
HASHTBL *currtb;
int currvis;
id_list_t *deflist = NULL;	// necessary for int a,b=a;
struct hashnode_s *currclass = NULL;
int stride= 1;
int reg = 0;
int label_count = 0;
char *lastname = NULL;
FILE *fd = NULL;
%}

%token TYPEDEF CHAR INT FLOAT CONST UNION CLASS PRIVATE PROTECTED PUBLIC
STATIC VOID LIST CONTINUE BREAK THIS IF ELSE WHILE FOR RETURN LENGTH
NEW CIN COUT MAIN FCONST CCONST OROP ANDOP NOTOP SIZEOP LPAREN RPAREN
SEMI DOT COMMA ASSIGN COLON LBRACK RBRACK REFER LBRACE RBRACE METH INP OUT

%left COMMA
%left ASSIGN
%left OROP
%left ANDOP
%left NOTOP
%left EQUOP
%left RELOP
%left ADDOP
%left MULOP
%nonassoc SIZEOP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left INCDEC DOT LBRACK RBRACK LPAR RPAR

%union{ 
       	int ival;
	float fval;
	char cval;
	short int oper;
	char *str;
	my_id_t *id;
	expr_t myexpr;
	type_t type;
	id_list_t *idlist;
	array_t *arr;
	header_t myhdr;
	par_list_t *par_list;
	expr_list_t *myexprlist;
	struct hashnode_s *node;
}
%token <oper> ADDOP EQUOP RELOP MULOP INCDEC
%token <ival> ICONST
%token <str> ID STRING LISTFUNC
%type <ival> init_value init_values initializer
%type <myexpr> expression constant assignment variable
%type <myexprlist> expression_list listexpression general_expression
%type <id> variabledef init_variabledef pass_variabledef 
%type <idlist> variabledefs init_variabledefs parameter_list
%type <node> class_func_header_start
%type <par_list> parameter_types
%type <arr> dims pass_list_dims
%type <str> standard_type typename class_body parent func_class
%type <myhdr> func_header_start nopar_func_header 
%%
program: global_declarations main_function {exit(0);};
global_declarations: global_declarations global_declaration | ;
global_declaration : typedef_declaration
	| const_declaration
	| class_declaration
	| union_declaration
	| global_var_declaration
	| func_declaration;
typedef_declaration : TYPEDEF typename listspec ID {dim_count = 0;} dims SEMI {hashtbl_insert(symtb, $4, $2 , scope, $6, 1, currvis);} // scope is always 0
typename : standard_type {$$ = $1;}
		| ID {struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1, currvis); if(p == NULL || p->istype == 0) yyerror("Type doesn't exist."); {$$ = p->key;}};
standard_type : CHAR {$$="char";}
		| INT {$$="int";}
		| FLOAT {$$="float";}
		| VOID {$$="void";};
listspec : LIST | ;
dims : dims LBRACK ICONST RBRACK {
		if (dim_count == MAX_DIMENSIONS) {
			//ERROR
			yyerror("Exceeded maximum array dimensions.");
			if ($1) free($1);
		}
		else if (dim_count == 0) {
			$$ = malloc(sizeof(array_t));
			if (!$$) {
				printf("Memory allocation error\n");
				exit(1);
			}
			if ($3 <= 0) {
				yyerror("Array dimension must be positive integer.");
				free($$);
				exit(1);
			}
			$$->dim_size[0] = $3;
			$$->dims = 1;
			dim_count++;
		}
		else {
			$1->dim_size[dim_count] = $3;
			$1->dims++;
			$$ = $1;
			dim_count++;
		}
	}
	| dims LBRACK RBRACK {
		if (dim_count == MAX_DIMENSIONS) {
			yyerror("Exceeded maximum array dimensions.");
			if ($1) free($1);
		}
		else if (dim_count == 0) {
			$$ = malloc(sizeof(array_t));
			$$->dim_size[0] = MAX_DIMENSIONS;
			$$->dims++;
			dim_count++;
		}
		else {
			$1->dim_size[dim_count] = MAX_DIMENSIONS;
			$1->dims++;
			$$ = $1;
			dim_count++;
		}
	}
    | {$$ = NULL;}
	;
const_declaration : CONST typename constdefs SEMI;
constdefs : constdefs COMMA constdef | constdef;
constdef : ID dims ASSIGN init_value;

expression : expression OROP expression { if (($1.type == T_INT) && ($3.type == T_INT))
   					  	$$.type = $1.type;
					  else	yyerror("Wrong expression type.");
				      	$$.node = create_node("||", $1.node, $3.node);
					}
	| expression ANDOP expression { if (($1.type == T_INT) && ($3.type == T_INT))
   					  	$$.type = $1.type;
					  else yyerror("Wrong expression type.");
				      	$$.node = create_node("&&", $1.node, $3.node);
				      }
	| expression EQUOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR))
						$$.type = T_INT;
					else yyerror("Wrong expression type.");
				      	if($2 == 0)$$.node = create_node("==", $1.node, $3.node);
				      	else $$.node = create_node("!=", $1.node, $3.node);
				      }
	| expression RELOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR))
						$$.type = T_INT;
					else yyerror("Wrong expression type.");
				      	if($2 == 0)$$.node = create_node(">", $1.node, $3.node);
				      	else if($2 == 1)$$.node = create_node(">=", $1.node, $3.node);
				      	else if($2 == 2)$$.node = create_node("<", $1.node, $3.node);
				      	else $$.node = create_node("<=", $1.node, $3.node);
				      }
	| expression ADDOP expression {if($1.type == T_INT && $3.type == T_INT)
						$$.type = T_INT;
					else if (($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT))
						$$.type = T_FLOAT;
					else yyerror("Wrong expression type.");
					$$.val.ival = $1.val.ival + $3.val.ival;
					if($2 == 0) $$.node = create_node("+", $1.node, $3.node);
					else $$.node = create_node("-", $1.node, $3.node);
				      }
	| expression MULOP expression {if($1.type == T_INT && $3.type == T_INT)
						$$.type = T_INT;
					else if ((($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT)))
						$$.type = T_FLOAT;
					else yyerror("Wrong expression type.");
				      	if($2 == 0)$$.node = create_node("*", $1.node, $3.node);
				      	else if($2 == 1)$$.node = create_node("/", $1.node, $3.node);
				      	else $$.node = create_node("%", $1.node, $3.node);
				      }
	| NOTOP expression { if ($2.type != T_INT) yyerror("Wrong expression type.");
	                     else $$.type = $2.type;
			     $$.node = create_node("!", $2.node, NULL);
	                   }
	| ADDOP expression { if (($2.type != T_INT) || ($2.type != T_FLOAT)) yyerror("Wrong expression type.");
			     	$$.type = $2.type;
				$$.val = $2.val;
			     	if($1 == 1)
					if($2.type == T_INT)
						$$.val.ival = ($2.val.ival * (-1));	
					if($2.type == T_INT)
						$$.val.fval = ($2.val.fval * (-1));
				if($1 == 0) $$.node = create_node("+", $2.node, NULL);
				else $$.node = create_node("-", $2.node, NULL);
			   }
	| SIZEOP expression {$$.type = T_INT; $$.val.ival = 0; $$.node = create_node("sizeof", $2.node, NULL);}
	| INCDEC variable {$$ = $2; if($1 == 0) $$.node = create_node("++", $2.node, NULL);
				      	else $$.node = create_node("--", $2.node, NULL);}
	| variable INCDEC {$$ = $1; if($2 == 0)$$.node = create_node("++", $1.node, NULL);
				      	else $$.node = create_node("--", $1.node, NULL);}
	| variable {$$ = $1;}
	| variable LPAREN expression_list RPAREN {$$ = $1;
							 if($1.n->func != NULL){
							struct hashnode_s *n = hashtbl_lookup(currtb, scope, $1.n->key, currvis);
							if(n == NULL)
								yyerror("Variable doesn't exist.");
							if(n->func != NULL){
							par_list_t *p1 = n->func->node;
							expr_list_t *p2 = $3;
							while(p1!=NULL && p2!=NULL){
								if(strcmp(p1->type,p2->exp->n->data))
									yyerror("Parameter type mismatch.");
								p1=p1->next; p2=p2->next;
							}
							if(p1 != NULL || p2!=NULL)
								yyerror("Parameter cardinality mismatch.");
							}
							else if($3 != NULL)
								printf("semantic error\n");
						}else if(strcmp($1.n->data, "func"))yyerror("Variable is not a function.");}
	| LENGTH LPAREN general_expression RPAREN
	| NEW LPAREN general_expression RPAREN
	| constant {$$.type = $1.type; $$.val = $1.val; $$.n = malloc(sizeof(expr_t)); $$.n->arr = malloc(sizeof(array_t)); $$.n->arr->dims = 0; $$.rec_count = 0;if($1.type == T_CHAR) $$.n->data = strdup("char"); else if($1.type == T_INT) $$.n->data = strdup("int"); else if($1.type == T_FLOAT) $$.n->data = strdup("float"); $$.node = create_node("const", NULL, NULL);}
	| LPAREN general_expression RPAREN
	| LPAREN standard_type RPAREN
	| listexpression {$$.type = $1->exp->type; $$.val.ival = $1->listsize; $$.rec_count = 0; $$.n = NULL;};
variable : variable LBRACK general_expression RBRACK {
							if($3->exp->type != T_INT ||($3->exp->n->arr != NULL) && ($3->exp->rec_count != $3->exp->n->arr->dims))
								yyerror("Wrong array indexing.");
							else{
								if($1.rec_count > $1.n->arr->dims)
						 	    	 	yyerror("Dimensions exceed declared dimensions.");
								else if($3->exp->val.ival <0 || $3->exp->val.ival >= $1.n->arr->dim_size[$1.rec_count]){
									yyerror("Incorrect dimension indexing.");}
							     	else {
									if($3->exp->rec_count != $3->exp->n->arr->dims)
										yyerror("Wrong array indexing.");
									if(stride == 1){
										for(int i = 1; i < $1.n->arr->dims; i++){
											stride = stride * $1.n->arr->dim_size[i];
										}
										$$.val.ival = $3->exp->val.ival * stride;
										$$.rec_count = $1.rec_count+1;
										$$.n = $1.n;}
									else{
									stride = stride / $1.n->arr->dim_size[$1.rec_count];
									$$.val.ival = $1.val.ival + $3->exp->val.ival * stride;
									$$.rec_count = $1.rec_count+1;
									$$.type = $1.type;
									$$.n = $1.n;}
								}
							}
					} // matrix
	| variable DOT ID {if($1.n == NULL) yyerror("Variable doesn't exist.");
			    struct hashnode_s *p=$1.n;
                            if ($1.n->un != NULL) {	
				if (hashtbl_lookup(p->un->untb, scope, $3, currvis) == NULL) 
					yyerror("Union field doesn't exist");
			    }
			    else if ($1.n->cla != NULL) {
				int currvis = 2; // INITIALLY, PERMISSION = 2
				while(p!=NULL && p->cla!=NULL && hashtbl_lookup(p->cla->classtb, scope, $3, currvis) == NULL){
					if(p!=NULL && p->cla!=NULL && p->cla->superclass == NULL)
						yyerror("Class member doesn't exist.");
					currvis = 1;
					p = hashtbl_lookup(currtb, scope, p->cla->superclass, 0);
				}
				p = hashtbl_lookup($1.n->cla->classtb, scope, $3, currvis);
			   	currtb = $1.n->cla->classtb;
				$$.n = p;
			    }
			    else 
				yyerror("Variable is not class or union.");
			$$.rec_count = 0;
			$$.val.ival =0;
			if(p == NULL)
				p = malloc(sizeof(struct hashnode_s));
			if(p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
				$$.n = p;
			}
			}// class and unions
	| LISTFUNC LPAREN general_expression RPAREN {char *ptr = $1; int count = 0;
							if($3->exp->n == NULL || $3->exp->n->arr == NULL ||$3->exp->n->arr->islist == 0)
								yyerror("Parameter is not list.");
							if($3->exp->rec_count != $3->exp->n->arr->dims)
								yyerror("Incorrect dimension indexing.");
							else{
							while ((ptr = strchr(ptr, 'd')) != NULL) {
								count++;
								ptr++;
    						    	}
								if($3->exp->n->arr->listsize[$3->exp->val.ival] < count+1)
									yyerror("List indexing exceeds limits");
							}
							$$.n = $3->exp->n;
							$$.val.ival = 1;
							$$.type = $3->exp->type;
						} // list
	| decltype ID {struct hashnode_s *p= hashtbl_lookup(currtb, scope, $2, currvis);
			if(p== NULL && deflist == NULL)
				yyerror("Variable doesn't exist.");
			else if(p == NULL && deflist != NULL){
				id_list_t *curr = deflist;
				$$.n = NULL;
				while (curr) {
					if(strcmp(curr->id->id, yylval.str))
						curr=curr->next;
					else{
						$$.rec_count = 0;
						$$.n = malloc(sizeof(struct hashnode_s));
						$$.n->data = curr->id->data;
						if(curr->id->arr == NULL){
							$$.n->arr = malloc(sizeof(array_t));
							$$.n->arr->dims = 0;
						}
						$$.n->arr = curr->id->arr;
						$$.n->key = curr->id->id;
						curr = NULL;
					}
				}
				if($$.n == NULL)
					yyerror("Variable doesn't exist.");
			}
			else{
				$$.rec_count = 0;
			 	$$.n = p;
				if(!strcmp(p->data, "char"))
					$$.type = T_CHAR;
				else if(!strcmp(p->data, "int"))
					$$.type = T_INT;
				else if(!strcmp(p->data, "float"))
					$$.type = T_FLOAT;
				else if(!strcmp(p->data, "void"))
					$$.type = T_VOID;
				else $$.type = T_ID;
			}
			if(p!=NULL && p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
			}
		$$.node = create_node($2, NULL, NULL);
		}
	| THIS {$$.rec_count = 0; $$.val.ival = 0; $$.n = currclass; $$.type = T_ID;}; // class
general_expression : general_expression COMMA general_expression {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = $3->exp; k->next =$1; k->listsize = $1->listsize+$3->listsize; $$ = k;}
	| assignment{expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = malloc(sizeof(expr_t));k->exp->type = $1.type; k->exp->val = $1.val; k->exp->rec_count = $1.rec_count; k->exp->n = $1.n; k->next =  NULL;  k->listsize = 1;$$ = k; $$->exp->node = $1.node; print_tree($1.node); reg = 0; print_ir($1.node);};
assignment : variable ASSIGN assignment {if($1.rec_count != $1.n->arr->dims) yyerror("Incorrect dimension indexing."); if($1.type != $3.type) yyerror("Type mismatch.");
					if($1.n->arr->islist)
						$1.n->arr->listsize[$1.val.ival] = $3.val.ival; 
					$$.node = create_node("=", $1.node, $3.node);
					}	
   	   | variable ASSIGN STRING 
	| expression {$$ = $1;};
expression_list : general_expression {$$ = $1;} | {$$ = NULL;};
constant : CCONST {$$.type = T_CHAR; $$.val.cval = yylval.cval;}
	| ICONST {$$.type = T_INT; $$.val.ival = yylval.ival;}
	| FCONST {$$.type = T_FLOAT; $$.val.fval = yylval.fval;};
listexpression : LBRACK expression_list RBRACK {$$ = $2;};
class_declaration : CLASS ID {hashtbl_insert(symtb, $2, "class", scope, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, currvis); currtb = p->cla->classtb; scope++;}class_body SEMI {scope--;struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, currvis); p->cla->superclass = $4;currtb = symtb; currvis = 0;};
class_body : parent LBRACE members_methods RBRACE {$$ = $1;};
parent : COLON ID {$$ = $2;}|  {$$ = NULL;};
members_methods : members_methods access member_or_method | access member_or_method;
access : PRIVATE COLON {currvis = 2;}| PROTECTED COLON {currvis = 1;} | PUBLIC COLON {currvis = 0;} | ;
member_or_method : member
	| method;
member : var_declaration
	| anonymous_union;
var_declaration : typename variabledefs SEMI {var_decl($2, $1);};
variabledefs : variabledefs COMMA variabledef {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = $3;
          n->next = $1;
          $$ = n;
      }
	| variabledef {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = $1;
          n->next = NULL;
          $$ = n;
      };
variabledef : LIST ID {dim_count = 0;} dims {	$$ = malloc(sizeof(id_t)); $$->id = $2;
						if($4 == NULL){
							$$->arr = malloc(sizeof(array_t));
							$$->arr->dims = 0;
						}
						else $$->arr = $4;
						$$->arr->islist = 1; int totalsize=1;
						for(int i = 0; i < $$->arr->dims; i++)
							totalsize = totalsize * $$->arr->dim_size[i];
						$$->arr->listsize = calloc(totalsize, sizeof(int));}
	| ID {dim_count = 0;} dims {
		$$ = malloc(sizeof(id_t));
		$$->id = $1;
		$$->arr = $3;
	};
anonymous_union : UNION union_body SEMI;
union_body : LBRACE fields RBRACE;
fields : fields field | field;
field : var_declaration;
method : short_func_declaration;
short_func_declaration : short_par_func_header SEMI | nopar_func_header SEMI{ struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
									  if (p != NULL) yyerror("Double header declaration");
									  else {
									  	hashtbl_insert(currtb, $1.name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, $1.name, currvis);
										p->func->ret_type = $1.type;			
										p->func->header_declared = 0;
										p->func->node = NULL;
									  }
									};
short_par_func_header : func_header_start LPAREN parameter_types RPAREN {struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
									  if (p != NULL) yyerror("Double header declaration");
									  else { 
										hashtbl_insert(currtb, $1.name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, $1.name, currvis);
										p->func->ret_type = $1.type;			
										p->func->header_declared = 0;
										p->func->node = $3;
									  }};
func_header_start : typename ID {$$.type = $1; $$.name = $2;} | LIST ID;
parameter_types : parameter_types COMMA typename pass_list_dims{
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = $3;
		n->next = $1;
		n->arr = $4;
		$$ = n; }
		| typename pass_list_dims {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = $1;
		n->next = NULL;
		n->arr = $2;
		$$= n;
		};
pass_list_dims : listspec dims {$$ = $2;} | REFER {array_t *n = malloc(sizeof(array_t)); n->dims = -1; $$ = n;};
nopar_func_header : func_header_start LPAREN RPAREN {$$=$1;};
union_declaration : UNION ID {hashtbl_insert(symtb, $2, "union", 0, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, 0); currtb = p->un->untb;} union_body SEMI {currtb = symtb;};
global_var_declaration : typename init_variabledefs SEMI {var_decl($2, $1); deflist = NULL;};
init_variabledefs : init_variabledefs COMMA init_variabledef  {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = $3;
         		 n->next = $1;
         		 $$ = n;
			deflist = n;
      			}
				| init_variabledef{
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = $1;
					n->next = NULL;
					$$ = n;
					deflist = n;
				};

init_variabledef : variabledef initializer {int p=1; for(int i=0;($1!=NULL && $1->arr!=NULL && i<$1->arr->dims); i++) p = p * $1->arr->dim_size[i]; if((($1!=NULL)&&($1->data!=NULL)&&(!strcmp($1->data,"char"))&&($1->arr!=NULL)&& p==$2)||p<$2) yyerror("Wrong Initialization.");};
initializer : ASSIGN {dim_count=0;} init_value {$$ = $3;} | {$$=0;};
init_value : expression {$$ = 1;}
        | LBRACE init_values RBRACE {$$ = $2;}
        | STRING {$$=strlen($1);};
init_values : init_values COMMA init_value {$$ = $1 + $3;}
                | init_value {$$= $1;}; 
func_declaration : short_func_declaration | full_func_declaration;
full_func_declaration : full_par_func_header {scope++;} LBRACE decl_statements RBRACE {currclass = NULL;hashtbl_get(currtb, scope); scope--;}
		| nopar_class_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(currtb, scope);scope--;}
		| nopar_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(currtb, scope);scope--;};
full_par_func_header : class_func_header_start LPAREN parameter_list RPAREN { struct hashnode_s *p = $1;
								   if(strcmp(p->data, "func")) yyerror("Class member not a method.");
								   if (p != NULL && p->istype == 0) yyerror("Class method already declared.");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									id_list_t *n = $3;
									par_list_t *s = p->func->node;
									while(s && n) {
										if(!(n->id->arr==NULL && s->arr==NULL) && !(n->id->arr == NULL || s->arr == NULL) && (n->id->arr->dims != s->arr->dims))
											yyerror("Function parameter mismatch.");
										else if(n->id->arr!=NULL && s->arr !=NULL)for (int i= 0; i < s->arr->dims; i++) if(n->id->arr->dim_size[i] != s->arr->dim_size[i]) yyerror("Function parameter mismatch.");
										if(strcmp(s->type,n->id->data)) {
											yyerror("Function parameter type mismatch.");
											break;
										}else{
											s = s->next;
											n = n->next;
										}	
									}
									if (s != NULL || n != NULL) yyerror("Function parameter mismatch.");
									else
									p->func->header_declared = 1;
									scope++;
									var_decl($3, $3->id->data);
									scope--;
									currtb = symtb;
								   }
								   else yyerror("Class method incorrectly declared.");}
		| func_header_start LPAREN parameter_list RPAREN { struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, 0);
								   if((p!=NULL) && strcmp(p->data, "func")) yyerror("Variable is not a function.");
								   if (p != NULL && p->istype == 0) yyerror("Function already declared.");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									//check if params are correct 
									id_list_t *n = $3;
									par_list_t *s = p->func->node;
									while(s && n) {
										if(!(n->id->arr==NULL&& s->arr==NULL) && !(n->id->arr == NULL || s->arr == NULL) && (n->id->arr->dims != s->arr->dims))
											yyerror("Function parameter mismatch.");
										else if(n->id->arr!=NULL && s->arr !=NULL)for (int i= 0; i < s->arr->dims; i++) if(n->id->arr->dim_size[i] != s->arr->dim_size[i]) yyerror("Function parameter mismatch.");
										if(strcmp(s->type,n->id->data)) {
											yyerror("Function parameter type mismatch.");
											break;
										}else{
											s = s->next;
											n = n->next;
										}	
									}
									if (s != NULL || n != NULL) yyerror("Function parameter mismatch.");
									else
									p->func->header_declared = 1;
									scope++;
									var_decl($3, $3->id->data);
									scope--;
								   }
								   else if (p == NULL) {
									hashtbl_insert(currtb, $1.name, "func", scope, NULL, 0, currvis);
									p = hashtbl_lookup(currtb, scope, $1.name, 0);
									p->func->ret_type = $1.type;
									p->func->header_declared = 1;
									id_list_t *n = $3;
									par_list_t *p2, *prev = NULL;
									par_list_t *head = NULL;
									par_list_t *tail = NULL;
									while (n) {
									    p2 = malloc(sizeof(par_list_t));
									    p2->type = n->id->data;
									    p2->next = NULL;
									    if (!head) {
									        head = p2;
										tail = p2;
									    } else {
									        tail->next = p2;
									        tail = p2;
									    }
									    n = n->next;
									}
									p->func->node = head;
									scope++;
									var_decl($3, $3->id->data);
									scope--;
								  }
								 };
class_func_header_start : typename func_class ID {struct hashnode_s *p =hashtbl_lookup(currtb, scope, $2, currvis); currclass = p; if(p==NULL) yyerror("Class doesn't exist."); if((p = hashtbl_lookup(p->cla->classtb, 55555, $3, currvis)) == NULL) yyerror("Method doesn't exist."); if(strcmp(p->func->ret_type, $1)) yyerror("Method type mismatch."); if(strcmp(p->data, "func")) yyerror("Member is not a method."); $$ = p;}
		| LIST func_class ID;
func_class : ID METH {$$ = $1;};
parameter_list : parameter_list COMMA typename pass_variabledef {
		id_list_t* n = malloc(sizeof(id_list_t));
                n->id = $4;
		n->id->data = $3;
                n->next = $1;
                $$ = n;
                }

		| typename pass_variabledef {
		id_list_t* n = malloc(sizeof(id_list_t));
		n->id = $2;
		n->id->data = $1;
		n->next = NULL;
		$$ = n;
		};
pass_variabledef : variabledef {$$ = $1;} | REFER ID {
		$$ = malloc(sizeof(id_t));
		$$->id = $2;
		$$->arr = malloc(sizeof(array_t));	
		$$->arr->dims = -1;	/* this is how you tell it that it's a reference*/};
nopar_class_func_header : class_func_header_start LPAREN RPAREN {if($1->func != NULL) yyerror("Function header mismatch");};
decl_statements : declarations statements
		| declarations
		| statements | ;
declarations : declarations decltype typename variabledefs SEMI { var_decl($4, $3);}
		| decltype typename variabledefs SEMI{ var_decl($3, $2);};
decltype : STATIC | ;
statements : statements statement | statement;
statement : expression_statement
	| if_statement
	| while_statement
	| for_statement
	| return_statement
	| io_statement
	| comp_statement
	| CONTINUE SEMI
	| BREAK SEMI
	| SEMI {currtb = symtb;};
expression_statement : general_expression SEMI {currtb = symtb;};
if_statement : IF LPAREN general_expression if_mid RPAREN statement %prec LOWER_THAN_ELSE{fprintf(fd, "L%d:\n", label_count);} 
		|IF LPAREN general_expression if_mid RPAREN statement ELSE statement;
if_mid: {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);};
while_statement : WHILE LPAREN {fprintf(fd, "L%d:\n", ++label_count); scope++;} general_expression {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);} RPAREN statement {scope--; fprintf(fd, "goto,\t,\t,\tL%d\n", label_count-1); fprintf(fd, "L%d:\n", label_count);};
for_statement : FOR LPAREN optexpr SEMI optexpr SEMI optexpr RPAREN statement;
optexpr : general_expression | ;
return_statement : RETURN optexpr SEMI;
io_statement : CIN INP in_list SEMI | COUT OUT out_list SEMI;
in_list : in_list INP in_item | in_item;
in_item : variable;
out_list: out_list OUT out_item | out_item
out_item: general_expression | STRING;
comp_statement: LBRACE{scope++;} decl_statements {hashtbl_get(currtb, scope);scope--;}RBRACE;
main_function: main_header {header_decl_check(currtb); scope++;} LBRACE decl_statements RBRACE {scope--; hashtbl_get(currtb, scope);};
main_header: INT MAIN LPAREN RPAREN; 
%%

void header_decl_check(HASHTBL *hashtbl) {
	hash_size i;
	struct hashnode_s *node, *old;
	for (i = 0; i < hashtbl->size; ++i) {
		node = hashtbl->nodes[i];
		while(node) {
			if(!strcmp(node->data, "func") && (node->func->header_declared == 0))
				yyerror("Function header without declaration.");
			else node = node->next;
	}}}
void var_decl(id_list_t *var_list, char *data) {
	id_list_t *curr = var_list, *prv = var_list;
	while (curr) {
		printf("str = %s\n", curr->id->id);
		struct hashnode_s *p = hashtbl_lookup(currtb, scope, curr->id->id, 0);
		if(p != NULL && p->scope == scope)
			yyerror("Variable double declaration.");
		else {hashtbl_insert(currtb, curr->id->id, data, scope, curr->id->arr, 0, currvis);printf("data = %s, key = %s\n", data, curr->id->id);}
		curr = curr->next;
		prv = curr;
	}
}

void yyerror(const char *s){
	printf("error: %s in line: %d\n", s, yylineno);
	exit(255);
}
static void print_tree_rec(const asd_t *node, const char *prefix, int is_left){
    if (!node) return;
    /* Print current node */
    printf("%s", prefix);
    printf(is_left ? "├── " : "└── ");
    printf("%s\n", node->name ? node->name : "(null)");
    /* Prepare prefix for children */
    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s",
             prefix,
             is_left ? "│   " : "    ");
    /* Recurse: left first, then right */
    if (node->lchild || node->rchild) {
        if (node->lchild)
            print_tree_rec(node->lchild, new_prefix, 1);
        if (node->rchild)
            print_tree_rec(node->rchild, new_prefix, 0);
    }
}

void print_tree(const asd_t *root){	
    if (!root) {
        printf("(empty tree)\n");
        return;
    }
    /* Root is printed without branches */
    printf("%s\n", root->name ? root->name : "(null)");

    if (root->lchild)
        print_tree_rec(root->lchild, "", 1);
    if (root->rchild)
        print_tree_rec(root->rchild, "", 0);
}

asd_t *create_node(const char *s, asd_t *lleaf, asd_t *rleaf) {
	asd_t *node = malloc(sizeof(asd_t));

	node->name = malloc(strlen(s) + 1);
	strcpy(node->name, s);

	node->lchild = lleaf;
	node->rchild = rleaf;

	return node;
}
char *print_ir(const asd_t *root) {
    if (!root) return NULL;

    if (root->lchild == NULL && root->rchild == NULL) {
        char *name = malloc(sizeof(char) * (strlen(root->name) + 1));
        strcpy(name, root->name);
	lastname = name;
        return name;
    }

    char *lname = print_ir(root->lchild);
    char *rname = print_ir(root->rchild);

    if (!lname && rname) {
        fprintf(fd, "%s,\t,\t%s,%s\n", root->name, rname, rname);
	lastname = lname;
	return NULL;
    }
    else if(lname && !rname) {
        fprintf(fd, "%s,\t%s,\t,\t%s\n", root->name, lname, lname);
	lastname = lname;
	return NULL;
    }
    else if (!strcmp(root->name, "=")) {
        printf("%s %s %s\n", lname, root->name, rname);
        fprintf(fd, "=,\t%s,\t-,\t%s\n", rname, lname);
	lastname = lname;
        return NULL;
    }
    else {
        printf("%s %s %s => t%d\n", lname, root->name, rname, reg);
    }

    reg++;
    char *name = malloc(sizeof(char) * 10);
    sprintf(name, "t%d", reg - 1);
    fprintf(fd, "%s,\t%s,\t%s,\t%s\n", root->name, lname, rname, name);
    lastname = name;
    return name;
}
int main(){
	fd = fopen("ir.dkk", "w");
	symtb = hashtbl_create(10, NULL);
	currtb = symtb;
	return yyparse();
	hashtbl_destroy(symtb);
	fclose(fd);
}
