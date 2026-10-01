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
#define YYLSP_NEEDED 1



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
     MEMBER = 264,
     ADD_ASSIGN = 265,
     SUB_ASSIGN = 266,
     MUL_ASSIGN = 267,
     DIV_ASSIGN = 268,
     NEWLINE = 269,
     QUOTED_CHAR = 270,
     STATEMENT_END = 271,
     ATOM = 272
   };
#endif
/* Tokens.  */
#define DIGIT 258
#define DOUBLE 259
#define ID 260
#define RETURN 261
#define FOREACH 262
#define COMMENT 263
#define MEMBER 264
#define ADD_ASSIGN 265
#define SUB_ASSIGN 266
#define MUL_ASSIGN 267
#define DIV_ASSIGN 268
#define NEWLINE 269
#define QUOTED_CHAR 270
#define STATEMENT_END 271
#define ATOM 272




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

void yyerror(const char *s);

#define SOURCE_LOCATION(loc) ((source_location_t){sourceFile(ParsedFile), \
  (loc).first_line, (loc).first_column, (loc).last_line, (loc).last_column})

static statement_t *sourceStatement(int type, void *content, source_location_t location) {
    statement_t *stmt = newStatement(type, content);
    stmt->location = location;
    stmt->file = location.file;
    stmt->line = location.first_line;
    return stmt;
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
#line 47 "gram.y"
{ int val_int; double val_double; char id[256]; void *data; }
/* Line 193 of yacc.c.  */
#line 174 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 199 "y.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   706

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    45,    28,    44,     2,    29,    22,    36,    43,
      24,    30,    20,    18,    42,    19,    26,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,    39,
      37,    17,    38,    32,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,    46,    33,    47,    48,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    35,    41,    34,     2,     2,     2,
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
      15,    16,    23
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    36,    37,    40,
      43,    46,    55,    58,    60,    63,    65,    70,    75,    80,
      85,    90,    92,    94,   100,   107,   115,   122,   128,   135,
     143,   150,   153,   155,   161,   164,   170,   172,   178,   180,
     182,   185,   187,   192,   197,   202,   207,   211,   215,   220,
     227,   234,   240,   247,   253,   257,   262,   266,   268,   273,
     277,   283,   290,   294,   298,   302,   306,   310,   314,   318,
     322,   326,   330,   334,   338,   343,   349,   352,   353,   357,
     361,   367,   373,   377,   383,   385,   389,   391,   393,   396,
     398,   401,   406,   411,   413,   415,   417,   419,   421,   423,
     425,   428,   433,   437,   440,   443,   445,   451,   456,   460,
     463,   465,   467,   469,   473,   477,   480,   483,   486,   488,
     490,   492,   494,   496,   498,   500,   502,   504,   506,   508,
     510,   512,   514,   516,   518,   520,   522,   524,   526,   528,
     530,   532,   534,   536,   538,   540,   542,   544,   546,   548,
     550,   552
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    53,    52,    51,    -1,    53,
      -1,    76,    -1,    72,    -1,    55,    -1,    60,    -1,    62,
      -1,    63,    -1,    58,    -1,    59,    -1,    57,    -1,    54,
      -1,    71,    -1,    53,    14,    -1,    -1,    29,     5,    -1,
      29,    90,    -1,    26,    56,    -1,    24,    53,    60,     7,
       5,    53,    30,    80,    -1,     6,    60,    -1,    31,    -1,
      28,    31,    -1,    61,    -1,    60,    18,    53,    60,    -1,
      60,    20,    53,    60,    -1,    60,    19,    53,    60,    -1,
      60,    22,    53,    60,    -1,    60,    21,    53,    60,    -1,
      86,    -1,    73,    -1,    32,    25,    67,    33,    80,    -1,
      32,    25,    67,    33,    80,    64,    -1,    32,    25,    67,
      33,    80,    64,    66,    -1,    32,    25,    67,    33,    80,
      66,    -1,    26,    25,    67,    33,    80,    -1,    26,    25,
      67,    33,    80,    64,    -1,    26,    25,    67,    33,    80,
      64,    66,    -1,    26,    25,    67,    33,    80,    66,    -1,
      64,    65,    -1,    65,    -1,    34,    25,    67,    33,    80,
      -1,    34,    80,    -1,    67,    35,    35,    53,    68,    -1,
      68,    -1,    68,    36,    36,    53,    69,    -1,    69,    -1,
      70,    -1,    28,    61,    -1,    61,    -1,    60,    17,    17,
      60,    -1,    60,    28,    17,    60,    -1,    60,    37,    17,
      60,    -1,    60,    38,    17,    60,    -1,    60,    37,    60,
      -1,    60,    38,    60,    -1,    24,    53,    70,    30,    -1,
      39,    39,     5,    39,    39,    80,    -1,    31,     5,    24,
      83,    30,    80,    -1,    31,     5,    24,    30,    80,    -1,
      61,     9,     5,    24,    82,    30,    -1,    61,     9,     5,
      24,    30,    -1,    61,     9,     5,    -1,     5,    24,    82,
      30,    -1,     5,    24,    30,    -1,    75,    -1,    85,    24,
      82,    30,    -1,    85,    24,    30,    -1,     5,    26,     5,
      24,    30,    -1,     5,    26,     5,    24,    82,    30,    -1,
       5,    17,    60,    -1,     5,    10,    60,    -1,     5,    11,
      60,    -1,     5,    12,    60,    -1,     5,    13,    60,    -1,
      85,    10,    60,    -1,    85,    11,    60,    -1,    85,    12,
      60,    -1,    85,    13,    60,    -1,     5,    17,    70,    -1,
      85,    17,    60,    -1,    85,    17,    70,    -1,    40,    53,
      78,    41,    -1,    78,    42,    53,    79,    53,    -1,    79,
      53,    -1,    -1,    90,    27,    61,    -1,    40,    51,    41,
      -1,    25,    53,    82,    53,    33,    -1,    25,    53,    56,
      53,    33,    -1,    25,    53,    33,    -1,    82,    53,    42,
      53,    60,    -1,    60,    -1,    83,    42,     5,    -1,     5,
      -1,    89,    -1,    19,    89,    -1,    88,    -1,    19,    88,
      -1,    61,    25,    60,    33,    -1,    61,    25,    87,    33,
      -1,    85,    -1,    84,    -1,    77,    -1,    81,    -1,    74,
      -1,    90,    -1,     5,    -1,    19,     5,    -1,    24,    53,
      60,    30,    -1,    86,    27,    86,    -1,    27,    86,    -1,
      86,    27,    -1,    27,    -1,    86,    27,    86,    27,    86,
      -1,    27,    86,    27,    86,    -1,    86,     9,    86,    -1,
       9,    86,    -1,     9,    -1,     3,    -1,     4,    -1,    43,
      91,    43,    -1,    44,    91,    44,    -1,    44,    44,    -1,
      43,    43,    -1,    91,    92,    -1,    92,    -1,     5,    -1,
      89,    -1,    88,    -1,     6,    -1,     7,    -1,    93,    -1,
      18,    -1,    45,    -1,    32,    -1,    37,    -1,    38,    -1,
      19,    -1,    21,    -1,    46,    -1,    27,    -1,    39,    -1,
      24,    -1,    30,    -1,    28,    -1,    42,    -1,    15,    -1,
      26,    -1,    25,    -1,    33,    -1,    20,    -1,    47,    -1,
      29,    -1,    36,    -1,    35,    -1,    40,    -1,    41,    -1,
      17,    -1,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   129,   134,   138,   141,   144,   147,   150,
     153,   156,   159,   162,   165,   168,   172,   172,   174,   176,
     181,   186,   190,   194,   198,   203,   206,   213,   220,   227,
     234,   243,   244,   248,   251,   258,   266,   275,   278,   285,
     293,   302,   309,   314,   321,   327,   331,   336,   340,   345,
     348,   354,   359,   363,   367,   371,   375,   379,   383,   387,
     421,   424,   429,   433,   437,   444,   449,   454,   457,   462,
     469,   476,   491,   496,   503,   510,   517,   524,   530,   536,
     542,   548,   553,   556,   561,   567,   574,   577,   582,   593,
     598,   604,   609,   615,   619,   624,   629,   635,   638,   643,
     646,   653,   660,   672,   675,   678,   681,   684,   687,   690,
     694,   700,   705,   709,   713,   717,   721,   725,   729,   733,
     737,   743,   757,   763,   766,   769,   774,   781,   810,   815,
     819,   827,   845,   851,   857,   863,   868,   873,   877,   881,
     885,   889,   893,   897,   901,   905,   909,   913,   917,   921,
     924,   928,   932,   936,   940,   944,   948,   952,   956,   960,
     964,   968
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "FOREACH", "COMMENT", "MEMBER", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "NEWLINE", "QUOTED_CHAR", "STATEMENT_END", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "ATOM", "'('", "'['", "'.'", "':'", "'!'",
  "'$'", "')'", "'@'", "'?'", "']'", "'~'", "'|'", "'&'", "'<'", "'>'",
  "';'", "'{'", "'}'", "','", "'''", "'\"'", "' '", "'\\\\'", "'^'", "'_'",
  "$accept", "program", "statements", "statement", "_", "systemStatement",
  "forEachStatementFull", "forEachStatement", "returnStatement",
  "continueStatement", "breakStatement", "expressions", "expression",
  "ifStatement", "loopStatement", "middleIfs", "middleIf", "endIf",
  "logical_a", "logical_b", "logical_expression", "condition", "class",
  "function", "classFunctionCall", "functionCall",
  "namespacedFunctionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "primaryExpression", "indexer", "mathContentDigit", "mathContentDouble",
  "stringContent", "stringEditions", "stringEdition", "otherChar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    61,    43,    45,
      42,    47,    37,   272,    40,    91,    46,    58,    33,    36,
      41,    64,    63,    93,   126,   124,    38,    60,    62,    59,
     123,   125,    44,    39,    34,    32,    92,    94,    95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      55,    56,    57,    58,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    63,
      63,    64,    64,    65,    66,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    78,    78,    78,    79,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    89,    90,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     2,
       2,     8,     2,     1,     2,     1,     4,     4,     4,     4,
       4,     1,     1,     5,     6,     7,     6,     5,     6,     7,
       6,     2,     1,     5,     2,     5,     1,     5,     1,     1,
       2,     1,     4,     4,     4,     4,     3,     3,     4,     6,
       6,     5,     6,     5,     3,     4,     3,     1,     4,     3,
       5,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     5,     2,     0,     3,     3,
       5,     5,     3,     5,     1,     3,     1,     1,     2,     1,
       2,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     2,     2,     1,     5,     4,     3,     2,
       1,     1,     1,     3,     3,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     2,     4,     1,   121,   122,   109,     0,    16,
       0,    17,    17,     0,     0,     0,    23,     0,     0,    17,
       0,     0,    17,    14,     7,    13,    11,    12,     8,    25,
       9,    10,    15,     6,    32,   107,    67,     5,   105,   106,
     104,   103,    31,    99,    97,   108,     0,     0,     0,     0,
       0,     0,     0,   109,    22,   103,   110,   100,    98,     0,
       0,    17,     0,    20,    24,    18,    19,     0,     0,     0,
      87,   129,   132,   133,   149,   160,   135,   140,   153,   141,
     145,   151,   150,   143,   147,   155,   146,   137,   152,   157,
     156,   138,   139,   144,   158,   159,   148,   126,   136,   142,
     154,   161,   131,   130,     0,   128,   134,   125,     0,     3,
      17,    17,    17,    17,    17,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    17,    72,    81,
      66,    94,    17,     0,     0,    17,    92,    17,    17,     0,
       0,     0,    25,     0,    46,    48,    49,     0,     0,     0,
       0,    17,     0,   123,   127,   124,     0,     0,     0,     0,
       0,    64,   120,   115,     0,    31,     0,    77,    78,    79,
      80,    82,    83,    69,    17,     0,     0,     0,     0,     0,
      65,     0,     0,   111,     0,     0,     0,     0,    50,     0,
       0,     0,    96,     0,     0,     0,     0,    84,    17,    86,
       0,    26,    28,    27,    30,    29,     0,     0,    31,    31,
     101,     0,   114,   102,    68,     0,     0,     0,     0,     0,
      56,     0,    57,    17,    70,    17,     0,    91,    90,     0,
      17,    37,    17,    17,    61,     0,     0,    33,     0,     0,
      88,    63,    17,     0,    31,    31,    58,    52,    53,    54,
      55,     0,    71,    17,     0,     0,    38,    42,    40,     0,
       0,    60,    95,    34,    36,    59,    17,    62,    31,     0,
      93,     0,    89,     0,    44,    41,    39,    45,    47,    35,
      85,    31,     0,     0,    21,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    22,   181,    23,    24,    63,    25,    26,
      27,   131,    29,    30,    31,   256,   257,   258,   143,   144,
     145,   146,    32,    33,    34,    35,    36,    37,    38,   150,
     151,   231,    39,   132,   194,    40,    55,    42,   166,    43,
      44,    45,   104,   105,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -194
static const yytype_int16 yypact[] =
{
    -194,    15,  -194,   159,  -194,  -194,  -194,   212,   611,  -194,
     101,  -194,  -194,    65,    19,    11,    20,    67,    54,  -194,
     262,   308,  -194,  -194,  -194,  -194,  -194,  -194,   240,     2,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,   261,  -194,  -194,  -194,  -194,   611,   611,   611,   611,
     637,   497,    95,    53,   240,    85,  -194,  -194,  -194,   514,
     446,  -194,   463,  -194,  -194,  -194,  -194,    88,   463,   114,
      -6,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,   354,  -194,  -194,  -194,   400,  -194,
    -194,  -194,  -194,  -194,  -194,   127,   453,   611,   611,   611,
     611,   637,   506,   240,   240,   240,   240,  -194,   668,  -194,
    -194,   240,    97,   115,   300,  -194,  -194,  -194,  -194,   514,
     611,   668,    51,    -9,   104,  -194,  -194,    18,    47,   107,
      93,  -194,   124,  -194,  -194,  -194,   514,   514,   514,   514,
     514,   125,   611,   611,    77,     8,   119,   240,   240,   240,
     240,   668,  -194,  -194,   128,   548,   143,   149,   560,   577,
    -194,    -2,   594,  -194,   514,     0,    25,   232,     2,   129,
     132,   134,  -194,   129,    31,   129,   135,  -194,  -194,   157,
     611,   122,   122,  -194,  -194,  -194,   603,     2,   144,    42,
    -194,   611,   611,  -194,  -194,   646,   156,   611,   611,   611,
     240,   611,   240,  -194,  -194,   162,   175,  -194,  -194,   184,
    -194,   166,  -194,  -194,  -194,   129,   196,   166,   129,    -6,
       2,  -194,   174,   611,   173,    45,  -194,   240,   240,   240,
     240,   514,  -194,  -194,   169,   -12,   166,  -194,  -194,   480,
     480,  -194,  -194,   166,  -194,  -194,  -194,  -194,   180,   611,
     240,     4,  -194,   463,  -194,  -194,  -194,   104,  -194,  -194,
     157,   186,   129,    50,  -194,   129,  -194
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,   -21,  -194,    10,  -194,  -194,   147,  -194,  -194,
    -194,    -3,   -32,  -194,  -194,   -20,  -193,  -175,   -61,   -39,
     -30,   -47,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
     -18,  -144,  -194,   -56,  -194,  -194,   228,  -110,  -194,    -1,
      21,   -13,   211,   -40,  -194
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const yytype_int16 yytable[] =
{
      28,   109,    66,   129,   138,    54,   165,   148,     9,    57,
       3,   115,     9,   273,     9,     4,    65,   211,     9,   102,
     102,    59,    60,   192,   189,    67,   190,   116,   230,    70,
     142,    58,     3,   227,   282,   212,   142,    20,    21,     9,
     223,   103,   103,   123,   124,   125,   126,   128,   193,   234,
      64,   237,   208,   209,    20,    21,   134,   152,   228,   141,
     115,   235,   264,   275,   154,   141,   174,   223,   154,   243,
     275,   139,   269,   236,   172,  -113,   116,    51,  -112,    52,
     195,   276,   190,   285,   -51,   190,   -51,   -51,   279,    61,
      62,   261,    68,    69,   265,   110,   111,   112,   113,   114,
     133,   244,   245,   102,     5,     6,    56,   102,   188,   122,
     210,   274,   147,   164,   167,   168,   169,   170,   171,   149,
     156,   157,   158,   159,   160,   103,   225,   180,   216,   103,
     207,   207,   161,   268,   197,   198,   187,   175,   284,   182,
     191,   286,   112,   113,   114,   184,   196,   185,   186,   206,
     242,   200,   213,   201,   202,   203,   204,   205,   214,   281,
     217,   199,     5,     6,     7,     8,   218,   232,   240,   230,
     233,     9,   215,     9,   238,   220,   222,  -119,    10,   207,
     207,   226,   229,    11,    12,    13,   246,    14,    15,   253,
      16,    17,   252,   110,   111,   112,   113,   114,    18,    19,
     255,   262,    20,    21,   267,   183,  -118,   137,   239,   254,
     272,   207,   283,  -117,   247,   248,   249,   263,   250,  -116,
     277,   266,    46,    47,    48,    49,   152,   142,   142,    50,
     278,    41,   108,   251,     0,     0,    51,   207,    52,   229,
       3,   142,   259,   260,     0,     0,     0,     0,   270,     0,
     110,   111,   112,   113,   114,     0,   141,   141,   110,   111,
     112,   113,   114,   271,     0,     5,     6,    71,    72,    73,
     141,   117,   118,   119,   120,     0,   280,    74,   121,    75,
      76,    77,    78,    79,     0,   122,    80,    81,    82,    83,
      84,    85,    86,     0,    87,    88,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,    99,   100,
     101,     5,     6,    71,    72,    73,     0,     0,   110,   111,
     112,   113,   114,    74,     0,    75,    76,    77,    78,    79,
     183,     0,    80,    81,    82,    83,    84,    85,    86,     0,
      87,    88,     0,    89,    90,    91,    92,    93,    94,    95,
      96,     0,   107,    98,    99,   100,   101,     5,     6,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,    74,
       0,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,    87,    88,     0,    89,
      90,    91,    92,    93,    94,    95,    96,   153,     0,    98,
      99,   100,   101,     5,     6,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,    87,    88,     0,    89,    90,    91,    92,    93,
      94,    95,    96,     0,   155,    98,    99,   100,   101,     5,
       6,    53,     0,     0,     0,     0,     5,     6,    53,     0,
       9,     0,   162,     0,     0,    10,     5,     6,    53,     0,
     135,    12,    10,     0,     0,     0,     0,    11,    12,   136,
     163,     0,    10,     5,     6,    53,    19,   127,    12,    20,
      21,   140,     0,    19,     9,     0,    20,    21,     0,    10,
       5,     6,    53,    19,   127,    12,    20,    21,   140,     5,
       6,    53,     0,     0,     0,     0,    10,     5,     6,    53,
      19,    11,    12,    20,    21,    10,     0,   130,     9,     0,
      11,    12,     0,    10,     0,     0,   173,    19,    11,    12,
      20,    21,     0,     0,     0,     0,    19,     0,     0,    20,
      21,     5,     6,    53,    19,     0,     0,    20,    21,     0,
       0,     0,     9,     5,     6,    53,     0,    10,     0,     0,
       0,     0,   127,    12,     0,     0,     0,   219,     0,    10,
       5,     6,    53,     0,    11,    12,     0,     0,    19,     0,
       0,    20,    21,     0,   221,     0,    10,     5,     6,    53,
      19,    11,    12,    20,    21,     0,     5,     6,    53,     0,
       0,     0,     0,    10,     5,     6,    53,    19,    11,    12,
      20,    21,    10,     0,   224,     0,     0,    11,    12,     0,
      10,     0,     0,   241,    19,    11,    12,    20,    21,     0,
       5,     6,    53,    19,     0,     0,    20,    21,     0,     0,
       0,    19,     0,     0,    20,    21,    10,     0,     0,     0,
       0,   127,    12,   176,   110,   111,   112,   113,   114,     0,
       0,     0,     0,     0,   177,     0,   183,    19,     0,     0,
      20,    21,     0,   178,   179,   176,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179
};

static const yytype_int16 yycheck[] =
{
       3,    22,    15,    50,    60,     8,   116,    68,    14,    10,
       0,     9,    14,    25,    14,     0,     5,     9,    14,    20,
      21,    11,    12,     5,    33,     5,    35,    25,    40,    19,
      62,    10,    22,    33,    30,    27,    68,    43,    44,    14,
      42,    20,    21,    46,    47,    48,    49,    50,    30,   193,
      31,   195,   162,   163,    43,    44,    59,    70,    33,    62,
       9,    30,   237,   256,   104,    68,   122,    42,   108,    27,
     263,    61,    27,    42,   121,    33,    25,    24,    33,    26,
      33,   256,    35,    33,    33,    35,    35,    36,   263,    24,
      25,   235,    25,    39,   238,    18,    19,    20,    21,    22,
       5,   211,   212,   104,     3,     4,     5,   108,   140,    24,
      33,   255,    24,   116,   117,   118,   119,   120,   121,     5,
     110,   111,   112,   113,   114,   104,   182,    30,   175,   108,
     162,   163,     5,   243,    41,    42,   139,   127,   282,    24,
      36,   285,    20,    21,    22,   135,    39,   137,   138,    24,
     206,    27,    33,   156,   157,   158,   159,   160,    30,   269,
      17,   151,     3,     4,     5,     6,    17,    35,   200,    40,
      36,    14,   175,    14,    39,   178,   179,    33,    19,   211,
     212,   184,     7,    24,    25,    26,    30,    28,    29,     5,
      31,    32,    30,    18,    19,    20,    21,    22,    39,    40,
      34,     5,    43,    44,    30,    30,    33,    60,   198,   230,
      41,   243,   273,    33,   217,   218,   219,   237,   221,    33,
     259,   239,    10,    11,    12,    13,   239,   259,   260,    17,
     260,     3,    21,   223,    -1,    -1,    24,   269,    26,     7,
     230,   273,   232,   233,    -1,    -1,    -1,    -1,   251,    -1,
      18,    19,    20,    21,    22,    -1,   259,   260,    18,    19,
      20,    21,    22,   253,    -1,     3,     4,     5,     6,     7,
     273,    10,    11,    12,    13,    -1,   266,    15,    17,    17,
      18,    19,    20,    21,    -1,    24,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,     3,     4,     5,     6,     7,    -1,    -1,    18,    19,
      20,    21,    22,    15,    -1,    17,    18,    19,    20,    21,
      30,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    19,    20,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    48,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,     3,
       4,     5,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      14,    -1,     9,    -1,    -1,    19,     3,     4,     5,    -1,
      24,    25,    19,    -1,    -1,    -1,    -1,    24,    25,    33,
      27,    -1,    19,     3,     4,     5,    40,    24,    25,    43,
      44,    28,    -1,    40,    14,    -1,    43,    44,    -1,    19,
       3,     4,     5,    40,    24,    25,    43,    44,    28,     3,
       4,     5,    -1,    -1,    -1,    -1,    19,     3,     4,     5,
      40,    24,    25,    43,    44,    19,    -1,    30,    14,    -1,
      24,    25,    -1,    19,    -1,    -1,    30,    40,    24,    25,
      43,    44,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,
      44,     3,     4,     5,    40,    -1,    -1,    43,    44,    -1,
      -1,    -1,    14,     3,     4,     5,    -1,    19,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    17,    -1,    19,
       3,     4,     5,    -1,    24,    25,    -1,    -1,    40,    -1,
      -1,    43,    44,    -1,    17,    -1,    19,     3,     4,     5,
      40,    24,    25,    43,    44,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    19,     3,     4,     5,    40,    24,    25,
      43,    44,    19,    -1,    30,    -1,    -1,    24,    25,    -1,
      19,    -1,    -1,    30,    40,    24,    25,    43,    44,    -1,
       3,     4,     5,    40,    -1,    -1,    43,    44,    -1,    -1,
      -1,    40,    -1,    -1,    43,    44,    19,    -1,    -1,    -1,
      -1,    24,    25,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    40,    -1,    -1,
      43,    44,    -1,    37,    38,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,    53,     0,     3,     4,     5,     6,    14,
      19,    24,    25,    26,    28,    29,    31,    32,    39,    40,
      43,    44,    52,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    71,    72,    73,    74,    75,    76,    77,    81,
      84,    85,    86,    88,    89,    90,    10,    11,    12,    13,
      17,    24,    26,     5,    60,    85,     5,    88,    89,    53,
      53,    24,    25,    56,    31,     5,    90,     5,    25,    39,
      53,     5,     6,     7,    15,    17,    18,    19,    20,    21,
      24,    25,    26,    27,    28,    29,    30,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    45,    46,
      47,    48,    88,    89,    91,    92,    93,    44,    91,    51,
      18,    19,    20,    21,    22,     9,    25,    10,    11,    12,
      13,    17,    24,    60,    60,    60,    60,    24,    60,    70,
      30,    60,    82,     5,    60,    24,    33,    56,    82,    53,
      28,    60,    61,    67,    68,    69,    70,    24,    67,     5,
      78,    79,    90,    43,    92,    44,    53,    53,    53,    53,
      53,     5,     9,    27,    60,    86,    87,    60,    60,    60,
      60,    60,    70,    30,    82,    53,    17,    28,    37,    38,
      30,    53,    24,    30,    53,    53,    53,    60,    61,    33,
      35,    36,     5,    30,    83,    33,    39,    41,    42,    53,
      27,    60,    60,    60,    60,    60,    24,    61,    86,    86,
      33,     9,    27,    33,    30,    60,    70,    17,    17,    17,
      60,    17,    60,    42,    30,    82,    60,    33,    33,     7,
      40,    80,    35,    36,    80,    30,    42,    80,    39,    53,
      61,    30,    82,    27,    86,    86,    30,    60,    60,    60,
      60,    53,    30,     5,    51,    34,    64,    65,    66,    53,
      53,    80,     5,    64,    66,    80,    79,    30,    86,    27,
      60,    53,    41,    25,    80,    65,    66,    68,    69,    66,
      53,    86,    30,    67,    80,    33,    80
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 112 "gram.y"
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
#line 129 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(2) - (3)].data);
        stmt->next = (statement_t*)(yyvsp[(3) - (3)].data);
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 4:
#line 134 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 138 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 6:
#line 141 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 7:
#line 144 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_FOREACH, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 8:
#line 147 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_EXPR, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 9:
#line 150 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 10:
#line 153 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 11:
#line 156 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 12:
#line 159 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 13:
#line 162 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 14:
#line 165 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 15:
#line 168 "gram.y"
    {
        (yyval.data) = sourceStatement(LANG_ENTITY_CLASSDECL, (yyvsp[(1) - (1)].data), SOURCE_LOCATION((yyloc)));
    }
    break;

  case 16:
#line 172 "gram.y"
    {}
    break;

  case 17:
#line 172 "gram.y"
    {}
    break;

  case 18:
#line 174 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 19:
#line 176 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 20:
#line 181 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 21:
#line 186 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(3) - (8)].data), (yyvsp[(5) - (8)].id), (yyvsp[(8) - (8)].data));
}
    break;

  case 22:
#line 190 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 23:
#line 194 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 24:
#line 198 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 25:
#line 203 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 26:
#line 206 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 27:
#line 213 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 28:
#line 220 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 29:
#line 227 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 30:
#line 234 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 31:
#line 243 "gram.y"
    { (yyval.data) = (yyvsp[(1) - (1)].data); }
    break;

  case 32:
#line 244 "gram.y"
    { (yyval.data) = (yyvsp[(1) - (1)].data); }
    break;

  case 33:
#line 248 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 34:
#line 251 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 35:
#line 258 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 36:
#line 266 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 37:
#line 275 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 38:
#line 278 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 39:
#line 285 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 40:
#line 293 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);

        (yyval.data) = ifs;
    }
    break;

  case 41:
#line 302 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 42:
#line 309 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 43:
#line 314 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 44:
#line 321 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 45:
#line 327 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (5)].data), NULL, (yyvsp[(5) - (5)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 46:
#line 331 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 47:
#line 336 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(5) - (5)].data), (yyvsp[(1) - (5)].data), NULL);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 48:
#line 340 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 49:
#line 345 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 50:
#line 348 "gram.y"
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[(2) - (2)].data));
        (yyval.data) = cond;
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 51:
#line 354 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 52:
#line 359 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 53:
#line 363 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 54:
#line 367 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 55:
#line 371 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 56:
#line 375 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 57:
#line 379 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 58:
#line 383 "gram.y"
    {
        (yyval.data) = (yyvsp[(3) - (4)].data);
    }
    break;

  case 59:
#line 387 "gram.y"
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
            reportSourceError(&walk->location,
                "SyntaxError: class '%s' may contain only variable and function declarations\n", (yyvsp[(3) - (6)].id));
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, (yyvsp[(3) - (6)].id)) == 0 ) {
                if ( funcDef->params != NULL ) {
                    reportSourceError(&walk->location,
                        "SyntaxError: constructor '%s' must not have parameters\n", (yyvsp[(3) - (6)].id));
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    (yyval.data) = newClass((yyvsp[(3) - (6)].id), bod);
}
    break;

  case 60:
#line 421 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 61:
#line 424 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 62:
#line 429 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (6)].data), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 63:
#line 433 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].id), NULL);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 64:
#line 437 "gram.y"
    {
        (yyval.data) = newClassAccesser((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].id));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 65:
#line 444 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 66:
#line 449 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newFunCall(id,NULL);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 67:
#line 454 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 68:
#line 457 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (4)].data);
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 69:
#line 462 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (3)].data);
        (yyval.data) = newFunCall(id,NULL);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 70:
#line 469 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(3) - (5)].id));
        expr_t *expr = newExpr_ID((yyvsp[(1) - (5)].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 71:
#line 476 "gram.y"
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
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 72:
#line 491 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 73:
#line 496 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 74:
#line 503 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 75:
#line 510 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 76:
#line 517 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 77:
#line 524 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[(1) - (3)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),opadd);
    }
    break;

  case 78:
#line 530 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[(1) - (3)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),opadd);
    }
    break;

  case 79:
#line 536 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[(1) - (3)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),opadd);
    }
    break;

  case 80:
#line 542 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(3) - (3)].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[(1) - (3)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),opadd);
    }
    break;

  case 81:
#line 548 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 82:
#line 553 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 83:
#line 556 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 84:
#line 561 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(3) - (4)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 85:
#line 567 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (5)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(4) - (5)].data);

      right->next = left;
      (yyval.data) = right;
    }
    break;

  case 86:
#line 574 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 87:
#line 577 "gram.y"
    {
        (yyval.data) = NULL;
    }
    break;

  case 88:
#line 582 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 89:
#line 593 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 90:
#line 598 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(3) - (5)].data);
      (yyval.data) = newExpr_Vector(args);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 91:
#line 604 "gram.y"
    {
      statement_t* stmt = sourceStatement(LANG_ENTITY_FOREACH, (yyvsp[(3) - (5)].data), SOURCE_LOCATION((yylsp[(3) - (5)])));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 92:
#line 609 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 93:
#line 615 "gram.y"
    {
        expr_t *expr = (yyvsp[(5) - (5)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (5)].data));
    }
    break;

  case 94:
#line 619 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 95:
#line 624 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 96:
#line 629 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 97:
#line 635 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 98:
#line 638 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 99:
#line 643 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 100:
#line 646 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 101:
#line 653 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 102:
#line 660 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 103:
#line 672 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 104:
#line 675 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 105:
#line 678 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 106:
#line 681 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 107:
#line 684 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 108:
#line 687 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 109:
#line 690 "gram.y"
    {
      (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 110:
#line 694 "gram.y"
    {
      expr_t *id = newExpr_ID((yyvsp[(2) - (2)].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 111:
#line 700 "gram.y"
    {
      (yyval.data) = (yyvsp[(3) - (4)].data);
    }
    break;

  case 112:
#line 705 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data), NULL);
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 113:
#line 709 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (2)].data), NULL);
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 114:
#line 713 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (2)].data), NULL, NULL);
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 115:
#line 717 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 116:
#line 721 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 117:
#line 725 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 118:
#line 729 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), NULL, (yyvsp[(3) - (3)].data));
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 119:
#line 733 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[(2) - (2)].data));
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 120:
#line 737 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
    ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
  }
    break;

  case 121:
#line 743 "gram.y"
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
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 122:
#line 757 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 123:
#line 763 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 124:
#line 766 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 125:
#line 769 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 126:
#line 774 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 127:
#line 781 "gram.y"
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
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 128:
#line 810 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 129:
#line 815 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 130:
#line 819 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 131:
#line 827 "gram.y"
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
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 132:
#line 845 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 133:
#line 851 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 134:
#line 857 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
      ((expr_t*)(yyval.data))->location = SOURCE_LOCATION((yyloc));
    }
    break;

  case 135:
#line 863 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 136:
#line 868 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 137:
#line 873 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 138:
#line 877 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 139:
#line 881 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 140:
#line 885 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 141:
#line 889 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 142:
#line 893 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 143:
#line 897 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 144:
#line 901 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 145:
#line 905 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 146:
#line 909 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 147:
#line 913 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 148:
#line 917 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 149:
#line 921 "gram.y"
    {
        strcpy((yyval.id), (yyvsp[(1) - (1)].id));
    }
    break;

  case 150:
#line 924 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 151:
#line 928 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 152:
#line 932 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 153:
#line 936 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 154:
#line 940 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 155:
#line 944 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 156:
#line 948 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 157:
#line 952 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 158:
#line 956 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 159:
#line 960 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 160:
#line 964 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 161:
#line 968 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3187 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 973 "gram.y"


void yyerror(const char *s) {
    source_location_t location = SOURCE_LOCATION(yylloc);
    reportSourceError(&location, "SyntaxError: %s\n", s);
}

#include <stdlib.h>
#include <string.h>
#include "hooks.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse(void);
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void initParser(void) {
    setParser(yyparse);
    setRoot(&root);
}

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, int stacksize, int heapsize, const char *prompt) {
    char lineBuffer[256];

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    while ( readCommand(lineBuffer, sizeof(lineBuffer), prompt) != NULL ) {
        YY_BUFFER_STATE buffer;

        /* Check if the user wants to quit */
        if ( strstr(lineBuffer, "quit") != NULL ) {
            func(argc, argv, NULL, 1, stacksize, heapsize);
            return;
        }

        /* Parse from read line */
        ParsedFile = "<stdin>";
        resetLexerLocation();
        root = NULL;
        buffer = yy_scan_string(lineBuffer);
        int parsed = yyparse();
        yy_delete_buffer(buffer);

        if ( parsed == 0 && root != NULL ) {
            func(argc, argv, root, 0, stacksize, heapsize);
        }

        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}


int runCommand(int argc, char *argv[], interactiveInterpreterFunc func, char *command, int stacksize, int heapsize) {
    YY_BUFFER_STATE buffer;

    /* Parse from provided command line */
    ParsedFile = "<command>";
    resetLexerLocation();
    root = NULL;
    buffer = yy_scan_string(command);
    int parsed = yyparse();
    yy_delete_buffer(buffer);

    if ( parsed == 0 && root != NULL ) {
        func(argc, argv, root, 0, stacksize, heapsize);
    }
    return parsed != 0;
}

