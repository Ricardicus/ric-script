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
#line 1 "gram.y" /* yacc.c:339  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "hooks.h"

extern int yylinenor;
extern char *ParsedFile;

void *e_malloc(size_t size)
{
    char *mem = (char*)calloc(size,1);
    if ( mem == NULL ) {
        fprintf(stderr, "Calloc failed, size: %zu\n", size);
        exit(1);
    }
    return (void*)mem;
}

void yyerror(const char *s)
{
    fprintf(stderr,
        "%s:%d: %s\n",
        ParsedFile,
        yylinenor,
        s);
}

int yylex(void);

/* Root statement */
statement_t *root = NULL;


#line 104 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DIGIT = 258,
    DOUBLE = 259,
    ID = 260,
    RETURN = 261,
    COMMENT = 262,
    NEWLINE = 263,
    KEY_FLOAT = 264,
    KEY_INT = 265,
    KEY_STR = 266,
    KEY_STRUCT = 267,
    KEY_PROCESS = 268,
    WHITESPACE = 269,
    OPEN = 270,
    CLOSE = 271,
    OTHER = 272
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define DOUBLE 259
#define ID 260
#define RETURN 261
#define COMMENT 262
#define NEWLINE 263
#define KEY_FLOAT 264
#define KEY_INT 265
#define KEY_STR 266
#define KEY_STRUCT 267
#define KEY_PROCESS 268
#define WHITESPACE 269
#define OPEN 270
#define CLOSE 271
#define OTHER 272

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "gram.y" /* yacc.c:355  */
 int val_int; double val_double; char id[256]; void *data; 

#line 181 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   459

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    43,    26,    42,     2,    24,    23,     2,    41,
      27,    28,    21,    19,    40,    20,    32,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    36,
      34,    18,    35,    29,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,    44,    31,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    33,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   117,   122,   126,   129,   132,   135,   138,
     141,   144,   147,   150,   153,   157,   159,   163,   167,   171,
     176,   179,   185,   191,   197,   203,   211,   214,   217,   220,
     223,   226,   229,   234,   237,   244,   252,   261,   264,   271,
     279,   288,   295,   300,   307,   313,   316,   319,   322,   325,
     330,   333,   336,   339,   342,   345,   348,   352,   389,   392,
     397,   400,   406,   410,   414,   418,   424,   429,   434,   439,
     443,   446,   449,   452,   457,   462,   469,   472,   477,   487,
     497,   507,   519,   524,   528,   533,   537,   542,   547,   553,
     556,   560,   563,   569,   575,   580,   585,   590,   596,   602,
     612,   622,   628,   634,   639,   642,   645,   649,   655,   683,
     688,   691,   698,   705,   710,   715,   720,   725,   729,   733,
     737,   741,   745,   749,   753,   757,   761,   765,   769,   773,
     777,   781,   785,   789,   793,   797,   801,   805
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "COMMENT", "NEWLINE", "KEY_FLOAT", "KEY_INT", "KEY_STR", "KEY_STRUCT",
  "KEY_PROCESS", "WHITESPACE", "OPEN", "CLOSE", "OTHER", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'$'", "'@'", "'!'", "'('", "')'", "'?'",
  "'['", "']'", "'.'", "'~'", "'<'", "'>'", "';'", "':'", "'{'", "'}'",
  "','", "'\\''", "'\"'", "' '", "'\\\\'", "'^'", "$accept", "program",
  "statements", "statement", "systemStatement", "returnStatement",
  "continueStatement", "breakStatement", "expressions", "expression",
  "ifStatement", "loopStatement", "middleIfs", "middleIf", "endIf",
  "logical", "condition", "class", "function", "classFunctionCall",
  "functionCall", "declaration", "dictionary", "dictionary_keys_vals",
  "dictionary_key_val", "body", "vector", "arguments_list",
  "parameters_list", "mathContent", "indexedVector", "mathContentDigit",
  "mathContentDouble", "stringContents", "stringContent", "stringEditions",
  "stringEdition", "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,    36,    64,    33,    40,    41,    63,
      91,    93,    46,   126,    60,    62,    59,    58,   123,   125,
      44,    39,    34,    32,    92,    94
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -131

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,  -150,  -150,    95,    60,   152,    35,     8,     4,    60,
      26,    56,    57,   185,   228,   109,  -150,    42,  -150,  -150,
    -150,  -150,   436,    81,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,   370,  -150,  -150,  -150,   103,   157,    60,    30,
     436,    52,  -150,  -150,  -150,   119,  -150,    97,  -150,   302,
     369,   369,   126,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,   151,  -150,  -150,  -150,  -150,  -150,  -150,
     271,  -150,  -150,  -150,   236,   314,  -150,  -150,    60,    60,
      60,    60,    60,    98,   103,   357,    60,   409,   360,   122,
     419,  -150,  -150,  -150,  -150,   436,   -13,   222,   197,   323,
       9,  -150,   128,   121,   419,   147,  -150,   155,   156,   161,
     172,   151,  -150,   236,   214,   214,  -150,  -150,  -150,   188,
     419,  -150,  -150,  -150,  -150,     2,   263,   397,   169,  -150,
      41,   143,  -150,     7,   200,   205,   116,   363,  -150,    60,
    -150,  -150,  -150,  -150,  -150,   194,   210,  -150,  -150,   213,
      13,   213,   213,   225,   240,  -150,  -150,  -150,  -150,  -150,
     122,   112,    60,    60,    60,   436,    60,   436,   436,    42,
    -150,   213,   273,   254,   254,   213,   366,  -150,   436,  -150,
    -150,   119,  -150,   436,   436,   436,   436,   249,  -150,  -150,
      99,   254,  -150,  -150,   254,  -150,  -150,  -150,    21,  -150,
     369,  -150,  -150,  -150,  -150,  -150,   265,   213,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    95,    96,    31,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     4,    13,    12,
      10,    11,     7,    20,     8,     9,    14,     6,    29,    28,
       5,    27,    26,    91,    89,    30,     0,     0,     0,    31,
      17,    26,    92,    90,    15,    16,   103,     0,    19,     0,
       0,     0,     0,   110,   113,   137,   115,   120,   134,   121,
     136,   127,   125,   126,   117,   132,   133,   131,   118,   119,
     124,   123,   128,   107,   130,   116,   122,   135,   112,   111,
       0,   109,   114,   129,   106,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      66,    68,    67,    69,    63,    86,     0,     0,     0,     0,
       0,    32,    95,    31,     0,     0,    45,    29,    28,     0,
       0,   104,   108,   105,    21,    23,    22,    25,    24,     0,
      70,    73,    71,    72,    65,     0,     0,     0,     0,    84,
       0,     0,    76,     0,     0,     0,     0,     0,    62,     0,
      93,    98,   100,    99,    97,     0,   102,   101,    88,     0,
       0,     0,     0,     0,     0,    64,    94,    56,    83,    74,
       0,     0,     0,     0,     0,    54,     0,    55,    85,     4,
      59,     0,     0,    33,    37,     0,     0,    75,    78,    80,
      81,    79,    30,    50,    51,    52,    53,     0,    58,    87,
       0,    34,    42,    36,    38,    40,    57,    61,     0,    82,
       0,    44,    41,    35,    39,    60,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   -10,  -150,  -150,  -150,  -150,  -150,     0,  -150,
    -150,  -150,   120,   -90,  -149,   -35,   -24,  -150,  -150,   -45,
     -40,  -150,   -86,  -150,   139,  -142,   -72,   -74,  -150,  -150,
       1,    18,    20,    -3,    -4,   296,   -26,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    20,    21,   105,    23,
      24,    25,   201,   202,   203,   115,   116,    26,    27,    28,
      29,    30,   102,   141,   142,   180,   103,   106,   160,    31,
      41,    33,    34,   143,    35,    80,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    32,    46,    45,    40,   117,   117,    87,   132,    49,
     118,   118,   101,    47,   158,   148,   119,    22,    32,   183,
     184,   135,   133,    42,   140,    43,   108,   149,   109,    48,
     165,    78,    78,    79,    79,   205,   100,   159,   107,   198,
      44,   181,   149,   206,   171,     1,     2,     3,     4,   215,
     114,   114,   213,   182,   122,   214,    50,    37,   211,   122,
      38,   149,     5,     1,     2,    39,     6,     7,     8,     9,
     131,    10,   168,   138,    11,   218,    13,    14,    12,    95,
       5,   149,    96,    13,    14,   189,    51,     9,   124,   125,
     126,   127,   128,    52,   130,    46,   136,   137,    78,   190,
      79,    13,    14,    78,   154,    79,     1,     2,    39,    86,
     156,   212,   208,    36,   212,     1,     2,    39,    93,     1,
       2,    39,    37,     5,   110,    38,   152,   157,   153,   210,
      97,   120,     5,    98,   174,   129,     5,   179,   108,     9,
     109,    99,    98,     9,    13,    14,   175,   177,    37,   178,
      99,    38,   -46,    13,    14,     1,     2,    13,    14,   -47,
       1,     2,    39,    13,    14,   117,    46,   192,   191,   197,
     118,   188,   193,   194,   195,   216,   196,     5,   161,    22,
      32,  -129,   169,   170,     9,   104,   -49,   -48,     1,     2,
      53,    54,   162,   164,  -129,  -129,  -129,   167,    13,    14,
       1,     2,   151,    55,    56,    57,    58,    59,   163,    60,
     114,    61,    62,    63,    64,    65,    66,    67,   172,    68,
      69,    70,    71,   173,    38,    72,    73,    74,    75,    76,
      77,     1,     2,    53,    54,    90,    91,    92,    13,    14,
      96,    88,    89,    90,    91,    92,    55,    56,    57,    58,
      59,   179,    60,   150,    61,    62,    63,    64,    65,    66,
      67,   185,    68,    69,    70,    71,  -130,   186,    72,    83,
      84,    75,    76,    77,     1,     2,    53,    54,   199,  -130,
    -130,  -130,    88,    89,    90,    91,    92,   200,   209,    55,
      56,    57,    58,    59,   166,    60,   217,    61,    62,    63,
      64,    65,    66,    67,   204,    68,    69,    70,    71,   187,
      85,    72,   121,    74,    75,    76,    77,     1,     2,    53,
      54,    88,    89,    90,    91,    92,     1,     0,   155,     0,
     111,     0,    55,    56,    57,    58,    59,     0,    60,     0,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    83,   123,    75,    76,    77,
       1,     2,    39,     1,     2,    39,     1,     2,    39,     1,
       2,    39,   112,     2,   113,     0,     0,     5,     0,     0,
       5,   176,     0,     5,     9,   134,     5,     9,    94,     5,
       9,   139,     0,     9,   207,     0,    97,    95,    13,    14,
      96,    13,    14,     0,    13,    14,     0,    13,    14,     0,
      13,    14,     1,     2,    39,   144,    88,    89,    90,    91,
      92,     0,     0,   145,     0,   111,     0,     0,     0,     5,
       0,   146,   147,     0,     0,     0,    97,   144,    88,    89,
      90,    91,    92,     0,     0,   145,     0,     0,     0,     0,
      13,    14,     0,   146,   147,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
       0,     0,     6,     6,     4,    50,    51,    17,    94,     9,
      50,    51,    36,     5,     5,    28,    51,    17,    17,   161,
     162,    95,    94,     5,    98,     5,    19,    40,    21,    25,
      28,    13,    14,    13,    14,   184,    36,    28,    38,   181,
       5,    28,    40,   185,    37,     3,     4,     5,     6,    28,
      50,    51,   201,    40,    80,   204,    30,    27,   200,    85,
      30,    40,    20,     3,     4,     5,    24,    25,    26,    27,
      94,    29,    31,    97,    32,   217,    41,    42,    36,    27,
      20,    40,    30,    41,    42,   171,    30,    27,    88,    89,
      90,    91,    92,    36,    94,    99,    96,    97,    80,   171,
      80,    41,    42,    85,   108,    85,     3,     4,     5,     0,
     109,   201,   186,    18,   204,     3,     4,     5,    37,     3,
       4,     5,    27,    20,    27,    30,   108,   109,   108,    30,
      27,     5,    20,    30,    18,    37,    20,    38,    19,    27,
      21,    38,    30,    27,    41,    42,   146,   147,    27,   149,
      38,    30,    31,    41,    42,     3,     4,    41,    42,    31,
       3,     4,     5,    41,    42,   210,   170,   171,   171,   179,
     210,   171,   172,   173,   174,   210,   176,    20,    31,   179,
     179,    30,    39,    40,    27,    28,    31,    31,     3,     4,
       5,     6,    31,     5,    43,    44,    45,    28,    41,    42,
       3,     4,     5,    18,    19,    20,    21,    22,    36,    24,
     210,    26,    27,    28,    29,    30,    31,    32,    18,    34,
      35,    36,    37,    18,    30,    40,    41,    42,    43,    44,
      45,     3,     4,     5,     6,    21,    22,    23,    41,    42,
      30,    19,    20,    21,    22,    23,    18,    19,    20,    21,
      22,    38,    24,    31,    26,    27,    28,    29,    30,    31,
      32,    36,    34,    35,    36,    37,    30,    27,    40,    41,
      42,    43,    44,    45,     3,     4,     5,     6,     5,    43,
      44,    45,    19,    20,    21,    22,    23,    33,    39,    18,
      19,    20,    21,    22,    31,    24,    31,    26,    27,    28,
      29,    30,    31,    32,   184,    34,    35,    36,    37,   170,
      14,    40,    41,    42,    43,    44,    45,     3,     4,     5,
       6,    19,    20,    21,    22,    23,     3,    -1,     5,    -1,
      28,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
       3,     4,     5,     3,     4,     5,     3,     4,     5,     3,
       4,     5,     3,     4,     5,    -1,    -1,    20,    -1,    -1,
      20,    18,    -1,    20,    27,    28,    20,    27,    18,    20,
      27,    31,    -1,    27,    28,    -1,    27,    27,    41,    42,
      30,    41,    42,    -1,    41,    42,    -1,    41,    42,    -1,
      41,    42,     3,     4,     5,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    20,
      -1,    34,    35,    -1,    -1,    -1,    27,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      41,    42,    -1,    34,    35,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    27,
      29,    32,    36,    41,    42,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    63,    64,    65,    66,
      67,    75,    76,    77,    78,    80,    18,    27,    30,     5,
      54,    76,    77,    78,     5,    79,    80,     5,    25,    54,
      30,    30,    36,     5,     6,    18,    19,    20,    21,    22,
      24,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      36,    37,    40,    41,    42,    43,    44,    45,    77,    78,
      81,    82,    83,    41,    42,    81,     0,    48,    19,    20,
      21,    22,    23,    37,    18,    27,    30,    27,    30,    38,
      54,    62,    68,    72,    28,    54,    73,    54,    19,    21,
      27,    28,     3,     5,    54,    61,    62,    65,    66,    61,
       5,    41,    82,    42,    54,    54,    54,    54,    54,    37,
      54,    62,    68,    72,    28,    73,    54,    54,    62,    31,
      73,    69,    70,    79,    18,    26,    34,    35,    28,    40,
      31,     5,    77,    78,    80,     5,    76,    77,     5,    28,
      74,    31,    31,    36,     5,    28,    31,    28,    31,    39,
      40,    37,    18,    18,    18,    54,    18,    54,    54,    38,
      71,    28,    40,    71,    71,    36,    27,    70,    54,    68,
      72,    79,    80,    54,    54,    54,    54,    48,    71,     5,
      33,    58,    59,    60,    58,    60,    71,    28,    73,    39,
      30,    71,    59,    60,    60,    28,    61,    31,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    52,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    60,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    69,    69,    69,    70,    70,
      70,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    77,    78,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     2,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     5,     6,     7,     6,     5,     6,     7,
       6,     2,     1,     5,     2,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     3,     3,     3,     6,     6,     5,
       7,     6,     4,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     3,     1,     1,
       2,     1,     2,     4,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 100 "gram.y" /* yacc.c:1646  */
    {
    root = (statement_t*)(yyval.data);

    if ( root != NULL ) {
      statement_t *walk1,*walk2;

      walk1 = root;
      while ( walk1 != NULL ) {
        walk2 = walk1;
        walk1 = walk1->next;
      }

      walk2->next = newStatement(LANG_ENTITY_FIN, NULL);
    }
}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "gram.y" /* yacc.c:1646  */
    {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "gram.y" /* yacc.c:1646  */
    { (yyval.data) = NULL; }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 126 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 135 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 144 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 167 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 171 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 197 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 203 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 211 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 214 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 217 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 220 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 226 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 234 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 237 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 244 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 261 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 264 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 271 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 279 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 288 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 295 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 307 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 313 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 316 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Ival((yyvsp[0].val_int));
    }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 322 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 330 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 333 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 336 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 339 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 342 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 345 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 348 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 352 "gram.y" /* yacc.c:1646  */
    {
    /* Only declarations allowed */
    body_t *bod = (yyvsp[0].data);
    statement_t *walk = bod->content;
    char *classId = ast_emalloc(strlen((yyvsp[-3].id))+2);
    memset(classId, 0, strlen((yyvsp[-3].id))+1);
    while ( walk != NULL ) {
        if (
            walk->entity != LANG_ENTITY_DECL &&
            walk->entity != LANG_ENTITY_FUNCDECL &&
            walk->entity != LANG_ENTITY_BODY &&
            walk->entity != LANG_ENTITY_BODY_END
        ) {
            fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[-3].id));
            fprintf(stderr, "  You may only have variable and or function declaration statements here.\r\n");
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, (yyvsp[-3].id)) == 0 ) {
                if ( funcDef->params != NULL ) {
                    fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[-3].id));
                    fprintf(stderr, "  You may not define a constructor with function parameters.\r\n");
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    snprintf(classId, strlen((yyvsp[-3].id))+2, "%s", (yyvsp[-3].id));
    (yyval.data) = newClass(classId, bod);
}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 389 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 392 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 397 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 400 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 406 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 410 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 414 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 418 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 424 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 429 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 434 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 439 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 443 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 446 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 449 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 452 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 457 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 462 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 469 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 472 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = NULL;
    }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 477 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 487 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 497 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 507 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 519 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 524 "gram.y" /* yacc.c:1646  */
    {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 528 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 533 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 537 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 542 "gram.y" /* yacc.c:1646  */
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 547 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 553 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 556 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 560 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 563 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 569 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 575 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 580 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 585 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 590 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 596 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 602 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 612 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 622 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 628 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 634 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 639 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 642 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 645 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 649 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 655 "gram.y" /* yacc.c:1646  */
    {
        char *textBuffer;

        expr_t *e1 = (expr_t*)(yyvsp[-1].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        size_t textlen_e1 = strlen(e1->text);
        size_t textlen_e2 = strlen(e2->text);

        textBuffer = ast_emalloc(textlen_e1+textlen_e2+1);

        snprintf(textBuffer, textlen_e1+textlen_e2+1,
            "%s%s",
            e1->text,
            e2->text
        );

        textBuffer[textlen_e1+textlen_e2] = 0;

        free(e1->text);
        free(e2->text);
        free(e1);
        free(e2);

        (yyval.data) = newExpr_Text(textBuffer);

        free(textBuffer);
    }
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 683 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 688 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 691 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 698 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 705 "gram.y" /* yacc.c:1646  */
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 710 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 715 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 720 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 725 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 729 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 733 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 737 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 741 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 745 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 749 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 753 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 757 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 761 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 765 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 769 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 773 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 777 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 781 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 785 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 789 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 793 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 797 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 801 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 805 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2797 "y.tab.c" /* yacc.c:1646  */
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
#line 810 "gram.y" /* yacc.c:1906  */


#include <stdlib.h>
#include <string.h>
#include "hooks.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse();
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void initParser() {
    setParser(yyparse);
    setRoot(&root);
}

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func) {
    char lineBuffer[256];

    ParsedFile = "stdin";

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    printf(">> ");
    while ( fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL ) {
        YY_BUFFER_STATE buffer;

        /* Check if the user wants to quit */
        if ( strstr(lineBuffer, "quit") != NULL ) {
            func(argc, argv, NULL, 1);
            return;
        }

        /* Parse from read line */
        buffer = yy_scan_string(lineBuffer);
        yyparse();
        yy_delete_buffer(buffer);

        if ( root != NULL ) {
            func(argc, argv, root, 0);
        }

        printf(">> ");
        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}
