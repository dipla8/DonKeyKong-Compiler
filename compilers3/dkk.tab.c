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
int dim_count = 0;
HASHTBL *symtb;

#line 88 "dkk.tab.c"

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
  YYSYMBOL_class_body = 83,                /* class_body  */
  YYSYMBOL_parent = 84,                    /* parent  */
  YYSYMBOL_members_methods = 85,           /* members_methods  */
  YYSYMBOL_access = 86,                    /* access  */
  YYSYMBOL_member_or_method = 87,          /* member_or_method  */
  YYSYMBOL_member = 88,                    /* member  */
  YYSYMBOL_var_declaration = 89,           /* var_declaration  */
  YYSYMBOL_variabledefs = 90,              /* variabledefs  */
  YYSYMBOL_variabledef = 91,               /* variabledef  */
  YYSYMBOL_92_2 = 92,                      /* $@2  */
  YYSYMBOL_93_3 = 93,                      /* $@3  */
  YYSYMBOL_anonymous_union = 94,           /* anonymous_union  */
  YYSYMBOL_union_body = 95,                /* union_body  */
  YYSYMBOL_fields = 96,                    /* fields  */
  YYSYMBOL_field = 97,                     /* field  */
  YYSYMBOL_method = 98,                    /* method  */
  YYSYMBOL_short_func_declaration = 99,    /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 100,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 101,        /* func_header_start  */
  YYSYMBOL_parameter_types = 102,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 103,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 104,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 105,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 106,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 107,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 108,         /* init_variabledef  */
  YYSYMBOL_initializer = 109,              /* initializer  */
  YYSYMBOL_func_declaration = 110,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 111,    /* full_func_declaration  */
  YYSYMBOL_112_4 = 112,                    /* $@4  */
  YYSYMBOL_113_5 = 113,                    /* $@5  */
  YYSYMBOL_114_6 = 114,                    /* $@6  */
  YYSYMBOL_full_par_func_header = 115,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 116,  /* class_func_header_start  */
  YYSYMBOL_func_class = 117,               /* func_class  */
  YYSYMBOL_parameter_list = 118,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 119,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 120,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 121,          /* decl_statements  */
  YYSYMBOL_declarations = 122,             /* declarations  */
  YYSYMBOL_decltype = 123,                 /* decltype  */
  YYSYMBOL_statements = 124,               /* statements  */
  YYSYMBOL_statement = 125,                /* statement  */
  YYSYMBOL_expression_statement = 126,     /* expression_statement  */
  YYSYMBOL_if_statement = 127,             /* if_statement  */
  YYSYMBOL_while_statement = 128,          /* while_statement  */
  YYSYMBOL_for_statement = 129,            /* for_statement  */
  YYSYMBOL_optexpr = 130,                  /* optexpr  */
  YYSYMBOL_return_statement = 131,         /* return_statement  */
  YYSYMBOL_io_statement = 132,             /* io_statement  */
  YYSYMBOL_in_list = 133,                  /* in_list  */
  YYSYMBOL_in_item = 134,                  /* in_item  */
  YYSYMBOL_out_list = 135,                 /* out_list  */
  YYSYMBOL_out_item = 136,                 /* out_item  */
  YYSYMBOL_comp_statement = 137,           /* comp_statement  */
  YYSYMBOL_138_7 = 138,                    /* $@7  */
  YYSYMBOL_139_8 = 139,                    /* $@8  */
  YYSYMBOL_main_function = 140,            /* main_function  */
  YYSYMBOL_141_9 = 141,                    /* $@9  */
  YYSYMBOL_main_header = 142               /* main_header  */
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
#define YYLAST   656

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

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
      64,    65,    65,    68,    69,    70,    71,    72,    73,    74,
      74,    75,   103,   122,   124,   125,   125,   126,   127,   128,
     129,   130,   138,   146,   152,   158,   166,   174,   183,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   222,   223,   224,   242,   243,   244,   245,   246,   247,
     248,   248,   249,   250,   251,   252,   253,   253,   254,   255,
     256,   256,   257,   257,   258,   258,   258,   258,   259,   260,
     261,   262,   263,   264,   270,   276,   276,   277,   277,   282,
     283,   284,   284,   285,   286,   287,   287,   288,   289,   294,
     295,   295,   296,   296,   297,   298,   299,   300,   306,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   318,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   326,   327,
     328,   329,   330,   330,   331,   332,   333,   333,   334,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   350,   351,   352,   352,
     353,   353,   354,   355,   355,   356,   356,   357,   357,   357,
     358,   358,   359
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
  "class_declaration", "class_body", "parent", "members_methods", "access",
  "member_or_method", "member", "var_declaration", "variabledefs",
  "variabledef", "$@2", "$@3", "anonymous_union", "union_body", "fields",
  "field", "method", "short_func_declaration", "short_par_func_header",
  "func_header_start", "parameter_types", "pass_list_dims",
  "nopar_func_header", "union_declaration", "global_var_declaration",
  "init_variabledefs", "init_variabledef", "initializer",
  "func_declaration", "full_func_declaration", "$@4", "$@5", "$@6",
  "full_par_func_header", "class_func_header_start", "func_class",
  "parameter_list", "pass_variabledef", "nopar_class_func_header",
  "decl_statements", "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "while_statement",
  "for_statement", "optexpr", "return_statement", "io_statement",
  "in_list", "in_item", "out_list", "out_item", "comp_statement", "$@7",
  "$@8", "main_function", "$@9", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-157)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -212,    35,    22,  -212,   157,  -212,    39,  -212,   157,    52,
      57,  -212,    63,  -212,  -212,  -212,   -14,  -212,  -212,  -212,
    -212,    31,    87,   132,  -212,  -212,  -212,  -212,  -212,   113,
    -212,  -212,  -212,  -212,   175,   159,   148,   161,   166,   178,
     173,   181,     0,   191,    96,  -212,   186,  -212,    38,  -212,
     201,   208,   109,   209,   217,  -212,   224,   234,  -212,   140,
    -212,   157,   239,   241,   255,   251,  -212,  -212,  -212,  -212,
     443,  -212,  -212,     7,  -212,  -212,    25,    48,    56,   326,
     326,  -212,    41,   128,   326,   326,  -212,  -212,   202,  -212,
     148,     7,  -212,   115,  -212,  -212,  -212,  -212,   215,  -212,
     253,  -212,  -212,   269,   270,  -212,  -212,   598,    92,   598,
     271,  -212,   205,   279,   443,   598,  -212,  -212,   171,   282,
    -212,  -212,   254,  -212,  -212,   181,   262,  -212,  -212,  -212,
    -212,  -212,   157,  -212,   157,   281,   285,   273,   284,   288,
     474,   268,   276,  -212,  -212,   171,   145,   206,  -212,   280,
     369,   174,   248,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,   283,   262,  -212,   289,   294,  -212,   443,   111,  -212,
     236,  -212,  -212,  -212,   286,   287,   293,   114,    81,   253,
     598,   598,   107,   -33,  -212,   598,   312,   142,   313,   308,
    -212,   120,   324,   598,   598,   598,   598,   598,   598,  -212,
     279,   301,   598,  -212,  -212,   253,    18,    41,  -212,  -212,
     598,   598,   474,   313,   318,    92,   505,   326,   536,  -212,
     598,  -212,   174,   248,    23,     7,  -212,  -212,  -212,  -212,
      -9,  -212,  -212,   317,  -212,     7,  -212,  -212,  -212,  -212,
      81,   161,   309,    47,  -212,  -212,  -212,  -212,  -212,  -212,
     329,   132,   150,   154,   172,  -212,  -212,  -212,   443,  -212,
     107,   107,   223,   223,  -212,   324,   330,  -212,   108,  -212,
    -212,  -212,   179,   194,   328,  -212,   -33,    45,  -212,  -212,
     313,    15,  -212,  -212,  -212,  -212,  -212,     7,   245,  -212,
    -212,  -212,  -212,   332,  -212,   335,    38,  -212,  -212,  -212,
    -212,  -212,  -212,   412,   412,   474,  -212,    92,  -212,   505,
     321,   250,  -212,  -212,    18,   359,  -212,   337,  -212,  -212,
    -212,  -212,   412,   567,  -212,   339,   412,  -212
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    15,    16,    17,     0,     0,
       0,    18,     0,    14,     3,     5,     0,    13,     6,     7,
     112,     0,     0,   118,     8,     9,    10,   113,   114,     0,
     116,     2,   170,    16,    20,     0,     0,     0,    71,    99,
       0,     0,    87,   111,     0,   108,     0,    95,     0,    96,
       0,     0,     0,     0,     0,    19,     0,     0,    23,     0,
      26,     0,     0,     0,     0,     0,   124,   123,    85,    23,
     137,   109,   106,     0,   122,   104,    20,     0,     0,   137,
     137,   129,     0,     0,   137,   137,    11,   172,     0,    24,
       0,     0,    93,     0,    92,   105,    70,    68,    77,    23,
      88,   136,    54,     0,     0,    64,    62,   137,   137,   137,
       0,    30,   137,    61,   137,   137,    63,   110,    28,    42,
      46,    49,     0,    87,   107,    19,   103,    23,   127,   101,
     126,    97,     0,   121,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   149,   167,    59,    42,     0,    56,     0,
     137,     0,   132,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   120,     0,     0,    23,   137,     0,    25,
       0,    84,    90,    91,     0,     0,     0,    77,     0,    86,
     137,   137,    37,    40,    39,   137,     0,     0,    60,     0,
      67,     0,    38,   137,   137,   137,   137,   137,   137,    41,
      61,     0,   137,    53,   128,   102,    20,     0,   147,   148,
     137,   137,   137,   155,     0,   137,   137,   137,   137,   150,
     137,   119,     0,   130,    53,     0,   138,   115,   117,   171,
       0,    27,    22,     0,    82,     0,    74,    75,    76,    69,
       0,     0,     0,     0,    73,    78,    80,    81,    79,    94,
       0,     0,     0,     0,     0,    48,    47,    65,   137,    29,
      31,    32,    33,    34,    36,    35,     0,    51,     0,   103,
     100,   125,     0,     0,     0,   157,   162,     0,   161,   166,
     165,     0,   164,   168,    58,    57,    55,     0,     0,    12,
      21,    83,    72,     0,    99,    87,     0,    44,    45,    52,
      66,    43,    50,   137,   137,   137,   158,   137,   159,   137,
       0,     0,   135,    89,    20,   151,   153,     0,   160,   163,
     169,   134,   137,   137,   152,     0,   137,   154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,  -212,  -212,    -2,   277,   363,   -48,
    -212,  -212,   310,  -106,   -50,   -60,  -108,   183,   203,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   225,   164,  -212,  -169,
    -211,   -13,  -212,  -212,  -212,   168,  -212,   320,  -212,   409,
    -212,   413,  -212,   210,   416,  -212,  -212,  -212,   341,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,   403,   370,   216,
    -212,   -61,  -212,   -67,   274,  -145,  -212,  -212,  -212,  -212,
    -196,  -212,  -212,  -212,   125,  -212,   131,  -212,  -212,  -212,
    -212,  -212,  -212
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,    15,   166,    91,    17,   127,    88,
      18,    59,    60,   117,   145,   146,   147,   148,   189,   120,
     121,   191,    19,    64,    65,   177,   178,   244,   245,    92,
     170,   171,    99,    69,   247,    62,    93,    94,   248,   249,
      21,   250,    77,   129,   251,    24,    25,    44,    45,    71,
      26,    27,    51,    53,    50,    28,    29,    40,    78,   130,
      30,   149,   150,   122,   152,   153,   154,   155,   156,   157,
     214,   158,   159,   277,   278,   281,   282,   160,   217,   310,
      31,    54,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    41,    34,    43,   187,   188,    36,   226,   190,   246,
     119,   201,   151,   151,   288,   202,   274,   151,   151,   161,
     118,   100,    41,   164,   165,     4,     5,     6,     7,     8,
       9,    10,   213,    55,   289,     3,    11,    12,   -14,   168,
     125,   -98,     5,    33,     7,    42,    76,   119,   183,   119,
      82,   179,    11,    66,   119,   119,    41,   182,   308,   184,
      43,   231,    41,   128,   118,   192,   123,    35,   269,   128,
     309,   246,   252,   253,    47,   126,   311,   254,   226,   205,
      75,    13,   -14,   222,   123,     5,    33,     7,   306,   241,
     131,   162,   188,   132,   268,    11,   242,    13,   133,   307,
     123,   134,   272,   273,   213,   101,   295,   119,   280,   317,
     102,    37,   286,     5,    33,     7,    38,   118,   230,     5,
      33,     7,    39,    11,   174,   175,   176,   325,    48,    11,
     206,   110,   207,   119,   119,   119,   119,   119,   119,    72,
      13,    73,   197,   260,   261,   262,   263,   264,   265,   225,
     151,    81,   300,   220,    52,   276,   283,   302,   315,   316,
     232,     5,    33,     7,   198,   258,   239,   172,    13,   233,
     163,    11,   259,   134,    13,    49,   243,   324,     5,    33,
       7,   327,   199,    89,   256,    90,   200,   220,    11,   201,
      55,   218,   297,   202,   128,   220,   298,   213,   119,   220,
      57,   280,   193,   194,   195,   196,   197,    58,   118,     5,
      33,     7,    61,    63,   299,   213,    13,   220,   101,    11,
     287,   303,   291,   102,   220,   174,   175,   176,   198,   103,
     104,    66,    67,   224,   105,   106,   304,    70,   243,   220,
      68,   107,   108,   109,   110,    74,   112,   276,   167,   219,
     168,   220,    79,   113,   193,   194,  -157,  -157,   197,    80,
      84,   101,   115,   116,   135,   136,   102,   137,    85,   138,
     139,   140,   103,   104,   141,   142,    87,   105,   106,   234,
     198,   235,    95,    86,   107,   108,   109,   110,   312,   112,
     235,   143,   101,   321,   314,   235,   113,   102,    97,   144,
      96,   168,    98,   103,   104,   115,   116,  -137,   105,   106,
     180,   181,   185,   203,   210,   107,   108,   109,   110,   199,
     112,   204,   215,   200,   208,   211,   201,   113,   209,   212,
     202,   216,   221,   236,   237,   227,   115,   116,  -137,   101,
     238,   228,   135,   136,   102,   137,   229,   138,   139,   140,
     103,   104,   141,   142,   255,   105,   106,   257,   220,   197,
     267,   275,   107,   108,   109,   110,   290,   112,   294,   143,
     296,   305,   301,   320,   113,   313,   -98,   144,  -133,   322,
     323,   326,   101,   115,   116,   135,   136,   102,   137,   186,
     138,   139,   140,   103,   104,   141,   142,    56,   105,   106,
     169,   285,   240,   266,   292,   107,   108,   109,   110,   293,
     112,    20,   143,   173,   124,    22,   270,   113,    23,    46,
     144,  -131,    83,   271,   223,   101,   115,   116,   135,   136,
     102,   137,   318,   138,   139,   140,   103,   104,   141,   142,
     319,   105,   106,     0,     0,     0,     0,     0,   107,   108,
     109,   110,     0,   112,     0,   143,   101,     0,     0,     0,
     113,   102,     0,   144,     0,     0,     0,   103,   104,   115,
     116,     0,   105,   106,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,   101,     0,     0,
       0,   113,   102,     0,   114,     0,     0,     0,   103,   104,
     115,   116,     0,   105,   106,     0,     0,     0,     0,     0,
     107,   108,   109,   110,     0,   112,     0,  -156,   101,     0,
       0,     0,   113,   102,     0,     0,     0,     0,     0,   103,
     104,   115,   116,     0,   105,   106,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   279,   112,     0,     0,   101,
       0,     0,     0,   113,   102,     0,     0,     0,     0,     0,
     103,   104,   115,   116,     0,   105,   106,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   284,   112,     0,     0,
     101,     0,     0,     0,   113,   102,     0,     0,     0,     0,
       0,   103,   104,   115,   116,     0,   105,   106,     0,     0,
       0,     0,     0,   107,   108,   109,   110,     0,   112,  -156,
       0,   101,     0,     0,     0,   113,   102,     0,     0,     0,
       0,     0,   103,   104,   115,   116,     0,   105,   106,     0,
       0,     0,     0,     0,   107,   108,   109,   110,     0,   112,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116
};

static const yytype_int16 yycheck[] =
{
       2,    15,     4,    16,   112,   113,     8,   152,   114,   178,
      70,    44,    79,    80,   225,    48,   212,    84,    85,    80,
      70,    69,    15,    84,    85,     3,     4,     5,     6,     7,
       8,     9,   140,    15,    43,     0,    14,    15,    15,    48,
      15,    41,     4,     5,     6,    59,    48,   107,   108,   109,
      52,    99,    14,    53,   114,   115,    15,   107,    43,   109,
      73,   167,    15,    76,   114,   115,    59,    28,    50,    82,
      55,   240,   180,   181,    43,    50,   287,   185,   223,   127,
      42,    59,    59,   150,    59,     4,     5,     6,    43,     8,
      42,    50,   200,    45,   202,    14,    15,    59,    42,    54,
      59,    45,   210,   211,   212,    13,    59,   167,   216,   305,
      18,    59,   220,     4,     5,     6,    59,   167,   166,     4,
       5,     6,    59,    14,    10,    11,    12,   323,    41,    14,
     132,    39,   134,   193,   194,   195,   196,   197,   198,    43,
      59,    45,    35,   193,   194,   195,   196,   197,   198,   151,
     217,    42,   258,    45,    41,   215,   217,    49,   303,   304,
      49,     4,     5,     6,    57,    45,    52,    52,    59,    58,
      42,    14,    52,    45,    59,    43,   178,   322,     4,     5,
       6,   326,    37,    43,    42,    45,    41,    45,    14,    44,
      15,    46,    42,    48,   207,    45,    42,   305,   258,    45,
      41,   309,    31,    32,    33,    34,    35,    59,   258,     4,
       5,     6,    51,    47,    42,   323,    59,    45,    13,    14,
     222,    42,   235,    18,    45,    10,    11,    12,    57,    24,
      25,    53,    59,    59,    29,    30,    42,    46,   240,    45,
      59,    36,    37,    38,    39,    59,    41,   307,    46,    43,
      48,    45,    51,    48,    31,    32,    33,    34,    35,    51,
      51,    13,    57,    58,    16,    17,    18,    19,    51,    21,
      22,    23,    24,    25,    26,    27,    42,    29,    30,    43,
      57,    45,    43,    59,    36,    37,    38,    39,    43,    41,
      45,    43,    13,    43,   296,    45,    48,    18,    43,    51,
      59,    48,    51,    24,    25,    57,    58,    59,    29,    30,
      41,    41,    41,    59,    41,    36,    37,    38,    39,    37,
      41,    59,    54,    41,    43,    41,    44,    48,    43,    41,
      48,    55,    52,    47,    47,    52,    57,    58,    59,    13,
      47,    52,    16,    17,    18,    19,    52,    21,    22,    23,
      24,    25,    26,    27,    42,    29,    30,    49,    45,    35,
      59,    43,    36,    37,    38,    39,    49,    41,    59,    43,
      41,    43,    42,    52,    48,    43,    41,    51,    52,    20,
      43,    42,    13,    57,    58,    16,    17,    18,    19,   112,
      21,    22,    23,    24,    25,    26,    27,    34,    29,    30,
      90,   218,   177,   200,   240,    36,    37,    38,    39,   241,
      41,     2,    43,    93,    73,     2,   206,    48,     2,    16,
      51,    52,    52,   207,   150,    13,    57,    58,    16,    17,
      18,    19,   307,    21,    22,    23,    24,    25,    26,    27,
     309,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    41,    -1,    43,    13,    -1,    -1,    -1,
      48,    18,    -1,    51,    -1,    -1,    -1,    24,    25,    57,
      58,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    -1,    -1,    13,    -1,    -1,
      -1,    48,    18,    -1,    51,    -1,    -1,    -1,    24,    25,
      57,    58,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    43,    13,    -1,
      -1,    -1,    48,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    57,    58,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    13,
      -1,    -1,    -1,    48,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    57,    58,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      13,    -1,    -1,    -1,    48,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    57,    58,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    -1,    41,    42,
      -1,    13,    -1,    -1,    -1,    48,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    57,    58,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,     4,     5,     6,     7,     8,
       9,    14,    15,    59,    63,    64,    66,    67,    70,    82,
      99,   100,   101,   104,   105,   106,   110,   111,   115,   116,
     120,   140,   142,     5,    66,    28,    66,    59,    59,    59,
     117,    15,    59,    91,   107,   108,   117,    43,    41,    43,
     114,   112,    41,   113,   141,    15,    68,    41,    59,    71,
      72,    51,    95,    47,    83,    84,    53,    59,    59,    93,
      46,   109,    43,    45,    59,    42,    66,   102,   118,    51,
      51,    42,    66,   118,    51,    51,    59,    42,    69,    43,
      45,    66,    89,    96,    97,    43,    59,    43,    51,    92,
      69,    13,    18,    24,    25,    29,    30,    36,    37,    38,
      39,    40,    41,    48,    51,    57,    58,    73,    74,    75,
      79,    80,   123,    59,   108,    15,    50,    68,    91,   103,
     119,    42,    45,    42,    45,    16,    17,    19,    21,    22,
      23,    26,    27,    43,    51,    74,    75,    76,    77,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   131,   132,
     137,   121,    50,    42,   121,   121,    65,    46,    48,    72,
      90,    91,    52,    97,    10,    11,    12,    85,    86,    69,
      41,    41,    74,    75,    74,    41,    67,    76,    76,    78,
      73,    81,    74,    31,    32,    33,    34,    35,    57,    37,
      41,    44,    48,    59,    59,    69,    66,    66,    43,    43,
      41,    41,    41,    76,   130,    54,    55,   138,    46,    43,
      45,    52,   123,   124,    59,    66,   125,    52,    52,    52,
      69,    73,    49,    58,    43,    45,    47,    47,    47,    52,
      86,     8,    15,    66,    87,    88,    89,    94,    98,    99,
     101,   104,    76,    76,    76,    42,    42,    49,    45,    52,
      74,    74,    74,    74,    74,    74,    78,    59,    76,    50,
     103,   119,    76,    76,   130,    43,    75,   133,   134,    40,
      76,   135,   136,   121,    40,    77,    76,    66,    90,    43,
      49,    91,    87,    95,    59,    59,    41,    42,    42,    42,
      73,    42,    49,    42,    42,    43,    43,    54,    43,    55,
     139,    90,    43,    43,    66,   125,   125,   130,   134,   136,
      52,    43,    20,    43,   125,   130,    42,   125
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
      78,    78,    79,    79,    79,    80,    81,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    90,    90,    92,    91,    93,    91,    94,
      95,    96,    96,    97,    98,    99,    99,   100,   101,   101,
     102,   102,   103,   103,   104,   105,   106,   107,   107,   108,
     109,   109,   110,   110,   112,   111,   113,   111,   114,   111,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   120,
     121,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   127,   127,   128,   129,   130,   130,   131,   132,   132,
     133,   133,   134,   135,   135,   136,   136,   138,   139,   137,
     141,   140,   142
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
       1,     0,     1,     1,     1,     3,     3,     1,     4,     4,
       2,     0,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     3,     1,     0,     4,     0,     3,     3,
       3,     2,     1,     1,     1,     2,     2,     4,     2,     2,
       4,     2,     2,     1,     3,     4,     3,     3,     1,     2,
       2,     0,     1,     1,     0,     5,     0,     5,     0,     5,
       4,     4,     3,     3,     2,     4,     2,     1,     2,     3,
       2,     1,     1,     0,     5,     4,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     5,     7,     5,     9,     1,     0,     3,     4,     4,
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
#line 57 "dkk.y"
                                           {exit(0);}
#line 1528 "dkk.tab.c"
    break;

  case 10: /* global_declaration: func_declaration  */
#line 64 "dkk.y"
                           {printf("global");}
#line 1534 "dkk.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 65 "dkk.y"
                                                   {
	dim_count = 0;
}
#line 1542 "dkk.tab.c"
    break;

  case 12: /* typedef_declaration: TYPEDEF typename listspec ID $@1 dims SEMI  */
#line 67 "dkk.y"
            {/*must add routine*/}
#line 1548 "dkk.tab.c"
    break;

  case 13: /* typename: standard_type  */
#line 68 "dkk.y"
                         {(yyval.ival) = (yyvsp[0].ival);}
#line 1554 "dkk.tab.c"
    break;

  case 14: /* typename: ID  */
#line 69 "dkk.y"
                     {(yyval.ival) = T_ID;}
#line 1560 "dkk.tab.c"
    break;

  case 15: /* standard_type: CHAR  */
#line 70 "dkk.y"
                     {printf("got char\n"); (yyval.ival) = T_CHAR;}
#line 1566 "dkk.tab.c"
    break;

  case 16: /* standard_type: INT  */
#line 71 "dkk.y"
                      {printf("got int\n"); (yyval.ival) = T_INT;}
#line 1572 "dkk.tab.c"
    break;

  case 17: /* standard_type: FLOAT  */
#line 72 "dkk.y"
                        {printf("got float\n"); (yyval.ival) = T_FLOAT;}
#line 1578 "dkk.tab.c"
    break;

  case 18: /* standard_type: VOID  */
#line 73 "dkk.y"
                       {printf("got void\n"); (yyval.ival) = T_VOID;}
#line 1584 "dkk.tab.c"
    break;

  case 21: /* dims: dims LBRACK ICONST RBRACK  */
#line 75 "dkk.y"
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
#line 1617 "dkk.tab.c"
    break;

  case 22: /* dims: dims LBRACK RBRACK  */
#line 103 "dkk.y"
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
#line 1641 "dkk.tab.c"
    break;

  case 23: /* dims: %empty  */
#line 122 "dkk.y"
      {(yyval.arr) = NULL;}
#line 1647 "dkk.tab.c"
    break;

  case 31: /* expression: expression OROP expression  */
#line 130 "dkk.y"
                                        { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
					}
#line 1660 "dkk.tab.c"
    break;

  case 32: /* expression: expression ANDOP expression  */
#line 138 "dkk.y"
                                      { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT)) {
   					  	printf("correct type\n");
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  }
					  else {
					  	printf("semantics error\n");
					  }
				      }
#line 1673 "dkk.tab.c"
    break;

  case 33: /* expression: expression EQUOP expression  */
#line 146 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type equop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1684 "dkk.tab.c"
    break;

  case 34: /* expression: expression RELOP expression  */
#line 152 "dkk.y"
                                      {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR)){
						printf("correct type relop\n");
						(yyval.myexpr).type = T_INT;
					}
					else printf("semantic error\n");
				      }
#line 1695 "dkk.tab.c"
    break;

  case 35: /* expression: expression ADDOP expression  */
#line 158 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if (((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT)) {
						(yyval.myexpr).type = T_FLOAT;
					}
					// list check
					else printf("semantic error\n");	
				      }
#line 1708 "dkk.tab.c"
    break;

  case 36: /* expression: expression MULOP expression  */
#line 166 "dkk.y"
                                      {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if ((((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT))/* && ($2.type != T_MULOP_MOD)*/) {
						(yyval.myexpr).type = T_FLOAT;
					}
					//list
					else printf("semantic error\n");	
				      }
#line 1721 "dkk.tab.c"
    break;

  case 37: /* expression: NOTOP expression  */
#line 174 "dkk.y"
                           { if ((yyvsp[0].myexpr).type != T_INT) { 
	                     	printf("not correct type. semantics error\n");
	                     }
	                     else {
	                   	(yyval.myexpr).type = (yyvsp[0].myexpr).type;
	                   	printf("correct type\n");
	                     }
	                   }
#line 1734 "dkk.tab.c"
    break;

  case 38: /* expression: ADDOP expression  */
#line 183 "dkk.y"
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
#line 1753 "dkk.tab.c"
    break;

  case 39: /* expression: SIZEOP expression  */
#line 197 "dkk.y"
                            {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = 0;}
#line 1759 "dkk.tab.c"
    break;

  case 40: /* expression: INCDEC variable  */
#line 198 "dkk.y"
                          {var_to_expr(&(yyval.myexpr), (yyvsp[0].myvar).ival);}
#line 1765 "dkk.tab.c"
    break;

  case 41: /* expression: variable INCDEC  */
#line 199 "dkk.y"
                          {var_to_expr(&(yyval.myexpr), (yyvsp[-1].myvar).ival);}
#line 1771 "dkk.tab.c"
    break;

  case 42: /* expression: variable  */
#line 200 "dkk.y"
                   {var_to_expr(&(yyval.myexpr), (yyvsp[0].myvar).ival); printf("%d\n", (yyval.myexpr).type); printf("%d\n", (yyval.myexpr).val.ival);}
#line 1777 "dkk.tab.c"
    break;

  case 43: /* expression: variable LPAREN expression_list RPAREN  */
#line 201 "dkk.y"
                                                 {var_to_expr(&(yyval.myexpr), (yyvsp[-3].myvar).ival);}
#line 1783 "dkk.tab.c"
    break;

  case 46: /* expression: constant  */
#line 204 "dkk.y"
                   {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val;}
#line 1789 "dkk.tab.c"
    break;

  case 50: /* variable: variable LBRACK general_expression RBRACK  */
#line 208 "dkk.y"
                                                     {
							if((yyvsp[-1].myexpr).type != T_INT)
								printf("semantic error here\n");
							else{
							     if((yyvsp[-3].myvar).rec_count > (yyvsp[-3].myvar).n->arr->dims)
								printf("semantic error there\n");
						 	     else if((yyvsp[-1].myexpr).val.ival <0 || (yyvsp[-1].myexpr).val.ival >= (yyvsp[-3].myvar).n->arr->dim_size[(yyvsp[-3].myvar).rec_count]){
							    //if($3.val.ival <0 || $3.val.ival >= curr_node->arr->dim_size[curr_node->arr->dims - rec_count]){
								printf("dims:%d, rec_count: %d\n", (yyvsp[-3].myvar).n->arr->dims, (yyvsp[-3].myvar).rec_count);
								printf("curr_dimsize %d, ival %d\n", (yyvsp[-3].myvar).n->arr->dim_size[(yyvsp[-3].myvar).rec_count], (yyvsp[-1].myexpr).val.ival);
								printf("semantic error2\n");}
							     	else (yyval.myvar).rec_count = (yyvsp[-3].myvar).rec_count+1;
							}
					}
#line 1808 "dkk.tab.c"
    break;

  case 52: /* variable: LISTFUNC LPAREN general_expression RPAREN  */
#line 223 "dkk.y"
                                                    {}
#line 1814 "dkk.tab.c"
    break;

  case 53: /* variable: decltype ID  */
#line 224 "dkk.y"
                      { 
			struct hashnode_s *p;
			if((p = hashtbl_lookup(symtb, scope, yylval.str)) == NULL)
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
#line 1837 "dkk.tab.c"
    break;

  case 56: /* general_expression: assignment  */
#line 244 "dkk.y"
                    {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val;}
#line 1843 "dkk.tab.c"
    break;

  case 59: /* assignment: expression  */
#line 247 "dkk.y"
                     {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val;}
#line 1849 "dkk.tab.c"
    break;

  case 62: /* constant: CCONST  */
#line 249 "dkk.y"
                  {(yyval.myexpr).type = T_CHAR; (yyval.myexpr).val.cval = yylval.cval;}
#line 1855 "dkk.tab.c"
    break;

  case 63: /* constant: ICONST  */
#line 250 "dkk.y"
                 {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = yylval.ival;}
#line 1861 "dkk.tab.c"
    break;

  case 64: /* constant: FCONST  */
#line 251 "dkk.y"
                 {(yyval.myexpr).type = T_FLOAT; (yyval.myexpr).val.fval = yylval.fval;}
#line 1867 "dkk.tab.c"
    break;

  case 82: /* var_declaration: typename variabledefs SEMI  */
#line 263 "dkk.y"
                                             { var_decl((yyvsp[-1].idlist), (yyvsp[-2].ival)); }
#line 1873 "dkk.tab.c"
    break;

  case 83: /* variabledefs: variabledefs COMMA variabledef  */
#line 264 "dkk.y"
                                              {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = (yyvsp[-2].idlist);
          (yyval.idlist) = n;
      }
#line 1884 "dkk.tab.c"
    break;

  case 84: /* variabledefs: variabledef  */
#line 270 "dkk.y"
                      {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = NULL;
          (yyval.idlist) = n;
      }
#line 1895 "dkk.tab.c"
    break;

  case 85: /* $@2: %empty  */
#line 276 "dkk.y"
                      {dim_count = 0;}
#line 1901 "dkk.tab.c"
    break;

  case 87: /* $@3: %empty  */
#line 277 "dkk.y"
             {dim_count = 0;}
#line 1907 "dkk.tab.c"
    break;

  case 88: /* variabledef: ID $@3 dims  */
#line 277 "dkk.y"
                                   {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[-2].str);
		(yyval.id)->arr = (yyvsp[0].arr);
	}
#line 1917 "dkk.tab.c"
    break;

  case 98: /* func_header_start: typename ID  */
#line 289 "dkk.y"
                                {id_list_t* n = malloc(sizeof(id_list_t));
          			n->id = malloc(sizeof(my_id_t));
				n->id->id = (yyvsp[0].str);
				n->id->arr = NULL;
       			 	n->next = NULL;
				var_decl(n, (yyvsp[-1].ival));}
#line 1928 "dkk.tab.c"
    break;

  case 106: /* global_var_declaration: typename init_variabledefs SEMI  */
#line 299 "dkk.y"
                                                         { var_decl((yyvsp[-1].idlist), (yyvsp[-2].ival)); }
#line 1934 "dkk.tab.c"
    break;

  case 107: /* init_variabledefs: init_variabledefs COMMA init_variabledef  */
#line 300 "dkk.y"
                                                              {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = (yyvsp[0].id);
         		 n->next = (yyvsp[-2].idlist);
         		 (yyval.idlist) = n;
      			}
#line 1945 "dkk.tab.c"
    break;

  case 108: /* init_variabledefs: init_variabledef  */
#line 306 "dkk.y"
                                                  {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = (yyvsp[0].id);
					n->next = NULL;
					(yyval.idlist) = n;
				}
#line 1956 "dkk.tab.c"
    break;

  case 109: /* init_variabledef: variabledef initializer  */
#line 313 "dkk.y"
                                           {(yyval.id) = (yyvsp[-1].id); printf("init_variabledef\n");}
#line 1962 "dkk.tab.c"
    break;

  case 113: /* func_declaration: full_func_declaration  */
#line 315 "dkk.y"
                                                                  {printf("sevo\n");}
#line 1968 "dkk.tab.c"
    break;

  case 114: /* $@4: %empty  */
#line 316 "dkk.y"
                                             {scope++;}
#line 1974 "dkk.tab.c"
    break;

  case 115: /* full_func_declaration: full_par_func_header $@4 LBRACE decl_statements RBRACE  */
#line 316 "dkk.y"
                                                                                      {hashtbl_get(symtb, scope); scope--;}
#line 1980 "dkk.tab.c"
    break;

  case 116: /* $@5: %empty  */
#line 317 "dkk.y"
                                          {scope++;}
#line 1986 "dkk.tab.c"
    break;

  case 117: /* full_func_declaration: nopar_class_func_header $@5 LBRACE decl_statements RBRACE  */
#line 317 "dkk.y"
                                                                                  {hashtbl_get(symtb, scope);scope--;}
#line 1992 "dkk.tab.c"
    break;

  case 118: /* $@6: %empty  */
#line 318 "dkk.y"
                                    {scope++;}
#line 1998 "dkk.tab.c"
    break;

  case 119: /* full_func_declaration: nopar_func_header $@6 LBRACE decl_statements RBRACE  */
#line 318 "dkk.y"
                                                                            {hashtbl_get(symtb, scope);scope--;}
#line 2004 "dkk.tab.c"
    break;

  case 134: /* declarations: declarations decltype typename variabledefs SEMI  */
#line 331 "dkk.y"
                                                                { var_decl((yyvsp[-1].idlist), (yyvsp[-2].ival)); }
#line 2010 "dkk.tab.c"
    break;

  case 135: /* declarations: decltype typename variabledefs SEMI  */
#line 332 "dkk.y"
                                                     { var_decl((yyvsp[-1].idlist), (yyvsp[-2].ival)); }
#line 2016 "dkk.tab.c"
    break;

  case 167: /* $@7: %empty  */
#line 357 "dkk.y"
                      {scope++;}
#line 2022 "dkk.tab.c"
    break;

  case 168: /* $@8: %empty  */
#line 357 "dkk.y"
                                                 {hashtbl_get(symtb, scope);scope--;}
#line 2028 "dkk.tab.c"
    break;

  case 170: /* $@9: %empty  */
#line 358 "dkk.y"
                           {scope++;}
#line 2034 "dkk.tab.c"
    break;

  case 171: /* main_function: main_header $@9 LBRACE decl_statements RBRACE  */
#line 358 "dkk.y"
                                                                    {hashtbl_get(symtb, scope);scope--;}
#line 2040 "dkk.tab.c"
    break;


#line 2044 "dkk.tab.c"

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

#line 360 "dkk.y"

#include "hashtbl.h"

void var_decl(id_list_t *var_list, int type) {
	id_list_t *curr = var_list, *prv = var_list;
	char t[8];

	switch (type) {
		case T_CHAR: strcpy(t, "char\0");  break;
		case T_INT: strcpy(t, "int\0");   break;
		case T_FLOAT: strcpy(t,"float\0"); break;
		case T_VOID: strcpy(t,"void\0");  break;
	    case T_ID: strcpy(t,"typedef\0"); break;
		default: strcpy(t, "unknown\0");
	}
	
	if (strcmp(t, "unknown") == 0) {
		printf("Error: Variable unknown type.\n");
		//return;
	}

	while (curr) {
		printf("str = %s\n", curr->id->id);
		if(hashtbl_lookup(symtb, scope, curr->id->id) != NULL)
			printf("semantic error, x2 declare\n");
		else hashtbl_insert(symtb, curr->id->id, t, scope, curr->id->arr);
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
