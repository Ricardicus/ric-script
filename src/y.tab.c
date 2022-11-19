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
#define YYLAST   769

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNRULES -- Number of states.  */
#define YYNSTATES  299

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
       0,     0,     3,     5,     9,    10,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    38,    39,
      42,    45,    48,    56,    65,    68,    70,    73,    75,    80,
      85,    90,    95,   100,   102,   104,   106,   108,   110,   112,
     114,   116,   119,   123,   129,   136,   144,   151,   157,   164,
     172,   179,   182,   184,   190,   193,   199,   201,   207,   209,
     211,   214,   216,   221,   226,   231,   236,   240,   244,   248,
     255,   262,   268,   276,   283,   288,   293,   297,   299,   304,
     308,   314,   321,   325,   330,   335,   340,   345,   350,   355,
     360,   365,   369,   373,   377,   381,   385,   387,   388,   392,
     396,   400,   404,   407,   411,   413,   417,   419,   421,   424,
     426,   429,   434,   439,   444,   448,   451,   454,   456,   462,
     467,   472,   476,   479,   481,   483,   487,   491,   494,   497,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   528,   530,   532,   534,   536,   538,
     540,   542,   544,   546,   548,   550,   552,   554,   556,   558,
     560,   562,   564,   566,   568
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    46,    44,    43,    -1,    -1,
      45,    46,    -1,    69,    -1,    65,    -1,    48,    -1,    53,
      -1,    55,    -1,    56,    -1,    51,    -1,    52,    -1,    50,
      -1,    47,    -1,    64,    -1,    46,     9,    -1,    -1,    16,
       5,    -1,    16,    82,    -1,    17,    49,    -1,    18,    53,
       7,     5,    46,    19,    73,    -1,    18,    46,    53,     7,
       5,    46,    19,    73,    -1,     6,    53,    -1,    20,    -1,
      21,    20,    -1,    54,    -1,    53,    11,    46,    53,    -1,
      53,    13,    46,    53,    -1,    53,    12,    46,    53,    -1,
      53,    15,    46,    53,    -1,    53,    14,    46,    53,    -1,
      78,    -1,    77,    -1,    70,    -1,    74,    -1,    67,    -1,
      66,    -1,    82,    -1,     5,    -1,    12,     5,    -1,    18,
      53,    19,    -1,    22,    23,    60,    24,    73,    -1,    22,
      23,    60,    24,    73,    57,    -1,    22,    23,    60,    24,
      73,    57,    59,    -1,    22,    23,    60,    24,    73,    59,
      -1,    17,    23,    60,    24,    73,    -1,    17,    23,    60,
      24,    73,    57,    -1,    17,    23,    60,    24,    73,    57,
      59,    -1,    17,    23,    60,    24,    73,    59,    -1,    57,
      58,    -1,    58,    -1,    25,    23,    60,    24,    73,    -1,
      25,    73,    -1,    60,    26,    26,    46,    61,    -1,    61,
      -1,    61,    27,    27,    46,    62,    -1,    62,    -1,    63,
      -1,    21,    54,    -1,    54,    -1,    53,    10,    10,    53,
      -1,    53,    21,    10,    53,    -1,    53,    28,    10,    53,
      -1,    53,    29,    10,    53,    -1,    53,    28,    53,    -1,
      53,    29,    53,    -1,    18,    63,    19,    -1,    30,    30,
       5,    30,    30,    73,    -1,    20,     5,    18,    76,    19,
      73,    -1,    20,     5,    18,    19,    73,    -1,    54,    31,
      31,     5,    18,    75,    19,    -1,    54,    31,    31,     5,
      18,    19,    -1,    54,    31,    31,     5,    -1,     5,    18,
      75,    19,    -1,     5,    18,    19,    -1,    68,    -1,    78,
      18,    75,    19,    -1,    78,    18,    19,    -1,     5,    17,
       5,    18,    19,    -1,     5,    17,     5,    18,    75,    19,
      -1,     5,    10,    53,    -1,     5,    11,    10,    53,    -1,
       5,    12,    10,    53,    -1,     5,    13,    10,    53,    -1,
       5,    14,    10,    53,    -1,    78,    11,    10,    53,    -1,
      78,    12,    10,    53,    -1,    78,    13,    10,    53,    -1,
      78,    14,    10,    53,    -1,     5,    10,    63,    -1,    78,
      10,    53,    -1,    78,    10,    63,    -1,    32,    71,    33,
      -1,    71,    34,    72,    -1,    72,    -1,    -1,    82,    31,
      54,    -1,    32,    43,    33,    -1,    23,    75,    24,    -1,
      23,    49,    24,    -1,    23,    24,    -1,    75,    34,    53,
      -1,    53,    -1,    76,    34,     5,    -1,     5,    -1,    81,
      -1,    12,    81,    -1,    80,    -1,    12,    80,    -1,    54,
      23,    53,    24,    -1,    54,    23,    79,    24,    -1,    78,
      23,    53,    24,    -1,    54,    31,    54,    -1,    31,    54,
      -1,    54,    31,    -1,    31,    -1,    54,    31,    54,    31,
      54,    -1,    31,    54,    31,    54,    -1,    54,    31,    31,
      54,    -1,    31,    31,    54,    -1,    31,    31,    -1,     3,
      -1,     4,    -1,    35,    83,    35,    -1,    36,    83,    36,
      -1,    36,    36,    -1,    35,    35,    -1,    83,    84,    -1,
      84,    -1,     5,    -1,    81,    -1,    80,    -1,     6,    -1,
       7,    -1,    85,    -1,    11,    -1,    37,    -1,    22,    -1,
      28,    -1,    29,    -1,    12,    -1,    14,    -1,    38,    -1,
      31,    -1,    30,    -1,    18,    -1,    19,    -1,    21,    -1,
      34,    -1,    35,    -1,    36,    -1,    17,    -1,    23,    -1,
      24,    -1,    13,    -1,    39,    -1,    16,    -1,    27,    -1,
      26,    -1,    32,    -1,    33,    -1,    10,    -1,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   114,   119,   122,   127,   130,   133,   136,
     139,   142,   145,   148,   151,   154,   157,   161,   161,   163,
     165,   170,   175,   177,   181,   185,   189,   194,   197,   203,
     209,   215,   221,   229,   232,   235,   238,   241,   244,   247,
     250,   253,   258,   263,   266,   273,   281,   290,   293,   300,
     308,   317,   324,   329,   336,   342,   345,   350,   353,   358,
     361,   366,   371,   374,   377,   380,   383,   386,   389,   393,
     427,   430,   435,   438,   441,   447,   451,   455,   458,   462,
     468,   474,   488,   493,   500,   507,   514,   521,   527,   533,
     539,   545,   550,   553,   558,   563,   570,   573,   578,   589,
     594,   599,   603,   608,   612,   617,   622,   628,   631,   635,
     638,   644,   650,   656,   661,   664,   667,   670,   673,   676,
     679,   682,   685,   690,   703,   708,   711,   714,   718,   724,
     752,   757,   760,   767,   784,   789,   794,   799,   804,   809,
     813,   817,   821,   825,   829,   833,   837,   841,   845,   849,
     853,   857,   861,   865,   869,   873,   877,   881,   885,   889,
     893,   897,   901,   905,   909
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
       0,    41,    42,    43,    43,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    48,    49,    49,    50,    51,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    71,    72,    73,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    81,    82,    82,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       2,     2,     7,     8,     2,     1,     2,     1,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     5,     6,     7,     6,     5,     6,     7,
       6,     2,     1,     5,     2,     5,     1,     5,     1,     1,
       2,     1,     4,     4,     4,     4,     3,     3,     3,     6,
       6,     5,     7,     6,     4,     4,     3,     1,     4,     3,
       5,     6,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       3,     3,     2,     3,     1,     3,     1,     1,     2,     1,
       2,     4,     4,     4,     3,     2,     2,     1,     5,     4,
       4,     3,     2,     1,     1,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      18,     0,     2,     0,     1,   123,   124,    40,     0,    17,
       0,     0,     0,     0,    25,     0,     0,     0,     0,    97,
       0,     0,    18,    18,    15,     8,    14,    12,    13,     9,
      27,    10,    11,    16,     7,    38,    37,    77,     6,    35,
      36,    34,    33,   109,   107,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    24,    33,    41,   110,   108,    19,
      20,    18,     0,    21,     0,     0,    26,     0,    18,   102,
       0,   104,     0,     0,     0,    96,     0,   131,   134,   135,
     163,   137,   142,   156,   143,   158,   153,   147,   148,   149,
     139,   154,   155,   160,   159,   140,   141,   146,   145,   161,
     162,   150,   128,   152,   138,   144,   157,   164,   133,   132,
       0,   130,   136,   151,   127,     0,     3,     5,    18,    18,
      18,    18,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    91,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,    27,     0,    56,    58,
      59,    42,     0,     0,     0,   101,   100,     0,     0,    94,
       0,     0,   125,   129,   126,     0,     0,     0,     0,     0,
     117,     0,    27,     0,     0,    92,    93,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,    75,     0,     0,    60,     0,
       0,     0,   106,     0,     0,     0,   103,     0,    95,    98,
      28,    30,    29,    32,    31,   122,   115,   111,   116,   112,
      74,    87,    88,    89,    90,    78,   113,    68,     0,     0,
       0,    66,     0,    67,    80,     0,     0,    18,    18,    47,
      18,    18,    71,     0,     0,    43,     0,   121,     0,     0,
     114,     0,    62,    63,    64,    65,    81,    18,     0,     0,
       0,    48,    52,    50,     0,     0,    70,   105,    44,    46,
      69,   119,    74,   120,     0,    73,     0,     0,     0,    99,
       0,    54,    51,    49,    55,    57,    45,     0,   118,    72,
       0,    22,     0,    73,     0,    23,     0,    72,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    22,    23,     3,    24,    25,    63,    26,
      27,    28,    71,    30,    31,    32,   261,   262,   263,   147,
     148,   149,   150,    33,    34,    35,    36,    37,    38,    39,
      74,    75,   239,    40,    72,   204,    41,    55,   173,    43,
      44,    45,   110,   111,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -246
static const yytype_int16 yypact[] =
{
      36,    63,  -246,   414,  -246,  -246,  -246,   231,   672,  -246,
      89,    10,    51,   672,    62,    60,    86,   137,    91,   115,
     262,   300,     9,  -246,  -246,  -246,  -246,  -246,  -246,   451,
      84,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,   134,  -246,  -246,  -246,   688,   121,   127,   149,
     157,   120,   175,   165,   451,    88,  -246,  -246,  -246,  -246,
    -246,   672,   435,  -246,   736,   153,  -246,   435,   672,  -246,
     173,   451,   -17,   194,   162,  -246,   181,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,   195,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
     338,  -246,  -246,  -246,   438,   376,  -246,   207,  -246,  -246,
    -246,  -246,  -246,   456,   187,   688,   209,   213,   218,   228,
     477,   672,   688,   242,  -246,   672,   672,   672,   672,   221,
    -246,    32,   498,   745,   672,   242,   182,    13,   220,  -246,
    -246,  -246,     8,   132,   528,  -246,  -246,   672,   229,  -246,
     115,   672,   195,  -246,   438,   498,   498,   498,   498,   498,
     514,    71,    93,   226,   246,   242,  -246,   672,   672,   672,
     672,  -246,    37,   177,   725,   239,   250,   254,   548,   558,
     451,   451,   451,   451,   583,  -246,   754,   277,    84,   255,
     282,   288,  -246,   255,    38,   255,   451,   279,  -246,    84,
     189,   189,  -246,  -246,  -246,   672,    95,  -246,   593,  -246,
     302,   451,   451,   451,   451,  -246,  -246,  -246,   672,   672,
     672,   451,   672,   451,  -246,    41,   320,  -246,   313,   322,
    -246,  -246,  -246,   255,   348,   322,   255,    84,   609,   698,
     107,   630,   451,   451,   451,   451,  -246,  -246,    25,   325,
      80,   322,  -246,  -246,    17,    17,  -246,  -246,   322,  -246,
    -246,    84,    73,    84,   609,  -246,    42,    59,   255,  -246,
     435,  -246,  -246,  -246,   220,  -246,  -246,   651,    84,  -246,
     255,  -246,   144,  -246,    43,  -246,   255,  -246,  -246
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,   -16,  -246,  -246,   -20,  -246,  -246,   346,  -246,
    -246,  -246,    -3,   -34,  -246,  -246,   139,  -245,  -214,   -56,
     158,   126,   -44,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,   225,  -173,  -246,   -51,  -246,  -246,   393,  -246,    -2,
       4,    -7,   380,   -60,  -246
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -153
static const yytype_int16 yytable[] =
{
      29,   141,   134,   117,    60,    54,   116,   156,    57,    -4,
      64,   153,    76,   202,    58,    59,   282,   157,   108,   108,
       5,     6,    53,   282,   109,   109,     9,   203,   146,    10,
     242,   269,   245,   146,     9,   132,    -4,   199,   144,   200,
      17,   142,    -4,   133,   278,    20,    21,   283,   142,    19,
     163,   195,    20,    21,   286,   163,   225,   243,   143,   145,
     256,   289,   297,     4,   145,   154,   157,    65,     9,    61,
     266,   157,   244,   270,    62,   157,   157,   157,   290,   182,
      66,   176,   118,   119,   120,   121,   122,   281,   185,   172,
      51,   287,     5,     6,    56,   217,   -40,   -40,   165,   166,
     167,   168,   169,   280,   -40,   291,   130,   123,   108,    67,
     198,   131,   238,   108,   109,   124,   123,   295,   123,   109,
     171,    73,   175,   298,   218,   139,   248,   209,   183,   184,
     123,   135,   190,   191,   192,   193,   216,   136,   274,   196,
       5,     6,    53,   235,   125,   126,   127,   128,   129,    10,
      20,    21,   130,    76,   206,    68,   205,   131,   200,   137,
      17,    69,   210,   211,   212,   213,   214,   138,   296,    19,
     200,   152,    20,    21,   221,   222,   223,   224,     5,     6,
      53,   247,    51,    52,   250,   231,   233,    10,   118,   119,
     120,   121,   122,    13,   140,   159,   160,   155,    17,   158,
     276,   226,   120,   121,   122,   123,   -61,    19,   -61,   -61,
      20,    21,   161,   124,   271,   273,     9,   258,   174,   177,
     264,   265,   259,   178,   292,   252,   253,   254,   179,   255,
     146,   146,  -151,  -151,  -151,  -151,   294,   277,   180,   194,
     288,    46,    47,    48,    49,    50,   146,   201,    51,    52,
     219,   220,   186,   118,   119,   120,   121,   122,   227,   207,
     228,   145,   145,   187,   229,     5,     6,    77,    78,    79,
     188,   189,    80,    81,    82,    83,    84,   145,    85,    86,
      87,    88,   237,    89,    90,    91,    92,   238,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     5,     6,    77,    78,    79,   240,   246,
      80,    81,    82,    83,    84,   241,    85,    86,    87,    88,
     251,    89,    90,    91,    92,   257,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   113,   114,   104,   105,   106,
     107,     5,     6,    77,    78,    79,    -4,   260,    80,    81,
      82,    83,    84,   267,    85,    86,    87,    88,   279,    89,
      90,    91,    92,    70,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   162,   103,   104,   105,   106,   107,     5,
       6,    77,    78,    79,   268,   208,    80,    81,    82,    83,
      84,   285,    85,    86,    87,    88,    42,    89,    90,    91,
      92,   115,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   113,   164,   104,   105,   106,   107,     5,     6,     7,
       8,     0,   284,     9,     0,     0,    10,     0,     0,     0,
      11,    12,    13,     0,    14,    15,    16,    17,     5,     6,
      53,     0,     0,     0,    18,     0,    19,    10,     0,    20,
      21,     0,     0,   132,     0,     0,   144,     0,    17,     5,
       6,    53,   118,   119,   120,   121,   122,    19,    10,     0,
      20,    21,     0,     0,    13,  -152,  -152,  -152,  -152,    17,
       5,     6,    53,     0,     0,     0,     0,   170,    19,    10,
       0,    20,    21,     0,     0,    13,   181,     0,     0,     0,
      17,     5,     6,    53,     0,     0,     0,     9,     0,    19,
      10,     0,    20,    21,     0,     0,    13,     5,     6,    53,
       0,    17,     0,     0,     0,     0,    10,     0,     0,     0,
      19,     0,    13,    20,    21,   197,     0,    17,     0,   118,
     119,   120,   121,   122,     0,   215,    19,   151,     0,    20,
      21,     5,     6,    53,     0,     0,     0,     0,   230,     0,
      10,     5,     6,    53,     0,     0,    13,     0,   232,     0,
      10,    17,     0,     0,     0,     0,    13,     0,     0,     0,
      19,    17,     0,    20,    21,     0,     5,     6,    53,     0,
      19,     0,     0,    20,    21,    10,     5,     6,    53,     0,
       0,    13,   234,     0,     0,    10,    17,     0,     0,     0,
       0,    13,     5,     6,    53,    19,    17,     0,    20,    21,
       0,    10,     0,     0,   249,    19,     0,    13,    20,    21,
       0,     0,    17,     5,     6,    53,     0,     0,     0,     0,
     174,    19,    10,     0,    20,    21,     0,     0,    13,   275,
       0,     0,     0,    17,     5,     6,    53,     0,     0,     0,
       0,     0,    19,    10,     0,    20,    21,     0,     0,    13,
     293,     0,     0,     0,    17,     5,     6,    53,     0,     0,
       0,     0,     0,    19,    10,     0,    20,    21,     0,     0,
      13,     5,     6,    53,     0,    17,     0,     0,     0,     0,
      10,     5,     6,   272,    19,     0,   132,    20,    21,     0,
      10,    17,     0,     0,     0,     0,    13,     0,     0,     0,
      19,    17,     0,    20,    21,     0,     0,     0,     0,     0,
      19,     0,     0,    20,    21,   186,   118,   119,   120,   121,
     122,     0,     0,     0,   151,     0,   187,   118,   119,   120,
     121,   122,   197,   188,   189,   151,   118,   119,   120,   121,
     122,   236,     0,     0,     0,   118,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
       3,    52,    46,    23,    11,     8,    22,    24,    10,     0,
      13,    67,    19,     5,    10,     5,   261,    34,    20,    21,
       3,     4,     5,   268,    20,    21,     9,    19,    62,    12,
     203,   245,   205,    67,     9,    18,     0,    24,    21,    26,
      23,    61,    33,    46,    19,    35,    36,   261,    68,    32,
     110,    19,    35,    36,   268,   115,    19,    19,    61,    62,
      19,    19,    19,     0,    67,    68,    34,     5,     9,    18,
     243,    34,    34,   246,    23,    34,    34,    34,    19,   130,
      20,   125,    11,    12,    13,    14,    15,   260,   132,   123,
      17,    18,     3,     4,     5,    24,    23,    24,   118,   119,
     120,   121,   122,    23,    31,   278,    18,    23,   110,    23,
     144,    23,    32,   115,   110,    31,    23,   290,    23,   115,
     123,    30,   125,   296,    31,     5,    31,   161,   131,   132,
      23,    10,   135,   136,   137,   138,   170,    10,    31,   142,
       3,     4,     5,   194,    10,    11,    12,    13,    14,    12,
      35,    36,    18,   160,   157,    18,    24,    23,    26,    10,
      23,    24,   165,   166,   167,   168,   169,    10,    24,    32,
      26,    18,    35,    36,   177,   178,   179,   180,     3,     4,
       5,   215,    17,    18,   218,   188,   189,    12,    11,    12,
      13,    14,    15,    18,    19,    33,    34,    24,    23,     5,
     251,    24,    13,    14,    15,    23,    24,    32,    26,    27,
      35,    36,    31,    31,   248,   249,     9,   237,    31,    10,
     240,   241,   238,    10,   280,   228,   229,   230,    10,   232,
     264,   265,    37,    38,    39,    40,   287,   257,    10,    18,
     274,    10,    11,    12,    13,    14,   280,    27,    17,    18,
      24,     5,    10,    11,    12,    13,    14,    15,    19,    30,
      10,   264,   265,    21,    10,     3,     4,     5,     6,     7,
      28,    29,    10,    11,    12,    13,    14,   280,    16,    17,
      18,    19,     5,    21,    22,    23,    24,    32,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     3,     4,     5,     6,     7,    26,    30,
      10,    11,    12,    13,    14,    27,    16,    17,    18,    19,
      18,    21,    22,    23,    24,     5,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     3,     4,     5,     6,     7,    33,    25,    10,    11,
      12,    13,    14,     5,    16,    17,    18,    19,    33,    21,
      22,    23,    24,    17,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     3,
       4,     5,     6,     7,   245,   160,    10,    11,    12,    13,
      14,   265,    16,    17,    18,    19,     3,    21,    22,    23,
      24,    21,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     3,     4,     5,
       6,    -1,   264,     9,    -1,    -1,    12,    -1,    -1,    -1,
      16,    17,    18,    -1,    20,    21,    22,    23,     3,     4,
       5,    -1,    -1,    -1,    30,    -1,    32,    12,    -1,    35,
      36,    -1,    -1,    18,    -1,    -1,    21,    -1,    23,     3,
       4,     5,    11,    12,    13,    14,    15,    32,    12,    -1,
      35,    36,    -1,    -1,    18,    37,    38,    39,    40,    23,
       3,     4,     5,    -1,    -1,    -1,    -1,    31,    32,    12,
      -1,    35,    36,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,     3,     4,     5,    -1,    -1,    -1,     9,    -1,    32,
      12,    -1,    35,    36,    -1,    -1,    18,     3,     4,     5,
      -1,    23,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      32,    -1,    18,    35,    36,     7,    -1,    23,    -1,    11,
      12,    13,    14,    15,    -1,    31,    32,    19,    -1,    35,
      36,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,
      12,     3,     4,     5,    -1,    -1,    18,    -1,    10,    -1,
      12,    23,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      32,    23,    -1,    35,    36,    -1,     3,     4,     5,    -1,
      32,    -1,    -1,    35,    36,    12,     3,     4,     5,    -1,
      -1,    18,    19,    -1,    -1,    12,    23,    -1,    -1,    -1,
      -1,    18,     3,     4,     5,    32,    23,    -1,    35,    36,
      -1,    12,    -1,    -1,    31,    32,    -1,    18,    35,    36,
      -1,    -1,    23,     3,     4,     5,    -1,    -1,    -1,    -1,
      31,    32,    12,    -1,    35,    36,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    32,    12,    -1,    35,    36,    -1,    -1,    18,
      19,    -1,    -1,    -1,    23,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    32,    12,    -1,    35,    36,    -1,    -1,
      18,     3,     4,     5,    -1,    23,    -1,    -1,    -1,    -1,
      12,     3,     4,     5,    32,    -1,    18,    35,    36,    -1,
      12,    23,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      32,    23,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    11,    12,    13,
      14,    15,     7,    28,    29,    19,    11,    12,    13,    14,
      15,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15
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
      82,    18,    23,    49,    53,     5,    20,    23,    18,    24,
      49,    53,    75,    30,    71,    72,    82,     5,     6,     7,
      10,    11,    12,    13,    14,    16,    17,    18,    19,    21,
      22,    23,    24,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    80,    81,
      83,    84,    85,    35,    36,    83,    43,    46,    11,    12,
      13,    14,    15,    23,    31,    10,    11,    12,    13,    14,
      18,    23,    18,    53,    63,    10,    10,    10,    10,     5,
      19,    75,    46,    53,    21,    53,    54,    60,    61,    62,
      63,    19,    18,    60,    53,    24,    24,    34,     5,    33,
      34,    31,    35,    84,    36,    46,    46,    46,    46,    46,
      31,    53,    54,    79,    31,    53,    63,    10,    10,    10,
      10,    19,    75,    53,    53,    63,    10,    21,    28,    29,
      53,    53,    53,    53,    18,    19,    53,     7,    54,    24,
      26,    27,     5,    19,    76,    24,    53,    30,    72,    54,
      53,    53,    53,    53,    53,    31,    54,    24,    31,    24,
       5,    53,    53,    53,    53,    19,    24,    19,    10,    10,
      10,    53,    10,    53,    19,    75,     7,     5,    32,    73,
      26,    27,    73,    19,    34,    73,    30,    54,    31,    31,
      54,    18,    53,    53,    53,    53,    19,     5,    46,    43,
      25,    57,    58,    59,    46,    46,    73,     5,    57,    59,
      73,    54,     5,    54,    31,    19,    75,    46,    19,    33,
      23,    73,    58,    59,    61,    62,    59,    18,    54,    19,
      19,    73,    60,    19,    75,    73,    24,    19,    73
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
#line 122 "gram.y"
    {
	(yyval.data) = (yyvsp[(1) - (2)].data);
}
    break;

  case 6:
#line 127 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 130 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 133 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 136 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 139 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 142 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 145 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 148 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 151 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 154 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 157 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 17:
#line 161 "gram.y"
    {}
    break;

  case 18:
#line 161 "gram.y"
    {}
    break;

  case 19:
#line 163 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 20:
#line 165 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 21:
#line 170 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 22:
#line 175 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(2) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(7) - (7)].data));
}
    break;

  case 23:
#line 177 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(3) - (8)].data), (yyvsp[(5) - (8)].id), (yyvsp[(8) - (8)].data));
}
    break;

  case 24:
#line 181 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 25:
#line 185 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 26:
#line 189 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 27:
#line 194 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 28:
#line 197 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 29:
#line 203 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 30:
#line 209 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
    break;

  case 31:
#line 215 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
    break;

  case 32:
#line 221 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (4)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(4) - (4)].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
    break;

  case 33:
#line 229 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 34:
#line 232 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 35:
#line 235 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 36:
#line 238 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 37:
#line 241 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 38:
#line 244 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 39:
#line 247 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 40:
#line 250 "gram.y"
    {
      (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 41:
#line 253 "gram.y"
    {
      expr_t *id = newExpr_ID((yyvsp[(2) - (2)].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
    }
    break;

  case 42:
#line 258 "gram.y"
    {
      (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 43:
#line 263 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 44:
#line 266 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 45:
#line 273 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 46:
#line 281 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 47:
#line 290 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 48:
#line 293 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 49:
#line 300 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 50:
#line 308 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);

        (yyval.data) = ifs;
    }
    break;

  case 51:
#line 317 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 52:
#line 324 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 53:
#line 329 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 54:
#line 336 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 55:
#line 342 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (5)].data), NULL, (yyvsp[(5) - (5)].data));
    }
    break;

  case 56:
#line 345 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 57:
#line 350 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (5)].data), (yyvsp[(5) - (5)].data), NULL);
    }
    break;

  case 58:
#line 353 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 59:
#line 358 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 60:
#line 361 "gram.y"
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[(2) - (2)].data));
        (yyval.data) = cond;
    }
    break;

  case 61:
#line 366 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 62:
#line 371 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 63:
#line 374 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 64:
#line 377 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 65:
#line 380 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 66:
#line 383 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 67:
#line 386 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 68:
#line 389 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 69:
#line 393 "gram.y"
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

  case 70:
#line 427 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 71:
#line 430 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 72:
#line 435 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(6) - (7)].data));
    }
    break;

  case 73:
#line 438 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (6)].data), (yyvsp[(4) - (6)].id), NULL);
    }
    break;

  case 74:
#line 441 "gram.y"
    {
        (yyval.data) = newClassAccesser((yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].id));
    }
    break;

  case 75:
#line 447 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 76:
#line 451 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 77:
#line 455 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 78:
#line 458 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (4)].data);
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 79:
#line 462 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (3)].data);
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 80:
#line 468 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(3) - (5)].id));
        expr_t *expr = newExpr_ID((yyvsp[(1) - (5)].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
    break;

  case 81:
#line 474 "gram.y"
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

  case 82:
#line 488 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 83:
#line 493 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 84:
#line 500 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 85:
#line 507 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 86:
#line 514 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 87:
#line 521 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 88:
#line 527 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 89:
#line 533 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 90:
#line 539 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 91:
#line 545 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 92:
#line 550 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 93:
#line 553 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 94:
#line 558 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(2) - (3)].data));
    }
    break;

  case 95:
#line 563 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (3)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(3) - (3)].data);

      right->next = left;
      (yyval.data) = right;
    }
    break;

  case 96:
#line 570 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 97:
#line 573 "gram.y"
    {
        (yyval.data) = NULL;
    }
    break;

  case 98:
#line 578 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 99:
#line 589 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 100:
#line 594 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(2) - (3)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 101:
#line 599 "gram.y"
    {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(2) - (3)].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
    break;

  case 102:
#line 603 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 103:
#line 608 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 104:
#line 612 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 105:
#line 617 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 106:
#line 622 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 107:
#line 628 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 108:
#line 631 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 109:
#line 635 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 110:
#line 638 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 111:
#line 644 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 112:
#line 650 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 113:
#line 656 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 114:
#line 661 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data), NULL);
  }
    break;

  case 115:
#line 664 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (2)].data), NULL);
  }
    break;

  case 116:
#line 667 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (2)].data), NULL, NULL);
  }
    break;

  case 117:
#line 670 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 118:
#line 673 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
  }
    break;

  case 119:
#line 676 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
  }
    break;

  case 120:
#line 679 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
  }
    break;

  case 121:
#line 682 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[(3) - (3)].data));
  }
    break;

  case 122:
#line 685 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 123:
#line 690 "gram.y"
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

  case 124:
#line 703 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 125:
#line 708 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 126:
#line 711 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 127:
#line 714 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 128:
#line 718 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 129:
#line 724 "gram.y"
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

  case 130:
#line 752 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 131:
#line 757 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 132:
#line 760 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 133:
#line 767 "gram.y"
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

  case 134:
#line 784 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 135:
#line 789 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 136:
#line 794 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 137:
#line 799 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 138:
#line 804 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 139:
#line 809 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 140:
#line 813 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 141:
#line 817 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 142:
#line 821 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 143:
#line 825 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 144:
#line 829 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 145:
#line 833 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 146:
#line 837 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 147:
#line 841 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 148:
#line 845 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 149:
#line 849 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 150:
#line 853 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 151:
#line 857 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 152:
#line 861 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 153:
#line 865 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 154:
#line 869 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 155:
#line 873 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 156:
#line 877 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 157:
#line 881 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 158:
#line 885 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 159:
#line 889 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 160:
#line 893 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 161:
#line 897 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 162:
#line 901 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 163:
#line 905 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 164:
#line 909 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3119 "y.tab.c"
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


#line 914 "gram.y"


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

    ParsedFile = "stdin";

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
    ParsedFile = "stdin";

    /* Parse from provided command line */
    buffer = yy_scan_string(command);
    yyparse();
    yy_delete_buffer(buffer);

    if ( root != NULL ) {
        func(argc, argv, root, 0, stacksize, heapsize);
    }
}

