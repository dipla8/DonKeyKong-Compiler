/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "dkk.y"

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
void patchinc();
int findsize(struct hashnode_s *n);
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
int noprint = 0;
char *lastname = NULL;
post_t *postlist = NULL;
FILE *fd = NULL;

#line 104 "dkk.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "dkk.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPEDEF = 3,                    /* TYPEDEF  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_UNION = 8,                      /* UNION  */
  YYSYMBOL_CLASS = 9,                      /* CLASS  */
  YYSYMBOL_PRIVATE = 10,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 11,                 /* PROTECTED  */
  YYSYMBOL_PUBLIC = 12,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 13,                    /* STATIC  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_LIST = 15,                      /* LIST  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_THIS = 18,                      /* THIS  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_LENGTH = 24,                    /* LENGTH  */
  YYSYMBOL_NEW = 25,                       /* NEW  */
  YYSYMBOL_CIN = 26,                       /* CIN  */
  YYSYMBOL_COUT = 27,                      /* COUT  */
  YYSYMBOL_MAIN = 28,                      /* MAIN  */
  YYSYMBOL_FCONST = 29,                    /* FCONST  */
  YYSYMBOL_CCONST = 30,                    /* CCONST  */
  YYSYMBOL_OROP = 31,                      /* OROP  */
  YYSYMBOL_ANDOP = 32,                     /* ANDOP  */
  YYSYMBOL_NOTOP = 33,                     /* NOTOP  */
  YYSYMBOL_SIZEOP = 34,                    /* SIZEOP  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_SEMI = 37,                      /* SEMI  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_LBRACK = 42,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 43,                    /* RBRACK  */
  YYSYMBOL_REFER = 44,                     /* REFER  */
  YYSYMBOL_LBRACE = 45,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 46,                    /* RBRACE  */
  YYSYMBOL_METH = 47,                      /* METH  */
  YYSYMBOL_INP = 48,                       /* INP  */
  YYSYMBOL_OUT = 49,                       /* OUT  */
  YYSYMBOL_LOWER_THAN_ELSE = 50,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_LPAR = 51,                      /* LPAR  */
  YYSYMBOL_RPAR = 52,                      /* RPAR  */
  YYSYMBOL_ADDOP = 53,                     /* ADDOP  */
  YYSYMBOL_EQUOP = 54,                     /* EQUOP  */
  YYSYMBOL_RELOP = 55,                     /* RELOP  */
  YYSYMBOL_MULOP = 56,                     /* MULOP  */
  YYSYMBOL_INCDEC = 57,                    /* INCDEC  */
  YYSYMBOL_ICONST = 58,                    /* ICONST  */
  YYSYMBOL_ID = 59,                        /* ID  */
  YYSYMBOL_STRING = 60,                    /* STRING  */
  YYSYMBOL_LISTFUNC = 61,                  /* LISTFUNC  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_global_declarations = 64,       /* global_declarations  */
  YYSYMBOL_global_declaration = 65,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 66,       /* typedef_declaration  */
  YYSYMBOL_67_1 = 67,                      /* $@1  */
  YYSYMBOL_typename = 68,                  /* typename  */
  YYSYMBOL_standard_type = 69,             /* standard_type  */
  YYSYMBOL_listspec = 70,                  /* listspec  */
  YYSYMBOL_dims = 71,                      /* dims  */
  YYSYMBOL_const_declaration = 72,         /* const_declaration  */
  YYSYMBOL_constdefs = 73,                 /* constdefs  */
  YYSYMBOL_constdef = 74,                  /* constdef  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_variable = 76,                  /* variable  */
  YYSYMBOL_general_expression = 77,        /* general_expression  */
  YYSYMBOL_assignment = 78,                /* assignment  */
  YYSYMBOL_expression_list = 79,           /* expression_list  */
  YYSYMBOL_constant = 80,                  /* constant  */
  YYSYMBOL_listexpression = 81,            /* listexpression  */
  YYSYMBOL_class_declaration = 82,         /* class_declaration  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_class_body = 84,                /* class_body  */
  YYSYMBOL_parent = 85,                    /* parent  */
  YYSYMBOL_members_methods = 86,           /* members_methods  */
  YYSYMBOL_access = 87,                    /* access  */
  YYSYMBOL_member_or_method = 88,          /* member_or_method  */
  YYSYMBOL_member = 89,                    /* member  */
  YYSYMBOL_var_declaration = 90,           /* var_declaration  */
  YYSYMBOL_variabledefs = 91,              /* variabledefs  */
  YYSYMBOL_variabledef = 92,               /* variabledef  */
  YYSYMBOL_93_3 = 93,                      /* $@3  */
  YYSYMBOL_94_4 = 94,                      /* $@4  */
  YYSYMBOL_anonymous_union = 95,           /* anonymous_union  */
  YYSYMBOL_union_body = 96,                /* union_body  */
  YYSYMBOL_fields = 97,                    /* fields  */
  YYSYMBOL_field = 98,                     /* field  */
  YYSYMBOL_method = 99,                    /* method  */
  YYSYMBOL_short_func_declaration = 100,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 101,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 102,        /* func_header_start  */
  YYSYMBOL_parameter_types = 103,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 104,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 105,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 106,        /* union_declaration  */
  YYSYMBOL_107_5 = 107,                    /* $@5  */
  YYSYMBOL_global_var_declaration = 108,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 109,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 110,         /* init_variabledef  */
  YYSYMBOL_initializer = 111,              /* initializer  */
  YYSYMBOL_112_6 = 112,                    /* $@6  */
  YYSYMBOL_init_value = 113,               /* init_value  */
  YYSYMBOL_init_values = 114,              /* init_values  */
  YYSYMBOL_func_declaration = 115,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 116,    /* full_func_declaration  */
  YYSYMBOL_117_7 = 117,                    /* $@7  */
  YYSYMBOL_118_8 = 118,                    /* $@8  */
  YYSYMBOL_119_9 = 119,                    /* $@9  */
  YYSYMBOL_full_par_func_header = 120,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 121,  /* class_func_header_start  */
  YYSYMBOL_func_class = 122,               /* func_class  */
  YYSYMBOL_parameter_list = 123,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 124,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 125,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 126,          /* decl_statements  */
  YYSYMBOL_declarations = 127,             /* declarations  */
  YYSYMBOL_decltype = 128,                 /* decltype  */
  YYSYMBOL_statements = 129,               /* statements  */
  YYSYMBOL_statement = 130,                /* statement  */
  YYSYMBOL_expression_statement = 131,     /* expression_statement  */
  YYSYMBOL_if_statement = 132,             /* if_statement  */
  YYSYMBOL_if_mid = 133,                   /* if_mid  */
  YYSYMBOL_while_statement = 134,          /* while_statement  */
  YYSYMBOL_135_10 = 135,                   /* $@10  */
  YYSYMBOL_136_11 = 136,                   /* $@11  */
  YYSYMBOL_for_statement = 137,            /* for_statement  */
  YYSYMBOL_138_12 = 138,                   /* $@12  */
  YYSYMBOL_139_13 = 139,                   /* $@13  */
  YYSYMBOL_140_14 = 140,                   /* $@14  */
  YYSYMBOL_141_15 = 141,                   /* $@15  */
  YYSYMBOL_optexpr = 142,                  /* optexpr  */
  YYSYMBOL_return_statement = 143,         /* return_statement  */
  YYSYMBOL_io_statement = 144,             /* io_statement  */
  YYSYMBOL_in_list = 145,                  /* in_list  */
  YYSYMBOL_in_item = 146,                  /* in_item  */
  YYSYMBOL_out_list = 147,                 /* out_list  */
  YYSYMBOL_out_item = 148,                 /* out_item  */
  YYSYMBOL_comp_statement = 149,           /* comp_statement  */
  YYSYMBOL_150_16 = 150,                   /* $@16  */
  YYSYMBOL_151_17 = 151,                   /* $@17  */
  YYSYMBOL_main_function = 152,            /* main_function  */
  YYSYMBOL_153_18 = 153,                   /* $@18  */
  YYSYMBOL_main_header = 154               /* main_header  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    84,    84,    85,    86,    87,    88,    89,
      90,    91,    91,    92,    93,    94,    95,    96,    97,    98,
      98,    99,   127,   145,   147,   148,   148,   149,   151,   156,
     161,   167,   175,   184,   193,   197,   208,   209,   211,   212,
     213,   232,   233,   234,   235,   236,   237,   238,   276,   306,
     323,   367,   368,   369,   370,   375,   376,   377,   377,   378,
     379,   380,   381,   382,   382,   383,   384,   384,   385,   385,
     386,   386,   386,   386,   387,   388,   389,   390,   391,   392,
     398,   404,   404,   414,   414,   419,   420,   421,   421,   422,
     423,   424,   424,   434,   443,   443,   444,   450,   457,   457,
     458,   459,   459,   460,   461,   468,   476,   477,   477,   477,
     478,   479,   480,   481,   482,   483,   483,   484,   484,   485,
     485,   486,   486,   487,   514,   569,   570,   571,   572,   580,
     587,   587,   592,   593,   594,   595,   595,   596,   597,   598,
     598,   599,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   614,   614,
     615,   615,   615,   615,   615,   616,   616,   617,   618,   618,
     619,   619,   620,   621,   621,   622,   622,   623,   623,   623,
     624,   624,   625
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPEDEF", "CHAR",
  "INT", "FLOAT", "CONST", "UNION", "CLASS", "PRIVATE", "PROTECTED",
  "PUBLIC", "STATIC", "VOID", "LIST", "CONTINUE", "BREAK", "THIS", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "LENGTH", "NEW", "CIN", "COUT", "MAIN",
  "FCONST", "CCONST", "OROP", "ANDOP", "NOTOP", "SIZEOP", "LPAREN",
  "RPAREN", "SEMI", "DOT", "COMMA", "ASSIGN", "COLON", "LBRACK", "RBRACK",
  "REFER", "LBRACE", "RBRACE", "METH", "INP", "OUT", "LOWER_THAN_ELSE",
  "LPAR", "RPAR", "ADDOP", "EQUOP", "RELOP", "MULOP", "INCDEC", "ICONST",
  "ID", "STRING", "LISTFUNC", "$accept", "program", "global_declarations",
  "global_declaration", "typedef_declaration", "$@1", "typename",
  "standard_type", "listspec", "dims", "const_declaration", "constdefs",
  "constdef", "expression", "variable", "general_expression", "assignment",
  "expression_list", "constant", "listexpression", "class_declaration",
  "$@2", "class_body", "parent", "members_methods", "access",
  "member_or_method", "member", "var_declaration", "variabledefs",
  "variabledef", "$@3", "$@4", "anonymous_union", "union_body", "fields",
  "field", "method", "short_func_declaration", "short_par_func_header",
  "func_header_start", "parameter_types", "pass_list_dims",
  "nopar_func_header", "union_declaration", "$@5",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "initializer", "$@6", "init_value", "init_values", "func_declaration",
  "full_func_declaration", "$@7", "$@8", "$@9", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "if_mid", "while_statement",
  "$@10", "$@11", "for_statement", "$@12", "$@13", "$@14", "$@15",
  "optexpr", "return_statement", "io_statement", "in_list", "in_item",
  "out_list", "out_item", "comp_statement", "$@16", "$@17",
  "main_function", "$@18", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -234,    10,   220,  -234,   140,  -234,    -8,  -234,   140,   -25,
      29,  -234,   115,  -234,  -234,  -234,    33,  -234,  -234,  -234,
    -234,    71,   144,   138,  -234,  -234,  -234,  -234,  -234,   153,
    -234,  -234,  -234,  -234,   183,   157,   148,  -234,  -234,   161,
     155,   163,    25,   198,    30,  -234,   185,  -234,    23,  -234,
     211,   218,   127,   219,   222,  -234,   221,   232,  -234,   116,
    -234,   230,   242,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
      42,  -234,  -234,    26,     6,    59,   224,   224,  -234,    60,
      98,   224,   224,  -234,  -234,   234,  -234,   148,   140,   249,
     243,   254,   258,  -234,   268,   394,  -234,  -234,   163,   252,
    -234,  -234,  -234,  -234,  -234,   140,  -234,   140,  -234,   277,
     278,  -234,   283,   284,  -234,   432,   291,   296,   289,   299,
    -234,  -234,   550,   550,   143,  -234,   446,  -234,   550,    18,
    -234,   310,   379,   149,   270,  -234,  -234,  -234,   303,   271,
     146,   317,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
     311,   252,  -234,   314,   315,  -234,   394,   -28,  -234,    42,
    -234,   112,  -234,  -234,  -234,  -234,   261,   268,   394,  -234,
     379,    49,  -234,   304,  -234,   268,    46,    60,  -234,  -234,
     550,  -234,   329,   326,   330,   550,   550,    18,   484,   164,
    -234,   332,   158,   326,   323,   224,   313,   128,   550,   550,
     550,   550,   550,   550,   550,   446,   312,   498,   550,  -234,
    -234,   550,  -234,   146,   317,    56,    42,  -234,  -234,  -234,
    -234,   122,  -234,  -234,   336,   288,  -234,  -234,  -234,   331,
     343,   351,   170,    48,  -234,    96,  -234,  -234,  -234,  -234,
     326,   550,   432,  -234,   173,   200,   128,   -13,  -234,  -234,
     326,    91,  -234,  -234,  -234,  -234,  -234,   216,   267,   164,
     313,   177,   209,  -234,   337,  -234,  -234,  -234,   126,  -234,
      42,   316,  -234,  -234,  -234,    42,  -234,  -234,  -234,  -234,
      48,   230,   341,    68,  -234,  -234,  -234,  -234,  -234,  -234,
     360,   138,   394,  -234,   366,   326,   359,  -234,  -234,  -234,
      18,  -234,   484,   357,  -234,  -234,  -234,   319,  -234,  -234,
    -234,   367,  -234,   370,    23,  -234,   364,   372,  -234,  -234,
    -234,  -234,  -234,  -234,    46,   393,   364,   432,   364,  -234,
    -234,  -234,   377,   536,  -234,   380,   364,  -234
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    15,    16,    17,     0,     0,
       0,    18,     0,    14,     3,     5,     0,    13,     6,     7,
     115,     0,     0,   121,     8,     9,    10,   116,   117,     0,
     119,     2,   180,    16,    20,     0,     0,   101,    63,    95,
       0,     0,    83,   109,     0,   105,     0,    91,     0,    92,
       0,     0,     0,     0,     0,    19,     0,     0,    23,     0,
      26,     0,    67,   127,   126,    81,    23,   107,   106,   103,
       0,   125,   100,    20,     0,     0,   140,   140,   132,     0,
       0,   140,   140,    11,   182,     0,    24,     0,     0,     0,
       0,     0,     0,    23,    84,   140,    83,   104,    19,    99,
      23,   130,    97,   129,    93,     0,   124,     0,   139,     0,
       0,    51,     0,     0,   160,   140,     0,     0,     0,     0,
      61,    59,   140,   140,   140,   152,    58,   177,   140,   140,
      60,     0,    56,    39,     0,    53,    43,    46,     0,   140,
       0,   135,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   123,     0,     0,    23,   140,     0,    25,     0,
      89,     0,    88,   102,    66,    64,    73,    82,   140,   112,
     110,    39,   108,     0,   131,    98,    20,     0,   150,   151,
     140,   157,     0,   165,     0,   140,   140,   140,   140,    34,
      36,     0,     0,    57,     0,   140,    35,    37,   140,   140,
     140,   140,   140,   140,   140,    58,     0,   140,   140,    38,
     153,   140,   122,     0,   133,    50,     0,   141,   118,   120,
     181,     0,    27,    22,     0,     0,    80,    86,    87,     0,
       0,     0,    73,     0,   114,     0,    50,    99,    96,   128,
     156,   140,   140,   167,     0,     0,   172,     0,   171,   176,
     175,     0,   174,    45,    44,    62,   178,     0,    28,    29,
      32,    30,    31,    33,     0,    48,    55,    54,     0,    52,
       0,     0,    12,    21,    78,     0,    70,    71,    72,    65,
       0,     0,     0,     0,    69,    74,    76,    77,    75,    90,
       0,     0,   140,   111,     0,   158,     0,    41,    42,   168,
     140,   169,   140,     0,    49,    40,    47,     0,   138,    79,
      68,     0,    95,    83,     0,   113,   140,     0,   161,   170,
     173,   179,   137,    85,    20,   154,   140,   140,   140,   159,
     162,   155,     0,   140,   163,     0,   140,   164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,  -234,  -234,  -234,    -2,   302,   381,   -53,
    -234,  -234,   333,   -79,   -90,  -112,   223,   226,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,   205,   160,  -234,  -229,  -205,
     -15,  -234,  -234,  -234,   162,  -234,   280,  -234,   436,  -234,
     440,  -234,   272,   442,  -234,  -234,  -234,  -234,   376,  -234,
    -234,  -149,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
     433,   401,   281,  -234,   -56,  -234,   -59,   321,  -133,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -233,  -234,  -234,  -234,   168,  -234,   171,  -234,  -234,  -234,
    -234,  -234,  -234
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,    15,   155,   159,    17,   100,    85,
      18,    59,    60,   132,   133,   134,   135,   194,   136,   137,
      19,    62,    91,    92,   232,   233,   284,   285,   160,   225,
     226,    93,    66,   287,    89,   161,   162,   288,   289,    21,
     290,    74,   102,   291,    24,    61,    25,    44,    45,    68,
      95,   172,   235,    26,    27,    51,    53,    50,    28,    29,
      40,    75,   103,    30,   138,   139,   173,   141,   142,   143,
     144,   294,   145,   241,   317,   146,   182,   327,   332,   335,
     184,   147,   148,   247,   248,   251,   252,   149,   195,   303,
      31,    54,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    43,    34,   183,   286,   171,    36,   222,   217,   296,
       3,   271,   192,    94,   193,   223,   170,   140,   140,   234,
      35,   150,   140,   140,   299,   153,   154,     5,    33,     7,
     224,   108,   171,   171,    37,   300,   111,    11,   171,   197,
     167,    98,   104,   189,   190,   105,    73,   175,    41,   196,
      79,   286,     5,    33,     7,    43,   281,    41,   101,    72,
     -94,    55,    11,   282,   101,   307,   171,    69,   240,    70,
      99,   -14,    63,   244,   245,    41,   250,   170,   171,   131,
     213,   217,    13,    41,   205,    96,   257,   206,    38,   170,
     237,   208,    42,   193,   330,   106,   268,   246,   107,   269,
     334,    96,   221,   176,   151,   177,   209,    13,    47,   171,
     171,   171,   171,   171,   171,   -14,     5,    33,     7,    96,
     258,   259,   260,   261,   262,   263,    11,   313,   301,   295,
     183,     5,    33,     7,   152,   292,   140,   107,   216,   256,
     302,    11,   293,   315,     5,    33,     7,     5,    33,     7,
       5,    33,     7,    86,    11,    87,   108,    11,   227,   272,
      11,   111,   101,    78,   157,   211,   206,   116,   117,   306,
     208,    13,   120,   121,    39,    49,   122,   123,   124,    48,
     229,   230,   231,   325,   205,   126,    13,   206,    52,   207,
     250,   208,    57,   329,   254,   331,   128,   211,    55,    13,
     129,   130,   171,   337,   131,   215,   209,    58,    63,   297,
     246,   270,   211,   170,    64,   183,   279,   201,   202,   203,
     204,   183,    65,     4,     5,     6,     7,     8,     9,    10,
     201,   283,   203,   204,    11,    12,   298,   108,    67,   211,
     109,   110,   111,   112,    71,   113,   114,   115,   116,   117,
     118,   119,   304,   120,   121,   211,    76,   122,   123,   124,
     309,   125,   201,    77,    81,   204,   126,    82,    84,   127,
    -136,   229,   230,   231,   156,    88,   157,   128,   283,    13,
      83,   129,   130,    90,   108,   131,   163,   109,   110,   111,
     112,   165,   113,   114,   115,   116,   117,   118,   119,   200,
     120,   121,   164,   166,   122,   123,   124,   210,   125,   211,
     157,   174,   324,   126,   178,   179,   127,  -134,   180,   181,
     201,   202,   203,   204,   128,   274,   185,   275,   129,   130,
     108,   186,   131,   109,   110,   111,   112,   187,   113,   114,
     115,   116,   117,   118,   119,   198,   120,   121,   188,   212,
     122,   123,   124,   308,   125,   275,   322,   218,   275,   126,
     219,   220,   127,   236,   242,   211,   255,   243,   253,   204,
     128,   265,   276,   305,   129,   130,  -140,   108,   131,   273,
     109,   110,   111,   112,   277,   113,   114,   115,   116,   117,
     118,   119,   278,   120,   121,   314,   318,   122,   123,   124,
     312,   125,   316,   321,   323,   -94,   126,   108,   326,   127,
     199,   200,   111,   328,   333,    56,   336,   128,   116,   117,
     158,   129,   130,   120,   121,   131,   191,   122,   123,   124,
     267,   264,   201,   202,   203,   204,   126,   280,    20,   168,
     310,   228,    22,   311,    23,   108,    97,   128,   238,    46,
     111,   129,   130,    80,   169,   131,   116,   117,   239,   108,
     214,   120,   121,     0,   111,   122,   123,   124,   319,  -166,
     116,   117,     0,   320,   126,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   128,     0,     0,   126,   129,
     130,     0,     0,   131,     0,     0,     0,   108,     0,   128,
       0,     0,   111,   129,   130,  -140,     0,   131,   116,   117,
       0,   108,     0,   120,   121,     0,   111,   122,   123,   124,
       0,     0,   116,   117,     0,     0,   126,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   128,     0,     0,
     126,   129,   130,     0,   249,   131,     0,     0,     0,   108,
       0,   128,     0,     0,   111,   129,   130,     0,   266,   131,
     116,   117,     0,   108,     0,   120,   121,     0,   111,   122,
     123,   124,  -166,     0,   116,   117,     0,     0,   126,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   128,
       0,     0,   126,   129,   130,     0,     0,   131,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   129,   130,     0,
       0,   131
};

static const yytype_int16 yycheck[] =
{
       2,    16,     4,   115,   233,    95,     8,   156,   141,   242,
       0,   216,   124,    66,   126,    43,    95,    76,    77,   168,
      28,    77,    81,    82,    37,    81,    82,     4,     5,     6,
      58,    13,   122,   123,    59,    48,    18,    14,   128,   129,
      93,    15,    36,   122,   123,    39,    48,   100,    15,   128,
      52,   280,     4,     5,     6,    70,     8,    15,    73,    36,
      35,    15,    14,    15,    79,   270,   156,    37,   180,    39,
      44,    15,    47,   185,   186,    15,   188,   156,   168,    61,
     139,   214,    59,    15,    35,    59,   198,    38,    59,   168,
      44,    42,    59,   205,   327,    36,   208,   187,    39,   211,
     333,    59,   155,   105,    44,   107,    57,    59,    37,   199,
     200,   201,   202,   203,   204,    59,     4,     5,     6,    59,
     199,   200,   201,   202,   203,   204,    14,    59,    37,   241,
     242,     4,     5,     6,    36,    39,   195,    39,   140,   195,
      49,    14,    46,   292,     4,     5,     6,     4,     5,     6,
       4,     5,     6,    37,    14,    39,    13,    14,    46,    37,
      14,    18,   177,    36,    42,    39,    38,    24,    25,    43,
      42,    59,    29,    30,    59,    37,    33,    34,    35,    35,
      10,    11,    12,   316,    35,    42,    59,    38,    35,    40,
     302,    42,    35,   326,    36,   328,    53,    39,    15,    59,
      57,    58,   292,   336,    61,    59,    57,    59,    47,    36,
     300,   213,    39,   292,    59,   327,    46,    53,    54,    55,
      56,   333,    59,     3,     4,     5,     6,     7,     8,     9,
      53,   233,    55,    56,    14,    15,    36,    13,    40,    39,
      16,    17,    18,    19,    59,    21,    22,    23,    24,    25,
      26,    27,    36,    29,    30,    39,    45,    33,    34,    35,
     275,    37,    53,    45,    45,    56,    42,    45,    36,    45,
      46,    10,    11,    12,    40,    45,    42,    53,   280,    59,
      59,    57,    58,    41,    13,    61,    37,    16,    17,    18,
      19,    37,    21,    22,    23,    24,    25,    26,    27,    32,
      29,    30,    59,    45,    33,    34,    35,    37,    37,    39,
      42,    59,   314,    42,    37,    37,    45,    46,    35,    35,
      53,    54,    55,    56,    53,    37,    35,    39,    57,    58,
      13,    35,    61,    16,    17,    18,    19,    48,    21,    22,
      23,    24,    25,    26,    27,    35,    29,    30,    49,    46,
      33,    34,    35,    37,    37,    39,    37,    46,    39,    42,
      46,    46,    45,    59,    35,    39,    43,    37,    36,    56,
      53,    59,    41,    36,    57,    58,    59,    13,    61,    43,
      16,    17,    18,    19,    41,    21,    22,    23,    24,    25,
      26,    27,    41,    29,    30,    35,    37,    33,    34,    35,
      59,    37,    36,    46,    37,    35,    42,    13,    36,    45,
      31,    32,    18,    20,    37,    34,    36,    53,    24,    25,
      87,    57,    58,    29,    30,    61,   124,    33,    34,    35,
     207,   205,    53,    54,    55,    56,    42,   232,     2,    45,
     280,   161,     2,   281,     2,    13,    70,    53,   176,    16,
      18,    57,    58,    52,    60,    61,    24,    25,   177,    13,
     139,    29,    30,    -1,    18,    33,    34,    35,   300,    37,
      24,    25,    -1,   302,    42,    29,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    53,    -1,    -1,    42,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    13,    -1,    53,
      -1,    -1,    18,    57,    58,    59,    -1,    61,    24,    25,
      -1,    13,    -1,    29,    30,    -1,    18,    33,    34,    35,
      -1,    -1,    24,    25,    -1,    -1,    42,    29,    30,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    53,    -1,    -1,
      42,    57,    58,    -1,    60,    61,    -1,    -1,    -1,    13,
      -1,    53,    -1,    -1,    18,    57,    58,    -1,    60,    61,
      24,    25,    -1,    13,    -1,    29,    30,    -1,    18,    33,
      34,    35,    36,    -1,    24,    25,    -1,    -1,    42,    29,
      30,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    53,
      -1,    -1,    42,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,     3,     4,     5,     6,     7,     8,
       9,    14,    15,    59,    65,    66,    68,    69,    72,    82,
     100,   101,   102,   105,   106,   108,   115,   116,   120,   121,
     125,   152,   154,     5,    68,    28,    68,    59,    59,    59,
     122,    15,    59,    92,   109,   110,   122,    37,    35,    37,
     119,   117,    35,   118,   153,    15,    70,    35,    59,    73,
      74,   107,    83,    47,    59,    59,    94,    40,   111,    37,
      39,    59,    36,    68,   103,   123,    45,    45,    36,    68,
     123,    45,    45,    59,    36,    71,    37,    39,    45,    96,
      41,    84,    85,    93,    71,   112,    59,   110,    15,    44,
      70,    92,   104,   124,    36,    39,    36,    39,    13,    16,
      17,    18,    19,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    33,    34,    35,    37,    42,    45,    53,    57,
      58,    61,    75,    76,    77,    78,    80,    81,   126,   127,
     128,   129,   130,   131,   132,   134,   137,   143,   144,   149,
     126,    44,    36,   126,   126,    67,    40,    42,    74,    68,
      90,    97,    98,    37,    59,    37,    45,    71,    45,    60,
      75,    76,   113,   128,    59,    71,    68,    68,    37,    37,
      35,    35,   138,    77,   142,    35,    35,    48,    49,    75,
      75,    69,    77,    77,    79,   150,    75,    76,    35,    31,
      32,    53,    54,    55,    56,    35,    38,    40,    42,    57,
      37,    39,    46,   128,   129,    59,    68,   130,    46,    46,
      46,    71,   113,    43,    58,    91,    92,    46,    98,    10,
      11,    12,    86,    87,   113,   114,    59,    44,   104,   124,
      77,   135,    35,    37,    77,    77,    76,   145,   146,    60,
      77,   147,   148,    36,    36,    43,   126,    77,    75,    75,
      75,    75,    75,    75,    79,    59,    60,    78,    77,    77,
      68,    91,    37,    43,    37,    39,    41,    41,    41,    46,
      87,     8,    15,    68,    88,    89,    90,    95,    99,   100,
     102,   105,    39,    46,   133,    77,   142,    36,    36,    37,
      48,    37,    49,   151,    36,    36,    43,    91,    37,    92,
      88,    96,    59,    59,    35,   113,    36,   136,    37,   146,
     148,    46,    37,    37,    68,   130,    36,   139,    20,   130,
     142,   130,   140,    37,   142,   141,    36,   130
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    67,    66,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    72,    73,    73,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    80,    81,    83,    82,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    88,    89,    89,    90,    91,
      91,    93,    92,    94,    92,    95,    96,    97,    97,    98,
      99,   100,   100,   101,   102,   102,   103,   103,   104,   104,
     105,   107,   106,   108,   109,   109,   110,   112,   111,   111,
     113,   113,   113,   114,   114,   115,   115,   117,   116,   118,
     116,   119,   116,   120,   120,   121,   121,   122,   123,   123,
     124,   124,   125,   126,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   131,   132,   132,   133,   135,   136,   134,
     138,   139,   140,   141,   137,   142,   142,   143,   144,   144,
     145,   145,   146,   147,   147,   148,   148,   150,   151,   149,
     153,   152,   154
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     7,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     3,     0,     4,     3,     1,     4,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     1,
       4,     4,     4,     1,     3,     3,     1,     4,     3,     4,
       2,     1,     3,     1,     3,     3,     1,     1,     0,     1,
       1,     1,     3,     0,     5,     4,     2,     0,     3,     2,
       2,     2,     2,     0,     1,     1,     1,     1,     3,     3,
       1,     0,     4,     0,     3,     3,     3,     2,     1,     1,
       1,     2,     2,     4,     2,     2,     4,     2,     2,     1,
       3,     0,     5,     3,     3,     1,     2,     0,     3,     0,
       1,     3,     1,     3,     1,     1,     1,     0,     5,     0,
       5,     0,     5,     4,     4,     3,     3,     2,     4,     2,
       1,     2,     3,     2,     1,     1,     0,     5,     4,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     6,     8,     0,     0,     0,     7,
       0,     0,     0,     0,    13,     1,     0,     3,     4,     4,
       3,     1,     1,     3,     1,     1,     1,     0,     0,     5,
       0,     5,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_declarations main_function  */
#line 83 "dkk.y"
                                           {exit(0);}
#line 1558 "dkk.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 91 "dkk.y"
                                                   {dim_count = 0;}
#line 1564 "dkk.tab.c"
    break;

  case 12: /* typedef_declaration: TYPEDEF typename listspec ID $@1 dims SEMI  */
#line 91 "dkk.y"
                                                                              {hashtbl_insert(symtb, (yyvsp[-3].str), (yyvsp[-5].str) , scope, (yyvsp[-1].arr), 1, currvis);}
#line 1570 "dkk.tab.c"
    break;

  case 13: /* typename: standard_type  */
#line 92 "dkk.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1576 "dkk.tab.c"
    break;

  case 14: /* typename: ID  */
#line 93 "dkk.y"
                     {struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), currvis); if(p == NULL || p->istype == 0) yyerror("Type doesn't exist."); {(yyval.str) = p->key;}}
#line 1582 "dkk.tab.c"
    break;

  case 15: /* standard_type: CHAR  */
#line 94 "dkk.y"
                     {(yyval.str)="char";}
#line 1588 "dkk.tab.c"
    break;

  case 16: /* standard_type: INT  */
#line 95 "dkk.y"
                      {(yyval.str)="int";}
#line 1594 "dkk.tab.c"
    break;

  case 17: /* standard_type: FLOAT  */
#line 96 "dkk.y"
                        {(yyval.str)="float";}
#line 1600 "dkk.tab.c"
    break;

  case 18: /* standard_type: VOID  */
#line 97 "dkk.y"
                       {(yyval.str)="void";}
#line 1606 "dkk.tab.c"
    break;

  case 21: /* dims: dims LBRACK ICONST RBRACK  */
#line 99 "dkk.y"
                                 {
		if (dim_count == MAX_DIMENSIONS) {
			//ERROR
			yyerror("Exceeded maximum array dimensions.");
			if ((yyvsp[-3].arr)) free((yyvsp[-3].arr));
		}
		else if (dim_count == 0) {
			(yyval.arr) = malloc(sizeof(array_t));
			if (!(yyval.arr)) {
				printf("Memory allocation error\n");
				exit(1);
			}
			if ((yyvsp[-1].ival) <= 0) {
				yyerror("Array dimension must be positive integer.");
				free((yyval.arr));
				exit(1);
			}
			(yyval.arr)->dim_size[0] = (yyvsp[-1].ival);
			(yyval.arr)->dims = 1;
			dim_count++;
		}
		else {
			(yyvsp[-3].arr)->dim_size[dim_count] = (yyvsp[-1].ival);
			(yyvsp[-3].arr)->dims++;
			(yyval.arr) = (yyvsp[-3].arr);
			dim_count++;
		}
	}
#line 1639 "dkk.tab.c"
    break;

  case 22: /* dims: dims LBRACK RBRACK  */
#line 127 "dkk.y"
                             {
		if (dim_count == MAX_DIMENSIONS) {
			yyerror("Exceeded maximum array dimensions.");
			if ((yyvsp[-2].arr)) free((yyvsp[-2].arr));
		}
		else if (dim_count == 0) {
			(yyval.arr) = malloc(sizeof(array_t));
			(yyval.arr)->dim_size[0] = MAX_DIMENSIONS;
			(yyval.arr)->dims++;
			dim_count++;
		}
		else {
			(yyvsp[-2].arr)->dim_size[dim_count] = MAX_DIMENSIONS;
			(yyvsp[-2].arr)->dims++;
			(yyval.arr) = (yyvsp[-2].arr);
			dim_count++;
		}
	}
#line 1662 "dkk.tab.c"
    break;

  case 23: /* dims: %empty  */
#line 145 "dkk.y"
      {(yyval.arr) = NULL;}
#line 1668 "dkk.tab.c"
    break;

  case 28: /* expression: expression OROP expression  */
#line 151 "dkk.y"
                                        { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT))
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  else	yyerror("Wrong expression type.");
				      	(yyval.myexpr).node = create_node("||", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					}
#line 1678 "dkk.tab.c"
    break;

  case 29: /* expression: expression ANDOP expression  */
#line 156 "dkk.y"
                                      { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT))
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  else yyerror("Wrong expression type.");
				      	(yyval.myexpr).node = create_node("&&", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1688 "dkk.tab.c"
    break;

  case 30: /* expression: expression EQUOP expression  */
#line 161 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR))
						(yyval.myexpr).type = T_INT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node("==", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("!=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1699 "dkk.tab.c"
    break;

  case 31: /* expression: expression RELOP expression  */
#line 167 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR))
						(yyval.myexpr).type = T_INT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node(">", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 1)(yyval.myexpr).node = create_node(">=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 2)(yyval.myexpr).node = create_node("<", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("<=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1712 "dkk.tab.c"
    break;

  case 32: /* expression: expression ADDOP expression  */
#line 175 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if (((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT))
						(yyval.myexpr).type = T_FLOAT;
					else yyerror("Wrong expression type.");
					(yyval.myexpr).val.ival = (yyvsp[-2].myexpr).val.ival + (yyvsp[0].myexpr).val.ival;
					if((yyvsp[-1].oper) == 0) (yyval.myexpr).node = create_node("+", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					else (yyval.myexpr).node = create_node("-", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1726 "dkk.tab.c"
    break;

  case 33: /* expression: expression MULOP expression  */
#line 184 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if ((((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT)))
						(yyval.myexpr).type = T_FLOAT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node("*", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 1)(yyval.myexpr).node = create_node("/", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("%", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1740 "dkk.tab.c"
    break;

  case 34: /* expression: NOTOP expression  */
#line 193 "dkk.y"
                           { if ((yyvsp[0].myexpr).type != T_INT) yyerror("Wrong expression type.");
	                     else (yyval.myexpr).type = (yyvsp[0].myexpr).type;
			     (yyval.myexpr).node = create_node("!", (yyvsp[0].myexpr).node, NULL);
	                   }
#line 1749 "dkk.tab.c"
    break;

  case 35: /* expression: ADDOP expression  */
#line 197 "dkk.y"
                           { if (((yyvsp[0].myexpr).type != T_INT) || ((yyvsp[0].myexpr).type != T_FLOAT)) yyerror("Wrong expression type.");
			     	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
				(yyval.myexpr).val = (yyvsp[0].myexpr).val;
			     	if((yyvsp[-1].oper) == 1)
					if((yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).val.ival = ((yyvsp[0].myexpr).val.ival * (-1));	
					if((yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).val.fval = ((yyvsp[0].myexpr).val.fval * (-1));
				if((yyvsp[-1].oper) == 0) (yyval.myexpr).node = create_node("+", (yyvsp[0].myexpr).node, NULL);
				else (yyval.myexpr).node = create_node("-", (yyvsp[0].myexpr).node, NULL);
			   }
#line 1765 "dkk.tab.c"
    break;

  case 36: /* expression: SIZEOP expression  */
#line 208 "dkk.y"
                            {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = 0; (yyval.myexpr).node = create_node("sizeof", (yyvsp[0].myexpr).node, NULL);}
#line 1771 "dkk.tab.c"
    break;

  case 37: /* expression: INCDEC variable  */
#line 209 "dkk.y"
                          {(yyval.myexpr) = (yyvsp[0].myexpr); asd_t *node = malloc(sizeof(asd_t)); node->name = "1"; if((yyvsp[-1].oper) == 0) (yyval.myexpr).node = create_node("+", (yyvsp[0].myexpr).node, node);
				      	else (yyval.myexpr).node = create_node("-", (yyvsp[0].myexpr).node, node);}
#line 1778 "dkk.tab.c"
    break;

  case 38: /* expression: variable INCDEC  */
#line 211 "dkk.y"
                          {(yyval.myexpr) = (yyvsp[-1].myexpr); post_t *temp = malloc(sizeof(post_t)); temp->name = (yyvsp[-1].myexpr).node->name; temp->sign = (yyvsp[0].oper); temp->next = postlist; postlist = temp;}
#line 1784 "dkk.tab.c"
    break;

  case 39: /* expression: variable  */
#line 212 "dkk.y"
                   {(yyval.myexpr) = (yyvsp[0].myexpr);}
#line 1790 "dkk.tab.c"
    break;

  case 40: /* expression: variable LPAREN expression_list RPAREN  */
#line 213 "dkk.y"
                                                 {(yyval.myexpr) = (yyvsp[-3].myexpr);
							 if((yyvsp[-3].myexpr).n->func != NULL){
							struct hashnode_s *n = hashtbl_lookup(currtb, scope, (yyvsp[-3].myexpr).n->key, currvis);
							if(n == NULL)
								yyerror("Variable doesn't exist.");
							if(n->func != NULL){
							par_list_t *p1 = n->func->node;
							expr_list_t *p2 = (yyvsp[-1].myexprlist);
							while(p1!=NULL && p2!=NULL){
								if(strcmp(p1->type,p2->exp->n->data))
									yyerror("Parameter type mismatch.");
								p1=p1->next; p2=p2->next;
							}
							if(p1 != NULL || p2!=NULL)
								yyerror("Parameter cardinality mismatch.");
							}
							else if((yyvsp[-1].myexprlist) != NULL)
								printf("semantic error\n");
						}else if(strcmp((yyvsp[-3].myexpr).n->data, "func"))yyerror("Variable is not a function."); fprintf(fd, "=,\tcurrinst,\t,\tra\n"); fprintf(fd, "j,\t,\t,\tL-%s:\n", (yyvsp[-3].myexpr).n->key);}
#line 1814 "dkk.tab.c"
    break;

  case 43: /* expression: constant  */
#line 234 "dkk.y"
                   {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val; (yyval.myexpr).n = malloc(sizeof(expr_t)); (yyval.myexpr).n->arr = malloc(sizeof(array_t)); (yyval.myexpr).n->arr->dims = 0; (yyval.myexpr).rec_count = 0;if((yyvsp[0].myexpr).type == T_CHAR) (yyval.myexpr).n->data = strdup("char"); else if((yyvsp[0].myexpr).type == T_INT) (yyval.myexpr).n->data = strdup("int"); else if((yyvsp[0].myexpr).type == T_FLOAT) (yyval.myexpr).n->data = strdup("float"); char *buf = malloc(15); if((yyvsp[0].myexpr).type == T_INT) sprintf(buf, "%d", (yyval.myexpr).val.ival); else if ((yyvsp[0].myexpr).type == T_CHAR) sprintf(buf, "%c", (yyval.myexpr).val.cval); if((yyvsp[0].myexpr).type == T_FLOAT) sprintf(buf, "%f", (yyval.myexpr).val.fval); (yyval.myexpr).node = create_node(buf, NULL, NULL);}
#line 1820 "dkk.tab.c"
    break;

  case 46: /* expression: listexpression  */
#line 237 "dkk.y"
                         {(yyval.myexpr).type = (yyvsp[0].myexprlist)->exp->type; (yyval.myexpr).val.ival = (yyvsp[0].myexprlist)->listsize; (yyval.myexpr).rec_count = 0; (yyval.myexpr).n = NULL;}
#line 1826 "dkk.tab.c"
    break;

  case 47: /* variable: variable LBRACK general_expression RBRACK  */
#line 238 "dkk.y"
                                                     {
							if((yyvsp[-1].myexprlist)->exp->type != T_INT ||((yyvsp[-1].myexprlist)->exp->n->arr != NULL) && ((yyvsp[-1].myexprlist)->exp->rec_count != (yyvsp[-1].myexprlist)->exp->n->arr->dims))
								yyerror("Wrong array indexing.");
							else{
								if((yyvsp[-3].myexpr).rec_count > (yyvsp[-3].myexpr).n->arr->dims)
						 	    	 	yyerror("Dimensions exceed declared dimensions.");
								else if((yyvsp[-1].myexprlist)->exp->val.ival <0 || (yyvsp[-1].myexprlist)->exp->val.ival >= (yyvsp[-3].myexpr).n->arr->dim_size[(yyvsp[-3].myexpr).rec_count]){
									yyerror("Incorrect dimension indexing.");}
							     	else {
									if((yyvsp[-1].myexprlist)->exp->rec_count != (yyvsp[-1].myexprlist)->exp->n->arr->dims)
										yyerror("Wrong array indexing.");
									if(stride == 1){
										for(int i = 1; i < (yyvsp[-3].myexpr).n->arr->dims; i++){
											stride = stride * (yyvsp[-3].myexpr).n->arr->dim_size[i];
										}
										(yyval.myexpr).val.ival = (yyvsp[-1].myexprlist)->exp->val.ival * stride;
										(yyval.myexpr).rec_count = (yyvsp[-3].myexpr).rec_count+1;
										(yyval.myexpr).n = (yyvsp[-3].myexpr).n;}
									else{
									stride = stride / (yyvsp[-3].myexpr).n->arr->dim_size[(yyvsp[-3].myexpr).rec_count];
									(yyval.myexpr).val.ival = (yyvsp[-3].myexpr).val.ival + (yyvsp[-1].myexprlist)->exp->val.ival * stride;
									(yyval.myexpr).rec_count = (yyvsp[-3].myexpr).rec_count+1;
									(yyval.myexpr).type = (yyvsp[-3].myexpr).type;
									(yyval.myexpr).n = (yyvsp[-3].myexpr).n;}
								}
							}
							if((yyvsp[-3].myexpr).rec_count == 0) fprintf(fd, "=,\t1,\t,\tstride\n");
							fprintf(fd, "*,\tstride,\t%s,\tt%d\n", lastname, ++reg);
							fprintf(fd, "+,\tindex,\tt%d,\tindex\n", reg);
							fprintf(fd, "*,\tstride,\t%d,\tstride\n", (yyvsp[-3].myexpr).n->arr->dim_size[(yyvsp[-3].myexpr).rec_count]);
							if((yyvsp[-3].myexpr).rec_count == (yyvsp[-3].myexpr).n->arr->dims-1){
								fprintf(fd, "*,\tindex,\t%d,\tindex\n\n", findsize((yyvsp[-3].myexpr).n));
								fprintf(fd, "o,\t%s,\tindex,\tt%d\n\n", (yyvsp[-3].myexpr).n->key, ++reg);
								char *buf = malloc(10);
								sprintf(buf, "t%d", reg);
								(yyval.myexpr).node->name = buf;
							}
					}
#line 1869 "dkk.tab.c"
    break;

  case 48: /* variable: variable DOT ID  */
#line 276 "dkk.y"
                          {if((yyvsp[-2].myexpr).n == NULL) yyerror("Variable doesn't exist.");
			    struct hashnode_s *p=(yyvsp[-2].myexpr).n;
                            if ((yyvsp[-2].myexpr).n->un != NULL) {	
				if (hashtbl_lookup(p->un->untb, scope, (yyvsp[0].str), currvis) == NULL) 
					yyerror("Union field doesn't exist");
			    }
			    else if ((yyvsp[-2].myexpr).n->cla != NULL) {
				int currvis = 2; // INITIALLY, PERMISSION = 2
				while(p!=NULL && p->cla!=NULL && hashtbl_lookup(p->cla->classtb, scope, (yyvsp[0].str), currvis) == NULL){
					if(p!=NULL && p->cla!=NULL && p->cla->superclass == NULL)
						yyerror("Class member doesn't exist.");
					currvis = 1;
					p = hashtbl_lookup(currtb, scope, p->cla->superclass, 0);
				}
				p = hashtbl_lookup((yyvsp[-2].myexpr).n->cla->classtb, scope, (yyvsp[0].str), currvis);
			   	currtb = (yyvsp[-2].myexpr).n->cla->classtb;
				(yyval.myexpr).n = p;
			    }
			    else 
				yyerror("Variable is not class or union.");
			(yyval.myexpr).rec_count = 0;
			(yyval.myexpr).val.ival =0;
			if(p == NULL)
				p = malloc(sizeof(struct hashnode_s));
			if(p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
				(yyval.myexpr).n = p;
			}
			}
#line 1904 "dkk.tab.c"
    break;

  case 49: /* variable: LISTFUNC LPAREN general_expression RPAREN  */
#line 306 "dkk.y"
                                                    {char *ptr = (yyvsp[-3].str); int count = 0;
							if((yyvsp[-1].myexprlist)->exp->n == NULL || (yyvsp[-1].myexprlist)->exp->n->arr == NULL ||(yyvsp[-1].myexprlist)->exp->n->arr->islist == 0)
								yyerror("Parameter is not list.");
							if((yyvsp[-1].myexprlist)->exp->rec_count != (yyvsp[-1].myexprlist)->exp->n->arr->dims)
								yyerror("Incorrect dimension indexing.");
							else{
							while ((ptr = strchr(ptr, 'd')) != NULL) {
								count++;
								ptr++;
    						    	}
								if((yyvsp[-1].myexprlist)->exp->n->arr->listsize[(yyvsp[-1].myexprlist)->exp->val.ival] < count+1)
									yyerror("List indexing exceeds limits");
							}
							(yyval.myexpr).n = (yyvsp[-1].myexprlist)->exp->n;
							(yyval.myexpr).val.ival = 1;
							(yyval.myexpr).type = (yyvsp[-1].myexprlist)->exp->type;
						}
#line 1926 "dkk.tab.c"
    break;

  case 50: /* variable: decltype ID  */
#line 323 "dkk.y"
                      {struct hashnode_s *p= hashtbl_lookup(currtb, scope, (yyvsp[0].str), currvis);
			if(p== NULL && deflist == NULL)
				yyerror("Variable doesn't exist.");
			else if(p == NULL && deflist != NULL){
				id_list_t *curr = deflist;
				(yyval.myexpr).n = NULL;
				while (curr) {
					if(strcmp(curr->id->id, yylval.str))
						curr=curr->next;
					else{
						(yyval.myexpr).rec_count = 0;
						(yyval.myexpr).n = malloc(sizeof(struct hashnode_s));
						(yyval.myexpr).n->data = curr->id->data;
						if(curr->id->arr == NULL){
							(yyval.myexpr).n->arr = malloc(sizeof(array_t));
							(yyval.myexpr).n->arr->dims = 0;
						}
						(yyval.myexpr).n->arr = curr->id->arr;
						(yyval.myexpr).n->key = curr->id->id;
						curr = NULL;
					}
				}
				if((yyval.myexpr).n == NULL)
					yyerror("Variable doesn't exist.");
			}
			else{
				(yyval.myexpr).rec_count = 0;
			 	(yyval.myexpr).n = p;
				if(!strcmp(p->data, "char"))
					(yyval.myexpr).type = T_CHAR;
				else if(!strcmp(p->data, "int"))
					(yyval.myexpr).type = T_INT;
				else if(!strcmp(p->data, "float"))
					(yyval.myexpr).type = T_FLOAT;
				else if(!strcmp(p->data, "void"))
					(yyval.myexpr).type = T_VOID;
				else (yyval.myexpr).type = T_ID;
			}
			if(p!=NULL && p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
			}
		(yyval.myexpr).node = create_node((yyvsp[0].str), NULL, NULL);
		}
#line 1975 "dkk.tab.c"
    break;

  case 51: /* variable: THIS  */
#line 367 "dkk.y"
               {(yyval.myexpr).rec_count = 0; (yyval.myexpr).val.ival = 0; (yyval.myexpr).n = currclass; (yyval.myexpr).type = T_ID;}
#line 1981 "dkk.tab.c"
    break;

  case 52: /* general_expression: general_expression COMMA general_expression  */
#line 368 "dkk.y"
                                                                 {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = (yyvsp[0].myexprlist)->exp; k->next =(yyvsp[-2].myexprlist); k->listsize = (yyvsp[-2].myexprlist)->listsize+(yyvsp[0].myexprlist)->listsize; (yyval.myexprlist) = k;}
#line 1987 "dkk.tab.c"
    break;

  case 53: /* general_expression: assignment  */
#line 369 "dkk.y"
                    {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = malloc(sizeof(expr_t));k->exp->type = (yyvsp[0].myexpr).type; k->exp->val = (yyvsp[0].myexpr).val; k->exp->rec_count = (yyvsp[0].myexpr).rec_count; k->exp->n = (yyvsp[0].myexpr).n; k->next =  NULL;  k->listsize = 1;(yyval.myexprlist) = k; (yyval.myexprlist)->exp->node = (yyvsp[0].myexpr).node; print_tree((yyvsp[0].myexpr).node); if(!noprint){ print_ir((yyvsp[0].myexpr).node); patchinc();}}
#line 1993 "dkk.tab.c"
    break;

  case 54: /* assignment: variable ASSIGN assignment  */
#line 370 "dkk.y"
                                        {if((yyvsp[-2].myexpr).rec_count != (yyvsp[-2].myexpr).n->arr->dims) yyerror("Incorrect dimension indexing.");if(findsize((yyvsp[-2].myexpr).n) != findsize((yyvsp[0].myexpr).n)) yyerror("Type mismatch.");
					if((yyvsp[-2].myexpr).n->arr->islist)
						(yyvsp[-2].myexpr).n->arr->listsize[(yyvsp[-2].myexpr).val.ival] = (yyvsp[0].myexpr).val.ival; 
					(yyval.myexpr).node = create_node("=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					}
#line 2003 "dkk.tab.c"
    break;

  case 56: /* assignment: expression  */
#line 376 "dkk.y"
                     {(yyval.myexpr) = (yyvsp[0].myexpr);}
#line 2009 "dkk.tab.c"
    break;

  case 57: /* expression_list: general_expression  */
#line 377 "dkk.y"
                                     {(yyval.myexprlist) = (yyvsp[0].myexprlist);}
#line 2015 "dkk.tab.c"
    break;

  case 58: /* expression_list: %empty  */
#line 377 "dkk.y"
                                                  {(yyval.myexprlist) = NULL;}
#line 2021 "dkk.tab.c"
    break;

  case 59: /* constant: CCONST  */
#line 378 "dkk.y"
                  {(yyval.myexpr).type = T_CHAR; (yyval.myexpr).val.cval = yylval.cval;}
#line 2027 "dkk.tab.c"
    break;

  case 60: /* constant: ICONST  */
#line 379 "dkk.y"
                 {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = yylval.ival;}
#line 2033 "dkk.tab.c"
    break;

  case 61: /* constant: FCONST  */
#line 380 "dkk.y"
                 {(yyval.myexpr).type = T_FLOAT; (yyval.myexpr).val.fval = yylval.fval;}
#line 2039 "dkk.tab.c"
    break;

  case 62: /* listexpression: LBRACK expression_list RBRACK  */
#line 381 "dkk.y"
                                               {(yyval.myexprlist) = (yyvsp[-1].myexprlist);}
#line 2045 "dkk.tab.c"
    break;

  case 63: /* $@2: %empty  */
#line 382 "dkk.y"
                             {hashtbl_insert(symtb, (yyvsp[0].str), "class", scope, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), currvis); currtb = p->cla->classtb; scope++;}
#line 2051 "dkk.tab.c"
    break;

  case 64: /* class_declaration: CLASS ID $@2 class_body SEMI  */
#line 382 "dkk.y"
                                                                                                                                                                                                          {scope--;struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[-3].str), currvis); p->cla->superclass = (yyvsp[-1].str);currtb = symtb; currvis = 0;}
#line 2057 "dkk.tab.c"
    break;

  case 65: /* class_body: parent LBRACE members_methods RBRACE  */
#line 383 "dkk.y"
                                                  {(yyval.str) = (yyvsp[-3].str);}
#line 2063 "dkk.tab.c"
    break;

  case 66: /* parent: COLON ID  */
#line 384 "dkk.y"
                  {(yyval.str) = (yyvsp[0].str);}
#line 2069 "dkk.tab.c"
    break;

  case 67: /* parent: %empty  */
#line 384 "dkk.y"
                               {(yyval.str) = NULL;}
#line 2075 "dkk.tab.c"
    break;

  case 70: /* access: PRIVATE COLON  */
#line 386 "dkk.y"
                       {currvis = 2;}
#line 2081 "dkk.tab.c"
    break;

  case 71: /* access: PROTECTED COLON  */
#line 386 "dkk.y"
                                                       {currvis = 1;}
#line 2087 "dkk.tab.c"
    break;

  case 72: /* access: PUBLIC COLON  */
#line 386 "dkk.y"
                                                                                     {currvis = 0;}
#line 2093 "dkk.tab.c"
    break;

  case 78: /* var_declaration: typename variabledefs SEMI  */
#line 391 "dkk.y"
                                             {var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2099 "dkk.tab.c"
    break;

  case 79: /* variabledefs: variabledefs COMMA variabledef  */
#line 392 "dkk.y"
                                              {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = (yyvsp[-2].idlist);
          (yyval.idlist) = n;
      }
#line 2110 "dkk.tab.c"
    break;

  case 80: /* variabledefs: variabledef  */
#line 398 "dkk.y"
                      {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = NULL;
          (yyval.idlist) = n;
      }
#line 2121 "dkk.tab.c"
    break;

  case 81: /* $@3: %empty  */
#line 404 "dkk.y"
                      {dim_count = 0;}
#line 2127 "dkk.tab.c"
    break;

  case 82: /* variabledef: LIST ID $@3 dims  */
#line 404 "dkk.y"
                                            {	(yyval.id) = malloc(sizeof(id_t)); (yyval.id)->id = (yyvsp[-2].str);
						if((yyvsp[0].arr) == NULL){
							(yyval.id)->arr = malloc(sizeof(array_t));
							(yyval.id)->arr->dims = 0;
						}
						else (yyval.id)->arr = (yyvsp[0].arr);
						(yyval.id)->arr->islist = 1; int totalsize=1;
						for(int i = 0; i < (yyval.id)->arr->dims; i++)
							totalsize = totalsize * (yyval.id)->arr->dim_size[i];
						(yyval.id)->arr->listsize = calloc(totalsize, sizeof(int));}
#line 2142 "dkk.tab.c"
    break;

  case 83: /* $@4: %empty  */
#line 414 "dkk.y"
             {dim_count = 0;}
#line 2148 "dkk.tab.c"
    break;

  case 84: /* variabledef: ID $@4 dims  */
#line 414 "dkk.y"
                                   {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[-2].str);
		(yyval.id)->arr = (yyvsp[0].arr);
	}
#line 2158 "dkk.tab.c"
    break;

  case 92: /* short_func_declaration: nopar_func_header SEMI  */
#line 424 "dkk.y"
                                                                            { struct hashnode_s *p = hashtbl_lookup(currtb, scope, (yyvsp[-1].myhdr).name, currvis);
									  if (p != NULL) yyerror("Double header declaration");
									  else {
									  	hashtbl_insert(currtb, (yyvsp[-1].myhdr).name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, (yyvsp[-1].myhdr).name, currvis);
										p->func->ret_type = (yyvsp[-1].myhdr).type;			
										p->func->header_declared = 0;
										p->func->node = NULL;
									  }
									}
#line 2173 "dkk.tab.c"
    break;

  case 93: /* short_par_func_header: func_header_start LPAREN parameter_types RPAREN  */
#line 434 "dkk.y"
                                                                        {struct hashnode_s *p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, currvis);
									  if (p != NULL) yyerror("Double header declaration");
									  else { 
										hashtbl_insert(currtb, (yyvsp[-3].myhdr).name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, currvis);
										p->func->ret_type = (yyvsp[-3].myhdr).type;			
										p->func->header_declared = 0;
										p->func->node = (yyvsp[-1].par_list);
									  }}
#line 2187 "dkk.tab.c"
    break;

  case 94: /* func_header_start: typename ID  */
#line 443 "dkk.y"
                                {if(!strcmp((yyvsp[-1].str), "float") ||!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "void")|| !strcmp((yyvsp[-1].str), "char")){(yyval.myhdr).type = (yyvsp[-1].str); (yyval.myhdr).name = (yyvsp[0].str);} else yyerror("Function type incorrect");}
#line 2193 "dkk.tab.c"
    break;

  case 95: /* func_header_start: LIST ID  */
#line 443 "dkk.y"
                                                                                                                                                                                                             {(yyval.myhdr).type = strdup("list"); (yyval.myhdr).name = (yyvsp[0].str);}
#line 2199 "dkk.tab.c"
    break;

  case 96: /* parameter_types: parameter_types COMMA typename pass_list_dims  */
#line 444 "dkk.y"
                                                               {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = (yyvsp[-1].str);
		n->next = (yyvsp[-3].par_list);
		n->arr = (yyvsp[0].arr);
		(yyval.par_list) = n; }
#line 2210 "dkk.tab.c"
    break;

  case 97: /* parameter_types: typename pass_list_dims  */
#line 450 "dkk.y"
                                          {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = (yyvsp[-1].str);
		n->next = NULL;
		n->arr = (yyvsp[0].arr);
		(yyval.par_list)= n;
		}
#line 2222 "dkk.tab.c"
    break;

  case 98: /* pass_list_dims: listspec dims  */
#line 457 "dkk.y"
                               {(yyval.arr) = (yyvsp[0].arr);}
#line 2228 "dkk.tab.c"
    break;

  case 99: /* pass_list_dims: REFER  */
#line 457 "dkk.y"
                                                  {array_t *n = malloc(sizeof(array_t)); n->dims = -1; (yyval.arr) = n;}
#line 2234 "dkk.tab.c"
    break;

  case 100: /* nopar_func_header: func_header_start LPAREN RPAREN  */
#line 458 "dkk.y"
                                                    {(yyval.myhdr)=(yyvsp[-2].myhdr);}
#line 2240 "dkk.tab.c"
    break;

  case 101: /* $@5: %empty  */
#line 459 "dkk.y"
                             {hashtbl_insert(symtb, (yyvsp[0].str), "union", 0, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), 0); currtb = p->un->untb;}
#line 2246 "dkk.tab.c"
    break;

  case 102: /* union_declaration: UNION ID $@5 union_body SEMI  */
#line 459 "dkk.y"
                                                                                                                                                                                    {currtb = symtb;}
#line 2252 "dkk.tab.c"
    break;

  case 103: /* global_var_declaration: typename init_variabledefs SEMI  */
#line 460 "dkk.y"
                                                         {var_decl((yyvsp[-1].idlist), (yyvsp[-2].str)); deflist = NULL;}
#line 2258 "dkk.tab.c"
    break;

  case 104: /* init_variabledefs: init_variabledefs COMMA init_variabledef  */
#line 461 "dkk.y"
                                                              {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = (yyvsp[0].id);
         		 n->next = (yyvsp[-2].idlist);
         		 (yyval.idlist) = n;
			deflist = n;
      			}
#line 2270 "dkk.tab.c"
    break;

  case 105: /* init_variabledefs: init_variabledef  */
#line 468 "dkk.y"
                                                  {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = (yyvsp[0].id);
					n->next = NULL;
					(yyval.idlist) = n;
					deflist = n;
				}
#line 2282 "dkk.tab.c"
    break;

  case 106: /* init_variabledef: variabledef initializer  */
#line 476 "dkk.y"
                                           {int p=1; for(int i=0;((yyvsp[-1].id)!=NULL && (yyvsp[-1].id)->arr!=NULL && i<(yyvsp[-1].id)->arr->dims); i++) p = p * (yyvsp[-1].id)->arr->dim_size[i]; if((((yyvsp[-1].id)!=NULL)&&((yyvsp[-1].id)->data!=NULL)&&(!strcmp((yyvsp[-1].id)->data,"char"))&&((yyvsp[-1].id)->arr!=NULL)&& p==(yyvsp[0].ival))||p<(yyvsp[0].ival)) yyerror("Wrong Initialization.");}
#line 2288 "dkk.tab.c"
    break;

  case 107: /* $@6: %empty  */
#line 477 "dkk.y"
                     {dim_count=0;}
#line 2294 "dkk.tab.c"
    break;

  case 108: /* initializer: ASSIGN $@6 init_value  */
#line 477 "dkk.y"
                                               {(yyval.ival) = (yyvsp[0].ival);}
#line 2300 "dkk.tab.c"
    break;

  case 109: /* initializer: %empty  */
#line 477 "dkk.y"
                                                            {(yyval.ival)=0;}
#line 2306 "dkk.tab.c"
    break;

  case 110: /* init_value: expression  */
#line 478 "dkk.y"
                        {(yyval.ival) = 1;}
#line 2312 "dkk.tab.c"
    break;

  case 111: /* init_value: LBRACE init_values RBRACE  */
#line 479 "dkk.y"
                                    {(yyval.ival) = (yyvsp[-1].ival);}
#line 2318 "dkk.tab.c"
    break;

  case 112: /* init_value: STRING  */
#line 480 "dkk.y"
                 {(yyval.ival)=strlen((yyvsp[0].str));}
#line 2324 "dkk.tab.c"
    break;

  case 113: /* init_values: init_values COMMA init_value  */
#line 481 "dkk.y"
                                           {(yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); /*fprintf(fd, "o,\tt,\t%d,\tt%d\n",$$,++reg); fprintf(fd, "=,\tconst,\t,\tt%d\n", reg);*/}
#line 2330 "dkk.tab.c"
    break;

  case 114: /* init_values: init_value  */
#line 482 "dkk.y"
                             {(yyval.ival)= (yyvsp[0].ival);}
#line 2336 "dkk.tab.c"
    break;

  case 116: /* func_declaration: full_func_declaration  */
#line 483 "dkk.y"
                                                                  {fprintf(fd,"j,\t,\t,\tra\n");}
#line 2342 "dkk.tab.c"
    break;

  case 117: /* $@7: %empty  */
#line 484 "dkk.y"
                                             {scope++;}
#line 2348 "dkk.tab.c"
    break;

  case 118: /* full_func_declaration: full_par_func_header $@7 LBRACE decl_statements RBRACE  */
#line 484 "dkk.y"
                                                                                      {currclass = NULL;hashtbl_get(currtb, scope); scope--;}
#line 2354 "dkk.tab.c"
    break;

  case 119: /* $@8: %empty  */
#line 485 "dkk.y"
                                          {scope++;}
#line 2360 "dkk.tab.c"
    break;

  case 120: /* full_func_declaration: nopar_class_func_header $@8 LBRACE decl_statements RBRACE  */
#line 485 "dkk.y"
                                                                                  {hashtbl_get(currtb, scope);scope--;}
#line 2366 "dkk.tab.c"
    break;

  case 121: /* $@9: %empty  */
#line 486 "dkk.y"
                                    {scope++;}
#line 2372 "dkk.tab.c"
    break;

  case 122: /* full_func_declaration: nopar_func_header $@9 LBRACE decl_statements RBRACE  */
#line 486 "dkk.y"
                                                                            {hashtbl_get(currtb, scope);scope--;}
#line 2378 "dkk.tab.c"
    break;

  case 123: /* full_par_func_header: class_func_header_start LPAREN parameter_list RPAREN  */
#line 487 "dkk.y"
                                                                            { struct hashnode_s *p = (yyvsp[-3].node);
								   if(strcmp(p->data, "func")) yyerror("Class member not a method.");
								   if (p != NULL && p->istype == 0) yyerror("Class method already declared.");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									id_list_t *n = (yyvsp[-1].idlist);
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
									else p->func->header_declared = 1;
									scope++;
									var_decl((yyvsp[-1].idlist), (yyvsp[-1].idlist)->id->data);
									scope--;
									currtb = symtb;
									fprintf(fd, "L-%s:\n", (yyvsp[-3].node)->key);	
								   }
								   else yyerror("Class method incorrectly declared.");}
#line 2410 "dkk.tab.c"
    break;

  case 124: /* full_par_func_header: func_header_start LPAREN parameter_list RPAREN  */
#line 514 "dkk.y"
                                                                 { struct hashnode_s *p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, 0);
								   if((p!=NULL) && strcmp(p->data, "func")) yyerror("Variable is not a function.");
								   if (p != NULL && p->istype == 0) yyerror("Function already declared.");
							           else if (p != NULL && p->istype == 1){ //we have header b4 body
									//check if params are correct 
									id_list_t *n = (yyvsp[-1].idlist);
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
									else p->func->header_declared = 1;
									scope++;
									var_decl((yyvsp[-1].idlist), (yyvsp[-1].idlist)->id->data);
									scope--;
									fprintf(fd, "L-%s:\n", (yyvsp[-3].myhdr).name);	
								   }
								   else if (p == NULL) {
									fprintf(fd, "L-%s:\n", (yyvsp[-3].myhdr).name);	
									hashtbl_insert(currtb, (yyvsp[-3].myhdr).name, "func", scope, NULL, 0, currvis);
									p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, 0);
									p->func->ret_type = (yyvsp[-3].myhdr).type;
									p->func->header_declared = 1;
									id_list_t *n = (yyvsp[-1].idlist);
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
									var_decl((yyvsp[-1].idlist), (yyvsp[-1].idlist)->id->data);
									scope--;
								  }
								 }
#line 2470 "dkk.tab.c"
    break;

  case 125: /* class_func_header_start: typename func_class ID  */
#line 569 "dkk.y"
                                                 {struct hashnode_s *p =hashtbl_lookup(currtb, scope, (yyvsp[-1].str), currvis); currclass = p; if(p==NULL) yyerror("Class doesn't exist."); if((p = hashtbl_lookup(p->cla->classtb, 55555, (yyvsp[0].str), currvis)) == NULL) yyerror("Method doesn't exist."); if(strcmp(p->func->ret_type, (yyvsp[-2].str))) yyerror("Method type mismatch."); if(strcmp(p->data, "func")) yyerror("Member is not a method."); (yyval.node) = p;}
#line 2476 "dkk.tab.c"
    break;

  case 127: /* func_class: ID METH  */
#line 571 "dkk.y"
                     {(yyval.str) = (yyvsp[-1].str);}
#line 2482 "dkk.tab.c"
    break;

  case 128: /* parameter_list: parameter_list COMMA typename pass_variabledef  */
#line 572 "dkk.y"
                                                                {
		id_list_t* n = malloc(sizeof(id_list_t));
                n->id = (yyvsp[0].id);
		n->id->data = (yyvsp[-1].str);
                n->next = (yyvsp[-3].idlist);
                (yyval.idlist) = n;
                }
#line 2494 "dkk.tab.c"
    break;

  case 129: /* parameter_list: typename pass_variabledef  */
#line 580 "dkk.y"
                                            {
		id_list_t* n = malloc(sizeof(id_list_t));
		n->id = (yyvsp[0].id);
		n->id->data = (yyvsp[-1].str);
		n->next = NULL;
		(yyval.idlist) = n;
		}
#line 2506 "dkk.tab.c"
    break;

  case 130: /* pass_variabledef: variabledef  */
#line 587 "dkk.y"
                               {(yyval.id) = (yyvsp[0].id);}
#line 2512 "dkk.tab.c"
    break;

  case 131: /* pass_variabledef: REFER ID  */
#line 587 "dkk.y"
                                                     {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[0].str);
		(yyval.id)->arr = malloc(sizeof(array_t));	
		(yyval.id)->arr->dims = -1;	/* this is how you tell it that it's a reference*/}
#line 2522 "dkk.tab.c"
    break;

  case 132: /* nopar_class_func_header: class_func_header_start LPAREN RPAREN  */
#line 592 "dkk.y"
                                                                {if((yyvsp[-2].node)->func != NULL) yyerror("Function header mismatch");}
#line 2528 "dkk.tab.c"
    break;

  case 137: /* declarations: declarations decltype typename variabledefs SEMI  */
#line 596 "dkk.y"
                                                                { var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2534 "dkk.tab.c"
    break;

  case 138: /* declarations: decltype typename variabledefs SEMI  */
#line 597 "dkk.y"
                                                     { var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2540 "dkk.tab.c"
    break;

  case 141: /* statements: statements statement  */
#line 599 "dkk.y"
                                  {reg = 0;}
#line 2546 "dkk.tab.c"
    break;

  case 142: /* statements: statement  */
#line 599 "dkk.y"
                                                         {reg = 0;}
#line 2552 "dkk.tab.c"
    break;

  case 152: /* statement: SEMI  */
#line 609 "dkk.y"
               {currtb = symtb;}
#line 2558 "dkk.tab.c"
    break;

  case 153: /* expression_statement: general_expression SEMI  */
#line 610 "dkk.y"
                                               {currtb = symtb;}
#line 2564 "dkk.tab.c"
    break;

  case 154: /* if_statement: IF LPAREN general_expression if_mid RPAREN statement  */
#line 611 "dkk.y"
                                                                                         {fprintf(fd, "L%d:\n", label_count);}
#line 2570 "dkk.tab.c"
    break;

  case 156: /* if_mid: %empty  */
#line 613 "dkk.y"
        {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);}
#line 2576 "dkk.tab.c"
    break;

  case 157: /* $@10: %empty  */
#line 614 "dkk.y"
                               {fprintf(fd, "L%d:\n", ++label_count); scope++;}
#line 2582 "dkk.tab.c"
    break;

  case 158: /* $@11: %empty  */
#line 614 "dkk.y"
                                                                                                   {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);}
#line 2588 "dkk.tab.c"
    break;

  case 159: /* while_statement: WHILE LPAREN $@10 general_expression $@11 RPAREN statement  */
#line 614 "dkk.y"
                                                                                                                                                                                    {scope--; fprintf(fd, "j,\t,\t,\tL%d\n", label_count-1); fprintf(fd, "L%d:\n", label_count);}
#line 2594 "dkk.tab.c"
    break;

  case 160: /* $@12: %empty  */
#line 615 "dkk.y"
                    {scope++;}
#line 2600 "dkk.tab.c"
    break;

  case 161: /* $@13: %empty  */
#line 615 "dkk.y"
                                                  {fprintf(fd, "L%d:\n", ++label_count);}
#line 2606 "dkk.tab.c"
    break;

  case 162: /* $@14: %empty  */
#line 615 "dkk.y"
                                                                                                  {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count); noprint=1;}
#line 2612 "dkk.tab.c"
    break;

  case 163: /* $@15: %empty  */
#line 615 "dkk.y"
                                                                                                                                                                                          {noprint=0;}
#line 2618 "dkk.tab.c"
    break;

  case 164: /* for_statement: FOR $@12 LPAREN optexpr SEMI $@13 optexpr $@14 SEMI optexpr $@15 RPAREN statement  */
#line 615 "dkk.y"
                                                                                                                                                                                                                       {print_ir((yyvsp[-3].myexprlist)->exp->node); fprintf(fd, "j,\t,\t,\tL%d\n", label_count-1); fprintf(fd, "L%d:\n", label_count); scope--;}
#line 2624 "dkk.tab.c"
    break;

  case 165: /* optexpr: general_expression  */
#line 616 "dkk.y"
                             {(yyval.myexprlist) = (yyvsp[0].myexprlist);}
#line 2630 "dkk.tab.c"
    break;

  case 166: /* optexpr: %empty  */
#line 616 "dkk.y"
                                          {(yyval.myexprlist) = NULL;}
#line 2636 "dkk.tab.c"
    break;

  case 177: /* $@16: %empty  */
#line 623 "dkk.y"
                      {scope++;}
#line 2642 "dkk.tab.c"
    break;

  case 178: /* $@17: %empty  */
#line 623 "dkk.y"
                                                 {hashtbl_get(currtb, scope);scope--;}
#line 2648 "dkk.tab.c"
    break;

  case 180: /* $@18: %empty  */
#line 624 "dkk.y"
                           {header_decl_check(currtb); scope++;}
#line 2654 "dkk.tab.c"
    break;

  case 181: /* main_function: main_header $@18 LBRACE decl_statements RBRACE  */
#line 624 "dkk.y"
                                                                                               {scope--; hashtbl_get(currtb, scope);}
#line 2660 "dkk.tab.c"
    break;

  case 182: /* main_header: INT MAIN LPAREN RPAREN  */
#line 625 "dkk.y"
                                    {fprintf(fd, "\nL-main:\n");}
#line 2666 "dkk.tab.c"
    break;


#line 2670 "dkk.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 626 "dkk.y"


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
        fprintf(fd, "%s,\t,\t%s,\t%s\n", root->name, rname, rname);
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
    sprintf(name, "t%d", reg);
    fprintf(fd, "%s,\t%s,\t%s,\t%s\n", root->name, lname, rname, name);
    lastname = name;
    return name;
}
void patchinc(){
	post_t *temp = postlist;
	while(temp != NULL){
		if(!temp->sign)	fprintf(fd, "+,\t%s,\t1,\t%s\n", temp->name, temp->name);
		else fprintf(fd, "-,\t%s,\t1,\t%s\n", temp->name, temp->name);
		temp = temp->next;
	}
	postlist = NULL;
}
int findsize(struct hashnode_s *n){ 
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
int main(){
	fd = fopen("ir.dkk", "w");
	fprintf(fd, "j,\t,\t,\tL-main\n\n");
	symtb = hashtbl_create(10, NULL);
	currtb = symtb;
	return yyparse();
	hashtbl_destroy(symtb);
	fclose(fd);
}
