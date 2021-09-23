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
#line 170 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 183 "y.tab.c"

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
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   737

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  257

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
       2,     2,    45,    29,    44,     2,    24,    23,    35,    43,
      25,    27,    21,    19,    42,    20,    26,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    38,
      36,    18,    37,    30,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,    46,    32,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    34,    41,    33,     2,     2,     2,
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
      19,    21,    23,    25,    27,    29,    31,    34,    37,    46,
      49,    51,    54,    56,    60,    64,    68,    72,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    96,   102,   109,
     117,   124,   130,   137,   145,   152,   155,   157,   163,   166,
     171,   173,   178,   180,   182,   185,   187,   192,   197,   202,
     207,   211,   215,   219,   226,   233,   239,   247,   254,   259,
     263,   268,   272,   276,   280,   284,   288,   292,   296,   298,
     299,   303,   307,   311,   315,   319,   322,   326,   328,   332,
     334,   336,   339,   341,   344,   349,   354,   359,   363,   366,
     369,   371,   377,   382,   387,   391,   394,   396,   398,   402,
     406,   410,   414,   418,   422,   424,   428,   432,   435,   438,
     441,   443,   445,   447,   449,   451,   453,   455,   457,   459,
     461,   463,   465,   467,   469,   471,   473,   475,   477,   479,
     481,   483,   485,   487,   489,   491,   493,   495,   497,   499,
     501,   503,   505
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    50,    -1,    -1,    72,
      -1,    69,    -1,    57,    -1,    59,    -1,    60,    -1,    53,
      -1,    55,    -1,    56,    -1,    54,    -1,    52,    -1,    68,
      -1,    24,     5,    -1,    24,    85,    -1,    25,    57,    26,
      26,    26,     5,    27,    76,    -1,     6,    57,    -1,    28,
      -1,    29,    28,    -1,    58,    -1,    57,    19,    57,    -1,
      57,    21,    57,    -1,    57,    20,    57,    -1,    57,    23,
      57,    -1,    57,    22,    57,    -1,    81,    -1,    80,    -1,
      73,    -1,    77,    -1,    71,    -1,    70,    -1,    86,    -1,
       5,    -1,    25,    57,    27,    -1,    30,    31,    64,    32,
      76,    -1,    30,    31,    64,    32,    76,    61,    -1,    30,
      31,    64,    32,    76,    61,    63,    -1,    30,    31,    64,
      32,    76,    63,    -1,    26,    31,    64,    32,    76,    -1,
      26,    31,    64,    32,    76,    61,    -1,    26,    31,    64,
      32,    76,    61,    63,    -1,    26,    31,    64,    32,    76,
      63,    -1,    61,    62,    -1,    62,    -1,    33,    31,    64,
      32,    76,    -1,    33,    76,    -1,    64,    34,    34,    65,
      -1,    65,    -1,    65,    35,    35,    66,    -1,    66,    -1,
      67,    -1,    29,    58,    -1,    58,    -1,    57,    18,    18,
      57,    -1,    57,    29,    18,    57,    -1,    57,    36,    18,
      57,    -1,    57,    37,    18,    57,    -1,    57,    36,    57,
      -1,    57,    37,    57,    -1,    25,    67,    27,    -1,    38,
      38,     5,    38,    38,    76,    -1,    28,     5,    25,    79,
      27,    76,    -1,    28,     5,    25,    27,    76,    -1,    58,
      39,    39,     5,    25,    78,    27,    -1,    58,    39,    39,
       5,    25,    27,    -1,     5,    25,    78,    27,    -1,     5,
      25,    27,    -1,    81,    25,    78,    27,    -1,    81,    25,
      27,    -1,     5,    18,    57,    -1,     5,    18,    67,    -1,
      81,    18,    57,    -1,    81,    18,    67,    -1,    40,    74,
      41,    -1,    74,    42,    75,    -1,    75,    -1,    -1,    85,
      39,    57,    -1,    85,    39,    85,    -1,    40,    50,    41,
      -1,    31,    78,    32,    -1,    31,    53,    32,    -1,    31,
      32,    -1,    78,    42,    57,    -1,    57,    -1,    79,    42,
       5,    -1,     5,    -1,    84,    -1,    20,    84,    -1,    83,
      -1,    20,    83,    -1,     5,    31,    57,    32,    -1,     5,
      31,    82,    32,    -1,    81,    31,    57,    32,    -1,    58,
      39,    58,    -1,    39,    58,    -1,    58,    39,    -1,    39,
      -1,    58,    39,    58,    39,    58,    -1,    39,    58,    39,
      58,    -1,    58,    39,    39,    58,    -1,    39,    39,    58,
      -1,    39,    39,    -1,     3,    -1,     4,    -1,    85,    19,
      86,    -1,    85,    19,     5,    -1,    85,    19,    84,    -1,
      85,    19,    83,    -1,    85,    21,    83,    -1,    85,    21,
      81,    -1,    86,    -1,    43,    87,    43,    -1,    44,    87,
      44,    -1,    44,    44,    -1,    43,    43,    -1,    87,    88,
      -1,    88,    -1,     5,    -1,    84,    -1,    83,    -1,     6,
      -1,    89,    -1,    19,    -1,    45,    -1,    30,    -1,    36,
      -1,    37,    -1,    20,    -1,    22,    -1,    46,    -1,    39,
      -1,    38,    -1,    25,    -1,    27,    -1,    29,    -1,    42,
      -1,    43,    -1,    44,    -1,    26,    -1,    31,    -1,    32,
      -1,    21,    -1,    47,    -1,    24,    -1,    35,    -1,    34,
      -1,    40,    -1,    41,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   121,   126,   130,   133,   136,   139,   142,
     145,   148,   151,   154,   157,   160,   164,   166,   171,   186,
     190,   194,   199,   202,   208,   214,   220,   226,   234,   237,
     240,   243,   246,   249,   252,   255,   258,   263,   266,   273,
     281,   290,   293,   300,   308,   317,   324,   329,   336,   342,
     345,   350,   353,   358,   361,   366,   371,   374,   377,   380,
     383,   386,   389,   393,   430,   433,   438,   441,   446,   450,
     454,   458,   464,   469,   474,   477,   482,   487,   494,   497,
     502,   511,   522,   527,   532,   536,   541,   545,   550,   555,
     561,   564,   568,   571,   577,   583,   589,   594,   597,   600,
     603,   606,   609,   612,   615,   618,   624,   629,   634,   640,
     646,   656,   666,   672,   678,   683,   686,   689,   693,   699,
     727,   732,   735,   742,   749,   754,   759,   764,   769,   773,
     777,   781,   785,   789,   793,   797,   801,   805,   809,   813,
     817,   821,   825,   829,   833,   837,   841,   845,   849,   853,
     857,   861,   865
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
  "'-'", "'*'", "'/'", "'%'", "'$'", "'('", "'.'", "')'", "'@'", "'!'",
  "'?'", "'['", "']'", "'~'", "'|'", "'&'", "'<'", "'>'", "';'", "':'",
  "'{'", "'}'", "','", "'''", "'\"'", "' '", "'\\\\'", "'^'", "$accept",
  "program", "statements", "statement", "systemStatement",
  "forEachStatement", "returnStatement", "continueStatement",
  "breakStatement", "expressions", "expression", "ifStatement",
  "loopStatement", "middleIfs", "middleIf", "endIf", "logical_a",
  "logical_b", "logical_expression", "condition", "class", "function",
  "classFunctionCall", "functionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "indexer", "mathContentDigit", "mathContentDouble", "stringContents",
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
      45,    42,    47,    37,    36,    40,    46,    41,    64,    33,
      63,    91,    93,   126,   124,    38,    60,    62,    59,    58,
     123,   125,    44,    39,    34,    32,    92,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    54,
      55,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    72,    72,    72,    72,    73,    74,    74,    74,
      75,    75,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    84,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     8,     2,
       1,     2,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     6,     7,
       6,     5,     6,     7,     6,     2,     1,     5,     2,     4,
       1,     4,     1,     1,     2,     1,     4,     4,     4,     4,
       3,     3,     3,     6,     6,     5,     7,     6,     4,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     1,     0,
       3,     3,     3,     3,     3,     2,     3,     1,     3,     1,
       1,     2,     1,     2,     4,     4,     4,     3,     2,     2,
       1,     5,     4,     4,     3,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   106,   107,    35,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    79,     0,     0,     0,     2,     4,
      14,    10,    13,    11,    12,     7,    22,     8,     9,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    92,    90,
      34,     0,     0,     0,    35,     0,    19,    28,    93,    91,
      16,    17,   114,     0,     0,     0,    21,     0,    85,     0,
      87,     0,     0,     0,    78,     0,   121,   124,   152,   126,
     131,   145,   132,   147,   136,   142,   137,   138,   128,   143,
     144,   149,   148,   129,   130,   135,   134,   150,   151,   139,
     118,   141,   127,   133,   146,   123,   122,     0,   120,   125,
     140,   117,     0,     1,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,    69,     0,   100,
       0,    22,     0,     0,     0,     0,     0,    36,     0,     0,
      22,     0,    50,    52,    53,     0,     0,    84,    83,     0,
       0,    76,     0,     0,   115,   119,   116,    23,    25,    24,
      27,    26,     0,    74,    75,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    68,   105,    98,    94,    99,    95,
     109,   111,   110,   108,     0,   113,   112,     0,    54,     0,
       0,     0,    89,     0,     0,     0,    86,     0,    77,    80,
      81,    34,     0,    70,    96,    62,     0,     0,     0,    60,
       0,    61,   104,     0,     0,    97,     0,     4,    41,     0,
       0,    65,     0,     0,    37,     0,     0,    56,    57,    58,
      59,   102,    35,   103,     0,     0,     0,     0,    42,    46,
      44,    49,    51,    64,    88,    38,    40,    63,    67,     0,
       0,   101,     0,    82,     0,    48,    45,    43,    39,    66,
      67,     0,    18,     0,    66,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    60,
      26,    27,    28,   228,   229,   230,   131,   132,   133,   134,
      29,    30,    31,    32,    33,    34,    63,    64,   208,    35,
      61,   184,    36,    47,   122,    38,    39,    65,    40,    97,
      98,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
     391,  -192,  -192,    51,   611,    23,    17,   611,   -23,     9,
      14,    15,    47,    42,    81,   211,   256,    49,  -192,   391,
    -192,  -192,  -192,  -192,  -192,   334,    61,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,    67,  -192,  -192,
    -192,   636,   161,   116,    52,   611,   334,    68,  -192,  -192,
    -192,   112,  -192,   244,   420,    87,  -192,   420,  -192,    84,
     334,    86,    83,   153,  -192,    -6,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
     122,  -192,  -192,  -192,  -192,  -192,  -192,   301,  -192,  -192,
    -192,   127,   346,  -192,  -192,   611,   611,   611,   611,   611,
      91,   636,   434,   611,   636,   700,  -192,  -192,   -11,   463,
     129,    95,   110,   289,    60,    63,   128,  -192,   611,   700,
      62,   146,   140,  -192,  -192,     7,   155,  -192,  -192,   611,
     119,  -192,    81,   611,   122,  -192,   127,   162,   162,  -192,
    -192,  -192,   177,   700,  -192,  -192,    11,   202,   688,   172,
     184,   188,   492,   521,  -192,   611,   173,  -192,   546,  -192,
    -192,  -192,  -192,  -192,   182,   195,  -192,   193,    61,   187,
     194,   204,  -192,   187,    28,   187,   334,   230,  -192,   334,
     112,  -192,   247,  -192,  -192,  -192,   611,   611,   611,   334,
     611,   334,    61,   553,   661,   234,   264,   391,   246,   420,
     420,  -192,   187,   279,   246,   187,   578,   334,   334,   334,
     334,    61,    98,    61,   553,   262,   272,     8,   246,  -192,
    -192,   140,  -192,  -192,  -192,   246,  -192,  -192,  -192,    29,
     603,    61,   187,  -192,   420,  -192,  -192,  -192,  -192,  -192,
    -192,    31,  -192,   186,  -192,   187,  -192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,   -17,  -192,  -192,   302,  -192,  -192,  -192,     0,
     -33,  -192,  -192,   101,  -188,  -191,   -51,   108,   114,   -30,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,   176,  -153,  -192,
     -37,  -192,  -192,     1,  -192,    13,    20,    -3,     3,   313,
      56,  -192
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -142
static const yytype_int16 yytable[] =
{
      25,    37,   104,    51,    46,   118,   136,    53,    54,    52,
     121,   116,   182,   124,    55,   125,   164,    52,    48,    25,
      37,   130,    50,   236,   130,    49,     1,     2,    95,    95,
     211,   139,   214,   143,   183,    96,    96,   247,   193,   244,
     246,   115,    56,   120,   248,   123,    57,   246,   207,   103,
       1,     2,    44,   139,   129,   212,   249,   129,   254,   233,
      15,    16,   237,     1,     2,   170,     1,     5,   174,    41,
     213,   139,     7,   139,   245,   156,    42,    42,    12,    58,
      62,   154,    43,    43,   159,   111,   166,    14,   140,   252,
      15,    16,   112,   112,   -55,   178,   -55,   -55,   113,   113,
     110,   110,   256,    15,    16,   147,   148,   149,   150,   151,
      95,   153,   135,   157,   158,    95,   137,    96,   138,     1,
       2,    44,    96,   240,    15,    16,   175,   173,   139,    43,
     152,   124,   202,   125,   168,   205,     5,   171,   176,   186,
     190,    45,   169,   189,   172,    52,   191,    12,   105,   106,
     107,   108,   109,   145,   177,   119,    14,   187,   145,    15,
      16,   167,   199,   201,     1,     2,    44,  -140,  -140,  -140,
     221,   223,  -141,  -141,  -141,   181,   130,   130,   179,   239,
     180,     5,   192,   107,   108,   109,    45,   185,   117,   180,
     226,   241,    12,   253,   141,   142,   217,   218,   219,   195,
     220,    14,   196,   251,    15,    16,   197,    25,    37,   129,
     129,   130,   203,    43,     1,     2,    66,    67,   255,   206,
     180,   105,   106,   107,   108,   109,   113,   207,   209,    68,
      69,    70,    71,    72,   194,    73,    74,    75,    76,   210,
      77,    78,    79,    80,   129,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     1,
       2,    66,    67,   105,   106,   107,   108,   109,   215,   225,
     126,   127,   216,   224,    68,    69,    70,    71,    72,   227,
      73,    74,    75,    76,   234,    77,    78,    79,    80,   242,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   100,
     101,    92,    93,    94,     1,     2,    66,    67,   105,   106,
     107,   108,   109,   243,    59,   235,   127,   231,   188,    68,
      69,    70,    71,    72,   232,    73,    74,    75,    76,   102,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   144,    91,    92,    93,    94,     1,
       2,    66,    67,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      73,    74,    75,    76,     0,    77,    78,    79,    80,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   100,
     146,    92,    93,    94,     1,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     6,     7,     8,     0,     9,
      10,    11,    12,     1,     2,    44,     0,     0,     0,    13,
       0,    14,     0,     0,    15,    16,     0,     1,     2,    44,
       5,     0,     0,     0,     0,   114,     0,     0,     0,   128,
       0,    12,     0,     0,     5,     0,     0,     0,     0,    45,
      14,   155,     0,    15,    16,    12,     1,     2,    44,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
       0,     0,     0,     5,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,    12,     1,     2,    44,     0,     0,
       0,     0,   165,    14,     0,     0,    15,    16,     0,     0,
     198,     0,     5,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    12,     1,     2,    44,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,     0,   200,
       0,     5,     0,     0,     0,     0,    45,     0,     0,     1,
       2,    44,    12,     0,     0,     0,     1,     2,    44,     0,
       0,    14,     0,     0,    15,    16,     5,     0,     0,     0,
       0,    45,     0,     5,     0,     0,     0,    12,    45,     0,
       0,     1,     2,    44,    12,   204,    14,     0,     0,    15,
      16,     0,   152,    14,     0,     0,    15,    16,     5,     0,
       0,     0,     0,    45,     0,   238,     1,     2,    44,    12,
       0,     0,     0,     0,     1,     2,    44,     0,    14,     0,
       0,    15,    16,     5,     0,     0,     0,     0,    45,     0,
     250,     5,     0,     0,    12,     0,    45,     0,     0,     1,
       2,    44,    12,    14,     0,     0,    15,    16,     0,     0,
       0,    14,     0,     0,    15,    16,     5,     0,     0,     0,
       0,   114,     0,     0,     1,     2,   222,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     5,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,   160,   105,   106,   107,
     108,   109,     0,     0,     0,   127,     0,   161,   160,   105,
     106,   107,   108,   109,   162,   163,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,   162,   163
};

static const yytype_int16 yycheck[] =
{
       0,     0,    19,     6,     4,    42,    57,     7,    31,     6,
      43,    41,     5,    19,     5,    21,    27,    14,     5,    19,
      19,    54,     5,   214,    57,     5,     3,     4,    15,    16,
     183,    42,   185,    39,    27,    15,    16,   228,    27,    31,
     228,    41,    28,    43,   235,    45,    31,   235,    40,     0,
       3,     4,     5,    42,    54,    27,    27,    57,    27,   212,
      43,    44,   215,     3,     4,     5,     3,    20,     5,    18,
      42,    42,    25,    42,   227,   112,    25,    25,    31,    32,
      38,   111,    31,    31,   114,    18,   119,    40,     5,   242,
      43,    44,    25,    25,    32,   128,    34,    35,    31,    31,
      39,    39,   255,    43,    44,   105,   106,   107,   108,   109,
      97,   111,    25,   113,   114,   102,    32,    97,    32,     3,
       4,     5,   102,    25,    43,    44,   125,   124,    42,    31,
      39,    19,   165,    21,    39,   168,    20,   124,   125,   139,
     143,    25,    32,   143,   124,   142,   143,    31,    19,    20,
      21,    22,    23,    97,    26,    39,    40,    38,   102,    43,
      44,    32,   162,   163,     3,     4,     5,    45,    46,    47,
     203,   204,    45,    46,    47,    35,   209,   210,    32,   216,
      34,    20,     5,    21,    22,    23,    25,    32,    27,    34,
     207,   224,    31,   244,    41,    42,   196,   197,   198,    27,
     200,    40,    18,   240,    43,    44,    18,   207,   207,   209,
     210,   244,    39,    31,     3,     4,     5,     6,    32,    26,
      34,    19,    20,    21,    22,    23,    31,    40,    34,    18,
      19,    20,    21,    22,    32,    24,    25,    26,    27,    35,
      29,    30,    31,    32,   244,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     3,
       4,     5,     6,    19,    20,    21,    22,    23,    38,     5,
      26,    27,    25,    39,    18,    19,    20,    21,    22,    33,
      24,    25,    26,    27,     5,    29,    30,    31,    32,    27,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     3,     4,     5,     6,    19,    20,
      21,    22,    23,    41,    12,   214,    27,   209,   142,    18,
      19,    20,    21,    22,   210,    24,    25,    26,    27,    16,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     3,
       4,     5,     6,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    30,    31,     3,     4,     5,    -1,    -1,    -1,    38,
      -1,    40,    -1,    -1,    43,    44,    -1,     3,     4,     5,
      20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      40,    27,    -1,    43,    44,    31,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,     3,     4,     5,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    43,    44,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    31,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    44,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,     3,
       4,     5,    31,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    40,    -1,    -1,    43,    44,    20,    -1,    -1,    -1,
      -1,    25,    -1,    20,    -1,    -1,    -1,    31,    25,    -1,
      -1,     3,     4,     5,    31,    39,    40,    -1,    -1,    43,
      44,    -1,    39,    40,    -1,    -1,    43,    44,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,     3,     4,     5,    31,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    40,    -1,
      -1,    43,    44,    20,    -1,    -1,    -1,    -1,    25,    -1,
      27,    20,    -1,    -1,    31,    -1,    25,    -1,    -1,     3,
       4,     5,    31,    40,    -1,    -1,    43,    44,    -1,    -1,
      -1,    40,    -1,    -1,    43,    44,    20,    -1,    -1,    -1,
      -1,    25,    -1,    -1,     3,     4,     5,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,
      44,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    43,    44,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    29,    18,    19,
      20,    21,    22,    23,    36,    37,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    28,
      29,    30,    31,    38,    40,    43,    44,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    68,
      69,    70,    71,    72,    73,    77,    80,    81,    83,    84,
      86,    18,    25,    31,     5,    25,    57,    81,    83,    84,
       5,    85,    86,    57,    31,     5,    28,    31,    32,    53,
      57,    78,    38,    74,    75,    85,     5,     6,    18,    19,
      20,    21,    22,    24,    25,    26,    27,    29,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    83,    84,    87,    88,    89,
      43,    44,    87,     0,    50,    19,    20,    21,    22,    23,
      39,    18,    25,    31,    25,    57,    67,    27,    78,    39,
      57,    58,    82,    57,    19,    21,    26,    27,    29,    57,
      58,    64,    65,    66,    67,    25,    64,    32,    32,    42,
       5,    41,    42,    39,    43,    88,    44,    57,    57,    57,
      57,    57,    39,    57,    67,    27,    78,    57,    57,    67,
      18,    29,    36,    37,    27,    39,    58,    32,    39,    32,
       5,    83,    84,    86,     5,    81,    83,    26,    58,    32,
      34,    35,     5,    27,    79,    32,    57,    38,    75,    57,
      85,    86,     5,    27,    32,    27,    18,    18,    18,    57,
      18,    57,    58,    39,    39,    58,    26,    40,    76,    34,
      35,    76,    27,    42,    76,    38,    25,    57,    57,    57,
      57,    58,     5,    58,    39,     5,    50,    33,    61,    62,
      63,    65,    66,    76,     5,    61,    63,    76,    27,    78,
      25,    58,    27,    41,    31,    76,    62,    63,    63,    27,
      27,    78,    76,    64,    27,    32,    76
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
#line 104 "gram.y"
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
#line 121 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(1) - (2)].data);
        stmt->next = (statement_t*)(yyvsp[(2) - (2)].data);
        (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 4:
#line 126 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 130 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 6:
#line 133 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 136 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 139 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 142 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 145 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 148 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 151 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 154 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 157 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 160 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 164 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 17:
#line 166 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 18:
#line 171 "gram.y"
    {
    body_t *bd = (yyvsp[(8) - (8)].data);
    statement_t *stmt = bd->content;

    while ( stmt != NULL ) {
        if ( stmt->entity == LANG_ENTITY_BODY_END ) {
            /* Set entity to continue */
            stmt->entity = LANG_ENTITY_CONTINUE;
        }
        stmt = stmt->next;
    }

    (yyval.data) = newForEach((yyvsp[(2) - (8)].data), (yyvsp[(6) - (8)].id), bd);
}
    break;

  case 19:
#line 186 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 20:
#line 190 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 21:
#line 194 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 22:
#line 199 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 23:
#line 202 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 24:
#line 208 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 25:
#line 214 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
    break;

  case 26:
#line 220 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
    break;

  case 27:
#line 226 "gram.y"
    {
      expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
      expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
    break;

  case 28:
#line 234 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 29:
#line 237 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 30:
#line 240 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 31:
#line 243 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 32:
#line 246 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 33:
#line 249 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 34:
#line 252 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 35:
#line 255 "gram.y"
    {
      (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 36:
#line 258 "gram.y"
    {
      (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 37:
#line 263 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 38:
#line 266 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 39:
#line 273 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 40:
#line 281 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 41:
#line 290 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 42:
#line 293 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 43:
#line 300 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 44:
#line 308 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);

        (yyval.data) = ifs;
    }
    break;

  case 45:
#line 317 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 46:
#line 324 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 47:
#line 329 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 48:
#line 336 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 49:
#line 342 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
    }
    break;

  case 50:
#line 345 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 51:
#line 350 "gram.y"
    {
      (yyval.data) = newExpr_Logical((yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data), NULL);
    }
    break;

  case 52:
#line 353 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 53:
#line 358 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 54:
#line 361 "gram.y"
    {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[(2) - (2)].data));
        (yyval.data) = cond;
    }
    break;

  case 55:
#line 366 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 56:
#line 371 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 57:
#line 374 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 58:
#line 377 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 59:
#line 380 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 60:
#line 383 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 61:
#line 386 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 62:
#line 389 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 63:
#line 393 "gram.y"
    {
    /* Only declarations allowed */
    body_t *bod = (yyvsp[(6) - (6)].data);
    statement_t *walk = bod->content;
    char *classId = ast_emalloc(strlen((yyvsp[(3) - (6)].id))+2);
    memset(classId, 0, strlen((yyvsp[(3) - (6)].id))+1);
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
    snprintf(classId, strlen((yyvsp[(3) - (6)].id))+2, "%s", (yyvsp[(3) - (6)].id));
    (yyval.data) = newClass(classId, bod);
}
    break;

  case 64:
#line 430 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 65:
#line 433 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 66:
#line 438 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (7)].data), (yyvsp[(4) - (7)].id), (yyvsp[(6) - (7)].data));
    }
    break;

  case 67:
#line 441 "gram.y"
    {
        (yyval.data) = newClassFunCall((yyvsp[(1) - (6)].data), (yyvsp[(4) - (6)].id), NULL);
    }
    break;

  case 68:
#line 446 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 69:
#line 450 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (3)].id));
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 70:
#line 454 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (4)].data);
        (yyval.data) = newFunCall(id,(yyvsp[(3) - (4)].data));
    }
    break;

  case 71:
#line 458 "gram.y"
    {
        expr_t *id = (expr_t*)(yyvsp[(1) - (3)].data);
        (yyval.data) = newFunCall(id,NULL);
    }
    break;

  case 72:
#line 464 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 73:
#line 469 "gram.y"
    {
        expr_t *idexpr = newExpr_ID((yyvsp[(1) - (3)].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[(3) - (3)].data));
    }
    break;

  case 74:
#line 474 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 75:
#line 477 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 76:
#line 482 "gram.y"
    {
      (yyval.data) = newExpr_Dictionary((yyvsp[(2) - (3)].data));
    }
    break;

  case 77:
#line 487 "gram.y"
    {
      keyValList_t *left = (keyValList_t*)(yyvsp[(1) - (3)].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[(3) - (3)].data);

      right->next = left;
      (yyval.data) = right;
    }
    break;

  case 78:
#line 494 "gram.y"
    {
      (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 79:
#line 497 "gram.y"
    {
        (yyval.data) = NULL;
    }
    break;

  case 80:
#line 502 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 81:
#line 511 "gram.y"
    {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[(1) - (3)].data);
      keyVal->val = (yyvsp[(3) - (3)].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
    break;

  case 82:
#line 522 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 83:
#line 527 "gram.y"
    {
      argsList_t *args = (argsList_t*) (yyvsp[(2) - (3)].data);
      (yyval.data) = newExpr_Vector(args);
    }
    break;

  case 84:
#line 532 "gram.y"
    {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[(2) - (3)].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
    break;

  case 85:
#line 536 "gram.y"
    {
      (yyval.data) = newExpr_Vector(NULL);
    }
    break;

  case 86:
#line 541 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 87:
#line 545 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 88:
#line 550 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 89:
#line 555 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 90:
#line 561 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 91:
#line 564 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 92:
#line 568 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 93:
#line 571 "gram.y"
    {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[(2) - (2)].data));
    }
    break;

  case 94:
#line 577 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 95:
#line 583 "gram.y"
    {
        expr_t *id = newExpr_ID((yyvsp[(1) - (4)].id));
        expr_t *index = (yyvsp[(3) - (4)].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
    break;

  case 96:
#line 589 "gram.y"
    {
      (yyval.data) = newExpr_VectorIndex((yyvsp[(1) - (4)].data), (yyvsp[(3) - (4)].data));
    }
    break;

  case 97:
#line 594 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data), NULL);
  }
    break;

  case 98:
#line 597 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (2)].data), NULL);
  }
    break;

  case 99:
#line 600 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (2)].data), NULL, NULL);
  }
    break;

  case 100:
#line 603 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 101:
#line 606 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (5)].data), (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
  }
    break;

  case 102:
#line 609 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
  }
    break;

  case 103:
#line 612 "gram.y"
    {
    (yyval.data) = newExpr_Indexer((yyvsp[(1) - (4)].data), NULL, (yyvsp[(4) - (4)].data));
  }
    break;

  case 104:
#line 615 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[(3) - (3)].data));
  }
    break;

  case 105:
#line 618 "gram.y"
    {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
    break;

  case 106:
#line 624 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
    break;

  case 107:
#line 629 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 108:
#line 634 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 109:
#line 640 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = newExpr_ID((yyvsp[(3) - (3)].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 110:
#line 646 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[(3) - (3)].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 111:
#line 656 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *d = (expr_t*)(yyvsp[(3) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[(3) - (3)].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 112:
#line 666 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 113:
#line 672 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
    break;

  case 114:
#line 678 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 115:
#line 683 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 116:
#line 686 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 117:
#line 689 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 118:
#line 693 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 119:
#line 699 "gram.y"
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

  case 120:
#line 727 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 121:
#line 732 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 122:
#line 735 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 123:
#line 742 "gram.y"
    {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[(1) - (1)].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[(1) - (1)].data));
    }
    break;

  case 124:
#line 749 "gram.y"
    {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 125:
#line 754 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 126:
#line 759 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 127:
#line 764 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 128:
#line 769 "gram.y"
    {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
    break;

  case 129:
#line 773 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 130:
#line 777 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 131:
#line 781 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 132:
#line 785 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 133:
#line 789 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 134:
#line 793 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 135:
#line 797 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 136:
#line 801 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 137:
#line 805 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 138:
#line 809 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 139:
#line 813 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 140:
#line 817 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 141:
#line 821 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 142:
#line 825 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 143:
#line 829 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 144:
#line 833 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 145:
#line 837 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 146:
#line 841 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 147:
#line 845 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 148:
#line 849 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 149:
#line 853 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 150:
#line 857 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 151:
#line 861 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 152:
#line 865 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3011 "y.tab.c"
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


#line 870 "gram.y"


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

