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
}
%token <oper> ADDOP
%token <ival> ICONST
%token <str> ID STRING
%type <ival> init_value init_values initializer
%type <myexpr> expression general_expression constant assignment
%type <id> variabledef init_variabledef
%type <idlist> variabledefs init_variabledefs
%type <par_list> parameter_types, parameter_list
%type <arr> dims
%type <myvar> variable
%type <str> standard_type typename class_body parent
%type <myhdr> func_header_start 
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
		| ID {struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1, 0); if(p == NULL || p->istype == 0) printf("semantic error\n");else{$$ = p->key;}};
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
expression : expression OROP expression { if (($1.type == T_INT) && ($3.type == T_INT)) {
   					  	printf("correct type\n");
   					  	$$.type = $1.type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
					}
	| expression ANDOP expression { if (($1.type == T_INT) && ($3.type == T_INT)) {
   					  	printf("correct type\n");
   					  	$$.type = $1.type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
				      }
	| expression EQUOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR)){
						printf("correct type equop\n");
						$$.type = T_INT;
					}
					else printf("semantic error\n");
				      }
	| expression RELOP expression {if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR)){
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
					// list check
					else printf("semantic error\n");	
				      }
	| expression MULOP expression {if($1.type == T_INT && $3.type == T_INT)
						$$.type = T_INT;
					else if ((($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT))/* && ($2.type != T_MULOP_MOD)*/) {
						$$.type = T_FLOAT;
					}
					//list
					else printf("semantic error\n");	
				      }
	| NOTOP expression { if ($2.type != T_INT) { 
	                     	printf("not correct type. semantics error\n");
	                     }
	                     else {
	                   	$$.type = $2.type;
	                   	printf("correct type\n");
	                     }
	                   }
				
	| ADDOP expression { if (($2.type != T_INT) || ($2.type != T_FLOAT)) {
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
	| variable LPAREN expression_list RPAREN {var_to_expr(&$$, $1.ival);}
	| LENGTH LPAREN general_expression RPAREN
	| NEW LPAREN general_expression RPAREN
	| constant {$$.type = $1.type; $$.val = $1.val; $$.n = malloc(sizeof(expr_t)); $$.n->arr = malloc(sizeof(array_t)); $$.n->arr->dims = 0; $$.rec_count = 0;}
	| LPAREN general_expression RPAREN
	| LPAREN standard_type RPAREN
	| listexpression;
variable : variable LBRACK general_expression RBRACK {
							if($3.type != T_INT ||($3.n->arr != NULL) && ($3.rec_count != $3.n->arr->dims))
								printf("semantic error here\n");
							else{
							     if($1.rec_count > $1.n->arr->dims)
								printf("semantic error there\n");
						 	     else if($3.val.ival <0 || $3.val.ival >= $1.n->arr->dim_size[$1.rec_count]){
							    //if($3.val.ival <0 || $3.val.ival >= curr_node->arr->dim_size[curr_node->arr->dims - rec_count]){
								printf("dims:%d, rec_count: %d\n", $1.n->arr->dims, $1.rec_count);
								printf("curr_dimsize %d, ival %d\n", $1.n->arr->dim_size[$1.rec_count], $3.val.ival);
								printf("semantic error2\n");}
							     	else {
									if($3.rec_count != $3.n->arr->dims)
										printf("semantic error\n");
									$$.rec_count = $1.rec_count+1;
									$$.n = $1.n;
								}
							}
					} // matrix
	| variable DOT ID { if($1.n == NULL) printf("semantic error 1\n");
			    struct hashnode_s *p;
                            if ($1.n->un != NULL) {
				
				if (hashtbl_lookup(p->un->untb, scope, $3, 0) == NULL) 
					printf("semantic error 3\n");
			    }
			    else if ($1.n->cla != NULL) {
			    	
				int perm = 2; // INITIALLY, PERMISSION = 2
				while(hashtbl_lookup(p->cla->classtb, scope, $3, perm) == NULL){
					if(p->cla->superclass == NULL)
						printf("semantic error 3\n");
					printf("psaxnw father %s\n", p->cla->superclass);
					perm = 1;
					p = hashtbl_lookup(symtb, scope, p->cla->superclass, 0);
				}
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
			}
			$$.n = p;
			}// class and unions
	| LISTFUNC LPAREN general_expression RPAREN {} // list
	| decltype ID { 
			struct hashnode_s *p;
			if((p = hashtbl_lookup(symtb, scope, yylval.str, 0)) == NULL)
				printf("semantics error\n");
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
			if(p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
			}
		}
	| THIS; // class
general_expression : general_expression COMMA general_expression
	| assignment{$$.type = $1.type; $$.val = $1.val; $$.rec_count = $1.rec_count; $$.n = $1.n;};
assignment : variable ASSIGN assignment {if($1.rec_count != $1.n->arr->dims) printf("semantic error\n");}
   	   | variable ASSIGN STRING 
	| expression {$$.type = $1.type; $$.val = $1.val;$$.rec_count = $1.rec_count; $$.n = $1.n;};
expression_list : general_expression | ;
constant : CCONST {$$.type = T_CHAR; $$.val.cval = yylval.cval;}
	| ICONST {$$.type = T_INT; $$.val.ival = yylval.ival;}
	| FCONST {$$.type = T_FLOAT; $$.val.fval = yylval.fval;};
listexpression : LBRACK expression_list RBRACK;
class_declaration : CLASS ID {hashtbl_insert(symtb, $2, "class", scope, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, 0); currtb = p->cla->classtb;}class_body SEMI {struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, 0); p->cla->superclass = $4;currtb = symtb; currvis = 0;};
class_body : parent LBRACE members_methods RBRACE {$$ = $1;};
parent : COLON ID {$$ = $2;}|  {$$ = NULL;};
members_methods : members_methods access member_or_method | access member_or_method;
access : PRIVATE COLON {currvis = 2;}| PROTECTED COLON {currvis = 1;} | PUBLIC COLON {currvis = 0;} | ;
member_or_method : member
	| method;
member : var_declaration
	| anonymous_union;
var_declaration : typename variabledefs SEMI {$2->id->data = $1; var_decl($2);};
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
short_func_declaration : short_par_func_header SEMI | nopar_func_header SEMI;
short_par_func_header : func_header_start LPAREN parameter_types RPAREN {struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1.name, 0);
									  if (p != NULL && p->istype == 1) printf("semantic error: x2 header declaration\n");
									  else { 
									  	hashtbl_insert(symtb, $1.name, "func", scope, NULL, 1, 0);
										p = hashtbl_lookup(symtb, scope, $1.name, 0);
										p->func->ret_type = $1.type;			
										p->func->header_declared = 0;
										p->func->node = $3;
									  }
									};
func_header_start : typename ID {
		  		if (!strcmp($1, "int") && !strcmp($1, "float") && !strcmp($1,"char") && !strcmp($1,"void")) 
					printf("semantic error: wrong func return type\n");
				else {	
					$$.type = $1;
					$$.name = $2;
				}	
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
nopar_func_header : func_header_start LPAREN RPAREN;
union_declaration : UNION ID {hashtbl_insert(symtb, $2, "union", 0, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, 0); currtb = p->un->untb;} union_body SEMI {currtb = symtb;};
global_var_declaration : typename init_variabledefs SEMI {$2->id->data = $1; var_decl($2);};
init_variabledefs : init_variabledefs COMMA init_variabledef  {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = $3;
         		 n->next = $1;
         		 $$ = n;
      			}
				| init_variabledef{
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = $1;
					n->next = NULL;
					$$ = n;
				};

init_variabledef : variabledef initializer {int p=1; for(int i=0; i<$1->arr->dims; i++) p = p * $1->arr->dim_size[i]; if((($1!=NULL)&&($1->data!=NULL)&&(!strcmp($1->data,"char"))&&($1->arr!=NULL)&&p==$2)||p<$2) printf("semantic error\n");};
initializer : ASSIGN {dim_count=0;} init_value {$$ = $3;} | {$$=0;};
init_value : expression {$$ = 1;}
        | LBRACE init_values RBRACE {$$ = $2;}
        | STRING {$$=strlen($1);};
init_values : init_values COMMA init_value {$$ = $1 + $3;}
                | init_value {$$= $1;}; 
func_declaration : short_func_declaration | full_func_declaration {printf("sevo\n");};
full_func_declaration : full_par_func_header {scope++;} LBRACE decl_statements RBRACE {hashtbl_get(symtb, scope); scope--;}
		| nopar_class_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(symtb, scope);scope--;}
		| nopar_func_header {scope++;} LBRACE decl_statements RBRACE{hashtbl_get(symtb, scope);scope--;};
full_par_func_header : class_func_header_start LPAREN parameter_list RPAREN
		| func_header_start LPAREN parameter_list RPAREN { struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1.name, 0);
								   if (p != NULL && p->istype == 0) printf("semantic error: x2 func declaration\n");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									//check if params are correct 
									par_list_t *n = $3;
									while(p->func->node && n) {
										if(!strcmp(p->func->node->type,n->type)) {
											printf("semantic error: parameters dont match\n");
											break;
										}else{
											p->func->node = p->func->node->next;
											n = n->next;
										}	
									}
									if (p->func->node != NULL || n != NULL)
										printf("semantic error:parameters dont match\n");
									else
									p->func->header_declared = 1;
								   }
								   else if (p == NULL) {
									hashtbl_insert(symtb, $1.name, "func", scope, NULL, 0, 0);
									p = hashtbl_lookup(symtb, scope, $1.name, 0);
									p->func->ret_type = $1.type;
									p->func->header_declared = 1;
									p->func->node = $3;
								  }
								 };
class_func_header_start : typename func_class ID
		| LIST func_class ID;
func_class : ID METH;
parameter_list : parameter_list COMMA typename pass_variabledef {
		 par_list_t *n = malloc(sizeof(par_list_t));
	         n->type = $3;
	         n->next = $1;
                 $$ = n; 
		}
		| typename pass_variabledef {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = $1;
		n->next = NULL;
		$$= n;
		};	
pass_variabledef : variabledef | REFER ID;
nopar_class_func_header : class_func_header_start LPAREN RPAREN;
decl_statements : declarations statements
		| declarations
		| statements | ;
declarations : declarations decltype typename variabledefs SEMI {  $4->id->data = $3; var_decl($4);}
		| decltype typename variabledefs SEMI{  $3->id->data = $2; var_decl($3);};
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
	| SEMI;
expression_statement : general_expression SEMI;
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
comp_statement: LBRACE{scope++;} decl_statements {hashtbl_get(symtb, scope);scope--;}RBRACE;
main_function: main_header {header_decl_check(symtb); scope++;} LBRACE decl_statements RBRACE {hashtbl_get(symtb, scope);scope--;};
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

void var_decl(id_list_t *var_list) {
	id_list_t *curr = var_list, *prv = var_list;
	while (curr) {
		printf("str = %s\n", curr->id->id);
		struct hashnode_s *p = hashtbl_lookup(currtb, scope, curr->id->id, 0);
		if(p != NULL && p->scope == scope)
			printf("semantic error, x2 declare\n");
		else hashtbl_insert(currtb, curr->id->id, curr->id->data, scope, curr->id->arr, 0, currvis);
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
