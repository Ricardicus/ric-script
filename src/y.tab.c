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
#define YYFINAL  98
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

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
       2,     2,    43,    29,    42,     2,    24,    23,     2,    41,
      25,    27,    21,    19,    40,    20,    26,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    36,
      34,    18,    35,    30,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,    44,    32,    45,     2,     2,     2,     2,     2,
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
       0,   101,   101,   118,   123,   127,   130,   133,   136,   139,
     142,   145,   148,   151,   154,   157,   161,   163,   167,   182,
     186,   190,   195,   198,   204,   210,   216,   222,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   259,   262,   269,
     277,   286,   289,   296,   304,   313,   320,   325,   332,   338,
     341,   346,   351,   354,   357,   360,   363,   366,   369,   373,
     410,   413,   418,   421,   426,   430,   434,   438,   444,   449,
     454,   457,   462,   467,   474,   477,   482,   492,   504,   509,
     513,   518,   522,   527,   532,   538,   541,   545,   548,   554,
     560,   565,   570,   575,   581,   587,   597,   607,   613,   619,
     624,   627,   630,   634,   640,   668,   673,   676,   683,   690,
     695,   700,   705,   710,   714,   718,   722,   726,   730,   734,
     738,   742,   746,   750,   754,   758,   762,   766,   770,   774,
     778,   782,   786,   790
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
  "'-'", "'*'", "'/'", "'%'", "'$'", "'('", "'.'", "')'", "'@'", "'!'",
  "'?'", "'['", "']'", "'~'", "'<'", "'>'", "';'", "':'", "'{'", "'}'",
  "','", "'\\''", "'\"'", "' '", "'\\\\'", "'^'", "$accept", "program",
  "statements", "statement", "systemStatement", "forEachStatement",
  "returnStatement", "continueStatement", "breakStatement", "expressions",
  "expression", "ifStatement", "loopStatement", "middleIfs", "middleIf",
  "endIf", "logical", "condition", "class", "function",
  "classFunctionCall", "functionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "mathContentDigit", "mathContentDouble", "stringContents",
  "stringContent", "stringEditions", "stringEdition", "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,    36,    40,    46,    41,    64,    33,
      63,    91,    93,   126,    60,    62,    59,    58,   123,   125,
      44,    39,    34,    32,    92,    94
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -127

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,  -160,  -160,    15,   437,   164,    25,   437,    -8,     9,
      16,    21,    33,    20,   130,   185,   228,   114,  -160,    57,
    -160,  -160,  -160,  -160,  -160,   259,    90,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,    66,  -160,  -160,
    -160,   460,   357,   437,    47,   437,   259,   117,  -160,  -160,
    -160,    71,  -160,   173,   135,   116,  -160,   135,  -160,   259,
     -16,   132,   145,  -160,    -6,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,   197,  -160,  -160,  -160,  -160,
    -160,  -160,   271,  -160,  -160,  -160,   240,   314,  -160,  -160,
     437,   437,   437,   437,   437,   120,   460,   365,   437,   460,
     503,  -160,  -160,    -5,   101,   216,   112,   108,   123,  -160,
     437,   503,   -11,   142,  -160,     7,   143,  -160,   437,   146,
    -160,   130,   437,   197,  -160,   240,   265,   265,  -160,  -160,
    -160,   192,   503,  -160,  -160,    28,   124,   485,   151,   180,
     183,   397,   405,  -160,  -160,  -160,  -160,  -160,  -160,   171,
     177,  -160,   198,    90,   206,  -160,   206,    67,   206,   259,
     182,  -160,   259,    71,  -160,   220,  -160,  -160,  -160,   437,
     437,   437,   259,   437,   259,   218,    57,   223,  -160,   206,
     246,   223,   206,   428,   259,   259,   259,   259,   234,   227,
      58,   223,  -160,  -160,  -160,  -160,   223,  -160,  -160,  -160,
      85,   206,  -160,   135,  -160,  -160,  -160,  -160,  -160,  -160,
     235,   206,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    91,    92,    35,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    75,     0,     0,     0,     2,     4,
      14,    10,    13,    11,    12,     7,    22,     8,     9,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    87,    85,
      34,     0,     0,     0,    35,     0,    19,    28,    88,    86,
      16,    17,    99,     0,     0,     0,    21,     0,    80,    82,
       0,     0,     0,    74,     0,   106,   109,   133,   111,   116,
     130,   117,   132,   121,   127,   122,   123,   113,   128,   129,
     114,   115,   120,   119,   124,   103,   126,   112,   118,   131,
     108,   107,     0,   105,   110,   125,   102,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    69,    65,     0,     0,     0,     0,     0,     0,    36,
       0,     0,    22,     0,    49,     0,     0,    79,     0,     0,
      72,     0,     0,   100,   104,   101,    23,    25,    24,    27,
      26,     0,    70,    71,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    89,    94,    96,    95,    93,     0,
      98,    97,     0,    50,     0,    84,     0,     0,     0,    81,
       0,    73,    76,    77,    34,     0,    66,    90,    58,     0,
       0,     0,    56,     0,    57,     0,     4,    41,    61,     0,
       0,    37,     0,     0,    52,    53,    54,    55,     0,     0,
       0,    42,    46,    44,    60,    83,    38,    40,    59,    63,
       0,     0,    78,     0,    48,    45,    43,    39,    62,    18,
       0,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   -17,  -160,  -160,  -160,  -160,  -160,  -160,     0,
     -51,  -160,  -160,   103,   -43,  -159,   -52,   -30,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,   168,  -141,  -160,   -34,  -160,
    -160,     1,    13,    34,     4,     3,   288,    73,  -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    59,
      26,    27,    28,   201,   202,   203,   123,   124,    29,    30,
      31,    32,    33,    34,    62,    63,   187,    35,    60,   167,
      36,    47,    38,    39,    64,    40,    92,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,    99,   122,    46,   126,   122,    53,   113,    52,
      51,   111,   165,   116,    55,   117,   127,    52,    48,    25,
      37,   -51,   153,    54,   128,   188,   105,   191,    90,    90,
      50,   132,   207,    41,   166,   128,     1,     2,    44,    49,
      42,   110,   216,   114,    56,   115,    43,   217,   204,    91,
      91,   208,    57,     5,   121,   176,    61,   121,    45,   214,
       1,     2,     3,     4,    12,    58,    15,    16,   128,   163,
     219,    14,    42,   145,    15,    16,   143,     5,    43,   148,
     222,     6,     7,     8,   106,     9,    10,    11,    12,   213,
     116,   107,   117,    13,   189,    14,   186,   108,    15,    16,
     136,   137,   138,   139,   140,    90,   142,   190,   146,   147,
      90,     1,   218,   159,    98,     1,     2,   155,   160,   158,
     100,   101,   102,   103,   104,   128,    91,   105,   169,   156,
     161,    91,   172,   154,    52,   174,   173,   129,     1,     2,
      44,   125,   107,   100,   101,   102,   103,   104,   108,   162,
     157,   182,   184,    15,    16,     5,   177,   141,   215,   210,
     109,   220,   122,   215,   120,   134,    12,     1,     2,   199,
     134,    15,    16,    14,   164,   168,    15,    16,   178,   194,
     195,   196,   170,   197,   130,   131,    25,    37,     1,     2,
      65,    66,   100,   101,   102,   103,   104,   175,   179,   118,
     119,   180,    43,    67,    68,    69,    70,    71,   108,    72,
      73,    74,    75,   121,    76,    77,    78,    79,   192,    80,
      81,    82,    83,   198,   185,    84,    85,    86,    87,    88,
      89,     1,     2,    65,    66,   100,   101,   102,   103,   104,
    -125,  -125,  -125,   119,   186,   193,    67,    68,    69,    70,
      71,   205,    72,    73,    74,    75,   200,    76,    77,    78,
      79,   211,    80,    81,    82,    83,   212,   221,    84,    95,
      96,    87,    88,    89,     1,     2,    65,    66,   100,   101,
     102,   103,   104,  -126,  -126,  -126,   102,   103,   104,    67,
      68,    69,    70,    71,   206,    72,    73,    74,    75,   171,
      76,    77,    78,    79,    97,    80,    81,    82,    83,     0,
       0,    84,   133,    86,    87,    88,    89,     1,     2,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,     0,    76,    77,    78,    79,     0,    80,    81,
      82,    83,     0,     0,    84,    95,   135,    87,    88,    89,
       1,     2,    44,     0,     0,     0,     0,     0,     1,     2,
      44,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,    45,     0,   112,     5,     0,     0,    12,     0,
      45,     0,   144,     0,     0,    14,    12,     0,    15,    16,
       1,     2,    44,    14,     0,     0,    15,    16,     1,     2,
      44,     0,     0,     0,     0,   181,     0,     5,     0,     0,
       0,     0,    45,   183,     0,     5,     0,     0,    12,     0,
      45,     1,     2,    44,     0,    14,    12,     0,    15,    16,
       1,     2,    44,    14,     0,     0,    15,    16,     5,     0,
       0,     0,     0,    45,     0,   209,     0,     5,     0,    12,
       0,     0,    45,     1,     2,    44,    14,     0,    12,    15,
      16,     0,     0,     0,     0,    14,     0,     0,    15,    16,
       5,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,   149,   100,   101,   102,   103,   104,     0,
       0,     0,   119,     0,   150,     0,     0,     0,     0,   151,
     152,   149,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,   151,   152
};

static const yytype_int16 yycheck[] =
{
       0,     0,    19,    54,     4,    57,    57,     7,    42,     6,
       6,    41,     5,    19,     5,    21,    32,    14,     5,    19,
      19,    32,    27,    31,    40,   166,    37,   168,    15,    16,
       5,    37,   191,    18,    27,    40,     3,     4,     5,     5,
      25,    41,   201,    43,    28,    45,    31,   206,   189,    15,
      16,   192,    31,    20,    54,    27,    36,    57,    25,   200,
       3,     4,     5,     6,    31,    32,    41,    42,    40,   120,
     211,    38,    25,   107,    41,    42,   106,    20,    31,   109,
     221,    24,    25,    26,    18,    28,    29,    30,    31,    31,
      19,    25,    21,    36,    27,    38,    38,    31,    41,    42,
     100,   101,   102,   103,   104,    92,   106,    40,   108,   109,
      97,     3,    27,     5,     0,     3,     4,     5,   117,   116,
      19,    20,    21,    22,    23,    40,    92,    37,   128,   116,
     117,    97,   132,    32,   131,   132,   132,     5,     3,     4,
       5,    25,    25,    19,    20,    21,    22,    23,    31,    26,
     116,   151,   152,    41,    42,    20,    32,    37,   201,   193,
      25,   213,   213,   206,    29,    92,    31,     3,     4,   186,
      97,    41,    42,    38,    32,    32,    41,    42,    27,   179,
     180,   181,    36,   183,    39,    40,   186,   186,     3,     4,
       5,     6,    19,    20,    21,    22,    23,     5,    18,    26,
      27,    18,    31,    18,    19,    20,    21,    22,    31,    24,
      25,    26,    27,   213,    29,    30,    31,    32,    36,    34,
      35,    36,    37,     5,    26,    40,    41,    42,    43,    44,
      45,     3,     4,     5,     6,    19,    20,    21,    22,    23,
      43,    44,    45,    27,    38,    25,    18,    19,    20,    21,
      22,     5,    24,    25,    26,    27,    33,    29,    30,    31,
      32,    27,    34,    35,    36,    37,    39,    32,    40,    41,
      42,    43,    44,    45,     3,     4,     5,     6,    19,    20,
      21,    22,    23,    43,    44,    45,    21,    22,    23,    18,
      19,    20,    21,    22,   191,    24,    25,    26,    27,   131,
      29,    30,    31,    32,    16,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    -1,    27,    20,    -1,    -1,    31,    -1,
      25,    -1,    27,    -1,    -1,    38,    31,    -1,    41,    42,
       3,     4,     5,    38,    -1,    -1,    41,    42,     3,     4,
       5,    -1,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    18,    -1,    20,    -1,    -1,    31,    -1,
      25,     3,     4,     5,    -1,    38,    31,    -1,    41,    42,
       3,     4,     5,    38,    -1,    -1,    41,    42,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    -1,    20,    -1,    31,
      -1,    -1,    25,     3,     4,     5,    38,    -1,    31,    41,
      42,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    28,
      29,    30,    31,    36,    38,    41,    42,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    64,
      65,    66,    67,    68,    69,    73,    76,    77,    78,    79,
      81,    18,    25,    31,     5,    25,    55,    77,    78,    79,
       5,    80,    81,    55,    31,     5,    28,    31,    32,    55,
      74,    36,    70,    71,    80,     5,     6,    18,    19,    20,
      21,    22,    24,    25,    26,    27,    29,    30,    31,    32,
      34,    35,    36,    37,    40,    41,    42,    43,    44,    45,
      78,    79,    82,    83,    84,    41,    42,    82,     0,    48,
      19,    20,    21,    22,    23,    37,    18,    25,    31,    25,
      55,    63,    27,    74,    55,    55,    19,    21,    26,    27,
      29,    55,    56,    62,    63,    25,    62,    32,    40,     5,
      39,    40,    37,    41,    83,    42,    55,    55,    55,    55,
      55,    37,    55,    63,    27,    74,    55,    55,    63,    18,
      29,    34,    35,    27,    32,     5,    78,    79,    81,     5,
      77,    78,    26,    56,    32,     5,    27,    75,    32,    55,
      36,    71,    55,    80,    81,     5,    27,    32,    27,    18,
      18,    18,    55,    18,    55,    26,    38,    72,    72,    27,
      40,    72,    36,    25,    55,    55,    55,    55,     5,    48,
      33,    59,    60,    61,    72,     5,    59,    61,    72,    27,
      74,    27,    39,    31,    72,    60,    61,    61,    27,    72,
      62,    32,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    50,    51,    52,
      53,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    59,    59,    60,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      77,    78,    79,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     8,     2,
       1,     2,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     6,     7,
       6,     5,     6,     7,     6,     2,     1,     5,     2,     1,
       2,     1,     4,     4,     4,     4,     3,     3,     3,     6,
       6,     5,     7,     6,     4,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     1,     0,     3,     3,     3,     3,
       2,     3,     1,     3,     1,     1,     2,     1,     2,     4,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 101 "gram.y" /* yacc.c:1646  */
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
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "gram.y" /* yacc.c:1646  */
    {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 123 "gram.y" /* yacc.c:1646  */
    { (yyval.data) = NULL; }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 127 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 130 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 151 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 167 "gram.y" /* yacc.c:1646  */
    {
    body_t *bd = (yyvsp[0].data);
    statement_t *stmt = bd->content;

    while ( stmt != NULL ) {
        if ( stmt->entity == LANG_ENTITY_BODY_END ) {
            /* Set entity to continue */
            stmt->entity = LANG_ENTITY_CONTINUE;
        }
        stmt = stmt->next;
    }

    (yyval.data) = newForEach((yyvsp[-6].data), (yyvsp[-2].id), bd);
}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 182 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 186 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 190 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 195 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 216 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 222 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 233 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 236 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 245 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 251 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 254 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 259 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 269 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 277 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 286 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 289 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 296 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 304 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 313 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 320 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 325 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 332 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 338 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "gram.y" /* yacc.c:1646  */
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 346 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 351 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 354 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 357 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 360 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 363 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 366 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 369 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 373 "gram.y" /* yacc.c:1646  */
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
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 410 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 413 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 418 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 421 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 426 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 430 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 434 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 438 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 444 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 449 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 454 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 457 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 467 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 474 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 477 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = NULL;
    }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 482 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 492 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 504 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 509 "gram.y" /* yacc.c:1646  */
    {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 513 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 518 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 522 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 527 "gram.y" /* yacc.c:1646  */
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 532 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 538 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 541 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 545 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 548 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 554 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 560 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 565 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 570 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 575 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 581 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 587 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 597 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 607 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 613 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 619 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 624 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 627 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 630 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 634 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 640 "gram.y" /* yacc.c:1646  */
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
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 668 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 673 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 676 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 683 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 690 "gram.y" /* yacc.c:1646  */
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 695 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 700 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 705 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 710 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 714 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 718 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 722 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 726 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 730 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 734 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 738 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 742 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 746 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 750 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 754 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 758 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 762 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 766 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 770 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 774 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 778 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 782 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 786 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 790 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2780 "y.tab.c" /* yacc.c:1646  */
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
#line 795 "gram.y" /* yacc.c:1906  */


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
