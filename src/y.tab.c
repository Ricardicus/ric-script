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
#define YYFINAL  111
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  279

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
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    34,    37,    40,
      47,    50,    52,    55,    57,    61,    65,    69,    73,    77,
      79,    81,    83,    85,    87,    89,    91,    93,    97,   103,
     110,   118,   125,   131,   138,   146,   153,   156,   158,   164,
     167,   172,   174,   179,   181,   183,   186,   188,   193,   198,
     203,   208,   212,   216,   220,   227,   234,   240,   248,   255,
     260,   265,   269,   271,   276,   280,   286,   293,   297,   302,
     307,   312,   317,   322,   327,   332,   337,   341,   345,   349,
     353,   357,   359,   360,   364,   368,   372,   376,   379,   383,
     385,   389,   391,   393,   396,   398,   401,   406,   411,   416,
     420,   423,   426,   428,   434,   439,   444,   448,   451,   453,
     455,   459,   463,   466,   469,   472,   474,   476,   478,   480,
     482,   484,   486,   488,   490,   492,   494,   496,   498,   500,
     502,   504,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    43,    -1,    -1,    67,
      -1,    63,    -1,    46,    -1,    51,    -1,    53,    -1,    54,
      -1,    49,    -1,    50,    -1,    48,    -1,    45,    -1,    62,
      -1,    16,     5,    -1,    16,    80,    -1,    17,    47,    -1,
      18,    51,     7,     5,    19,    71,    -1,     6,    51,    -1,
      20,    -1,    21,    20,    -1,    52,    -1,    51,    11,    51,
      -1,    51,    13,    51,    -1,    51,    12,    51,    -1,    51,
      15,    51,    -1,    51,    14,    51,    -1,    76,    -1,    75,
      -1,    68,    -1,    72,    -1,    65,    -1,    64,    -1,    80,
      -1,     5,    -1,    18,    51,    19,    -1,    22,    23,    58,
      24,    71,    -1,    22,    23,    58,    24,    71,    55,    -1,
      22,    23,    58,    24,    71,    55,    57,    -1,    22,    23,
      58,    24,    71,    57,    -1,    17,    23,    58,    24,    71,
      -1,    17,    23,    58,    24,    71,    55,    -1,    17,    23,
      58,    24,    71,    55,    57,    -1,    17,    23,    58,    24,
      71,    57,    -1,    55,    56,    -1,    56,    -1,    25,    23,
      58,    24,    71,    -1,    25,    71,    -1,    58,    26,    26,
      59,    -1,    59,    -1,    59,    27,    27,    60,    -1,    60,
      -1,    61,    -1,    21,    52,    -1,    52,    -1,    51,    10,
      10,    51,    -1,    51,    21,    10,    51,    -1,    51,    28,
      10,    51,    -1,    51,    29,    10,    51,    -1,    51,    28,
      51,    -1,    51,    29,    51,    -1,    18,    61,    19,    -1,
      30,    30,     5,    30,    30,    71,    -1,    20,     5,    18,
      74,    19,    71,    -1,    20,     5,    18,    19,    71,    -1,
      52,    31,    31,     5,    18,    73,    19,    -1,    52,    31,
      31,     5,    18,    19,    -1,    52,    31,    31,     5,    -1,
       5,    18,    73,    19,    -1,     5,    18,    19,    -1,    66,
      -1,    76,    18,    73,    19,    -1,    76,    18,    19,    -1,
       5,    17,     5,    18,    19,    -1,     5,    17,     5,    18,
      73,    19,    -1,     5,    10,    51,    -1,     5,    11,    10,
      51,    -1,     5,    12,    10,    51,    -1,     5,    13,    10,
      51,    -1,     5,    14,    10,    51,    -1,    76,    11,    10,
      51,    -1,    76,    12,    10,    51,    -1,    76,    13,    10,
      51,    -1,    76,    14,    10,    51,    -1,     5,    10,    61,
      -1,    76,    10,    51,    -1,    76,    10,    61,    -1,    32,
      69,    33,    -1,    69,    34,    70,    -1,    70,    -1,    -1,
      80,    31,    52,    -1,    32,    43,    33,    -1,    23,    73,
      24,    -1,    23,    47,    24,    -1,    23,    24,    -1,    73,
      34,    51,    -1,    51,    -1,    74,    34,     5,    -1,     5,
      -1,    79,    -1,    12,    79,    -1,    78,    -1,    12,    78,
      -1,    52,    23,    51,    24,    -1,    52,    23,    77,    24,
      -1,    76,    23,    51,    24,    -1,    52,    31,    52,    -1,
      31,    52,    -1,    52,    31,    -1,    31,    -1,    52,    31,
      52,    31,    52,    -1,    31,    52,    31,    52,    -1,    52,
      31,    31,    52,    -1,    31,    31,    52,    -1,    31,    31,
      -1,     3,    -1,     4,    -1,    35,    81,    35,    -1,    36,
      81,    36,    -1,    36,    36,    -1,    35,    35,    -1,    81,
      82,    -1,    82,    -1,     5,    -1,    79,    -1,    78,    -1,
       6,    -1,     7,    -1,    83,    -1,    11,    -1,    37,    -1,
      22,    -1,    28,    -1,    29,    -1,    12,    -1,    14,    -1,
      38,    -1,    31,    -1,    30,    -1,    18,    -1,    19,    -1,
      21,    -1,    34,    -1,    35,    -1,    36,    -1,    17,    -1,
      23,    -1,    24,    -1,    13,    -1,    39,    -1,    16,    -1,
      27,    -1,    26,    -1,    32,    -1,    33,    -1,    10,    -1,
      40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   114,   119,   123,   126,   129,   132,   135,
     138,   141,   144,   147,   150,   153,   157,   159,   164,   169,
     173,   177,   181,   186,   189,   195,   201,   207,   213,   221,
     224,   227,   230,   233,   236,   239,   242,   245,   250,   253,
     260,   268,   277,   280,   287,   295,   304,   311,   316,   323,
     329,   332,   337,   340,   345,   348,   353,   358,   361,   364,
     367,   370,   373,   376,   380,   414,   417,   422,   425,   428,
     434,   438,   442,   445,   449,   455,   461,   475,   480,   487,
     494,   501,   508,   514,   520,   526,   532,   537,   540,   545,
     550,   557,   560,   565,   576,   581,   586,   590,   595,   599,
     604,   609,   615,   618,   622,   625,   631,   637,   643,   648,
     651,   654,   657,   660,   663,   666,   669,   672,   677,   686,
     691,   694,   697,   701,   707,   735,   740,   743,   750,   765,
     770,   775,   780,   785,   790,   794,   798,   802,   806,   810,
     814,   818,   822,   826,   830,   834,   838,   842,   846,   850,
     854,   858,   862,   866,   870,   874,   878,   882,   886,   890
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
  "statements", "statement", "systemStatement", "forEachStatementFull",
  "forEachStatement", "returnStatement", "continueStatement",
  "breakStatement", "expressions", "expression", "ifStatement",
  "loopStatement", "middleIfs", "middleIf", "endIf", "logical_a",
  "logical_b", "logical_expression", "condition", "class", "function",
  "classFunctionCall", "functionCall", "namespacedFunctionCall",
  "declaration", "dictionary", "dictionary_keys_vals",
  "dictionary_key_val", "body", "vector", "arguments_list",
  "parameters_list", "mathContent", "indexedVector", "indexer",
  "mathContentDigit", "mathContentDouble", "stringContent",
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
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    46,    47,
      48,    49,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      69,    69,    69,    70,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      80,    80,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     6,
       2,     1,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     6,
       7,     6,     5,     6,     7,     6,     2,     1,     5,     2,
       4,     1,     4,     1,     1,     2,     1,     4,     4,     4,
       4,     3,     3,     3,     6,     6,     5,     7,     6,     4,
       4,     3,     1,     4,     3,     5,     6,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     1,     0,     3,     3,     3,     3,     2,     3,     1,
       3,     1,     1,     2,     1,     2,     4,     4,     4,     3,
       2,     2,     1,     5,     4,     4,     3,     2,     1,     1,
       3,     3,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   118,   119,    36,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,    92,     0,     0,     0,     2,     4,
      14,     7,    13,    11,    12,     8,    23,     9,    10,    15,
       6,    34,    33,    72,     5,    31,    32,    30,    29,   104,
     102,    35,     0,     0,     0,     0,     0,     0,     0,    36,
      20,    29,   105,   103,    16,    17,     0,     0,    18,     0,
       0,    22,     0,     0,    97,     0,    99,     0,     0,     0,
      91,     0,   126,   129,   130,   158,   132,   137,   151,   138,
     153,   148,   142,   143,   144,   134,   149,   150,   155,   154,
     135,   136,   141,   140,   156,   157,   145,   123,   147,   133,
     139,   152,   159,   128,   127,     0,   125,   131,   146,   122,
       0,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    86,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
      23,     0,    51,    53,    54,    37,     0,     0,     0,    96,
      95,     0,     0,    89,     0,     0,   120,   124,   121,    24,
      26,    25,    28,    27,   112,     0,    23,     0,     0,    87,
      88,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,     0,    70,
       0,    55,     0,     0,     0,   101,     0,     0,     0,    98,
       0,    90,    93,   117,   110,   106,   111,   107,    69,    82,
      83,    84,    85,    73,   108,    63,     0,     0,     0,    61,
       0,    62,    75,     0,     0,     4,    42,     0,     0,    66,
       0,     0,    38,     0,   116,     0,     0,   109,     0,    57,
      58,    59,    60,    76,     0,     0,     0,    43,    47,    45,
      50,    52,    65,   100,    39,    41,    64,   114,    69,   115,
       0,    68,     0,    19,    94,     0,    49,    46,    44,    40,
       0,   113,    67,     0,    68,     0,     0,    67,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    58,    22,    23,    24,
      66,    26,    27,    28,   247,   248,   249,   141,   142,   143,
     144,    29,    30,    31,    32,    33,    34,    35,    69,    70,
     226,    36,    67,   197,    37,    51,   167,    39,    40,    41,
     105,   106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
     392,  -196,  -196,   389,   613,   210,    19,    25,   613,    17,
       8,    35,     9,    51,   187,   240,   278,   149,  -196,   392,
    -196,  -196,  -196,  -196,  -196,   176,    63,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   666,  -196,
    -196,  -196,   629,    21,   153,   175,   183,    56,    65,   212,
     176,   141,  -196,  -196,  -196,  -196,   613,   163,  -196,   702,
     179,  -196,   163,   613,  -196,   191,   176,   101,   202,   198,
    -196,   188,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    84,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,   316,  -196,  -196,  -196,   165,
     354,  -196,  -196,   613,   613,   613,   613,   613,   413,   190,
     629,   224,   225,   226,   227,   434,   613,   629,   133,  -196,
     613,   613,   613,   613,   221,  -196,    -9,   711,   613,   133,
     129,   154,   213,  -196,  -196,  -196,    46,   170,   693,  -196,
    -196,   613,   211,  -196,   187,   613,    84,  -196,   165,   125,
     125,  -196,  -196,  -196,   455,    95,    72,   218,   243,   133,
    -196,   613,   613,   613,   613,  -196,    -8,   679,    61,   230,
     245,   250,   471,   492,   176,   176,   176,   176,   513,  -196,
     281,    63,   255,   267,   271,  -196,   255,     4,   255,   176,
     273,  -196,    63,   613,   127,  -196,   534,  -196,   306,   176,
     176,   176,   176,  -196,  -196,  -196,   613,   613,   613,   176,
     613,   176,  -196,    15,   312,   392,   300,   163,   163,  -196,
     255,   331,   300,   255,    63,   550,   639,   146,   571,   176,
     176,   176,   176,  -196,   255,   308,   -17,   300,  -196,  -196,
     213,  -196,  -196,  -196,   300,  -196,  -196,    63,    81,    63,
     550,  -196,    59,  -196,  -196,   163,  -196,  -196,  -196,  -196,
     592,    63,  -196,   186,  -196,    68,   255,  -196,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   -14,  -196,  -196,  -196,   350,  -196,  -196,  -196,
       0,   -27,  -196,  -196,   131,  -187,  -195,   -59,   142,   151,
     -35,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   220,
    -180,  -196,   -46,  -196,  -196,     1,  -196,    24,    31,     3,
     395,    60,  -196
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -148
static const yytype_int16 yytable[] =
{
      25,    38,   136,   147,    50,   112,   265,   129,    59,    55,
     189,   213,     1,     2,    49,   225,   229,    71,   232,    25,
      38,     5,    60,   230,    54,   151,   151,    63,    61,    52,
     140,   130,    12,    64,   243,   140,    53,   255,   231,   103,
     103,    14,   128,    56,    15,    16,   104,   104,    57,   151,
     252,   195,   268,   256,    15,    16,   137,   139,    62,   269,
     267,   134,   139,   148,   263,   196,   266,   267,     1,     2,
      49,   180,   113,   114,   115,   116,   117,     5,   272,   176,
     145,    68,   181,     8,   135,   170,   118,   277,    12,   182,
     183,   166,   179,   151,   119,   118,   278,    14,    47,   270,
      15,    16,   151,   206,   -36,   -36,   113,   114,   115,   116,
     117,   191,   -36,   159,   160,   161,   162,   163,   165,   205,
     169,  -146,  -146,  -146,  -146,   150,   177,   178,   202,   103,
     184,   185,   186,   187,   103,   151,   104,   204,   115,   116,
     117,   104,   223,   180,   113,   114,   115,   116,   117,   111,
     118,   199,   118,   -56,   181,   -56,   -56,    71,   235,   125,
     119,   182,   183,   131,   126,   157,     1,     2,    49,   118,
     157,   209,   210,   211,   212,     5,   234,   260,   192,   237,
     193,   127,   219,   221,   138,   132,    12,   113,   114,   115,
     116,   117,   262,   133,   198,    14,   193,   146,    15,    16,
     140,   140,  -147,  -147,  -147,  -147,   273,   152,   257,   259,
     276,   245,   193,     1,     2,   149,   239,   240,   241,   155,
     242,   168,    15,    16,   275,    25,    38,   139,   139,    47,
      48,   153,   154,   271,   171,   172,   173,   174,   140,   188,
     194,   200,   207,     1,     2,    72,    73,    74,   208,   215,
      75,    76,    77,    78,    79,   216,    80,    81,    82,    83,
     217,    84,    85,    86,    87,   139,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     1,     2,    72,    73,    74,   224,   225,    75,    76,
      77,    78,    79,   227,    80,    81,    82,    83,   228,    84,
      85,    86,    87,   233,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   108,   109,    99,   100,   101,   102,     1,
       2,    72,    73,    74,   238,   246,    75,    76,    77,    78,
      79,   244,    80,    81,    82,    83,   253,    84,    85,    86,
      87,   264,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   156,    98,    99,   100,   101,   102,     1,     2,    72,
      73,    74,    65,   254,    75,    76,    77,    78,    79,   250,
      80,    81,    82,    83,   201,    84,    85,    86,    87,   251,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   108,
     158,    99,   100,   101,   102,     1,     2,     3,     4,    42,
      43,    44,    45,    46,     5,     0,    47,    48,     6,     7,
       8,   110,     9,    10,    11,    12,     1,     2,    49,     0,
       0,     0,    13,     0,    14,     5,     0,    15,    16,     0,
       0,     8,     0,     0,     0,     0,    12,     1,     2,    49,
       0,     0,     0,     0,   164,    14,     5,     0,    15,    16,
       0,     0,     8,   175,     0,     0,     0,    12,     1,     2,
      49,     0,     0,     0,     0,     0,    14,     5,     0,    15,
      16,     0,     0,     8,     1,     2,    49,     0,    12,     0,
       0,   218,     0,     5,     0,     0,   203,    14,     0,     8,
      15,    16,     0,     0,    12,     1,     2,    49,     0,     0,
       0,     0,   220,    14,     5,     0,    15,    16,     0,     0,
       8,     0,     0,     0,     0,    12,     1,     2,    49,     0,
       0,     0,     0,     0,    14,     5,     0,    15,    16,     0,
       0,     8,   222,     0,     0,     0,    12,     1,     2,    49,
       0,     0,     0,     0,     0,    14,     5,     0,    15,    16,
       0,     0,     8,     1,     2,    49,     0,    12,     0,     0,
       0,     0,     5,     0,     0,   236,    14,     0,     8,    15,
      16,     0,     0,    12,     1,     2,    49,     0,     0,     0,
       0,   168,    14,     5,     0,    15,    16,     0,     0,     8,
     261,     0,     0,     0,    12,     1,     2,    49,     0,     0,
       0,     0,     0,    14,     5,     0,    15,    16,     0,     0,
       8,   274,     0,     0,     0,    12,     1,     2,    49,     0,
       0,     0,     0,     0,    14,     5,     0,    15,    16,     0,
       0,     8,     1,     2,    49,     0,    12,     0,     0,     0,
       0,     5,     1,     2,   258,    14,     0,   127,    15,    16,
       0,     5,    12,     0,     0,     0,     0,     8,     0,     0,
       0,    14,    12,     0,    15,    16,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,   120,   121,   122,   123,
     124,     0,     0,     0,   125,     0,     0,     0,     0,   126,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
     190,     0,     0,   214,   113,   114,   115,   116,   117,     0,
       0,     0,   145,   113,   114,   115,   116,   117,   190,     0,
       0,   145,   113,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
       0,     0,    48,    62,     4,    19,    23,    42,     8,     6,
      19,    19,     3,     4,     5,    32,   196,    14,   198,    19,
      19,    12,     5,    19,     5,    34,    34,    18,    20,     5,
      57,    10,    23,    24,    19,    62,     5,   232,    34,    15,
      16,    32,    42,    18,    35,    36,    15,    16,    23,    34,
     230,     5,   247,   233,    35,    36,    56,    57,    23,   254,
     247,     5,    62,    63,   244,    19,   246,   254,     3,     4,
       5,    10,    11,    12,    13,    14,    15,    12,    19,   125,
      19,    30,    21,    18,    19,   120,    23,    19,    23,    28,
      29,   118,   127,    34,    31,    23,   276,    32,    17,    18,
      35,    36,    34,    31,    23,    24,    11,    12,    13,    14,
      15,   138,    31,   113,   114,   115,   116,   117,   118,    24,
     120,    37,    38,    39,    40,    24,   126,   127,   155,   105,
     130,   131,   132,   133,   110,    34,   105,   164,    13,    14,
      15,   110,   188,    10,    11,    12,    13,    14,    15,     0,
      23,   151,    23,    24,    21,    26,    27,   154,    31,    18,
      31,    28,    29,    10,    23,   105,     3,     4,     5,    23,
     110,   171,   172,   173,   174,    12,   203,    31,    24,   206,
      26,    18,   182,   183,    21,    10,    23,    11,    12,    13,
      14,    15,   238,    10,    24,    32,    26,    18,    35,    36,
     227,   228,    37,    38,    39,    40,   265,     5,   235,   236,
      24,   225,    26,     3,     4,    24,   216,   217,   218,    31,
     220,    31,    35,    36,   270,   225,   225,   227,   228,    17,
      18,    33,    34,   260,    10,    10,    10,    10,   265,    18,
      27,    30,    24,     3,     4,     5,     6,     7,     5,    19,
      10,    11,    12,    13,    14,    10,    16,    17,    18,    19,
      10,    21,    22,    23,    24,   265,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     3,     4,     5,     6,     7,     5,    32,    10,    11,
      12,    13,    14,    26,    16,    17,    18,    19,    27,    21,
      22,    23,    24,    30,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     3,
       4,     5,     6,     7,    18,    25,    10,    11,    12,    13,
      14,    19,    16,    17,    18,    19,     5,    21,    22,    23,
      24,    33,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     3,     4,     5,
       6,     7,    12,   232,    10,    11,    12,    13,    14,   227,
      16,    17,    18,    19,   154,    21,    22,    23,    24,   228,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     3,     4,     5,     6,    10,
      11,    12,    13,    14,    12,    -1,    17,    18,    16,    17,
      18,    16,    20,    21,    22,    23,     3,     4,     5,    -1,
      -1,    -1,    30,    -1,    32,    12,    -1,    35,    36,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    23,     3,     4,     5,
      -1,    -1,    -1,    -1,    31,    32,    12,    -1,    35,    36,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    32,    12,    -1,    35,
      36,    -1,    -1,    18,     3,     4,     5,    -1,    23,    -1,
      -1,    10,    -1,    12,    -1,    -1,    31,    32,    -1,    18,
      35,    36,    -1,    -1,    23,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    32,    12,    -1,    35,    36,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    32,    12,    -1,    35,    36,    -1,
      -1,    18,    19,    -1,    -1,    -1,    23,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    32,    12,    -1,    35,    36,
      -1,    -1,    18,     3,     4,     5,    -1,    23,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    31,    32,    -1,    18,    35,
      36,    -1,    -1,    23,     3,     4,     5,    -1,    -1,    -1,
      -1,    31,    32,    12,    -1,    35,    36,    -1,    -1,    18,
      19,    -1,    -1,    -1,    23,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    32,    12,    -1,    35,    36,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    32,    12,    -1,    35,    36,    -1,
      -1,    18,     3,     4,     5,    -1,    23,    -1,    -1,    -1,
      -1,    12,     3,     4,     5,    32,    -1,    18,    35,    36,
      -1,    12,    23,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    32,    23,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    24,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    11,    12,    13,    14,    15,     7,    -1,
      -1,    19,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    12,    16,    17,    18,    20,
      21,    22,    23,    30,    32,    35,    36,    42,    43,    44,
      45,    46,    48,    49,    50,    51,    52,    53,    54,    62,
      63,    64,    65,    66,    67,    68,    72,    75,    76,    78,
      79,    80,    10,    11,    12,    13,    14,    17,    18,     5,
      51,    76,    78,    79,     5,    80,    18,    23,    47,    51,
       5,    20,    23,    18,    24,    47,    51,    73,    30,    69,
      70,    80,     5,     6,     7,    10,    11,    12,    13,    14,
      16,    17,    18,    19,    21,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    78,    79,    81,    82,    83,    35,    36,
      81,     0,    43,    11,    12,    13,    14,    15,    23,    31,
      10,    11,    12,    13,    14,    18,    23,    18,    51,    61,
      10,    10,    10,    10,     5,    19,    73,    51,    21,    51,
      52,    58,    59,    60,    61,    19,    18,    58,    51,    24,
      24,    34,     5,    33,    34,    31,    35,    82,    36,    51,
      51,    51,    51,    51,    31,    51,    52,    77,    31,    51,
      61,    10,    10,    10,    10,    19,    73,    51,    51,    61,
      10,    21,    28,    29,    51,    51,    51,    51,    18,    19,
       7,    52,    24,    26,    27,     5,    19,    74,    24,    51,
      30,    70,    52,    31,    52,    24,    31,    24,     5,    51,
      51,    51,    51,    19,    24,    19,    10,    10,    10,    51,
      10,    51,    19,    73,     5,    32,    71,    26,    27,    71,
      19,    34,    71,    30,    52,    31,    31,    52,    18,    51,
      51,    51,    51,    19,    19,    43,    25,    55,    56,    57,
      59,    60,    71,     5,    55,    57,    71,    52,     5,    52,
      31,    19,    73,    71,    33,    23,    71,    56,    57,    57,
      18,    52,    19,    58,    19,    73,    24,    19,    71
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
        statement_t *stmt = (statement_t*)(yyvsp[(1) - (2)].data);
        stmt->next = (statement_t*)(yyvsp[(2) - (2)].data);
        (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 4:
#line 119 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 123 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 6:
#line 126 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 129 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 132 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 135 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 138 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 141 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 144 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 147 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 150 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 153 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 157 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 17:
#line 159 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 18:
#line 164 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 19:
#line 169 "gram.y"
    {
    (yyval.data) = newForEach((yyvsp[(2) - (6)].data), (yyvsp[(4) - (6)].id), (yyvsp[(6) - (6)].data));
}
    break;

  case 20:
#line 173 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 21:
#line 177 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 22:
#line 181 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 23:
#line 186 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 24:
#line 189 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 25:
#line 195 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 26:
#line 201 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
    break;

  case 27:
#line 207 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
    break;

  case 28:
#line 213 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
    break;

  case 29:
#line 221 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 30:
#line 224 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 31:
#line 227 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 32:
#line 230 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 33:
#line 233 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 34:
#line 236 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 35:
#line 239 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 36:
#line 242 "gram.y"
    {
      (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 37:
#line 245 "gram.y"
    {
      (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 38:
#line 250 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 39:
#line 253 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 40:
#line 260 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 41:
#line 268 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 42:
#line 277 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 43:
#line 280 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 44:
#line 287 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 45:
#line 295 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);

        (yyval.data) = ifs;
    }
    break;

  case 46:
#line 304 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 47:
#line 311 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 48:
#line 316 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 49:
#line 323 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 50:
#line 329 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
    }
    break;

  case 51:
#line 332 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 52:
#line 337 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data), NULL);
    }
    break;

  case 53:
#line 340 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 54:
#line 345 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 55:
#line 348 "gram.y"
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[(2) - (2)].data));
        (yyval.data) = cond;
    }
    break;

  case 56:
#line 353 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 57:
#line 358 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 58:
#line 361 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 59:
#line 364 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 60:
#line 367 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 61:
#line 370 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 62:
#line 373 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 63:
#line 376 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 64:
#line 380 "gram.y"
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

  case 65:
#line 414 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 66:
#line 417 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 67:
#line 422 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(6) - (7)].data));
    }
    break;

  case 68:
#line 425 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (6)].data), (yyvsp[(4) - (6)].id), NULL);
    }
    break;

  case 69:
#line 428 "gram.y"
    {
        (yyval.data) = newClassAccesser((yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].id));
    }
    break;

  case 70:
#line 434 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 71:
#line 438 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 72:
#line 442 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 73:
#line 445 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (4)].data);
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 74:
#line 449 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (3)].data);
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 75:
#line 455 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(3) - (5)].id));
        expr_t *expr = newExpr_ID((yyvsp[(1) - (5)].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
    break;

  case 76:
#line 461 "gram.y"
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

  case 77:
#line 475 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 78:
#line 480 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 79:
#line 487 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 80:
#line 494 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 81:
#line 501 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
    break;

  case 82:
#line 508 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 83:
#line 514 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 84:
#line 520 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 85:
#line 526 "gram.y"
    {
        expr_t *valexpr = (yyvsp[(4) - (4)].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[(1) - (4)].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[(1) - (4)].data),opadd);
    }
    break;

  case 86:
#line 532 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 87:
#line 537 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 88:
#line 540 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 89:
#line 545 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(2) - (3)].data));
    }
    break;

  case 90:
#line 550 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (3)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(3) - (3)].data);

      right->next = left;
      (yyval.data) = right;
    }
    break;

  case 91:
#line 557 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 92:
#line 560 "gram.y"
    {
        (yyval.data) = NULL;
    }
    break;

  case 93:
#line 565 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 94:
#line 576 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 95:
#line 581 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(2) - (3)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 96:
#line 586 "gram.y"
    {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(2) - (3)].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
    break;

  case 97:
#line 590 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 98:
#line 595 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 99:
#line 599 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 100:
#line 604 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 101:
#line 609 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 102:
#line 615 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 103:
#line 618 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 104:
#line 622 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 105:
#line 625 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 106:
#line 631 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 107:
#line 637 "gram.y"
    {
        expr_t *id = (yyvsp[(1) - (4)].data);
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 108:
#line 643 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 109:
#line 648 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data), NULL);
  }
    break;

  case 110:
#line 651 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (2)].data), NULL);
  }
    break;

  case 111:
#line 654 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (2)].data), NULL, NULL);
  }
    break;

  case 112:
#line 657 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 113:
#line 660 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
  }
    break;

  case 114:
#line 663 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
  }
    break;

  case 115:
#line 666 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
  }
    break;

  case 116:
#line 669 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[(3) - (3)].data));
  }
    break;

  case 117:
#line 672 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 118:
#line 677 "gram.y"
    {
      if ( strlen(yyval.id) >= 10 ) {
        (yyval.data) = newExpr_BigIntFromStr(yyval.id);
      } else {
        (yyval.data) = newExpr_Ival(atoi(yyval.id));
      }
    }
    break;

  case 119:
#line 686 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 120:
#line 691 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 121:
#line 694 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 122:
#line 697 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 123:
#line 701 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 124:
#line 707 "gram.y"
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

  case 125:
#line 735 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 126:
#line 740 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 127:
#line 743 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 128:
#line 750 "gram.y"
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
        }
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 129:
#line 765 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 130:
#line 770 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 131:
#line 775 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 132:
#line 780 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 133:
#line 785 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 134:
#line 790 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 135:
#line 794 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 136:
#line 798 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 137:
#line 802 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 138:
#line 806 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 139:
#line 810 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 140:
#line 814 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 141:
#line 818 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 142:
#line 822 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 143:
#line 826 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 144:
#line 830 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 145:
#line 834 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 146:
#line 838 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 147:
#line 842 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 148:
#line 846 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 149:
#line 850 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 150:
#line 854 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 151:
#line 858 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 152:
#line 862 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 153:
#line 866 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 154:
#line 870 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 155:
#line 874 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 156:
#line 878 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 157:
#line 882 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 158:
#line 886 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 159:
#line 890 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3060 "y.tab.c"
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


#line 895 "gram.y"


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

