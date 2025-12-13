%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "dkk.tab.h"
#include "hashtbl.h"
int yylex(void);
void yyerror(const char *s);
int scope = 0;
HASHTBL *symtb;
%}
%token TYPEDEF CHAR INT FLOAT CONST UNION CLASS PRIVATE PROTECTED PUBLIC
STATIC VOID LIST CONTINUE BREAK THIS IF ELSE WHILE FOR RETURN LENGTH
NEW CIN COUT MAIN ICONST FCONST CCONST OROP ANDOP EQUOP RELOP ADDOP MULOP NOTOP INCDEC
SIZEOP LISTFUNC STRING LPAREN RPAREN SEMI DOT COMMA ASSIGN COLON LBRACK RBRACK REFER
LBRACE RBRACE METH INP OUT ID

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
	expr_t myexpr;	
	id_list_t *idlist;
}

%type <myexpr> expression
%type <ival> standard_type typename 
%type <str> variabledef init_variabledef
%type <idlist> variabledefs init_variabledefs
%%
program: global_declarations main_function {exit(0);};
global_declarations: global_declarations global_declaration | ;
global_declaration : typedef_declaration
	| const_declaration
	| class_declaration
	| union_declaration
	| global_var_declaration
	| func_declaration {printf("global");};
typedef_declaration : TYPEDEF typename listspec ID dims SEMI;
typename : standard_type {$$ = $1;} 
		| ID {$$ = 4;};
standard_type : CHAR {printf("got char\n"); $$ = 0;}
		| INT {printf("got int\n"); $$ = 1;}
		| FLOAT {printf("got float\n"); $$ = 2;}
		| VOID {printf("got void\n"); $$ = 3;};
listspec : LIST | ;
dims : dims dim | ;
dim : LBRACK ICONST RBRACK | LBRACK RBRACK;
const_declaration : CONST typename constdefs SEMI;
constdefs : constdefs COMMA constdef | constdef;
constdef : ID dims ASSIGN init_value;
init_value : expression
	| LBRACE init_values RBRACE
	| STRING;
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
	                   	printf("correct type\n");
			     }
			   }
	| SIZEOP expression
	| INCDEC variable
	| variable INCDEC
	| variable
	| variable LPAREN expression_list RPAREN
	| LENGTH LPAREN general_expression RPAREN
	| NEW LPAREN general_expression RPAREN
	| constant
	| LPAREN general_expression RPAREN
	| LPAREN standard_type RPAREN
	| listexpression;
variable : variable LBRACK general_expression RBRACK
	| variable DOT ID
	| LISTFUNC LPAREN general_expression RPAREN
	| decltype ID
	| THIS;
general_expression : general_expression COMMA general_expression
	| assignment;
assignment : variable ASSIGN assignment
	| variable ASSIGN STRING
	| expression;
expression_list : general_expression | ;
constant : CCONST | ICONST | FCONST;
listexpression : LBRACK expression_list RBRACK;
init_values : init_values COMMA init_value | init_value;
class_declaration : CLASS ID class_body SEMI;
class_body : parent LBRACE members_methods RBRACE;
parent : COLON ID | ;
members_methods : members_methods access member_or_method | access member_or_method;
access : PRIVATE COLON | PROTECTED COLON | PUBLIC COLON | ;
member_or_method : member
	| method;
member : var_declaration
	| anonymous_union;
var_declaration : typename variabledefs SEMI {
	  id_list_t *curr = $2, *prv = $2;
          char t[8];

          switch ($1) {
              case 0: strcpy(t, "char\0");  break;
              case 1: strcpy(t, "int\0");   break;
              case 2: strcpy(t,"float\0"); break;
              case 3: strcpy(t,"void\0");  break;
	      case 4: strcpy(t,"typedef\0"); break;
              default: strcpy(t, "unknown\0");
          }
		  
		  if (strcmp(t, "unknown") == 0) {
			  printf("Error: Variable unknown type.\n");
			  //return;
		  }
          while (curr) {
              printf("str = %s\n", curr->id);
              hashtbl_insert(symtb, curr->id, t, scope);
              curr = curr->next;
			  free(prv);
			  prv = curr;
          }
      };
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
variabledef : LIST ID dims
	| ID dims {$$ = yylval.str; printf("variabledef\n");};
anonymous_union : UNION union_body SEMI;
union_body : LBRACE fields RBRACE;
fields : fields field | field;
field : var_declaration;
method : short_func_declaration;
short_func_declaration : short_par_func_header SEMI | nopar_func_header SEMI;
short_par_func_header : func_header_start LPAREN parameter_types RPAREN;
func_header_start : typename ID | LIST ID;
parameter_types : parameter_types COMMA typename pass_list_dims | typename pass_list_dims;
pass_list_dims : listspec dims | REFER;
nopar_func_header : func_header_start LPAREN RPAREN;
union_declaration : UNION ID union_body SEMI;
global_var_declaration : typename init_variabledefs SEMI {
	  id_list_t *curr = $2, *prv = $2;
          char t[8];

          switch ($1) {
              case 0: strcpy(t, "char\0");  break;
              case 1: strcpy(t, "int\0");   break;
              case 2: strcpy(t,"float\0"); break;
              case 3: strcpy(t,"void\0");  break;
	      case 4: strcpy(t,"typedef\0"); break;
              default: strcpy(t, "unknown\0");
          }
		  
		  if (strcmp(t, "unknown") == 0) {
			  printf("Error: Variable unknown type.\n");
			  //return;
		  }
          while (curr) {
              printf("str = %s\n", curr->id);
              hashtbl_insert(symtb, curr->id, t, scope);
              curr = curr->next;
			  free(prv);
			  prv = curr;
          }
      };
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

init_variabledef : variabledef initializer {$$ = $1; printf("init_variabledef\n");};
initializer : ASSIGN init_value | ;
func_declaration : short_func_declaration | full_func_declaration {printf("sevo");};
full_func_declaration : full_par_func_header LBRACE decl_statements RBRACE
		| nopar_class_func_header LBRACE decl_statements RBRACE
		| nopar_func_header LBRACE decl_statements RBRACE;
full_par_func_header : class_func_header_start LPAREN parameter_list RPAREN
		| func_header_start LPAREN parameter_list RPAREN;
class_func_header_start : typename func_class ID
		| LIST func_class ID;
func_class : ID METH;
parameter_list : parameter_list COMMA typename pass_variabledef
		| typename pass_variabledef;
pass_variabledef : variabledef | REFER ID;
nopar_class_func_header : class_func_header_start LPAREN RPAREN;
decl_statements : declarations statements
		| declarations
		| statements | ;
declarations : declarations decltype typename variabledefs SEMI {
	  id_list_t *curr = $4, *prv = $4;
          char t[8];

          switch ($3) {
              case 0: strcpy(t, "char\0");  break;
              case 1: strcpy(t, "int\0");   break;
              case 2: strcpy(t,"float\0"); break;
              case 3: strcpy(t,"void\0");  break;
	      case 4: strcpy(t,"typedef\0"); break;
              default: strcpy(t, "unknown\0");
          }
		  
		  if (strcmp(t, "unknown") == 0) {
			  printf("Error: Variable unknown type.\n");
			  //return;
		  }
          while (curr) {
              printf("str = %s\n", curr->id);
              hashtbl_insert(symtb, curr->id, t, scope);
              curr = curr->next;
			  free(prv);
			  prv = curr;
          }
      }
		| decltype typename variabledefs SEMI{
	  id_list_t *curr = $3, *prv = $3;
          char t[8];

          switch ($2) {
              case 0: strcpy(t, "char\0");  break;
              case 1: strcpy(t, "int\0");   break;
              case 2: strcpy(t,"float\0"); break;
              case 3: strcpy(t,"void\0");  break;
	      case 4: strcpy(t,"typedef\0"); break;
              default: strcpy(t, "unknown\0");
          }
		  
		  if (strcmp(t, "unknown") == 0) {
			  printf("Error: Variable unknown type.\n");
			  //return;
		  }
          while (curr) {
              printf("str = %s\n", curr->id);
              hashtbl_insert(symtb, curr->id, t, scope);
              curr = curr->next;
			  free(prv);
			  prv = curr;
          }
      };
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
if_statement : IF LPAREN general_expression RPAREN statement %prec LOWER_THAN_ELSE | IF LPAREN general_expression RPAREN statement ELSE statement;
while_statement : WHILE LPAREN general_expression RPAREN statement;
for_statement : FOR LPAREN optexpr SEMI optexpr SEMI optexpr RPAREN statement;
optexpr : general_expression | ;
return_statement : RETURN optexpr SEMI;
io_statement : CIN INP in_list SEMI | COUT OUT out_list SEMI;
in_list : in_list INP in_item | in_item;
in_item : variable;
out_list: out_list OUT out_item | out_item
out_item: general_expression | STRING;
comp_statement: LBRACE decl_statements RBRACE;
main_function: main_header LBRACE decl_statements RBRACE;
main_header: INT MAIN LPAREN RPAREN;
%%
#include "hashtbl.h"
void yyerror (char const *s) {
	printf("error: %s\n", s);
}
int main(){
	symtb = hashtbl_create(10, NULL);
	return yyparse();
	hashtbl_destroy(symtb);
}
