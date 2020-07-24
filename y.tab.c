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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

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
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      31,    18,    32,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,    41,    28,     2,     2,     2,     2,     2,     2,
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
      42,    45,    50,    56,    63,    69,    74,    80,    87,    93,
      99,   106,   114,   121,   127,   134,   142,   149,   152,   154,
     160,   163,   168,   173,   178,   183,   188,   192,   196,   203,
     209,   214,   218,   222,   226,   230,   234,   238,   240,   244,
     246,   250,   252,   256,   260,   264,   268,   272,   274,   276,
     278,   280,   284,   286,   290,   294,   298,   302,   306,   308,
     312,   316,   319,   322,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    46,    45,    -1,    -1,    59,
      -1,    57,    -1,    58,    -1,    51,    -1,    52,    -1,    63,
      -1,    65,    -1,    49,    -1,    50,    -1,    48,    -1,    47,
      -1,    24,     5,    -1,    24,    65,    -1,     6,    63,    -1,
      25,    -1,    26,    25,    -1,    27,    56,    28,    60,    -1,
      27,    56,    28,    60,    53,    -1,    27,    56,    28,    60,
      53,    55,    -1,    27,    56,    28,    60,    55,    -1,    27,
      63,    28,    60,    -1,    27,    63,    28,    60,    53,    -1,
      27,    63,    28,    60,    53,    55,    -1,    27,    63,    28,
      60,    55,    -1,    29,    27,    56,    28,    60,    -1,    29,
      27,    56,    28,    60,    53,    -1,    29,    27,    56,    28,
      60,    53,    55,    -1,    29,    27,    56,    28,    60,    55,
      -1,    29,    27,    63,    28,    60,    -1,    29,    27,    63,
      28,    60,    53,    -1,    29,    27,    63,    28,    60,    53,
      55,    -1,    29,    27,    63,    28,    60,    55,    -1,    53,
      54,    -1,    54,    -1,    30,    27,    56,    28,    60,    -1,
      30,    60,    -1,    63,    18,    18,    63,    -1,    65,    18,
      18,    65,    -1,    63,    26,    18,    63,    -1,    63,    31,
      18,    63,    -1,    63,    32,    18,    63,    -1,    63,    31,
      63,    -1,    63,    32,    63,    -1,    25,     5,    33,    62,
      34,    60,    -1,    25,     5,    33,    34,    60,    -1,     5,
      33,    61,    34,    -1,     5,    33,    34,    -1,     5,    18,
      65,    -1,     5,    18,    63,    -1,     5,    18,    56,    -1,
      35,    45,    36,    -1,    61,    37,    63,    -1,    63,    -1,
      61,    37,    65,    -1,    65,    -1,    62,    37,     5,    -1,
       5,    -1,    63,    19,    63,    -1,    63,    20,    63,    -1,
      63,    21,    63,    -1,    63,    23,    63,    -1,    63,    22,
      63,    -1,    64,    -1,     5,    -1,     4,    -1,     3,    -1,
      33,    63,    34,    -1,    58,    -1,    33,    56,    34,    -1,
      65,    19,    66,    -1,    65,    19,     5,    -1,    65,    19,
       4,    -1,    65,    19,     3,    -1,    66,    -1,    38,    67,
      38,    -1,    39,    67,    39,    -1,    39,    39,    -1,    38,
      38,    -1,    67,    68,    -1,    68,    -1,     5,    -1,     4,
      -1,     3,    -1,    69,    -1,    19,    -1,    40,    -1,    31,
      -1,    32,    -1,    20,    -1,    22,    -1,    41,    -1,    42,
      -1,    33,    -1,    34,    -1,    26,    -1,    37,    -1,    38,
      -1,    39,    -1,    29,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,   104,   109,   113,   116,   119,   122,   125,
     128,   131,   134,   137,   140,   143,   147,   149,   153,   157,
     161,   166,   169,   176,   184,   191,   197,   207,   218,   230,
     233,   240,   248,   255,   261,   271,   282,   294,   301,   306,
     313,   319,   322,   325,   328,   331,   334,   337,   342,   345,
     350,   353,   358,   361,   364,   370,   375,   379,   382,   386,
     391,   396,   402,   405,   408,   411,   414,   417,   422,   425,
     428,   431,   434,   437,   442,   448,   454,   462,   470,   475,
     478,   481,   485,   491,   514,   519,   522,   527,   532,   537,
     542,   546,   550,   554,   558,   562,   566,   570,   574,   578,
     582,   586,   590,   594,   598
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
  "' '", "'\\\\'", "':'", "$accept", "program", "statements", "statement",
  "systemStatement", "returnStatement", "continueStatement",
  "breakStatement", "ifStatement", "loopStatement", "middleIfs",
  "middleIf", "endIf", "condition", "function", "functionCall",
  "declaration", "body", "arguments_list", "parameters_list",
  "mathContents", "mathContent", "stringContents", "stringContent",
  "stringEditions", "stringEdition", "otherChar", 0
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
      32,    92,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    47,    47,    48,    49,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      55,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     4,     5,     6,     5,     4,     5,     6,     5,     5,
       6,     7,     6,     5,     6,     7,     6,     2,     1,     5,
       2,     4,     4,     4,     4,     4,     3,     3,     6,     5,
       4,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    70,    69,    68,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     2,     4,    15,    14,    12,    13,
       8,     9,     6,     7,     5,    10,    67,    11,    78,     0,
       0,    68,    72,    18,    16,    17,     0,    20,     0,     0,
       0,     0,     0,     0,    87,    86,    85,   104,    89,    93,
      94,    99,   103,    91,    92,    97,    98,   100,    82,   102,
      90,    95,    96,     0,    84,    88,   101,    81,     0,     1,
       3,     0,     0,     0,     0,     0,     0,    54,    53,    52,
      51,     0,    57,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    71,    79,    83,    80,    62,
      63,    64,    66,    65,    77,    76,    75,    74,    50,     0,
      61,     0,     0,     4,    21,     0,     0,    25,     0,    46,
       0,    47,     0,     0,     0,    56,    58,    49,     0,     0,
       0,     0,    22,    38,    24,    41,    43,    26,    28,    44,
      45,    42,    29,    33,    48,    60,    55,     0,    40,    37,
      23,    27,    30,    32,    34,    36,     0,     0,    31,    35,
       0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     132,   133,   134,    38,    22,    32,    24,   114,    81,   112,
      25,    26,    40,    28,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      54,   -91,   -91,    -3,    30,     5,     6,     4,    51,   -14,
      51,   122,   162,    31,   -91,    54,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   156,   -91,   189,   -91,    42,   -91,    51,
      69,    32,   -91,   189,   -91,    42,    33,   -91,    48,   310,
       0,    51,    57,   293,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   265,   -91,
     -91,   -91,   -91,   202,   -91,   -91,   -91,   268,   242,   -91,
     -91,    30,    30,    30,    30,    30,    91,   -91,   340,     0,
     -91,    83,   189,    42,    41,    47,    70,    79,    47,    18,
      95,    86,    78,   325,   -91,   -91,   265,   -91,   268,   124,
     124,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    51,
     -91,    47,    87,    54,    80,    30,    30,    80,    30,   189,
      30,   189,    11,    47,    47,   189,    42,   -91,    47,   114,
      96,   -19,    80,   -91,   -91,   189,   189,    80,   -91,   189,
     189,    42,    80,    80,   -91,   -91,   -91,    51,   -91,   -91,
     -91,   -91,    80,   -91,    80,   -91,   105,   340,   -91,   -91,
      47,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -12,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
      -8,    20,   -90,    -9,   -91,     2,   -91,   -83,   -91,   -91,
      -4,   -91,     9,    60,   111,   -56,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      33,    42,    23,    70,    39,   117,    43,    97,   147,    27,
      34,    36,    97,    41,    35,    29,   113,    23,    91,    76,
      77,     1,     2,    31,    27,    78,    82,   138,   127,    37,
      30,    69,    92,     1,     2,    31,   118,    93,    79,    83,
     142,   143,   150,    11,    12,   144,   110,   151,   148,    11,
      12,    10,   153,   155,     1,     2,    31,     1,     2,     3,
       4,    76,   158,    10,   159,    30,    84,    99,   100,   101,
     102,   103,     1,     2,    31,   111,    85,   161,     5,     6,
       7,     8,   113,     9,    10,   119,   121,    10,   115,    11,
      12,    94,    11,    12,   104,   105,   106,   116,     1,     2,
      31,   130,    10,    80,   122,   125,   123,    11,    12,   137,
     131,   135,   136,   120,   139,    23,   140,   108,   126,   145,
     109,   128,    27,    68,   129,    44,    45,    46,    10,    11,
      12,   141,   146,   160,   152,   154,   107,     0,   156,     0,
      47,    48,    49,   157,    50,    73,    74,    75,    51,     0,
       0,    52,   149,    53,    54,    55,    56,   149,     0,    57,
      58,    59,    60,    61,    62,    44,    45,    46,     0,     0,
       0,     0,   149,     0,   149,   -72,   -72,   -72,   -72,   -72,
      47,    48,    49,     0,    50,     0,     0,     0,    51,     0,
       0,    52,     0,    53,    54,    55,    56,     0,     0,    57,
      66,    67,    60,    61,    62,    44,    45,    46,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,     0,    50,     0,     0,     0,    51,     0,
       0,    52,     0,    53,    54,    55,    56,     0,     0,    57,
      96,    59,    60,    61,    62,    44,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,     0,    50,     0,     0,     0,    51,     0,
       0,    52,     0,    53,    54,    55,    56,     0,     0,    57,
      66,    98,    60,    61,    62,  -101,     0,  -101,  -102,     0,
    -102,     0,     0,     0,     0,     0,  -101,  -101,     0,  -102,
    -102,     0,     0,     0,     0,  -101,  -101,  -101,  -102,  -102,
    -102,    86,    71,    72,    73,    74,    75,     0,     0,    87,
       0,     0,     0,     0,    89,    90,     0,    95,    86,    71,
      72,    73,    74,    75,     0,     0,    87,     0,    88,     0,
       0,    89,    90,    86,    71,    72,    73,    74,    75,     0,
       0,    87,     0,   124,     0,     0,    89,    90,    86,    71,
      72,    73,    74,    75,     0,     0,    87,     0,     0,     0,
       0,    89,    90
};

static const yytype_int16 yycheck[] =
{
       4,    10,     0,    15,     8,    88,    10,    63,    27,     0,
       5,     5,    68,    27,     5,    18,    35,    15,    18,    19,
      29,     3,     4,     5,    15,    29,    30,   117,   111,    25,
      33,     0,    41,     3,     4,     5,    18,    41,    29,    30,
     123,   124,   132,    38,    39,   128,     5,   137,   131,    38,
      39,    33,   142,   143,     3,     4,     5,     3,     4,     5,
       6,    19,   152,    33,   154,    33,    33,    71,    72,    73,
      74,    75,     3,     4,     5,    34,    28,   160,    24,    25,
      26,    27,    35,    29,    33,    89,    90,    33,    18,    38,
      39,    34,    38,    39,     3,     4,     5,    18,     3,     4,
       5,   113,    33,    34,    18,   109,    28,    38,    39,   117,
      30,   115,   116,    18,   118,   113,   120,    34,   109,     5,
      37,    34,   113,    12,    37,     3,     4,     5,    33,    38,
      39,   122,    36,    28,   142,   143,    76,    -1,   147,    -1,
      18,    19,    20,   147,    22,    21,    22,    23,    26,    -1,
      -1,    29,   132,    31,    32,    33,    34,   137,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,    -1,    -1,
      -1,    -1,   152,    -1,   154,    19,    20,    21,    22,    23,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    20,    -1,    22,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    31,
      32,    -1,    -1,    -1,    -1,    40,    41,    42,    40,    41,
      42,    18,    19,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    31,    32,    -1,    34,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    -1,
      -1,    31,    32,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    28,    -1,    -1,    31,    32,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    24,    25,    26,    27,    29,
      33,    38,    39,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    57,    58,    59,    63,    64,    65,    66,    18,
      33,     5,    58,    63,     5,    65,     5,    25,    56,    63,
      65,    27,    56,    63,     3,     4,     5,    18,    19,    20,
      22,    26,    29,    31,    32,    33,    34,    37,    38,    39,
      40,    41,    42,    67,    68,    69,    38,    39,    67,     0,
      45,    19,    20,    21,    22,    23,    19,    56,    63,    65,
      34,    61,    63,    65,    33,    28,    18,    26,    28,    31,
      32,    18,    56,    63,    34,    34,    38,    68,    39,    63,
      63,    63,    63,    63,     3,     4,     5,    66,    34,    37,
       5,    34,    62,    35,    60,    18,    18,    60,    18,    63,
      18,    63,    18,    28,    28,    63,    65,    60,    34,    37,
      45,    30,    53,    54,    55,    63,    63,    53,    55,    63,
      63,    65,    60,    60,    60,     5,    36,    27,    60,    54,
      55,    55,    53,    55,    53,    55,    56,    63,    55,    55,
      28,    60
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
#line 87 "gram.y"
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
#line 104 "gram.y"
    {
        statement_t *stmt = (statement_t*)(yyvsp[(1) - (2)].data);
        stmt->next = (statement_t*)(yyvsp[(2) - (2)].data);
        (yyval.data) = (yyvsp[(1) - (2)].data);
    }
    break;

  case 4:
#line 109 "gram.y"
    { (yyval.data) = NULL; }
    break;

  case 5:
#line 113 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 6:
#line 116 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 7:
#line 119 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCCALL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 8:
#line 122 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 9:
#line 125 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[(1) - (1)].data));
    }
    break;

  case 10:
#line 128 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_MATH, (yyvsp[(1) - (1)].data));
    }
    break;

  case 11:
#line 131 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_EMPTY_STR, (yyvsp[(1) - (1)].data));
    }
    break;

  case 12:
#line 134 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[(1) - (1)].data));
    }
    break;

  case 13:
#line 137 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[(1) - (1)].data));
    }
    break;

  case 14:
#line 140 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[(1) - (1)].data));
    }
    break;

  case 15:
#line 143 "gram.y"
    {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[(1) - (1)].data));
    }
    break;

  case 16:
#line 147 "gram.y"
    {
    (yyval.data) = newExpr_ID((yyvsp[(2) - (2)].id));
}
    break;

  case 17:
#line 149 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 18:
#line 153 "gram.y"
    {
    (yyval.data) = (yyvsp[(2) - (2)].data);
}
    break;

  case 19:
#line 157 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 20:
#line 161 "gram.y"
    {
    (yyval.data) = NULL;
}
    break;

  case 21:
#line 166 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 22:
#line 169 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 23:
#line 176 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (6)].data), (yyvsp[(4) - (6)].data));

        ifs->elif = (yyvsp[(5) - (6)].data);
        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 24:
#line 184 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[(2) - (5)].data), (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 25:
#line 191 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (4)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (4)].data));
    }
    break;

  case 26:
#line 197 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->elif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 27:
#line 207 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (6)].data));

        ifs->elif = (yyvsp[(5) - (6)].data);
        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 28:
#line 218 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(2) - (5)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, cond, (yyvsp[(4) - (5)].data));

        ifs->endif = (yyvsp[(5) - (5)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 29:
#line 230 "gram.y"
    {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
    }
    break;

  case 30:
#line 233 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 31:
#line 240 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (7)].data), (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 32:
#line 248 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[(3) - (6)].data), (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 33:
#line 255 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (5)].data), expr);

        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (5)].data));
    }
    break;

  case 34:
#line 261 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->elif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 35:
#line 271 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (7)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (7)].data));

        ifs->elif = (yyvsp[(6) - (7)].data);
        ifs->endif = (yyvsp[(7) - (7)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 36:
#line 282 "gram.y"
    {
        expr_t *expr = newExpr_Ival(0);
        ifCondition_t *cond = newConditional(CONDITION_GE, (yyvsp[(3) - (6)].data), expr);

        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, cond, (yyvsp[(5) - (6)].data));

        ifs->endif = (yyvsp[(6) - (6)].data);
        
        (yyval.data) = ifs;
    }
    break;

  case 37:
#line 294 "gram.y"
    {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[(1) - (2)].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[(2) - (2)].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
    break;

  case 38:
#line 301 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 39:
#line 306 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[(3) - (5)].data), (yyvsp[(5) - (5)].data));
       
        (yyval.data) = ifs;
    }
    break;

  case 40:
#line 313 "gram.y"
    {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[(2) - (2)].data));
        (yyval.data) = ifs;
    }
    break;

  case 41:
#line 319 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 42:
#line 322 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 43:
#line 325 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 44:
#line 328 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 45:
#line 331 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[(1) - (4)].data), (yyvsp[(4) - (4)].data));
    }
    break;

  case 46:
#line 334 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 47:
#line 337 "gram.y"
    {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[(1) - (3)].data), (yyvsp[(3) - (3)].data));
    }
    break;

  case 48:
#line 342 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].data),(yyvsp[(6) - (6)].data));
    }
    break;

  case 49:
#line 345 "gram.y"
    {
        (yyval.data) = newFunc((yyvsp[(2) - (5)].id),NULL,(yyvsp[(5) - (5)].data));
    }
    break;

  case 50:
#line 350 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].data));
    }
    break;

  case 51:
#line 353 "gram.y"
    {
        (yyval.data) = newFunCall((yyvsp[(1) - (3)].id),NULL);
    }
    break;

  case 52:
#line 358 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)].data));
    }
    break;

  case 53:
#line 361 "gram.y"
    {
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)].data));
    }
    break;

  case 54:
#line 364 "gram.y"
    {
        expr_t *expr = newExpr_Cond((yyvsp[(3) - (3)].data));
        (yyval.data) = newDeclaration((yyvsp[(1) - (3)].id),expr);
    }
    break;

  case 55:
#line 370 "gram.y"
    {
        (yyval.data) = newBody((yyvsp[(2) - (3)].data));
    }
    break;

  case 56:
#line 375 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 57:
#line 379 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 58:
#line 382 "gram.y"
    {
        expr_t *expr = (yyvsp[(3) - (3)].data);
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 59:
#line 386 "gram.y"
    {
        (yyval.data) = newArgument((yyvsp[(1) - (1)].data), NULL);
    }
    break;

  case 60:
#line 391 "gram.y"
    {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[(3) - (3)].id));
        (yyval.data) = newArgument(expr, (yyvsp[(1) - (3)].data));
    }
    break;

  case 61:
#line 396 "gram.y"
    {
        expr_t *expr = newExpr_ID((yyvsp[(1) - (1)].id));
        (yyval.data) = newArgument(expr, NULL);
    }
    break;

  case 62:
#line 402 "gram.y"
    {
        (yyval.data) = newExpr_OPAdd((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 63:
#line 405 "gram.y"
    {
        (yyval.data) = newExpr_OPSub((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 64:
#line 408 "gram.y"
    {
        (yyval.data) = newExpr_OPMul((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 65:
#line 411 "gram.y"
    {
        (yyval.data) = newExpr_OPMod((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 66:
#line 414 "gram.y"
    {
        (yyval.data) = newExpr_OPDiv((yyvsp[(1) - (3)].data),(yyvsp[(3) - (3)].data));
    }
    break;

  case 67:
#line 417 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 68:
#line 422 "gram.y"
    {
        (yyval.data) = newExpr_ID((yyvsp[(1) - (1)].id));
    }
    break;

  case 69:
#line 425 "gram.y"
    {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
    break;

  case 70:
#line 428 "gram.y"
    {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
    break;

  case 71:
#line 431 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 72:
#line 434 "gram.y"
    {
        (yyval.data) = newExpr_FuncCall((yyvsp[(1) - (1)].data));
    }
    break;

  case 73:
#line 437 "gram.y"
    {
        (yyval.data) = newExpr_Cond((yyvsp[(2) - (3)].data));
    }
    break;

  case 74:
#line 442 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = (expr_t*)(yyvsp[(3) - (3)].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 75:
#line 448 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        expr_t *e2 = newExpr_ID((yyvsp[(3) - (3)].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 76:
#line 454 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", (yyvsp[(3) - (3)].val_double));
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 77:
#line 462 "gram.y"
    {
        expr_t *e1 = (expr_t*)(yyvsp[(1) - (3)].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", (yyvsp[(3) - (3)].val_int));
        expr_t *e2 = newExpr_Text(buffer);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
    break;

  case 78:
#line 470 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 79:
#line 475 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 80:
#line 478 "gram.y"
    {
        (yyval.data) = (yyvsp[(2) - (3)].data);
    }
    break;

  case 81:
#line 481 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 82:
#line 485 "gram.y"
    {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
    break;

  case 83:
#line 491 "gram.y"
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
    }
    break;

  case 84:
#line 514 "gram.y"
    {
        (yyval.data) = (yyvsp[(1) - (1)].data);
    }
    break;

  case 85:
#line 519 "gram.y"
    {
        (yyval.data) = newExpr_Text(yyval.id);
    }
    break;

  case 86:
#line 522 "gram.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%lf", yyval.val_double);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 87:
#line 527 "gram.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", yyval.val_int);
        (yyval.data) = newExpr_Text(buffer);
    }
    break;

  case 88:
#line 532 "gram.y"
    {
        (yyval.data) = newExpr_Text((yyvsp[(1) - (1)].id));
    }
    break;

  case 89:
#line 537 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 90:
#line 542 "gram.y"
    {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
    break;

  case 91:
#line 546 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 92:
#line 550 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 93:
#line 554 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 94:
#line 558 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 95:
#line 562 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 96:
#line 566 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 97:
#line 570 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 98:
#line 574 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 99:
#line 578 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 100:
#line 582 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 101:
#line 586 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 102:
#line 590 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 103:
#line 594 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;

  case 104:
#line 598 "gram.y"
    {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2458 "y.tab.c"
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


#line 603 "gram.y"


#include "hooks.h"

void initParser() {
    setParser(yyparse);
    setRoot(&root);
}

