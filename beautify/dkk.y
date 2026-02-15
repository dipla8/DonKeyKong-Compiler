%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include "defines.h"
#include "dkk.tab.h"

extern int yylineno;

int yylex(void);
void dfs_post_order(const asd_t *node);
static void print_tree_rec(const asd_t *node, const char *prefix, int is_left);
asd_t *create_node(const char *s, asd_t *lleaf, asd_t *rleaf);
char *print_ir(const asd_t *root);
void print_tree(const asd_t *root);
void print_list();
void yyerror(const char *s);
void patchinc();
int findsize(struct hashnode_s *n);
bindv *findoff(char *fname, char *name);
void print_assembly(char *name, char* lname, char* rname, const asd_t *root);
void normalize_node(asd_t **tmp1, asd_t **tmp2, asd_t *node1, asd_t *node2, char *name1, char *name2);
void inherit(struct hashnode_s *og);

int scope = 0;
int dim_count = 0;
HASHTBL *symtb;
HASHTBL *currtb;
int currvis;
struct hashnode_s *currfunc;
id_list_t *deflist = NULL;	// necessary for int a,b=a;
struct hashnode_s *currclass = NULL;
int stride= 1;
int reg = 0;
int freg = 0;
int reg2 = 0;
int freg2 = 0;
int label_count = 0;
int logical_case = 0;
int noprint = 0;
int fpoff = 0;
char *lastname = NULL;
post_t *postlist = NULL;
FILE *fd = NULL;
FILE *fd3 = NULL;
bindf* currlist = NULL;
int gp;

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
	init_vals *init_vals1;
}

%token <oper> ADDOP EQUOP RELOP MULOP INCDEC
%token <ival> ICONST
%token <str> ID STRING LISTFUNC
%type <init_vals1> init_value init_values initializer
%type <ival> decltype
%type <myexpr> expression constant assignment variable
%type <myexprlist> expression_list listexpression general_expression optexpr
%type <id> variabledef init_variabledef pass_variabledef 
%type <idlist> variabledefs init_variabledefs parameter_list
%type <node> class_func_header_start nopar_class_func_header
%type <par_list> parameter_types
%type <arr> dims pass_list_dims
%type <str> standard_type typename class_body parent func_class
%type <myhdr> func_header_start nopar_func_header full_par_func_header
%%

program: global_declarations main_function;
global_declarations: global_declarations global_declaration | ;
global_declaration : typedef_declaration
					| const_declaration
					| class_declaration
					| union_declaration
					| global_var_declaration
					| func_declaration;
typedef_declaration : TYPEDEF typename listspec ID {dim_count = 0;}
					  dims SEMI {hashtbl_insert(symtb, $4, $2 , scope, $6, 1, currvis, NULL, &currlist);} // scope is always 0
typename : standard_type {$$ = $1;}
			| ID {
				struct hashnode_s *p = hashtbl_lookup(symtb, scope, $1, currvis);
				if(p == NULL || p->istype == 0)
					yyerror("Type doesn't exist.");
				{$$ = p->key;}
			};
standard_type : CHAR {$$="char";}
				| INT {$$="int";}
				| FLOAT {$$="float";}
				| VOID {$$="void";};
listspec : LIST | ;
dims : dims LBRACK ICONST RBRACK {
			if(dim_count == MAX_DIMENSIONS) {
				//ERROR
				yyerror("Exceeded maximum array dimensions.");
				if($1) {free($1)};
			}
			else if(dim_count == 0) {
				$$ = malloc(sizeof(array_t));
				if(!$$) {
					printf("Memory allocation error\n");
					exit(1);
				}
				if($3 <= 0) {
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
expression : expression OROP expression {
							asd_t *tmp1; asd_t *tmp2;

							if (($1.type == T_INT) && ($3.type == T_INT)) {
								$$.type = $1.type;
							}
							else {
								yyerror("Wrong expression type.");
							}
							
							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);
							$$.node = create_node("||", tmp1, tmp2);
						}
			| expression ANDOP expression {
							asd_t *tmp1; asd_t *tmp2;

							if (($1.type == T_INT) && ($3.type == T_INT)) {
								$$.type = $1.type;
							}
							else {
								yyerror("Wrong expression type.");
							}
							
							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);
							$$.node = create_node("&&", tmp1, tmp2);
						}
			| expression EQUOP expression {
							asd_t *tmp1; asd_t *tmp2;

							if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR)) {
								$$.type = T_INT;
							}
							else {
								yyerror("Wrong expression type.");
							}

							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);
							if($2 == 0) {
								$$.node = create_node("==", tmp1, tmp2);
							}
							else {
								$$.node = create_node("!=", tmp1, tmp2);
							}
						}
			| expression RELOP expression {
							asd_t *tmp1; asd_t *tmp2;

							if((($1.type == T_INT || $1.type == T_FLOAT) && (($3.type == T_INT) ||($3.type == T_FLOAT))) || ($1.type == T_CHAR && $3.type == T_CHAR)) {
								$$.type = T_INT;
							}
							else {
								yyerror("Wrong expression type.");
							}
							
							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);

							switch($2) {
								case 0:
									$$.node = create_node(">", tmp1, tmp2);
									break;
								case 1:
									$$.node = create_node(">=", tmp1, tmp2);
									break;
								case 2:
									$$.node = create_node("<", tmp1, tmp2);
									break;
								default:
									$$.node = create_node("<=", tmp1, tmp2);
							}
						}
			| expression ADDOP expression {
							asd_t *tmp1; asd_t *tmp2;

							if($1.type == T_INT && $3.type == T_INT) {
								$$.type = T_INT;
							}
							else if (($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT)) {
								$$.type = T_FLOAT;
							}
							else {
								yyerror("Wrong expression type.");
							}

							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);
							$$.val.ival = $1.val.ival + $3.val.ival;
							if($2 == 0) {
								$$.node = create_node("+", tmp1, tmp2);
							}
							else {
								$$.node = create_node("-", tmp1, tmp2);
							}
						}
			| expression MULOP expression {
							asd_t *tmp1; asd_t *tmp2;

							if($1.type == T_INT && $3.type == T_INT) {
								$$.type = T_INT;
							}
							else if ((($1.type == T_INT && $3.type == T_FLOAT) || ($1.type == T_FLOAT && $3.type == T_INT) || ($1.type == T_FLOAT && $3.type == T_FLOAT))) {
								$$.type = T_FLOAT;
							}
							else {
								yyerror("Wrong expression type.");
							}
							
							normalize_node(&tmp1, &tmp2, $1.node, $3.node, $1.name, $3.name);
							if($2 == 0) {
								$$.node = create_node("*", tmp1, tmp2);
							}
							else if($2 == 1) {
								$$.node = create_node("/", tmp1, tmp2);
							}
							else {
								$$.node = create_node("%", tmp1, tmp2);
							}
						}
			| NOTOP expression {
						asd_t *tmp1;

						if ($2.type != T_INT) {
							yyerror("Wrong expression type.");
						}
						else {
							$$.type = $2.type;
						}
						
						normalize_node(&tmp1, NULL, $2.node, NULL, $2.name, NULL);
						$$.node = create_node("!", tmp1, NULL);
					}
			| ADDOP expression {
						if (($2.type != T_INT) || ($2.type != T_FLOAT)) {
							yyerror("Wrong expression type.");
						}
						
						$$.type = $2.type;
						$$.val = $2.val;
						if($1 == 1)
							if($2.type == T_INT)
								$$.val.ival = ($2.val.ival * (-1));	

						if($2.type == T_INT)
							$$.val.fval = ($2.val.fval * (-1));

						asd_t *tmp1;
						normalize_node(&tmp1, NULL, $2.node, NULL, $2.name, NULL);
						if($1 == 0) {
							$$.node = create_node("+", tmp1, NULL);
						}
						else {
							$$.node = create_node("-", tmp1, NULL);
						}
					}
			| SIZEOP expression {
						$$.type = T_INT;
						$$.val.ival = 0;
						char *buf = malloc(10);
						sprintf(buf, "%d", findsize2($2.n, currtb, scope));
						$$.node = create_node(buf, NULL, NULL);
					}
			| INCDEC variable {
						$$ = $2;
						asd_t *node = malloc(sizeof(asd_t));
						node->name = "1";
						if($1 == 0) {
							$$.node = create_node("+", $2.node, node);
						}
						else {
							$$.node = create_node("-", $2.node, node);
						}
					}
			| variable INCDEC {
						$$ = $1;
						post_t *temp = malloc(sizeof(post_t));

						if($1.node != NULL && $1.node->name != NULL) {
							temp->name = $1.node->name;
						}
						else {
							temp->name = strdup($1.name);
						}
						temp->sign = $2;
						temp->next = postlist;
						postlist = temp;
					}
			| variable {$$ = $1;}
			| variable LPAREN expression_list RPAREN {
									$$ = $1;
									if($1.n->func != NULL){
										struct hashnode_s *n = hashtbl_lookup(currtb, scope, $1.n->key, currvis);
										
										if(n == NULL) {
											yyerror("Variable doesn't exist.");
										}

										if(n->func != NULL) {
											par_list_t *p1 = n->func->node;
											expr_list_t *p2 = $3;
											int i = 0;
											int j = 0;
											char *k;
											char tmp1[15];
											while(p1!=NULL && p2!=NULL) {
												if(strcmp(p1->type,p2->exp->n->data)) {
													yyerror("Parameter type mismatch.");
												}

												if(p2->exp->name != NULL) {

													if(!strcmp(p1->type, "float")) {
														fprintf(fd, "=,\t%s,\t,\t$fa%d\n", p2->exp->name, j);
													}
													else {
														fprintf(fd, "=,\t%s,\t,\t$a%d\n", p2->exp->name, i-j);
													}

													if(p2->exp->name[0] != '$') {
														if(atoi(p2->exp->name)) {
															if(strstr(p2->exp->name, ".") != NULL) {
																fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(p2->exp->name, NULL));
																fprintf(fd3, "fcvt.s.w $fa%d, $t%d\n", j, reg2);
															}
															else {
																fprintf(fd3, "li $a%d, %s\n", i-j, p2->exp->name);
															}
														}
														else {
															strcpy(tmp1, p2->exp->name);
															k = strstr(tmp1 , "fp");

															if(k == NULL) {
																k = strstr(tmp1, "gp");
															}
															
															if(k != NULL) {
																*k = '\0';
															}

															fprintf(fd3, "addi $t%d, %s, %s\n", ++reg2, &p2->exp->name[k-tmp1], &tmp1[4]);
															
															if(p2->exp->name[0] == '&'){
																fprintf(fd3, "mv $a%d, $t%d\n", i-j, reg2);
															}
															else {
																if(!strcmp(p1->type, "float")){
																	fprintf(fd3, "lw $f%d, 0($t%d)\n", ++freg2, reg2);
																	fprintf(fd3, "mv $fa%d, $f%d\n", j, freg2);
																}
																else {
																	fprintf(fd3, "lw $t%d, 0($t%d)\n", ++reg2, reg2);
																	fprintf(fd3, "mv $a%d, $t%d\n", i-j, reg2);
																}
															}
														}
													}
													else if (p2->exp->name[0] == '$' || p2->exp->name[0] == 't' ) {
														if(!strcmp(p1->type, "float")) {
															fprintf(fd3, "mv $fa%d, %s\n", j, p2->exp->name);
														}
														else {
															fprintf(fd3, "mv $a%d, %s\n", i-j, p2->exp->name);
														}
													}
													else {
														if(!strcmp(p1->type, "float")) {
															fprintf(fd3, "li $fa%d, %s\n", j, p2->exp->name);
														}
														else {
															fprintf(fd3, "li $a%d, %s\n", i-j, p2->exp->name);
														}
													}
												}
												i++;
												j = j + !strcmp(p1->type, "float")?1:0;
												p1=p1->next; p2=p2->next;
											}

											if(p1 != NULL || p2!=NULL) {
												yyerror("Parameter cardinality mismatch.");
											}
										}
										else if($3 != NULL) {
											printf("semantic error\n");
										}
									}
									else if(strcmp($1.n->data, "#")) {
										yyerror("Variable is not a function.");
									}

									fprintf(fd, "+,\tcurrinst,\t4,\tra\n");
									fprintf(fd3, "addi $ra, $pc, 4\n");
									fprintf(fd, "jal,\t,\t,\t%s\n", $1.n->key);
									fprintf(fd3, "jal %s\n", $1.n->key);
								}
			| LENGTH LPAREN general_expression RPAREN
			| NEW LPAREN general_expression RPAREN
			| constant {
				char *buf = malloc(15);

				$$.type = $1.type;
				$$.val = $1.val;
				$$.n = malloc(sizeof(expr_t));
				$$.n->arr = malloc(sizeof(array_t));
				$$.n->arr->dims = 0;
				$$.rec_count = 0;

				switch($1.type) {
					case T_INT:
						$$.n->data = strdup("int");
						sprintf(buf, "%d", $1.val.ival);
						break;		
					case T_CHAR:
						$$.n->data = strdup("char");
						sprintf(buf, "%c", $1.val.cval);
						break;
					case T_FLOAT:
						$$.n->data = strdup("float");
						sprintf(buf, "%f", $1.val.fval);
						break;	
				}

				$$.node = create_node(buf, NULL, NULL);
			}
			| LPAREN general_expression RPAREN
			| LPAREN standard_type RPAREN
			| listexpression {
				$$.type = $1->exp->type;
				$$.val.ival = $1->listsize;
				$$.rec_count = 0;
				$$.n = NULL;
			};
variable : variable LBRACK general_expression RBRACK {
							if($3->exp->type != T_INT ||($3->exp->n->arr != NULL) && ($3->exp->rec_count != $3->exp->n->arr->dims)) {
								yyerror("Wrong array indexing.");
							}
							else {
								if($1.rec_count > $1.n->arr->dims) {
						 	    	 	yyerror("Dimensions exceed declared dimensions.");
								}
								else if($3->exp->val.ival <0 || $3->exp->val.ival >= $1.n->arr->dim_size[$1.rec_count]) {
									yyerror("Incorrect dimension indexing.");
								}
								else {
									if($3->exp->rec_count != $3->exp->n->arr->dims) {
										yyerror("Wrong array indexing.");
									}

									if(stride == 1) {
										for(int i = 1; i < $1.n->arr->dims; i++) {
											stride = stride * $1.n->arr->dim_size[i];
										}

										$$.val.ival = $3->exp->val.ival * stride;
										$$.rec_count = $1.rec_count+1;
										$$.n = $1.n;
									}
									else {
										stride = stride / $1.n->arr->dim_size[$1.rec_count];
										$$.val.ival = $1.val.ival + $3->exp->val.ival * stride;
										$$.rec_count = $1.rec_count+1;
										$$.type = $1.type;
										$$.n = $1.n;
									}
								}
							}

							char temp[15];
							if($1.rec_count == 0) {
								fprintf(fd, "=,\t1,\t,\toff=4\n");
								fprintf (fd3, "li $t%d, 0\n", reg2++);
								fprintf(fd3, "li $t%d, 1\n", reg2);
								gp = reg2;
							}

							fprintf(fd, "*,\toff=4,\t%s,\t$t%d\n", lastname, ++reg);
							fprintf(fd3, "li $t%d, %s\n", ++reg2, lastname);
							fprintf(fd3, "mul $t%d, $t%d, $t%d\n", ++reg2, gp, reg2);
							fprintf(fd, "+,\toff=0,\t$t%d,\toff=0\n", reg);
							fprintf(fd3, "add $t%d, $t%d, $t%d\n", gp-1, reg2, gp-1);
							fprintf(fd, "*,\toff=4,\t%d,\toff=4\n", $1.n->arr->dim_size[$1.rec_count]);
							fprintf(fd3, "mul $t%d, $t%d, $t%d\n", gp, $1.n->arr->dim_size[$1.rec_count], gp);

							if($1.rec_count == $1.n->arr->dims-1) {
								fprintf(fd, "*,\toff=0,\t%d,\toff=0\n\n", findsize($1.n));
								fprintf(fd3, "li $t%d, %d\n", ++reg2, findsize($1.n));
								fprintf(fd3, "mul $t%d, $t%d, $t%d\n", gp-1, gp-1, reg2);
								fprintf(fd, "lw,\t%s,\toff=0,\t$t%d\n\n", $1.n->key, ++reg);
								fprintf(fd3, "add $t%d, $t%d, %s\n", ++reg2, gp-1, $1.n->scope == 0? "$gp": "$fp");
								fprintf(fd3, "lw $t%d, 0($t%d)\n", ++reg2, reg2-1);
								
								char *buf = malloc(10);
								sprintf(buf, "$t%d", reg);
								if($$.node != NULL) {
									$$.node->name = buf;
								}
								gp = 0;
							}
						} // matrix
			| variable DOT ID {
						if($1.n == NULL) yyerror("Variable doesn't exist.");
						struct hashnode_s *p=$1.n;
						if ($1.n->un != NULL) {	
							if (hashtbl_lookup(p->un->untb, scope, $3, currvis) == NULL) {
								yyerror("Union field doesn't exist");
							}
						}
						else if ($1.n->cla != NULL) {
							int currvis = 2; // INITIALLY, PERMISSION = 2
							while(p!=NULL && p->cla!=NULL && hashtbl_lookup(p->cla->classtb, scope, $3, currvis) == NULL) {
								if(p!=NULL && p->cla!=NULL && p->cla->superclass == NULL) {
									yyerror("Class member doesn't exist.");
								}
								currvis = 1;
								p = hashtbl_lookup(currtb, scope, p->cla->superclass, 0);
							}
							p = hashtbl_lookup(p->cla->classtb, scope, $3, currvis);
							currtb = $1.n->cla->classtb;
							$$.n = p;
						}
						else {
							yyerror("Variable is not class or union.");
						}

						$$.rec_count = 0;
						$$.val.ival =0;

						if(p == NULL) {
							p = malloc(sizeof(struct hashnode_s));
						}
						
						if(p->arr ==  NULL) {
							p->arr = malloc(sizeof(array_t));
							p->arr->dims = 0;
							$$.n = p;
						}

						//char *buf = malloc(10);
						//sprintf(buf, "$t%d", reg);
						//$$.node = malloc(sizeof(asd_t));
						//$$.node->name = buf;

						char *str = malloc(20);
						sprintf(str, "f%s", currfunc->key);
						printf("str is %s\n", str);
						bindv *temp = findoff(str, $1.n->key);

						if(temp==NULL) {
							temp = findoff("gglobal", $1.n->key);
						}

						printf("off is %d\n", temp->offset);
						sprintf(str, "c%s", $1.n->data);
						printf("str is %s\n", str);
						bindv*temp2 = findoff(str, $3);
						
						if(temp2==NULL) {
							temp2 = findoff("gglobal", $3);
						}
						
						printf("off is %d\n", temp2->offset);
						if(temp!=NULL && temp!=NULL && temp2!=NULL) {
							sprintf(str, "off=%d%s", temp->offset - temp2->offset /*findsize(hashtbl_lookup(currtb, scope, $3, currvis))*/, temp->scope?"fp":"gp");
							$$.node = create_node(str, NULL, NULL);
						}
					}// class and unions
			| LISTFUNC LPAREN general_expression RPAREN {
									char *ptr = $1;
									int count = 0;
									if($3->exp->n == NULL || $3->exp->n->arr == NULL ||$3->exp->n->arr->islist == 0) {
										yyerror("Parameter is not list.");
									}

									if($3->exp->rec_count != $3->exp->n->arr->dims) {
										yyerror("Incorrect dimension indexing.");
									}
									else {
										while ((ptr = strchr(ptr, 'd')) != NULL) {
											count++;
											ptr++;
										}
										
										if($3->exp->n->arr->listsize[$3->exp->val.ival] < count+1) {
											yyerror("List indexing exceeds limits");
										}
									}
									$$.n = $3->exp->n;
									$$.val.ival = 1;
									$$.type = $3->exp->type;
								} // list
			| decltype ID {
					struct hashnode_s *p;
					
					if($1) {
						p = hashtbl_lookup(currtb, 0, $2, currvis);
					}
					else {
						p = hashtbl_lookup(currtb, scope, $2, currvis);
					}
					
					if(p== NULL && deflist == NULL) {
						yyerror("Variable doesn't exist.");
					}
					else if(p == NULL && deflist != NULL) {
						id_list_t *curr = deflist;
						$$.n = NULL;
						while (curr) {
							if(strcmp(curr->id->id, yylval.str)) {
								curr=curr->next;
							}
							else {
								$$.rec_count = 0;
								$$.n = malloc(sizeof(struct hashnode_s));
								$$.n->data = curr->id->data;

								if(curr->id->arr == NULL){
									$$.n->arr = malloc(sizeof(array_t));
									$$.n->arr->dims = 0;
									$$.n->arr->islist = 0;
								}
								
								$$.n->arr = curr->id->arr;
								$$.n->key = curr->id->id;
								
								if(!strcmp(curr->id->data, "char"))
									$$.type = T_CHAR;
								else if(!strcmp(curr->id->data, "int"))
									$$.type = T_INT;
								else if(!strcmp(curr->id->data, "float"))
									$$.type = T_FLOAT;
								else if(!strcmp(curr->id->data, "void"))
									$$.type = T_VOID;
								else
									$$.type = T_ID;
								
								curr = NULL;
							}
						}
						if($$.n == NULL) {
							yyerror("Variable doesn't exist.");
						}
					}
					else {
						bindf *tmp1 = currlist;
						par_list_t *tmp2;
						
						while (tmp1 != NULL && strcmp(&tmp1->name[1], currfunc->key)) {
							tmp1 = tmp1->next;
						}

						if(tmp1 != NULL && !strcmp(&tmp1->name[1], currfunc->key) && currfunc->func != NULL && currfunc->func->node != NULL) {
							tmp2 = currfunc->func->node;
							int i = 0;
							int j = 0;
							char tmp[15];

							while(tmp2 != NULL) {
								i++;
								j = j + !strcmp(tmp2->type, "float")?1:0;
								
								if(!strcmp(tmp2->name, $2)) break;
								
								tmp2 = tmp2->next;
							}

							if(tmp2 != NULL) {
								if(!strcmp(tmp2->type, "float"))
									sprintf(tmp, "$fa%d", j-1);
								else sprintf(tmp, "$a%d", i-j);
								$$.name = strdup(tmp);
							}
						}

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
						else
							$$.type = T_ID;
					}

					if(p!=NULL && p->arr ==  NULL){
						p->arr = malloc(sizeof(array_t));
						p->arr->dims = 0;
						p->arr->islist = 0;
					}

					char *str = malloc(20);
					sprintf(str, "f%s", currfunc->key);
					bindv *temp = findoff(str, $2);

					if(temp!=NULL && temp!= NULL){
						sprintf(str, "off=%d%s", temp->offset, temp->scope?"fp":"gp");
						$$.node = create_node(str, NULL, NULL);
					}
				}
			| THIS {
				$$.rec_count = 0;
				$$.val.ival = 0;
				$$.n = currclass;
				$$.type = T_ID;
			}; // class
general_expression : general_expression COMMA general_expression {
						expr_list_t *k = malloc(sizeof(expr_list_t));
						k->exp = $3->exp; k->next =$1;
						k->listsize = $1->listsize+$3->listsize;
						$$ = k;
					}
					| assignment {
							expr_list_t *k = malloc(sizeof(expr_list_t));
							k->exp = malloc(sizeof(expr_t));
							k->exp->type = $1.type;
							k->exp->val = $1.val;
							k->exp->rec_count = $1.rec_count;
							k->exp->n = $1.n;
							k->next =  NULL; 
							k->listsize = 1;
							$$ = k;
							$$->exp->node = $1.node;
							
							print_tree($1.node);
							
							if(!noprint) {
								print_ir($1.node);
								patchinc();
								$$->exp->name = lastname;
							}
						};
assignment : variable ASSIGN assignment {
					if($1.rec_count != $1.n->arr->dims) {
						yyerror("Incorrect dimension indexing.");
					}
					
					if(findsize($1.n) != findsize($3.n)) {
						yyerror("Type mismatch.");
					}

					if($1.n->arr!= NULL && $1.n->arr->islist) {
						$1.n->arr->listsize[$1.val.ival] = $3.val.ival;
					}

					if($1.node != NULL) {
						$$.node = create_node("=", $1.node, $3.node);
					}
					else {
						printf("$1.name is %s\n", $1.name);
						char *str = malloc(20);
						sprintf(str, "f%s", currfunc->key);
						bindv *k;
						k = findoff(str, $1.n->key);
						printf("s is %s\n\n\n", str);

						if(k == NULL) {
							k = findoff("gglobal", $1.n->key);
						}
						
						if(k!=NULL) {
							if($1.type == T_INT) {
								fprintf(fd3, "lw $t%d, %d(%s)\n", ++reg2, k->offset, $1.n->scope?"fp":"gp");
								$1.name = malloc(10);
								sprintf($1.name, "$t%d", reg2);
							}
						}
						$$.node = create_node("=", create_node($1.name, NULL, NULL), $3.node);
					}
				}
			| variable ASSIGN STRING 
			| expression {
					$$ = $1;
					
					/*if($1.n == NULL) {
						char *temp = malloc(15);
						
						if($1.type == T_INT)
							sprintf(temp, "%d", $1.val.ival);
						else if($1.type == T_CHAR)
							sprintf(temp, "c", $1.val.cval);
						else if($1.type == T_FLOAT)
							sprintf(temp, "%2f", $1.val.fval);
						$$.name = temp;
						} else
							lastname = $1.n->key;*/
				};
expression_list : general_expression {$$ = $1;} | {$$ = NULL;};
constant : CCONST {$$.type = T_CHAR; $$.val.cval = yylval.cval;}
		| ICONST {$$.type = T_INT; $$.val.ival = yylval.ival;}
		| FCONST {$$.type = T_FLOAT; $$.val.fval = yylval.fval;};
listexpression : LBRACK expression_list RBRACK {$$ = $2;};
class_declaration : CLASS ID {
						hashtbl_insert(symtb, $2, "class", scope, NULL, 1, 0, NULL, &currlist);
						struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, currvis);
						currtb = p->cla->classtb; currfunc = p; scope++;
					} 
					class_body SEMI {
						fpoff = 0;scope--;
						struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, currvis);
						p->cla->superclass = $4;
						inherit(p);
						currtb = symtb;
						currvis = 0;
					};
class_body : parent LBRACE members_methods RBRACE {$$ = $1;};
parent : COLON ID {$$ = $2;} |  {$$ = NULL;};
members_methods : members_methods access member_or_method | access member_or_method;
access : PRIVATE COLON {currvis = 2;} | PROTECTED COLON {currvis = 1;} | PUBLIC COLON {currvis = 0;} | ;
member_or_method : member
	| method;
member : var_declaration
	| anonymous_union;
var_declaration : typename variabledefs SEMI {var_decl($2, $1);};
variabledefs : variabledefs COMMA variabledef {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = $3;
					n->id->init_vals = NULL;
					n->next = $1;
					$$ = n;
				}
				| variabledef {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = $1;
					n->id->init_vals = NULL;
					n->next = NULL;
					$$ = n;
				};
variabledef : LIST ID {dim_count = 0;} dims {
						$$ = malloc(sizeof(id_t)); $$->id = $2;
						
						if($4 == NULL){
							$$->arr = malloc(sizeof(array_t));
							$$->arr->dims = 0;
						}
						else {
							$$->arr = $4;
						}
						
						$$->arr->islist = 1; int totalsize=1;
						for(int i = 0; i < $$->arr->dims; i++) {
							totalsize = totalsize * $$->arr->dim_size[i];
						}

						$$->arr->listsize = calloc(totalsize, sizeof(int));
					}
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
	short_func_declaration : short_par_func_header SEMI 
							| nopar_func_header SEMI {
											struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
											if (p != NULL) {
												yyerror("Double header declaration");
											}
											else {
												hashtbl_insert(currtb, $1.name, "#", scope, NULL, 1, currvis, NULL, &currlist);
												p = hashtbl_lookup(currtb, scope, $1.name, currvis);
												p->func->ret_type = $1.type;			
												p->func->header_declared = 0;
												p->func->node = NULL;
											}
										};
short_par_func_header : func_header_start LPAREN parameter_types RPAREN {
										struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, currvis);
										if (p != NULL) {
											yyerror("Double header declaration");
										}
										else { 
											hashtbl_insert(currtb, $1.name, "#", scope, NULL, 1, currvis, NULL, &currlist);
											p = hashtbl_lookup(currtb, scope, $1.name, currvis);
											p->func->ret_type = $1.type;			
											p->func->header_declared = 0;
											p->func->node = $3;
										}
									};
func_header_start : typename ID {
					if(!strcmp($1, "float") ||!strcmp($1, "int") || !strcmp($1, "void")|| !strcmp($1, "char")) {
						$$.type = $1;
						$$.name = $2;
					}
					else {
						yyerror("Function type incorrect");
					}
				}
				| LIST ID {$$.type = strdup("list"); $$.name = $2;};
parameter_types : parameter_types COMMA typename pass_list_dims{
					par_list_t *n = malloc(sizeof(par_list_t));
					n->type = $3;
					n->next = $1;
					n->arr = $4;
					n->name = NULL;
					$$ = n; 
					}
				| typename pass_list_dims {
								par_list_t *n = malloc(sizeof(par_list_t));
								n->type = $1;
								n->next = NULL;
								n->arr = $2;
								n->name = NULL;
								$$= n;
							};
pass_list_dims : listspec dims {$$ = $2;}
				| REFER {
					array_t *n = malloc(sizeof(array_t));
					n->dims = -1;
					$$ = n;
				};
nopar_func_header : func_header_start LPAREN RPAREN {$$=$1;};
union_declaration : UNION ID {
						hashtbl_insert(symtb, $2, "union", 0, NULL, 1, 0, NULL, &currlist);
						struct hashnode_s *p = hashtbl_lookup(symtb, scope, $2, 0);
						currtb = p->un->untb;
					}
					union_body SEMI {currtb = symtb;};
global_var_declaration : typename init_variabledefs SEMI {var_decl($2, $1); deflist = NULL;};
init_variabledefs : init_variabledefs COMMA init_variabledef  {
						id_list_t* n = malloc(sizeof(id_list_t));
						n->id = $3;
						n->next = $1;
						$$ = n;
						deflist = n;
					}
					| init_variabledef {
						id_list_t* n = malloc(sizeof(id_list_t));
						n->id = $1;
						n->next = NULL;
						$$ = n;
						deflist = n;
					};
init_variabledef : variabledef initializer {
					int p=1;
					for(int i=0; ($1!=NULL && $1->arr!=NULL && i<$1->arr->dims); i++) {
						p = p * $1->arr->dim_size[i];
					}

					if((($1!=NULL)&&($1->data!=NULL)&&(!strcmp($1->data,"char"))&&($1->arr!=NULL)&& (($2!=NULL) && p==$2->size))|| (($2!=NULL && p<$2->size))) {
						yyerror("Wrong Initialization.");
					}
					
					if($2!=NULL)  {
						$$->init_vals = $2;
					}
				};
initializer : ASSIGN {dim_count=0;} init_value {$$ = $3;} | {$$=NULL;};
init_value : /*expression {$$ = 1;}*/ constant {
								init_vals *p = malloc(sizeof(init_vals));
								p->val = $1.val;
								p->next = NULL;
								$$ = p;
								$$->size = 1;
								$$->type = $1.type;
							}
			| LBRACE init_values RBRACE {$$ = $2;}
			| STRING {$$->string = $1; $$->size=strlen($1); $$->type = T_CHAR;};
init_values : init_values COMMA init_value {
				if ($1->type !=$3->type) {
					yyerror("Initialization types dont match.");
				}

				init_vals *tmp = $1;

				while(tmp->next) {
					tmp = tmp->next;
				}

				tmp->next = $3;
				$$ = $1; $$->size = $1->size + $3->size;
			}
			| init_value {$$= $1;}; 
func_declaration : short_func_declaration
				| full_func_declaration {fprintf(fd,"jr,\t,\t,\t$ra\n"); currfunc = NULL;};
full_func_declaration : full_par_func_header {
							scope++;
							currfunc = hashtbl_lookup(currtb, scope, $1.name, 0);
							fpoff = 0;
						}
						LBRACE decl_statements RBRACE {
							currfunc = NULL;
							fpoff = 0;
							currclass = NULL;
							hashtbl_get(currtb, scope);
							scope--;
						}
						| nopar_class_func_header {
							scope++;
							currfunc = $1;
							fpoff = 0;
						}
						LBRACE decl_statements RBRACE {
							currfunc = NULL;
							fpoff = 0;
							hashtbl_get(currtb, scope);
							scope--;
						}
						| nopar_func_header {
							scope++;
							currfunc = hashtbl_lookup(currtb, scope, $1.name, 0);
							fpoff = 0;
						}
						LBRACE decl_statements RBRACE {
							currfunc = NULL;
							fpoff = 0;
							hashtbl_get(currtb, scope);
							scope--;
						};
full_par_func_header : class_func_header_start LPAREN parameter_list RPAREN {
								currfunc = $1;
								struct hashnode_s *p = $1;
								
								if(strcmp(p->data, "#")) {
									yyerror("Class member not a method.");
								}

								if (p != NULL && p->istype == 0) {
									yyerror("Class method already declared.");
								}
								else if (p != NULL && p->istype == 1) { //we have header b4 body
									id_list_t *n = $3;
									par_list_t *s = p->func->node;

									while(s && n) {
										if(!(n->id->arr==NULL && s->arr==NULL) && !(n->id->arr == NULL || s->arr == NULL) && (n->id->arr->dims != s->arr->dims)) {
											yyerror("Function parameter mismatch.");
										}
										else if(n->id->arr!=NULL && s->arr !=NULL)for (int i= 0; i < s->arr->dims; i++) {
											if(n->id->arr->dim_size[i] != s->arr->dim_size[i]) {
												yyerror("Function parameter mismatch.");
											}
										}

										if(strcmp(s->type,n->id->data)) {
											yyerror("Function parameter type mismatch.");
											break;
										}
										else {
											s = s->next;
											n = n->next;
											if(s != NULL) {
												s->name = n->id->id;
											}
										}	
									}

									if (s != NULL || n != NULL) {
										yyerror("Function parameter mismatch.");
									}
									else {
										p->func->header_declared = 1;
									}

									scope++;
									var_decl($3, NULL);
									scope--;
									currtb = symtb;
									fprintf(fd, "%s:\n", $1->key);
									fprintf(fd3, "start %s\n", $1->key);
								}
								else {
									yyerror("Class method incorrectly declared.");
								}
								header_t k;
								k.name = p->key;
							}
					| func_header_start LPAREN parameter_list RPAREN {
								struct hashnode_s *p = hashtbl_lookup(currtb, scope, $1.name, 0);
								currfunc = p;
								if((p!=NULL) && strcmp(p->data, "#")) {
									yyerror("Variable is not a function.");
								}

								if (p != NULL && p->istype == 0) {
									yyerror("Function already declared.");
								}
								else if (p != NULL && p->istype == 1) { //we have header b4 body
									//check if params are correct 
									id_list_t *n = $3;
									par_list_t *s = p->func->node;

									while(s && n) {
										if(!(n->id->arr==NULL&& s->arr==NULL) && !(n->id->arr == NULL || s->arr == NULL) && (n->id->arr->dims != s->arr->dims)) {
											yyerror("Function parameter mismatch.");
										}
										else if(n->id->arr!=NULL && s->arr !=NULL)for (int i= 0; i < s->arr->dims; i++) {
											if(n->id->arr->dim_size[i] != s->arr->dim_size[i]) {
												yyerror("Function parameter mismatch.");
											}
										}

										if(strcmp(s->type,n->id->data)) {
											yyerror("Function parameter type mismatch.");
											break;
										}
										else {
											s = s->next;
											n = n->next;
											s->name = n->id->id;
										}
									}

									if (s != NULL || n != NULL) {
										yyerror("Function parameter mismatch.");
									}
									else {
										p->func->header_declared = 1;
									}
									
									scope++;
									var_decl($3, NULL);
									scope--;
									fprintf(fd, "%s:\n", $1.name);
									fprintf(fd3, "start %s\n", $1.name);
								}
								else if (p == NULL) {
									fprintf(fd, "%s:\n", $1.name);
									fprintf(fd3, "start %s\n", $1.name);
									hashtbl_insert(currtb, $1.name, "#", scope, NULL, 0, currvis, NULL, &currlist);
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
										p2->name = n->id->id;
										p2->next = NULL;

										if (!head) {
											head = p2;
											tail = p2;
										}
										else {
											tail->next = p2;
											tail = p2;
										}
										n = n->next;

									}

									p->func->node = head;
									scope++;
									var_decl($3, NULL);
									scope--;
								}
								$$ = $1;
							};
class_func_header_start : typename func_class ID {
								struct hashnode_s *p =hashtbl_lookup(currtb, scope, $2, currvis);
								currclass = p;
								if(p==NULL) {
									yyerror("Class doesn't exist.");
								}
								
								if((p = hashtbl_lookup(p->cla->classtb, 55555, $3, currvis)) == NULL) {
									yyerror("Method doesn't exist.");
								}
								
								if(strcmp(p->func->ret_type, $1)) {
									yyerror("Method type mismatch.");
								}
								
								if(strcmp(p->data, "#")) {
									yyerror("Member is not a method.");
								}
								$$ = p;
							}
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
pass_variabledef : variabledef {$$ = $1;}
					| REFER ID {
						$$ = malloc(sizeof(id_t));
						$$->id = $2;
						$$->arr = malloc(sizeof(array_t));	
						$$->arr->dims = -1;	/* this is how you tell it that it's a reference*/
					};
nopar_class_func_header : class_func_header_start LPAREN RPAREN {
													if($1->func != NULL) {
														yyerror("Function header mismatch");
													}
													$$ = $1;
												};
decl_statements : declarations statements
		| declarations
		| statements | ;
declarations : declarations decltype typename variabledefs SEMI {
													int old_scope = scope;
													
													if($2) scope = 0;

													var_decl($4, $3);
													scope = old_scope;
												}
		| decltype typename variabledefs SEMI{
										int old_scope = scope;
										
										if($1) scope = 0;
										
										var_decl($3, $2);
										scope = old_scope;
									};
decltype : STATIC {$$ = 1;} | {$$ = 0;};
statements : statements statement {reg = 0; freg = 0; reg2 = 0; freg2= 0;}
			| statement {reg = 0; freg = 0; reg2= 0; freg2 = 0;};
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
if_statement : IF LPAREN general_expression if_mid RPAREN statement %prec LOWER_THAN_ELSE{
												fprintf(fd, "L%d:\n", label_count);
												fprintf(fd3, "L%d:\n", label_count);
											} 
			|IF LPAREN general_expression if_mid RPAREN statement ELSE statement;
if_mid: {
	if(logical_case) {
		logical_case = 0;
		fprintf(fd3, "esc%d:\n", ++label_count);
	}
	
	fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);
	fprintf(fd3, "bne %s, $0,\tL%d\n", lastname, label_count);
};
while_statement : WHILE LPAREN {
					fprintf(fd, "L%d:\n", ++label_count);
					fprintf(fd3, "L%d:\n", label_count);
					scope++;
				}
				general_expression {
					if(logical_case) {
						logical_case = 0;
						fprintf(fd3, "esc%d:\n", ++label_count);
					}
					
					fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);
					fprintf(fd3, "bne %s, $0, L%d\n", lastname, label_count);
				}
				RPAREN statement {
					scope--;
					fprintf(fd, "jal,\t,\t,\tL%d\n", label_count-1);
					fprintf(fd3, "jal L%d\n", label_count-1);
					fprintf(fd, "L%d:\n", label_count);
					fprintf(fd3, "L%d:\n", label_count);
				};
for_statement : FOR {scope++;} 
				LPAREN optexpr SEMI {
					fprintf(fd, "L%d:\n", ++label_count);
					fprintf(fd3, "L%d:\n", label_count);
				}
				optexpr {
					if(logical_case) {
						logical_case = 0;
						fprintf(fd3, "esc%d:\n", ++label_count);
					}
					
					fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);
					fprintf(fd3, "bne %s, $0, L%d\n", lastname, label_count);
					noprint=1;
				}
				SEMI optexpr {noprint=0;}
				RPAREN statement{
					print_ir($10->exp->node);
					fprintf(fd, "jal,\t,\t,\tL%d\n", label_count-1);
					fprintf(fd3, "jal L%d\n", label_count-1);
					fprintf(fd, "L%d:\n", label_count);
					fprintf(fd3, "L%d:\n", label_count);
					scope--;
				};
optexpr : general_expression {$$ = $1;} | {$$ = NULL;};
return_statement : RETURN optexpr SEMI {
							if($2->exp->name != NULL) {
								if($2 != NULL) {
									fprintf(fd, "\n=,\t%s,\t,\t$a0\n", $2->exp->name);
								}
								
								if(logical_case) {
									logical_case = 0;
									fprintf(fd3, "esc%d:\n", ++label_count);
								}
								
								if($2->exp->name[0] != '$') {
									fprintf(fd3, "li $a0 %s\n", $2->exp->name); 
								}
								else if($2->exp->name[0] == '$' || $2->exp->name[0] == 't') {
									fprintf(fd3, "mv $a0, %s\n", $2->exp->name);
								}
								else {
									fprintf(fd3, "li $a0, %s\n", $2->exp->name);
								}
							}
						};
io_statement : CIN INP in_list SEMI | COUT OUT out_list SEMI;
in_list : in_list INP in_item | in_item;
in_item : variable;
out_list: out_list OUT out_item | out_item
out_item: general_expression | STRING;
comp_statement: LBRACE          {scope++;}
				decl_statements {hashtbl_get(currtb, scope);scope--;}
				RBRACE;
main_function: main_header {
					header_decl_check(currtb);
					scope++;
					fpoff = 0;
				}
				LBRACE decl_statements RBRACE {
					scope--;
					/*hashtbl_get(currtb, scope);*/
					return 0;
				};
main_header: INT MAIN LPAREN RPAREN {
					currfunc = hashtbl_lookup(symtb, 0, "main", 0);
					printf("%p\n", currfunc);
					fprintf(fd, "\nmain:\n");
					fprintf(fd3, "start main\n");
				};

%%

void header_decl_check(HASHTBL *hashtbl) {
	hash_size i;
	struct hashnode_s *node, *old;

	for (i = 0; i < hashtbl->size; ++i) {
		node = hashtbl->nodes[i];
		while(node) {
			if(!strcmp(node->data, "#") && (node->func->header_declared == 0) && (strcmp(node->key, "main"))) {
				yyerror("Function header without declaration.");
			}
			else {
				node = node->next;
			}
		}
	}
}
void var_decl(id_list_t *var_list, char *data) {
	id_list_t *curr = var_list, *prv = var_list;

	while (curr) {
		struct hashnode_s *p = hashtbl_lookup(currtb, scope, curr->id->id, 0);

		if(p != NULL && p->scope == scope) {
			yyerror("Variable double declaration.");
		}
		else if(data == NULL) {
			hashtbl_insert(currtb, curr->id->id, curr->id->data, scope, curr->id->arr, 0, currvis,curr->id->init_vals, &currlist);
			printf("data = %s, key = %s\n", data, curr->id->id);
		}
		else {
			hashtbl_insert(currtb, curr->id->id, data, scope, curr->id->arr, 0, currvis, curr->id->init_vals, &currlist);
			printf("data = %s, key = %s\n", data, curr->id->id);
		}
		
		if(currfunc != NULL && scope != 0) {
			currfunc->funcsize = currfunc->funcsize + findsize2(hashtbl_lookup(currtb, scope, curr->id->id, 0), currtb, scope);
		}
		
		fpoff = fpoff + findsize2(hashtbl_lookup(currtb, scope, curr->id->id, 3), currtb, scope);
		printf("fpoff for %s is %d\n", curr->id->id, fpoff);
		bindf *temp = currlist;
		bindf *old;

		if(currfunc == NULL && scope == 0) {
			currfunc = malloc(sizeof(struct hashnode_s));
			currfunc->key = strdup("global");
			currfunc->data = NULL;
		}

		while(temp && currfunc) {
			if(!strcmp(&temp->name[1], currfunc->key)) {
				bindv *new = malloc(sizeof(bindv));
				new->scope = scope;
				new->name = curr->id->id;
				new->offset = fpoff;
				new->next = NULL;

				if(data == NULL) {
					new->type = curr->id->data;
				}
				else {
					new->type = data;
				}

				if (scope  == 0) {
					old = temp;
					temp = currlist;
				}
				
				if (temp->head == NULL) {
					temp->head = new;
				}
				else {
					bindv* last = temp->head;
					while (last->next) {
						last = last->next;
					}

					last->next = new;
					if(scope==0) {
						temp = old;
					}
				}
			}
			temp = temp->next;
		}
		curr = curr->next;
		prv = curr;
	}
	if( currfunc != NULL && !strcmp(currfunc->key, "global") && currfunc->data == NULL) {
		free(currfunc->key);
		free(currfunc);
		currfunc = NULL;
	}
	print_list();
}

void print_list() {
	bindf *temp = currlist;
	bindv *temp2;
	while (temp) {
		printf("IN %s:\n", temp->name);
		temp2 = temp->head;
		while(temp2) {
			printf("\t%s, o=%d,\n", temp2->name, temp2->offset);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void yyerror(const char *s) {
	printf("error: %s in line: %d\n", s, yylineno);
	exit(255);
}

static void print_tree_rec(const asd_t *node, const char *prefix, int is_left) {
    if (!node) return;
    /* Print current node */
    printf("%s", prefix);
    printf(is_left ? "├── " : "└── ");
    printf("%s\n", node->name ? node->name : "(null)");
    /* Prepare prefix for children */
    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");
    /* Recurse: left first, then right */
    if (node->lchild || node->rchild) {
        if (node->lchild) {
            print_tree_rec(node->lchild, new_prefix, 1);
		}

        if (node->rchild) {
            print_tree_rec(node->rchild, new_prefix, 0);
		}
    }
}

void print_tree(const asd_t *root){	
    if (!root) {
        printf("(empty tree)\n");
        return;
    }
    printf("%s\n", root->name ? root->name : "(null)");

    if (root->lchild) {
        print_tree_rec(root->lchild, "", 1);
	}

    if (root->rchild) {
        print_tree_rec(root->rchild, "", 0);
	}
}

asd_t *create_node(const char *s, asd_t *lleaf, asd_t *rleaf) {
	asd_t *node = malloc(sizeof(asd_t));
	if(s != NULL) {
		node->name = malloc(strlen(s) + 1);
		strcpy(node->name, s);
	}
	
	node->lchild = lleaf;
	node->rchild = rleaf;

	return node;
}
char *print_ir(const asd_t *root) {
    if (!root) return NULL;

    if (root->lchild == NULL && root->rchild == NULL) {
		char *name;
		name = malloc(sizeof(char) * (strlen(root->name) + 1));
		strcpy(name, root->name);
		lastname = name;
        return name;
    }

    char *lname = print_ir(root->lchild);
    char *rname = print_ir(root->rchild);
	char temp[15];
	char *i;

    if (!lname && rname) {
        fprintf(fd, "%s,\t,\t%s,\t%s\n", root->name, rname, rname);
		fprintf(fd3, "\n");

		char *name = malloc(sizeof(char) * 10);
		sprintf(name, "$t%d", reg);
		print_assembly(name, lname, rname, root);
		lastname = lname;

		return NULL;
    }
	else if(lname && !rname) {
        fprintf(fd, "%s,\t%s,\t,\t%s\n", root->name, lname, lname);

		char *name = malloc(sizeof(char) * 10);
		
		if(strstr(lname, ".") != NULL) {
			sprintf(name, "$f%d", freg);
		}
		else {
			sprintf(name, "$t%d", reg);
		}
		print_assembly(name, lname, rname, root);
		lastname = lname;

		return NULL;
    }
	else if (!strcmp(root->name, "=")) {
        printf("%s %s %s\n", lname, root->name, rname);

		if(lname[0] != '$') {
			fprintf(fd, "sw,\t%s,\t,\t%s\n", rname, lname);
		}
		else {
			fprintf(fd, "=,\t%s,\t,\t%s\n", rname, lname);
		}

		strcpy(temp, lname);
		i = strstr(temp , "fp");

		if(i == NULL) {
			i = strstr(temp, "gp");
		}
		
		if(i != NULL) {
			*i = '\0';
		}
		
		if(lname[0] != '$') {
			fprintf(fd3, "addi $t%d, %s, %s\n", ++reg2, &lname[i-temp], &temp[4]);
			if((atoi(rname) || rname[0] != '0') && strstr(rname, ".") != NULL) {
				fprintf(fd3, "li $t%d, %s\n", ++reg2, rname);
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "fsw $f%d, 0($t%d)\n", freg2, reg2-1);
			}
			else if(rname[0] == '$' && rname[1] == 'f') {
				fprintf(fd3, "fsw %s, 0($t%d)\n", rname, reg2);
			}
			else if(rname[0] == '$' && rname[1] != 'f') {
				fprintf(fd3, "fcvt.s.w $f%d, %s\n", ++freg2, rname);
				fprintf(fd3, "fsw $f%d, 0($t%d)\n", freg2, reg2);
			}
			else {
				fprintf(fd3, "sw %s, 0($t%d)\n", rname, reg2);
			}
		}
		else if(rname[0] == '$' || lname[0] == '$'){ 
			if((rname[1] == 't' || rname[1] == 'a') && (lname[1] == 't' || lname[1] == 'a')) {
				fprintf(fd3, "mv %s, %s\n", lname, rname);
			}
			else if(lname[1] == 'f' && rname[1] == 'f') {
				fprintf(fd3, "f.mv %s, %s\n", lname, rname);
			}
			else if(lname[1] == 'f') {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
			}
		} 
		else {
			fprintf(fd3, "li %s, %s\n", lname, rname);
		}

		char *name = malloc(sizeof(char) * 10);
		sprintf(name, "$t%d", reg);
		print_assembly(name, lname, rname, root);
		lastname = lname;
        return NULL;
    }
    else {
        printf("%s %s %s => $t%d\n", lname, root->name, rname, reg);
    }

    reg++;
    char *name = malloc(sizeof(char) * 10);
    sprintf(name, "$t%d", reg);
    fprintf(fd, "%s,\t%s,\t%s,\t%s\n", root->name, lname, rname, name);
	print_assembly(name, lname, rname, root);
    lastname = name;

    return name;
}

void print_assembly(char *name, char* lname, char* rname, const asd_t *root) {
	if((logical_case == 1) && (strcmp(root->name, "&&") && strcmp(root->name, "||"))) {
		fprintf(fd3, "esc%d:\n", ++label_count);
	}

	logical_case = 0;
	if(*root->name == '+') {
		if((lname[0]=='0' && rname[0] == '0') ||(atoi(lname) && atoi(rname))) {
			if(strstr(rname, ".")!=NULL || strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)(strtof(lname, NULL) + strtof(rname, NULL)));
				fprintf(fd3, "fmv.w.x %s, $t%d\n", name, reg2);
			}
			else {
				fprintf(fd3, "li %s, %d\n", name, atoi(lname) + atoi(rname));
			}
		}
		else if(atoi(lname) || lname[0] == '0') {
			if(strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(lname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.add.s %s, %s, $f%d\n", name, rname, freg2);
			}
			else {
				fprintf(fd3, "addi %s, %s, %d\n", name, rname, atoi(lname)); // REVERSED
			}
		}
		else if(atoi(rname) || rname[0] == '0') {
			if(strstr(rname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.add.s %s, %s, $f%d\n", name, lname, freg2);
			}
			else {
				fprintf(fd3, "addi %s, %s, %d\n", name, lname, atoi(rname));
			}
		}
		else {
			if(name[1] = 'f') {
				fprintf(fd3, "f.add.s %s, %s, %s\n",name, lname, rname);
			}
			else {
				fprintf(fd3, "add %s, %s, %s\n", name, lname, rname);
			}
		}
	}
	else if(*root->name == '-') {
		if((lname[0]=='0' && rname[0] == '0') || (atoi(lname) && atoi(rname))) {
			if(strstr(rname, ".")!=NULL || strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)(strtof(lname, NULL) - strtof(rname, NULL)));
				fprintf(fd3, "fmv.w.x %s, $t%d\n", name, reg2);
			}
			else {
				fprintf(fd3, "li %s, %d\n", name, atoi(lname) - atoi(rname));
			}
		}
		else if(atoi(lname) || lname[0] == '0') {
			if(strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(lname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.sub.s %s, $f%d, %s\n", name, freg2, rname);
			}

			fprintf(fd3, "li $t%d, %d", ++reg2, atoi(lname));
			fprintf(fd3, "sub %s, $t%d, %s\n", name, reg2, rname);
		}
		else if(atoi(rname) || rname[0] == '0') {
			if(strstr(rname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.sub.s %s, %s, $f%d\n", name, lname, freg2);
			}

			fprintf(fd3, "subi %s, %s, %d\n", name,  lname, atoi(rname));
		}
		else {
			if(name[1] == 'f') {
				fprintf(fd3, "f.sub.s %s, %s, %s\n", name, lname, rname);
			}
			else {
				fprintf(fd3, "sub %s, %s, %s\n", name, lname, rname);
			}
		}
	}
	else if(*root->name == '*') {
		if((lname[0]=='0' && rname[0] == '0') || (atoi(lname) && atoi(rname))) {
			if(strstr(rname, ".")!=NULL || strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)(strtof(lname, NULL) * strtof(rname, NULL)));
				fprintf(fd3, "fmv.w.x %s, $t%d\n", name, reg2);
			}

			fprintf(fd3, "li %s, %d\n", name, atoi(lname) * atoi(rname));
		}
		else if(atoi(lname) || lname[0] == '0') {
			if(strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(lname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.mul.s %s, $f%d, %s\n", name, freg2, rname);
			}

			fprintf(fd3, "li $t%d %d", reg2, atoi(lname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "mul %s, $t%d, %s\n", name, reg2-1, rname);
		}
		else if(atoi(rname) || rname[0] == '0') {
			if(strstr(rname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.mul.s %s, %s, $f%d\n", name, lname, freg2);
			}

			fprintf(fd3, "li $t%d %d", reg2, atoi(rname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "mul %s, %s, $t%d\n", name,  lname, reg2-1);
		}
		else {
			if(name[1] == 'f') {
				fprintf(fd3, "f.mul.s %s, %s, %s\n", name, lname, rname);
			}
			else {
				fprintf(fd3, "mul %s, %s, %s\n", name, lname, rname);
			}
		}
	}
	else if(*root->name == '/') {
		if((lname[0]=='0' && rname[0] == '0') || (atoi(lname) && atoi(rname))) {
			if(strstr(rname, ".")!=NULL || strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)(strtof(lname, NULL) / strtof(rname, NULL)));
				fprintf(fd3, "fmv.w.x %s, $t%d\n", name, reg2);
			}

			fprintf(fd3, "li %s, %d\n", name, atoi(lname) / atoi(rname));
		}
		else if(atoi(lname) || lname[0] == '0') {
			if(strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(lname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.div.s %s, $f%d, %s\n", name, freg2, rname);
			}

			fprintf(fd3, "li $t%d %d", reg2, atoi(lname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "div %s, $t%d, %s\n", name, reg2-1, rname);
		}
		else if(atoi(rname) || rname[0] == '0') {
			if(strstr(rname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);
				fprintf(fd3, "f.div.s %s, %s, $f%d\n", name, lname, freg2);
			}

			fprintf(fd3, "li $t%d %d", reg2, atoi(rname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "div %s, %s, $t%d\n", name,  lname, reg2-1);
		}
		else {
			if(name[1] == 'f') {
				fprintf(fd3, "f.div.s %s, %s, %s\n", name, lname, rname);
			}
			else {
				fprintf(fd3, "div %s, %s, %s\n", name, lname, rname);
			}
		}
	}
	else if(*root->name == '%') {
		if((lname[0]=='0' && rname[0] == '0') || (atoi(lname) && atoi(rname))) {
			fprintf(fd3, "li %s, %d\n", name, atoi(lname) % atoi(rname));
		}
		else if(atoi(lname) || lname[0] == '0') {
			fprintf(fd3, "li $t%d %d", reg2, atoi(lname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "rem %s, $t%d, %s\n", name, reg2-1, rname);
		}
		else if(atoi(rname) || rname[0] == '0') {
			fprintf(fd3, "li $t%d %d", reg2, atoi(rname));
			sprintf(name, "$t%d", ++reg2);
			fprintf(fd3, "rem %s, %s, $t%d\n", name,  lname, reg2-1);
		}
		else {
			fprintf(fd3, "rem %s, %s, %s\n", name, lname, rname);
		}
	}
	else if(!strcmp(root->name, "==") || !strcmp(root->name, ">=") || !strcmp(root->name, "<=") || !strcmp(root->name, ">") || !strcmp(root->name, "<") || !strcmp(root->name, "!=")) {
		if((lname[0]=='0' && rname[0] == '0') || (atoi(lname) && atoi(rname))) {
			if(strstr(rname, ".")!=NULL || strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)(strtof(lname, NULL) - strtof(rname, NULL)));
			}
			else {
				fprintf(fd3, "li $t%d, %d\n", ++reg2, atoi(lname) - atoi(rname));
			}
		}
		else if(atoi(lname) || lname[0] == '0') {
			if(strstr(lname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(lname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);

				if(rname[0] == '$') {
					fprintf(fd3, "f.sub.s $f%d, $f%d, %s\n", ++freg2, freg2, rname);
					fprintf(fd3, "fcvt.w.s %s, $f%d\n", name, freg2);
				}
			}

			fprintf(fd3, "subi $t%d, %s, %d\n", ++reg2, rname, atoi(lname));
		}
		else if(atoi(rname) || rname[0] == '0') {
			if(strstr(rname, ".")!=NULL) {
				fprintf(fd3, "li $t%d, 0x%x\n", ++reg2, (uint32_t)strtof(rname, NULL));
				fprintf(fd3, "fmv.w.x $f%d, $t%d\n", ++freg2, reg2);

				if(rname[0] == '$') {
					fprintf(fd3, "f.sub.s $f%d, $f%d, %s\n", ++freg2, freg2, lname);
					fprintf(fd3, "fcvt.w.s %s, $f%d\n", name, freg2);
				}
			}

			fprintf(fd3, "subi $t%d, %s, %d\n", ++reg2, lname, atoi(rname));
		}
		else if(rname[0] == '$' && lname[0] == '$') {
			if(rname[1] == 'f' && lname[1] == 'f') {
				fprintf(fd3, "f.sub.s $f%d, %s, %s\n", ++freg2, lname, rname);
			}
			else {
				fprintf(fd3, "sub $t%d, %s, %s\n", ++reg2, lname, rname);
			}
		}
		else if(rname[0] == '$') {
			fprintf(fd3, "subi $t%d, %s, %d\n", ++reg2, rname, *lname);
		}
		else if(lname[0] == '$') {
			fprintf(fd3, "subi $t%d, %s, %d\n", ++reg2, lname, *rname);
		}
		else {
			fprintf(fd3, "li $t%d, %d\n", ++reg2, *lname - *rname);
		}
		
		if(!strcmp(root->name, "==")) {
			fprintf(fd3, "xori $t%d, $t%d, 1\n", reg2, reg2);
		}
		else if(!strcmp(root->name, ">")) {
			fprintf(fd3, "slt $t%d, $t%d, $0\n", reg2, reg2);
		}
		else if(!strcmp(root->name, "<")){
			fprintf(fd3, "xori $t%d, $t%d, 1\n", reg2, reg2);
			fprintf(fd3, "slt $t%d, $t%d, $0\n", reg2, reg2);
		}
		else if(!strcmp(root->name, ">=")) {
			fprintf(fd3, "subi $t%d, $t%d, 1\n", reg2, reg2);
			fprintf(fd3, "slt $t%d, $t%d, $0\n", reg2, reg2);
		}
		else if(!strcmp(root->name, "<=")) {
			fprintf(fd3, "addi $t%d, $t%d, 1\n", reg2, reg2);
			fprintf(fd3, "xori $t%d, $t%d, 1\n", reg2, reg2);
			fprintf(fd3, "slt $t%d, $t%d, $0\n", reg2, reg2);
		}
		//fprintf(fd3, "slt $t%d, $t%d, $0\n", reg2, reg2);
	}
	else if(!strcmp(root->name, "&&") ||  !strcmp(root->name, "||")) {
		logical_case = 1;
		if(lname[0] == '$' && rname[0] == '$') {
			if(!strcmp(root->name, "&&")) {
				fprintf(fd3, "and $t%d, %s, %s\n", ++reg2, lname, rname);
			}
			else {
				fprintf(fd3, "or $t%d, %s, %s\n", ++reg2, lname, rname);
			}
		}
		else if(lname[0] == '$') {
			if(!strcmp(root->name, "&&")) {
				fprintf(fd3, "andi $t%d, %s, %d\n", ++reg2, lname, atoi(rname));
			}
			else {
				fprintf(fd3, "ori $t%d, %s, %d\n", ++reg2, lname, atoi(rname));
			}
		}
		else if(rname[0] == '$') {
			if(!strcmp(root->name, "&&")) {
				fprintf(fd3, "andi $t%d, %s, %d\n", ++reg2, rname, atoi(lname));
			}
			else {
				fprintf(fd3, "ori $t%d, %s, %d\n", ++reg2, rname, atoi(lname));
			}
		}
		else if(!strcmp(root->name, "&&")) {
			fprintf(fd3, "li $t%d, %d\n", ++reg2, atoi(lname) && atoi(rname));
		}
		else {
			fprintf(fd3, "li $t%d %d\n", ++reg2, atoi(lname) || atoi(rname));
		}
		
		if(!strcmp(root->name, "&&")) {
			fprintf(fd3, "beq $t%d, $0, esc%d\n", reg2, label_count+1);
		}
		else {
			fprintf(fd3, "bneq $t%d, $0, esc%d\n", reg2, label_count+1);
		}
	}
}

void patchinc() {
	post_t *temp = postlist;

	while(temp != NULL) {
		if(!temp->sign) {
			fprintf(fd, "+,\t%s,\t1,\t%s\n", temp->name, temp->name);
			fprintf(fd3, "addi %s, %s, 1\n", temp->name, temp->name);
		}
		else {
			fprintf(fd, "-,\t%s,\t1,\t%s\n", temp->name, temp->name);
			fprintf(fd3, "subi %s, %s, 1\n", temp->name, temp->name);
		}
		
		temp = temp->next;
	}
	
	postlist = NULL;
}

int findsize(struct hashnode_s *n) { 
	if(n== NULL || n->data == NULL) return 0;

	if (!strcmp(n->data,"int"))
		return sizeof(int);
	else if (!strcmp(n->data,"char"))
		return sizeof(char);
	else if (!strcmp(n->data, "float"))
		return sizeof(float);
	else {
		struct hashnode_s *tmp;
		tmp = hashtbl_lookup(currtb, scope, n->data, currvis);
		return findsize(tmp);
	}
	return 0;
}

bindv *findoff(char *fname, char *name) {
	bindf *temp = currlist;
	bindv *temp2;

	while(temp) {
		printf("name = %s\n", temp->name);

		if(!strcmp(temp->name, fname)) {

			temp2 = temp->head;
			while(temp2) {
				printf("name = %s\n", temp2->name);

				if(!strcmp(name, temp2->name)) {return temp2;}

				temp2 = temp2->next;
				if(temp2 == NULL && fname[0] == 'c') {
					char *str = malloc(20);
					struct hashnode_s *k = hashtbl_lookup(symtb, scope, &fname[1], currvis);
					sprintf(str, "c%s", k->cla->superclass);

					return findoff(str, name);
				}
			}
		}
		temp = temp->next;
	}
	return NULL;
}

void normalize_node(asd_t **tmp1, asd_t **tmp2, asd_t *node1, asd_t *node2, char *name1, char *name2) {
	if(node1 == NULL) {
		*tmp1=create_node(name1, NULL, NULL);
	}
	else {
		*tmp1=node1;
	}

	if(node2 == NULL) {
		*tmp2=create_node(name2, NULL, NULL);
	}
	else {
		*tmp2=node2;
	}
}

void inherit(struct hashnode_s *og) {
	struct hashnode_s *tmp1 = og;
	bindf *k = currlist;
	bindv *tmp2, *tmp3;

	while(k != NULL){
		if(!strcmp(k->name, currfunc->key)) {break;}
		k = k->next;
	}

	if(k != NULL) {tmp3 = k->head;}

	while(tmp3->next != NULL) {tmp3 = tmp3->next;}

	while(tmp1 != NULL && k != NULL) {
		k = currlist;
		while(k != NULL) {
			if(!strcmp(k->name, tmp1->cla->superclass)) {break;}
			k = k->next;
		}

		if(k!=NULL) {tmp2 = k->head;}

		while(tmp2 != NULL && k != NULL) {
			tmp3->next->scope = tmp2->scope;
			tmp3->next->name = strdup(tmp2->name);
			tmp3->next->type = strdup(tmp2->type);
			tmp3->next->offset = tmp2->offset;
			tmp3->next->next = NULL;
			tmp2 = tmp2->next;
			tmp3= tmp3->next;
		}
		tmp1 = hashtbl_lookup(currtb, scope, tmp1->cla->superclass, currvis);
	}
}

int main(){
	fd = fopen("ir.dkk", "w");
	fd3 = fopen("irir.asm", "w");

	symtb = hashtbl_create(10, NULL);
	hashtbl_insert(symtb, "main", "#", 0, NULL, 1, 0, NULL, &currlist);
	currtb = symtb;
	bindf *global = malloc(sizeof(bindf));
	global->name = strdup("gglobal");
	bindf *m = malloc(sizeof(bindf));
	global->next = m;
	m->name = strdup("fmain");
	m->next = NULL;
	currlist = global;

	int res = yyparse();

	FILE *fd_asm = fopen("out.asm", "w");
	print_top(fd_asm, symtb);
	print_txt(fd_asm, symtb);

	//hashtbl_destroy(symtb);
	fclose(fd_asm);
	fclose(fd);
	fclose(fd3);

	exit(res);
}
