/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "dkk.y" /* yacc.c:339  */

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

#line 100 "dkk.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "dkk.tab.h".  */
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
#line 54 "dkk.y" /* yacc.c:355  */
 
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

#line 219 "dkk.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DKK_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 236 "dkk.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   649

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    85,    86,    87,    88,    89,    90,
      91,    92,    92,    93,    94,    95,    96,    97,    98,    99,
      99,   100,   128,   146,   148,   149,   149,   150,   152,   157,
     162,   168,   176,   185,   194,   198,   209,   210,   212,   213,
     214,   233,   234,   235,   236,   237,   238,   239,   277,   307,
     324,   368,   369,   370,   371,   376,   377,   378,   378,   379,
     380,   381,   382,   383,   383,   384,   385,   385,   386,   386,
     387,   387,   387,   387,   388,   389,   390,   391,   392,   393,
     399,   405,   405,   415,   415,   420,   421,   422,   422,   423,
     424,   425,   425,   435,   444,   444,   445,   451,   458,   458,
     459,   460,   460,   461,   462,   469,   477,   478,   478,   478,
     479,   480,   481,   482,   483,   484,   484,   485,   485,   486,
     486,   487,   487,   488,   515,   569,   570,   571,   572,   580,
     587,   587,   592,   593,   594,   595,   595,   596,   597,   598,
     598,   599,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   614,   614,
     615,   615,   615,   615,   615,   616,   616,   617,   618,   618,
     619,   619,   620,   621,   621,   622,   622,   623,   623,   623,
     624,   624,   625
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "CHAR", "INT", "FLOAT",
  "CONST", "UNION", "CLASS", "PRIVATE", "PROTECTED", "PUBLIC", "STATIC",
  "VOID", "LIST", "CONTINUE", "BREAK", "THIS", "IF", "ELSE", "WHILE",
  "FOR", "RETURN", "LENGTH", "NEW", "CIN", "COUT", "MAIN", "FCONST",
  "CCONST", "OROP", "ANDOP", "NOTOP", "SIZEOP", "LPAREN", "RPAREN", "SEMI",
  "DOT", "COMMA", "ASSIGN", "COLON", "LBRACK", "RBRACK", "REFER", "LBRACE",
  "RBRACE", "METH", "INP", "OUT", "EQUOP", "RELOP", "ADDOP", "MULOP",
  "LOWER_THAN_ELSE", "INCDEC", "LPAR", "RPAR", "ICONST", "ID", "STRING",
  "LISTFUNC", "$accept", "program", "global_declarations",
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
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -234

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-234)))

#define YYTABLE_NINF -167

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -234,    20,   220,  -234,   200,  -234,   -18,  -234,   200,   -25,
     -17,  -234,    24,  -234,  -234,  -234,    33,  -234,  -234,  -234,
    -234,    61,    71,    89,  -234,  -234,  -234,  -234,  -234,   116,
    -234,  -234,  -234,  -234,   142,   128,    99,  -234,  -234,   133,
     122,   137,    10,   172,    30,  -234,   157,  -234,    23,  -234,
     202,   208,   141,   209,   231,  -234,   173,   225,  -234,   148,
    -234,   239,   251,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
      45,  -234,  -234,    26,   153,   162,   264,   264,  -234,    57,
     197,   264,   264,  -234,  -234,   180,  -234,    99,   200,   237,
     236,   238,   255,  -234,   254,   438,  -234,  -234,   137,   243,
    -234,  -234,  -234,  -234,  -234,   200,  -234,   200,  -234,   266,
     267,  -234,   270,   272,  -234,   452,   273,   276,   265,   268,
    -234,  -234,   588,   588,   136,  -234,   487,  -234,   588,    18,
    -234,   279,   187,   144,   229,  -234,  -234,  -234,   269,   310,
     203,   356,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
     274,   243,  -234,   275,   278,  -234,   438,   -28,  -234,    45,
    -234,   113,  -234,  -234,  -234,  -234,   246,   254,   438,  -234,
     187,    53,  -234,   259,  -234,   254,    46,    57,  -234,  -234,
     588,  -234,   295,   299,   304,   588,   588,    18,   501,   123,
    -234,   306,   205,   299,   303,   264,   296,   114,   588,   588,
     588,   588,   588,   588,   588,   487,   289,   539,   588,  -234,
    -234,   588,  -234,   203,   356,    56,    45,  -234,  -234,  -234,
    -234,   111,  -234,  -234,   307,   230,  -234,  -234,  -234,   312,
     313,   316,   121,    48,  -234,    98,  -234,  -234,  -234,  -234,
     299,   588,   452,  -234,   206,   207,   114,   -13,  -234,  -234,
     299,    38,  -234,  -234,  -234,  -234,  -234,   216,   198,   123,
     212,    82,   296,  -234,   315,  -234,  -234,  -234,   125,  -234,
      45,   233,  -234,  -234,  -234,    45,  -234,  -234,  -234,  -234,
      48,   239,   300,    69,  -234,  -234,  -234,  -234,  -234,  -234,
     323,    89,   438,  -234,   324,   299,   326,  -234,  -234,  -234,
      18,  -234,   501,   318,  -234,  -234,  -234,   234,  -234,  -234,
    -234,   329,  -234,   332,    23,  -234,   403,   325,  -234,  -234,
    -234,  -234,  -234,  -234,    46,   350,   403,   452,   403,  -234,
    -234,  -234,   339,   553,  -234,   348,   403,  -234
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
      30,    31,    32,    33,     0,    48,    55,    54,     0,    52,
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
    -234,  -234,  -234,  -234,  -234,  -234,    -2,   263,   354,   -53,
    -234,  -234,   305,   -79,   -90,  -112,   188,   189,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,   164,   117,  -234,  -229,  -205,
     -15,  -234,  -234,  -234,   118,  -234,   241,  -234,   398,  -234,
     401,  -234,   228,   404,  -234,  -234,  -234,  -234,   335,  -234,
    -234,  -149,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
     391,   357,   235,  -234,   -56,  -234,   -59,   271,  -133,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -233,  -234,  -234,  -234,   131,  -234,   132,  -234,  -234,  -234,
    -234,  -234,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,   155,   159,    17,   100,    85,
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
      35,   271,   192,    94,   193,   223,   170,   140,   140,   234,
       3,   150,   140,   140,   299,   153,   154,     5,    33,     7,
     224,   108,   171,   171,    37,   300,   111,    11,   171,   197,
     167,    98,    38,   189,   190,   -94,    73,   175,    41,   196,
      79,   286,     5,    33,     7,    43,   281,    63,   101,    72,
      41,    55,    11,   282,   101,   307,   171,    69,   240,    70,
      99,   -14,    41,   244,   245,   301,   250,   170,   171,   131,
     213,   217,    13,    39,    41,    96,   257,   302,   205,   170,
     237,   206,    42,   193,   330,   208,   268,   246,    47,   269,
     334,   151,   221,   176,    96,   177,    48,    13,   209,   171,
     171,   171,   171,   171,   171,   -14,    96,     5,    33,     7,
     258,   259,   260,   261,   262,   263,    49,    11,   313,   295,
     183,   229,   230,   231,   203,   204,   140,   292,   216,   256,
       5,    33,     7,   315,   293,     5,    33,     7,   272,   108,
      11,    52,   206,   157,   111,    11,   208,    55,    58,   227,
     116,   117,   101,    57,   211,   120,   121,   279,   306,   122,
     123,   124,    13,   201,   202,   203,   204,    78,   126,   205,
      63,    64,   206,   325,   207,    86,   208,    87,   128,   104,
     250,   129,   105,   329,   130,   331,    65,   131,   106,   209,
      13,   107,   171,   337,     5,    33,     7,     5,    33,     7,
     246,   270,    67,   170,    11,   183,    71,    11,   199,   200,
     156,   183,   157,     4,     5,     6,     7,     8,     9,    10,
     200,   283,    83,   152,    11,    12,   107,   201,   202,   203,
     204,   254,   297,   298,   211,   211,   211,    76,   201,   202,
     203,   204,   304,    77,    81,   211,   229,   230,   231,    13,
     309,    84,   215,   202,   203,   204,   210,   274,   211,   275,
     308,   322,   275,   275,   163,   165,    82,   108,   283,    13,
     109,   110,   111,   112,    88,   113,   114,   115,   116,   117,
     118,   119,    90,   120,   121,   164,   157,   122,   123,   124,
     166,   125,   174,   178,   179,   180,   126,   181,   185,   127,
    -136,   186,   324,   187,   198,   212,   128,   188,   236,   129,
     218,   219,   130,   108,   220,   131,   109,   110,   111,   112,
     242,   113,   114,   115,   116,   117,   118,   119,   211,   120,
     121,   243,   253,   122,   123,   124,   255,   125,   265,   204,
     273,   305,   126,   276,   277,   127,  -134,   278,   314,   312,
     316,   326,   128,   318,   321,   129,   323,   -94,   130,   108,
     328,   131,   109,   110,   111,   112,   333,   113,   114,   115,
     116,   117,   118,   119,   336,   120,   121,   191,    56,   122,
     123,   124,   158,   125,   264,   267,   280,   310,   126,   311,
      20,   127,   228,    22,   238,    97,    23,    46,   128,    80,
     214,   129,   239,     0,   130,  -140,   108,   131,     0,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,   118,
     119,   319,   120,   121,   320,     0,   122,   123,   124,     0,
     125,     0,     0,     0,     0,   126,     0,     0,   127,     0,
       0,   108,     0,     0,     0,   128,   111,     0,   129,     0,
       0,   130,   116,   117,   131,   108,     0,   120,   121,     0,
     111,   122,   123,   124,     0,     0,   116,   117,     0,     0,
     126,   120,   121,   168,     0,   122,   123,   124,     0,  -166,
     128,     0,     0,   129,   126,     0,   130,     0,   169,   131,
     108,     0,     0,     0,   128,   111,     0,   129,     0,     0,
     130,   116,   117,   131,   108,     0,   120,   121,     0,   111,
     122,   123,   124,     0,     0,   116,   117,     0,     0,   126,
     120,   121,     0,     0,   122,   123,   124,     0,     0,   128,
       0,     0,   129,   126,     0,   130,  -140,     0,   131,     0,
       0,     0,   108,   128,     0,     0,   129,   111,     0,   130,
       0,   249,   131,   116,   117,     0,   108,     0,   120,   121,
       0,   111,   122,   123,   124,     0,     0,   116,   117,     0,
       0,   126,   120,   121,     0,     0,   122,   123,   124,  -166,
       0,   128,     0,     0,   129,   126,     0,   130,     0,   266,
     131,   108,     0,     0,     0,   128,   111,     0,   129,     0,
       0,   130,   116,   117,   131,     0,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,   129,     0,     0,   130,     0,     0,   131
};

static const yytype_int16 yycheck[] =
{
       2,    16,     4,   115,   233,    95,     8,   156,   141,   242,
      28,   216,   124,    66,   126,    43,    95,    76,    77,   168,
       0,    77,    81,    82,    37,    81,    82,     4,     5,     6,
      58,    13,   122,   123,    59,    48,    18,    14,   128,   129,
      93,    15,    59,   122,   123,    35,    48,   100,    15,   128,
      52,   280,     4,     5,     6,    70,     8,    47,    73,    36,
      15,    15,    14,    15,    79,   270,   156,    37,   180,    39,
      44,    15,    15,   185,   186,    37,   188,   156,   168,    61,
     139,   214,    59,    59,    15,    59,   198,    49,    35,   168,
      44,    38,    59,   205,   327,    42,   208,   187,    37,   211,
     333,    44,   155,   105,    59,   107,    35,    59,    55,   199,
     200,   201,   202,   203,   204,    59,    59,     4,     5,     6,
     199,   200,   201,   202,   203,   204,    37,    14,    59,   241,
     242,    10,    11,    12,    52,    53,   195,    39,   140,   195,
       4,     5,     6,   292,    46,     4,     5,     6,    37,    13,
      14,    35,    38,    42,    18,    14,    42,    15,    59,    46,
      24,    25,   177,    35,    39,    29,    30,    46,    43,    33,
      34,    35,    59,    50,    51,    52,    53,    36,    42,    35,
      47,    59,    38,   316,    40,    37,    42,    39,    52,    36,
     302,    55,    39,   326,    58,   328,    59,    61,    36,    55,
      59,    39,   292,   336,     4,     5,     6,     4,     5,     6,
     300,   213,    40,   292,    14,   327,    59,    14,    31,    32,
      40,   333,    42,     3,     4,     5,     6,     7,     8,     9,
      32,   233,    59,    36,    14,    15,    39,    50,    51,    52,
      53,    36,    36,    36,    39,    39,    39,    45,    50,    51,
      52,    53,    36,    45,    45,    39,    10,    11,    12,    59,
     275,    36,    59,    51,    52,    53,    37,    37,    39,    39,
      37,    37,    39,    39,    37,    37,    45,    13,   280,    59,
      16,    17,    18,    19,    45,    21,    22,    23,    24,    25,
      26,    27,    41,    29,    30,    59,    42,    33,    34,    35,
      45,    37,    59,    37,    37,    35,    42,    35,    35,    45,
      46,    35,   314,    48,    35,    46,    52,    49,    59,    55,
      46,    46,    58,    13,    46,    61,    16,    17,    18,    19,
      35,    21,    22,    23,    24,    25,    26,    27,    39,    29,
      30,    37,    36,    33,    34,    35,    43,    37,    59,    53,
      43,    36,    42,    41,    41,    45,    46,    41,    35,    59,
      36,    36,    52,    37,    46,    55,    37,    35,    58,    13,
      20,    61,    16,    17,    18,    19,    37,    21,    22,    23,
      24,    25,    26,    27,    36,    29,    30,   124,    34,    33,
      34,    35,    87,    37,   205,   207,   232,   280,    42,   281,
       2,    45,   161,     2,   176,    70,     2,    16,    52,    52,
     139,    55,   177,    -1,    58,    59,    13,    61,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,   300,    29,    30,   302,    -1,    33,    34,    35,    -1,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    13,    -1,    -1,    -1,    52,    18,    -1,    55,    -1,
      -1,    58,    24,    25,    61,    13,    -1,    29,    30,    -1,
      18,    33,    34,    35,    -1,    -1,    24,    25,    -1,    -1,
      42,    29,    30,    45,    -1,    33,    34,    35,    -1,    37,
      52,    -1,    -1,    55,    42,    -1,    58,    -1,    60,    61,
      13,    -1,    -1,    -1,    52,    18,    -1,    55,    -1,    -1,
      58,    24,    25,    61,    13,    -1,    29,    30,    -1,    18,
      33,    34,    35,    -1,    -1,    24,    25,    -1,    -1,    42,
      29,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    52,
      -1,    -1,    55,    42,    -1,    58,    59,    -1,    61,    -1,
      -1,    -1,    13,    52,    -1,    -1,    55,    18,    -1,    58,
      -1,    60,    61,    24,    25,    -1,    13,    -1,    29,    30,
      -1,    18,    33,    34,    35,    -1,    -1,    24,    25,    -1,
      -1,    42,    29,    30,    -1,    -1,    33,    34,    35,    36,
      -1,    52,    -1,    -1,    55,    42,    -1,    58,    -1,    60,
      61,    13,    -1,    -1,    -1,    52,    18,    -1,    55,    -1,
      -1,    58,    24,    25,    61,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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
      29,    30,    33,    34,    35,    37,    42,    45,    52,    55,
      58,    61,    75,    76,    77,    78,    80,    81,   126,   127,
     128,   129,   130,   131,   132,   134,   137,   143,   144,   149,
     126,    44,    36,   126,   126,    67,    40,    42,    74,    68,
      90,    97,    98,    37,    59,    37,    45,    71,    45,    60,
      75,    76,   113,   128,    59,    71,    68,    68,    37,    37,
      35,    35,   138,    77,   142,    35,    35,    48,    49,    75,
      75,    69,    77,    77,    79,   150,    75,    76,    35,    31,
      32,    50,    51,    52,    53,    35,    38,    40,    42,    55,
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 84 "dkk.y" /* yacc.c:1646  */
    {exit(0);}
#line 1640 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 92 "dkk.y" /* yacc.c:1646  */
    {dim_count = 0;}
#line 1646 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "dkk.y" /* yacc.c:1646  */
    {hashtbl_insert(symtb, (yyvsp[-3].str), (yyvsp[-5].str) , scope, (yyvsp[-1].arr), 1, currvis);}
#line 1652 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "dkk.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1658 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "dkk.y" /* yacc.c:1646  */
    {struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), currvis); if(p == NULL || p->istype == 0) yyerror("Type doesn't exist."); {(yyval.str) = p->key;}}
#line 1664 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 95 "dkk.y" /* yacc.c:1646  */
    {(yyval.str)="char";}
#line 1670 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "dkk.y" /* yacc.c:1646  */
    {(yyval.str)="int";}
#line 1676 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "dkk.y" /* yacc.c:1646  */
    {(yyval.str)="float";}
#line 1682 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "dkk.y" /* yacc.c:1646  */
    {(yyval.str)="void";}
#line 1688 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "dkk.y" /* yacc.c:1646  */
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
#line 1721 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 128 "dkk.y" /* yacc.c:1646  */
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
#line 1744 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "dkk.y" /* yacc.c:1646  */
    {(yyval.arr) = NULL;}
#line 1750 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 152 "dkk.y" /* yacc.c:1646  */
    { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT))
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  else	yyerror("Wrong expression type.");
				      	(yyval.myexpr).node = create_node("||", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					}
#line 1760 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "dkk.y" /* yacc.c:1646  */
    { if (((yyvsp[-2].myexpr).type == T_INT) && ((yyvsp[0].myexpr).type == T_INT))
   					  	(yyval.myexpr).type = (yyvsp[-2].myexpr).type;
					  else yyerror("Wrong expression type.");
				      	(yyval.myexpr).node = create_node("&&", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1770 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "dkk.y" /* yacc.c:1646  */
    {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR))
						(yyval.myexpr).type = T_INT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node("==", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("!=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1781 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "dkk.y" /* yacc.c:1646  */
    {if((((yyvsp[-2].myexpr).type == T_INT || (yyvsp[-2].myexpr).type == T_FLOAT) && (((yyvsp[0].myexpr).type == T_INT) ||((yyvsp[0].myexpr).type == T_FLOAT))) || ((yyvsp[-2].myexpr).type == T_CHAR && (yyvsp[0].myexpr).type == T_CHAR))
						(yyval.myexpr).type = T_INT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node(">", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 1)(yyval.myexpr).node = create_node(">=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 2)(yyval.myexpr).node = create_node("<", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("<=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1794 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "dkk.y" /* yacc.c:1646  */
    {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if (((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT))
						(yyval.myexpr).type = T_FLOAT;
					else yyerror("Wrong expression type.");
					(yyval.myexpr).val.ival = (yyvsp[-2].myexpr).val.ival + (yyvsp[0].myexpr).val.ival;
					if((yyvsp[-1].oper) == 0) (yyval.myexpr).node = create_node("+", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					else (yyval.myexpr).node = create_node("-", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1808 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "dkk.y" /* yacc.c:1646  */
    {if((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_INT)
						(yyval.myexpr).type = T_INT;
					else if ((((yyvsp[-2].myexpr).type == T_INT && (yyvsp[0].myexpr).type == T_FLOAT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_INT) || ((yyvsp[-2].myexpr).type == T_FLOAT && (yyvsp[0].myexpr).type == T_FLOAT)))
						(yyval.myexpr).type = T_FLOAT;
					else yyerror("Wrong expression type.");
				      	if((yyvsp[-1].oper) == 0)(yyval.myexpr).node = create_node("*", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else if((yyvsp[-1].oper) == 1)(yyval.myexpr).node = create_node("/", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      	else (yyval.myexpr).node = create_node("%", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
				      }
#line 1822 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "dkk.y" /* yacc.c:1646  */
    { if ((yyvsp[0].myexpr).type != T_INT) yyerror("Wrong expression type.");
	                     else (yyval.myexpr).type = (yyvsp[0].myexpr).type;
			     (yyval.myexpr).node = create_node("!", (yyvsp[0].myexpr).node, NULL);
	                   }
#line 1831 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 198 "dkk.y" /* yacc.c:1646  */
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
#line 1847 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 209 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = 0; (yyval.myexpr).node = create_node("sizeof", (yyvsp[0].myexpr).node, NULL);}
#line 1853 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 210 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr) = (yyvsp[0].myexpr); asd_t *node = malloc(sizeof(asd_t)); node->name = "1"; if((yyvsp[-1].oper) == 0) (yyval.myexpr).node = create_node("+", (yyvsp[0].myexpr).node, node);
				      	else (yyval.myexpr).node = create_node("-", (yyvsp[0].myexpr).node, node);}
#line 1860 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr) = (yyvsp[-1].myexpr); post_t *temp = malloc(sizeof(post_t)); temp->name = (yyvsp[-1].myexpr).node->name; temp->sign = (yyvsp[0].oper); temp->next = postlist; postlist = temp;}
#line 1866 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr) = (yyvsp[0].myexpr);}
#line 1872 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 214 "dkk.y" /* yacc.c:1646  */
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
						}else if(strcmp((yyvsp[-3].myexpr).n->data, "func"))yyerror("Variable is not a function.");}
#line 1896 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = (yyvsp[0].myexpr).type; (yyval.myexpr).val = (yyvsp[0].myexpr).val; (yyval.myexpr).n = malloc(sizeof(expr_t)); (yyval.myexpr).n->arr = malloc(sizeof(array_t)); (yyval.myexpr).n->arr->dims = 0; (yyval.myexpr).rec_count = 0;if((yyvsp[0].myexpr).type == T_CHAR) (yyval.myexpr).n->data = strdup("char"); else if((yyvsp[0].myexpr).type == T_INT) (yyval.myexpr).n->data = strdup("int"); else if((yyvsp[0].myexpr).type == T_FLOAT) (yyval.myexpr).n->data = strdup("float"); (yyval.myexpr).node = create_node("const", NULL, NULL);}
#line 1902 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 238 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = (yyvsp[0].myexprlist)->exp->type; (yyval.myexpr).val.ival = (yyvsp[0].myexprlist)->listsize; (yyval.myexpr).rec_count = 0; (yyval.myexpr).n = NULL;}
#line 1908 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 239 "dkk.y" /* yacc.c:1646  */
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
								fprintf(fd, "l,\t%s,\tindex,\tt%d\n\n", (yyvsp[-3].myexpr).n->key, ++reg);
								char *buf = malloc(10);
								sprintf(buf, "t%d", reg);
								(yyval.myexpr).node->name = buf;
							}
					}
#line 1951 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "dkk.y" /* yacc.c:1646  */
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
#line 1986 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 307 "dkk.y" /* yacc.c:1646  */
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
#line 2008 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 324 "dkk.y" /* yacc.c:1646  */
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
#line 2057 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).rec_count = 0; (yyval.myexpr).val.ival = 0; (yyval.myexpr).n = currclass; (yyval.myexpr).type = T_ID;}
#line 2063 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 369 "dkk.y" /* yacc.c:1646  */
    {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = (yyvsp[0].myexprlist)->exp; k->next =(yyvsp[-2].myexprlist); k->listsize = (yyvsp[-2].myexprlist)->listsize+(yyvsp[0].myexprlist)->listsize; (yyval.myexprlist) = k;}
#line 2069 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 370 "dkk.y" /* yacc.c:1646  */
    {expr_list_t *k = malloc(sizeof(expr_list_t)); k->exp = malloc(sizeof(expr_t));k->exp->type = (yyvsp[0].myexpr).type; k->exp->val = (yyvsp[0].myexpr).val; k->exp->rec_count = (yyvsp[0].myexpr).rec_count; k->exp->n = (yyvsp[0].myexpr).n; k->next =  NULL;  k->listsize = 1;(yyval.myexprlist) = k; (yyval.myexprlist)->exp->node = (yyvsp[0].myexpr).node; print_tree((yyvsp[0].myexpr).node); if(!noprint){ print_ir((yyvsp[0].myexpr).node); patchinc();}}
#line 2075 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 371 "dkk.y" /* yacc.c:1646  */
    {if((yyvsp[-2].myexpr).rec_count != (yyvsp[-2].myexpr).n->arr->dims) yyerror("Incorrect dimension indexing.");if(findsize((yyvsp[-2].myexpr).n) != findsize((yyvsp[0].myexpr).n)) yyerror("Type mismatch.");
					if((yyvsp[-2].myexpr).n->arr->islist)
						(yyvsp[-2].myexpr).n->arr->listsize[(yyvsp[-2].myexpr).val.ival] = (yyvsp[0].myexpr).val.ival; 
					(yyval.myexpr).node = create_node("=", (yyvsp[-2].myexpr).node, (yyvsp[0].myexpr).node);
					}
#line 2085 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 377 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr) = (yyvsp[0].myexpr);}
#line 2091 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 378 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexprlist) = (yyvsp[0].myexprlist);}
#line 2097 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 378 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexprlist) = NULL;}
#line 2103 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 379 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = T_CHAR; (yyval.myexpr).val.cval = yylval.cval;}
#line 2109 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 380 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = T_INT; (yyval.myexpr).val.ival = yylval.ival;}
#line 2115 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 381 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexpr).type = T_FLOAT; (yyval.myexpr).val.fval = yylval.fval;}
#line 2121 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 382 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexprlist) = (yyvsp[-1].myexprlist);}
#line 2127 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 383 "dkk.y" /* yacc.c:1646  */
    {hashtbl_insert(symtb, (yyvsp[0].str), "class", scope, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), currvis); currtb = p->cla->classtb; scope++;}
#line 2133 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 383 "dkk.y" /* yacc.c:1646  */
    {scope--;struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[-3].str), currvis); p->cla->superclass = (yyvsp[-1].str);currtb = symtb; currvis = 0;}
#line 2139 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 384 "dkk.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-3].str);}
#line 2145 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 385 "dkk.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2151 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 385 "dkk.y" /* yacc.c:1646  */
    {(yyval.str) = NULL;}
#line 2157 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 387 "dkk.y" /* yacc.c:1646  */
    {currvis = 2;}
#line 2163 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 387 "dkk.y" /* yacc.c:1646  */
    {currvis = 1;}
#line 2169 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 387 "dkk.y" /* yacc.c:1646  */
    {currvis = 0;}
#line 2175 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 392 "dkk.y" /* yacc.c:1646  */
    {var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2181 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 393 "dkk.y" /* yacc.c:1646  */
    {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = (yyvsp[-2].idlist);
          (yyval.idlist) = n;
      }
#line 2192 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 399 "dkk.y" /* yacc.c:1646  */
    {
          id_list_t* n = malloc(sizeof(id_list_t));
          n->id = (yyvsp[0].id);
          n->next = NULL;
          (yyval.idlist) = n;
      }
#line 2203 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 405 "dkk.y" /* yacc.c:1646  */
    {dim_count = 0;}
#line 2209 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 405 "dkk.y" /* yacc.c:1646  */
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
#line 2224 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 415 "dkk.y" /* yacc.c:1646  */
    {dim_count = 0;}
#line 2230 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 415 "dkk.y" /* yacc.c:1646  */
    {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[-2].str);
		(yyval.id)->arr = (yyvsp[0].arr);
	}
#line 2240 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 425 "dkk.y" /* yacc.c:1646  */
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
#line 2255 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 435 "dkk.y" /* yacc.c:1646  */
    {struct hashnode_s *p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, currvis);
									  if (p != NULL) yyerror("Double header declaration");
									  else { 
										hashtbl_insert(currtb, (yyvsp[-3].myhdr).name, "func", scope, NULL, 1, currvis);
										p = hashtbl_lookup(currtb, scope, (yyvsp[-3].myhdr).name, currvis);
										p->func->ret_type = (yyvsp[-3].myhdr).type;			
										p->func->header_declared = 0;
										p->func->node = (yyvsp[-1].par_list);
									  }}
#line 2269 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 444 "dkk.y" /* yacc.c:1646  */
    {(yyval.myhdr).type = (yyvsp[-1].str); (yyval.myhdr).name = (yyvsp[0].str);}
#line 2275 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 445 "dkk.y" /* yacc.c:1646  */
    {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = (yyvsp[-1].str);
		n->next = (yyvsp[-3].par_list);
		n->arr = (yyvsp[0].arr);
		(yyval.par_list) = n; }
#line 2286 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 451 "dkk.y" /* yacc.c:1646  */
    {
		par_list_t *n = malloc(sizeof(par_list_t));
		n->type = (yyvsp[-1].str);
		n->next = NULL;
		n->arr = (yyvsp[0].arr);
		(yyval.par_list)= n;
		}
#line 2298 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 458 "dkk.y" /* yacc.c:1646  */
    {(yyval.arr) = (yyvsp[0].arr);}
#line 2304 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 458 "dkk.y" /* yacc.c:1646  */
    {array_t *n = malloc(sizeof(array_t)); n->dims = -1; (yyval.arr) = n;}
#line 2310 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 459 "dkk.y" /* yacc.c:1646  */
    {(yyval.myhdr)=(yyvsp[-2].myhdr);}
#line 2316 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 460 "dkk.y" /* yacc.c:1646  */
    {hashtbl_insert(symtb, (yyvsp[0].str), "union", 0, NULL, 1, 0); struct hashnode_s *p = hashtbl_lookup(symtb, scope, (yyvsp[0].str), 0); currtb = p->un->untb;}
#line 2322 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 460 "dkk.y" /* yacc.c:1646  */
    {currtb = symtb;}
#line 2328 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 461 "dkk.y" /* yacc.c:1646  */
    {var_decl((yyvsp[-1].idlist), (yyvsp[-2].str)); deflist = NULL;}
#line 2334 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 462 "dkk.y" /* yacc.c:1646  */
    {
         		 id_list_t* n = malloc(sizeof(id_list_t));
         		 n->id = (yyvsp[0].id);
         		 n->next = (yyvsp[-2].idlist);
         		 (yyval.idlist) = n;
			deflist = n;
      			}
#line 2346 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 469 "dkk.y" /* yacc.c:1646  */
    {
					id_list_t* n = malloc(sizeof(id_list_t));
					n->id = (yyvsp[0].id);
					n->next = NULL;
					(yyval.idlist) = n;
					deflist = n;
				}
#line 2358 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 477 "dkk.y" /* yacc.c:1646  */
    {int p=1; for(int i=0;((yyvsp[-1].id)!=NULL && (yyvsp[-1].id)->arr!=NULL && i<(yyvsp[-1].id)->arr->dims); i++) p = p * (yyvsp[-1].id)->arr->dim_size[i]; if((((yyvsp[-1].id)!=NULL)&&((yyvsp[-1].id)->data!=NULL)&&(!strcmp((yyvsp[-1].id)->data,"char"))&&((yyvsp[-1].id)->arr!=NULL)&& p==(yyvsp[0].ival))||p<(yyvsp[0].ival)) yyerror("Wrong Initialization.");}
#line 2364 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 478 "dkk.y" /* yacc.c:1646  */
    {dim_count=0;}
#line 2370 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 478 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival) = (yyvsp[0].ival);}
#line 2376 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 478 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival)=0;}
#line 2382 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 479 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival) = 1;}
#line 2388 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 480 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival) = (yyvsp[-1].ival);}
#line 2394 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 481 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival)=strlen((yyvsp[0].str));}
#line 2400 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 482 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival);}
#line 2406 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 483 "dkk.y" /* yacc.c:1646  */
    {(yyval.ival)= (yyvsp[0].ival);}
#line 2412 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 485 "dkk.y" /* yacc.c:1646  */
    {scope++;}
#line 2418 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 485 "dkk.y" /* yacc.c:1646  */
    {currclass = NULL;hashtbl_get(currtb, scope); scope--;}
#line 2424 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 486 "dkk.y" /* yacc.c:1646  */
    {scope++;}
#line 2430 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 486 "dkk.y" /* yacc.c:1646  */
    {hashtbl_get(currtb, scope);scope--;}
#line 2436 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 487 "dkk.y" /* yacc.c:1646  */
    {scope++;}
#line 2442 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 487 "dkk.y" /* yacc.c:1646  */
    {hashtbl_get(currtb, scope);scope--;}
#line 2448 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 488 "dkk.y" /* yacc.c:1646  */
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
									else
									p->func->header_declared = 1;
									scope++;
									var_decl((yyvsp[-1].idlist), (yyvsp[-1].idlist)->id->data);
									scope--;
									currtb = symtb;
								   }
								   else yyerror("Class method incorrectly declared.");}
#line 2480 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 515 "dkk.y" /* yacc.c:1646  */
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
									else
									p->func->header_declared = 1;
									scope++;
									var_decl((yyvsp[-1].idlist), (yyvsp[-1].idlist)->id->data);
									scope--;
								   }
								   else if (p == NULL) {
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
#line 2539 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 569 "dkk.y" /* yacc.c:1646  */
    {struct hashnode_s *p =hashtbl_lookup(currtb, scope, (yyvsp[-1].str), currvis); currclass = p; if(p==NULL) yyerror("Class doesn't exist."); if((p = hashtbl_lookup(p->cla->classtb, 55555, (yyvsp[0].str), currvis)) == NULL) yyerror("Method doesn't exist."); if(strcmp(p->func->ret_type, (yyvsp[-2].str))) yyerror("Method type mismatch."); if(strcmp(p->data, "func")) yyerror("Member is not a method."); (yyval.node) = p;}
#line 2545 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 571 "dkk.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-1].str);}
#line 2551 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 572 "dkk.y" /* yacc.c:1646  */
    {
		id_list_t* n = malloc(sizeof(id_list_t));
                n->id = (yyvsp[0].id);
		n->id->data = (yyvsp[-1].str);
                n->next = (yyvsp[-3].idlist);
                (yyval.idlist) = n;
                }
#line 2563 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 580 "dkk.y" /* yacc.c:1646  */
    {
		id_list_t* n = malloc(sizeof(id_list_t));
		n->id = (yyvsp[0].id);
		n->id->data = (yyvsp[-1].str);
		n->next = NULL;
		(yyval.idlist) = n;
		}
#line 2575 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 587 "dkk.y" /* yacc.c:1646  */
    {(yyval.id) = (yyvsp[0].id);}
#line 2581 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 587 "dkk.y" /* yacc.c:1646  */
    {
		(yyval.id) = malloc(sizeof(id_t));
		(yyval.id)->id = (yyvsp[0].str);
		(yyval.id)->arr = malloc(sizeof(array_t));	
		(yyval.id)->arr->dims = -1;	/* this is how you tell it that it's a reference*/}
#line 2591 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 592 "dkk.y" /* yacc.c:1646  */
    {if((yyvsp[-2].node)->func != NULL) yyerror("Function header mismatch");}
#line 2597 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 596 "dkk.y" /* yacc.c:1646  */
    { var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2603 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 597 "dkk.y" /* yacc.c:1646  */
    { var_decl((yyvsp[-1].idlist), (yyvsp[-2].str));}
#line 2609 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 599 "dkk.y" /* yacc.c:1646  */
    {reg = 0;}
#line 2615 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 599 "dkk.y" /* yacc.c:1646  */
    {reg = 0;}
#line 2621 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 609 "dkk.y" /* yacc.c:1646  */
    {currtb = symtb;}
#line 2627 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 610 "dkk.y" /* yacc.c:1646  */
    {currtb = symtb;}
#line 2633 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 611 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "L%d:\n", label_count);}
#line 2639 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 613 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);}
#line 2645 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 614 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "L%d:\n", ++label_count); scope++;}
#line 2651 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 614 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count);}
#line 2657 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 614 "dkk.y" /* yacc.c:1646  */
    {scope--; fprintf(fd, "goto,\t,\t,\tL%d\n", label_count-1); fprintf(fd, "L%d:\n", label_count);}
#line 2663 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 615 "dkk.y" /* yacc.c:1646  */
    {scope++;}
#line 2669 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 615 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "L%d:\n", ++label_count);}
#line 2675 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 615 "dkk.y" /* yacc.c:1646  */
    {fprintf(fd, "bne,\t%s,\t0,\tL%d\n", lastname, ++label_count); noprint=1;}
#line 2681 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 615 "dkk.y" /* yacc.c:1646  */
    {noprint=0;}
#line 2687 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 615 "dkk.y" /* yacc.c:1646  */
    {print_ir((yyvsp[-3].myexprlist)->exp->node); fprintf(fd, "goto,\t,\t,\tL%d\n", label_count-1); fprintf(fd, "L%d:\n", label_count); scope--;}
#line 2693 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 616 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexprlist) = (yyvsp[0].myexprlist);}
#line 2699 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 616 "dkk.y" /* yacc.c:1646  */
    {(yyval.myexprlist) = NULL;}
#line 2705 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 623 "dkk.y" /* yacc.c:1646  */
    {scope++;}
#line 2711 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 623 "dkk.y" /* yacc.c:1646  */
    {hashtbl_get(currtb, scope);scope--;}
#line 2717 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 624 "dkk.y" /* yacc.c:1646  */
    {header_decl_check(currtb); scope++;}
#line 2723 "dkk.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 624 "dkk.y" /* yacc.c:1646  */
    {scope--; hashtbl_get(currtb, scope);}
#line 2729 "dkk.tab.c" /* yacc.c:1646  */
    break;


#line 2733 "dkk.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 626 "dkk.y" /* yacc.c:1906  */


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
		fprintf(fd, "+,\t%s,\t1,\t%s\n", temp->name, temp->name);
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
	symtb = hashtbl_create(10, NULL);
	currtb = symtb;
	return yyparse();
	hashtbl_destroy(symtb);
	fclose(fd);
}
