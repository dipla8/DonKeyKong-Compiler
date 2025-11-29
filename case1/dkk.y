%{
#include <stdio.h>
#include "dkk.tab.h"
int yylex(void);
void yyerror(const char *s);
%}
%token TYPEDEF CHAR INT FLOAT CONST UNION CLASS PRIVATE PROTECTED PUBLIC
STATIC VOID LIST CONTINUE BREAK THIS IF ELSE WHILE FOR RETURN LENGTH
NEW CIN COUT MAIN ID ICONST FCONST CCONST OROP ANDOP EQUOP RELOP ADDOP MULOP NOTOP INCDEC
SIZEOP LISTFUNC STRING LPAREN RPAREN SEMI DOT COMMA ASSIGN COLON LBRACK RBRACK REFER
LBRACE RBRACE METH INP OUT
%nonassoc EQUOP RELOP
%nonassoc THEN
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
}
%%
program: global_declarations main_function;
global_declarations: global_declarations global_declaration | ;
global_declaration : typedef_declaration
	| const_declaration
	| class_declaration
	| union_declaration
	| global_var_declaration
	| func_declaration;
typedef_declaration : TYPEDEF typename listspec ID dims SEMI;
typename : standard_type | ID;
standard_type : CHAR | INT | FLOAT | VOID;
listspec : LIST | ;
dims : dims dim | ;
dim : LBRACK ICONST RBRACK | LBRACK RBRACK;
const_declaration : CONST typename constdefs SEMI;
constdefs : constdefs COMMA constdef | constdef;
constdef : ID dims ASSIGN init_value;
init_value : expression
	| LBRACE init_values RBRACE
	| STRING;
expression : expression OROP expression
	| expression ANDOP expression
	| expression EQUOP expression
	| expression RELOP expression
	| expression ADDOP expression
	| expression MULOP expression
	| NOTOP expression
	| ADDOP expression
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
var_declaration : typename variabledefs SEMI;
variabledefs : variabledefs COMMA variabledef
	| variabledef;
variabledef : LIST ID dims
	| ID dims;
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
global_var_declaration : typename init_variabledefs SEMI;
init_variabledefs : init_variabledefs COMMA init_variabledef | init_variabledef;
init_variabledef : variabledef initializer;
initializer : ASSIGN init_value | ;
func_declaration : short_func_declaration | full_func_declaration;
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
declarations : declarations decltype typename variabledefs SEMI
		| decltype typename variabledefs SEMI;
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
if_statement : IF LPAREN general_expression RPAREN THEN statement | IF LPAREN general_expression RPAREN statement ELSE statement;
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
void yyerror (char const *s) {
	printf("error: %s\n", s);
}
int main(){
	return yyparse();
}
