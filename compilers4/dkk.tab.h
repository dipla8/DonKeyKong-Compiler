/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_DKK_TAB_H_INCLUDED
# define YY_YY_DKK_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPEDEF = 258,
    CHAR = 259,
    INT = 260,
    FLOAT = 261,
    CONST = 262,
    UNION = 263,
    CLASS = 264,
    PRIVATE = 265,
    PROTECTED = 266,
    PUBLIC = 267,
    STATIC = 268,
    VOID = 269,
    LIST = 270,
    CONTINUE = 271,
    BREAK = 272,
    THIS = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    FOR = 277,
    RETURN = 278,
    LENGTH = 279,
    NEW = 280,
    CIN = 281,
    COUT = 282,
    MAIN = 283,
    FCONST = 284,
    CCONST = 285,
    OROP = 286,
    ANDOP = 287,
    NOTOP = 288,
    SIZEOP = 289,
    LPAREN = 290,
    RPAREN = 291,
    SEMI = 292,
    DOT = 293,
    COMMA = 294,
    ASSIGN = 295,
    COLON = 296,
    LBRACK = 297,
    RBRACK = 298,
    REFER = 299,
    LBRACE = 300,
    RBRACE = 301,
    METH = 302,
    INP = 303,
    OUT = 304,
    EQUOP = 305,
    RELOP = 306,
    ADDOP = 307,
    MULOP = 308,
    LOWER_THAN_ELSE = 309,
    INCDEC = 310,
    LPAR = 311,
    RPAR = 312,
    ICONST = 313,
    ID = 314,
    STRING = 315,
    LISTFUNC = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "dkk.y" /* yacc.c:1909  */
 
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

#line 133 "dkk.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DKK_TAB_H_INCLUDED  */
