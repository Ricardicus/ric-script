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




/* Copy the first part of user declarations.  */
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
#line 37 "gram.y"
{ int val_int; double val_double; char id[256]; void *data; }
/* Line 193 of yacc.c.  */
#line 168 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 181 "y.tab.c"

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

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
       2,     2,    41,    26,    40,     2,    24,    23,     2,    39,
      33,    34,    21,    19,    37,    20,    29,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
      31,    18,    32,    42,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,    43,    28,     2,     2,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    34,    37,    40,
      43,    46,    48,    51,    56,    62,    69,    75,    80,    86,
      93,    99,   105,   112,   120,   127,   133,   140,   148,   155,
     158,   160,   166,   169,   174,   179,   184,   189,   194,   198,
     202,   209,   215,   220,   224,   228,   232,   236,   240,   244,
     248,   252,   256,   260,   264,   268,   270,   274,   278,   282,
     286,   289,   293,   295,   299,   301,   305,   307,   311,   315,
     319,   323,   327,   329,   331,   333,   336,   338,   341,   343,
     347,   349,   353,   358,   363,   368,   373,   378,   383,   385,
     387,   391,   395,   399,   403,   407,   409,   413,   417,   419,
     422,   425,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   466,   468,   470,   472,   474
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    47,    46,    -1,    -1,    60,
      -1,    58,    -1,    59,    -1,    52,    -1,    53,    -1,    68,
      -1,    73,    -1,    50,    -1,    51,    -1,    49,    -1,    48,
      -1,    24,     5,    -1,    24,    73,    -1,     6,    68,    -1,
       6,    73,    -1,     6,     5,    -1,    25,    -1,    26,    25,
      -1,    27,    57,    28,    64,    -1,    27,    57,    28,    64,
      54,    -1,    27,    57,    28,    64,    54,    56,    -1,    27,
      57,    28,    64,    56,    -1,    27,    68,    28,    64,    -1,
      27,    68,    28,    64,    54,    -1,    27,    68,    28,    64,
      54,    56,    -1,    27,    68,    28,    64,    56,    -1,    29,
      27,    57,    28,    64,    -1,    29,    27,    57,    28,    64,
      54,    -1,    29,    27,    57,    28,    64,    54,    56,    -1,
      29,    27,    57,    28,    64,    56,    -1,    29,    27,    68,
      28,    64,    -1,    29,    27,    68,    28,    64,    54,    -1,
      29,    27,    68,    28,    64,    54,    56,    -1,    29,    27,
      68,    28,    64,    56,    -1,    54,    55,    -1,    55,    -1,
      30,    27,    57,    28,    64,    -1,    30,    64,    -1,    68,
      18,    18,    68,    -1,    73,    18,    18,    73,    -1,    68,
      26,    18,    68,    -1,    68,    31,    18,    68,    -1,    68,
      32,    18,    68,    -1,    68,    31,    68,    -1,    68,    32,
      68,    -1,    25,     5,    33,    67,    34,    64,    -1,    25,
       5,    33,    34,    64,    -1,     5,    33,    66,    34,    -1,
       5,    33,    34,    -1,     5,    18,    73,    -1,     5,    18,
      68,    -1,     5,    18,    61,    -1,     5,    18,    57,    -1,
       5,    18,    65,    -1,    70,    18,    73,    -1,    70,    18,
      68,    -1,    70,    18,    57,    -1,    70,    18,    65,    -1,
      35,    62,    36,    -1,    62,    37,    63,    -1,    63,    -1,
      73,    38,    68,    -1,    73,    38,    73,    -1,    35,    46,
      36,    -1,    27,    66,    28,    -1,    27,    28,    -1,    66,
      37,    68,    -1,    68,    -1,    66,    37,    73,    -1,    73,
      -1,    67,    37,     5,    -1,     5,    -1,    68,    19,    69,
      -1,    68,    20,    69,    -1,    68,    21,    69,    -1,    68,
      23,    69,    -1,    68,    22,    69,    -1,    69,    -1,     5,
      -1,    72,    -1,    20,    72,    -1,    71,    -1,    20,    71,
      -1,    70,    -1,    33,    68,    34,    -1,    59,    -1,    33,
      57,    34,    -1,     5,    27,    71,    28,    -1,     5,    27,
       5,    28,    -1,     5,    27,    73,    28,    -1,    70,    27,
      71,    28,    -1,    70,    27,     5,    28,    -1,    70,    27,
      73,    28,    -1,     3,    -1,     4,    -1,    73,    19,    74,
      -1,    73,    19,     5,    -1,    73,    19,    72,    -1,    73,
      19,    71,    -1,    73,    19,    70,    -1,    74,    -1,    39,
      75,    39,    -1,    40,    75,    40,    -1,    59,    -1,    40,
      40,    -1,    39,    39,    -1,    75,    76,    -1,    76,    -1,
       5,    -1,    72,    -1,    71,    -1,    77,    -1,    19,    -1,
      41,    -1,    42,    -1,    31,    -1,    32,    -1,    20,    -1,
      22,    -1,    43,    -1,    38,    -1,    33,    -1,    34,    -1,
      26,    -1,    37,    -1,    39,    -1,    40,    -1,    29,    -1,
      27,    -1,    28,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   111,   116,   120,   123,   126,   129,   132,
     135,   138,   141,   144,   147,   150,   154,   156,   160,   162,
     164,   168,   172,   177,   180,   187,   195,   202,   208,   218,
     229,   241,   244,   251,   259,   266,   272,   282,   293,   305,
     312,   317,   324,   330,   333,   336,   339,   342,   345,   348,
     353,   356,   361,   364,   369,   374,   379,   384,   389,   393,
     396,   399,   402,   407,   412,   419,   424,   433,   444,   449,
     453,   458,   462,   465,   469,   474,   479,   485,   488,   491,
     494,   497,   500,   505,   508,   511,   516,   519,   524,   527,
     530,   533,   538,   544,   549,   554,   557,   561,   566,   571,
     576,   582,   588,   597,   606,   612,   617,   620,   623,   626,
     630,   636,   661,   666,   669,   675,   681,   686,   691,   696,
     700,   704,   708,   712,   716,   720,   724,   728,   732,   736,
     740,   744,   748,   752,   756,   760
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "COMMENT", "NEWLINE", "KEY_FLOAT", "KEY_INT", "KEY_STR", "KEY_STRUCT",
  "KEY_PROCESS", "WHITESPACE", "OPEN", "CLOSE", "OTHER", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'$'", "'@'", "'!'", "'['", "']'", "'.'",
  "'~'", "'<'", "'>'", "'('", "')'", "'{'", "'}'", "','", "':'", "'''",
  "'\"'", "' '", "'?'", "'\\\\'", "$accept", "program", "statements",
  "statement", "systemStatement", "returnStatement", "continueStatement",
  "breakStatement", "ifStatement", "loopStatement", "middleIfs",
  "middleIf", "endIf", "condition", "function", "functionCall",
  "declaration", "dictionary", "dictionary_keys_vals",
  "dictionary_key_val", "body", "vector", "arguments_list",
  "parameters_list", "mathContents", "mathContent", "indexedVector",
  "mathContentDigit", "mathContentDouble", "stringContents",
  "stringContent", "stringEditions", "stringEdition", "otherChar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,    36,    64,    33,    91,    93,    46,
     126,    60,    62,    40,    41,   123,   125,    44,    58,    39,
      34,    32,    63,    92
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    49,
      49,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    62,    62,    63,    63,    64,    65,
      65,    66,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    72,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     1,     2,     4,     5,     6,     5,     4,     5,     6,
       5,     5,     6,     7,     6,     5,     6,     7,     6,     2,
       1,     5,     2,     4,     4,     4,     4,     4,     3,     3,
       6,     5,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       2,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     1,     2,     1,     3,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    98,    99,    83,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     2,     4,    15,    14,    12,
      13,     8,     9,     6,     7,     5,    10,    82,    88,    86,
      84,    11,   105,     0,     0,     0,    20,    90,    18,    88,
      19,    87,    85,    16,   108,    17,     0,    22,    83,     0,
       0,     0,     0,     0,     0,   113,   135,   117,   122,   123,
     128,   133,   134,   132,   120,   121,   126,   127,   129,   125,
     110,   131,   118,   119,   124,   115,   114,     0,   112,   116,
     130,   109,     0,     1,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    56,    58,    55,    54,
       0,     0,     0,    53,     0,    72,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    89,   106,
     111,   107,    90,    77,    78,    79,    81,    80,    61,    62,
      60,    59,     0,     0,     0,   101,   104,   103,   102,   100,
      70,     0,     0,     0,    65,     0,    93,    92,    94,    52,
       0,    76,     0,     0,     4,    23,     0,     0,    27,     0,
      48,     0,    49,     0,     0,     0,    96,    95,    97,    69,
      63,     0,     0,    71,    73,    51,     0,     0,     0,     0,
      24,    40,    26,    43,    45,    28,    30,    46,    47,    44,
      31,    35,    64,    66,    67,    50,    75,    68,     0,    42,
      39,    25,    29,    32,    34,    36,    38,     0,     0,    33,
      37,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     180,   181,   182,    49,    23,    37,    25,    96,   143,   144,
     155,    97,   104,   153,    26,    27,    39,    29,    30,    51,
      32,    77,    78,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
     356,  -141,  -141,    39,   395,    12,     7,    31,    -8,   405,
      33,   405,   192,   233,   129,  -141,   356,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   194,  -141,   223,  -141,    34,  -141,
    -141,   114,  -141,   139,    19,   131,   303,  -141,   223,    44,
     114,  -141,  -141,   115,  -141,   114,   117,  -141,    52,   134,
     428,    81,   405,   135,   398,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
      96,  -141,  -141,  -141,  -141,  -141,  -141,   274,  -141,  -141,
    -141,   161,   315,  -141,  -141,   277,   277,   277,   277,   277,
     364,    85,    71,   374,    64,  -141,  -141,  -141,   458,    81,
     128,   145,    45,  -141,    47,   223,   114,    -2,   142,   162,
     172,   142,   127,   236,   180,   173,   443,  -141,  -141,    96,
    -141,   161,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
     458,    81,   153,   181,    49,    52,    44,  -141,  -141,  -141,
    -141,    84,   115,   170,  -141,    11,  -141,  -141,  -141,  -141,
     405,  -141,   142,    89,   356,   178,   277,   277,   178,   277,
     223,   277,   223,    64,   142,   142,  -141,  -141,  -141,  -141,
    -141,    64,   405,   223,   114,  -141,   142,   217,   191,     6,
     178,  -141,  -141,   223,   223,   178,  -141,   223,   223,   114,
     178,   178,  -141,   223,   114,  -141,  -141,  -141,   405,  -141,
    -141,  -141,  -141,   178,  -141,   178,  -141,   200,   458,  -141,
    -141,   142,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,    -5,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -137,   -98,  -140,   -10,  -141,    28,  -141,  -141,  -141,    76,
    -109,   158,   156,  -141,    -4,   198,     9,     1,    14,     4,
     165,   237,   123,  -141
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -132
static const yytype_int16 yytable[] =
{
      38,    53,   158,   151,    31,    50,    41,    54,    40,    28,
      45,    84,    43,    75,    75,     1,     2,    47,   186,    42,
      31,   185,     1,    95,   100,    28,    76,    76,    24,    98,
      92,   105,   152,   198,    44,   101,    46,    99,   102,   106,
     201,   154,   115,   175,    24,   202,    12,    13,   116,   172,
     204,   206,    90,   203,   205,   190,   191,    33,    12,    13,
      52,    91,    44,   209,    92,   210,    34,   195,    92,   142,
     199,    91,    35,   148,     1,     2,   135,   168,    75,    34,
     128,   149,   200,    75,   150,    35,   130,   200,     1,   105,
     132,    76,   133,   137,   131,   134,    76,   106,   145,   114,
      92,   136,   212,    12,    13,   200,   138,   200,   160,   162,
      12,    13,   169,   122,   122,   122,   122,   122,  -130,    44,
      44,   150,    44,   176,    12,    13,   177,  -130,  -130,    83,
       1,     2,    48,    92,     1,     2,    48,  -130,  -130,  -130,
     122,   122,     1,     2,    48,   159,   173,     5,    35,   178,
     107,     5,   183,   184,   174,   187,   146,   188,    31,     5,
      11,    35,   108,    28,    11,   103,    93,   189,   193,   117,
      12,    13,    11,   147,    94,   145,   194,   154,    12,    13,
     156,   166,    24,  -131,   122,   122,    35,   122,   207,   122,
     157,    44,  -131,  -131,   208,     1,     2,    55,   163,    44,
     120,   164,  -131,  -131,  -131,   120,   170,   171,   179,   167,
      56,    57,    58,   -90,    59,   -90,   -90,   -90,    60,    61,
      62,    63,   196,    64,    65,    66,    67,   197,   211,    68,
      69,    70,    71,    72,    73,    74,     1,     2,    55,     1,
       2,    48,    85,    86,    87,    88,    89,   192,   129,   141,
      82,    56,    57,    58,   161,    59,     5,   139,     0,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,    11,
      68,    69,    80,    81,    72,    73,    74,     1,     2,    55,
       1,     2,    48,   123,   124,   125,   126,   127,     0,     0,
       0,     0,    56,    57,    58,     0,    59,     5,     0,     0,
      60,    61,    62,    63,     0,    64,    65,    66,    67,     0,
      11,    68,    69,   119,    71,    72,    73,    74,     1,     2,
      55,     0,   -83,     0,   -83,   -83,   -83,     0,     0,     0,
      34,     0,     0,    56,    57,    58,    35,    59,     0,     0,
       0,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    80,   121,    72,    73,    74,     1,
       2,     3,     4,     0,     0,     0,     0,     1,     2,    48,
       0,     0,     0,     0,     0,     0,     5,     1,     2,    48,
       6,     7,     8,     9,     5,    10,     0,     0,     0,    11,
       0,    93,     0,     0,     5,    12,    13,    11,     1,     2,
      36,     0,   140,    12,    13,     0,     0,    11,     1,     2,
      48,     0,     0,    12,    13,     5,   109,    85,    86,    87,
      88,    89,     0,     0,   110,     5,     0,     0,    11,   112,
     113,     0,   118,     0,    12,    13,     0,     0,    11,     0,
       0,     0,     0,     0,    12,    13,   109,    85,    86,    87,
      88,    89,     0,     0,   110,     0,   111,     0,     0,   112,
     113,   109,    85,    86,    87,    88,    89,     0,     0,   110,
       0,   165,     0,     0,   112,   113,   109,    85,    86,    87,
      88,    89,     0,     0,   110,     0,     0,     0,     0,   112,
     113
};

static const yytype_int16 yycheck[] =
{
       4,    11,   111,     5,     0,     9,     5,    11,     4,     0,
       6,    16,     5,    12,    13,     3,     4,    25,   158,     5,
      16,   158,     3,    33,     5,    16,    12,    13,     0,    33,
      19,    35,    34,    27,     6,    34,     5,    33,    34,    35,
     180,    35,    52,   152,    16,   185,    39,    40,    52,    38,
     190,   191,    18,   190,   191,   164,   165,    18,    39,    40,
      27,    27,    34,   203,    19,   205,    27,   176,    19,     5,
     179,    27,    33,    28,     3,     4,     5,    28,    77,    27,
      90,    34,   180,    82,    37,    33,    90,   185,     3,    93,
       5,    77,    91,    92,    90,    91,    82,    93,    94,    18,
      19,    92,   211,    39,    40,   203,    92,   205,   112,   113,
      39,    40,    28,    85,    86,    87,    88,    89,    22,    91,
      92,    37,    94,    34,    39,    40,    37,    31,    32,     0,
       3,     4,     5,    19,     3,     4,     5,    41,    42,    43,
     112,   113,     3,     4,     5,    18,   150,    20,    33,   154,
      33,    20,   156,   157,   150,   159,    28,   161,   154,    20,
      33,    33,    28,   154,    33,    34,    27,   163,   172,    34,
      39,    40,    33,    28,    35,   171,   172,    35,    39,    40,
      18,    28,   154,    22,   156,   157,    33,   159,   198,   161,
      18,   163,    31,    32,   198,     3,     4,     5,    18,   171,
      77,    28,    41,    42,    43,    82,    36,    37,    30,    28,
      18,    19,    20,    19,    22,    21,    22,    23,    26,    27,
      28,    29,     5,    31,    32,    33,    34,    36,    28,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     3,
       4,     5,    19,    20,    21,    22,    23,   171,    90,    93,
      13,    18,    19,    20,    18,    22,    20,    92,    -1,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    -1,    33,
      37,    38,    39,    40,    41,    42,    43,     3,     4,     5,
       3,     4,     5,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    22,    20,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    -1,
      33,    37,    38,    39,    40,    41,    42,    43,     3,     4,
       5,    -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    -1,    18,    19,    20,    33,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    20,     3,     4,     5,
      24,    25,    26,    27,    20,    29,    -1,    -1,    -1,    33,
      -1,    27,    -1,    -1,    20,    39,    40,    33,     3,     4,
       5,    -1,    28,    39,    40,    -1,    -1,    33,     3,     4,
       5,    -1,    -1,    39,    40,    20,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    20,    -1,    -1,    33,    31,
      32,    -1,    34,    -1,    39,    40,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    28,    -1,    -1,    31,
      32,    18,    19,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    28,    -1,    -1,    31,    32,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    27,
      29,    33,    39,    40,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    58,    59,    60,    68,    69,    70,    71,
      72,    73,    74,    18,    27,    33,     5,    59,    68,    70,
      73,    71,    72,     5,    59,    73,     5,    25,     5,    57,
      68,    73,    27,    57,    68,     5,    18,    19,    20,    22,
      26,    27,    28,    29,    31,    32,    33,    34,    37,    38,
      39,    40,    41,    42,    43,    71,    72,    75,    76,    77,
      39,    40,    75,     0,    46,    19,    20,    21,    22,    23,
      18,    27,    19,    27,    35,    57,    61,    65,    68,    73,
       5,    71,    73,    34,    66,    68,    73,    33,    28,    18,
      26,    28,    31,    32,    18,    57,    68,    34,    34,    39,
      76,    40,    59,    69,    69,    69,    69,    69,    57,    65,
      68,    73,     5,    71,    73,     5,    70,    71,    72,    74,
      28,    66,     5,    62,    63,    73,    28,    28,    28,    34,
      37,     5,    34,    67,    35,    64,    18,    18,    64,    18,
      68,    18,    68,    18,    28,    28,    28,    28,    28,    28,
      36,    37,    38,    68,    73,    64,    34,    37,    46,    30,
      54,    55,    56,    68,    68,    54,    56,    68,    68,    73,
      64,    64,    63,    68,    73,    64,     5,    36,    27,    64,
      55,    56,    56,    54,    56,    54,    56,    57,    68,    56,
      56,    28,    64
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
#line 94 "gram.y"
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
#line 111 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(1) - (2)].data);
        stmt->next = (statement_t*)(yyvsp[(2) - (2)].data);
        (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 4:
#line 116 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 120 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 6:
#line 123 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 126 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCCALL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 129 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 132 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 135 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_MATH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 138 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_STR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 141 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 144 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 147 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 150 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 154 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 17:
#line 156 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 18:
#line 160 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 19:
#line 162 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 20:
#line 164 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 21:
#line 168 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 22:
#line 172 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 23:
#line 177 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 24:
#line 180 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 25:
#line 187 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (6)].data), (yyvsp[(4) - (6)].data));

        ifs->elif = (yyvsp[(5) - (6)].data);
        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 26:
#line 195 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 27:
#line 202 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (4)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (4)].data));
    }
    break;

  case 28:
#line 208 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 29:
#line 218 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (6)].data));

        ifs->elif = (yyvsp[(5) - (6)].data);
        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 30:
#line 229 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 31:
#line 241 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 32:
#line 244 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 33:
#line 251 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 34:
#line 259 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 35:
#line 266 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (5)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (5)].data));
    }
    break;

  case 36:
#line 272 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 37:
#line 282 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (7)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 38:
#line 293 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 39:
#line 305 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 40:
#line 312 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 41:
#line 317 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 42:
#line 324 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 43:
#line 330 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 44:
#line 333 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 45:
#line 336 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 46:
#line 339 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 47:
#line 342 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 48:
#line 345 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 49:
#line 348 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 50:
#line 353 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 51:
#line 356 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 52:
#line 361 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].data));
    }
    break;

  case 53:
#line 364 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (3)].id),NULL);
    }
    break;

  case 54:
#line 369 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 55:
#line 374 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 56:
#line 379 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 57:
#line 384 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *condexpr = newExpr_Cond((yyvsp[(3) - (3)].data));
        (yyval.data) = newDeclaration(idexpr,condexpr);
    }
    break;

  case 58:
#line 389 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 59:
#line 393 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 60:
#line 396 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 61:
#line 399 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 62:
#line 402 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 63:
#line 407 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(2) - (3)].data));
    }
    break;

  case 64:
#line 412 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (3)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(3) - (3)].data);

      left->next = right;
      (yyval.data) = left;
    }
    break;

  case 65:
#line 419 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 66:
#line 424 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);

      (yyval.data) = keyVal;
    }
    break;

  case 67:
#line 433 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);

      (yyval.data) = keyVal;
    }
    break;

  case 68:
#line 444 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 69:
#line 449 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(2) - (3)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 70:
#line 453 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 71:
#line 458 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 72:
#line 462 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 73:
#line 465 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 74:
#line 469 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 75:
#line 474 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 76:
#line 479 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 77:
#line 485 "gram.y"
    {
        (yyval.data) = newExpr_OPAdd((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 78:
#line 488 "gram.y"
    {
        (yyval.data) = newExpr_OPSub((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 79:
#line 491 "gram.y"
    {
        (yyval.data) = newExpr_OPMul((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 80:
#line 494 "gram.y"
    {
        (yyval.data) = newExpr_OPMod((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 81:
#line 497 "gram.y"
    {
        (yyval.data) = newExpr_OPDiv((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 82:
#line 500 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 83:
#line 505 "gram.y"
    {
        (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 84:
#line 508 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 85:
#line 511 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[(2) - (2)].data);
        double val = e->fval * -1.0;
        (yyval.data) = newExpr_Float(val);
    }
    break;

  case 86:
#line 516 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 87:
#line 519 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[(2) - (2)].data);
        int val = e->ival * -1;
        (yyval.data) = newExpr_Ival(val);
    }
    break;

  case 88:
#line 524 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 89:
#line 527 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 90:
#line 530 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[(1) - (1)].data));
    }
    break;

  case 91:
#line 533 "gram.y"
    {
        (yyval.data) = newExpr_Cond((yyvsp[(2) - (3)].data));
    }
    break;

  case 92:
#line 538 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 93:
#line 544 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = newExpr_ID((yyvsp[(3) - (4)].id));
        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 94:
#line 549 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = newExpr_ID((yyvsp[(3) - (4)].data));
        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 95:
#line 554 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 96:
#line 557 "gram.y"
    {
      expr_t *index = newExpr_ID((yyvsp[(3) - (4)].id));
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), index);
    }
    break;

  case 97:
#line 561 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 98:
#line 566 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
    break;

  case 99:
#line 571 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 100:
#line 576 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 101:
#line 582 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = newExpr_ID((yyvsp[(3) - (3)].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 102:
#line 588 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 103:
#line 597 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 104:
#line 606 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 105:
#line 612 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 106:
#line 617 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 107:
#line 620 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 108:
#line 623 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[(1) - (1)].data));
    }
    break;

  case 109:
#line 626 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 110:
#line 630 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 111:
#line 636 "gram.y"
    {
        char *textBuffer;

        expr_t *e1 = (expr_t*)(yyvsp[(1) - (2)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(2) - (2)].data);

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
    break;

  case 112:
#line 661 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 113:
#line 666 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 114:
#line 669 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 115:
#line 675 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 116:
#line 681 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 117:
#line 686 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 118:
#line 691 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 119:
#line 696 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 120:
#line 700 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 121:
#line 704 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 122:
#line 708 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 123:
#line 712 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 124:
#line 716 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 125:
#line 720 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 126:
#line 724 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 127:
#line 728 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 128:
#line 732 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 129:
#line 736 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 130:
#line 740 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 131:
#line 744 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 132:
#line 748 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 133:
#line 752 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 134:
#line 756 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 135:
#line 760 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2790 "y.tab.c"
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


#line 765 "gram.y"


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

