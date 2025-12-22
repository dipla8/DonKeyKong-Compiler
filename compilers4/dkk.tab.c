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



int yylex(void);
void yyerror(const char *s);
int scope = 0;
int dim_count = 0;
HASHTBL *symtb;
HASHTBL *currtb;
int currvis;

#line 89 "dkk.tab.c"

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
  YYSYMBOL_EQUOP = 33,                     /* EQUOP  */
  YYSYMBOL_RELOP = 34,                     /* RELOP  */
  YYSYMBOL_MULOP = 35,                     /* MULOP  */
  YYSYMBOL_NOTOP = 36,                     /* NOTOP  */
  YYSYMBOL_INCDEC = 37,                    /* INCDEC  */
  YYSYMBOL_SIZEOP = 38,                    /* SIZEOP  */
  YYSYMBOL_LISTFUNC = 39,                  /* LISTFUNC  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_SEMI = 43,                      /* SEMI  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 46,                    /* ASSIGN  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_LBRACK = 48,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 49,                    /* RBRACK  */
  YYSYMBOL_REFER = 50,                     /* REFER  */
  YYSYMBOL_LBRACE = 51,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 52,                    /* RBRACE  */
  YYSYMBOL_METH = 53,                      /* METH  */
  YYSYMBOL_INP = 54,                       /* INP  */
  YYSYMBOL_OUT = 55,                       /* OUT  */
  YYSYMBOL_LOWER_THAN_ELSE = 56,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_ADDOP = 57,                     /* ADDOP  */
  YYSYMBOL_ICONST = 58,                    /* ICONST  */
  YYSYMBOL_ID = 59,                        /* ID  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_global_declarations = 62,       /* global_declarations  */
  YYSYMBOL_global_declaration = 63,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 64,       /* typedef_declaration  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_typename = 66,                  /* typename  */
  YYSYMBOL_standard_type = 67,             /* standard_type  */
  YYSYMBOL_listspec = 68,                  /* listspec  */
  YYSYMBOL_dims = 69,                      /* dims  */
  YYSYMBOL_const_declaration = 70,         /* const_declaration  */
  YYSYMBOL_constdefs = 71,                 /* constdefs  */
  YYSYMBOL_constdef = 72,                  /* constdef  */
  YYSYMBOL_init_value = 73,                /* init_value  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_variable = 75,                  /* variable  */
  YYSYMBOL_general_expression = 76,        /* general_expression  */
  YYSYMBOL_assignment = 77,                /* assignment  */
  YYSYMBOL_expression_list = 78,           /* expression_list  */
  YYSYMBOL_constant = 79,                  /* constant  */
  YYSYMBOL_listexpression = 80,            /* listexpression  */
  YYSYMBOL_init_values = 81,               /* init_values  */
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
  YYSYMBOL_global_var_declaration = 107,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 108,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 109,         /* init_variabledef  */
  YYSYMBOL_initializer = 110,              /* initializer  */
  YYSYMBOL_func_declaration = 111,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 112,    /* full_func_declaration  */
  YYSYMBOL_113_5 = 113,                    /* $@5  */
  YYSYMBOL_114_6 = 114,                    /* $@6  */
  YYSYMBOL_115_7 = 115,                    /* $@7  */
  YYSYMBOL_full_par_func_header = 116,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 117,  /* class_func_header_start  */
  YYSYMBOL_func_class = 118,               /* func_class  */
  YYSYMBOL_parameter_list = 119,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 120,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 121,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 122,          /* decl_statements  */
  YYSYMBOL_declarations = 123,             /* declarations  */
  YYSYMBOL_decltype = 124,                 /* decltype  */
  YYSYMBOL_statements = 125,               /* statements  */
  YYSYMBOL_statement = 126,                /* statement  */
  YYSYMBOL_expression_statement = 127,     /* expression_statement  */
  YYSYMBOL_if_statement = 128,             /* if_statement  */
  YYSYMBOL_while_statement = 129,          /* while_statement  */
  YYSYMBOL_for_statement = 130,            /* for_statement  */
  YYSYMBOL_optexpr = 131,                  /* optexpr  */
  YYSYMBOL_return_statement = 132,         /* return_statement  */
  YYSYMBOL_io_statement = 133,             /* io_statement  */
  YYSYMBOL_in_list = 134,                  /* in_list  */
  YYSYMBOL_in_item = 135,                  /* in_item  */
  YYSYMBOL_out_list = 136,                 /* out_list  */
  YYSYMBOL_out_item = 137,                 /* out_item  */
  YYSYMBOL_comp_statement = 138,           /* comp_statement  */
  YYSYMBOL_139_8 = 139,                    /* $@8  */
  YYSYMBOL_140_9 = 140,                    /* $@9  */
  YYSYMBOL_main_function = 141,            /* main_function  */
  YYSYMBOL_142_10 = 142,                   /* $@10  */
  YYSYMBOL_main_header = 143               /* main_header  */
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
#define YYLAST   672

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    58,    58,    59,    60,    61,    62,    63,
      64,    65,    65,    66,    67,    68,    69,    70,    71,    72,
      72,    73,   101,   120,   122,   123,   123,   124,   125,   126,
     127,   128,   136,   144,   150,   156,   164,   172,   181,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   225,   247,   248,   266,   267,   268,   269,   270,   271,
     272,   272,   273,   274,   275,   276,   277,   277,   278,   278,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   283,
     284,   285,   286,   287,   288,   294,   300,   300,   301,   301,
     306,   307,   308,   308,   309,   310,   311,   311,   312,   313,
     319,   320,   320,   321,   321,   322,   323,   324,   325,   331,
     338,   339,   339,   340,   340,   341,   341,   342,   342,   343,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   351,
     352,   353,   354,   355,   355,   356,   357,   358,   358,   359,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   375,   376,   377,
     377,   378,   378,   379,   380,   380,   381,   381,   382,   382,
     382,   383,   383,   384
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
  "FCONST", "CCONST", "OROP", "ANDOP", "EQUOP", "RELOP", "MULOP", "NOTOP",
  "INCDEC", "SIZEOP", "LISTFUNC", "STRING", "LPAREN", "RPAREN", "SEMI",
  "DOT", "COMMA", "ASSIGN", "COLON", "LBRACK", "RBRACK", "REFER", "LBRACE",
  "RBRACE", "METH", "INP", "OUT", "LOWER_THAN_ELSE", "ADDOP", "ICONST",
  "ID", "$accept", "program", "global_declarations", "global_declaration",
  "typedef_declaration", "$@1", "typename", "standard_type", "listspec",
  "dims", "const_declaration", "constdefs", "constdef", "init_value",
  "expression", "variable", "general_expression", "assignment",
  "expression_list", "constant", "listexpression", "init_values",
  "class_declaration", "$@2", "class_body", "parent", "members_methods",
  "access", "member_or_method", "member", "var_declaration",
  "variabledefs", "variabledef", "$@3", "$@4", "anonymous_union",
  "union_body", "fields", "field", "method", "short_func_declaration",
  "short_par_func_header", "func_header_start", "parameter_types",
  "pass_list_dims", "nopar_func_header", "union_declaration",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "initializer", "func_declaration", "full_func_declaration", "$@5", "$@6",
  "$@7", "full_par_func_header", "class_func_header_start", "func_class",
  "parameter_list", "pass_variabledef", "nopar_class_func_header",
  "decl_statements", "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "while_statement",
  "for_statement", "optexpr", "return_statement", "io_statement",
  "in_list", "in_item", "out_list", "out_item", "comp_statement", "$@8",
  "$@9", "main_function", "$@10", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-222)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-158)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -222,    68,    25,  -222,   158,  -222,   -14,  -222,   158,    16,
      17,  -222,    33,  -222,  -222,  -222,     7,  -222,  -222,  -222,
    -222,    63,    98,   106,  -222,  -222,  -222,  -222,  -222,   120,
    -222,  -222,  -222,  -222,   179,   129,   112,   125,  -222,   166,
     181,   182,   -32,   168,   201,  -222,   194,  -222,    39,  -222,
     210,   217,    96,   221,   222,  -222,   211,   193,  -222,   206,
    -222,   158,   228,   231,  -222,  -222,  -222,  -222,   459,  -222,
    -222,    21,  -222,  -222,    12,    49,    95,   342,   342,  -222,
      27,   142,   342,   342,  -222,  -222,   204,  -222,   112,    21,
    -222,   154,  -222,  -222,   225,   249,   223,  -222,   247,  -222,
    -222,   255,   256,  -222,  -222,   614,    72,   614,   257,  -222,
     218,   295,   459,   614,  -222,  -222,   148,   156,  -222,  -222,
     240,  -222,  -222,   182,   245,  -222,  -222,  -222,  -222,  -222,
     158,  -222,   158,   263,   266,   269,   273,   275,   490,   272,
     262,  -222,  -222,   148,   155,   215,  -222,   276,   385,   161,
     264,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,   277,
     245,  -222,   278,   283,  -222,   459,    14,  -222,   219,  -222,
    -222,  -222,  -222,  -222,   227,   247,   614,   614,    64,   108,
    -222,   614,   285,   144,   292,   289,  -222,    74,   304,   614,
     614,   614,   614,   614,   614,  -222,   295,   259,   614,  -222,
    -222,   247,     1,    27,  -222,  -222,   614,   614,   490,   292,
     297,    72,   521,   342,   552,  -222,   614,  -222,   161,   264,
      23,    21,  -222,  -222,  -222,  -222,    79,  -222,  -222,   293,
    -222,    21,   294,   298,   299,    77,   110,   146,   170,   183,
    -222,  -222,  -222,   459,  -222,    64,    64,   176,   176,  -222,
     304,   302,  -222,   128,  -222,  -222,  -222,   184,   185,   305,
    -222,   108,    69,  -222,  -222,   292,   -18,  -222,  -222,  -222,
    -222,  -222,    21,   220,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,   110,   125,   288,    37,  -222,  -222,  -222,  -222,  -222,
    -222,   308,   106,  -222,  -222,  -222,  -222,  -222,  -222,   428,
     428,   490,  -222,    72,  -222,   521,   310,   224,  -222,  -222,
     307,  -222,   315,    39,   331,  -222,   314,  -222,  -222,  -222,
    -222,  -222,     1,   428,   583,  -222,   328,   428,  -222
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    15,    16,    17,     0,     0,
       0,    18,     0,    14,     3,     5,     0,    13,     6,     7,
     113,     0,     0,   119,     8,     9,    10,   114,   115,     0,
     117,     2,   171,    16,    20,     0,     0,     0,    68,   100,
       0,     0,    88,   112,     0,   109,     0,    96,     0,    97,
       0,     0,     0,     0,     0,    19,     0,     0,    23,     0,
      26,     0,     0,    72,   125,   124,    86,    23,   138,   110,
     107,     0,   123,   105,    20,     0,     0,   138,   138,   130,
       0,     0,   138,   138,    11,   173,     0,    24,     0,     0,
      94,     0,    93,   106,     0,     0,     0,    23,    89,   137,
      54,     0,     0,    64,    62,   138,   138,   138,     0,    30,
     138,    61,   138,   138,    63,   111,    28,    42,    46,    49,
       0,    88,   108,    19,   104,    23,   128,   102,   127,    98,
       0,   122,     0,     0,     0,     0,     0,     0,   138,     0,
       0,   150,   168,    59,    42,     0,    56,     0,   138,     0,
     133,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,   121,     0,     0,    23,   138,     0,    25,     0,    85,
      91,    92,    71,    69,    78,    87,   138,   138,    37,    40,
      39,   138,     0,     0,    60,     0,    67,     0,    38,   138,
     138,   138,   138,   138,   138,    41,    61,     0,   138,    53,
     129,   103,    20,     0,   148,   149,   138,   138,   138,   156,
       0,   138,   138,   138,   138,   151,   138,   120,     0,   131,
      53,     0,   139,   116,   118,   172,     0,    27,    22,     0,
      83,     0,     0,     0,     0,    78,     0,     0,     0,     0,
      48,    47,    65,   138,    29,    31,    32,    33,    34,    36,
      35,     0,    51,     0,   104,   101,   126,     0,     0,     0,
     158,   163,     0,   162,   167,   166,     0,   165,   169,    58,
      57,    55,     0,     0,    12,    21,    84,    75,    76,    77,
      70,     0,     0,     0,     0,    74,    79,    81,    82,    80,
      95,     0,     0,    44,    45,    52,    66,    43,    50,   138,
     138,   138,   159,   138,   160,   138,     0,     0,   136,    73,
       0,   100,    88,     0,   152,   154,     0,   161,   164,   170,
     135,    90,    20,   138,   138,   153,     0,   138,   155
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,  -222,  -222,  -222,    -2,   265,   339,   -56,
    -222,  -222,   286,   -86,   -48,   -58,  -103,   162,   186,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,   149,   105,  -222,
    -221,  -216,   -13,  -222,  -222,  -222,   107,  -222,   296,  -222,
     375,  -222,   386,  -222,   189,   390,  -222,  -222,  -222,   324,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,   380,   345,
     202,  -222,   -59,  -222,   -65,   268,  -149,  -222,  -222,  -222,
    -222,  -204,  -222,  -222,  -222,   114,  -222,   113,  -222,  -222,
    -222,  -222,  -222,  -222
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,    15,   164,    89,    17,   125,    86,
      18,    59,    60,   115,   143,   144,   145,   146,   185,   118,
     119,   187,    19,    63,    95,    96,   235,   236,   285,   286,
      90,   168,   169,    97,    67,   288,    62,    91,    92,   289,
     290,    21,   291,    75,   127,   292,    24,    25,    44,    45,
      69,    26,    27,    51,    53,    50,    28,    29,    40,    76,
     128,    30,   147,   148,   120,   150,   151,   152,   153,   154,
     155,   210,   156,   157,   262,   263,   266,   267,   158,   213,
     306,    31,    54,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,   222,    34,    43,   259,   273,    36,   183,   184,   -99,
     117,    98,   149,   149,    35,   287,    55,   149,   149,   159,
     116,    64,    41,   162,   163,   304,   186,   123,     4,     5,
       6,     7,     8,     9,    10,   209,    41,   305,   -14,    11,
      12,   175,    41,     5,    33,     7,    74,   117,   179,   117,
      80,   254,    41,    11,   117,   117,   307,   178,    43,   180,
     287,   126,   124,   228,   116,   188,    42,   126,     3,   201,
     222,   121,   229,   237,   238,    37,    38,   160,   239,   227,
     121,    73,   -14,   218,    13,    99,   121,   232,   233,   234,
     100,   129,    39,   184,   130,   253,   312,   316,    13,   193,
       5,    33,     7,   257,   258,   209,    47,   117,   226,   265,
      11,   108,   302,   271,     5,    33,     7,   116,   282,   243,
     326,   194,   274,   303,    11,   283,   244,   166,   202,   280,
     203,   117,   117,   117,   117,   117,   117,   131,    79,    48,
     132,   245,   246,   247,   248,   249,   250,   221,   149,    49,
     314,   315,   197,   261,   268,    13,   198,   296,     5,    33,
       7,    52,     5,    33,     7,     5,    33,     7,    11,    13,
      57,    58,    11,   216,   325,    11,    61,   298,   328,   189,
     190,   191,   192,   193,   161,   117,   241,   132,   293,   216,
     126,   216,   195,   195,    55,   116,   196,   196,   209,   197,
     197,   214,   265,   198,   198,   194,   170,   189,   190,  -158,
    -158,   193,   294,    13,    68,   216,   272,    13,   276,    64,
     220,   209,     5,    33,     7,   295,   299,   300,   216,   216,
     216,    99,    11,   194,   284,    85,   100,   232,   233,   234,
      65,    66,   101,   102,    70,   261,    71,   103,   104,    87,
     165,    88,   166,    72,   105,   106,   107,   108,   215,   110,
     216,    77,   230,   308,   231,   231,   111,   320,    78,   231,
      84,    93,    82,    83,   174,   113,   114,    99,    94,   284,
     133,   134,   100,   135,   172,   136,   137,   138,   101,   102,
     139,   140,   173,   103,   104,   166,   176,   177,   181,   199,
     105,   106,   107,   108,   200,   110,   204,   141,    99,   205,
     206,   322,   111,   100,   207,   142,   208,   212,   252,   101,
     102,   113,   114,  -138,   103,   104,   211,   240,   217,   223,
     224,   105,   106,   107,   108,   225,   110,   216,   242,   193,
     260,   277,   275,   111,   297,   278,   279,   311,   301,   313,
     321,   323,   113,   114,  -138,    99,   -99,   324,   133,   134,
     100,   135,   319,   136,   137,   138,   101,   102,   139,   140,
     327,   103,   104,    56,   167,   182,   270,    20,   105,   106,
     107,   108,   251,   110,   281,   141,   309,   171,    22,   310,
     111,   255,    23,   142,  -134,   122,    46,    81,    99,   113,
     114,   133,   134,   100,   135,   256,   136,   137,   138,   101,
     102,   139,   140,     0,   103,   104,   219,   317,   318,     0,
       0,   105,   106,   107,   108,     0,   110,     0,   141,     0,
       0,     0,     0,   111,     0,     0,   142,  -132,     0,     0,
       0,    99,   113,   114,   133,   134,   100,   135,     0,   136,
     137,   138,   101,   102,   139,   140,     0,   103,   104,     0,
       0,     0,     0,     0,   105,   106,   107,   108,     0,   110,
       0,   141,    99,     0,     0,     0,   111,   100,     0,   142,
       0,     0,     0,   101,   102,   113,   114,     0,   103,   104,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,     0,     0,    99,     0,     0,     0,   111,   100,     0,
     112,     0,     0,     0,   101,   102,   113,   114,     0,   103,
     104,     0,     0,     0,     0,     0,   105,   106,   107,   108,
       0,   110,     0,  -157,    99,     0,     0,     0,   111,   100,
       0,     0,     0,     0,     0,   101,   102,   113,   114,     0,
     103,   104,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   264,   110,     0,     0,    99,     0,     0,     0,   111,
     100,     0,     0,     0,     0,     0,   101,   102,   113,   114,
       0,   103,   104,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   269,   110,     0,     0,    99,     0,     0,     0,
     111,   100,     0,     0,     0,     0,     0,   101,   102,   113,
     114,     0,   103,   104,     0,     0,     0,     0,     0,   105,
     106,   107,   108,     0,   110,  -157,     0,    99,     0,     0,
       0,   111,   100,     0,     0,     0,     0,     0,   101,   102,
     113,   114,     0,   103,   104,     0,     0,     0,     0,     0,
     105,   106,   107,   108,     0,   110,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114
};

static const yytype_int16 yycheck[] =
{
       2,   150,     4,    16,   208,   221,     8,   110,   111,    41,
      68,    67,    77,    78,    28,   236,    15,    82,    83,    78,
      68,    53,    15,    82,    83,    43,   112,    15,     3,     4,
       5,     6,     7,     8,     9,   138,    15,    55,    15,    14,
      15,    97,    15,     4,     5,     6,    48,   105,   106,   107,
      52,    50,    15,    14,   112,   113,   272,   105,    71,   107,
     281,    74,    50,    49,   112,   113,    59,    80,     0,   125,
     219,    59,    58,   176,   177,    59,    59,    50,   181,   165,
      59,    42,    59,   148,    59,    13,    59,    10,    11,    12,
      18,    42,    59,   196,    45,   198,    59,   301,    59,    35,
       4,     5,     6,   206,   207,   208,    43,   165,   164,   212,
      14,    39,    43,   216,     4,     5,     6,   165,     8,    45,
     324,    57,    43,    54,    14,    15,    52,    48,   130,    52,
     132,   189,   190,   191,   192,   193,   194,    42,    42,    41,
      45,   189,   190,   191,   192,   193,   194,   149,   213,    43,
     299,   300,    44,   211,   213,    59,    48,   243,     4,     5,
       6,    41,     4,     5,     6,     4,     5,     6,    14,    59,
      41,    59,    14,    45,   323,    14,    51,    49,   327,    31,
      32,    33,    34,    35,    42,   243,    42,    45,    42,    45,
     203,    45,    37,    37,    15,   243,    41,    41,   301,    44,
      44,    46,   305,    48,    48,    57,    52,    31,    32,    33,
      34,    35,    42,    59,    46,    45,   218,    59,   231,    53,
      59,   324,     4,     5,     6,    42,    42,    42,    45,    45,
      45,    13,    14,    57,   236,    42,    18,    10,    11,    12,
      59,    59,    24,    25,    43,   303,    45,    29,    30,    43,
      46,    45,    48,    59,    36,    37,    38,    39,    43,    41,
      45,    51,    43,    43,    45,    45,    48,    43,    51,    45,
      59,    43,    51,    51,    51,    57,    58,    13,    47,   281,
      16,    17,    18,    19,    59,    21,    22,    23,    24,    25,
      26,    27,    43,    29,    30,    48,    41,    41,    41,    59,
      36,    37,    38,    39,    59,    41,    43,    43,    13,    43,
      41,   313,    48,    18,    41,    51,    41,    55,    59,    24,
      25,    57,    58,    59,    29,    30,    54,    42,    52,    52,
      52,    36,    37,    38,    39,    52,    41,    45,    49,    35,
      43,    47,    49,    48,    42,    47,    47,    59,    43,    41,
      43,    20,    57,    58,    59,    13,    41,    43,    16,    17,
      18,    19,    52,    21,    22,    23,    24,    25,    26,    27,
      42,    29,    30,    34,    88,   110,   214,     2,    36,    37,
      38,    39,   196,    41,   235,    43,   281,    91,     2,   282,
      48,   202,     2,    51,    52,    71,    16,    52,    13,    57,
      58,    16,    17,    18,    19,   203,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,   148,   303,   305,    -1,
      -1,    36,    37,    38,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    13,    57,    58,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    43,    13,    -1,    -1,    -1,    48,    18,    -1,    51,
      -1,    -1,    -1,    24,    25,    57,    58,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    -1,    -1,    13,    -1,    -1,    -1,    48,    18,    -1,
      51,    -1,    -1,    -1,    24,    25,    57,    58,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    43,    13,    -1,    -1,    -1,    48,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    57,    58,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    13,    -1,    -1,    -1,    48,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    57,    58,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    13,    -1,    -1,    -1,
      48,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    57,
      58,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    42,    -1,    13,    -1,    -1,
      -1,    48,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      57,    58,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,     4,     5,     6,     7,     8,
       9,    14,    15,    59,    63,    64,    66,    67,    70,    82,
     100,   101,   102,   105,   106,   107,   111,   112,   116,   117,
     121,   141,   143,     5,    66,    28,    66,    59,    59,    59,
     118,    15,    59,    92,   108,   109,   118,    43,    41,    43,
     115,   113,    41,   114,   142,    15,    68,    41,    59,    71,
      72,    51,    96,    83,    53,    59,    59,    94,    46,   110,
      43,    45,    59,    42,    66,   103,   119,    51,    51,    42,
      66,   119,    51,    51,    59,    42,    69,    43,    45,    66,
      90,    97,    98,    43,    47,    84,    85,    93,    69,    13,
      18,    24,    25,    29,    30,    36,    37,    38,    39,    40,
      41,    48,    51,    57,    58,    73,    74,    75,    79,    80,
     124,    59,   109,    15,    50,    68,    92,   104,   120,    42,
      45,    42,    45,    16,    17,    19,    21,    22,    23,    26,
      27,    43,    51,    74,    75,    76,    77,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   132,   133,   138,   122,
      50,    42,   122,   122,    65,    46,    48,    72,    91,    92,
      52,    98,    59,    43,    51,    69,    41,    41,    74,    75,
      74,    41,    67,    76,    76,    78,    73,    81,    74,    31,
      32,    33,    34,    35,    57,    37,    41,    44,    48,    59,
      59,    69,    66,    66,    43,    43,    41,    41,    41,    76,
     131,    54,    55,   139,    46,    43,    45,    52,   124,   125,
      59,    66,   126,    52,    52,    52,    69,    73,    49,    58,
      43,    45,    10,    11,    12,    86,    87,    76,    76,    76,
      42,    42,    49,    45,    52,    74,    74,    74,    74,    74,
      74,    78,    59,    76,    50,   104,   120,    76,    76,   131,
      43,    75,   134,   135,    40,    76,   136,   137,   122,    40,
      77,    76,    66,    91,    43,    49,    92,    47,    47,    47,
      52,    87,     8,    15,    66,    88,    89,    90,    95,    99,
     100,   102,   105,    42,    42,    42,    73,    42,    49,    42,
      42,    43,    43,    54,    43,    55,   140,    91,    43,    88,
      96,    59,    59,    41,   126,   126,   131,   135,   137,    52,
      43,    43,    66,    20,    43,   126,   131,    42,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    65,    64,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    70,    71,    71,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    79,    80,    81,    81,    83,    82,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    93,    92,    94,    92,
      95,    96,    97,    97,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   104,   104,   105,   106,   107,   108,   108,
     109,   110,   110,   111,   111,   113,   112,   114,   112,   115,
     112,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     121,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   128,   128,   129,   130,   131,   131,   132,   133,
     133,   134,   134,   135,   136,   136,   137,   137,   139,   140,
     138,   142,   141,   143
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     7,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     3,     0,     4,     3,     1,     4,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     4,     4,     4,     1,     3,     3,     1,
       4,     3,     4,     2,     1,     3,     1,     3,     3,     1,
       1,     0,     1,     1,     1,     3,     3,     1,     0,     5,
       4,     2,     0,     3,     2,     2,     2,     2,     0,     1,
       1,     1,     1,     3,     3,     1,     0,     4,     0,     3,
       3,     3,     2,     1,     1,     1,     2,     2,     4,     2,
       2,     4,     2,     2,     1,     3,     4,     3,     3,     1,
       2,     2,     0,     1,     1,     0,     5,     0,     5,     0,
       5,     4,     4,     3,     3,     2,     4,     2,     1,     2,
       3,     2,     1,     1,     0,     5,     4,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     5,     7,     5,     9,     1,     0,     3,     4,
       4,     3,     1,     1,     3,     1,     1,     1,     0,     0,
       5,     0,     5,     4
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
#line 57 "dkk.y"
                                           {exit(0);}
#line 1534 "dkk.tab.c"
    break;

  case 10: /* global_declaration: func_declaration  */
#line 64 "dkk.y"
                           {printf("global");}
#line 1540 "dkk.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 65 "dkk.y"
                                                   {dim_count = 0;}
#line 1546 "dkk.tab.c"
    break;

  case 12: /* typedef_declaration: TYPEDEF typename listspec ID $@1 dims SEMI  */
#line 65 "dkk.y"
                                                                              {hashtbl_insert(symtb, (yyvsp[-3].str), (yyvsp[-5].str) , scope, (yyvsp[-1].arr), 1, currvis);}
#line 1552 "dkk.tab.c"
    break;

  case 13: /* typename: standard_type  */
#line 66 "dkk.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1558 "dkk.tab.c"
    break;

  case 14: /* typename: ID  */
#line 67 "dkk.y"
                     {struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), 0); if(p == NULL || p->istype == 0) printf("semantic error\n");else{(yyval.str) = p->key;}}
#line 1564 "dkk.tab.c"
    break;

  case 15: /* standard_type: CHAR  */
#line 68 "dkk.y"
                     {(yyval.str)="char";}
#line 1570 "dkk.tab.c"
    break;

  case 16: /* standard_type: INT  */
#line 69 "dkk.y"
                      {(yyval.str)="int";}
#line 1576 "dkk.tab.c"
    break;

  case 17: /* standard_type: FLOAT  */
#line 70 "dkk.y"
                        {(yyval.str)="float";}
#line 1582 "dkk.tab.c"
    break;

  case 18: /* standard_type: VOID  */
#line 71 "dkk.y"
                       {(yyval.str)="void";}
#line 1588 "dkk.tab.c"
    break;

  case 21: /* dims: dims LBRACK ICONST RBRACK  */
#line 73 "dkk.y"
                                 {
		if (dim_count == MAX_DIMENSIONS) {
			//ERROR
			printf("Error: Exceeded maximum number of dimensions (%d)\n", MAX_DIMENSIONS);
			if ((yyvsp[-3].arr)) free((yyvsp[-3].arr));
		}
		else if (dim_count == 0) {
			(yyval.arr) = malloc(sizeof(array_t));
			if (!(yyval.arr)) {
				printf("Memory allocation error\n");
				exit(1);
			}
			if ((yyvsp[-1].ival) <= 0) {
				printf("Error: Array dimension must be positive integer\n");
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
#line 1621 "dkk.tab.c"
    break;

  case 22: /* dims: dims LBRACK RBRACK  */
#line 101 "dkk.y"
                             {
		if (dim_count == MAX_DIMENSIONS) {
			//ERROR
			printf("Error: Exceeded maximum number of dimensions (%d)\n", MAX_DIMENSIONS);
			if ((yyvsp[-2].arr)) free((yyvsp[-2].arr));
		}
		else if (dim_count == 0) {
			(yyval.arr) = malloc(sizeof(array_t));
			(yyval.arr)->dim_size[0] = 0;
			(yyval.arr)->dims++;
			dim_count++;
		}
		else {
			(yyvsp[-2].arr)->dim_size[dim_count] = 0;
			(yyvsp[-2].arr)->dims++;
			(yyval.arr) = (yyvsp[-2].arr);
			dim_count++;
		}
	}
#line 1645 "dkk.tab.c"
    break;

  case 23: /* dims: %empty  */
#line 120 "dkk.y"
      {(yyval.arr) = NULL;}
#line 1651 "dkk.tab.c"
    break;

  case 31: /* expression: expression OROP expression  */
#line 128 "dkk.y"
                                        { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
					}
#line 1664 "dkk.tab.c"
    break;

  case 32: /* expression: expression ANDOP expression  */
#line 136 "dkk.y"
                                      { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
				      }
#line 1677 "dkk.tab.c"
    break;

  case 33: /* expression: expression EQUOP expression  */
#line 144 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type equop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1688 "dkk.tab.c"
    break;

  case 34: /* expression: expression RELOP expression  */
#line 150 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type relop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1699 "dkk.tab.c"
    break;

  case 35: /* expression: expression ADDOP expression  */
#line 156 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if (((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT)) {
						(yyval.myexpr).type = T_FLOAT;
					}
					// list check
					else printf("semantic error\n");	
				      }
#line 1712 "dkk.tab.c"
    break;

  case 36: /* expression: expression MULOP expression  */
#line 164 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if ((((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT))/* && ($2.type != T_MULOP_MOD)*/) {
						(yyval.myexpr).type = T_FLOAT;
					}
					//list
					else printf("semantic error\n");	
				      }
#line 1725 "dkk.tab.c"
    break;

  case 37: /* expression: NOTOP expression  */
#line 172 "dkk.y"
                           { if ((yyvsp[0].myexpr).type != T_INT) { 
	                     	printf("not correct type. semantics error\n");
	                     }
	                     else {
	                   	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
	                   	printf("correct type\n");
	                     }
	                   }
#line 1738 "dkk.tab.c"
    break;

  case 38: /* expression: ADDOP expression  */
#line 181 "dkk.y"
                           { if (((yyvsp[0].myexpr).type != T_INT) || ((yyvsp[0].myexpr).type != T_FLOAT)) {
		             	printf("semantic error\n");
			     }
			     else {
			     	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
				(yyval.myexpr).val = (yyvsp[0].myexpr).val;
	                   	printf("correct type\n");
			     	if((yyvsp[-1].oper) == 1)
					if((yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).val.ival = ((yyvsp[0].myexpr).val.ival * (-1));	
					if((yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).val.fval = ((yyvsp[0].myexpr).val.fval * (-1));
				}
			   }
#line 1757 "dkk.tab.c"
    break;

  case 39: /* expression: SIZEOP expression  */
#line 195 "dkk.y"
                            {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = 0;}
#line 1763 "dkk.tab.c"
    break;

  case 40: /* expression: INCDEC variable  */
#line 196 "dkk.y"
                          {var_to_expr(&(yyval.myexpr), (yyvsp[0].myvar).ival);(yyval.myexpr).rec_count = (yyvsp[0].myvar).rec_count; (yyval.myexpr).n = (yyvsp[0].myvar).n;}
#line 1769 "dkk.tab.c"
    break;

  case 41: /* expression: variable INCDEC  */
#line 197 "dkk.y"
                          {var_to_expr(&(yyval.myexpr), (yyvsp[-1].myvar).ival);(yyval.myexpr).rec_count = (yyvsp[-1].myvar).rec_count; (yyval.myexpr).n = (yyvsp[-1].myvar).n;}
#line 1775 "dkk.tab.c"
    break;

  case 42: /* expression: variable  */
#line 198 "dkk.y"
                   {var_to_expr(&(yyval.myexpr), (yyvsp[0].myvar).ival); (yyval.myexpr).rec_count = (yyvsp[0].myvar).rec_count; (yyval.myexpr).n = (yyvsp[0].myvar).n; printf("%d\n", (yyval.myexpr).type); printf("%d\n", (yyval.myexpr).val.ival);}
#line 1781 "dkk.tab.c"
    break;

  case 43: /* expression: variable LPAREN expression_list RPAREN  */
#line 199 "dkk.y"
                                                 {var_to_expr(&(yyval.myexpr), (yyvsp[-3].myvar).ival);}
#line 1787 "dkk.tab.c"
    break;

  case 46: /* expression: constant  */
#line 202 "dkk.y"
                   {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val; (yyval.myexpr).n = malloc(sizeof(expr_t)); (yyval.myexpr).n->arr = malloc(sizeof(array_t)); (yyval.myexpr).n->arr->dims = 0; (yyval.myexpr).rec_count = 0;}
#line 1793 "dkk.tab.c"
    break;

  case 50: /* variable: variable LBRACK general_expression RBRACK  */
#line 206 "dkk.y"
                                                     {
							if((yyvsp[-1].myexpr).type != T_INT ||((yyvsp[-1].myexpr).n->arr != NULL) && ((yyvsp[-1].myexpr).rec_count != (yyvsp[-1].myexpr).n->arr->dims))
								printf("semantic error here\n");
							else{
							     if((yyvsp[-3].myvar).rec_count > (yyvsp[-3].myvar).n->arr->dims)
								printf("semantic error there\n");
						 	     else if((yyvsp[-1].myexpr).val.ival <0 || (yyvsp[-1].myexpr).val.ival >= (yyvsp[-3].myvar).n->arr->dim_size[(yyvsp[-3].myvar).rec_count]){
							    //if($3.val.ival <0 || $3.val.ival >= curr_node->arr->dim_size[curr_node->arr->dims - rec_count]){
								printf("dims:%d, rec_count: %d\n", (yyvsp[-3].myvar).n->arr->dims, (yyvsp[-3].myvar).rec_count);
								printf("curr_dimsize %d, ival %d\n", (yyvsp[-3].myvar).n->arr->dim_size[(yyvsp[-3].myvar).rec_count], (yyvsp[-1].myexpr).val.ival);
								printf("semantic error2\n");}
							     	else {
									if((yyvsp[-1].myexpr).rec_count != (yyvsp[-1].myexpr).n->arr->dims)
										printf("semantic error\n");
									(yyval.myvar).rec_count = (yyvsp[-3].myvar).rec_count+1;
									(yyval.myvar).n = (yyvsp[-3].myvar).n;
								}
							}
					}
#line 1817 "dkk.tab.c"
    break;

  case 51: /* variable: variable DOT ID  */
#line 225 "dkk.y"
                          {if((yyvsp[-2].myvar).n == NULL) printf("semantic error 1\n");
			if((yyvsp[-2].myvar).n->cla == NULL)
				printf("semantic error 2\n");
			struct hashnode_s *p = (yyvsp[-2].myvar).n;
			int perm = 2; // INITIALLY, PERMISSION = 2
			while(hashtbl_lookup(p->cla->classtb, scope, (yyvsp[0].str), perm) == NULL){
				if(p->cla->superclass == NULL)
					printf("semantic error 3\n");
				printf("psaxnw father %s\n", p->cla->superclass);
				perm = 1;
				p = hashtbl_lookup(symtb, scope, p->cla->superclass, 0);
			}
			(yyval.myvar).rec_count = 0;
			(yyval.myvar).ival =0;
			if(p == NULL)
				p = malloc(sizeof(struct hashnode_s));
			if(p->arr ==  NULL){
				p->arr = malloc(sizeof(array_t));
				p->arr->dims = 0;
			}
			(yyval.myvar).n = p;
			}
#line 1844 "dkk.tab.c"
    break;

  case 52: /* variable: LISTFUNC LPAREN general_expression RPAREN  */
#line 247 "dkk.y"
                                                    {}
#line 1850 "dkk.tab.c"
    break;

  case 53: /* variable: decltype ID  */
#line 248 "dkk.y"
                      { 
			struct hashnode_s *p;
			if((p = hashtbl_lookup(symtb, scope, yylval.str, 0)) == NULL)
				printf("semantics error\n");
			else{
				(yyval.myvar).rec_count = 0;
			 	(yyval.myvar).n = p;
				if(!strcmp(p->data, "char"))
					(yyval.myvar).ival = 0;
				else if(!strcmp(p->data, "int"))
					(yyval.myvar).ival = 1;
				else if(!strcmp(p->data, "float"))
					(yyval.myvar).ival = 2;
				else if(!strcmp(p->data, "void"))
					(yyval.myvar).ival = 3;
				else (yyval.myvar).ival = 4;
			}
		}
#line 1873 "dkk.tab.c"
    break;

  case 56: /* general_expression: assignment  */
#line 268 "dkk.y"
                    {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val; (yyval.myexpr).rec_count = (yyvsp[0].myexpr).rec_count; (yyval.myexpr).n = (yyvsp[0].myexpr).n;}
#line 1879 "dkk.tab.c"
    break;

  case 57: /* assignment: variable ASSIGN assignment  */
#line 269 "dkk.y"
                                        {if((yyvsp[-2].myvar).rec_count != (yyvsp[-2].myvar).n->arr->dims) printf("semantic error\n");}
#line 1885 "dkk.tab.c"
    break;

  case 59: /* assignment: expression  */
#line 271 "dkk.y"
                     {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val;(yyval.myexpr).rec_count = (yyvsp[0].myexpr).rec_count; (yyval.myexpr).n = (yyvsp[0].myexpr).n;}
#line 1891 "dkk.tab.c"
    break;

  case 62: /* constant: CCONST  */
#line 273 "dkk.y"
                  {(yyval.myexpr).type = T_CHAR; (yyval.myexpr).val.cval = yylval.cval;}
#line 1897 "dkk.tab.c"
    break;

  case 63: /* constant: ICONST  */
#line 274 "dkk.y"
                 {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = yylval.ival;}
#line 1903 "dkk.tab.c"
    break;

  case 64: /* constant: FCONST  */
#line 275 "dkk.y"
                 {(yyval.myexpr).type = T_FLOAT; (yyval.myexpr).val.fval = yylval.fval;}
#line 1909 "dkk.tab.c"
    break;

  case 68: /* $@2: %empty  */
#line 278 "dkk.y"
                             {hashtbl_insert(symtb, (yyvsp[0].str), "class", scope, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), 0); currtb = p->cla->classtb; printf("FINALLY\n");}
#line 1915 "dkk.tab.c"
    break;

  case 69: /* class_declaration: CLASS ID $@2 class_body SEMI  */
#line 278 "dkk.y"
                                                                                                                                                                                                                 {struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[-3].str), 0); p->cla->superclass = (yyvsp[-1].str);currtb = symtb; currvis = 0;}
#line 1921 "dkk.tab.c"
    break;

  case 70: /* class_body: parent LBRACE members_methods RBRACE  */
#line 279 "dkk.y"
                                                  {(yyval.str) = (yyvsp[-3].str);}
#line 1927 "dkk.tab.c"
    break;

  case 71: /* parent: COLON ID  */
#line 280 "dkk.y"
                  {(yyval.str) = (yyvsp[0].str);}
#line 1933 "dkk.tab.c"
    break;

  case 72: /* parent: %empty  */
#line 280 "dkk.y"
                               {(yyval.str) = NULL;}
#line 1939 "dkk.tab.c"
    break;

  case 75: /* access: PRIVATE COLON  */
#line 282 "dkk.y"
                       {currvis = 2;}
#line 1945 "dkk.tab.c"
    break;

  case 76: /* access: PROTECTED COLON  */
#line 282 "dkk.y"
                                                       {currvis = 1;}
#line 1951 "dkk.tab.c"
    break;

  case 77: /* access: PUBLIC COLON  */
#line 282 "dkk.y"
                                                                                     {currvis = 0;}
#line 1957 "dkk.tab.c"
    break;

  case 83: /* var_declaration: typename variabledefs SEMI  */
#line 287 "dkk.y"
                                             {(yyvsp[-1].idlist)->id->data = (yyvsp[-2].str); var_decl((yyvsp[-1].idlist));}
#line 1963 "dkk.tab.c"
    break;

  case 84: /* variabledefs: variabledefs COMMA variabledef  */
#line 288 "dkk.y"
                                              {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = (yyvsp[-2].idlist);
          (yyval.idlist) = n;
      }
#line 1974 "dkk.tab.c"
    break;

  case 85: /* variabledefs: variabledef  */
#line 294 "dkk.y"
                      {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = NULL;
          (yyval.idlist) = n;
      }
#line 1985 "dkk.tab.c"
    break;

  case 86: /* $@3: %empty  */
#line 300 "dkk.y"
                      {dim_count = 0;}
#line 1991 "dkk.tab.c"
    break;

  case 88: /* $@4: %empty  */
#line 301 "dkk.y"
             {dim_count = 0;}
#line 1997 "dkk.tab.c"
    break;

  case 89: /* variabledef: ID $@4 dims  */
#line 301 "dkk.y"
                                   {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[-2].str);
		(yyval.id)->arr = (yyvsp[0].arr);
	}
#line 2007 "dkk.tab.c"
    break;

  case 99: /* func_header_start: typename ID  */
#line 313 "dkk.y"
                                {id_list_t* n = malloc(sizeof(id_list_t));
          			n->id = malloc(sizeof(my_id_t));
				n->id->id = (yyvsp[0].str);
				n->id->arr = NULL;
       			 	n->id->data = (yyvsp[-1].str);
				n->next = NULL;
				var_decl(n);}
#line 2019 "dkk.tab.c"
    break;

  case 107: /* global_var_declaration: typename init_variabledefs SEMI  */
#line 324 "dkk.y"
                                                         {(yyvsp[-1].idlist)->id->data = (yyvsp[-2].str); var_decl((yyvsp[-1].idlist));}
#line 2025 "dkk.tab.c"
    break;

  case 108: /* init_variabledefs: init_variabledefs COMMA init_variabledef  */
#line 325 "dkk.y"
                                                              {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = (yyvsp[0].id);
         		 n->next = (yyvsp[-2].idlist);
         		 (yyval.idlist) = n;
      			}
#line 2036 "dkk.tab.c"
    break;

  case 109: /* init_variabledefs: init_variabledef  */
#line 331 "dkk.y"
                                                  {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = (yyvsp[0].id);
					n->next = NULL;
					(yyval.idlist) = n;
				}
#line 2047 "dkk.tab.c"
    break;

  case 110: /* init_variabledef: variabledef initializer  */
#line 338 "dkk.y"
                                           {(yyval.id) = (yyvsp[-1].id); printf("init_variabledef\n");}
#line 2053 "dkk.tab.c"
    break;

  case 114: /* func_declaration: full_func_declaration  */
#line 340 "dkk.y"
                                                                  {printf("sevo\n");}
#line 2059 "dkk.tab.c"
    break;

  case 115: /* $@5: %empty  */
#line 341 "dkk.y"
                                             {scope++;}
#line 2065 "dkk.tab.c"
    break;

  case 116: /* full_func_declaration: full_par_func_header $@5 LBRACE decl_statements RBRACE  */
#line 341 "dkk.y"
                                                                                      {hashtbl_get(symtb, scope); scope--;}
#line 2071 "dkk.tab.c"
    break;

  case 117: /* $@6: %empty  */
#line 342 "dkk.y"
                                          {scope++;}
#line 2077 "dkk.tab.c"
    break;

  case 118: /* full_func_declaration: nopar_class_func_header $@6 LBRACE decl_statements RBRACE  */
#line 342 "dkk.y"
                                                                                  {hashtbl_get(symtb, scope);scope--;}
#line 2083 "dkk.tab.c"
    break;

  case 119: /* $@7: %empty  */
#line 343 "dkk.y"
                                    {scope++;}
#line 2089 "dkk.tab.c"
    break;

  case 120: /* full_func_declaration: nopar_func_header $@7 LBRACE decl_statements RBRACE  */
#line 343 "dkk.y"
                                                                            {hashtbl_get(symtb, scope);scope--;}
#line 2095 "dkk.tab.c"
    break;

  case 135: /* declarations: declarations decltype typename variabledefs SEMI  */
#line 356 "dkk.y"
                                                                {  (yyvsp[-1].idlist)->id->data = (yyvsp[-2].str); var_decl((yyvsp[-1].idlist));}
#line 2101 "dkk.tab.c"
    break;

  case 136: /* declarations: decltype typename variabledefs SEMI  */
#line 357 "dkk.y"
                                                     {  (yyvsp[-1].idlist)->id->data = (yyvsp[-2].str); var_decl((yyvsp[-1].idlist));}
#line 2107 "dkk.tab.c"
    break;

  case 168: /* $@8: %empty  */
#line 382 "dkk.y"
                      {scope++;}
#line 2113 "dkk.tab.c"
    break;

  case 169: /* $@9: %empty  */
#line 382 "dkk.y"
                                                 {hashtbl_get(symtb, scope);scope--;}
#line 2119 "dkk.tab.c"
    break;

  case 171: /* $@10: %empty  */
#line 383 "dkk.y"
                           {scope++;}
#line 2125 "dkk.tab.c"
    break;

  case 172: /* main_function: main_header $@10 LBRACE decl_statements RBRACE  */
#line 383 "dkk.y"
                                                                    {hashtbl_get(symtb, scope);scope--;}
#line 2131 "dkk.tab.c"
    break;


#line 2135 "dkk.tab.c"

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

#line 385 "dkk.y"


void var_decl(id_list_t *var_list) {
	id_list_t *curr = var_list, *prv = var_list;
	while (curr) {
		printf("str = %s\n", curr->id->id);
		if(hashtbl_lookup(symtb, scope, curr->id->id, 0) != NULL)
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
	return yyparse();
	hashtbl_destroy(symtb);
}
