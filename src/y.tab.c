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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       0,    91,    91,   108,   113,   117,   120,   123,   126,   129,
     132,   135,   138,   141,   144,   147,   151,   153,   157,   161,
     165,   170,   173,   180,   188,   195,   201,   211,   222,   234,
     237,   244,   252,   259,   265,   275,   286,   298,   305,   310,
     317,   323,   326,   329,   332,   335,   338,   341,   346,   349,
     354,   357,   362,   367,   372,   377,   381,   384,   387,   390,
     395,   400,   404,   409,   413,   416,   420,   425,   430,   436,
     439,   442,   445,   448,   451,   456,   459,   462,   467,   470,
     475,   478,   481,   484,   489,   495,   500,   503,   509,   514,
     519,   525,   531,   540,   549,   555,   560,   563,   566,   569,
     573,   579,   604,   609,   612,   618,   624,   629,   634,   639,
     643,   647,   651,   655,   659,   663,   667,   671,   675,   679,
     683,   687,   691,   695,   699,   703
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
      45,    42,    47,    37,    36,    64,    33,    91,    93,    46,
     126,    60,    62,    40,    41,   123,   125,    44,    39,    34,
      32,    63,    92,    58
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -122

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,  -108,  -108,    41,   122,    93,    19,    45,   -21,   347,
      29,   347,   157,   198,    18,  -108,    95,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,   151,  -108,   192,  -108,    -1,  -108,
    -108,    44,  -108,   321,    43,   324,    -6,  -108,   192,    61,
    -108,  -108,    38,  -108,    44,    42,  -108,    66,  -108,   399,
     112,   347,    71,   382,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   351,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,   239,  -108,  -108,  -108,
     356,   280,  -108,  -108,   122,   122,   122,   122,   122,   321,
      78,    73,   333,  -108,  -108,   429,   112,    86,    90,  -108,
     -12,   192,    44,    -2,    97,   117,   118,    97,   160,   201,
     119,   110,   414,  -108,  -108,   351,  -108,   356,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,   429,   112,   113,   116,    -6,
      61,  -108,  -108,  -108,  -108,    -9,  -108,  -108,  -108,   347,
    -108,    97,    30,    95,   115,   122,   122,   115,   122,   192,
     122,   192,    48,    97,    97,  -108,  -108,  -108,   192,    44,
    -108,    97,   143,   114,   -20,   115,  -108,  -108,   192,   192,
     115,  -108,   192,   192,    38,    44,   115,   115,  -108,  -108,
    -108,   347,  -108,  -108,  -108,  -108,   115,  -108,   115,  -108,
     126,   429,  -108,  -108,    97,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    88,    89,    75,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     2,     4,    15,    14,    12,
      13,     8,     9,     6,     7,     5,    10,    74,    80,    78,
      76,    11,    95,     0,     0,     0,    75,    82,    18,    80,
      79,    77,    16,    98,    17,     0,    20,     0,    82,     0,
       0,     0,     0,     0,   103,   125,   107,   112,   113,   118,
     123,   124,   122,   110,   111,   116,   117,   119,   100,   121,
     108,   109,   114,   115,   105,   104,     0,   102,   106,   120,
      99,     0,     1,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    55,    53,    52,     0,     0,    51,
       0,    64,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    81,    96,   101,    97,    69,    70,
      71,    73,    72,    58,    59,    57,    56,     0,     0,    91,
      94,    93,    92,    90,    62,     0,    85,    84,    50,     0,
      68,     0,     0,     4,    21,     0,     0,    25,     0,    46,
       0,    47,     0,     0,     0,    87,    86,    61,    63,    65,
      49,     0,     0,     0,     0,    22,    38,    24,    41,    43,
      26,    28,    44,    45,     0,    42,    29,    33,    48,    67,
      60,     0,    40,    37,    23,    27,    30,    32,    34,    36,
       0,     0,    31,    35,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   -14,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -107,    22,  -104,   -10,  -108,     0,  -108,   -99,    69,    67,
    -108,     1,   161,    13,    26,    32,    14,    76,   155,     4,
    -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     165,   166,   167,    47,    23,    37,    25,   144,    94,   100,
     142,    26,    27,    39,    29,    30,    50,    32,    76,    77,
      78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    52,    83,   140,    46,    38,    43,   181,   147,    48,
      49,    48,    53,    28,    31,   143,    24,    89,    82,   157,
      44,    34,   138,    93,    42,   139,    90,    35,   139,    28,
      31,    40,   141,    48,    95,    48,   101,    41,    74,    74,
     170,   111,   160,   171,    75,    75,     1,    96,    97,   102,
      45,    48,   112,   174,   176,   177,    51,    12,    13,    33,
      98,   184,   178,    91,   161,   182,   185,   162,    34,   186,
     188,    35,   187,   189,    35,   103,     1,     2,   129,   123,
     116,     1,   192,   127,   193,   116,    12,    13,    90,    48,
     125,    43,    48,   101,   104,   195,     1,     2,     1,     2,
       3,     4,    74,   126,   130,   113,   102,    74,    75,   149,
     151,    12,    13,    75,   136,     5,   128,   131,   137,     6,
       7,     8,     9,   132,    10,     1,     2,    36,    11,   163,
     110,    91,   143,    12,    13,   145,   146,   152,   153,    48,
     158,   155,     5,    24,   156,   164,   168,   169,   179,   172,
     180,   173,    43,   159,   194,    11,    28,    31,   124,   135,
       1,     2,    54,     1,     2,    36,   175,   133,    81,     0,
     -82,   190,   -82,   -82,   -82,    55,    56,    57,   148,    58,
       5,    48,   191,    59,    60,    61,    62,   183,    63,    64,
      65,    66,   183,    11,    67,    68,    69,    70,    71,    72,
      73,     1,     2,    54,     1,     2,    36,     0,   183,     0,
     183,    84,    85,    86,    87,    88,    55,    56,    57,   150,
      58,     5,     0,     0,    59,    60,    61,    62,     0,    63,
      64,    65,    66,     0,    11,    67,    79,    80,    70,    71,
      72,    73,     1,     2,    54,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
       0,    58,     0,     0,     0,    59,    60,    61,    62,     0,
      63,    64,    65,    66,     0,     0,    67,   115,    69,    70,
      71,    72,    73,     1,     2,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,     0,    58,     0,     0,     0,    59,    60,    61,    62,
       0,    63,    64,    65,    66,     0,     0,    67,    79,   117,
      70,    71,    72,    73,     1,     2,    36,     1,     2,    36,
       0,     0,     0,     0,     0,     0,     1,     2,    36,     0,
       0,     5,     0,     0,     5,     0,     0,     0,    92,     0,
       1,     2,    36,     5,    11,     0,     0,    11,    99,    12,
      13,   134,    12,    13,     0,     0,    11,     5,     0,     0,
       0,    12,    13,  -120,     0,     0,     0,     0,  -121,     0,
      11,     0,  -120,  -120,     0,    12,    13,  -121,  -121,     0,
       0,  -120,  -120,  -120,  -120,     0,  -121,  -121,  -121,  -121,
     105,    84,    85,    86,    87,    88,     0,     0,   106,     0,
       0,     0,     0,   108,   109,     0,   114,   105,    84,    85,
      86,    87,    88,     0,     0,   106,     0,   107,     0,     0,
     108,   109,   105,    84,    85,    86,    87,    88,     0,     0,
     106,     0,   154,     0,     0,   108,   109,   105,    84,    85,
      86,    87,    88,     0,     0,   106,     0,     0,     0,     0,
     108,   109
};

static const yytype_int16 yycheck[] =
{
       0,    11,    16,     5,    25,     4,     6,    27,   107,     9,
       9,    11,    11,     0,     0,    35,    16,    18,     0,    28,
       6,    27,    34,    33,     5,    37,    27,    33,    37,    16,
      16,     5,    34,    33,    33,    35,    35,     5,    12,    13,
     147,    51,   141,   147,    12,    13,     3,    33,     5,    35,
       5,    51,    51,     5,   153,   154,    27,    38,    39,    18,
      34,   165,   161,    19,    34,   164,   170,    37,    27,   176,
     177,    33,   176,   177,    33,    33,     3,     4,     5,    89,
      76,     3,   186,     5,   188,    81,    38,    39,    27,    89,
      89,    91,    92,    92,    28,   194,     3,     4,     3,     4,
       5,     6,    76,    89,    91,    34,    92,    81,    76,   108,
     109,    38,    39,    81,    28,    20,    90,    91,    28,    24,
      25,    26,    27,    91,    29,     3,     4,     5,    33,   143,
      18,    19,    35,    38,    39,    18,    18,    18,    28,   139,
     139,    28,    20,   143,    28,    30,   145,   146,     5,   148,
      36,   150,   152,   139,    28,    33,   143,   143,    89,    92,
       3,     4,     5,     3,     4,     5,   152,    91,    13,    -1,
      19,   181,    21,    22,    23,    18,    19,    20,    18,    22,
      20,   181,   181,    26,    27,    28,    29,   165,    31,    32,
      33,    34,   170,    33,    37,    38,    39,    40,    41,    42,
      43,     3,     4,     5,     3,     4,     5,    -1,   186,    -1,
     188,    19,    20,    21,    22,    23,    18,    19,    20,    18,
      22,    20,    -1,    -1,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    -1,    33,    37,    38,    39,    40,    41,
      42,    43,     3,     4,     5,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,     3,     4,     5,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    20,    -1,    -1,    20,    -1,    -1,    -1,    27,    -1,
       3,     4,     5,    20,    33,    -1,    -1,    33,    34,    38,
      39,    28,    38,    39,    -1,    -1,    33,    20,    -1,    -1,
      -1,    38,    39,    22,    -1,    -1,    -1,    -1,    22,    -1,
      33,    -1,    31,    32,    -1,    38,    39,    31,    32,    -1,
      -1,    40,    41,    42,    43,    -1,    40,    41,    42,    43,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    31,    32,    -1,    34,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    28,    -1,    -1,
      31,    32,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    -1,    -1,    31,    32,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    27,
      29,    33,    38,    39,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    58,    59,    60,    65,    66,    67,    68,
      69,    70,    71,    18,    27,    33,     5,    59,    65,    67,
      68,    69,     5,    59,    70,     5,    25,    57,    59,    65,
      70,    27,    57,    65,     5,    18,    19,    20,    22,    26,
      27,    28,    29,    31,    32,    33,    34,    37,    38,    39,
      40,    41,    42,    43,    68,    69,    72,    73,    74,    38,
      39,    72,     0,    46,    19,    20,    21,    22,    23,    18,
      27,    19,    27,    57,    62,    65,    70,     5,    68,    34,
      63,    65,    70,    33,    28,    18,    26,    28,    31,    32,
      18,    57,    65,    34,    34,    38,    73,    39,    66,    66,
      66,    66,    66,    57,    62,    65,    70,     5,    68,     5,
      67,    68,    69,    71,    28,    63,    28,    28,    34,    37,
       5,    34,    64,    35,    61,    18,    18,    61,    18,    65,
      18,    65,    18,    28,    28,    28,    28,    28,    65,    70,
      61,    34,    37,    46,    30,    54,    55,    56,    65,    65,
      54,    56,    65,    65,     5,    70,    61,    61,    61,     5,
      36,    27,    61,    55,    56,    56,    54,    56,    54,    56,
      57,    65,    56,    56,    28,    61
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
      66,    66,    66,    66,    67,    67,    67,    67,    68,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74
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
       3,     3,     3,     3,     1,     1,     1,     2,     1,     2,
       1,     3,     1,     3,     4,     4,     4,     4,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 91 "gram.y"
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
#line 1489 "y.tab.c"
    break;

  case 3:
#line 108 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1499 "y.tab.c"
    break;

  case 4:
#line 113 "gram.y"
    { (yyval.data) = NULL; }
#line 1505 "y.tab.c"
    break;

  case 5:
#line 117 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1513 "y.tab.c"
    break;

  case 6:
#line 120 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1521 "y.tab.c"
    break;

  case 7:
#line 123 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCCALL, (yyvsp[0].data));
    }
#line 1529 "y.tab.c"
    break;

  case 8:
#line 126 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1537 "y.tab.c"
    break;

  case 9:
#line 129 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1545 "y.tab.c"
    break;

  case 10:
#line 132 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_MATH, (yyvsp[0].data));
    }
#line 1553 "y.tab.c"
    break;

  case 11:
#line 135 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_STR, (yyvsp[0].data));
    }
#line 1561 "y.tab.c"
    break;

  case 12:
#line 138 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1569 "y.tab.c"
    break;

  case 13:
#line 141 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1577 "y.tab.c"
    break;

  case 14:
#line 144 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1585 "y.tab.c"
    break;

  case 15:
#line 147 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1593 "y.tab.c"
    break;

  case 16:
#line 151 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1601 "y.tab.c"
    break;

  case 17:
#line 153 "gram.y"
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1609 "y.tab.c"
    break;

  case 18:
#line 157 "gram.y"
    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1617 "y.tab.c"
    break;

  case 19:
#line 161 "gram.y"
    {
    (yyval.data) = NULL;
}
#line 1625 "y.tab.c"
    break;

  case 20:
#line 165 "gram.y"
    {
    (yyval.data) = NULL;
}
#line 1633 "y.tab.c"
    break;

  case 21:
#line 170 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1641 "y.tab.c"
    break;

  case 22:
#line 173 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1653 "y.tab.c"
    break;

  case 23:
#line 180 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1666 "y.tab.c"
    break;

  case 24:
#line 188 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1678 "y.tab.c"
    break;

  case 25:
#line 195 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-2].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[0].data));
    }
#line 1689 "y.tab.c"
    break;

  case 26:
#line 201 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1704 "y.tab.c"
    break;

  case 27:
#line 211 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-4].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1720 "y.tab.c"
    break;

  case 28:
#line 222 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1735 "y.tab.c"
    break;

  case 29:
#line 234 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1743 "y.tab.c"
    break;

  case 30:
#line 237 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1755 "y.tab.c"
    break;

  case 31:
#line 244 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1768 "y.tab.c"
    break;

  case 32:
#line 252 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1780 "y.tab.c"
    break;

  case 33:
#line 259 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-2].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[0].data));
    }
#line 1791 "y.tab.c"
    break;

  case 34:
#line 265 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1806 "y.tab.c"
    break;

  case 35:
#line 275 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-4].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1822 "y.tab.c"
    break;

  case 36:
#line 286 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[-3].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1837 "y.tab.c"
    break;

  case 37:
#line 298 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 1849 "y.tab.c"
    break;

  case 38:
#line 305 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 1857 "y.tab.c"
    break;

  case 39:
#line 310 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 1867 "y.tab.c"
    break;

  case 40:
#line 317 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 1876 "y.tab.c"
    break;

  case 41:
#line 323 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1884 "y.tab.c"
    break;

  case 42:
#line 326 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1892 "y.tab.c"
    break;

  case 43:
#line 329 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1900 "y.tab.c"
    break;

  case 44:
#line 332 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1908 "y.tab.c"
    break;

  case 45:
#line 335 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 1916 "y.tab.c"
    break;

  case 46:
#line 338 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1924 "y.tab.c"
    break;

  case 47:
#line 341 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1932 "y.tab.c"
    break;

  case 48:
#line 346 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 1940 "y.tab.c"
    break;

  case 49:
#line 349 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 1948 "y.tab.c"
    break;

  case 50:
#line 354 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[-3].id),(yyvsp[-1].data));
    }
#line 1956 "y.tab.c"
    break;

  case 51:
#line 357 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[-2].id),NULL);
    }
#line 1964 "y.tab.c"
    break;

  case 52:
#line 362 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 1974 "y.tab.c"
    break;

  case 53:
#line 367 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 1984 "y.tab.c"
    break;

  case 54:
#line 372 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        expr_t *condexpr = newExpr_Cond((yyvsp[0].data));
        (yyval.data) = newDeclaration(idexpr,condexpr);
    }
#line 1994 "y.tab.c"
    break;

  case 55:
#line 377 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2003 "y.tab.c"
    break;

  case 56:
#line 381 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2011 "y.tab.c"
    break;

  case 57:
#line 384 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2019 "y.tab.c"
    break;

  case 58:
#line 387 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2027 "y.tab.c"
    break;

  case 59:
#line 390 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2035 "y.tab.c"
    break;

  case 60:
#line 395 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2043 "y.tab.c"
    break;

  case 61:
#line 400 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2052 "y.tab.c"
    break;

  case 62:
#line 404 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2060 "y.tab.c"
    break;

  case 63:
#line 409 "gram.y"
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2069 "y.tab.c"
    break;

  case 64:
#line 413 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2077 "y.tab.c"
    break;

  case 65:
#line 416 "gram.y"
    {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2086 "y.tab.c"
    break;

  case 66:
#line 420 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2094 "y.tab.c"
    break;

  case 67:
#line 425 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2104 "y.tab.c"
    break;

  case 68:
#line 430 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2113 "y.tab.c"
    break;

  case 69:
#line 436 "gram.y"
    {
        (yyval.data) = newExpr_OPAdd((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2121 "y.tab.c"
    break;

  case 70:
#line 439 "gram.y"
    {
        (yyval.data) = newExpr_OPSub((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2129 "y.tab.c"
    break;

  case 71:
#line 442 "gram.y"
    {
        (yyval.data) = newExpr_OPMul((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2137 "y.tab.c"
    break;

  case 72:
#line 445 "gram.y"
    {
        (yyval.data) = newExpr_OPMod((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2145 "y.tab.c"
    break;

  case 73:
#line 448 "gram.y"
    {
        (yyval.data) = newExpr_OPDiv((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2153 "y.tab.c"
    break;

  case 74:
#line 451 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2161 "y.tab.c"
    break;

  case 75:
#line 456 "gram.y"
    {
        (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 2169 "y.tab.c"
    break;

  case 76:
#line 459 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2177 "y.tab.c"
    break;

  case 77:
#line 462 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[0].data);
        double val = e->fval * -1.0;
        (yyval.data) = newExpr_Float(val);
    }
#line 2187 "y.tab.c"
    break;

  case 78:
#line 467 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2195 "y.tab.c"
    break;

  case 79:
#line 470 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[0].data);
        int val = e->ival * -1;
        (yyval.data) = newExpr_Ival(val);
    }
#line 2205 "y.tab.c"
    break;

  case 80:
#line 475 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2213 "y.tab.c"
    break;

  case 81:
#line 478 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2221 "y.tab.c"
    break;

  case 82:
#line 481 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[0].data));
    }
#line 2229 "y.tab.c"
    break;

  case 83:
#line 484 "gram.y"
    {
        (yyval.data) = newExpr_Cond((yyvsp[-1].data));
    }
#line 2237 "y.tab.c"
    break;

  case 84:
#line 489 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2248 "y.tab.c"
    break;

  case 85:
#line 495 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = newExpr_ID((yyvsp[-1].id));
        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2258 "y.tab.c"
    break;

  case 86:
#line 500 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2266 "y.tab.c"
    break;

  case 87:
#line 503 "gram.y"
    {
      expr_t *index = newExpr_ID((yyvsp[-1].id));
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), index);
    }
#line 2275 "y.tab.c"
    break;

  case 88:
#line 509 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2283 "y.tab.c"
    break;

  case 89:
#line 514 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2291 "y.tab.c"
    break;

  case 90:
#line 519 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2302 "y.tab.c"
    break;

  case 91:
#line 525 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2313 "y.tab.c"
    break;

  case 92:
#line 531 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2327 "y.tab.c"
    break;

  case 93:
#line 540 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2341 "y.tab.c"
    break;

  case 94:
#line 549 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2352 "y.tab.c"
    break;

  case 95:
#line 555 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2360 "y.tab.c"
    break;

  case 96:
#line 560 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2368 "y.tab.c"
    break;

  case 97:
#line 563 "gram.y"
    {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2376 "y.tab.c"
    break;

  case 98:
#line 566 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[0].data));
    }
#line 2384 "y.tab.c"
    break;

  case 99:
#line 569 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2393 "y.tab.c"
    break;

  case 100:
#line 573 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2402 "y.tab.c"
    break;

  case 101:
#line 579 "gram.y"
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
#line 2432 "y.tab.c"
    break;

  case 102:
#line 604 "gram.y"
    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2440 "y.tab.c"
    break;

  case 103:
#line 609 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2448 "y.tab.c"
    break;

  case 104:
#line 612 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2459 "y.tab.c"
    break;

  case 105:
#line 618 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2470 "y.tab.c"
    break;

  case 106:
#line 624 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2478 "y.tab.c"
    break;

  case 107:
#line 629 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2487 "y.tab.c"
    break;

  case 108:
#line 634 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2496 "y.tab.c"
    break;

  case 109:
#line 639 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2505 "y.tab.c"
    break;

  case 110:
#line 643 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2514 "y.tab.c"
    break;

  case 111:
#line 647 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2523 "y.tab.c"
    break;

  case 112:
#line 651 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2532 "y.tab.c"
    break;

  case 113:
#line 655 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2541 "y.tab.c"
    break;

  case 114:
#line 659 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2550 "y.tab.c"
    break;

  case 115:
#line 663 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2559 "y.tab.c"
    break;

  case 116:
#line 667 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2568 "y.tab.c"
    break;

  case 117:
#line 671 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2577 "y.tab.c"
    break;

  case 118:
#line 675 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2586 "y.tab.c"
    break;

  case 119:
#line 679 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2595 "y.tab.c"
    break;

  case 120:
#line 683 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2604 "y.tab.c"
    break;

  case 121:
#line 687 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2613 "y.tab.c"
    break;

  case 122:
#line 691 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2622 "y.tab.c"
    break;

  case 123:
#line 695 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2631 "y.tab.c"
    break;

  case 124:
#line 699 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2640 "y.tab.c"
    break;

  case 125:
#line 703 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2649 "y.tab.c"
    break;


#line 2653 "y.tab.c"

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
#line 708 "gram.y"


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
