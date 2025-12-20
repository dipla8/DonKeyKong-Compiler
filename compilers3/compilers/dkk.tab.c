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
#include "hashtbl.h"
int yylex(void);
void yyerror(const char *s);
int scope = 0;
HASHTBL *symtb;

#line 84 "dkk.tab.c"

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
  YYSYMBOL_ICONST = 29,                    /* ICONST  */
  YYSYMBOL_FCONST = 30,                    /* FCONST  */
  YYSYMBOL_CCONST = 31,                    /* CCONST  */
  YYSYMBOL_OROP = 32,                      /* OROP  */
  YYSYMBOL_ANDOP = 33,                     /* ANDOP  */
  YYSYMBOL_EQUOP = 34,                     /* EQUOP  */
  YYSYMBOL_RELOP = 35,                     /* RELOP  */
  YYSYMBOL_ADDOP = 36,                     /* ADDOP  */
  YYSYMBOL_MULOP = 37,                     /* MULOP  */
  YYSYMBOL_NOTOP = 38,                     /* NOTOP  */
  YYSYMBOL_INCDEC = 39,                    /* INCDEC  */
  YYSYMBOL_SIZEOP = 40,                    /* SIZEOP  */
  YYSYMBOL_LISTFUNC = 41,                  /* LISTFUNC  */
  YYSYMBOL_STRING = 42,                    /* STRING  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_SEMI = 45,                      /* SEMI  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 48,                    /* ASSIGN  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_LBRACK = 50,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 51,                    /* RBRACK  */
  YYSYMBOL_REFER = 52,                     /* REFER  */
  YYSYMBOL_LBRACE = 53,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 54,                    /* RBRACE  */
  YYSYMBOL_METH = 55,                      /* METH  */
  YYSYMBOL_INP = 56,                       /* INP  */
  YYSYMBOL_OUT = 57,                       /* OUT  */
  YYSYMBOL_ID = 58,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 59,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_global_declarations = 62,       /* global_declarations  */
  YYSYMBOL_global_declaration = 63,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 64,       /* typedef_declaration  */
  YYSYMBOL_typename = 65,                  /* typename  */
  YYSYMBOL_standard_type = 66,             /* standard_type  */
  YYSYMBOL_listspec = 67,                  /* listspec  */
  YYSYMBOL_dims = 68,                      /* dims  */
  YYSYMBOL_dim = 69,                       /* dim  */
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
  YYSYMBOL_class_body = 83,                /* class_body  */
  YYSYMBOL_parent = 84,                    /* parent  */
  YYSYMBOL_members_methods = 85,           /* members_methods  */
  YYSYMBOL_access = 86,                    /* access  */
  YYSYMBOL_member_or_method = 87,          /* member_or_method  */
  YYSYMBOL_member = 88,                    /* member  */
  YYSYMBOL_var_declaration = 89,           /* var_declaration  */
  YYSYMBOL_variabledefs = 90,              /* variabledefs  */
  YYSYMBOL_variabledef = 91,               /* variabledef  */
  YYSYMBOL_anonymous_union = 92,           /* anonymous_union  */
  YYSYMBOL_union_body = 93,                /* union_body  */
  YYSYMBOL_fields = 94,                    /* fields  */
  YYSYMBOL_field = 95,                     /* field  */
  YYSYMBOL_method = 96,                    /* method  */
  YYSYMBOL_short_func_declaration = 97,    /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 98,     /* short_par_func_header  */
  YYSYMBOL_func_header_start = 99,         /* func_header_start  */
  YYSYMBOL_parameter_types = 100,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 101,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 102,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 103,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 104,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 105,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 106,         /* init_variabledef  */
  YYSYMBOL_initializer = 107,              /* initializer  */
  YYSYMBOL_func_declaration = 108,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 109,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 110,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 111,  /* class_func_header_start  */
  YYSYMBOL_func_class = 112,               /* func_class  */
  YYSYMBOL_parameter_list = 113,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 114,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 115,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 116,          /* decl_statements  */
  YYSYMBOL_declarations = 117,             /* declarations  */
  YYSYMBOL_decltype = 118,                 /* decltype  */
  YYSYMBOL_statements = 119,               /* statements  */
  YYSYMBOL_statement = 120,                /* statement  */
  YYSYMBOL_expression_statement = 121,     /* expression_statement  */
  YYSYMBOL_if_statement = 122,             /* if_statement  */
  YYSYMBOL_while_statement = 123,          /* while_statement  */
  YYSYMBOL_for_statement = 124,            /* for_statement  */
  YYSYMBOL_optexpr = 125,                  /* optexpr  */
  YYSYMBOL_return_statement = 126,         /* return_statement  */
  YYSYMBOL_io_statement = 127,             /* io_statement  */
  YYSYMBOL_in_list = 128,                  /* in_list  */
  YYSYMBOL_in_item = 129,                  /* in_item  */
  YYSYMBOL_out_list = 130,                 /* out_list  */
  YYSYMBOL_out_item = 131,                 /* out_item  */
  YYSYMBOL_comp_statement = 132,           /* comp_statement  */
  YYSYMBOL_main_function = 133,            /* main_function  */
  YYSYMBOL_main_header = 134               /* main_header  */
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
#define YYLAST   636

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

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
       0,    45,    45,    46,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    64,    65,    66,    67,
      68,    69,    77,    85,    91,    97,   105,   113,   122,   130,
     131,   132,   133,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   158,   159,   160,   161,   162,   163,
     164,   164,   165,   166,   167,   168,   169,   169,   170,   171,
     172,   172,   173,   173,   174,   174,   174,   174,   175,   176,
     177,   178,   179,   204,   210,   216,   217,   218,   219,   220,
     220,   221,   222,   223,   223,   224,   225,   225,   226,   226,
     227,   227,   228,   229,   230,   255,   261,   268,   269,   269,
     270,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   281,   282,   283,   284,   285,   285,   286,
     311,   336,   336,   337,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   349,   350,   351,
     352,   352,   353,   354,   354,   355,   355,   356,   357,   357,
     358,   358,   359,   360,   361
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
  "ICONST", "FCONST", "CCONST", "OROP", "ANDOP", "EQUOP", "RELOP", "ADDOP",
  "MULOP", "NOTOP", "INCDEC", "SIZEOP", "LISTFUNC", "STRING", "LPAREN",
  "RPAREN", "SEMI", "DOT", "COMMA", "ASSIGN", "COLON", "LBRACK", "RBRACK",
  "REFER", "LBRACE", "RBRACE", "METH", "INP", "OUT", "ID",
  "LOWER_THAN_ELSE", "$accept", "program", "global_declarations",
  "global_declaration", "typedef_declaration", "typename", "standard_type",
  "listspec", "dims", "dim", "const_declaration", "constdefs", "constdef",
  "init_value", "expression", "variable", "general_expression",
  "assignment", "expression_list", "constant", "listexpression",
  "init_values", "class_declaration", "class_body", "parent",
  "members_methods", "access", "member_or_method", "member",
  "var_declaration", "variabledefs", "variabledef", "anonymous_union",
  "union_body", "fields", "field", "method", "short_func_declaration",
  "short_par_func_header", "func_header_start", "parameter_types",
  "pass_list_dims", "nopar_func_header", "union_declaration",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "initializer", "func_declaration", "full_func_declaration",
  "full_par_func_header", "class_func_header_start", "func_class",
  "parameter_list", "pass_variabledef", "nopar_class_func_header",
  "decl_statements", "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "while_statement",
  "for_statement", "optexpr", "return_statement", "io_statement",
  "in_list", "in_item", "out_list", "out_item", "comp_statement",
  "main_function", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-209)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-152)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -209,    31,   159,  -209,    38,  -209,    17,  -209,    38,    96,
     101,  -209,   102,  -209,  -209,  -209,     2,  -209,  -209,  -209,
    -209,   126,   127,   -32,  -209,  -209,  -209,  -209,    23,   150,
     122,  -209,   146,  -209,   206,   188,   182,   191,   200,   196,
     197,   202,    26,   208,    59,  -209,   204,  -209,    97,  -209,
     336,   336,   132,   336,   336,  -209,   205,   210,  -209,    87,
    -209,    38,   216,   212,   234,   229,  -209,  -209,  -209,   231,
     445,  -209,  -209,    10,  -209,  -209,    19,   106,   125,  -209,
     242,   250,  -209,   256,   257,   258,   476,   261,   266,   259,
     262,  -209,  -209,  -209,   586,   586,    52,   586,   270,   228,
    -209,   298,   336,   193,   139,   134,  -209,  -209,  -209,   260,
     375,   143,   267,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,   264,  -209,    21,   133,   272,   276,  -209,  -209,   155,
    -209,   182,    10,  -209,   138,  -209,  -209,  -209,  -209,   227,
     231,    27,  -209,  -209,   445,  -209,   193,   152,   263,  -209,
    -209,   202,   273,  -209,  -209,  -209,  -209,  -209,    38,  -209,
      38,  -209,  -209,   586,   586,   476,   277,   287,   586,   586,
      52,   500,   296,    81,     1,  -209,   586,   291,   153,   277,
     289,   288,   586,   586,   586,   586,   586,   586,  -209,   298,
     285,   531,   586,  -209,   586,  -209,   143,   267,    22,    10,
    -209,  -209,   273,  -209,  -209,  -209,    90,   445,  -209,   141,
    -209,  -209,  -209,   295,   297,   301,    18,    49,   294,  -209,
    -209,    65,  -209,  -209,   231,    -3,    21,   160,   162,   302,
    -209,   166,   175,     1,    60,  -209,  -209,   277,    42,  -209,
     176,  -209,  -209,  -209,  -209,    81,    81,   240,   240,   296,
    -209,   307,  -209,  -209,  -209,    47,  -209,    10,   198,  -209,
    -209,  -209,    10,  -209,  -209,  -209,  -209,    49,   191,   306,
      33,  -209,  -209,  -209,  -209,  -209,  -209,   325,   324,  -209,
     445,  -209,  -209,  -209,  -209,   414,   414,   476,  -209,  -209,
    -209,    52,  -209,   500,  -209,  -209,  -209,   203,  -209,  -209,
    -209,   326,  -209,   327,    97,  -209,   353,  -209,   333,  -209,
    -209,  -209,  -209,    -3,   414,   562,  -209,   338,   414,  -209
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    14,    15,    16,     0,     0,
       0,    17,     0,    13,     3,     5,     0,    12,     6,     7,
     110,     0,     0,     0,     8,     9,    10,   111,     0,     0,
       0,     2,     0,    15,    19,     0,     0,     0,    71,    97,
       0,     0,    21,   109,     0,   106,     0,    93,     0,    94,
     132,   132,     0,   132,   132,    18,     0,     0,    21,     0,
      26,     0,     0,     0,     0,     0,   119,   118,    21,    86,
     132,   107,   104,     0,   117,   102,    19,     0,     0,   131,
       0,     0,    54,     0,     0,     0,   132,     0,     0,     0,
       0,    63,    64,    62,   132,   132,   132,   132,     0,   132,
     144,    61,   132,    59,    42,     0,    56,    46,    49,     0,
     132,     0,   127,   134,   135,   136,   137,   138,   139,   140,
     141,     0,   124,     0,     0,     0,     0,    21,   164,     0,
      24,     0,     0,    91,     0,    90,   103,    70,    68,    77,
      85,     0,    20,    30,   132,   108,    28,    42,     0,    21,
     105,    18,   101,    21,   122,    99,   121,    95,     0,   116,
       0,   142,   143,   132,   132,   132,   150,     0,   132,   132,
     132,   132,    38,    37,    40,    39,   132,     0,     0,    60,
       0,     0,   132,   132,   132,   132,   132,   132,    41,    61,
       0,   132,   132,   145,   132,   114,     0,   125,    53,     0,
     133,   112,     0,   115,   113,   163,     0,   132,    25,     0,
      84,    88,    89,     0,     0,     0,    77,     0,     0,    23,
      67,     0,    53,   123,   100,    19,     0,     0,     0,     0,
     152,     0,     0,   157,     0,   156,   161,   160,     0,   159,
       0,    48,    47,    65,   162,    31,    32,    33,    34,    35,
      36,     0,    51,    58,    57,     0,    55,     0,     0,    11,
      27,    82,     0,    74,    75,    76,    69,     0,     0,     0,
       0,    73,    78,    80,    81,    79,    92,     0,     0,    22,
     132,    29,   101,    98,   120,   132,   132,   132,    44,    45,
     153,   132,   154,   132,    52,    43,    50,     0,   130,    83,
      72,     0,    97,    21,     0,    66,   146,   148,     0,   155,
     158,   129,    87,    19,   132,   132,   147,     0,   132,   149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,  -209,  -209,    -2,   281,   349,   -53,  -209,
    -209,  -209,   253,  -141,   -62,   -56,   -79,   194,   214,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,   171,   128,  -209,  -208,
    -195,   -15,  -209,   140,  -209,   275,  -209,   405,  -209,   408,
    -209,   187,   415,  -209,  -209,  -209,   346,  -209,  -209,  -209,
    -209,  -209,   406,   369,   220,  -209,   -35,  -209,   -27,   313,
    -102,  -209,  -209,  -209,  -209,  -154,  -209,  -209,  -209,   135,
    -209,   131,  -209,  -209,  -209
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,    15,   132,    17,   153,    69,   142,
      18,    59,    60,   145,   103,   104,   105,   106,   180,   107,
     108,   221,    19,    64,    65,   216,   217,   271,   272,   133,
     209,   210,   274,    62,   134,   135,   275,   276,    21,   277,
      77,   155,   278,    24,    25,    44,    45,    71,    26,    27,
      28,    29,    40,    78,   156,    30,   109,   110,   148,   112,
     113,   114,   115,   116,   117,   167,   118,   119,   234,   235,
     238,   239,   120,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    43,    34,   220,   258,   129,    36,   166,   146,   273,
     200,   229,    55,    49,   147,   140,   121,    41,   125,   126,
     178,    50,   179,   111,   111,    41,   111,   111,   213,   214,
     215,     3,   172,   173,   151,   175,    41,   -13,   147,   147,
     174,   147,     5,    33,     7,    35,    76,   190,    41,   282,
     123,   192,    11,     5,    33,     7,   218,   268,    43,   273,
      42,   154,   297,    11,   269,    79,   260,   181,   149,   -96,
      82,   152,   266,   202,   206,   111,    51,   149,   219,   149,
     -13,    66,   146,   196,   227,   228,   166,   292,   147,   231,
     232,   303,   237,    98,   194,   200,    13,   240,   296,   293,
     224,     5,    33,     7,    72,   290,    73,    13,   154,   199,
     179,    11,   280,   255,   233,   256,   291,   186,   187,   281,
     245,   246,   247,   248,   249,   250,   147,   147,   147,   147,
     147,   147,   130,   308,   131,   259,     5,    33,     7,   305,
     141,    75,     5,    33,     7,   146,    11,     5,    33,     7,
     157,   147,    11,   158,    37,    13,   225,    11,   226,    38,
      39,   317,     4,     5,     6,     7,     8,     9,    10,   159,
      48,    47,   160,    11,    12,    53,   122,   203,   188,   193,
     160,   194,   189,   306,   307,   190,   261,   191,   262,   192,
      13,   188,   211,    52,   257,   189,    13,   242,   190,    54,
     194,   198,   192,   207,   285,   141,   286,   194,   166,   194,
     288,   154,   316,   194,   237,   270,   319,    13,   146,   289,
     294,    55,   194,   194,   147,   182,   183,   184,   185,   186,
     187,    57,     5,    33,     7,   233,   166,   213,   214,   215,
      58,    79,    11,   298,    61,   262,    82,   299,   311,    63,
     262,    66,    87,    88,   128,    67,    70,    91,    92,    93,
      68,   136,    74,   127,    94,   270,    95,    96,    97,    98,
     137,    99,   182,   183,  -152,  -152,   186,   187,   101,   138,
      79,   141,   139,    80,    81,    82,    83,   161,    84,    85,
      86,    87,    88,    89,    90,   162,    91,    92,    93,   163,
     164,   165,   313,    94,   168,    95,    96,    97,    98,   169,
      99,    79,   100,   176,   195,   170,    82,   101,   201,   171,
     102,   222,    87,    88,   194,  -132,   204,    91,    92,    93,
     205,   223,   230,   187,    94,   241,    95,    96,    97,    98,
     243,    99,   244,   252,   263,   279,   264,   287,   101,    79,
     265,   295,    80,    81,    82,    83,  -132,    84,    85,    86,
      87,    88,    89,    90,   302,    91,    92,    93,   304,    49,
     -96,   312,    94,   314,    95,    96,    97,    98,   315,    99,
     177,   100,   318,    56,   208,   254,   101,   267,    79,   102,
    -128,    80,    81,    82,    83,   300,    84,    85,    86,    87,
      88,    89,    90,   251,    91,    92,    93,    20,   301,   212,
      22,    94,   283,    95,    96,    97,    98,    23,    99,   150,
     100,   124,    46,   197,   310,   101,   309,    79,   102,  -126,
      80,    81,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,   284,     0,     0,     0,
      94,     0,    95,    96,    97,    98,     0,    99,    79,   100,
       0,     0,     0,    82,   101,     0,     0,   102,     0,    87,
      88,     0,     0,     0,    91,    92,    93,     0,     0,     0,
       0,    94,     0,    95,    96,    97,    98,   143,    99,    79,
       0,     0,     0,     0,    82,   101,     0,     0,   144,     0,
      87,    88,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,    94,    79,    95,    96,    97,    98,    82,    99,
       0,  -151,     0,     0,    87,    88,   101,     0,     0,    91,
      92,    93,     0,     0,     0,     0,    94,     0,    95,    96,
      97,    98,   236,    99,    79,     0,     0,     0,     0,    82,
     101,     0,     0,     0,     0,    87,    88,     0,     0,     0,
      91,    92,    93,     0,     0,     0,     0,    94,     0,    95,
      96,    97,    98,   253,    99,    79,     0,     0,     0,     0,
      82,   101,     0,     0,     0,     0,    87,    88,     0,     0,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    79,
      95,    96,    97,    98,    82,    99,  -151,     0,     0,     0,
      87,    88,   101,     0,     0,    91,    92,    93,     0,     0,
       0,     0,    94,     0,    95,    96,    97,    98,     0,    99,
       0,     0,     0,     0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
       2,    16,     4,   144,   199,    58,     8,    86,    70,   217,
     112,   165,    15,    45,    70,    68,    51,    15,    53,    54,
      99,    53,   101,    50,    51,    15,    53,    54,    10,    11,
      12,     0,    94,    95,    15,    97,    15,    15,    94,    95,
      96,    97,     4,     5,     6,    28,    48,    46,    15,    52,
      52,    50,    14,     4,     5,     6,    29,     8,    73,   267,
      58,    76,   257,    14,    15,    13,   207,   102,    58,    43,
      18,    52,    54,    52,   127,   102,    53,    58,    51,    58,
      58,    55,   144,   110,   163,   164,   165,    45,   144,   168,
     169,    58,   171,    41,    47,   197,    58,   176,    51,    57,
     153,     4,     5,     6,    45,    45,    47,    58,   123,   111,
     189,    14,    47,   192,   170,   194,    56,    36,    37,    54,
     182,   183,   184,   185,   186,   187,   182,   183,   184,   185,
     186,   187,    45,   287,    47,    45,     4,     5,     6,   280,
      50,    44,     4,     5,     6,   207,    14,     4,     5,     6,
      44,   207,    14,    47,    58,    58,   158,    14,   160,    58,
      58,   315,     3,     4,     5,     6,     7,     8,     9,    44,
      43,    45,    47,    14,    15,    53,    44,    44,    39,    45,
      47,    47,    43,   285,   286,    46,    45,    48,    47,    50,
      58,    39,    54,    43,   196,    43,    58,    44,    46,    53,
      47,    58,    50,    48,    44,    50,    44,    47,   287,    47,
      44,   226,   314,    47,   293,   217,   318,    58,   280,    44,
      44,    15,    47,    47,   280,    32,    33,    34,    35,    36,
      37,    43,     4,     5,     6,   291,   315,    10,    11,    12,
      58,    13,    14,    45,    53,    47,    18,   262,    45,    49,
      47,    55,    24,    25,    44,    58,    48,    29,    30,    31,
      58,    45,    58,    58,    36,   267,    38,    39,    40,    41,
      58,    43,    32,    33,    34,    35,    36,    37,    50,    45,
      13,    50,    53,    16,    17,    18,    19,    45,    21,    22,
      23,    24,    25,    26,    27,    45,    29,    30,    31,    43,
      43,    43,   304,    36,    43,    38,    39,    40,    41,    43,
      43,    13,    45,    43,    54,    56,    18,    50,    54,    57,
      53,    58,    24,    25,    47,    58,    54,    29,    30,    31,
      54,    58,    45,    37,    36,    44,    38,    39,    40,    41,
      51,    43,    54,    58,    49,    51,    49,    45,    50,    13,
      49,    44,    16,    17,    18,    19,    58,    21,    22,    23,
      24,    25,    26,    27,    58,    29,    30,    31,    43,    45,
      43,    45,    36,    20,    38,    39,    40,    41,    45,    43,
      99,    45,    44,    34,   131,   191,    50,   216,    13,    53,
      54,    16,    17,    18,    19,   267,    21,    22,    23,    24,
      25,    26,    27,   189,    29,    30,    31,     2,   268,   134,
       2,    36,   225,    38,    39,    40,    41,     2,    43,    73,
      45,    52,    16,   110,   293,    50,   291,    13,    53,    54,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,   226,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    -1,    43,    13,    45,
      -1,    -1,    -1,    18,    50,    -1,    -1,    53,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    13,
      -1,    -1,    -1,    -1,    18,    50,    -1,    -1,    53,    -1,
      24,    25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      -1,    -1,    36,    13,    38,    39,    40,    41,    18,    43,
      -1,    45,    -1,    -1,    24,    25,    50,    -1,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    13,    -1,    -1,    -1,    -1,    18,
      50,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    13,    -1,    -1,    -1,    -1,
      18,    50,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    13,
      38,    39,    40,    41,    18,    43,    44,    -1,    -1,    -1,
      24,    25,    50,    -1,    -1,    29,    30,    31,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,     4,     5,     6,     7,     8,
       9,    14,    15,    58,    63,    64,    65,    66,    70,    82,
      97,    98,    99,   102,   103,   104,   108,   109,   110,   111,
     115,   133,   134,     5,    65,    28,    65,    58,    58,    58,
     112,    15,    58,    91,   105,   106,   112,    45,    43,    45,
      53,    53,    43,    53,    53,    15,    67,    43,    58,    71,
      72,    53,    93,    49,    83,    84,    55,    58,    58,    68,
      48,   107,    45,    47,    58,    44,    65,   100,   113,    13,
      16,    17,    18,    19,    21,    22,    23,    24,    25,    26,
      27,    29,    30,    31,    36,    38,    39,    40,    41,    43,
      45,    50,    53,    74,    75,    76,    77,    79,    80,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   126,   127,
     132,   116,    44,    65,   113,   116,   116,    58,    44,    68,
      45,    47,    65,    89,    94,    95,    45,    58,    45,    53,
      68,    50,    69,    42,    53,    73,    74,    75,   118,    58,
     106,    15,    52,    67,    91,   101,   114,    44,    47,    44,
      47,    45,    45,    43,    43,    43,    76,   125,    43,    43,
      56,    57,    74,    74,    75,    74,    43,    66,    76,    76,
      78,   116,    32,    33,    34,    35,    36,    37,    39,    43,
      46,    48,    50,    45,    47,    54,   118,   119,    58,    65,
     120,    54,    52,    44,    54,    54,    68,    48,    72,    90,
      91,    54,    95,    10,    11,    12,    85,    86,    29,    51,
      73,    81,    58,    58,    68,    65,    65,    76,    76,   125,
      45,    76,    76,    75,   128,   129,    42,    76,   130,   131,
      76,    44,    44,    51,    54,    74,    74,    74,    74,    74,
      74,    78,    58,    42,    77,    76,    76,    65,    90,    45,
      73,    45,    47,    49,    49,    49,    54,    86,     8,    15,
      65,    87,    88,    89,    92,    96,    97,    99,   102,    51,
      47,    54,    52,   101,   114,    44,    44,    45,    44,    44,
      45,    56,    45,    57,    44,    44,    51,    90,    45,    91,
      87,    93,    58,    58,    43,    73,   120,   120,   125,   129,
     131,    45,    45,    65,    20,    45,   120,   125,    44,   120
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    79,    80,    81,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    91,    92,    93,    94,
      94,    95,    96,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   102,   103,   104,   105,   105,   106,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   112,
     113,   113,   114,   114,   115,   116,   116,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   121,   122,   122,   123,   124,
     125,   125,   126,   127,   127,   128,   128,   129,   130,   130,
     131,   131,   132,   133,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     3,     2,     4,     3,     1,     4,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     4,     4,     4,     1,     3,     3,     1,
       4,     3,     4,     2,     1,     3,     1,     3,     3,     1,
       1,     0,     1,     1,     1,     3,     3,     1,     4,     4,
       2,     0,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     3,     1,     3,     2,     3,     3,     2,
       1,     1,     1,     2,     2,     4,     2,     2,     4,     2,
       2,     1,     3,     4,     3,     3,     1,     2,     2,     0,
       1,     1,     4,     4,     4,     4,     4,     3,     3,     2,
       4,     2,     1,     2,     3,     2,     1,     1,     0,     5,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     5,     7,     5,     9,
       1,     0,     3,     4,     4,     3,     1,     1,     3,     1,
       1,     1,     3,     4,     4
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
#line 45 "dkk.y"
                                           {exit(0);}
#line 1504 "dkk.tab.c"
    break;

  case 10: /* global_declaration: func_declaration  */
#line 52 "dkk.y"
                           {printf("global");}
#line 1510 "dkk.tab.c"
    break;

  case 12: /* typename: standard_type  */
#line 54 "dkk.y"
                         {(yyval.ival) = (yyvsp[0].ival);}
#line 1516 "dkk.tab.c"
    break;

  case 13: /* typename: ID  */
#line 55 "dkk.y"
                     {(yyval.ival) = 4;}
#line 1522 "dkk.tab.c"
    break;

  case 14: /* standard_type: CHAR  */
#line 56 "dkk.y"
                     {printf("got char\n"); (yyval.ival) = 0;}
#line 1528 "dkk.tab.c"
    break;

  case 15: /* standard_type: INT  */
#line 57 "dkk.y"
                      {printf("got int\n"); (yyval.ival) = 1;}
#line 1534 "dkk.tab.c"
    break;

  case 16: /* standard_type: FLOAT  */
#line 58 "dkk.y"
                        {printf("got float\n"); (yyval.ival) = 2;}
#line 1540 "dkk.tab.c"
    break;

  case 17: /* standard_type: VOID  */
#line 59 "dkk.y"
                       {printf("got void\n"); (yyval.ival) = 3;}
#line 1546 "dkk.tab.c"
    break;

  case 31: /* expression: expression OROP expression  */
#line 69 "dkk.y"
                                        { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
					}
#line 1559 "dkk.tab.c"
    break;

  case 32: /* expression: expression ANDOP expression  */
#line 77 "dkk.y"
                                      { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
				      }
#line 1572 "dkk.tab.c"
    break;

  case 33: /* expression: expression EQUOP expression  */
#line 85 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type equop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1583 "dkk.tab.c"
    break;

  case 34: /* expression: expression RELOP expression  */
#line 91 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type relop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1594 "dkk.tab.c"
    break;

  case 35: /* expression: expression ADDOP expression  */
#line 97 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if (((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT)) {
						(yyval.myexpr).type = T_FLOAT;
					}
					// list check
					else printf("semantic error\n");	
				      }
#line 1607 "dkk.tab.c"
    break;

  case 36: /* expression: expression MULOP expression  */
#line 105 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if ((((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT))/* && ($2.type != T_MULOP_MOD)*/) {
						(yyval.myexpr).type = T_FLOAT;
					}
					//list
					else printf("semantic error\n");	
				      }
#line 1620 "dkk.tab.c"
    break;

  case 37: /* expression: NOTOP expression  */
#line 113 "dkk.y"
                           { if ((yyvsp[0].myexpr).type != T_INT) { 
	                     	printf("not correct type. semantics error\n");
	                     }
	                     else {
	                   	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
	                   	printf("correct type\n");
	                     }
	                   }
#line 1633 "dkk.tab.c"
    break;

  case 38: /* expression: ADDOP expression  */
#line 122 "dkk.y"
                           { if (((yyvsp[0].myexpr).type != T_INT) || ((yyvsp[0].myexpr).type != T_FLOAT)) {
		             	printf("semantic error\n");
			     }
			     else {
			     	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
	                   	printf("correct type\n");
			     }
			   }
#line 1646 "dkk.tab.c"
    break;

  case 39: /* expression: SIZEOP expression  */
#line 130 "dkk.y"
                            {(yyval.myexpr).type = T_INT;}
#line 1652 "dkk.tab.c"
    break;

  case 42: /* expression: variable  */
#line 133 "dkk.y"
                   { switch((yyvsp[0].ival)){
			case 0:{ (yyval.myexpr).type = T_CHAR; break;}
			case 1:{ (yyval.myexpr).type = T_INT; break;}
			case 2:{ (yyval.myexpr).type = T_FLOAT; break;}
			case 3:{ (yyval.myexpr).type = T_VOID; break;}
			case 4:{ (yyval.myexpr).type = T_ID; break;}
			default: {printf("semantic error");}
			}
			}
#line 1666 "dkk.tab.c"
    break;

  case 46: /* expression: constant  */
#line 145 "dkk.y"
                   {(yyval.myexpr).type = (yyvsp[0].type);}
#line 1672 "dkk.tab.c"
    break;

  case 53: /* variable: decltype ID  */
#line 152 "dkk.y"
                      { int p;
			p = hashtbl_lookup(symtb, scope, yylval.str);
			if(p == -1)
				printf("semantics error\n");
			else
				(yyval.ival) = p;}
#line 1683 "dkk.tab.c"
    break;

  case 62: /* constant: CCONST  */
#line 165 "dkk.y"
                  {(yyval.type) = T_CHAR;}
#line 1689 "dkk.tab.c"
    break;

  case 63: /* constant: ICONST  */
#line 166 "dkk.y"
                 {(yyval.type) = T_INT;}
#line 1695 "dkk.tab.c"
    break;

  case 64: /* constant: FCONST  */
#line 167 "dkk.y"
                 {(yyval.type) = T_FLOAT;}
#line 1701 "dkk.tab.c"
    break;

  case 82: /* var_declaration: typename variabledefs SEMI  */
#line 179 "dkk.y"
                                             {
	  id_list_t *curr = (yyvsp[-1].idlist), *prv = (yyvsp[-1].idlist);
          char t[8];

          switch ((yyvsp[-2].ival)) {
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
#line 1731 "dkk.tab.c"
    break;

  case 83: /* variabledefs: variabledefs COMMA variabledef  */
#line 204 "dkk.y"
                                              {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].str);
          n->next = (yyvsp[-2].idlist);
          (yyval.idlist) = n;
      }
#line 1742 "dkk.tab.c"
    break;

  case 84: /* variabledefs: variabledef  */
#line 210 "dkk.y"
                      {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].str);
          n->next = NULL;
          (yyval.idlist) = n;
      }
#line 1753 "dkk.tab.c"
    break;

  case 86: /* variabledef: ID dims  */
#line 217 "dkk.y"
                  {(yyval.str) = yylval.str; printf("variabledef\n");}
#line 1759 "dkk.tab.c"
    break;

  case 104: /* global_var_declaration: typename init_variabledefs SEMI  */
#line 230 "dkk.y"
                                                         {
	  id_list_t *curr = (yyvsp[-1].idlist), *prv = (yyvsp[-1].idlist);
          char t[8];

          switch ((yyvsp[-2].ival)) {
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
#line 1789 "dkk.tab.c"
    break;

  case 105: /* init_variabledefs: init_variabledefs COMMA init_variabledef  */
#line 255 "dkk.y"
                                                              {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = (yyvsp[0].str);
         		 n->next = (yyvsp[-2].idlist);
         		 (yyval.idlist) = n;
      			}
#line 1800 "dkk.tab.c"
    break;

  case 106: /* init_variabledefs: init_variabledef  */
#line 261 "dkk.y"
                                  {
        		  id_list_t* n = malloc(sizeof(id_list_t));
        		  n->id = (yyvsp[0].str);
        		  n->next = NULL;
        		  (yyval.idlist) = n;
      			}
#line 1811 "dkk.tab.c"
    break;

  case 107: /* init_variabledef: variabledef initializer  */
#line 268 "dkk.y"
                                           {(yyval.str) = (yyvsp[-1].str); printf("init_variabledef\n");}
#line 1817 "dkk.tab.c"
    break;

  case 111: /* func_declaration: full_func_declaration  */
#line 270 "dkk.y"
                                                                  {printf("sevo");}
#line 1823 "dkk.tab.c"
    break;

  case 129: /* declarations: declarations decltype typename variabledefs SEMI  */
#line 286 "dkk.y"
                                                                {
	  id_list_t *curr = (yyvsp[-1].idlist), *prv = (yyvsp[-1].idlist);
          char t[8];

          switch ((yyvsp[-2].ival)) {
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
#line 1853 "dkk.tab.c"
    break;

  case 130: /* declarations: decltype typename variabledefs SEMI  */
#line 311 "dkk.y"
                                                     {
	  id_list_t *curr = (yyvsp[-1].idlist), *prv = (yyvsp[-1].idlist);
          char t[8];

          switch ((yyvsp[-2].ival)) {
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
#line 1883 "dkk.tab.c"
    break;


#line 1887 "dkk.tab.c"

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

#line 362 "dkk.y"

#include "hashtbl.h"
void yyerror (char const *s) {
	printf("error: %s\n", s);
}
int main(){
	symtb = hashtbl_create(10, NULL);
	return yyparse();
	hashtbl_destroy(symtb);
}
