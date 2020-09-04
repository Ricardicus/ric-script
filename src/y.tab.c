/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gram.y"


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


#line 106 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 37 "gram.y"
 int val_int; double val_double; char id[256]; void *data; 

#line 186 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   272

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    40,    26,    39,     2,    24,    23,     2,    38,
      33,    34,    21,    19,    37,    20,    29,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,     2,
      31,    18,    32,    41,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,    42,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,    30,     2,     2,     2,
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
       0,    90,    90,   107,   112,   116,   119,   122,   125,   128,
     131,   134,   137,   140,   143,   146,   150,   152,   156,   160,
     164,   169,   172,   179,   187,   194,   200,   210,   221,   233,
     236,   243,   251,   258,   264,   274,   285,   297,   304,   309,
     316,   322,   325,   328,   331,   334,   337,   340,   345,   348,
     353,   356,   361,   366,   371,   376,   380,   383,   386,   389,
     394,   399,   403,   408,   412,   415,   419,   424,   429,   435,
     438,   441,   444,   447,   450,   455,   458,   461,   464,   467,
     470,   473,   478,   484,   489,   492,   498,   503,   509,   515,
     523,   531,   537,   542,   545,   548,   551,   555,   561,   586,
     591,   594,   599,   604,   609,   614,   619,   623,   627,   631,
     635,   639,   643,   647,   651,   655,   659,   663,   667,   671,
     675,   679,   683
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
  "'-'", "'*'", "'/'", "'%'", "'$'", "'@'", "'!'", "'['", "']'", "'.'",
  "'~'", "'<'", "'>'", "'('", "')'", "'{'", "'}'", "','", "'\\''", "'\"'",
  "' '", "'?'", "'\\\\'", "':'", "$accept", "program", "statements",
  "statement", "systemStatement", "returnStatement", "continueStatement",
  "breakStatement", "ifStatement", "loopStatement", "middleIfs",
  "middleIf", "endIf", "condition", "function", "functionCall",
  "declaration", "body", "vector", "arguments_list", "parameters_list",
  "mathContents", "mathContent", "indexedVector", "mathContentDigit",
  "stringContents", "stringContent", "stringEditions", "stringEdition",
  "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,    36,    64,    33,    91,    93,    46,
     126,    60,    62,    40,    41,   123,   125,    44,    39,    34,
      32,    63,    92,    58
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,  -130,  -130,    46,   158,    61,    18,    36,   137,    -2,
     137,   161,   202,    95,  -130,    45,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,   194,  -130,   237,  -130,   -11,  -130,    27,
    -130,    77,    72,    98,    -3,  -130,   237,    69,    79,  -130,
      27,    92,  -130,    89,  -130,   355,   -15,   137,    96,   338,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,   308,  -130,  -130,  -130,
    -130,  -130,   243,  -130,  -130,  -130,   312,   284,  -130,  -130,
     158,   158,   158,   158,   158,    77,   140,    24,   119,  -130,
    -130,   385,   -15,   105,   110,  -130,    74,   237,    27,     7,
      70,   116,   128,    70,   205,   246,   131,   126,   370,  -130,
    -130,   308,  -130,   312,   106,   106,  -130,  -130,  -130,  -130,
    -130,   385,   -15,   139,   143,  -130,  -130,    -3,    69,  -130,
    -130,   -19,  -130,  -130,  -130,   137,  -130,    70,    84,    45,
     142,   158,   158,   142,   158,   237,   158,   237,    81,    70,
      70,  -130,  -130,  -130,   237,    27,  -130,    70,   168,   138,
      32,   142,  -130,  -130,   237,   237,   142,  -130,   237,   237,
      79,    27,   142,   142,  -130,  -130,  -130,   137,  -130,  -130,
    -130,  -130,   142,  -130,   142,  -130,   150,   385,  -130,  -130,
      70,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    86,    76,    75,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     2,     4,    15,    14,    12,    13,
       8,     9,     6,     7,     5,    10,    74,    78,    77,    11,
      92,     0,     0,     0,    75,    80,    18,    78,    16,    95,
      17,     0,    20,     0,    80,     0,     0,     0,     0,     0,
     102,   101,   100,   122,   104,   109,   110,   115,   120,   121,
     119,   107,   108,   113,   114,   116,    97,   118,   105,   106,
     111,   112,     0,    99,   103,   117,    96,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,    53,    52,     0,     0,    51,     0,    64,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      79,    93,    98,    94,    69,    70,    71,    73,    72,    58,
      59,    57,    56,     0,     0,    90,    89,    88,    91,    87,
      62,     0,    83,    82,    50,     0,    68,     0,     0,     4,
      21,     0,     0,    25,     0,    46,     0,    47,     0,     0,
       0,    85,    84,    61,    63,    65,    49,     0,     0,     0,
       0,    22,    38,    24,    41,    43,    26,    28,    44,    45,
       0,    42,    29,    33,    48,    67,    60,     0,    40,    37,
      23,    27,    30,    32,    34,    36,     0,     0,    31,    35,
       0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   -13,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
      39,    71,  -129,    -9,  -130,     0,  -130,   -92,    99,    97,
    -130,     9,  -130,    20,   -26,    21,   109,   185,   -38,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     161,   162,   163,    43,    22,    35,    24,   140,    90,    96,
     138,    25,    26,    37,    28,    46,    30,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    48,    79,   106,    87,    39,    94,    85,    44,   153,
      44,   143,   136,    36,   167,    23,    86,    45,   135,    49,
      27,    29,    89,    41,    32,    47,    40,   125,   126,   127,
      33,    44,   180,    44,   112,    27,    29,   181,   107,   112,
      91,   137,    97,   183,   185,   156,    87,    44,     1,     2,
       3,     4,    92,   188,    98,   189,   108,   172,   173,   177,
     124,    42,    11,    12,    31,   174,    38,   139,   178,     5,
       6,     7,     8,    32,     9,     1,   119,    93,    10,    33,
       1,     2,    34,    11,    12,    44,   170,    39,    44,   114,
     115,   116,   117,   118,   121,    78,    86,    97,   191,    11,
      12,     1,     2,    34,    88,   139,   122,   128,   134,    98,
      10,   135,    33,   145,   147,    11,    12,   100,   157,    11,
      12,   158,     1,     2,    34,    99,   159,    82,    83,    84,
     109,    10,    95,   132,   141,    44,    11,    12,   133,    23,
       1,     2,    34,     1,   154,   123,   142,   130,    39,   148,
     164,   165,    10,   168,   149,   169,   155,    11,    12,    27,
      29,     1,     2,    34,    50,    51,    52,   151,   186,   171,
      10,   152,   160,   175,   176,    11,    12,    44,   190,    53,
      54,    55,   166,    56,   120,   131,   187,    57,    58,    59,
      60,    10,    61,    62,    63,    64,   129,    77,    65,    66,
      67,    68,    69,    70,    71,    50,    51,    52,     1,     2,
      34,   182,   184,   -80,   -80,   -80,   -80,   -80,     0,     0,
      53,    54,    55,   144,    56,     0,     0,     0,    57,    58,
      59,    60,   179,    61,    62,    63,    64,   179,    10,    65,
      75,    76,    68,    69,    70,    71,    50,    51,    52,     1,
       2,    34,     0,   179,     0,   179,    80,    81,    82,    83,
      84,    53,    54,    55,   146,    56,     0,     0,     0,    57,
      58,    59,    60,     0,    61,    62,    63,    64,     0,    10,
      65,   111,    67,    68,    69,    70,    71,    50,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,     0,    56,     0,     0,     0,
      57,    58,    59,    60,     0,    61,    62,    63,    64,     0,
       0,    65,    75,   113,    68,    69,    70,    71,  -117,     0,
    -117,     0,  -118,     0,  -118,     0,     0,     0,     0,  -117,
    -117,     0,     0,  -118,  -118,     0,     0,     0,  -117,  -117,
    -117,  -117,  -118,  -118,  -118,  -118,   101,    80,    81,    82,
      83,    84,     0,     0,   102,     0,     0,     0,     0,   104,
     105,     0,   110,   101,    80,    81,    82,    83,    84,     0,
       0,   102,     0,   103,     0,     0,   104,   105,   101,    80,
      81,    82,    83,    84,     0,     0,   102,     0,   150,     0,
       0,   104,   105,   101,    80,    81,    82,    83,    84,     0,
       0,   102,     0,     0,     0,     0,   104,   105
};

static const yytype_int16 yycheck[] =
{
       0,    10,    15,    18,    19,     5,    32,    18,     8,    28,
      10,   103,     5,     4,   143,    15,    27,     8,    37,    10,
       0,     0,    31,     5,    27,    27,     5,     3,     4,     5,
      33,    31,   161,    33,    72,    15,    15,   166,    47,    77,
      31,    34,    33,   172,   173,   137,    19,    47,     3,     4,
       5,     6,    31,   182,    33,   184,    47,   149,   150,    27,
      86,    25,    38,    39,    18,   157,     5,    35,   160,    24,
      25,    26,    27,    27,    29,     3,    85,     5,    33,    33,
       3,     4,     5,    38,    39,    85,     5,    87,    88,    80,
      81,    82,    83,    84,    85,     0,    27,    88,   190,    38,
      39,     3,     4,     5,    27,    35,    85,    87,    34,    88,
      33,    37,    33,   104,   105,    38,    39,    28,    34,    38,
      39,    37,     3,     4,     5,    33,   139,    21,    22,    23,
      34,    33,    34,    28,    18,   135,    38,    39,    28,   139,
       3,     4,     5,     3,   135,     5,    18,    28,   148,    18,
     141,   142,    33,   144,    28,   146,   135,    38,    39,   139,
     139,     3,     4,     5,     3,     4,     5,    28,   177,   148,
      33,    28,    30,     5,    36,    38,    39,   177,    28,    18,
      19,    20,   143,    22,    85,    88,   177,    26,    27,    28,
      29,    33,    31,    32,    33,    34,    87,    12,    37,    38,
      39,    40,    41,    42,    43,     3,     4,     5,     3,     4,
       5,   172,   173,    19,    20,    21,    22,    23,    -1,    -1,
      18,    19,    20,    18,    22,    -1,    -1,    -1,    26,    27,
      28,    29,   161,    31,    32,    33,    34,   166,    33,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     3,
       4,     5,    -1,   182,    -1,   184,    19,    20,    21,    22,
      23,    18,    19,    20,    18,    22,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    -1,    33,
      37,    38,    39,    40,    41,    42,    43,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    20,    -1,
      22,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    31,    32,    -1,    -1,    -1,    40,    41,
      42,    43,    40,    41,    42,    43,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    -1,    34,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    28,    -1,    -1,    31,    32,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    -1,
      -1,    31,    32,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    24,    25,    26,    27,    29,
      33,    38,    39,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    58,    59,    60,    65,    66,    67,    68,    69,
      70,    18,    27,    33,     5,    59,    65,    67,     5,    59,
      69,     5,    25,    57,    59,    65,    69,    27,    57,    65,
       3,     4,     5,    18,    19,    20,    22,    26,    27,    28,
      29,    31,    32,    33,    34,    37,    38,    39,    40,    41,
      42,    43,    71,    72,    73,    38,    39,    71,     0,    46,
      19,    20,    21,    22,    23,    18,    27,    19,    27,    57,
      62,    65,    69,     5,    68,    34,    63,    65,    69,    33,
      28,    18,    26,    28,    31,    32,    18,    57,    65,    34,
      34,    38,    72,    39,    65,    65,    65,    65,    65,    57,
      62,    65,    69,     5,    68,     3,     4,     5,    67,    70,
      28,    63,    28,    28,    34,    37,     5,    34,    64,    35,
      61,    18,    18,    61,    18,    65,    18,    65,    18,    28,
      28,    28,    28,    28,    65,    69,    61,    34,    37,    46,
      30,    54,    55,    56,    65,    65,    54,    56,    65,    65,
       5,    69,    61,    61,    61,     5,    36,    27,    61,    55,
      56,    56,    54,    56,    54,    56,    57,    65,    56,    56,
      28,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    50,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     4,     5,     6,     5,     4,     5,     6,     5,     5,
       6,     7,     6,     5,     6,     7,     6,     2,     1,     5,
       2,     4,     4,     4,     4,     4,     3,     3,     6,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     4,     4,     4,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  case 2:
#line 90 "gram.y"
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
#line 1477 "y.tab.c"
    break;

  case 3:
#line 107 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1487 "y.tab.c"
    break;

  case 4:
#line 112 "gram.y"
    { (yyval.data) = NULL; }
#line 1493 "y.tab.c"
    break;

  case 5:
#line 116 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1501 "y.tab.c"
    break;

  case 6:
#line 119 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1509 "y.tab.c"
    break;

  case 7:
#line 122 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCCALL, (yyvsp[0].data));
    }
#line 1517 "y.tab.c"
    break;

  case 8:
#line 125 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1525 "y.tab.c"
    break;

  case 9:
#line 128 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1533 "y.tab.c"
    break;

  case 10:
#line 131 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_MATH, (yyvsp[0].data));
    }
#line 1541 "y.tab.c"
    break;

  case 11:
#line 134 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_STR, (yyvsp[0].data));
    }
#line 1549 "y.tab.c"
    break;

  case 12:
#line 137 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1557 "y.tab.c"
    break;

  case 13:
#line 140 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1565 "y.tab.c"
    break;

  case 14:
#line 143 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1573 "y.tab.c"
    break;

  case 15:
#line 146 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1581 "y.tab.c"
    break;

  case 16:
#line 150 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1589 "y.tab.c"
    break;

  case 17:
#line 152 "gram.y"
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1597 "y.tab.c"
    break;

  case 18:
#line 156 "gram.y"
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1605 "y.tab.c"
    break;

  case 19:
#line 160 "gram.y"
    {
    (yyval.data) = NULL;
}
#line 1613 "y.tab.c"
    break;

  case 20:
#line 164 "gram.y"
    {
    (yyval.data) = NULL;
}
#line 1621 "y.tab.c"
    break;

  case 21:
#line 169 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1629 "y.tab.c"
    break;

  case 22:
#line 172 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1641 "y.tab.c"
    break;

  case 23:
#line 179 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1654 "y.tab.c"
    break;

  case 24:
#line 187 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1666 "y.tab.c"
    break;

  case 25:
#line 194 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-2].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[0].data));
    }
#line 1677 "y.tab.c"
    break;

  case 26:
#line 200 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1692 "y.tab.c"
    break;

  case 27:
#line 210 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-4].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1708 "y.tab.c"
    break;

  case 28:
#line 221 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1723 "y.tab.c"
    break;

  case 29:
#line 233 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1731 "y.tab.c"
    break;

  case 30:
#line 236 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1743 "y.tab.c"
    break;

  case 31:
#line 243 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1756 "y.tab.c"
    break;

  case 32:
#line 251 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1768 "y.tab.c"
    break;

  case 33:
#line 258 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-2].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[0].data));
    }
#line 1779 "y.tab.c"
    break;

  case 34:
#line 264 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1794 "y.tab.c"
    break;

  case 35:
#line 274 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-4].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1810 "y.tab.c"
    break;

  case 36:
#line 285 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1825 "y.tab.c"
    break;

  case 37:
#line 297 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 1837 "y.tab.c"
    break;

  case 38:
#line 304 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1845 "y.tab.c"
    break;

  case 39:
#line 309 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 1855 "y.tab.c"
    break;

  case 40:
#line 316 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 1864 "y.tab.c"
    break;

  case 41:
#line 322 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1872 "y.tab.c"
    break;

  case 42:
#line 325 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1880 "y.tab.c"
    break;

  case 43:
#line 328 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1888 "y.tab.c"
    break;

  case 44:
#line 331 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1896 "y.tab.c"
    break;

  case 45:
#line 334 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1904 "y.tab.c"
    break;

  case 46:
#line 337 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1912 "y.tab.c"
    break;

  case 47:
#line 340 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1920 "y.tab.c"
    break;

  case 48:
#line 345 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 1928 "y.tab.c"
    break;

  case 49:
#line 348 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 1936 "y.tab.c"
    break;

  case 50:
#line 353 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[-3].id),(yyvsp[-1].data));
    }
#line 1944 "y.tab.c"
    break;

  case 51:
#line 356 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[-2].id),NULL);
    }
#line 1952 "y.tab.c"
    break;

  case 52:
#line 361 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 1962 "y.tab.c"
    break;

  case 53:
#line 366 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 1972 "y.tab.c"
    break;

  case 54:
#line 371 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        expr_t *condexpr = newExpr_Cond((yyvsp[0].data));
        (yyval.data) = newDeclaration(idexpr,condexpr);
    }
#line 1982 "y.tab.c"
    break;

  case 55:
#line 376 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 1991 "y.tab.c"
    break;

  case 56:
#line 380 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 1999 "y.tab.c"
    break;

  case 57:
#line 383 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2007 "y.tab.c"
    break;

  case 58:
#line 386 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2015 "y.tab.c"
    break;

  case 59:
#line 389 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2023 "y.tab.c"
    break;

  case 60:
#line 394 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2031 "y.tab.c"
    break;

  case 61:
#line 399 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2040 "y.tab.c"
    break;

  case 62:
#line 403 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2048 "y.tab.c"
    break;

  case 63:
#line 408 "gram.y"
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2057 "y.tab.c"
    break;

  case 64:
#line 412 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2065 "y.tab.c"
    break;

  case 65:
#line 415 "gram.y"
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2074 "y.tab.c"
    break;

  case 66:
#line 419 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2082 "y.tab.c"
    break;

  case 67:
#line 424 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2092 "y.tab.c"
    break;

  case 68:
#line 429 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2101 "y.tab.c"
    break;

  case 69:
#line 435 "gram.y"
    {
        (yyval.data) = newExpr_OPAdd((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2109 "y.tab.c"
    break;

  case 70:
#line 438 "gram.y"
    {
        (yyval.data) = newExpr_OPSub((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2117 "y.tab.c"
    break;

  case 71:
#line 441 "gram.y"
    {
        (yyval.data) = newExpr_OPMul((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2125 "y.tab.c"
    break;

  case 72:
#line 444 "gram.y"
    {
        (yyval.data) = newExpr_OPMod((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2133 "y.tab.c"
    break;

  case 73:
#line 447 "gram.y"
    {
        (yyval.data) = newExpr_OPDiv((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2141 "y.tab.c"
    break;

  case 74:
#line 450 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2149 "y.tab.c"
    break;

  case 75:
#line 455 "gram.y"
    {
        (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 2157 "y.tab.c"
    break;

  case 76:
#line 458 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2165 "y.tab.c"
    break;

  case 77:
#line 461 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2173 "y.tab.c"
    break;

  case 78:
#line 464 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2181 "y.tab.c"
    break;

  case 79:
#line 467 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2189 "y.tab.c"
    break;

  case 80:
#line 470 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[0].data));
    }
#line 2197 "y.tab.c"
    break;

  case 81:
#line 473 "gram.y"
    {
        (yyval.data) = newExpr_Cond((yyvsp[-1].data));
    }
#line 2205 "y.tab.c"
    break;

  case 82:
#line 478 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2216 "y.tab.c"
    break;

  case 83:
#line 484 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = newExpr_ID((yyvsp[-1].id));
        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2226 "y.tab.c"
    break;

  case 84:
#line 489 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2234 "y.tab.c"
    break;

  case 85:
#line 492 "gram.y"
    {
      expr_t *index = newExpr_ID((yyvsp[-1].id));
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), index);
    }
#line 2243 "y.tab.c"
    break;

  case 86:
#line 498 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2251 "y.tab.c"
    break;

  case 87:
#line 503 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2262 "y.tab.c"
    break;

  case 88:
#line 509 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2273 "y.tab.c"
    break;

  case 89:
#line 515 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", (yyvsp[0].val_double));
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2286 "y.tab.c"
    break;

  case 90:
#line 523 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", (yyvsp[0].val_int));
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2299 "y.tab.c"
    break;

  case 91:
#line 531 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2310 "y.tab.c"
    break;

  case 92:
#line 537 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2318 "y.tab.c"
    break;

  case 93:
#line 542 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2326 "y.tab.c"
    break;

  case 94:
#line 545 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2334 "y.tab.c"
    break;

  case 95:
#line 548 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[0].data));
    }
#line 2342 "y.tab.c"
    break;

  case 96:
#line 551 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2351 "y.tab.c"
    break;

  case 97:
#line 555 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2360 "y.tab.c"
    break;

  case 98:
#line 561 "gram.y"
    {
        char *textBuffer;

        expr_t *e1 = (expr_t*)(yyvsp[-1].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        textBuffer = ast_emalloc(e1->textLen+e2->textLen+1);

        snprintf(textBuffer, e1->textLen+e2->textLen+1,
            "%s%s",
            e1->text,
            e2->text
        );

        textBuffer[e1->textLen + e2->textLen] = 0;

        free(e1->text);
        free(e2->text);
        free(e1);
        free(e2);

        (yyval.data) = newExpr_Text(textBuffer);

        free(textBuffer);
    }
#line 2390 "y.tab.c"
    break;

  case 99:
#line 586 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2398 "y.tab.c"
    break;

  case 100:
#line 591 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2406 "y.tab.c"
    break;

  case 101:
#line 594 "gram.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%lf", yyval.val_double);
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2416 "y.tab.c"
    break;

  case 102:
#line 599 "gram.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", yyval.val_int);
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2426 "y.tab.c"
    break;

  case 103:
#line 604 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2434 "y.tab.c"
    break;

  case 104:
#line 609 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2443 "y.tab.c"
    break;

  case 105:
#line 614 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2452 "y.tab.c"
    break;

  case 106:
#line 619 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2461 "y.tab.c"
    break;

  case 107:
#line 623 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2470 "y.tab.c"
    break;

  case 108:
#line 627 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2479 "y.tab.c"
    break;

  case 109:
#line 631 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2488 "y.tab.c"
    break;

  case 110:
#line 635 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2497 "y.tab.c"
    break;

  case 111:
#line 639 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2506 "y.tab.c"
    break;

  case 112:
#line 643 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2515 "y.tab.c"
    break;

  case 113:
#line 647 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2524 "y.tab.c"
    break;

  case 114:
#line 651 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2533 "y.tab.c"
    break;

  case 115:
#line 655 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2542 "y.tab.c"
    break;

  case 116:
#line 659 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2551 "y.tab.c"
    break;

  case 117:
#line 663 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2560 "y.tab.c"
    break;

  case 118:
#line 667 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2569 "y.tab.c"
    break;

  case 119:
#line 671 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2578 "y.tab.c"
    break;

  case 120:
#line 675 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2587 "y.tab.c"
    break;

  case 121:
#line 679 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2596 "y.tab.c"
    break;

  case 122:
#line 683 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2605 "y.tab.c"
    break;


#line 2609 "y.tab.c"

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 688 "gram.y"


#include "hooks.h"

void initParser() {
    setParser(yyparse);
    setRoot(&root);
}
