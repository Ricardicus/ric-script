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
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

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
     248,   252,   256,   260,   264,   267,   271,   273,   277,   279,
     283,   285,   289,   293,   297,   301,   305,   307,   309,   311,
     314,   316,   319,   321,   325,   327,   331,   336,   341,   346,
     351,   353,   355,   359,   363,   367,   371,   375,   377,   381,
     385,   387,   390,   393,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   442
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    47,    46,    -1,    -1,    60,
      -1,    58,    -1,    59,    -1,    52,    -1,    53,    -1,    65,
      -1,    70,    -1,    50,    -1,    51,    -1,    49,    -1,    48,
      -1,    24,     5,    -1,    24,    70,    -1,     6,    65,    -1,
       6,    70,    -1,     6,     5,    -1,    25,    -1,    26,    25,
      -1,    27,    57,    28,    61,    -1,    27,    57,    28,    61,
      54,    -1,    27,    57,    28,    61,    54,    56,    -1,    27,
      57,    28,    61,    56,    -1,    27,    65,    28,    61,    -1,
      27,    65,    28,    61,    54,    -1,    27,    65,    28,    61,
      54,    56,    -1,    27,    65,    28,    61,    56,    -1,    29,
      27,    57,    28,    61,    -1,    29,    27,    57,    28,    61,
      54,    -1,    29,    27,    57,    28,    61,    54,    56,    -1,
      29,    27,    57,    28,    61,    56,    -1,    29,    27,    65,
      28,    61,    -1,    29,    27,    65,    28,    61,    54,    -1,
      29,    27,    65,    28,    61,    54,    56,    -1,    29,    27,
      65,    28,    61,    56,    -1,    54,    55,    -1,    55,    -1,
      30,    27,    57,    28,    61,    -1,    30,    61,    -1,    65,
      18,    18,    65,    -1,    70,    18,    18,    70,    -1,    65,
      26,    18,    65,    -1,    65,    31,    18,    65,    -1,    65,
      32,    18,    65,    -1,    65,    31,    65,    -1,    65,    32,
      65,    -1,    25,     5,    33,    64,    34,    61,    -1,    25,
       5,    33,    34,    61,    -1,     5,    33,    63,    34,    -1,
       5,    33,    34,    -1,     5,    18,    70,    -1,     5,    18,
      65,    -1,     5,    18,    57,    -1,     5,    18,    62,    -1,
      67,    18,    70,    -1,    67,    18,    65,    -1,    67,    18,
      57,    -1,    67,    18,    62,    -1,    35,    46,    36,    -1,
      27,    63,    28,    -1,    27,    28,    -1,    63,    37,    65,
      -1,    65,    -1,    63,    37,    70,    -1,    70,    -1,    64,
      37,     5,    -1,     5,    -1,    65,    19,    66,    -1,    65,
      20,    66,    -1,    65,    21,    66,    -1,    65,    23,    66,
      -1,    65,    22,    66,    -1,    66,    -1,     5,    -1,    69,
      -1,    20,    69,    -1,    68,    -1,    20,    68,    -1,    67,
      -1,    33,    65,    34,    -1,    59,    -1,    33,    57,    34,
      -1,     5,    27,    68,    28,    -1,     5,    27,     5,    28,
      -1,    67,    27,    68,    28,    -1,    67,    27,     5,    28,
      -1,     3,    -1,     4,    -1,    70,    19,    71,    -1,    70,
      19,     5,    -1,    70,    19,    69,    -1,    70,    19,    68,
      -1,    70,    19,    67,    -1,    71,    -1,    38,    72,    38,
      -1,    39,    72,    39,    -1,    59,    -1,    39,    39,    -1,
      38,    38,    -1,    72,    73,    -1,    73,    -1,     5,    -1,
      69,    -1,    68,    -1,    74,    -1,    19,    -1,    40,    -1,
      41,    -1,    31,    -1,    32,    -1,    20,    -1,    22,    -1,
      42,    -1,    43,    -1,    33,    -1,    34,    -1,    26,    -1,
      37,    -1,    38,    -1,    39,    -1,    29,    -1,    27,    -1,
      28,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,   108,   113,   117,   120,   123,   126,   129,
     132,   135,   138,   141,   144,   147,   151,   153,   157,   159,
     161,   165,   169,   174,   177,   184,   192,   199,   205,   215,
     226,   238,   241,   248,   256,   263,   269,   279,   290,   302,
     309,   314,   321,   327,   330,   333,   336,   339,   342,   345,
     350,   353,   358,   361,   366,   371,   376,   381,   385,   388,
     391,   394,   399,   404,   408,   413,   417,   420,   424,   429,
     434,   440,   443,   446,   449,   452,   455,   460,   463,   466,
     471,   474,   479,   482,   485,   488,   493,   499,   504,   507,
     513,   518,   523,   529,   535,   544,   553,   559,   564,   567,
     570,   573,   577,   583,   608,   613,   616,   622,   628,   633,
     638,   643,   647,   651,   655,   659,   663,   667,   671,   675,
     679,   683,   687,   691,   695,   699,   703,   707
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
  "'~'", "'<'", "'>'", "'('", "')'", "'{'", "'}'", "','", "'''", "'\"'",
  "' '", "'?'", "'\\\\'", "':'", "$accept", "program", "statements",
  "statement", "systemStatement", "returnStatement", "continueStatement",
  "breakStatement", "ifStatement", "loopStatement", "middleIfs",
  "middleIf", "endIf", "condition", "function", "functionCall",
  "declaration", "body", "vector", "arguments_list", "parameters_list",
  "mathContents", "mathContent", "indexedVector", "mathContentDigit",
  "mathContentDouble", "stringContents", "stringContent", "stringEditions",
  "stringEdition", "otherChar", 0
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
     126,    60,    62,    40,    41,   123,   125,    44,    39,    34,
      32,    63,    92,    58
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
      60,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74
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
       3,     3,     3,     3,     2,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     2,
       1,     2,     1,     3,     1,     3,     4,     4,     4,     4,
       1,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    90,    91,    77,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     2,     4,    15,    14,    12,
      13,     8,     9,     6,     7,     5,    10,    76,    82,    80,
      78,    11,    97,     0,     0,     0,    20,    84,    18,    82,
      19,    81,    79,    16,   100,    17,     0,    22,    77,     0,
       0,     0,     0,     0,     0,   105,   127,   109,   114,   115,
     120,   125,   126,   124,   112,   113,   118,   119,   121,   102,
     123,   110,   111,   116,   117,   107,   106,     0,   104,   108,
     122,   101,     0,     1,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    55,    54,     0,     0,
      53,     0,    66,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    83,    98,   103,    99,    84,
      71,    72,    73,    75,    74,    60,    61,    59,    58,     0,
       0,    93,    96,    95,    94,    92,    64,     0,    87,    86,
      52,     0,    70,     0,     0,     4,    23,     0,     0,    27,
       0,    48,     0,    49,     0,     0,     0,    89,    88,    63,
      65,    67,    51,     0,     0,     0,     0,    24,    40,    26,
      43,    45,    28,    30,    46,    47,     0,    44,    31,    35,
      50,    69,    62,     0,    42,    39,    25,    29,    32,    34,
      36,    38,     0,     0,    33,    37,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     167,   168,   169,    49,    23,   119,    25,   146,    95,   101,
     144,    26,    27,    39,    29,    30,    51,    32,    77,    78,
      79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -122
static const yytype_int16 yypact[] =
{
      96,  -122,  -122,    41,   349,   129,     2,    -2,    29,   372,
      37,   372,   159,   200,    73,  -122,    96,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   153,  -122,   190,  -122,    -3,  -122,
    -122,    65,  -122,   323,    82,   326,   117,  -122,   190,    71,
      65,  -122,  -122,    86,  -122,    65,    97,  -122,    56,    78,
     418,   128,   372,    81,   401,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   358,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,   241,  -122,  -122,
    -122,   375,   282,  -122,  -122,   123,   123,   123,   123,   123,
     323,    92,    74,   335,  -122,  -122,   448,   128,   109,   124,
    -122,   -12,   190,    65,    16,   122,   142,   143,   122,   162,
     203,   151,   161,   433,  -122,  -122,   358,  -122,   375,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,   448,   128,   166,
     186,    56,    71,  -122,  -122,  -122,  -122,   -11,  -122,  -122,
    -122,   372,  -122,   122,    38,    96,   140,   123,   123,   140,
     123,   190,   123,   190,    43,   122,   122,  -122,  -122,  -122,
     190,    65,  -122,   122,   210,   135,    -8,   140,  -122,  -122,
     190,   190,   140,  -122,   190,   190,    86,    65,   140,   140,
    -122,  -122,  -122,   372,  -122,  -122,  -122,  -122,   140,  -122,
     140,  -122,   188,   448,  -122,  -122,   122,  -122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,   -14,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -117,  -102,  -121,   -10,  -122,     0,  -122,  -100,   127,   131,
    -122,     1,   163,    13,    26,    32,    14,   133,   217,    -6,
    -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
      24,    53,    84,    46,    37,    38,    44,    43,   149,    37,
      50,    37,    54,    28,    31,    90,    24,   159,    40,   183,
      45,   142,   140,    94,    91,   141,   141,   145,   173,    28,
      31,    41,   172,    37,    96,    37,   102,    42,    75,    75,
      12,    13,   112,   162,    76,    76,   186,    97,   176,   103,
     143,   187,    37,   113,    47,   178,   179,   189,   191,    33,
      99,   188,   190,   180,    52,   185,   184,   194,    34,   195,
     185,   117,   163,    83,    35,   164,   117,     1,     2,   131,
     125,    12,    13,    34,    92,     1,   185,    98,   185,    35,
      37,   127,    44,    37,   102,     1,   197,   129,    91,     1,
       2,     3,     4,    75,   128,   132,   105,   103,    75,    76,
     151,   153,    12,    13,    76,   114,     5,   130,   133,    35,
       6,     7,     8,     9,   134,    10,     1,     2,    48,    11,
     104,   165,     1,     2,    12,    13,   -77,   138,   -77,   -77,
     -77,    37,   160,     5,    34,    24,   111,    92,   170,   171,
      35,   174,   139,   175,    44,   161,    11,   145,    28,    31,
     147,   148,     1,     2,    55,     1,     2,    48,   177,   154,
     166,   182,   -84,   192,   -84,   -84,   -84,    56,    57,    58,
     150,    59,     5,    37,   193,    60,    61,    62,    63,   155,
      64,    65,    66,    67,   157,    11,    68,    69,    70,    71,
      72,    73,    74,     1,     2,    55,     1,     2,    48,    85,
      86,    87,    88,    89,   158,   181,   196,   126,    56,    57,
      58,   152,    59,     5,   137,   135,    60,    61,    62,    63,
      82,    64,    65,    66,    67,     0,    11,    68,    80,    81,
      71,    72,    73,    74,     1,     2,    55,     0,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,    56,
      57,    58,     0,    59,     0,     0,     0,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,   116,
      70,    71,    72,    73,    74,     1,     2,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,     0,    59,     0,     0,     0,    60,    61,
      62,    63,     0,    64,    65,    66,    67,     0,     0,    68,
      80,   118,    71,    72,    73,    74,     1,     2,    48,     1,
       2,    48,     0,     0,     0,     0,     0,     0,     1,     2,
      48,     0,     0,     5,     0,     0,     5,     0,     0,     0,
      93,     0,     1,     2,    36,     5,    11,     0,     0,    11,
     100,    12,    13,   136,    12,    13,     0,     0,    11,     5,
       0,     0,     0,    12,    13,     1,     2,    48,     0,     0,
    -122,     0,    11,     0,     0,     0,     0,    12,    13,  -122,
    -122,     0,     5,     0,     0,     0,     0,  -123,  -122,  -122,
    -122,  -122,     0,     0,     0,    11,  -123,  -123,     0,     0,
      12,    13,     0,     0,     0,  -123,  -123,  -123,  -123,   106,
      85,    86,    87,    88,    89,     0,     0,   107,     0,     0,
       0,     0,   109,   110,     0,   115,   106,    85,    86,    87,
      88,    89,     0,     0,   107,     0,   108,     0,     0,   109,
     110,   106,    85,    86,    87,    88,    89,     0,     0,   107,
       0,   156,     0,     0,   109,   110,   106,    85,    86,    87,
      88,    89,     0,     0,   107,     0,     0,     0,     0,   109,
     110
};

static const yytype_int16 yycheck[] =
{
       0,    11,    16,     5,     4,     4,     6,     5,   108,     9,
       9,    11,    11,     0,     0,    18,    16,    28,     4,    27,
       6,     5,    34,    33,    27,    37,    37,    35,   149,    16,
      16,     5,   149,    33,    33,    35,    35,     5,    12,    13,
      38,    39,    52,   143,    12,    13,   167,    33,     5,    35,
      34,   172,    52,    52,    25,   155,   156,   178,   179,    18,
      34,   178,   179,   163,    27,   167,   166,   188,    27,   190,
     172,    77,    34,     0,    33,    37,    82,     3,     4,     5,
      90,    38,    39,    27,    19,     3,   188,     5,   190,    33,
      90,    90,    92,    93,    93,     3,   196,     5,    27,     3,
       4,     5,     6,    77,    90,    92,    28,    93,    82,    77,
     109,   110,    38,    39,    82,    34,    20,    91,    92,    33,
      24,    25,    26,    27,    92,    29,     3,     4,     5,    33,
      33,   145,     3,     4,    38,    39,    19,    28,    21,    22,
      23,   141,   141,    20,    27,   145,    18,    19,   147,   148,
      33,   150,    28,   152,   154,   141,    33,    35,   145,   145,
      18,    18,     3,     4,     5,     3,     4,     5,   154,    18,
      30,    36,    19,   183,    21,    22,    23,    18,    19,    20,
      18,    22,    20,   183,   183,    26,    27,    28,    29,    28,
      31,    32,    33,    34,    28,    33,    37,    38,    39,    40,
      41,    42,    43,     3,     4,     5,     3,     4,     5,    19,
      20,    21,    22,    23,    28,     5,    28,    90,    18,    19,
      20,    18,    22,    20,    93,    92,    26,    27,    28,    29,
      13,    31,    32,    33,    34,    -1,    33,    37,    38,    39,
      40,    41,    42,    43,     3,     4,     5,    -1,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    20,    -1,    -1,    20,    -1,    -1,    -1,
      27,    -1,     3,     4,     5,    20,    33,    -1,    -1,    33,
      34,    38,    39,    28,    38,    39,    -1,    -1,    33,    20,
      -1,    -1,    -1,    38,    39,     3,     4,     5,    -1,    -1,
      22,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    31,
      32,    -1,    20,    -1,    -1,    -1,    -1,    22,    40,    41,
      42,    43,    -1,    -1,    -1,    33,    31,    32,    -1,    -1,
      38,    39,    -1,    -1,    -1,    40,    41,    42,    43,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    32,    -1,    34,    18,    19,    20,    21,
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
      29,    33,    38,    39,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    58,    59,    60,    65,    66,    67,    68,
      69,    70,    71,    18,    27,    33,     5,    59,    65,    67,
      70,    68,    69,     5,    59,    70,     5,    25,     5,    57,
      65,    70,    27,    57,    65,     5,    18,    19,    20,    22,
      26,    27,    28,    29,    31,    32,    33,    34,    37,    38,
      39,    40,    41,    42,    43,    68,    69,    72,    73,    74,
      38,    39,    72,     0,    46,    19,    20,    21,    22,    23,
      18,    27,    19,    27,    57,    62,    65,    70,     5,    68,
      34,    63,    65,    70,    33,    28,    18,    26,    28,    31,
      32,    18,    57,    65,    34,    34,    38,    73,    39,    59,
      66,    66,    66,    66,    66,    57,    62,    65,    70,     5,
      68,     5,    67,    68,    69,    71,    28,    63,    28,    28,
      34,    37,     5,    34,    64,    35,    61,    18,    18,    61,
      18,    65,    18,    65,    18,    28,    28,    28,    28,    28,
      65,    70,    61,    34,    37,    46,    30,    54,    55,    56,
      65,    65,    54,    56,    65,    65,     5,    70,    61,    61,
      61,     5,    36,    27,    61,    55,    56,    56,    54,    56,
      54,    56,    57,    65,    56,    56,    28,    61
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
    break;

  case 3:
#line 108 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(1) - (2)].data);
        stmt->next = (statement_t*)(yyvsp[(2) - (2)].data);
        (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 4:
#line 113 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 117 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 6:
#line 120 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 123 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCCALL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 126 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 129 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 132 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_MATH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 135 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_STR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 138 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 141 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 144 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 147 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 151 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 17:
#line 153 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 18:
#line 157 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 19:
#line 159 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 20:
#line 161 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 21:
#line 165 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 22:
#line 169 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 23:
#line 174 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 24:
#line 177 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 25:
#line 184 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (6)].data), (yyvsp[(4) - (6)].data));

        ifs->elif = (yyvsp[(5) - (6)].data);
        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 26:
#line 192 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 27:
#line 199 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (4)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (4)].data));
    }
    break;

  case 28:
#line 205 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 29:
#line 215 "gram.y"
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
#line 226 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 31:
#line 238 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 32:
#line 241 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 33:
#line 248 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 34:
#line 256 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 35:
#line 263 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (5)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (5)].data));
    }
    break;

  case 36:
#line 269 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 37:
#line 279 "gram.y"
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
#line 290 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 39:
#line 302 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 40:
#line 309 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 41:
#line 314 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 42:
#line 321 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 43:
#line 327 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 44:
#line 330 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 45:
#line 333 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 46:
#line 336 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 47:
#line 339 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 48:
#line 342 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 49:
#line 345 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 50:
#line 350 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 51:
#line 353 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 52:
#line 358 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].data));
    }
    break;

  case 53:
#line 361 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (3)].id),NULL);
    }
    break;

  case 54:
#line 366 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 55:
#line 371 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 56:
#line 376 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        expr_t *condexpr = newExpr_Cond((yyvsp[(3) - (3)].data));
        (yyval.data) = newDeclaration(idexpr,condexpr);
    }
    break;

  case 57:
#line 381 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 58:
#line 385 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 59:
#line 388 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 60:
#line 391 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 61:
#line 394 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 62:
#line 399 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 63:
#line 404 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(2) - (3)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 64:
#line 408 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 65:
#line 413 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 66:
#line 417 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 67:
#line 420 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 68:
#line 424 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 69:
#line 429 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 70:
#line 434 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 71:
#line 440 "gram.y"
    {
        (yyval.data) = newExpr_OPAdd((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 72:
#line 443 "gram.y"
    {
        (yyval.data) = newExpr_OPSub((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 73:
#line 446 "gram.y"
    {
        (yyval.data) = newExpr_OPMul((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 74:
#line 449 "gram.y"
    {
        (yyval.data) = newExpr_OPMod((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 75:
#line 452 "gram.y"
    {
        (yyval.data) = newExpr_OPDiv((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 76:
#line 455 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 77:
#line 460 "gram.y"
    {
        (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 78:
#line 463 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 79:
#line 466 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[(2) - (2)].data);
        double val = e->fval * -1.0;
        (yyval.data) = newExpr_Float(val);
    }
    break;

  case 80:
#line 471 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 81:
#line 474 "gram.y"
    {
        expr_t *e = (expr_t*) (yyvsp[(2) - (2)].data);
        int val = e->ival * -1;
        (yyval.data) = newExpr_Ival(val);
    }
    break;

  case 82:
#line 479 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 83:
#line 482 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 84:
#line 485 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[(1) - (1)].data));
    }
    break;

  case 85:
#line 488 "gram.y"
    {
        (yyval.data) = newExpr_Cond((yyvsp[(2) - (3)].data));
    }
    break;

  case 86:
#line 493 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 87:
#line 499 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = newExpr_ID((yyvsp[(3) - (4)].id));
        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 88:
#line 504 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 89:
#line 507 "gram.y"
    {
      expr_t *index = newExpr_ID((yyvsp[(3) - (4)].id));
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), index);
    }
    break;

  case 90:
#line 513 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
    break;

  case 91:
#line 518 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 92:
#line 523 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 93:
#line 529 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = newExpr_ID((yyvsp[(3) - (3)].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 94:
#line 535 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 95:
#line 544 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 96:
#line 553 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 97:
#line 559 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 98:
#line 564 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 99:
#line 567 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 100:
#line 570 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[(1) - (1)].data));
    }
    break;

  case 101:
#line 573 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 102:
#line 577 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 103:
#line 583 "gram.y"
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

  case 104:
#line 608 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 105:
#line 613 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 106:
#line 616 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 107:
#line 622 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 108:
#line 628 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 109:
#line 633 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 110:
#line 638 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 111:
#line 643 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 112:
#line 647 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 113:
#line 651 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 114:
#line 655 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 115:
#line 659 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 116:
#line 663 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 117:
#line 667 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 118:
#line 671 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 119:
#line 675 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 120:
#line 679 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 121:
#line 683 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 122:
#line 687 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 123:
#line 691 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 124:
#line 695 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 125:
#line 699 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 126:
#line 703 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 127:
#line 707 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2698 "y.tab.c"
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


#line 712 "gram.y"


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

