/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGIT = 258,
     DOUBLE = 259,
     ID = 260,
     RETURN = 261,
     FOREACH = 262,
     COMMENT = 263,
     NEWLINE = 264
   };
#endif
/* Tokens.  */
#define DIGIT 258
#define DOUBLE 259
#define ID 260
#define RETURN 261
#define FOREACH 262
#define COMMENT 263
#define NEWLINE 264




/* Copy the first part of user declarations.  */
#line 1 "gram.y"


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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "gram.y"
{ int val_int; double val_double; char id[256]; void *data; }
/* Line 193 of yacc.c.  */
#line 154 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 167 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   791

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  310

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   264

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    37,    21,    36,     2,    16,    15,    27,    35,
      18,    19,    13,    11,    34,    12,    17,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    30,
      28,    10,    29,    22,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,    38,    24,    39,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,    26,    33,    25,     2,     2,     2,
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
       5,     6,     7,     8,     9
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    12,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    40,
      41,    44,    47,    50,    58,    67,    70,    72,    75,    77,
      82,    87,    92,    97,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   121,   125,   131,   138,   146,   153,   159,
     166,   174,   181,   184,   186,   192,   195,   201,   203,   209,
     211,   213,   216,   218,   223,   228,   233,   238,   242,   246,
     250,   257,   264,   270,   278,   285,   290,   295,   299,   301,
     306,   310,   316,   323,   327,   332,   337,   342,   347,   352,
     357,   362,   367,   371,   375,   379,   384,   389,   393,   394,
     398,   402,   408,   414,   418,   424,   426,   430,   432,   434,
     437,   439,   442,   447,   452,   457,   462,   466,   469,   472,
     474,   480,   485,   490,   494,   497,   499,   501,   505,   509,
     512,   515,   518,   520,   522,   524,   526,   528,   530,   532,
     534,   536,   538,   540,   542,   544,   546,   548,   550,   552,
     554,   556,   558,   560,   562,   564,   566,   568,   570,   572,
     574,   576,   578,   580,   582,   584,   586
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    46,    44,    43,    -1,    46,
      -1,    -1,    45,    46,    -1,    69,    -1,    65,    -1,    48,
      -1,    53,    -1,    55,    -1,    56,    -1,    51,    -1,    52,
      -1,    50,    -1,    47,    -1,    64,    -1,    46,     9,    -1,
      -1,    16,     5,    -1,    16,    82,    -1,    17,    49,    -1,
      18,    53,     7,     5,    46,    19,    73,    -1,    18,    46,
      53,     7,     5,    46,    19,    73,    -1,     6,    53,    -1,
      20,    -1,    21,    20,    -1,    54,    -1,    53,    11,    46,
      53,    -1,    53,    13,    46,    53,    -1,    53,    12,    46,
      53,    -1,    53,    15,    46,    53,    -1,    53,    14,    46,
      53,    -1,    78,    -1,    77,    -1,    70,    -1,    74,    -1,
      67,    -1,    66,    -1,    82,    -1,     5,    -1,    12,     5,
      -1,    18,    53,    19,    -1,    22,    23,    60,    24,    73,
      -1,    22,    23,    60,    24,    73,    57,    -1,    22,    23,
      60,    24,    73,    57,    59,    -1,    22,    23,    60,    24,
      73,    59,    -1,    17,    23,    60,    24,    73,    -1,    17,
      23,    60,    24,    73,    57,    -1,    17,    23,    60,    24,
      73,    57,    59,    -1,    17,    23,    60,    24,    73,    59,
      -1,    57,    58,    -1,    58,    -1,    25,    23,    60,    24,
      73,    -1,    25,    73,    -1,    60,    26,    26,    46,    61,
      -1,    61,    -1,    61,    27,    27,    46,    62,    -1,    62,
      -1,    63,    -1,    21,    54,    -1,    54,    -1,    53,    10,
      10,    53,    -1,    53,    21,    10,    53,    -1,    53,    28,
      10,    53,    -1,    53,    29,    10,    53,    -1,    53,    28,
      53,    -1,    53,    29,    53,    -1,    18,    63,    19,    -1,
      30,    30,     5,    30,    30,    73,    -1,    20,     5,    18,
      76,    19,    73,    -1,    20,     5,    18,    19,    73,    -1,
      54,    31,    31,     5,    18,    75,    19,    -1,    54,    31,
      31,     5,    18,    19,    -1,    54,    31,    31,     5,    -1,
       5,    18,    75,    19,    -1,     5,    18,    19,    -1,    68,
      -1,    78,    18,    75,    19,    -1,    78,    18,    19,    -1,
       5,    17,     5,    18,    19,    -1,     5,    17,     5,    18,
      75,    19,    -1,     5,    10,    53,    -1,     5,    11,    10,
      53,    -1,     5,    12,    10,    53,    -1,     5,    13,    10,
      53,    -1,     5,    14,    10,    53,    -1,    78,    11,    10,
      53,    -1,    78,    12,    10,    53,    -1,    78,    13,    10,
      53,    -1,    78,    14,    10,    53,    -1,     5,    10,    63,
      -1,    78,    10,    53,    -1,    78,    10,    63,    -1,    32,
      71,    46,    33,    -1,    71,    34,    46,    72,    -1,    46,
      72,    46,    -1,    -1,    82,    31,    54,    -1,    32,    43,
      33,    -1,    23,    46,    75,    46,    24,    -1,    23,    46,
      49,    46,    24,    -1,    23,    46,    24,    -1,    75,    46,
      34,    46,    53,    -1,    53,    -1,    76,    34,     5,    -1,
       5,    -1,    81,    -1,    12,    81,    -1,    80,    -1,    12,
      80,    -1,    54,    23,    53,    24,    -1,    54,    23,    79,
      24,    -1,    78,    23,    53,    24,    -1,    78,    23,    79,
      24,    -1,    54,    31,    54,    -1,    31,    54,    -1,    54,
      31,    -1,    31,    -1,    54,    31,    54,    31,    54,    -1,
      31,    54,    31,    54,    -1,    54,    31,    31,    54,    -1,
      31,    31,    54,    -1,    31,    31,    -1,     3,    -1,     4,
      -1,    35,    83,    35,    -1,    36,    83,    36,    -1,    36,
      36,    -1,    35,    35,    -1,    83,    84,    -1,    84,    -1,
       5,    -1,    81,    -1,    80,    -1,     6,    -1,     7,    -1,
      85,    -1,    11,    -1,    37,    -1,    22,    -1,    28,    -1,
      29,    -1,    12,    -1,    14,    -1,    38,    -1,    31,    -1,
      30,    -1,    18,    -1,    19,    -1,    21,    -1,    34,    -1,
      35,    -1,    36,    -1,    17,    -1,    23,    -1,    24,    -1,
      13,    -1,    39,    -1,    16,    -1,    27,    -1,    26,    -1,
      32,    -1,    33,    -1,    10,    -1,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   114,   119,   120,   123,   128,   131,   134,
     137,   140,   143,   146,   149,   152,   155,   158,   162,   162,
     164,   166,   171,   176,   178,   182,   186,   190,   195,   198,
     204,   210,   216,   222,   230,   233,   236,   239,   242,   245,
     248,   251,   254,   259,   264,   267,   274,   282,   291,   294,
     301,   309,   318,   325,   330,   337,   343,   346,   351,   354,
     359,   362,   367,   372,   375,   378,   381,   384,   387,   390,
     394,   428,   431,   436,   439,   442,   448,   452,   456,   459,
     463,   469,   475,   489,   494,   501,   508,   515,   522,   528,
     534,   540,   546,   551,   554,   559,   564,   571,   574,   579,
     590,   595,   600,   604,   609,   613,   618,   623,   629,   632,
     636,   639,   645,   651,   657,   660,   667,   670,   673,   676,
     679,   682,   685,   688,   691,   696,   709,   714,   717,   720,
     724,   730,   758,   763,   766,   773,   790,   795,   800,   805,
     810,   815,   819,   823,   827,   831,   835,   839,   843,   847,
     851,   855,   859,   863,   867,   871,   875,   879,   883,   887,
     891,   895,   899,   903,   907,   911,   915
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "FOREACH", "COMMENT", "NEWLINE", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'$'", "'.'", "'('", "')'", "'@'", "'!'", "'?'", "'['", "']'",
  "'~'", "'|'", "'&'", "'<'", "'>'", "';'", "':'", "'{'", "'}'", "','",
  "'''", "'\"'", "' '", "'\\\\'", "'^'", "'_'", "$accept", "program",
  "statements", "statement_", "statement", "_", "systemStatement",
  "forEachStatementFull", "forEachStatement", "returnStatement",
  "continueStatement", "breakStatement", "expressions", "expression",
  "ifStatement", "loopStatement", "middleIfs", "middleIf", "endIf",
  "logical_a", "logical_b", "logical_expression", "condition", "class",
  "function", "classFunctionCall", "functionCall",
  "namespacedFunctionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "indexer", "mathContentDigit", "mathContentDouble", "stringContent",
  "stringEditions", "stringEdition", "otherChar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,    43,    45,    42,    47,    37,    36,    46,    40,    41,
      64,    33,    63,    91,    93,   126,   124,    38,    60,    62,
      59,    58,   123,   125,    44,    39,    34,    32,    92,    94,
      95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    51,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    71,    71,    72,
      73,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    81,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     2,     2,     7,     8,     2,     1,     2,     1,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     5,     6,     7,     6,     5,     6,
       7,     6,     2,     1,     5,     2,     5,     1,     5,     1,
       1,     2,     1,     4,     4,     4,     4,     3,     3,     3,
       6,     6,     5,     7,     6,     4,     4,     3,     1,     4,
       3,     5,     6,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     4,     4,     3,     0,     3,
       3,     5,     5,     3,     5,     1,     3,     1,     1,     2,
       1,     2,     4,     4,     4,     4,     3,     2,     2,     1,
       5,     4,     4,     3,     2,     1,     1,     3,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      19,     0,     2,     4,     1,   125,   126,    41,     0,    18,
       0,     0,     0,     0,    26,     0,     0,    19,     0,    19,
       0,     0,    19,    19,    16,     9,    15,    13,    14,    10,
      28,    11,    12,    17,     8,    39,    38,    78,     7,    36,
      37,    35,    34,   110,   108,    40,     0,     0,     0,     0,
       0,     0,     0,    41,    25,    34,    42,   111,   109,    20,
      21,    19,     0,    22,     0,     0,    27,     0,     0,     0,
       0,    19,   133,   136,   137,   165,   139,   144,   158,   145,
     160,   155,   149,   150,   151,   141,   156,   157,   162,   161,
     142,   143,   148,   147,   163,   164,   152,   130,   154,   140,
     146,   159,   166,   135,   134,     0,   132,   138,   153,   129,
       0,     3,     6,    19,    19,    19,    19,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    92,
       0,     0,     0,     0,     0,    77,   105,    19,     0,     0,
       0,     0,    28,     0,    57,    59,    60,    43,     0,     0,
      19,   103,    19,    19,     0,    19,     0,    19,     0,   127,
     131,   128,     0,     0,     0,     0,     0,   119,     0,    28,
       0,     0,    93,    94,     0,     0,     0,     0,    80,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,     0,    76,     0,     0,     0,    61,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,    95,    29,    31,    30,    33,    32,   124,   117,
     112,   118,   113,    75,    88,    89,    90,    91,    79,   114,
     115,    69,     0,     0,     0,    67,     0,    68,    81,    19,
      19,     0,    19,    19,    48,    19,    19,    72,     0,     0,
      44,   102,   101,     0,    99,    96,   123,     0,     0,   116,
       0,    63,    64,    65,    66,    82,     0,    19,     0,     0,
       0,    49,    53,    51,     0,     0,    71,   106,    45,    47,
      70,   121,    75,   122,     0,    74,    19,   104,     0,     0,
     100,     0,    55,    52,    50,    56,    58,    46,     0,   120,
      73,     0,    23,     0,    74,    19,    24,     0,    73,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    22,    23,   194,    24,    25,    63,    26,
      27,    28,   136,    30,    31,    32,   271,   272,   273,   143,
     144,   145,   146,    33,    34,    35,    36,    37,    38,    39,
      71,   155,   244,    40,   137,   203,    41,    55,   170,    43,
      44,    45,   105,   106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -244
static const yytype_int16 yypact[] =
{
      15,    30,  -244,   238,  -244,  -244,  -244,   532,   724,  -244,
     177,     6,    13,   724,    43,    82,    93,  -244,   101,    -1,
     307,   345,     4,  -244,  -244,  -244,  -244,  -244,  -244,   698,
      58,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,   127,  -244,  -244,  -244,   740,   123,   124,   136,
     156,   163,   494,    69,   698,    49,  -244,  -244,  -244,  -244,
    -244,   724,   504,  -244,   207,   152,  -244,   504,   459,   171,
       9,   153,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,   227,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,   383,  -244,  -244,  -244,   481,
     421,  -244,   180,  -244,  -244,  -244,  -244,  -244,   174,   165,
     740,   184,   188,   189,   191,   529,   174,   740,    83,  -244,
     724,   724,   724,   724,   186,  -244,   698,   183,   550,   580,
     724,    83,   222,    44,   181,  -244,  -244,  -244,    21,    79,
     724,  -244,  -244,  -244,   187,  -244,   176,  -244,    16,   227,
    -244,   481,   550,   550,   550,   550,   550,   566,    39,    95,
     192,   229,    83,  -244,   724,   724,   724,   724,  -244,   208,
     200,   211,    63,   213,   230,   241,   600,   610,   698,   698,
     698,   698,   635,  -244,    12,   776,   232,    58,   220,   231,
     235,  -244,   220,    -7,   220,   284,    10,     5,   239,   180,
     724,     9,  -244,   272,   272,  -244,  -244,  -244,   724,   134,
    -244,   645,  -244,   259,   698,   698,   698,   698,  -244,  -244,
    -244,  -244,   724,   724,   724,   698,   724,   698,  -244,   260,
    -244,   277,  -244,   256,   265,  -244,  -244,  -244,   220,   289,
     265,  -244,  -244,   220,    58,  -244,    58,   661,   750,   144,
     682,   698,   698,   698,   698,  -244,   550,  -244,    60,   267,
      24,   265,  -244,  -244,   469,   469,  -244,  -244,   265,  -244,
    -244,    58,   125,    58,   661,  -244,   282,   698,    91,   220,
    -244,   504,  -244,  -244,  -244,   181,  -244,  -244,   703,    58,
    -244,   220,  -244,    96,  -244,   285,  -244,   220,  -244,  -244
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -244,  -244,   -20,  -244,  -244,    38,  -244,  -244,   240,  -244,
    -244,  -244,    -3,    18,  -244,  -244,    56,  -157,  -243,   -66,
      33,    40,   -37,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,   105,  -182,  -244,   -60,  -244,  -244,   319,   201,    -4,
       3,    -8,   311,    59,  -244
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -155
static const yytype_int16 yytable[] =
{
      29,   149,   111,    60,    -5,    54,    57,   279,   153,   129,
      64,    59,   248,    58,     9,    -5,   103,   103,     9,     9,
     247,     9,   250,   104,   104,     9,   201,   249,   294,   252,
       4,    61,   -98,   -98,   251,   297,    62,    -5,     3,   240,
     202,    20,    21,   128,    20,    21,   240,   291,    65,   212,
     113,   114,   115,   116,   117,    68,   243,    70,   139,   141,
       3,   112,   156,   220,   141,   179,   276,   125,   198,     9,
     199,   280,   126,   184,   113,   114,   115,   116,   117,   289,
     142,   118,   147,   173,   185,   142,    51,    52,   292,   119,
     183,   186,   187,   184,   113,   114,   115,   116,   117,   138,
       9,   103,    66,   204,   185,   199,   103,   302,   104,   158,
     301,   186,   187,   104,   293,   168,    67,   172,   118,   306,
     307,   293,   199,   180,   182,   309,   221,   188,   189,   190,
     191,    69,   239,   130,   131,   195,   169,   120,   121,   122,
     123,   124,    51,   298,   169,   125,   132,   205,   -41,   -41,
     126,   162,   163,   164,   165,   166,   -41,   118,   197,   213,
     214,   215,   216,   217,   160,   257,   133,   118,   134,   160,
     148,   224,   225,   226,   227,   284,   154,     5,     6,    53,
       5,     6,    56,   235,   237,   219,    10,   157,   138,     9,
     206,   207,    13,   209,   174,   211,   171,    17,   175,   176,
     286,   177,   193,   156,   192,   167,    19,   210,   200,    20,
      21,   113,   114,   115,   116,   117,   222,   208,   113,   114,
     115,   116,   117,   269,   229,   303,   147,   228,   254,   261,
     262,   263,   231,   264,   223,   230,   256,   242,   305,   259,
     232,     5,     6,     7,     8,   118,   -62,     9,   -62,   -62,
      10,   233,   243,   119,    11,    12,    13,   245,    14,    15,
      16,    17,   246,   287,  -153,  -153,  -153,  -153,    18,   253,
      19,   141,   141,    20,    21,   281,   283,   260,   266,   265,
     268,     3,   267,   274,   275,   115,   116,   117,   141,    -5,
     270,   196,   142,   142,   277,   113,   114,   115,   116,   117,
     290,   300,   299,   147,   308,   288,   278,   295,   152,   142,
       5,     6,    72,    73,    74,   296,   255,    75,    76,    77,
      78,    79,    42,    80,    81,    82,    83,   181,    84,    85,
      86,    87,   110,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     5,     6,
      72,    73,    74,     0,     0,    75,    76,    77,    78,    79,
       0,    80,    81,    82,    83,     0,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     108,   109,    99,   100,   101,   102,     5,     6,    72,    73,
      74,     0,     0,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,     0,    84,    85,    86,    87,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   159,    98,
      99,   100,   101,   102,     5,     6,    72,    73,    74,     0,
       0,    75,    76,    77,    78,    79,     0,    80,    81,    82,
      83,     0,    84,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   108,   161,    99,   100,
     101,   102,     5,     6,    53,     0,     0,     0,     9,     0,
       0,    10,     5,     6,    53,     0,     0,   150,     9,     0,
       0,    10,    17,   151,     0,     0,     0,   127,     0,     0,
     140,    19,    17,     0,    20,    21,     0,     5,     6,    53,
       0,    19,     0,     0,    20,    21,    10,     5,     6,    53,
       0,     0,    13,   135,     0,     0,    10,    17,  -154,  -154,
    -154,  -154,   127,     0,     0,   140,    19,    17,     0,    20,
      21,     0,     5,     6,    53,     0,    19,     0,     0,    20,
      21,    10,    46,    47,    48,    49,    50,    13,   178,    51,
      52,     0,    17,     5,     6,    53,     0,     0,     0,     9,
       0,    19,    10,     0,    20,    21,     0,     0,    13,     5,
       6,    53,     0,    17,     0,     0,     0,     0,    10,     0,
       0,     0,    19,     0,    13,    20,    21,   196,     0,    17,
       0,   113,   114,   115,   116,   117,     0,   218,    19,     0,
       0,    20,    21,     5,     6,    53,     0,     0,     0,     0,
     234,     0,    10,     5,     6,    53,     0,     0,    13,     0,
     236,     0,    10,    17,     0,     0,     0,     0,    13,     0,
       0,     0,    19,    17,     0,    20,    21,     0,     5,     6,
      53,     0,    19,     0,     0,    20,    21,    10,     5,     6,
      53,     0,     0,    13,   238,     0,     0,    10,    17,     0,
       0,     0,     0,    13,     5,     6,    53,    19,    17,     0,
      20,    21,     0,    10,     0,     0,   258,    19,     0,    13,
      20,    21,     0,     0,    17,     5,     6,    53,     0,     0,
       0,     0,   171,    19,    10,     0,    20,    21,     0,     0,
      13,   285,     0,     0,     0,    17,     5,     6,    53,   113,
     114,   115,   116,   117,    19,    10,     0,    20,    21,     0,
       0,    13,   304,     0,     0,     0,    17,     5,     6,    53,
       0,     0,     0,     0,     0,    19,    10,     0,    20,    21,
       0,     0,    13,     5,     6,    53,     0,    17,     0,     0,
       0,     0,    10,     5,     6,   282,    19,     0,   127,    20,
      21,     0,    10,    17,     0,     0,     0,     0,    13,     0,
       0,     0,    19,    17,     0,    20,    21,     0,     0,     0,
       0,     0,    19,   241,     0,    20,    21,   113,   114,   115,
     116,   117
};

static const yytype_int16 yycheck[] =
{
       3,    67,    22,    11,     0,     8,    10,   250,    68,    46,
      13,     5,    19,    10,     9,     0,    20,    21,     9,     9,
     202,     9,   204,    20,    21,     9,     5,    34,   271,    24,
       0,    18,    33,    34,    24,   278,    23,    33,     0,    34,
      19,    35,    36,    46,    35,    36,    34,    23,     5,    33,
      11,    12,    13,    14,    15,    17,    32,    19,    61,    62,
      22,    23,    70,    24,    67,   125,   248,    18,    24,     9,
      26,   253,    23,    10,    11,    12,    13,    14,    15,    19,
      62,    23,    19,   120,    21,    67,    17,    18,   270,    31,
     127,    28,    29,    10,    11,    12,    13,    14,    15,    61,
       9,   105,    20,    24,    21,    26,   110,   289,   105,    71,
      19,    28,    29,   110,   271,   118,    23,   120,    23,   301,
      24,   278,    26,   126,   127,   307,    31,   130,   131,   132,
     133,    30,   192,    10,    10,   138,   118,    10,    11,    12,
      13,    14,    17,    18,   126,    18,    10,   150,    23,    24,
      23,   113,   114,   115,   116,   117,    31,    23,   140,   162,
     163,   164,   165,   166,   105,    31,    10,    23,     5,   110,
      18,   174,   175,   176,   177,    31,     5,     3,     4,     5,
       3,     4,     5,   186,   187,   167,    12,    34,   150,     9,
     152,   153,    18,   155,    10,   157,    31,    23,    10,    10,
     260,    10,    19,   211,    18,    31,    32,    31,    27,    35,
      36,    11,    12,    13,    14,    15,    24,    30,    11,    12,
      13,    14,    15,   243,    24,   291,    19,    19,   210,   232,
     233,   234,    19,   236,     5,    24,   218,     5,   298,   221,
      10,     3,     4,     5,     6,    23,    24,     9,    26,    27,
      12,    10,    32,    31,    16,    17,    18,    26,    20,    21,
      22,    23,    27,   266,    37,    38,    39,    40,    30,    30,
      32,   274,   275,    35,    36,   257,   258,    18,   240,    19,
     242,   243,     5,   245,   246,    13,    14,    15,   291,    33,
      25,     7,   274,   275,     5,    11,    12,    13,    14,    15,
      33,    19,   284,    19,    19,   267,   250,   274,    68,   291,
       3,     4,     5,     6,     7,   275,   211,    10,    11,    12,
      13,    14,     3,    16,    17,    18,    19,   126,    21,    22,
      23,    24,    21,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    12,     3,     4,     5,    -1,    -1,    18,     9,    -1,
      -1,    12,    23,    24,    -1,    -1,    -1,    18,    -1,    -1,
      21,    32,    23,    -1,    35,    36,    -1,     3,     4,     5,
      -1,    32,    -1,    -1,    35,    36,    12,     3,     4,     5,
      -1,    -1,    18,    19,    -1,    -1,    12,    23,    37,    38,
      39,    40,    18,    -1,    -1,    21,    32,    23,    -1,    35,
      36,    -1,     3,     4,     5,    -1,    32,    -1,    -1,    35,
      36,    12,    10,    11,    12,    13,    14,    18,    19,    17,
      18,    -1,    23,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    32,    12,    -1,    35,    36,    -1,    -1,    18,     3,
       4,     5,    -1,    23,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    32,    -1,    18,    35,    36,     7,    -1,    23,
      -1,    11,    12,    13,    14,    15,    -1,    31,    32,    -1,
      -1,    35,    36,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    -1,    12,     3,     4,     5,    -1,    -1,    18,    -1,
      10,    -1,    12,    23,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    32,    23,    -1,    35,    36,    -1,     3,     4,
       5,    -1,    32,    -1,    -1,    35,    36,    12,     3,     4,
       5,    -1,    -1,    18,    19,    -1,    -1,    12,    23,    -1,
      -1,    -1,    -1,    18,     3,     4,     5,    32,    23,    -1,
      35,    36,    -1,    12,    -1,    -1,    31,    32,    -1,    18,
      35,    36,    -1,    -1,    23,     3,     4,     5,    -1,    -1,
      -1,    -1,    31,    32,    12,    -1,    35,    36,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,     3,     4,     5,    11,
      12,    13,    14,    15,    32,    12,    -1,    35,    36,    -1,
      -1,    18,    19,    -1,    -1,    -1,    23,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    32,    12,    -1,    35,    36,
      -1,    -1,    18,     3,     4,     5,    -1,    23,    -1,    -1,
      -1,    -1,    12,     3,     4,     5,    32,    -1,    18,    35,
      36,    -1,    12,    23,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    32,    23,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    32,     7,    -1,    35,    36,    11,    12,    13,
      14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,    46,     0,     3,     4,     5,     6,     9,
      12,    16,    17,    18,    20,    21,    22,    23,    30,    32,
      35,    36,    44,    45,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    64,    65,    66,    67,    68,    69,    70,
      74,    77,    78,    80,    81,    82,    10,    11,    12,    13,
      14,    17,    18,     5,    53,    78,     5,    80,    81,     5,
      82,    18,    23,    49,    53,     5,    20,    23,    46,    30,
      46,    71,     5,     6,     7,    10,    11,    12,    13,    14,
      16,    17,    18,    19,    21,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    80,    81,    83,    84,    85,    35,    36,
      83,    43,    46,    11,    12,    13,    14,    15,    23,    31,
      10,    11,    12,    13,    14,    18,    23,    18,    53,    63,
      10,    10,    10,    10,     5,    19,    53,    75,    46,    53,
      21,    53,    54,    60,    61,    62,    63,    19,    18,    60,
      18,    24,    49,    75,     5,    72,    82,    34,    46,    35,
      84,    36,    46,    46,    46,    46,    46,    31,    53,    54,
      79,    31,    53,    63,    10,    10,    10,    10,    19,    75,
      53,    79,    53,    63,    10,    21,    28,    29,    53,    53,
      53,    53,    18,    19,    46,    53,     7,    54,    24,    26,
      27,     5,    19,    76,    24,    53,    46,    46,    30,    46,
      31,    46,    33,    53,    53,    53,    53,    53,    31,    54,
      24,    31,    24,     5,    53,    53,    53,    53,    19,    24,
      24,    19,    10,    10,    10,    53,    10,    53,    19,    75,
      34,     7,     5,    32,    73,    26,    27,    73,    19,    34,
      73,    24,    24,    30,    54,    72,    54,    31,    31,    54,
      18,    53,    53,    53,    53,    19,    46,     5,    46,    43,
      25,    57,    58,    59,    46,    46,    73,     5,    57,    59,
      73,    54,     5,    54,    31,    19,    75,    53,    46,    19,
      33,    23,    73,    58,    59,    61,    62,    59,    18,    54,
      19,    19,    73,    60,    19,    75,    73,    24,    19,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 97 "gram.y"
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
    break;

  case 3:
#line 114 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(2) - (3)].data);
        stmt->next = (statement_t*)(yyvsp[(3) - (3)].data);
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 4:
#line 119 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 120 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 6:
#line 123 "gram.y"
    {
	(yyval.data) = (yyvsp[(1) - (2)].data);
}
    break;

  case 7:
#line 128 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 131 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 134 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 137 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 140 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 143 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 146 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 149 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 152 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 155 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 17:
#line 158 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 18:
#line 162 "gram.y"
    {}
    break;

  case 19:
#line 162 "gram.y"
    {}
    break;

  case 20:
#line 164 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 21:
#line 166 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 22:
#line 171 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 23:
#line 176 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(2) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(7) - (7)].data));
}
    break;

  case 24:
#line 178 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(3) - (8)].data), (yyvsp[(5) - (8)].id), (yyvsp[(8) - (8)].data));
}
    break;

  case 25:
#line 182 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 26:
#line 186 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 27:
#line 190 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 28:
#line 195 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 29:
#line 198 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 30:
#line 204 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 31:
#line 210 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
    break;

  case 32:
#line 216 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
    break;

  case 33:
#line 222 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
    break;

  case 34:
#line 230 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 35:
#line 233 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 36:
#line 236 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 37:
#line 239 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 38:
#line 242 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 39:
#line 245 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 40:
#line 248 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 41:
#line 251 "gram.y"
    {
      (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 42:
#line 254 "gram.y"
    {
      expr_t *id = newExpr_ID((yyvsp[(2) - (2)].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
    }
    break;

  case 43:
#line 259 "gram.y"
    {
      (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 44:
#line 264 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 45:
#line 267 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 46:
#line 274 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 47:
#line 282 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 48:
#line 291 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 49:
#line 294 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 50:
#line 301 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 51:
#line 309 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);

        (yyval.data) = ifs;
    }
    break;

  case 52:
#line 318 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 53:
#line 325 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 54:
#line 330 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 55:
#line 337 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 56:
#line 343 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (5)].data), NULL, (yyvsp[(5) - (5)].data));
    }
    break;

  case 57:
#line 346 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 58:
#line 351 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(5) - (5)].data), (yyvsp[(1) - (5)].data), NULL);
    }
    break;

  case 59:
#line 354 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 60:
#line 359 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 61:
#line 362 "gram.y"
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[(2) - (2)].data));
        (yyval.data) = cond;
    }
    break;

  case 62:
#line 367 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 63:
#line 372 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 64:
#line 375 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 65:
#line 378 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 66:
#line 381 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 67:
#line 384 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 68:
#line 387 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 69:
#line 390 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 70:
#line 394 "gram.y"
    {
    /* Only declarations allowed */
    body_t *bod = (yyvsp[(6) - (6)].data);
    statement_t *walk = bod->content;
    while ( walk != NULL ) {
        if (
            walk->entity != LANG_ENTITY_DECL &&
            walk->entity != LANG_ENTITY_FUNCDECL &&
            walk->entity != LANG_ENTITY_BODY &&
            walk->entity != LANG_ENTITY_BODY_END
        ) {
            fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[(3) - (6)].id));
            fprintf(stderr, "  You may only have variable and or function declaration statements here.\r\n");
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, (yyvsp[(3) - (6)].id)) == 0 ) {
                if ( funcDef->params != NULL ) {
                    fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[(3) - (6)].id));
                    fprintf(stderr, "  You may not define a constructor with function parameters.\r\n");
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    (yyval.data) = newClass((yyvsp[(3) - (6)].id), bod);
}
    break;

  case 71:
#line 428 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 72:
#line 431 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 73:
#line 436 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(6) - (7)].data));
    }
    break;

  case 74:
#line 439 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (6)].data), (yyvsp[(4) - (6)].id), NULL);
    }
    break;

  case 75:
#line 442 "gram.y"
    {
        (yyval.data) = newClassAccesser((yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].id));
    }
    break;

  case 76:
#line 448 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 77:
#line 452 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 78:
#line 456 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 79:
#line 459 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (4)].data);
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 80:
#line 463 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (3)].data);
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 81:
#line 469 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(3) - (5)].id));
        expr_t *expr = newExpr_ID((yyvsp[(1) - (5)].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
    break;

  case 82:
#line 475 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(3) - (6)].id));
        expr_t *expr = newExpr_ID((yyvsp[(1) - (6)].id));
        argsList_t *args = newArgument(expr, NULL);
        argsList_t *walk = (yyvsp[(5) - (6)].data);
        walk->length += 1;
        while ( walk->next != NULL ) {
          walk = walk->next;
        }
        walk->next = args;
        (yyval.data) = newFunCall(id, (yyvsp[(5) - (6)].data));
    }
    break;

  case 83:
#line 489 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 84:
#line 494 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 85:
#line 501 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 86:
#line 508 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 87:
#line 515 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 88:
#line 522 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 89:
#line 528 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 90:
#line 534 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 91:
#line 540 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 92:
#line 546 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 93:
#line 551 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 94:
#line 554 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 95:
#line 559 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(2) - (4)].data));
    }
    break;

  case 96:
#line 564 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (4)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(4) - (4)].data);

      right->next = left;
      (yyval.data) = right;
    }
    break;

  case 97:
#line 571 "gram.y"
    {
      (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 98:
#line 574 "gram.y"
    {
        (yyval.data) = NULL;
    }
    break;

  case 99:
#line 579 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 100:
#line 590 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 101:
#line 595 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(3) - (5)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 102:
#line 600 "gram.y"
    {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(3) - (5)].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
    break;

  case 103:
#line 604 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 104:
#line 609 "gram.y"
    {
        expr_t *expr = (yyvsp[(5) - (5)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (5)].data));
    }
    break;

  case 105:
#line 613 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 106:
#line 618 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 107:
#line 623 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 108:
#line 629 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 109:
#line 632 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 110:
#line 636 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 111:
#line 639 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 112:
#line 645 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 113:
#line 651 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 114:
#line 657 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 115:
#line 660 "gram.y"
    {
      expr_t *id = (yyvsp[(1) - (4)].data);
      expr_t *index = (yyvsp[(3) - (4)].data);
      (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 116:
#line 667 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data), NULL);
  }
    break;

  case 117:
#line 670 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (2)].data), NULL);
  }
    break;

  case 118:
#line 673 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (2)].data), NULL, NULL);
  }
    break;

  case 119:
#line 676 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 120:
#line 679 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
  }
    break;

  case 121:
#line 682 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
  }
    break;

  case 122:
#line 685 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
  }
    break;

  case 123:
#line 688 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[(3) - (3)].data));
  }
    break;

  case 124:
#line 691 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 125:
#line 696 "gram.y"
    {
      if ( strlen(yyval.id) >= 10 ) {
        (yyval.data) = newExpr_BigIntFromStr(yyval.id);
      } else {
        if ( yyval.id[0] == '0' && strlen(yyval.id) > 1 ) {
          (yyval.data) = newExpr_Text(yyval.id);
        } else {
          (yyval.data) = newExpr_Ival(atoi(yyval.id));
        }
      }
    }
    break;

  case 126:
#line 709 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 127:
#line 714 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 128:
#line 717 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 129:
#line 720 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 130:
#line 724 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 131:
#line 730 "gram.y"
    {
        char *textBuffer;

        expr_t *e1 = (expr_t*)(yyvsp[(1) - (2)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(2) - (2)].data);

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
    break;

  case 132:
#line 758 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 133:
#line 763 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 134:
#line 766 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 135:
#line 773 "gram.y"
    {
        char buffer[256];
        expr_t *d = (expr_t*)(yyvsp[(1) - (1)].data);
        if ( d->type == EXPR_TYPE_IVAL ) {
          snprintf(buffer, sizeof(buffer), "%d", d->ival);
        } else if ( d->type == EXPR_TYPE_BIGINT ) {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *d->bigInt);
          snprintf(buffer, sizeof(buffer), "%s", c);
        } else if ( d->type == EXPR_TYPE_TEXT ) {
          snprintf(buffer, sizeof(buffer), "%s", d->text);
        }
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 136:
#line 790 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 137:
#line 795 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 138:
#line 800 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 139:
#line 805 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 140:
#line 810 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 141:
#line 815 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 142:
#line 819 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 143:
#line 823 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 144:
#line 827 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 145:
#line 831 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 146:
#line 835 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 147:
#line 839 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 148:
#line 843 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 149:
#line 847 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 150:
#line 851 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 151:
#line 855 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 152:
#line 859 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 153:
#line 863 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 154:
#line 867 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 155:
#line 871 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 156:
#line 875 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 157:
#line 879 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 158:
#line 883 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 159:
#line 887 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 160:
#line 891 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 161:
#line 895 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 162:
#line 899 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 163:
#line 903 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 164:
#line 907 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 165:
#line 911 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 166:
#line 915 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3144 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 920 "gram.y"


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

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, int stacksize, int heapsize, const char *prompt) {
    char lineBuffer[256];

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    printf("%s", prompt);
    while ( fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL ) {
        YY_BUFFER_STATE buffer;

        /* Check if the user wants to quit */
        if ( strstr(lineBuffer, "quit") != NULL ) {
            func(argc, argv, NULL, 1, stacksize, heapsize);
            return;
        }

        /* Parse from read line */
        buffer = yy_scan_string(lineBuffer);
        yyparse();
        yy_delete_buffer(buffer);

        if ( root != NULL ) {
            func(argc, argv, root, 0, stacksize, heapsize);
        }

        printf("%s", prompt);
        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}


void runCommand(int argc, char *argv[], interactiveInterpreterFunc func, char *command, int stacksize, int heapsize) {
    YY_BUFFER_STATE buffer;

    /* Parse from provided command line */
    buffer = yy_scan_string(command);
    yyparse();
    yy_delete_buffer(buffer);

    if ( root != NULL ) {
        func(argc, argv, root, 0, stacksize, heapsize);
    }
}

