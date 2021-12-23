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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   763

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

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
     454,   458,   464,   469,   476,   483,   490,   497,   502,   505,
     510,   515,   522,   525,   530,   539,   550,   555,   560,   564,
     569,   573,   578,   583,   589,   592,   596,   599,   605,   611,
     617,   622,   625,   628,   631,   634,   637,   640,   643,   646,
     652,   661,   666,   672,   678,   688,   706,   712,   718,   723,
     726,   729,   733,   739,   767,   772,   775,   782,   797,   802,
     807,   812,   817,   821,   825,   829,   833,   837,   841,   845,
     849,   853,   857,   861,   865,   869,   873,   877,   881,   885,
     889,   893,   897,   901,   905,   909,   913
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

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     403,  -214,  -214,    67,   637,    93,    13,   637,     8,    26,
      50,    62,    59,    91,    94,   223,   268,   105,  -214,   403,
    -214,  -214,  -214,  -214,  -214,   194,    77,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    42,  -214,  -214,
    -214,   662,   128,   131,   139,   150,   136,   417,    75,   637,
     194,    76,  -214,  -214,  -214,   111,  -214,   256,   446,   133,
    -214,   446,  -214,   137,   194,    -4,   172,    78,  -214,    29,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,    80,  -214,  -214,  -214,  -214,  -214,
    -214,   313,  -214,  -214,  -214,    97,   358,  -214,  -214,   637,
     637,   637,   637,   637,   142,   662,   460,   637,   662,   726,
    -214,   637,   637,   637,   637,  -214,   -19,   489,   173,   146,
     159,   301,     9,   147,   152,  -214,   637,   726,    37,   140,
     162,  -214,  -214,     6,   141,  -214,  -214,   637,   144,  -214,
      94,   637,    80,  -214,    97,   143,   143,  -214,  -214,  -214,
     195,   726,  -214,  -214,    -6,   214,   714,   174,   181,   185,
     518,   547,   194,   194,   194,   194,  -214,   637,   167,  -214,
     572,  -214,  -214,  -214,  -214,  -214,   176,   187,  -214,   197,
      77,   190,   191,   196,  -214,   190,    -2,   190,   194,   200,
    -214,   194,   111,  -214,   207,  -214,  -214,  -214,   637,   637,
     637,   194,   637,   194,    77,   579,   687,   201,   234,   403,
     218,   446,   446,  -214,   190,   275,   218,   190,   604,   194,
     194,   194,   194,    77,    83,    77,   579,   254,   243,    34,
     218,  -214,  -214,   162,  -214,  -214,  -214,   218,  -214,  -214,
    -214,    17,   629,    77,   190,  -214,   446,  -214,  -214,  -214,
    -214,  -214,  -214,    28,  -214,   154,  -214,   190,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   110,   111,    35,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    83,     0,     0,     0,     2,     4,
      14,    10,    13,    11,    12,     7,    22,     8,     9,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    96,    94,
      34,     0,     0,     0,     0,     0,     0,     0,    35,     0,
      19,    28,    97,    95,    16,    17,   118,     0,     0,     0,
      21,     0,    89,     0,    91,     0,     0,     0,    82,     0,
     125,   128,   156,   130,   135,   149,   136,   151,   140,   146,
     141,   142,   132,   147,   148,   153,   152,   133,   134,   139,
     138,   154,   155,   143,   122,   145,   131,   137,   150,   127,
     126,     0,   124,   129,   144,   121,     0,     1,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      77,     0,     0,     0,     0,    69,     0,   104,     0,    22,
       0,     0,     0,     0,     0,    36,     0,     0,    22,     0,
      50,    52,    53,     0,     0,    88,    87,     0,     0,    80,
       0,     0,   119,   123,   120,    23,    25,    24,    27,    26,
       0,    78,    79,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    68,   109,   102,    98,
     103,    99,   113,   115,   114,   112,     0,   117,   116,     0,
      54,     0,     0,     0,    93,     0,     0,     0,    90,     0,
      81,    84,    85,    34,     0,    70,   100,    62,     0,     0,
       0,    60,     0,    61,   108,     0,     0,   101,     0,     4,
      41,     0,     0,    65,     0,     0,    37,     0,     0,    56,
      57,    58,    59,   106,    35,   107,     0,     0,     0,     0,
      42,    46,    44,    49,    51,    64,    92,    38,    40,    63,
      67,     0,     0,   105,     0,    86,     0,    48,    45,    43,
      39,    66,    67,     0,    18,     0,    66,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,   -17,  -214,  -214,   273,  -214,  -214,  -214,     0,
     -32,  -214,  -214,    65,  -213,  -210,   -58,   104,    74,   -35,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,   151,  -173,  -214,
     -41,  -214,  -214,     1,  -214,    27,    30,     4,     3,   310,
     -24,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    64,
      26,    27,    28,   240,   241,   242,   139,   140,   141,   142,
      29,    30,    31,    32,    33,    34,    67,    68,   220,    35,
      65,   196,    36,    51,   130,    38,    39,    69,    40,   101,
     102,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,   108,   144,    50,   126,   120,    57,   176,    56,
      55,   194,     1,     2,   182,   129,   248,    56,    54,    25,
      37,   205,   223,   147,   226,   224,   138,   258,   146,   138,
     259,    59,    52,   195,   258,    53,   147,   260,   147,    58,
     225,   119,    99,    99,   261,   100,   100,   128,   132,   131,
     133,   245,    15,    16,   249,   266,    15,    16,   137,   147,
     115,   137,     1,     2,    48,   256,   257,   116,   151,   -55,
     147,   -55,   -55,   117,   219,   164,   114,   153,    60,     5,
     162,   264,   153,   167,     7,    41,    42,    43,    44,    45,
      12,    62,    46,    61,   268,   178,     1,     2,    47,    14,
      46,   116,    15,    16,   190,   107,    47,   117,   252,   155,
     156,   157,   158,   159,    47,   161,   114,   165,   166,   149,
     150,   172,   173,   174,   175,  -144,  -144,  -144,    99,    66,
     132,   100,   133,    99,   187,   185,   100,    15,    16,     1,
       2,    48,  -145,  -145,  -145,   214,   121,   198,   217,   122,
       1,   201,   186,    56,   203,   202,     5,   123,   143,   183,
     188,    49,   184,   125,   111,   112,   113,    12,   124,   145,
     211,   213,   191,   197,   192,   192,    14,   148,   189,    15,
      16,   160,   199,   233,   235,   180,   267,   251,   192,   138,
     138,   181,   109,   110,   111,   112,   113,   193,   265,   208,
     204,   207,   238,   209,   253,   179,   215,    47,   229,   230,
     231,   263,   232,   109,   110,   111,   112,   113,   117,    25,
      37,   137,   137,   218,   138,   221,     1,     2,    70,    71,
     219,   222,   228,   109,   110,   111,   112,   113,   227,   237,
     236,    72,    73,    74,    75,    76,   206,    77,    78,    79,
      80,   239,    81,    82,    83,    84,   137,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     1,     2,    70,    71,   109,   110,   111,   112,   113,
     246,   254,   134,   135,   255,    63,    72,    73,    74,    75,
      76,   247,    77,    78,    79,    80,   244,    81,    82,    83,
      84,   200,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   104,   105,    96,    97,    98,     1,     2,    70,    71,
     109,   110,   111,   112,   113,   243,   106,     0,   135,     0,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
      80,     0,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   152,    95,    96,    97,
      98,     1,     2,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,    80,     0,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   104,   154,    96,    97,    98,     1,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,    48,     5,     0,     0,     0,     6,     7,     8,
       0,     9,    10,    11,    12,     0,     0,     5,     0,     0,
       0,    13,    49,    14,     0,     0,    15,    16,    12,     1,
       2,    48,     0,     0,     0,     0,   127,    14,     0,     0,
      15,    16,     0,     1,     2,    48,     5,     0,     0,     0,
       0,   118,     0,     0,     0,   136,     0,    12,     0,     0,
       5,     0,     0,     0,     0,    49,    14,   163,     0,    15,
      16,    12,     1,     2,    48,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,     0,     0,     0,     5,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
      12,     1,     2,    48,     0,     0,     0,     0,   177,    14,
       0,     0,    15,    16,     0,     0,   210,     0,     5,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,    12,
       1,     2,    48,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,     0,   212,     0,     5,     0,     0,
       0,     0,    49,     0,     0,     1,     2,    48,    12,     0,
       0,     0,     1,     2,    48,     0,     0,    14,     0,     0,
      15,    16,     5,     0,     0,     0,     0,    49,     0,     5,
       0,     0,     0,    12,    49,     0,     0,     1,     2,    48,
      12,   216,    14,     0,     0,    15,    16,     0,   160,    14,
       0,     0,    15,    16,     5,     0,     0,     0,     0,    49,
       0,   250,     1,     2,    48,    12,     0,     0,     0,     0,
       1,     2,    48,     0,    14,     0,     0,    15,    16,     5,
       0,     0,     0,     0,    49,     0,   262,     5,     0,     0,
      12,     0,    49,     0,     0,     1,     2,    48,    12,    14,
       0,     0,    15,    16,     0,     0,     0,    14,     0,     0,
      15,    16,     5,     0,     0,     0,     0,   118,     0,     0,
       1,     2,   234,    12,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     5,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,   168,   109,   110,   111,   112,   113,     0,     0,
       0,   135,     0,   169,   168,   109,   110,   111,   112,   113,
     170,   171,     0,     0,     0,   169,     0,     0,     0,     0,
       0,     0,   170,   171
};

static const yytype_int16 yycheck[] =
{
       0,     0,    19,    61,     4,    46,    41,     7,    27,     6,
       6,     5,     3,     4,     5,    47,   226,    14,     5,    19,
      19,    27,   195,    42,   197,    27,    58,   240,    32,    61,
     240,     5,     5,    27,   247,     5,    42,   247,    42,    31,
      42,    41,    15,    16,    27,    15,    16,    47,    19,    49,
      21,   224,    43,    44,   227,    27,    43,    44,    58,    42,
      18,    61,     3,     4,     5,    31,   239,    25,    39,    32,
      42,    34,    35,    31,    40,   116,    39,   101,    28,    20,
     115,   254,   106,   118,    25,    18,    19,    20,    21,    22,
      31,    32,    25,    31,   267,   127,     3,     4,    31,    40,
      25,    25,    43,    44,   136,     0,    31,    31,    25,   109,
     110,   111,   112,   113,    31,   115,    39,   117,   118,    41,
      42,   121,   122,   123,   124,    45,    46,    47,   101,    38,
      19,   101,    21,   106,   133,   132,   106,    43,    44,     3,
       4,     5,    45,    46,    47,   177,    18,   147,   180,    18,
       3,   151,     5,   150,   151,   151,    20,    18,    25,   132,
     133,    25,   132,    27,    21,    22,    23,    31,    18,    32,
     170,   171,    32,    32,    34,    34,    40,     5,    26,    43,
      44,    39,    38,   215,   216,    39,    32,   228,    34,   221,
     222,    32,    19,    20,    21,    22,    23,    35,   256,    18,
       5,    27,   219,    18,   236,    32,    39,    31,   208,   209,
     210,   252,   212,    19,    20,    21,    22,    23,    31,   219,
     219,   221,   222,    26,   256,    34,     3,     4,     5,     6,
      40,    35,    25,    19,    20,    21,    22,    23,    38,     5,
      39,    18,    19,    20,    21,    22,    32,    24,    25,    26,
      27,    33,    29,    30,    31,    32,   256,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,    19,    20,    21,    22,    23,
       5,    27,    26,    27,    41,    12,    18,    19,    20,    21,
      22,   226,    24,    25,    26,    27,   222,    29,    30,    31,
      32,   150,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      19,    20,    21,    22,    23,   221,    16,    -1,    27,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    20,    -1,    -1,    -1,    24,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    20,    -1,    -1,
      -1,    38,    25,    40,    -1,    -1,    43,    44,    31,     3,
       4,     5,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      43,    44,    -1,     3,     4,     5,    20,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    40,    27,    -1,    43,
      44,    31,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,     3,     4,     5,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    43,    44,    -1,    -1,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    44,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    -1,    -1,     3,     4,     5,    31,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    40,    -1,    -1,
      43,    44,    20,    -1,    -1,    -1,    -1,    25,    -1,    20,
      -1,    -1,    -1,    31,    25,    -1,    -1,     3,     4,     5,
      31,    39,    40,    -1,    -1,    43,    44,    -1,    39,    40,
      -1,    -1,    43,    44,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,     3,     4,     5,    31,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    40,    -1,    -1,    43,    44,    20,
      -1,    -1,    -1,    -1,    25,    -1,    27,    20,    -1,    -1,
      31,    -1,    25,    -1,    -1,     3,     4,     5,    31,    40,
      -1,    -1,    43,    44,    -1,    -1,    -1,    40,    -1,    -1,
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
      86,    18,    19,    20,    21,    22,    25,    31,     5,    25,
      57,    81,    83,    84,     5,    85,    86,    57,    31,     5,
      28,    31,    32,    53,    57,    78,    38,    74,    75,    85,
       5,     6,    18,    19,    20,    21,    22,    24,    25,    26,
      27,    29,    30,    31,    32,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    83,
      84,    87,    88,    89,    43,    44,    87,     0,    50,    19,
      20,    21,    22,    23,    39,    18,    25,    31,    25,    57,
      67,    18,    18,    18,    18,    27,    78,    39,    57,    58,
      82,    57,    19,    21,    26,    27,    29,    57,    58,    64,
      65,    66,    67,    25,    64,    32,    32,    42,     5,    41,
      42,    39,    43,    88,    44,    57,    57,    57,    57,    57,
      39,    57,    67,    27,    78,    57,    57,    67,    18,    29,
      36,    37,    57,    57,    57,    57,    27,    39,    58,    32,
      39,    32,     5,    83,    84,    86,     5,    81,    83,    26,
      58,    32,    34,    35,     5,    27,    79,    32,    57,    38,
      75,    57,    85,    86,     5,    27,    32,    27,    18,    18,
      18,    57,    18,    57,    58,    39,    39,    58,    26,    40,
      76,    34,    35,    76,    27,    42,    76,    38,    25,    57,
      57,    57,    57,    58,     5,    58,    39,     5,    50,    33,
      61,    62,    63,    65,    66,    76,     5,    61,    63,    76,
      27,    78,    25,    58,    27,    41,    31,    76,    62,    63,
      63,    27,    27,    78,    76,    64,    27,    32,    76
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
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    74,    74,    74,    75,    75,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89
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
       4,     3,     3,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     1,     0,     3,     3,     3,     3,     3,     2,
       3,     1,     3,     1,     1,     2,     1,     2,     4,     4,
       4,     3,     2,     2,     1,     5,     4,     4,     3,     2,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 1676 "y.tab.c"
    break;

  case 3:
#line 121 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1686 "y.tab.c"
    break;

  case 4:
#line 126 "gram.y"
      { (yyval.data) = NULL; }
#line 1692 "y.tab.c"
    break;

  case 5:
#line 130 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1700 "y.tab.c"
    break;

  case 6:
#line 133 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1708 "y.tab.c"
    break;

  case 7:
#line 136 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1716 "y.tab.c"
    break;

  case 8:
#line 139 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1724 "y.tab.c"
    break;

  case 9:
#line 142 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1732 "y.tab.c"
    break;

  case 10:
#line 145 "gram.y"
                       {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1740 "y.tab.c"
    break;

  case 11:
#line 148 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1748 "y.tab.c"
    break;

  case 12:
#line 151 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1756 "y.tab.c"
    break;

  case 13:
#line 154 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1764 "y.tab.c"
    break;

  case 14:
#line 157 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1772 "y.tab.c"
    break;

  case 15:
#line 160 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1780 "y.tab.c"
    break;

  case 16:
#line 164 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1788 "y.tab.c"
    break;

  case 17:
#line 166 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1796 "y.tab.c"
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
#line 1815 "y.tab.c"
    break;

  case 19:
#line 186 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1823 "y.tab.c"
    break;

  case 20:
#line 190 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1831 "y.tab.c"
    break;

  case 21:
#line 194 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1839 "y.tab.c"
    break;

  case 22:
#line 199 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1847 "y.tab.c"
    break;

  case 23:
#line 202 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1858 "y.tab.c"
    break;

  case 24:
#line 208 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1869 "y.tab.c"
    break;

  case 25:
#line 214 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1880 "y.tab.c"
    break;

  case 26:
#line 220 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1891 "y.tab.c"
    break;

  case 27:
#line 226 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1902 "y.tab.c"
    break;

  case 28:
#line 234 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1910 "y.tab.c"
    break;

  case 29:
#line 237 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1918 "y.tab.c"
    break;

  case 30:
#line 240 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1926 "y.tab.c"
    break;

  case 31:
#line 243 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1934 "y.tab.c"
    break;

  case 32:
#line 246 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1942 "y.tab.c"
    break;

  case 33:
#line 249 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1950 "y.tab.c"
    break;

  case 34:
#line 252 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1958 "y.tab.c"
    break;

  case 35:
#line 255 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1966 "y.tab.c"
    break;

  case 36:
#line 258 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1974 "y.tab.c"
    break;

  case 37:
#line 263 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1982 "y.tab.c"
    break;

  case 38:
#line 266 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1994 "y.tab.c"
    break;

  case 39:
#line 273 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2007 "y.tab.c"
    break;

  case 40:
#line 281 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2019 "y.tab.c"
    break;

  case 41:
#line 290 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2027 "y.tab.c"
    break;

  case 42:
#line 293 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2039 "y.tab.c"
    break;

  case 43:
#line 300 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2052 "y.tab.c"
    break;

  case 44:
#line 308 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2064 "y.tab.c"
    break;

  case 45:
#line 317 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2076 "y.tab.c"
    break;

  case 46:
#line 324 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2084 "y.tab.c"
    break;

  case 47:
#line 329 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2094 "y.tab.c"
    break;

  case 48:
#line 336 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2103 "y.tab.c"
    break;

  case 49:
#line 342 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2111 "y.tab.c"
    break;

  case 50:
#line 345 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2119 "y.tab.c"
    break;

  case 51:
#line 350 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2127 "y.tab.c"
    break;

  case 52:
#line 353 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2135 "y.tab.c"
    break;

  case 53:
#line 358 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2143 "y.tab.c"
    break;

  case 54:
#line 361 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2153 "y.tab.c"
    break;

  case 55:
#line 366 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2161 "y.tab.c"
    break;

  case 56:
#line 371 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2169 "y.tab.c"
    break;

  case 57:
#line 374 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2177 "y.tab.c"
    break;

  case 58:
#line 377 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2185 "y.tab.c"
    break;

  case 59:
#line 380 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2193 "y.tab.c"
    break;

  case 60:
#line 383 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2201 "y.tab.c"
    break;

  case 61:
#line 386 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2209 "y.tab.c"
    break;

  case 62:
#line 389 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2217 "y.tab.c"
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
#line 2257 "y.tab.c"
    break;

  case 64:
#line 430 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2265 "y.tab.c"
    break;

  case 65:
#line 433 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2273 "y.tab.c"
    break;

  case 66:
#line 438 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2281 "y.tab.c"
    break;

  case 67:
#line 441 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2289 "y.tab.c"
    break;

  case 68:
#line 446 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2298 "y.tab.c"
    break;

  case 69:
#line 450 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2307 "y.tab.c"
    break;

  case 70:
#line 454 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2316 "y.tab.c"
    break;

  case 71:
#line 458 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2325 "y.tab.c"
    break;

  case 72:
#line 464 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2335 "y.tab.c"
    break;

  case 73:
#line 469 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2347 "y.tab.c"
    break;

  case 74:
#line 476 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2359 "y.tab.c"
    break;

  case 75:
#line 483 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2371 "y.tab.c"
    break;

  case 76:
#line 490 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2383 "y.tab.c"
    break;

  case 77:
#line 497 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2393 "y.tab.c"
    break;

  case 78:
#line 502 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2401 "y.tab.c"
    break;

  case 79:
#line 505 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2409 "y.tab.c"
    break;

  case 80:
#line 510 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2417 "y.tab.c"
    break;

  case 81:
#line 515 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2429 "y.tab.c"
    break;

  case 82:
#line 522 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2437 "y.tab.c"
    break;

  case 83:
#line 525 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2445 "y.tab.c"
    break;

  case 84:
#line 530 "gram.y"
                                   {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2459 "y.tab.c"
    break;

  case 85:
#line 539 "gram.y"
                                        {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2473 "y.tab.c"
    break;

  case 86:
#line 550 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2481 "y.tab.c"
    break;

  case 87:
#line 555 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2490 "y.tab.c"
    break;

  case 88:
#line 560 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2499 "y.tab.c"
    break;

  case 89:
#line 564 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2507 "y.tab.c"
    break;

  case 90:
#line 569 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2516 "y.tab.c"
    break;

  case 91:
#line 573 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2524 "y.tab.c"
    break;

  case 92:
#line 578 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2534 "y.tab.c"
    break;

  case 93:
#line 583 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2543 "y.tab.c"
    break;

  case 94:
#line 589 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2551 "y.tab.c"
    break;

  case 95:
#line 592 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2560 "y.tab.c"
    break;

  case 96:
#line 596 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2568 "y.tab.c"
    break;

  case 97:
#line 599 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2577 "y.tab.c"
    break;

  case 98:
#line 605 "gram.y"
                           {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2588 "y.tab.c"
    break;

  case 99:
#line 611 "gram.y"
                         {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2599 "y.tab.c"
    break;

  case 100:
#line 617 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2607 "y.tab.c"
    break;

  case 101:
#line 622 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2615 "y.tab.c"
    break;

  case 102:
#line 625 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2623 "y.tab.c"
    break;

  case 103:
#line 628 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2631 "y.tab.c"
    break;

  case 104:
#line 631 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2639 "y.tab.c"
    break;

  case 105:
#line 634 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2647 "y.tab.c"
    break;

  case 106:
#line 637 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2655 "y.tab.c"
    break;

  case 107:
#line 640 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2663 "y.tab.c"
    break;

  case 108:
#line 643 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2671 "y.tab.c"
    break;

  case 109:
#line 646 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2679 "y.tab.c"
    break;

  case 110:
#line 652 "gram.y"
          {
      if ( strlen(yyval.id) >= 10 ) {
        (yyval.data) = newExpr_BigIntFromStr(yyval.id);
      } else {
        (yyval.data) = newExpr_Ival(atoi(yyval.id));
      }
    }
#line 2691 "y.tab.c"
    break;

  case 111:
#line 661 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2699 "y.tab.c"
    break;

  case 112:
#line 666 "gram.y"
                                     {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2710 "y.tab.c"
    break;

  case 113:
#line 672 "gram.y"
                             {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2721 "y.tab.c"
    break;

  case 114:
#line 678 "gram.y"
                                            {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2736 "y.tab.c"
    break;

  case 115:
#line 688 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        if ( d->type == EXPR_TYPE_IVAL ) {
          snprintf(buffer, sizeof(buffer), "%d", d->ival);
        } else if ( d->type == EXPR_TYPE_BIGINT ) {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *d->bigInt);
          snprintf(buffer, sizeof(buffer), "%s", c);
        }
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2759 "y.tab.c"
    break;

  case 116:
#line 706 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2770 "y.tab.c"
    break;

  case 117:
#line 712 "gram.y"
                                        {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2781 "y.tab.c"
    break;

  case 118:
#line 718 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2789 "y.tab.c"
    break;

  case 119:
#line 723 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2797 "y.tab.c"
    break;

  case 120:
#line 726 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2805 "y.tab.c"
    break;

  case 121:
#line 729 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2814 "y.tab.c"
    break;

  case 122:
#line 733 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2823 "y.tab.c"
    break;

  case 123:
#line 739 "gram.y"
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
#line 2856 "y.tab.c"
    break;

  case 124:
#line 767 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2864 "y.tab.c"
    break;

  case 125:
#line 772 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2872 "y.tab.c"
    break;

  case 126:
#line 775 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2884 "y.tab.c"
    break;

  case 127:
#line 782 "gram.y"
                       {
        char buffer[256];
        expr_t *d = (expr_t*)(yyvsp[0].data);
        if ( d->type == EXPR_TYPE_IVAL ) {
          snprintf(buffer, sizeof(buffer), "%d", d->ival);
        } else if ( d->type == EXPR_TYPE_BIGINT ) {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *d->bigInt);
          snprintf(buffer, sizeof(buffer), "%s", c);
        }
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2904 "y.tab.c"
    break;

  case 128:
#line 797 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2914 "y.tab.c"
    break;

  case 129:
#line 802 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2922 "y.tab.c"
    break;

  case 130:
#line 807 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2931 "y.tab.c"
    break;

  case 131:
#line 812 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2940 "y.tab.c"
    break;

  case 132:
#line 817 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2949 "y.tab.c"
    break;

  case 133:
#line 821 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2958 "y.tab.c"
    break;

  case 134:
#line 825 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2967 "y.tab.c"
    break;

  case 135:
#line 829 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2976 "y.tab.c"
    break;

  case 136:
#line 833 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2985 "y.tab.c"
    break;

  case 137:
#line 837 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2994 "y.tab.c"
    break;

  case 138:
#line 841 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3003 "y.tab.c"
    break;

  case 139:
#line 845 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3012 "y.tab.c"
    break;

  case 140:
#line 849 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3021 "y.tab.c"
    break;

  case 141:
#line 853 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3030 "y.tab.c"
    break;

  case 142:
#line 857 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3039 "y.tab.c"
    break;

  case 143:
#line 861 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3048 "y.tab.c"
    break;

  case 144:
#line 865 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3057 "y.tab.c"
    break;

  case 145:
#line 869 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3066 "y.tab.c"
    break;

  case 146:
#line 873 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3075 "y.tab.c"
    break;

  case 147:
#line 877 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3084 "y.tab.c"
    break;

  case 148:
#line 881 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3093 "y.tab.c"
    break;

  case 149:
#line 885 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3102 "y.tab.c"
    break;

  case 150:
#line 889 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3111 "y.tab.c"
    break;

  case 151:
#line 893 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3120 "y.tab.c"
    break;

  case 152:
#line 897 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3129 "y.tab.c"
    break;

  case 153:
#line 901 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3138 "y.tab.c"
    break;

  case 154:
#line 905 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3147 "y.tab.c"
    break;

  case 155:
#line 909 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3156 "y.tab.c"
    break;

  case 156:
#line 913 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3165 "y.tab.c"
    break;


#line 3169 "y.tab.c"

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
#line 918 "gram.y"


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
