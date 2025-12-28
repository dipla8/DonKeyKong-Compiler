%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "dkk.tab.h"



int yylex(void);
void yyerror(const char *s);
int scope = 0;
int dim_count = 0;
HASHTBL *symtb;
HASHTBL *currtb;
int currvis;
id_list_t *deflist = NULL; //necessary for int a,b=a;
%}

%token TYPEDEF CHAR INT FLOAT CONST UNION CLASS PRIVATE PROTECTED PUBLIC
STATIC VOID LIST CONTINUE BREAK THIS IF ELSE WHILE FOR RETURN LENGTH
NEW CIN COUT MAIN FCONST CCONST OROP ANDOP EQUOP RELOP MULOP NOTOP INCDEC
SIZEOP LISTFUNC LPAREN RPAREN SEMI DOT COMMA ASSIGN COLON LBRACK RBRACK REFER
LBRACE RBRACE METH INP OUT

%nonassoc EQUOP RELOP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left COMMA
%left OROP ANDOP NOTOP
%left ADDOP
%left MULOP
%left SIZEOP

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
	var_t myvar;
	header_t myhdr;
	par_list_t *par_list;
	expr_list_t *myexprlist;
}
%token <oper> ADDOP
%token <ival> ICONST
%token <str> ID STRING
%type <ival> init_value init_values initializer
%type <myexpr> expression constant assignment
%type <myexprlist> expression_list general_expression
%type <id> variabledef init_variabledef pass_variabledef
%type <idlist> variabledefs init_variabledefs parameter_list
%type <par_list> parameter_types
%type <arr> dims
%type <myvar> variable
%type <str> standard_type typename class_body parent func_class
%type <myhdr> func_header_start nopar_func_header class_func_header_start
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
		| ID {struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1, currvis); if(p == NULL || p->istype == 0) printf("semantic error\n");else{$$ = p->key;}};
standard_type : CHAR {$$="char";}
		| INT {$$="int";}
		| FLOAT {$$="float";}
		| VOID {$$="void";};
listspec : LIST | ;
dims : dims LBRACK ICONST RBRACK {
		if (dim_count == MAX_DIMENSIONS) {
			//ERROR
			printf("Error: Exceeded maximum number of dimensions (%d)\n", MAX_DIMENSIONS);
			if ($1) free($1);
		}
		else if (dim_count == 0) {
			$$ = malloc(sizeof(array_t));
			if (!$$) {
				printf("Memory allocation error\n");
				exit(1);
			}
			if ($3 <= 0) {
				printf("Error: Array dimension must be positive integer\n");
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
			//ERROR
			printf("Error: Exceeded maximum number of dimensions (%d)\n", MAX_DIMENSIONS);
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
expression : expression OROP expression { if (($1.type == T_INT) && ($3.type == T_INT) || $1.type == 5 || $3.type == 5) {
   					  	printf("correct type\n");
   					  	$$.type = $1.type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
					}
	| expression ANDOP expression { if (($1.type == T_INT) && ($3.type == T_INT) || $1.type == 5 || $3.type == 5) {
   					  	printf("correct type\n");
   					  	$$.type = $1.type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
				      }
	| expression EQUOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR) || $1.type == 5 || $3.type == 5){
						printf("correct type equop\n");
						$$.type = T_INT;
					}
					else printf("semantic error\n");
				      }
	| expression RELOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR) || $1.type == 5 || $3.type == 5){
						printf("correct type relop\n");
						$$.type = T_INT;
					}
					else printf("semantic error\n");
				      }
	| expression ADDOP expression {if($1.type == T_INT && $3.type == T_INT)
						$$.type = T_INT;
					else if (($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT)) {
						$$.type = T_FLOAT;
					}
					else if( $1.type == 5 || $3.type == 5)
						$$.type = 5;
					// list check
					else printf("semantic error\n");	
				      }
	| expression MULOP expression {if($1.type == T_INT && $3.type == T_INT)
						$$.type = T_INT;
					else if ((($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT))/* && ($2.type != T_MULOP_MOD)*/) {
						$$.type = T_FLOAT;
					}
					else if($1.type == 5 || $3.type == 5)
						$$.type = 5;
					//list
					else printf("semantic error\n");	
				      }
	| NOTOP expression { if ($2.type != T_INT || $2.type == 5) { 
	                     	printf("not correct type. semantics error\n");
	                     }
	                     else {
	                   	$$.type = $2.type;
	                   	printf("correct type\n");
	                     }
	                   }
				
	| ADDOP expression { if (($2.type != T_INT) || ($2.type != T_FLOAT) || $2.type == 5) {
		             	printf("semantic error\n");
			     }
			     else {
			     	$$.type = $2.type;
				$$.val = $2.val;
	                   	printf("correct type\n");
			     	if($1 == 1)
					if($2.type == T_INT)
						$$.val.ival = ($2.val.ival * (-1));	
					if($2.type == T_INT)
						$$.val.fval = ($2.val.fval * (-1));
				}
			   }
	| SIZEOP expression {$$.type = T_INT; $$.val.ival = 0;}
	| INCDEC variable {var_to_expr(&$$, $2.ival);$$.rec_count = $2.rec_count; $$.n = $2.n;}
	| variable INCDEC {var_to_expr(&$$, $1.ival);$$.rec_count = $1.rec_count; $$.n = $1.n;}
	| variable {var_to_expr(&$$, $1.ival); $$.rec_count = $1.rec_count; $$.n = $1.n; printf("%d\n", $$.type); printf("%d\n", $$.val.ival);}
	| variable LPAREN expression_list RPAREN {var_to_expr(&$$, $1.ival);
							 if($1.n->func != NULL){
							struct hashnode_s *n = hashtbl_lookup(currtb, scope, $1.n->key, currvis);
							if(n == NULL)
								printf("semantic error\n");
							if(n->func != NULL){
							par_list_t *p1 = n->func->node;
							expr_list_t *p2 = $3;
							printf("p1==NULL:%d, p2==NULL:%d\n", p1==NULL, p2==NULL);
							while(p1!=NULL && p2!=NULL){
								printf("pt: %s, p2t: %s\n", p1->type, p2->exp->n->data);
								if(strcmp(p1->type,p2->exp->n->data))
									printf("semantic error param type\n");
								p1=p1->next; p2=p2->next;
							}
							if(p1 != NULL || p2!=NULL)
								printf("semantic error param size\n");}
							else if($3 != NULL)
								printf("semantic error\n");
						}else if(strcmp($1.n->data, "func"))printf("semantic error %s\n", $1.n->data);}
	| LENGTH LPAREN general_expression RPAREN
	| NEW LPAREN general_expression RPAREN
	| constant {$$.type = $1.type; $$.val = $1.val; $$.n = malloc(sizeof(expr_t)); $$.n->arr = malloc(sizeof(array_t)); $$.n->arr->dims = 0; $$.rec_count = 0;}
	| LPAREN general_expression RPAREN
	| LPAREN standard_type RPAREN
	| listexpression;
variable : variable LBRACK general_expression RBRACK {
							if($3->exp->type != T_INT ||($3->exp->n->arr != NULL) && ($3->exp->rec_count != $3->exp->n->arr->dims))
								printf("semantic error here\n");
							else{
							     if($1.rec_count > $1.n->arr->dims)
								printf("semantic error there\n");
						 	     else if($3->exp->val.ival <0 || $3->exp->val.ival >= $1.n->arr->dim_size[$1.rec_count]){
							    //if($3.val.ival <0 || $3.val.ival >= curr_node->arr->dim_size[curr_node->arr->dims - rec_count]){
								printf("dims:%d, rec_count: %d\n", $1.n->arr->dims, $1.rec_count);
								printf("curr_dimsize %d, ival %d\n", $1.n->arr->dim_size[$1.rec_count], $3->exp->val.ival);
								printf("semantic error2\n");}
							     	else {
									if($3->exp->rec_count != $3->exp->n->arr->dims)
										printf("semantic error\n");
									$$.rec_count = $1.rec_count+1;
									$$.n = $1.n;
								}
							}
					} // matrix
	| variable DOT ID {if($1.n == NULL) printf("semantic error 1\n");
			    struct hashnode_s *p=$1.n;
                            if ($1.n->un != NULL) {
				
				if (hashtbl_lookup(p->un->untb, scope, $3, currvis) == NULL) 
					printf("semantic error 3\n");
			    }
			    else if ($1.n->cla != NULL) {
				int currvis = 2; // INITIALLY, PERMISSION = 2
				while(p!=NULL && p->cla!=NULL && hashtbl_lookup(p->cla->classtb, scope, $3, currvis) == NULL){
					if(p!=NULL && p->cla!=NULL && p->cla->superclass == NULL)
						printf("semantic error 3\n");
					printf("psaxnw father %s\n", p->cla->superclass);
					currvis = 1;
					p = hashtbl_lookup(currtb, scope, p->cla->superclass, 0);
				}
				p = hashtbl_lookup($1.n->cla->classtb, scope, $3, currvis);
			   	currtb = $1.n->cla->classtb;
				$$.n = p;
			    }
			    else 
				printf("semantic error 2\n");
			
			$$.rec_count = 0;
			$$.ival =0;
			if(p == NULL)
				p = malloc(sizeof(struct hashnode_s));
			if(p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
				$$.n = p;
			}
			};// class and unions
	| LISTFUNC LPAREN general_expression RPAREN {} // list
	| decltype ID { 
			struct hashnode_s *p= hashtbl_lookup(currtb, scope, yylval.str, currvis);
			if(p== NULL && deflist == NULL)
				printf("semantics error\n");
			else if(p == NULL && deflist != NULL){
				id_list_t *curr = deflist, *prv = deflist;
				$$.n = NULL;
				while (curr) {
					printf("str = %s\n", curr->id->id);
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
						$$.ival = 5; // so i cant know the type unless i make a global
								// what i do know is that the type will be the same as the
								// one before it, so with 5 i tell it theres no way theres a semantic error
						curr = NULL;
					}
				}
				if($$.n == NULL)
					printf("semantic error\n");
			}
			else{
				$$.rec_count = 0;
			 	$$.n = p;
				if(!strcmp(p->data, "char"))
					$$.ival = 0;
				else if(!strcmp(p->data, "int"))
					$$.ival = 1;
				else if(!strcmp(p->data, "float"))
					$$.ival = 2;
				else if(!strcmp(p->data, "void"))
					$$.ival = 3;
				else $$.ival = 4;
			}
			if(p!=NULL && p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
			}
		}
	| THIS; // class
general_expression : general_expression COMMA general_expression {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = $3->exp; k->next =$1; $$ = k;}
	| assignment{expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = malloc(sizeof(expr_t)); k->exp->type = $1.type; k->exp->val = $1.val; k->exp->rec_count = $1.rec_count; k->exp->n = $1.n; k->next =  NULL; $$ = k;};
assignment : variable ASSIGN assignment {if($1.rec_count != $1.n->arr->dims) printf("semantic error\n");}
   	   | variable ASSIGN STRING 
	| expression {$$.type = $1.type; $$.val = $1.val;$$.rec_count = $1.rec_count; $$.n = $1.n;};
expression_list : general_expression {$$ = $1;} | {$$ = NULL;};
constant : CCONST {$$.type = T_CHAR; $$.val.cval = yylval.cval;}
	| ICONST {$$.type = T_INT; $$.val.ival = yylval.ival;}
	| FCONST {$$.type = T_FLOAT; $$.val.fval = yylval.fval;};
listexpression : LBRACK expression_list RBRACK;
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
variabledef : LIST ID {dim_count = 0;} dims
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
short_func_declaration : short_par_func_header SEMI | nopar_func_header SEMI{struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
									  if (p != NULL) printf("semantic error: x2 header declaration\n");
									  else {
									  	hashtbl_insert(currtb, $1.name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, $1.name, currvis);
										p->func->ret_type = $1.type;			
										p->func->header_declared = 0;
										p->func->node = NULL;
									  }
									};
short_par_func_header : func_header_start LPAREN parameter_types RPAREN {struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
									  if (p != NULL) printf("semantic error: x2 header declaration\n");
									  else { 
										hashtbl_insert(currtb, $1.name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, $1.name, currvis);
										p->func->ret_type = $1.type;			
										p->func->header_declared = 0;
										p->func->node = $3;
									  }
									};
func_header_start : typename ID {
		  		//if (!strcmp($1, "int") && !strcmp($1, "float") && !strcmp($1,"char") && !strcmp($1,"void")) 
				//	printf("semantic error: wrong func return type\n");
				//else {	
					$$.type = $1;
					$$.name = $2;
				//}	
				} | LIST ID;
parameter_types : parameter_types COMMA typename pass_list_dims{
	       par_list_t *n = malloc(sizeof(par_list_t));
	       n->type = $3;
	       n->next = $1;
               $$ = n; }
				
		| typename pass_list_dims {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = $1;
		n->next = NULL;
		$$= n;
		};
pass_list_dims : listspec dims | REFER;
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

init_variabledef : variabledef initializer {int p=1; for(int i=0;($1!=NULL && $1->arr!=NULL && i<$1->arr->dims); i++) p = p * $1->arr->dim_size[i]; if((($1!=NULL)&&($1->data!=NULL)&&(!strcmp($1->data,"char"))&&($1->arr!=NULL)&&p==$2)||p<$2) printf("semantic error\n");};
initializer : ASSIGN {dim_count=0;} init_value {$$ = $3;} | {$$=0;};
init_value : expression {$$ = 1;}
        | LBRACE init_values RBRACE {$$ = $2;}
        | STRING {$$=strlen($1);};
init_values : init_values COMMA init_value {$$ = $1 + $3;}
                | init_value {$$= $1;}; 
func_declaration : short_func_declaration | full_func_declaration {printf("sevo\n");};
full_func_declaration : full_par_func_header {scope++;} LBRACE decl_statements RBRACE {hashtbl_get(currtb, scope); scope--;}
		| nopar_class_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(currtb, scope);scope--;}
		| nopar_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(currtb, scope);scope--;};
full_par_func_header : class_func_header_start LPAREN parameter_list RPAREN { struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
								   if(strcmp(p->data, "func")) printf("semantic error\n");
								   if (p != NULL && p->istype == 0) printf("semantic error: x2 func declaration\n");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									//check if params are correct 
									id_list_t *n = $3;
									par_list_t *s = p->func->node;
									while(s && n) {
										if(strcmp(s->type,n->id->data)) {
											printf("semantic error: parameters dont match\n");
											break;
										}else{
											s = s->next;
											n = n->next;
										}	
									}
									if (s != NULL || n != NULL)
										printf("semantic error:parameters dont match2\n");
									else
									p->func->header_declared = 1;
									scope++;
									var_decl($3, $3->id->data);
									scope--;
								   }
								   else printf("semantic error\n");}
		| func_header_start LPAREN parameter_list RPAREN { struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, 0);
								   if(strcmp(p->data, "func")) printf("semantic error\n");
								   if (p != NULL && p->istype == 0) printf("semantic error: x2 func declaration\n");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									//check if params are correct 
									id_list_t *n = $3;
									par_list_t *s = p->func->node;
									while(s && n) {
										if(strcmp(s->type,n->id->data)) {
											printf("semantic error: parameters dont match\n");
											break;
										}else{
											s = s->next;
											n = n->next;
										}	
									}
									if (s != NULL || n != NULL)
										printf("semantic error:parameters dont match2\n");
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
class_func_header_start : typename func_class ID {struct hashnode_s *p =hashtbl_lookup(currtb, scope, $2, currvis); if(p==NULL) printf("semantic error1\n"); if((p = hashtbl_lookup(p->cla->classtb, 55555, $3, currvis)) == NULL) printf("semantic error2\n"); if(strcmp(p->func->ret_type, $1)) printf("semantic error4\n"); if(strcmp(p->data, "func")) printf("semantic error3\n"); $$.type = $1;$$.name = $3;}
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
pass_variabledef : variabledef | REFER ID;
nopar_class_func_header : class_func_header_start LPAREN RPAREN;
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
if_statement : IF LPAREN general_expression RPAREN statement %prec LOWER_THAN_ELSE |
		IF LPAREN general_expression RPAREN statement ELSE statement;
while_statement : WHILE LPAREN general_expression RPAREN statement;
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
			if(!strcmp(node->data, "func") && (node->func->header_declared == 0)) {
				printf("header of func %s without declaration\n", node->key);
				exit(1);
				//handle semantic error
			}else
				node = node->next;
				
		}

	}
	
}

void var_decl(id_list_t *var_list, char *data) {
	id_list_t *curr = var_list, *prv = var_list;
	while (curr) {
		printf("str = %s\n", curr->id->id);
		struct hashnode_s *p = hashtbl_lookup(currtb, scope, curr->id->id, 0);
		if(p != NULL && p->scope == scope)
			printf("semantic error, x2 declare\n");
		else {hashtbl_insert(currtb, curr->id->id, data, scope, curr->id->arr, 0, currvis);printf("data = %s, key = %s\n", data, curr->id->id);}
		curr = curr->next;
		free(prv);
		prv = curr;
	}
}

void var_to_expr(expr_t *expr, int type){ 
	switch(type){
		case 0:{ expr->type = T_CHAR; break;}
		case 1:{ expr->type = T_INT; break;}
		case 2:{ expr->type = T_FLOAT; break;}
		case 3:{ expr->type = T_VOID; break;}
		case 4:{ expr->type = T_ID; break;}
		case 5:{ expr->type = T_ALL; break;}
		default: {printf("semantic error func\n");}
	}
	expr->val.ival = 0;
}
void yyerror (char const *s) {
	printf("error: %s\n", s);
}

int main(){
	symtb = hashtbl_create(10, NULL);
	currtb = symtb;
	return yyparse();
	hashtbl_destroy(symtb);
}
