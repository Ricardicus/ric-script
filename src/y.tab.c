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
        "%s at line: %d\n",
        s,
        yylinenor);
}

int yylex(void);

/* Root statement */
statement_t *root = NULL;


#line 102 "y.tab.c" /* yacc.c:339  */

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
#line 37 "gram.y" /* yacc.c:355  */
 int val_int; double val_double; char id[256]; void *data; 

#line 179 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

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
       2,    30,    44,    31,     2,     2,     2,     2,     2,     2,
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
       0,    98,    98,   115,   120,   124,   127,   130,   133,   136,
     139,   142,   145,   148,   151,   155,   157,   161,   165,   169,
     174,   177,   183,   189,   195,   201,   209,   212,   215,   218,
     221,   224,   227,   232,   235,   242,   250,   259,   262,   269,
     277,   286,   293,   298,   305,   311,   314,   317,   320,   323,
     328,   331,   334,   337,   340,   343,   346,   350,   387,   390,
     395,   398,   404,   408,   412,   416,   422,   427,   432,   437,
     441,   444,   447,   450,   455,   460,   467,   470,   475,   485,
     495,   505,   517,   522,   526,   531,   535,   540,   545,   551,
     554,   558,   561,   567,   573,   578,   583,   588,   594,   600,
     610,   620,   626,   632,   637,   640,   643,   647,   653,   681,
     686,   689,   696,   703,   708,   713,   718,   723,   727,   731,
     735,   739,   743,   747,   751,   755,   759,   763,   767,   771,
     775,   779,   783,   787,   791,   795
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
  "','", "'\\''", "'\"'", "' '", "'\\\\'", "$accept", "program",
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
      44,    39,    34,    32,    92
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -131

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     110,  -146,  -146,   355,   363,   119,    19,     8,    14,   363,
      26,    51,    92,   183,   225,   138,  -146,   110,  -146,  -146,
    -146,  -146,   393,   162,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,   373,  -146,  -146,  -146,    25,   155,   363,    77,
     393,   149,  -146,  -146,  -146,   129,  -146,   189,  -146,   134,
     403,   403,   216,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,    75,  -146,  -146,  -146,  -146,  -146,   267,  -146,
    -146,  -146,    97,   309,  -146,  -146,   363,   363,   363,   363,
     363,   185,    25,   351,   363,   406,    38,   139,   214,  -146,
    -146,  -146,  -146,   393,   -13,   259,    70,   236,    21,  -146,
     207,   102,   214,   211,  -146,   219,   227,   232,   228,    75,
    -146,    97,   253,   253,  -146,  -146,  -146,   272,   214,  -146,
    -146,  -146,  -146,     7,   301,   172,   255,  -146,    22,   145,
    -146,    27,   266,   273,   354,   357,  -146,   363,  -146,  -146,
    -146,  -146,  -146,   262,   270,  -146,  -146,   268,   103,   268,
     268,   269,   289,  -146,  -146,  -146,  -146,  -146,   139,    79,
     363,   363,   363,   393,   363,   393,   393,   110,  -146,   268,
     312,   285,   285,   268,   360,  -146,   393,  -146,  -146,   129,
    -146,   393,   393,   393,   393,   280,  -146,  -146,    40,   285,
    -146,  -146,   285,  -146,  -146,  -146,   121,  -146,   403,  -146,
    -146,  -146,  -146,  -146,   294,   268,  -146
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
       0,     0,     0,   110,   113,   135,   115,   120,   134,   121,
     127,   125,   126,   117,   132,   133,   131,   118,   119,   124,
     123,   128,   107,   130,   116,   122,   112,   111,     0,   109,
     114,   129,   106,     0,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    66,    68,
      67,    69,    63,    86,     0,     0,     0,     0,     0,    32,
      95,    31,     0,     0,    45,    29,    28,     0,     0,   104,
     108,   105,    21,    23,    22,    25,    24,     0,    70,    73,
      71,    72,    65,     0,     0,     0,     0,    84,     0,     0,
      76,     0,     0,     0,     0,     0,    62,     0,    93,    98,
     100,    99,    97,     0,   102,   101,    88,     0,     0,     0,
       0,     0,     0,    64,    94,    56,    83,    74,     0,     0,
       0,     0,     0,    54,     0,    55,    85,     4,    59,     0,
       0,    33,    37,     0,     0,    75,    78,    80,    81,    79,
      30,    50,    51,    52,    53,     0,    58,    87,     0,    34,
      42,    36,    38,    40,    57,    61,     0,    82,     0,    44,
      41,    35,    39,    60,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   -10,  -146,  -146,  -146,  -146,  -146,     0,  -146,
    -146,  -146,   144,  -102,  -145,   -35,   -24,  -146,  -146,   -45,
     -40,  -146,   -84,  -146,   165,  -139,   -78,   -74,  -146,  -146,
       1,    18,    20,    -3,    -4,   320,    -6,  -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    20,    21,   103,    23,
      24,    25,   199,   200,   201,   113,   114,    26,    27,    28,
      29,    30,   100,   139,   140,   178,   101,   104,   158,    31,
      41,    33,    34,   141,    35,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    32,    46,    45,    40,   115,   115,    85,   130,    49,
     116,   116,    99,    47,   131,   146,   117,    22,    32,   133,
     181,   182,   138,    42,    44,    43,   156,   147,     1,     2,
      39,    76,    76,    77,    77,   163,    98,   203,   105,    48,
     196,     1,     2,    39,   204,     5,   106,   147,   107,   157,
     112,   112,    95,   166,   211,    96,    50,   212,     5,   209,
      13,    14,   147,    97,   169,     9,    13,    14,   129,   137,
     208,   136,   120,     1,     2,   149,   216,   120,   177,    13,
      14,    51,     1,     2,    39,   187,   122,   123,   124,   125,
     126,   188,   128,    46,   134,   135,    76,   210,    77,     5,
     210,    76,   152,    77,    37,  -129,     9,    38,   154,    96,
     206,    13,    14,     1,     2,     3,     4,    97,  -129,  -129,
      13,    14,     1,     2,   150,   155,   151,  -130,    52,    37,
       5,   179,    38,   -46,     6,     7,     8,     9,    84,    10,
    -130,  -130,    11,   180,   173,   175,    12,   176,   106,   213,
     107,    13,    14,    86,    87,    88,    89,    90,     1,     2,
      39,   147,   109,   115,    46,   190,   189,   195,   116,   186,
     191,   192,   193,   214,   194,     5,    93,    22,    32,    94,
      13,    14,     9,   102,   167,   168,     1,     2,    53,    54,
     142,    86,    87,    88,    89,    90,    13,    14,   143,    91,
     109,    55,    56,    57,    58,    59,   144,   145,   112,    60,
      61,    62,    63,    64,    65,    66,   108,    67,    68,    69,
      70,   118,   127,    71,    72,    73,    74,    75,     1,     2,
      53,    54,   142,    86,    87,    88,    89,    90,   -47,     1,
     143,   153,   159,    55,    56,    57,    58,    59,   144,   145,
     -49,    60,    61,    62,    63,    64,    65,    66,   -48,    67,
      68,    69,    70,   160,   161,    71,    81,    82,    74,    75,
       1,     2,    53,    54,    88,    89,    90,   162,    86,    87,
      88,    89,    90,   165,   170,    55,    56,    57,    58,    59,
     148,   171,    38,    60,    61,    62,    63,    64,    65,    66,
      94,    67,    68,    69,    70,   183,   177,    71,   119,    73,
      74,    75,     1,     2,    53,    54,   184,   197,   198,   207,
      86,    87,    88,    89,    90,   215,   202,    55,    56,    57,
      58,    59,   164,   185,    83,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,     0,     0,    71,
      81,   121,    74,    75,     1,     2,    39,     1,     2,    39,
       1,     2,    39,     1,     2,    39,     1,     2,    39,     0,
       0,     5,   172,    36,     5,   174,     0,     5,     9,   132,
       5,     9,    37,     5,     9,    38,     0,     9,   205,     0,
       9,    92,    13,    14,     0,    13,    14,     0,    13,    14,
      93,    13,    14,    94,    13,    14,   110,     2,   111,     1,
       2,    39,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     5,     0,     0,     0,
      95,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     0,    13,    14
};

static const yytype_int16 yycheck[] =
{
       0,     0,     6,     6,     4,    50,    51,    17,    92,     9,
      50,    51,    36,     5,    92,    28,    51,    17,    17,    93,
     159,   160,    96,     5,     5,     5,     5,    40,     3,     4,
       5,    13,    14,    13,    14,    28,    36,   182,    38,    25,
     179,     3,     4,     5,   183,    20,    19,    40,    21,    28,
      50,    51,    27,    31,   199,    30,    30,   202,    20,   198,
      41,    42,    40,    38,    37,    27,    41,    42,    92,    31,
      30,    95,    78,     3,     4,     5,   215,    83,    38,    41,
      42,    30,     3,     4,     5,   169,    86,    87,    88,    89,
      90,   169,    92,    97,    94,    95,    78,   199,    78,    20,
     202,    83,   106,    83,    27,    30,    27,    30,   107,    30,
     184,    41,    42,     3,     4,     5,     6,    38,    43,    44,
      41,    42,     3,     4,   106,   107,   106,    30,    36,    27,
      20,    28,    30,    31,    24,    25,    26,    27,     0,    29,
      43,    44,    32,    40,   144,   145,    36,   147,    19,    28,
      21,    41,    42,    19,    20,    21,    22,    23,     3,     4,
       5,    40,    28,   208,   168,   169,   169,   177,   208,   169,
     170,   171,   172,   208,   174,    20,    27,   177,   177,    30,
      41,    42,    27,    28,    39,    40,     3,     4,     5,     6,
      18,    19,    20,    21,    22,    23,    41,    42,    26,    37,
      28,    18,    19,    20,    21,    22,    34,    35,   208,    26,
      27,    28,    29,    30,    31,    32,    27,    34,    35,    36,
      37,     5,    37,    40,    41,    42,    43,    44,     3,     4,
       5,     6,    18,    19,    20,    21,    22,    23,    31,     3,
      26,     5,    31,    18,    19,    20,    21,    22,    34,    35,
      31,    26,    27,    28,    29,    30,    31,    32,    31,    34,
      35,    36,    37,    31,    36,    40,    41,    42,    43,    44,
       3,     4,     5,     6,    21,    22,    23,     5,    19,    20,
      21,    22,    23,    28,    18,    18,    19,    20,    21,    22,
      31,    18,    30,    26,    27,    28,    29,    30,    31,    32,
      30,    34,    35,    36,    37,    36,    38,    40,    41,    42,
      43,    44,     3,     4,     5,     6,    27,     5,    33,    39,
      19,    20,    21,    22,    23,    31,   182,    18,    19,    20,
      21,    22,    31,   168,    14,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,     3,     4,     5,     3,     4,     5,
       3,     4,     5,     3,     4,     5,     3,     4,     5,    -1,
      -1,    20,    18,    18,    20,    18,    -1,    20,    27,    28,
      20,    27,    27,    20,    27,    30,    -1,    27,    28,    -1,
      27,    18,    41,    42,    -1,    41,    42,    -1,    41,    42,
      27,    41,    42,    30,    41,    42,     3,     4,     5,     3,
       4,     5,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    20,    -1,    -1,    -1,
      27,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    27,
      29,    32,    36,    41,    42,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    62,    63,    64,    65,
      66,    74,    75,    76,    77,    79,    18,    27,    30,     5,
      53,    75,    76,    77,     5,    78,    79,     5,    25,    53,
      30,    30,    36,     5,     6,    18,    19,    20,    21,    22,
      26,    27,    28,    29,    30,    31,    32,    34,    35,    36,
      37,    40,    41,    42,    43,    44,    76,    77,    80,    81,
      82,    41,    42,    80,     0,    47,    19,    20,    21,    22,
      23,    37,    18,    27,    30,    27,    30,    38,    53,    61,
      67,    71,    28,    53,    72,    53,    19,    21,    27,    28,
       3,     5,    53,    60,    61,    64,    65,    60,     5,    41,
      81,    42,    53,    53,    53,    53,    53,    37,    53,    61,
      67,    71,    28,    72,    53,    53,    61,    31,    72,    68,
      69,    78,    18,    26,    34,    35,    28,    40,    31,     5,
      76,    77,    79,     5,    75,    76,     5,    28,    73,    31,
      31,    36,     5,    28,    31,    28,    31,    39,    40,    37,
      18,    18,    18,    53,    18,    53,    53,    38,    70,    28,
      40,    70,    70,    36,    27,    69,    53,    67,    71,    78,
      79,    53,    53,    53,    53,    47,    70,     5,    33,    57,
      58,    59,    57,    59,    70,    28,    72,    39,    30,    70,
      58,    59,    59,    28,    60,    31,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    51,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    68,    68,    68,    69,    69,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82
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
       1,     1,     1,     1,     1,     1
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
#line 98 "gram.y" /* yacc.c:1646  */
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
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "gram.y" /* yacc.c:1646  */
    {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 120 "gram.y" /* yacc.c:1646  */
    { (yyval.data) = NULL; }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "gram.y" /* yacc.c:1646  */
    {
    (yyval.data) = NULL;
}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 183 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 189 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "gram.y" /* yacc.c:1646  */
    {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 215 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 218 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 227 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 232 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 235 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 250 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 259 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 269 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 277 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 286 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 293 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 298 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 305 "gram.y" /* yacc.c:1646  */
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 311 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 314 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 317 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Ival((yyvsp[0].val_int));
    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 320 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 323 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 328 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 331 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 334 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 337 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 340 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 343 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 346 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 350 "gram.y" /* yacc.c:1646  */
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
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 387 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 390 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 395 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 398 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 404 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 412 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 416 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 422 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 427 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 432 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 437 "gram.y" /* yacc.c:1646  */
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 441 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 444 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 447 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 450 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 455 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 460 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 467 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 470 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = NULL;
    }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 475 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 485 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 495 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 505 "gram.y" /* yacc.c:1646  */
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 517 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 522 "gram.y" /* yacc.c:1646  */
    {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 526 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 531 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 535 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 540 "gram.y" /* yacc.c:1646  */
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "gram.y" /* yacc.c:1646  */
    {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 551 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 554 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 558 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 561 "gram.y" /* yacc.c:1646  */
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 567 "gram.y" /* yacc.c:1646  */
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 573 "gram.y" /* yacc.c:1646  */
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 578 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 583 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 588 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 594 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 600 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 610 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 620 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 626 "gram.y" /* yacc.c:1646  */
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 632 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 637 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 640 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 643 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 647 "gram.y" /* yacc.c:1646  */
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 653 "gram.y" /* yacc.c:1646  */
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
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 681 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 686 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 689 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 696 "gram.y" /* yacc.c:1646  */
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 703 "gram.y" /* yacc.c:1646  */
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 708 "gram.y" /* yacc.c:1646  */
    {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 713 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 718 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 723 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 727 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 731 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 735 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 739 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 743 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 747 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 751 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 755 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 759 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 763 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 767 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 771 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 775 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 779 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 783 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 787 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 791 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 795 "gram.y" /* yacc.c:1646  */
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2775 "y.tab.c" /* yacc.c:1646  */
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
#line 800 "gram.y" /* yacc.c:1906  */


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
