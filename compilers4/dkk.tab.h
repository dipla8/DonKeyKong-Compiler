/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DKK_TAB_H_INCLUDED
# define YY_YY_DKK_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPEDEF = 258,                 /* TYPEDEF  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    CONST = 262,                   /* CONST  */
    UNION = 263,                   /* UNION  */
    CLASS = 264,                   /* CLASS  */
    PRIVATE = 265,                 /* PRIVATE  */
    PROTECTED = 266,               /* PROTECTED  */
    PUBLIC = 267,                  /* PUBLIC  */
    STATIC = 268,                  /* STATIC  */
    VOID = 269,                    /* VOID  */
    LIST = 270,                    /* LIST  */
    CONTINUE = 271,                /* CONTINUE  */
    BREAK = 272,                   /* BREAK  */
    THIS = 273,                    /* THIS  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    RETURN = 278,                  /* RETURN  */
    LENGTH = 279,                  /* LENGTH  */
    NEW = 280,                     /* NEW  */
    CIN = 281,                     /* CIN  */
    COUT = 282,                    /* COUT  */
    MAIN = 283,                    /* MAIN  */
    FCONST = 284,                  /* FCONST  */
    CCONST = 285,                  /* CCONST  */
    OROP = 286,                    /* OROP  */
    ANDOP = 287,                   /* ANDOP  */
    NOTOP = 288,                   /* NOTOP  */
    SIZEOP = 289,                  /* SIZEOP  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    SEMI = 292,                    /* SEMI  */
    DOT = 293,                     /* DOT  */
    COMMA = 294,                   /* COMMA  */
    ASSIGN = 295,                  /* ASSIGN  */
    COLON = 296,                   /* COLON  */
    LBRACK = 297,                  /* LBRACK  */
    RBRACK = 298,                  /* RBRACK  */
    REFER = 299,                   /* REFER  */
    LBRACE = 300,                  /* LBRACE  */
    RBRACE = 301,                  /* RBRACE  */
    METH = 302,                    /* METH  */
    INP = 303,                     /* INP  */
    OUT = 304,                     /* OUT  */
    LOWER_THAN_ELSE = 305,         /* LOWER_THAN_ELSE  */
    LPAR = 306,                    /* LPAR  */
    RPAR = 307,                    /* RPAR  */
    ADDOP = 308,                   /* ADDOP  */
    EQUOP = 309,                   /* EQUOP  */
    RELOP = 310,                   /* RELOP  */
    MULOP = 311,                   /* MULOP  */
    INCDEC = 312,                  /* INCDEC  */
    ICONST = 313,                  /* ICONST  */
    ID = 314,                      /* ID  */
    STRING = 315,                  /* STRING  */
    LISTFUNC = 316                 /* LISTFUNC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "dkk.y"
 
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

#line 143 "dkk.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DKK_TAB_H_INCLUDED  */
