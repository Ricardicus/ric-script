/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

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


#line 108 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
#line 39 "gram.y"
 int val_int; double val_double; char id[256]; void *data; 

#line 197 "y.tab.c"

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

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  101
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

#define YYUNDEFTOK  2
#define YYMAXUTOK   272


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   121,   126,   130,   133,   136,   139,   142,
     145,   148,   151,   154,   157,   160,   164,   166,   171,   186,
     190,   194,   199,   202,   208,   214,   220,   226,   234,   237,
     240,   243,   246,   249,   252,   255,   258,   263,   266,   273,
     281,   290,   293,   300,   308,   317,   324,   329,   336,   342,
     345,   350,   353,   358,   361,   366,   371,   374,   377,   380,
     383,   386,   389,   393,   430,   433,   438,   441,   446,   450,
     454,   458,   464,   469,   474,   477,   482,   487,   494,   497,
     502,   512,   524,   529,   534,   538,   543,   547,   552,   557,
     563,   566,   570,   573,   579,   585,   591,   596,   599,   602,
     605,   611,   616,   621,   627,   633,   643,   653,   659,   665,
     670,   673,   676,   680,   686,   714,   719,   722,   729,   736,
     741,   746,   751,   756,   760,   764,   768,   772,   776,   780,
     784,   788,   792,   796,   800,   804,   808,   812,   816,   820,
     824,   828,   832,   836,   840,   844
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
  "'-'", "'*'", "'/'", "'%'", "'$'", "'('", "'.'", "')'", "'@'", "'!'",
  "'?'", "'['", "']'", "'~'", "'|'", "'&'", "'<'", "'>'", "';'", "':'",
  "'{'", "'}'", "','", "'\\''", "'\"'", "' '", "'\\\\'", "'^'", "$accept",
  "program", "statements", "statement", "systemStatement",
  "forEachStatement", "returnStatement", "continueStatement",
  "breakStatement", "expressions", "expression", "ifStatement",
  "loopStatement", "middleIfs", "middleIf", "endIf", "logical_a",
  "logical_b", "logical_expression", "condition", "class", "function",
  "classFunctionCall", "functionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "indexer", "mathContentDigit", "mathContentDouble", "stringContents",
  "stringContent", "stringEditions", "stringEdition", "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,    36,    40,    46,    41,    64,    33,
      63,    91,    93,   126,   124,    38,    60,    62,    59,    58,
     123,   125,    44,    39,    34,    32,    92,    94
};
# endif

#define YYPACT_NINF (-187)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-137)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,  -187,  -187,    53,   542,   166,    21,   542,    35,    44,
      24,    39,    56,    42,    95,   200,   245,    94,  -187,   147,
    -187,  -187,  -187,  -187,  -187,   192,    59,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,    83,  -187,  -187,
    -187,   567,   380,   388,   -10,   542,   192,    19,  -187,  -187,
    -187,    98,  -187,   278,   413,    58,  -187,   413,  -187,    84,
     192,    31,   124,   157,  -187,    17,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,    76,  -187,
    -187,  -187,  -187,  -187,  -187,   290,  -187,  -187,  -187,   101,
     335,  -187,  -187,   542,   542,   542,   542,   542,   103,   567,
     442,   542,   567,   606,  -187,  -187,   -18,   542,    70,   110,
     127,   323,    25,    92,   107,  -187,   542,   606,    96,   102,
     130,  -187,  -187,     8,   134,  -187,  -187,   542,   141,  -187,
      95,   542,    76,  -187,   101,   135,   135,  -187,  -187,  -187,
     177,   606,  -187,  -187,   -11,   236,   594,   159,   144,   170,
     456,   485,  -187,    59,  -187,   510,  -187,  -187,  -187,  -187,
    -187,   158,   165,  -187,   174,    59,   167,   175,   173,  -187,
     167,    13,   167,   192,   178,  -187,   192,    98,  -187,   198,
    -187,  -187,  -187,   542,   542,   542,   192,   542,   192,    59,
     212,   147,   195,   413,   413,  -187,   167,   228,   195,   167,
     517,   192,   192,   192,   192,   213,   211,    27,   195,  -187,
    -187,   130,  -187,  -187,  -187,   195,  -187,  -187,  -187,    30,
     167,  -187,   413,  -187,  -187,  -187,  -187,  -187,  -187,   149,
     167,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   101,   102,    35,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    79,     0,     0,     0,     2,     4,
      14,    10,    13,    11,    12,     7,    22,     8,     9,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    92,    90,
      34,     0,     0,     0,    35,     0,    19,    28,    93,    91,
      16,    17,   109,     0,     0,     0,    21,     0,    85,     0,
      87,     0,     0,     0,    78,     0,   116,   119,   145,   121,
     126,   140,   127,   142,   131,   137,   132,   133,   123,   138,
     139,   144,   143,   124,   125,   130,   129,   134,   113,   136,
     122,   128,   141,   118,   117,     0,   115,   120,   135,   112,
       0,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    69,     0,   100,     0,    22,
       0,     0,     0,     0,     0,    36,     0,     0,    22,     0,
      50,    52,    53,     0,     0,    84,    83,     0,     0,    76,
       0,     0,   110,   114,   111,    23,    25,    24,    27,    26,
       0,    74,    75,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    98,    94,    99,    95,   104,   106,   105,
     103,     0,   108,   107,     0,    54,     0,     0,     0,    89,
       0,     0,     0,    86,     0,    77,    80,    81,    34,     0,
      70,    96,    62,     0,     0,     0,    60,     0,    61,    97,
       0,     4,    41,     0,     0,    65,     0,     0,    37,     0,
       0,    56,    57,    58,    59,     0,     0,     0,    42,    46,
      44,    49,    51,    64,    88,    38,    40,    63,    67,     0,
       0,    82,     0,    48,    45,    43,    39,    66,    18,     0,
       0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,   -17,  -187,  -187,   229,  -187,  -187,  -187,     0,
     -40,  -187,  -187,    45,  -172,  -186,   -52,    51,    57,   -30,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,   120,  -155,  -187,
     -36,  -187,  -187,     1,  -187,    32,    18,     2,     4,   246,
      20,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,   127,
      26,    27,    28,   218,   219,   220,   129,   130,   131,   132,
      29,    30,    31,    32,    33,    34,    63,    64,   202,    35,
      61,   181,    36,    47,   120,    38,    39,    65,    40,    95,
      96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,   102,   119,    46,   134,   116,    53,    51,   162,
      52,   114,    60,   179,   128,    42,   190,   128,    52,    25,
      37,    43,   226,    49,   137,   205,    50,   208,     1,     2,
     167,   137,   235,    94,    94,   180,   122,    48,   123,   236,
     206,   113,    60,   118,   110,   121,   234,    93,    93,    55,
     111,   223,    56,   234,   227,   207,   141,   237,   232,     1,
       2,    44,   233,   136,    15,    16,    54,   201,    15,    16,
      57,    41,   137,   137,   154,   238,     5,   163,    42,   152,
      62,     7,   157,   133,    43,   241,   175,    12,    58,   103,
     104,   105,   106,   107,   101,     1,    14,   171,   108,    15,
      16,   109,   164,   145,   146,   147,   148,   149,   110,   151,
      60,   155,   156,    94,   111,   143,   135,   122,    94,   123,
     143,  -135,  -135,  -135,   172,   199,   170,    93,   -55,   138,
     -55,   -55,    93,   174,   176,   108,   177,   183,    15,    16,
     169,   186,   150,   187,    52,   188,  -136,  -136,  -136,   165,
       1,     2,     3,     4,   168,   173,   105,   106,   107,   166,
     196,   198,   193,   128,   128,   178,   182,     5,   177,     1,
       2,     6,     7,     8,   229,     9,    10,    11,    12,   184,
     239,   240,   189,   177,   216,    13,   192,    14,   194,    43,
      15,    16,   128,   211,   212,   213,   111,   214,   139,   140,
     200,    25,    37,     1,     2,    66,    67,   201,   204,   203,
      60,   103,   104,   105,   106,   107,   209,   215,    68,    69,
      70,    71,    72,   210,    73,    74,    75,    76,   217,    77,
      78,    79,    80,   224,    81,    82,    83,    84,    85,    86,
     230,    59,    87,    88,    89,    90,    91,    92,     1,     2,
      66,    67,   231,   225,   221,   103,   104,   105,   106,   107,
     185,   222,   100,    68,    69,    70,    71,    72,   191,    73,
      74,    75,    76,     0,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,     0,     0,    87,    98,    99,
      90,    91,    92,     1,     2,    66,    67,   103,   104,   105,
     106,   107,     0,     0,   124,   125,     0,     0,    68,    69,
      70,    71,    72,     0,    73,    74,    75,    76,     0,    77,
      78,    79,    80,     0,    81,    82,    83,    84,    85,    86,
       0,     0,    87,   142,    89,    90,    91,    92,     1,     2,
      66,    67,   103,   104,   105,   106,   107,     0,     0,     0,
     125,     0,     0,    68,    69,    70,    71,    72,     0,    73,
      74,    75,    76,     0,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,     0,     0,    87,    98,   144,
      90,    91,    92,     1,     2,    44,     0,     0,     0,     0,
       0,     1,     2,    44,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,    45,     0,   115,     5,     0,
       0,    12,     0,    45,     0,     0,     1,     2,    44,    12,
      14,     0,     0,    15,    16,     0,     0,   117,    14,     0,
       0,    15,    16,     5,     0,     0,     0,     0,   112,     0,
       0,     0,   126,     0,    12,     1,     2,    44,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,     1,
       2,    44,     5,     0,     0,     0,     0,    45,     0,   153,
       0,     0,     0,    12,   195,     0,     5,     0,     0,     0,
       0,    45,    14,     0,     0,    15,    16,    12,     1,     2,
      44,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,     0,   197,     0,     5,     0,     0,     0,     0,
      45,     0,     0,     1,     2,    44,    12,     0,     0,     0,
       1,     2,    44,     0,     0,    14,     0,     0,    15,    16,
       5,     0,     0,     0,     0,    45,     0,     5,     0,     0,
       0,    12,    45,     0,   228,     1,     2,    44,    12,   150,
      14,     0,     0,    15,    16,     0,     0,    14,     0,     0,
      15,    16,     5,     0,     0,     0,     0,    45,     0,     0,
       1,     2,    44,    12,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     5,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,   158,   103,   104,   105,   106,   107,     0,     0,
       0,   125,     0,   159,   158,   103,   104,   105,   106,   107,
     160,   161,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,   160,   161
};

static const yytype_int16 yycheck[] =
{
       0,     0,    19,    43,     4,    57,    42,     7,     6,    27,
       6,    41,    12,     5,    54,    25,    27,    57,    14,    19,
      19,    31,   208,     5,    42,   180,     5,   182,     3,     4,
       5,    42,   218,    15,    16,    27,    19,     5,    21,   225,
      27,    41,    42,    43,    25,    45,   218,    15,    16,     5,
      31,   206,    28,   225,   209,    42,    39,    27,    31,     3,
       4,     5,   217,    32,    43,    44,    31,    40,    43,    44,
      31,    18,    42,    42,   110,   230,    20,   117,    25,   109,
      38,    25,   112,    25,    31,   240,   126,    31,    32,    19,
      20,    21,    22,    23,     0,     3,    40,     5,    39,    43,
      44,    18,    32,   103,   104,   105,   106,   107,    25,   109,
     110,   111,   112,    95,    31,    95,    32,    19,   100,    21,
     100,    45,    46,    47,   123,   165,   122,    95,    32,     5,
      34,    35,   100,    26,    32,    39,    34,   137,    43,    44,
     122,   141,    39,   141,   140,   141,    45,    46,    47,    39,
       3,     4,     5,     6,   122,   123,    21,    22,    23,    32,
     160,   161,    18,   203,   204,    35,    32,    20,    34,     3,
       4,    24,    25,    26,   210,    28,    29,    30,    31,    38,
     232,    32,     5,    34,   201,    38,    27,    40,    18,    31,
      43,    44,   232,   193,   194,   195,    31,   197,    41,    42,
      26,   201,   201,     3,     4,     5,     6,    40,    35,    34,
     210,    19,    20,    21,    22,    23,    38,     5,    18,    19,
      20,    21,    22,    25,    24,    25,    26,    27,    33,    29,
      30,    31,    32,     5,    34,    35,    36,    37,    38,    39,
      27,    12,    42,    43,    44,    45,    46,    47,     3,     4,
       5,     6,    41,   208,   203,    19,    20,    21,    22,    23,
     140,   204,    16,    18,    19,    20,    21,    22,    32,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    46,    47,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    43,    44,    45,    46,    47,     3,     4,
       5,     6,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    46,    47,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    20,    -1,
      -1,    31,    -1,    25,    -1,    -1,     3,     4,     5,    31,
      40,    -1,    -1,    43,    44,    -1,    -1,    39,    40,    -1,
      -1,    43,    44,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    -1,     3,
       4,     5,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,
      -1,    -1,    -1,    31,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    40,    -1,    -1,    43,    44,    31,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,
      44,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    -1,    -1,     3,     4,     5,    31,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    40,    -1,    -1,    43,    44,
      20,    -1,    -1,    -1,    -1,    25,    -1,    20,    -1,    -1,
      -1,    31,    25,    -1,    27,     3,     4,     5,    31,    39,
      40,    -1,    -1,    43,    44,    -1,    -1,    40,    -1,    -1,
      43,    44,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
       3,     4,     5,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    44,    20,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    44,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    27,    -1,    29,    18,    19,    20,    21,    22,    23,
      36,    37,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    28,
      29,    30,    31,    38,    40,    43,    44,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    68,
      69,    70,    71,    72,    73,    77,    80,    81,    83,    84,
      86,    18,    25,    31,     5,    25,    57,    81,    83,    84,
       5,    85,    86,    57,    31,     5,    28,    31,    32,    53,
      57,    78,    38,    74,    75,    85,     5,     6,    18,    19,
      20,    21,    22,    24,    25,    26,    27,    29,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    42,    43,    44,
      45,    46,    47,    83,    84,    87,    88,    89,    43,    44,
      87,     0,    50,    19,    20,    21,    22,    23,    39,    18,
      25,    31,    25,    57,    67,    27,    78,    39,    57,    58,
      82,    57,    19,    21,    26,    27,    29,    57,    58,    64,
      65,    66,    67,    25,    64,    32,    32,    42,     5,    41,
      42,    39,    43,    88,    44,    57,    57,    57,    57,    57,
      39,    57,    67,    27,    78,    57,    57,    67,    18,    29,
      36,    37,    27,    58,    32,    39,    32,     5,    83,    84,
      86,     5,    81,    83,    26,    58,    32,    34,    35,     5,
      27,    79,    32,    57,    38,    75,    57,    85,    86,     5,
      27,    32,    27,    18,    18,    18,    57,    18,    57,    58,
      26,    40,    76,    34,    35,    76,    27,    42,    76,    38,
      25,    57,    57,    57,    57,     5,    50,    33,    61,    62,
      63,    65,    66,    76,     5,    61,    63,    76,    27,    78,
      27,    41,    31,    76,    62,    63,    63,    27,    76,    64,
      32,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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
      82,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 1643 "y.tab.c"
    break;

  case 3:
#line 121 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1653 "y.tab.c"
    break;

  case 4:
#line 126 "gram.y"
      { (yyval.data) = NULL; }
#line 1659 "y.tab.c"
    break;

  case 5:
#line 130 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1667 "y.tab.c"
    break;

  case 6:
#line 133 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1675 "y.tab.c"
    break;

  case 7:
#line 136 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1683 "y.tab.c"
    break;

  case 8:
#line 139 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1691 "y.tab.c"
    break;

  case 9:
#line 142 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1699 "y.tab.c"
    break;

  case 10:
#line 145 "gram.y"
                       {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1707 "y.tab.c"
    break;

  case 11:
#line 148 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1715 "y.tab.c"
    break;

  case 12:
#line 151 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1723 "y.tab.c"
    break;

  case 13:
#line 154 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1731 "y.tab.c"
    break;

  case 14:
#line 157 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1739 "y.tab.c"
    break;

  case 15:
#line 160 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1747 "y.tab.c"
    break;

  case 16:
#line 164 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1755 "y.tab.c"
    break;

  case 17:
#line 166 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1763 "y.tab.c"
    break;

  case 18:
#line 171 "gram.y"
                                            {
    body_t *bd = (yyvsp[0].data);
    statement_t *stmt = bd->content;

    while ( stmt != NULL ) {
        if ( stmt->entity == LANG_ENTITY_BODY_END ) {
            /* Set entity to continue */
            stmt->entity = LANG_ENTITY_CONTINUE;
        }
        stmt = stmt->next;
    }

    (yyval.data) = newForEach((yyvsp[-6].data), (yyvsp[-2].id), bd);
}
#line 1782 "y.tab.c"
    break;

  case 19:
#line 186 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1790 "y.tab.c"
    break;

  case 20:
#line 190 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1798 "y.tab.c"
    break;

  case 21:
#line 194 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1806 "y.tab.c"
    break;

  case 22:
#line 199 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1814 "y.tab.c"
    break;

  case 23:
#line 202 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1825 "y.tab.c"
    break;

  case 24:
#line 208 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1836 "y.tab.c"
    break;

  case 25:
#line 214 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1847 "y.tab.c"
    break;

  case 26:
#line 220 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1858 "y.tab.c"
    break;

  case 27:
#line 226 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1869 "y.tab.c"
    break;

  case 28:
#line 234 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1877 "y.tab.c"
    break;

  case 29:
#line 237 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1885 "y.tab.c"
    break;

  case 30:
#line 240 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1893 "y.tab.c"
    break;

  case 31:
#line 243 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1901 "y.tab.c"
    break;

  case 32:
#line 246 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1909 "y.tab.c"
    break;

  case 33:
#line 249 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1917 "y.tab.c"
    break;

  case 34:
#line 252 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1925 "y.tab.c"
    break;

  case 35:
#line 255 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1933 "y.tab.c"
    break;

  case 36:
#line 258 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1941 "y.tab.c"
    break;

  case 37:
#line 263 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1949 "y.tab.c"
    break;

  case 38:
#line 266 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1961 "y.tab.c"
    break;

  case 39:
#line 273 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1974 "y.tab.c"
    break;

  case 40:
#line 281 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1986 "y.tab.c"
    break;

  case 41:
#line 290 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1994 "y.tab.c"
    break;

  case 42:
#line 293 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2006 "y.tab.c"
    break;

  case 43:
#line 300 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2019 "y.tab.c"
    break;

  case 44:
#line 308 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2031 "y.tab.c"
    break;

  case 45:
#line 317 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2043 "y.tab.c"
    break;

  case 46:
#line 324 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2051 "y.tab.c"
    break;

  case 47:
#line 329 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2061 "y.tab.c"
    break;

  case 48:
#line 336 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2070 "y.tab.c"
    break;

  case 49:
#line 342 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2078 "y.tab.c"
    break;

  case 50:
#line 345 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2086 "y.tab.c"
    break;

  case 51:
#line 350 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2094 "y.tab.c"
    break;

  case 52:
#line 353 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2102 "y.tab.c"
    break;

  case 53:
#line 358 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2110 "y.tab.c"
    break;

  case 54:
#line 361 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2120 "y.tab.c"
    break;

  case 55:
#line 366 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2128 "y.tab.c"
    break;

  case 56:
#line 371 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2136 "y.tab.c"
    break;

  case 57:
#line 374 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2144 "y.tab.c"
    break;

  case 58:
#line 377 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2152 "y.tab.c"
    break;

  case 59:
#line 380 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2160 "y.tab.c"
    break;

  case 60:
#line 383 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2168 "y.tab.c"
    break;

  case 61:
#line 386 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2176 "y.tab.c"
    break;

  case 62:
#line 389 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2184 "y.tab.c"
    break;

  case 63:
#line 393 "gram.y"
                               {
    /* Only declarations allowed */
    body_t *bod = (yyvsp[0].data);
    statement_t *walk = bod->content;
    char *classId = ast_emalloc(strlen((yyvsp[-3].id))+2);
    memset(classId, 0, strlen((yyvsp[-3].id))+1);
    while ( walk != NULL ) {
        if (
            walk->entity != LANG_ENTITY_DECL &&
            walk->entity != LANG_ENTITY_FUNCDECL &&
            walk->entity != LANG_ENTITY_BODY &&
            walk->entity != LANG_ENTITY_BODY_END
        ) {
            fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[-3].id));
            fprintf(stderr, "  You may only have variable and or function declaration statements here.\r\n");
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, (yyvsp[-3].id)) == 0 ) {
                if ( funcDef->params != NULL ) {
                    fprintf(stderr, "Syntax error, class '%s':\r\n", (yyvsp[-3].id));
                    fprintf(stderr, "  You may not define a constructor with function parameters.\r\n");
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    snprintf(classId, strlen((yyvsp[-3].id))+2, "%s", (yyvsp[-3].id));
    (yyval.data) = newClass(classId, bod);
}
#line 2224 "y.tab.c"
    break;

  case 64:
#line 430 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2232 "y.tab.c"
    break;

  case 65:
#line 433 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2240 "y.tab.c"
    break;

  case 66:
#line 438 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2248 "y.tab.c"
    break;

  case 67:
#line 441 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2256 "y.tab.c"
    break;

  case 68:
#line 446 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2265 "y.tab.c"
    break;

  case 69:
#line 450 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2274 "y.tab.c"
    break;

  case 70:
#line 454 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2283 "y.tab.c"
    break;

  case 71:
#line 458 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2292 "y.tab.c"
    break;

  case 72:
#line 464 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2302 "y.tab.c"
    break;

  case 73:
#line 469 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2312 "y.tab.c"
    break;

  case 74:
#line 474 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2320 "y.tab.c"
    break;

  case 75:
#line 477 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2328 "y.tab.c"
    break;

  case 76:
#line 482 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2336 "y.tab.c"
    break;

  case 77:
#line 487 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2348 "y.tab.c"
    break;

  case 78:
#line 494 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2356 "y.tab.c"
    break;

  case 79:
#line 497 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2364 "y.tab.c"
    break;

  case 80:
#line 502 "gram.y"
                                   {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2379 "y.tab.c"
    break;

  case 81:
#line 512 "gram.y"
                                        {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2394 "y.tab.c"
    break;

  case 82:
#line 524 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2402 "y.tab.c"
    break;

  case 83:
#line 529 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2411 "y.tab.c"
    break;

  case 84:
#line 534 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2420 "y.tab.c"
    break;

  case 85:
#line 538 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2428 "y.tab.c"
    break;

  case 86:
#line 543 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2437 "y.tab.c"
    break;

  case 87:
#line 547 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2445 "y.tab.c"
    break;

  case 88:
#line 552 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2455 "y.tab.c"
    break;

  case 89:
#line 557 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2464 "y.tab.c"
    break;

  case 90:
#line 563 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2472 "y.tab.c"
    break;

  case 91:
#line 566 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2481 "y.tab.c"
    break;

  case 92:
#line 570 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2489 "y.tab.c"
    break;

  case 93:
#line 573 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2498 "y.tab.c"
    break;

  case 94:
#line 579 "gram.y"
                           {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2509 "y.tab.c"
    break;

  case 95:
#line 585 "gram.y"
                         {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2520 "y.tab.c"
    break;

  case 96:
#line 591 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2528 "y.tab.c"
    break;

  case 97:
#line 596 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2536 "y.tab.c"
    break;

  case 98:
#line 599 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data));
  }
#line 2544 "y.tab.c"
    break;

  case 99:
#line 602 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL);
  }
#line 2552 "y.tab.c"
    break;

  case 100:
#line 605 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL);
  }
#line 2560 "y.tab.c"
    break;

  case 101:
#line 611 "gram.y"
          {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2568 "y.tab.c"
    break;

  case 102:
#line 616 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2576 "y.tab.c"
    break;

  case 103:
#line 621 "gram.y"
                                     {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2587 "y.tab.c"
    break;

  case 104:
#line 627 "gram.y"
                             {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2598 "y.tab.c"
    break;

  case 105:
#line 633 "gram.y"
                                            {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2613 "y.tab.c"
    break;

  case 106:
#line 643 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2628 "y.tab.c"
    break;

  case 107:
#line 653 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2639 "y.tab.c"
    break;

  case 108:
#line 659 "gram.y"
                                        {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2650 "y.tab.c"
    break;

  case 109:
#line 665 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2658 "y.tab.c"
    break;

  case 110:
#line 670 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2666 "y.tab.c"
    break;

  case 111:
#line 673 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2674 "y.tab.c"
    break;

  case 112:
#line 676 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2683 "y.tab.c"
    break;

  case 113:
#line 680 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2692 "y.tab.c"
    break;

  case 114:
#line 686 "gram.y"
                                 {
        char *textBuffer;

        expr_t *e1 = (expr_t*)(yyvsp[-1].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

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
#line 2725 "y.tab.c"
    break;

  case 115:
#line 714 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2733 "y.tab.c"
    break;

  case 116:
#line 719 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2741 "y.tab.c"
    break;

  case 117:
#line 722 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2753 "y.tab.c"
    break;

  case 118:
#line 729 "gram.y"
                       {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2765 "y.tab.c"
    break;

  case 119:
#line 736 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2775 "y.tab.c"
    break;

  case 120:
#line 741 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2783 "y.tab.c"
    break;

  case 121:
#line 746 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2792 "y.tab.c"
    break;

  case 122:
#line 751 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2801 "y.tab.c"
    break;

  case 123:
#line 756 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2810 "y.tab.c"
    break;

  case 124:
#line 760 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2819 "y.tab.c"
    break;

  case 125:
#line 764 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2828 "y.tab.c"
    break;

  case 126:
#line 768 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2837 "y.tab.c"
    break;

  case 127:
#line 772 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2846 "y.tab.c"
    break;

  case 128:
#line 776 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2855 "y.tab.c"
    break;

  case 129:
#line 780 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2864 "y.tab.c"
    break;

  case 130:
#line 784 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2873 "y.tab.c"
    break;

  case 131:
#line 788 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2882 "y.tab.c"
    break;

  case 132:
#line 792 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2891 "y.tab.c"
    break;

  case 133:
#line 796 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2900 "y.tab.c"
    break;

  case 134:
#line 800 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2909 "y.tab.c"
    break;

  case 135:
#line 804 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2918 "y.tab.c"
    break;

  case 136:
#line 808 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2927 "y.tab.c"
    break;

  case 137:
#line 812 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2936 "y.tab.c"
    break;

  case 138:
#line 816 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2945 "y.tab.c"
    break;

  case 139:
#line 820 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2954 "y.tab.c"
    break;

  case 140:
#line 824 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2963 "y.tab.c"
    break;

  case 141:
#line 828 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2972 "y.tab.c"
    break;

  case 142:
#line 832 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2981 "y.tab.c"
    break;

  case 143:
#line 836 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2990 "y.tab.c"
    break;

  case 144:
#line 840 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2999 "y.tab.c"
    break;

  case 145:
#line 844 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3008 "y.tab.c"
    break;


#line 3012 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 849 "gram.y"


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
