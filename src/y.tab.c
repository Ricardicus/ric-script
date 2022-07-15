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
    FOREACH = 262,
    COMMENT = 263,
    NEWLINE = 264,
    KEY_FLOAT = 265,
    KEY_INT = 266,
    KEY_STR = 267,
    KEY_STRUCT = 268,
    KEY_PROCESS = 269,
    WHITESPACE = 270,
    OPEN = 271,
    CLOSE = 272,
    OTHER = 273
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
#define KEY_FLOAT 265
#define KEY_INT 266
#define KEY_STR 267
#define KEY_STRUCT 268
#define KEY_PROCESS 269
#define WHITESPACE 270
#define OPEN 271
#define CLOSE 272
#define OTHER 273

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "gram.y"
 int val_int; double val_double; char id[256]; void *data; 

#line 199 "y.tab.c"

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
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

#define YYUNDEFTOK  2
#define YYMAXUTOK   273


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
       2,     2,    46,    30,    45,     2,    25,    24,    36,    44,
      27,    28,    22,    20,    43,    21,    26,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    39,
      37,    19,    38,    31,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,    47,    33,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    35,    42,    34,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   122,   127,   131,   134,   137,   140,   143,
     146,   149,   152,   155,   158,   161,   165,   167,   172,   177,
     181,   185,   189,   194,   197,   203,   209,   215,   221,   229,
     232,   235,   238,   241,   244,   247,   250,   253,   258,   261,
     268,   276,   285,   288,   295,   303,   312,   319,   324,   331,
     337,   340,   345,   348,   353,   356,   361,   366,   369,   372,
     375,   378,   381,   384,   388,   422,   425,   430,   433,   438,
     442,   446,   452,   464,   468,   474,   479,   486,   493,   500,
     507,   513,   519,   525,   531,   536,   539,   544,   549,   556,
     559,   564,   575,   580,   585,   589,   594,   598,   603,   608,
     614,   617,   621,   624,   630,   636,   642,   647,   650,   653,
     656,   659,   662,   665,   668,   671,   676,   685,   690,   693,
     696,   700,   706,   734,   739,   742,   749,   764,   769,   774,
     779,   784,   789,   793,   797,   801,   805,   809,   813,   817,
     821,   825,   829,   833,   837,   841,   845,   849,   853,   857,
     861,   865,   869,   873,   877,   881,   885
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "FOREACH", "COMMENT", "NEWLINE", "KEY_FLOAT", "KEY_INT", "KEY_STR",
  "KEY_STRUCT", "KEY_PROCESS", "WHITESPACE", "OPEN", "CLOSE", "OTHER",
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'$'", "'.'", "'('", "')'",
  "'@'", "'!'", "'?'", "'['", "']'", "'~'", "'|'", "'&'", "'<'", "'>'",
  "';'", "':'", "'{'", "'}'", "','", "'\\''", "'\"'", "' '", "'\\\\'",
  "'^'", "$accept", "program", "statements", "statement",
  "systemStatement", "forEachStatementFull", "forEachStatement",
  "returnStatement", "continueStatement", "breakStatement", "expressions",
  "expression", "ifStatement", "loopStatement", "middleIfs", "middleIf",
  "endIf", "logical_a", "logical_b", "logical_expression", "condition",
  "class", "function", "classFunctionCall", "functionCall", "declaration",
  "dictionary", "dictionary_keys_vals", "dictionary_key_val", "body",
  "vector", "arguments_list", "parameters_list", "mathContent",
  "indexedVector", "indexer", "mathContentDigit", "mathContentDouble",
  "stringContent", "stringEditions", "stringEdition", "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    61,
      43,    45,    42,    47,    37,    36,    46,    40,    41,    64,
      33,    63,    91,    93,   126,   124,    38,    60,    62,    59,
      58,   123,   125,    44,    39,    34,    32,    92,    94
};
# endif

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     418,  -231,  -231,   269,   607,   155,     6,    42,   607,    34,
      17,    10,    62,    48,   123,   234,   280,    52,  -231,   418,
    -231,  -231,  -231,  -231,  -231,   360,    13,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   190,  -231,  -231,
    -231,   632,    54,    72,    85,    90,   135,   116,   176,   360,
      43,  -231,  -231,  -231,  -231,   607,    27,  -231,   314,   109,
    -231,    27,   607,  -231,   113,   360,   -17,   147,   191,  -231,
     134,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,   108,  -231,  -231,  -231,
    -231,  -231,  -231,   326,  -231,  -231,  -231,   131,   372,  -231,
    -231,   607,   607,   607,   607,   607,   433,   156,   632,   180,
     189,   201,   231,   448,   607,   632,   666,  -231,   607,   607,
     607,   607,   217,  -231,    -5,    78,   607,   666,   196,    -6,
     215,  -231,  -231,  -231,     9,   159,    56,  -231,  -231,   607,
     213,  -231,   123,   607,   108,  -231,   131,   166,   166,  -231,
    -231,  -231,   463,   142,   101,   235,   288,   666,  -231,   607,
     607,   607,   607,  -231,    -3,   225,   163,   266,   278,   279,
     478,   497,   360,   360,   360,   360,   522,  -231,   299,    13,
     268,   304,   305,  -231,   268,    21,   268,   360,   275,  -231,
     360,   607,   107,  -231,   530,  -231,   313,   360,   360,   360,
     360,  -231,  -231,  -231,   607,   607,   607,   360,   607,   360,
    -231,    53,   315,   418,   310,    27,    27,  -231,   268,   345,
     310,   268,    13,   555,   639,   110,   576,   360,   360,   360,
     360,  -231,   268,   318,    94,   310,  -231,  -231,   215,  -231,
    -231,  -231,   310,  -231,  -231,    13,   216,    13,   555,  -231,
      89,  -231,  -231,    27,  -231,  -231,  -231,  -231,   586,    13,
    -231,   186,  -231,    95,   268,  -231,  -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   116,   117,    36,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,    90,     0,     0,     0,     2,     4,
      14,     7,    13,    11,    12,     8,    23,     9,    10,    15,
       6,    34,    33,     5,    31,    32,    30,    29,   102,   100,
      35,     0,     0,     0,     0,     0,     0,     0,    36,    20,
      29,   103,   101,    16,    17,     0,     0,    18,     0,     0,
      22,     0,     0,    95,     0,    97,     0,     0,     0,    89,
       0,   124,   127,   128,   156,   130,   135,   149,   136,   151,
     146,   140,   141,   142,   132,   147,   148,   153,   152,   133,
     134,   139,   138,   154,   155,   143,   121,   145,   131,   137,
     150,   126,   125,     0,   123,   129,   144,   120,     0,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    84,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,    23,     0,
      51,    53,    54,    37,     0,     0,     0,    94,    93,     0,
       0,    87,     0,     0,   118,   122,   119,    24,    26,    25,
      28,    27,   110,     0,    23,     0,     0,    85,    86,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,     0,    69,     0,    55,
       0,     0,     0,    99,     0,     0,     0,    96,     0,    88,
      91,   115,   108,   104,   109,   105,     0,    80,    81,    82,
      83,    73,   106,    63,     0,     0,     0,    61,     0,    62,
      71,     0,     0,     4,    42,     0,     0,    66,     0,     0,
      38,     0,   114,     0,     0,   107,     0,    57,    58,    59,
      60,    72,     0,     0,     0,    43,    47,    45,    50,    52,
      65,    98,    39,    41,    64,   112,    36,   113,     0,    68,
       0,    19,    92,     0,    49,    46,    44,    40,     0,   111,
      67,     0,    68,     0,     0,    67,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,   -16,  -231,  -231,  -231,   343,  -231,  -231,  -231,
       0,   -28,  -231,  -231,   157,  -230,  -209,   -59,   160,   162,
     -32,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   237,  -184,
    -231,   -41,  -231,  -231,     1,  -231,     2,    19,    -1,   370,
     -11,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    57,    22,    23,    24,
      65,    26,    27,    28,   245,   246,   247,   139,   140,   141,
     142,    29,    30,    31,    32,    33,    34,    68,    69,   224,
      35,    66,   195,    36,    50,   165,    38,    39,    40,   103,
     104,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,   145,   110,    49,    54,   134,    51,    58,   127,
     227,    53,   230,    70,   193,   265,   148,   101,   101,    25,
      37,   253,   265,   187,    52,   211,   149,   190,   138,   191,
       1,     2,    48,   138,   102,   102,   266,   194,   149,    59,
     149,   126,    61,   267,   250,   116,    60,   254,     5,   228,
      15,    16,   109,   117,   125,   135,   137,   136,   261,    12,
     264,   137,   146,   188,   229,     1,     2,    48,    14,    55,
     123,    15,    16,   128,    56,   124,   111,   112,   113,   114,
     115,   241,   174,     5,   143,   188,   168,    67,   164,    62,
     276,   129,   155,   177,    12,    63,   149,   155,   111,   112,
     113,   114,   115,    14,   130,   101,    15,    16,   189,   131,
     101,   157,   158,   159,   160,   161,   163,   270,   167,     1,
       2,    48,   102,   275,   175,   176,   263,   102,   182,   183,
     184,   185,   149,   116,   202,   223,   144,     5,   149,   116,
     132,   204,   116,     8,   133,   221,   147,   233,    12,   197,
     258,    70,   150,   200,  -144,  -144,  -144,    14,     1,     2,
      15,    16,   111,   112,   113,   114,   115,    15,    16,   207,
     208,   209,   210,   232,   153,   203,   235,  -145,  -145,  -145,
     217,   219,   178,   111,   112,   113,   114,   115,   113,   114,
     115,   143,   196,   179,   191,   260,   166,   138,   138,   169,
     180,   181,    46,    47,   271,   255,   257,   243,   170,   118,
     119,   120,   121,   122,   237,   238,   239,   123,   240,   274,
     171,   191,   124,    25,    37,   137,   137,   273,   116,   -56,
     269,   -56,   -56,   151,   152,   138,   117,     1,     2,    71,
      72,    73,    46,   268,   186,   111,   112,   113,   114,   115,
     172,   192,   198,    74,    75,    76,    77,    78,   212,    79,
      80,    81,    82,   137,    83,    84,    85,    86,   205,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     1,     2,    71,    72,    73,    41,    42,
      43,    44,    45,   206,   213,    46,    47,   214,   215,    74,
      75,    76,    77,    78,   222,    79,    80,    81,    82,   223,
      83,    84,    85,    86,   231,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   106,   107,    98,    99,   100,     1,
       2,    71,    72,    73,   111,   112,   113,   114,   115,   225,
     236,   226,   143,   242,   244,    74,    75,    76,    77,    78,
     251,    79,    80,    81,    82,    64,    83,    84,    85,    86,
     262,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     154,    97,    98,    99,   100,     1,     2,    71,    72,    73,
     111,   112,   113,   114,   115,   248,   108,   252,   249,   199,
       0,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,     0,    83,    84,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   106,   156,    98,    99,
     100,     1,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,    48,     5,
       0,     0,     0,     6,     7,     8,     0,     9,    10,    11,
      12,     1,     2,    48,     5,     0,     0,    13,     0,    14,
       8,     0,    15,    16,     0,    12,     1,     2,    48,     5,
       0,     0,     0,   162,    14,     8,   173,    15,    16,     0,
      12,     1,     2,    48,     5,     0,     0,     0,     0,    14,
       8,     0,    15,    16,     0,    12,     0,   216,     0,     5,
       1,     2,    48,   201,    14,     8,     0,    15,    16,     0,
      12,     0,     0,     0,     0,     0,   218,     0,     5,    14,
       0,     0,    15,    16,     8,     1,     2,    48,     0,    12,
       0,     0,     0,     1,     2,    48,     0,     0,    14,     0,
       0,    15,    16,     5,     0,     0,     0,     0,     0,     8,
     220,     5,     0,     0,    12,     0,     0,     8,     1,     2,
      48,     0,    12,    14,     0,     0,    15,    16,     0,     0,
     234,    14,     0,     0,    15,    16,     5,     0,     0,     1,
       2,    48,     8,     0,     0,     0,     0,    12,     0,     1,
       2,    48,     0,     0,     0,   166,    14,     5,     0,    15,
      16,     0,     0,     8,   259,     0,     0,     5,    12,     0,
       1,     2,    48,     8,   272,     0,     0,    14,    12,     0,
      15,    16,     0,     0,     0,     0,     0,    14,     5,     0,
      15,    16,     0,     0,     8,     1,     2,    48,     0,    12,
       0,     0,     1,     2,   256,     0,     0,     0,    14,     0,
       0,    15,    16,     5,     0,     0,     0,     0,     0,   125,
       5,     0,     0,     0,    12,     0,     8,     0,     0,     0,
       0,    12,     0,    14,     0,     0,    15,    16,     0,     0,
      14,     0,     0,    15,    16,   178,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,   180,   181
};

static const yytype_int16 yycheck[] =
{
       0,     0,    61,    19,     4,     6,    47,     5,     8,    41,
     194,     5,   196,    14,     5,   245,    33,    15,    16,    19,
      19,   230,   252,    28,     5,    28,    43,    33,    56,    35,
       3,     4,     5,    61,    15,    16,   245,    28,    43,     5,
      43,    41,    32,   252,   228,    32,    29,   231,    21,    28,
      44,    45,     0,    40,    27,    55,    56,    30,   242,    32,
     244,    61,    62,     7,    43,     3,     4,     5,    41,    27,
      27,    44,    45,    19,    32,    32,    20,    21,    22,    23,
      24,    28,   123,    21,    28,     7,   118,    39,   116,    27,
     274,    19,   103,   125,    32,    33,    43,   108,    20,    21,
      22,    23,    24,    41,    19,   103,    44,    45,   136,    19,
     108,   111,   112,   113,   114,   115,   116,    28,   118,     3,
       4,     5,   103,    28,   124,   125,    32,   108,   128,   129,
     130,   131,    43,    32,   162,    41,    27,    21,    43,    32,
       5,    40,    32,    27,    28,   186,    33,    40,    32,   149,
      40,   152,     5,   153,    46,    47,    48,    41,     3,     4,
      44,    45,    20,    21,    22,    23,    24,    44,    45,   169,
     170,   171,   172,   201,    40,    33,   204,    46,    47,    48,
     180,   181,    19,    20,    21,    22,    23,    24,    22,    23,
      24,    28,    33,    30,    35,   236,    40,   225,   226,    19,
      37,    38,    26,    27,   263,   233,   234,   223,    19,    19,
      20,    21,    22,    23,   214,   215,   216,    27,   218,    33,
      19,    35,    32,   223,   223,   225,   226,   268,    32,    33,
     258,    35,    36,    42,    43,   263,    40,     3,     4,     5,
       6,     7,    26,    27,    27,    20,    21,    22,    23,    24,
      19,    36,    39,    19,    20,    21,    22,    23,    33,    25,
      26,    27,    28,   263,    30,    31,    32,    33,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     3,     4,     5,     6,     7,    19,    20,
      21,    22,    23,     5,    28,    26,    27,    19,    19,    19,
      20,    21,    22,    23,     5,    25,    26,    27,    28,    41,
      30,    31,    32,    33,    39,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     3,
       4,     5,     6,     7,    20,    21,    22,    23,    24,    35,
      27,    36,    28,    28,    34,    19,    20,    21,    22,    23,
       5,    25,    26,    27,    28,    12,    30,    31,    32,    33,
      42,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,     4,     5,     6,     7,
      20,    21,    22,    23,    24,   225,    16,   230,   226,   152,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    21,
      -1,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,     3,     4,     5,    21,    -1,    -1,    39,    -1,    41,
      27,    -1,    44,    45,    -1,    32,     3,     4,     5,    21,
      -1,    -1,    -1,    40,    41,    27,    28,    44,    45,    -1,
      32,     3,     4,     5,    21,    -1,    -1,    -1,    -1,    41,
      27,    -1,    44,    45,    -1,    32,    -1,    19,    -1,    21,
       3,     4,     5,    40,    41,    27,    -1,    44,    45,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    41,
      -1,    -1,    44,    45,    27,     3,     4,     5,    -1,    32,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    41,    -1,
      -1,    44,    45,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    21,    -1,    -1,    32,    -1,    -1,    27,     3,     4,
       5,    -1,    32,    41,    -1,    -1,    44,    45,    -1,    -1,
      40,    41,    -1,    -1,    44,    45,    21,    -1,    -1,     3,
       4,     5,    27,    -1,    -1,    -1,    -1,    32,    -1,     3,
       4,     5,    -1,    -1,    -1,    40,    41,    21,    -1,    44,
      45,    -1,    -1,    27,    28,    -1,    -1,    21,    32,    -1,
       3,     4,     5,    27,    28,    -1,    -1,    41,    32,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    41,    21,    -1,
      44,    45,    -1,    -1,    27,     3,     4,     5,    -1,    32,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    41,    -1,
      -1,    44,    45,    21,    -1,    -1,    -1,    -1,    -1,    27,
      21,    -1,    -1,    -1,    32,    -1,    27,    -1,    -1,    -1,
      -1,    32,    -1,    41,    -1,    -1,    44,    45,    -1,    -1,
      41,    -1,    -1,    44,    45,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    25,    26,    27,    29,
      30,    31,    32,    39,    41,    44,    45,    50,    51,    52,
      53,    54,    56,    57,    58,    59,    60,    61,    62,    70,
      71,    72,    73,    74,    75,    79,    82,    83,    85,    86,
      87,    19,    20,    21,    22,    23,    26,    27,     5,    59,
      83,    85,    86,     5,    87,    27,    32,    55,    59,     5,
      29,    32,    27,    33,    55,    59,    80,    39,    76,    77,
      87,     5,     6,     7,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    30,    31,    32,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    85,    86,    88,    89,    90,    44,    45,    88,     0,
      51,    20,    21,    22,    23,    24,    32,    40,    19,    20,
      21,    22,    23,    27,    32,    27,    59,    69,    19,    19,
      19,    19,     5,    28,    80,    59,    30,    59,    60,    66,
      67,    68,    69,    28,    27,    66,    59,    33,    33,    43,
       5,    42,    43,    40,    44,    89,    45,    59,    59,    59,
      59,    59,    40,    59,    60,    84,    40,    59,    69,    19,
      19,    19,    19,    28,    80,    59,    59,    69,    19,    30,
      37,    38,    59,    59,    59,    59,    27,    28,     7,    60,
      33,    35,    36,     5,    28,    81,    33,    59,    39,    77,
      59,    40,    60,    33,    40,    33,     5,    59,    59,    59,
      59,    28,    33,    28,    19,    19,    19,    59,    19,    59,
      28,    80,     5,    41,    78,    35,    36,    78,    28,    43,
      78,    39,    60,    40,    40,    60,    27,    59,    59,    59,
      59,    28,    28,    51,    34,    63,    64,    65,    67,    68,
      78,     5,    63,    65,    78,    60,     5,    60,    40,    28,
      80,    78,    42,    32,    78,    64,    65,    65,    27,    60,
      28,    66,    28,    80,    33,    28,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    65,
      66,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    76,
      76,    77,    78,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    86,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     6,
       2,     1,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     6,
       7,     6,     5,     6,     7,     6,     2,     1,     5,     2,
       4,     1,     4,     1,     1,     2,     1,     4,     4,     4,
       4,     3,     3,     3,     6,     6,     5,     7,     6,     4,
       3,     5,     6,     4,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     3,     3,     3,     3,     1,
       0,     3,     3,     3,     3,     2,     3,     1,     3,     1,
       1,     2,     1,     2,     4,     4,     4,     3,     2,     2,
       1,     5,     4,     4,     3,     2,     1,     1,     3,     3,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
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
#line 105 "gram.y"
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
#line 1669 "y.tab.c"
    break;

  case 3:
#line 122 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1679 "y.tab.c"
    break;

  case 4:
#line 127 "gram.y"
      { (yyval.data) = NULL; }
#line 1685 "y.tab.c"
    break;

  case 5:
#line 131 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1693 "y.tab.c"
    break;

  case 6:
#line 134 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1701 "y.tab.c"
    break;

  case 7:
#line 137 "gram.y"
                           {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1709 "y.tab.c"
    break;

  case 8:
#line 140 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1717 "y.tab.c"
    break;

  case 9:
#line 143 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1725 "y.tab.c"
    break;

  case 10:
#line 146 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1733 "y.tab.c"
    break;

  case 11:
#line 149 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1741 "y.tab.c"
    break;

  case 12:
#line 152 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1749 "y.tab.c"
    break;

  case 13:
#line 155 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1757 "y.tab.c"
    break;

  case 14:
#line 158 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1765 "y.tab.c"
    break;

  case 15:
#line 161 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1773 "y.tab.c"
    break;

  case 16:
#line 165 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1781 "y.tab.c"
    break;

  case 17:
#line 167 "gram.y"
                      {
    (yyval.data) = (yyvsp[0].data);
}
#line 1789 "y.tab.c"
    break;

  case 18:
#line 172 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1797 "y.tab.c"
    break;

  case 19:
#line 177 "gram.y"
                                        {
    (yyval.data) = newForEach((yyvsp[-4].data), (yyvsp[-2].id), (yyvsp[0].data));
}
#line 1805 "y.tab.c"
    break;

  case 20:
#line 181 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1813 "y.tab.c"
    break;

  case 21:
#line 185 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1821 "y.tab.c"
    break;

  case 22:
#line 189 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1829 "y.tab.c"
    break;

  case 23:
#line 194 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1837 "y.tab.c"
    break;

  case 24:
#line 197 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1848 "y.tab.c"
    break;

  case 25:
#line 203 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1859 "y.tab.c"
    break;

  case 26:
#line 209 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1870 "y.tab.c"
    break;

  case 27:
#line 215 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1881 "y.tab.c"
    break;

  case 28:
#line 221 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1892 "y.tab.c"
    break;

  case 29:
#line 229 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1900 "y.tab.c"
    break;

  case 30:
#line 232 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1908 "y.tab.c"
    break;

  case 31:
#line 235 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1916 "y.tab.c"
    break;

  case 32:
#line 238 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1924 "y.tab.c"
    break;

  case 33:
#line 241 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1932 "y.tab.c"
    break;

  case 34:
#line 244 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1940 "y.tab.c"
    break;

  case 35:
#line 247 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1948 "y.tab.c"
    break;

  case 36:
#line 250 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1956 "y.tab.c"
    break;

  case 37:
#line 253 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1964 "y.tab.c"
    break;

  case 38:
#line 258 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1972 "y.tab.c"
    break;

  case 39:
#line 261 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1984 "y.tab.c"
    break;

  case 40:
#line 268 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1997 "y.tab.c"
    break;

  case 41:
#line 276 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2009 "y.tab.c"
    break;

  case 42:
#line 285 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2017 "y.tab.c"
    break;

  case 43:
#line 288 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2029 "y.tab.c"
    break;

  case 44:
#line 295 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2042 "y.tab.c"
    break;

  case 45:
#line 303 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2054 "y.tab.c"
    break;

  case 46:
#line 312 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2066 "y.tab.c"
    break;

  case 47:
#line 319 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2074 "y.tab.c"
    break;

  case 48:
#line 324 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2084 "y.tab.c"
    break;

  case 49:
#line 331 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2093 "y.tab.c"
    break;

  case 50:
#line 337 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2101 "y.tab.c"
    break;

  case 51:
#line 340 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2109 "y.tab.c"
    break;

  case 52:
#line 345 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2117 "y.tab.c"
    break;

  case 53:
#line 348 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2125 "y.tab.c"
    break;

  case 54:
#line 353 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2133 "y.tab.c"
    break;

  case 55:
#line 356 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2143 "y.tab.c"
    break;

  case 56:
#line 361 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2151 "y.tab.c"
    break;

  case 57:
#line 366 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2159 "y.tab.c"
    break;

  case 58:
#line 369 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2167 "y.tab.c"
    break;

  case 59:
#line 372 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2175 "y.tab.c"
    break;

  case 60:
#line 375 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2183 "y.tab.c"
    break;

  case 61:
#line 378 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2191 "y.tab.c"
    break;

  case 62:
#line 381 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2199 "y.tab.c"
    break;

  case 63:
#line 384 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2207 "y.tab.c"
    break;

  case 64:
#line 388 "gram.y"
                               {
    /* Only declarations allowed */
    body_t *bod = (yyvsp[0].data);
    statement_t *walk = bod->content;
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
    (yyval.data) = newClass((yyvsp[-3].id), bod);
}
#line 2244 "y.tab.c"
    break;

  case 65:
#line 422 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2252 "y.tab.c"
    break;

  case 66:
#line 425 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2260 "y.tab.c"
    break;

  case 67:
#line 430 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2268 "y.tab.c"
    break;

  case 68:
#line 433 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2276 "y.tab.c"
    break;

  case 69:
#line 438 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2285 "y.tab.c"
    break;

  case 70:
#line 442 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2294 "y.tab.c"
    break;

  case 71:
#line 446 "gram.y"
                        {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        expr_t *expr = newExpr_ID((yyvsp[-4].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
#line 2305 "y.tab.c"
    break;

  case 72:
#line 452 "gram.y"
                                       {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *expr = newExpr_ID((yyvsp[-5].id));
        argsList_t *args = newArgument(expr, NULL);
        argsList_t *walk = (yyvsp[-1].data);
        walk->length += 1;
        while ( walk->next != NULL ) {
          walk = walk->next;
        }
        walk->next = args;
        (yyval.data) = newFunCall(id, (yyvsp[-1].data));
    }
#line 2322 "y.tab.c"
    break;

  case 73:
#line 464 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2331 "y.tab.c"
    break;

  case 74:
#line 468 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2340 "y.tab.c"
    break;

  case 75:
#line 474 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2350 "y.tab.c"
    break;

  case 76:
#line 479 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2362 "y.tab.c"
    break;

  case 77:
#line 486 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2374 "y.tab.c"
    break;

  case 78:
#line 493 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2386 "y.tab.c"
    break;

  case 79:
#line 500 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2398 "y.tab.c"
    break;

  case 80:
#line 507 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2409 "y.tab.c"
    break;

  case 81:
#line 513 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2420 "y.tab.c"
    break;

  case 82:
#line 519 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2431 "y.tab.c"
    break;

  case 83:
#line 525 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2442 "y.tab.c"
    break;

  case 84:
#line 531 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2452 "y.tab.c"
    break;

  case 85:
#line 536 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2460 "y.tab.c"
    break;

  case 86:
#line 539 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2468 "y.tab.c"
    break;

  case 87:
#line 544 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2476 "y.tab.c"
    break;

  case 88:
#line 549 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2488 "y.tab.c"
    break;

  case 89:
#line 556 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2496 "y.tab.c"
    break;

  case 90:
#line 559 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2504 "y.tab.c"
    break;

  case 91:
#line 564 "gram.y"
                                  {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2518 "y.tab.c"
    break;

  case 92:
#line 575 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2526 "y.tab.c"
    break;

  case 93:
#line 580 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2535 "y.tab.c"
    break;

  case 94:
#line 585 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2544 "y.tab.c"
    break;

  case 95:
#line 589 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2552 "y.tab.c"
    break;

  case 96:
#line 594 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2561 "y.tab.c"
    break;

  case 97:
#line 598 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2569 "y.tab.c"
    break;

  case 98:
#line 603 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2579 "y.tab.c"
    break;

  case 99:
#line 608 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2588 "y.tab.c"
    break;

  case 100:
#line 614 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2596 "y.tab.c"
    break;

  case 101:
#line 617 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2605 "y.tab.c"
    break;

  case 102:
#line 621 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2613 "y.tab.c"
    break;

  case 103:
#line 624 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2622 "y.tab.c"
    break;

  case 104:
#line 630 "gram.y"
                                   {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2633 "y.tab.c"
    break;

  case 105:
#line 636 "gram.y"
                                 {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2644 "y.tab.c"
    break;

  case 106:
#line 642 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2652 "y.tab.c"
    break;

  case 107:
#line 647 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2660 "y.tab.c"
    break;

  case 108:
#line 650 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2668 "y.tab.c"
    break;

  case 109:
#line 653 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2676 "y.tab.c"
    break;

  case 110:
#line 656 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2684 "y.tab.c"
    break;

  case 111:
#line 659 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2692 "y.tab.c"
    break;

  case 112:
#line 662 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2700 "y.tab.c"
    break;

  case 113:
#line 665 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2708 "y.tab.c"
    break;

  case 114:
#line 668 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2716 "y.tab.c"
    break;

  case 115:
#line 671 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2724 "y.tab.c"
    break;

  case 116:
#line 676 "gram.y"
          {
      if ( strlen(yyval.id) >= 10 ) {
        (yyval.data) = newExpr_BigIntFromStr(yyval.id);
      } else {
        (yyval.data) = newExpr_Ival(atoi(yyval.id));
      }
    }
#line 2736 "y.tab.c"
    break;

  case 117:
#line 685 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2744 "y.tab.c"
    break;

  case 118:
#line 690 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2752 "y.tab.c"
    break;

  case 119:
#line 693 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2760 "y.tab.c"
    break;

  case 120:
#line 696 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2769 "y.tab.c"
    break;

  case 121:
#line 700 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2778 "y.tab.c"
    break;

  case 122:
#line 706 "gram.y"
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
#line 2811 "y.tab.c"
    break;

  case 123:
#line 734 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2819 "y.tab.c"
    break;

  case 124:
#line 739 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2827 "y.tab.c"
    break;

  case 125:
#line 742 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2839 "y.tab.c"
    break;

  case 126:
#line 749 "gram.y"
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
#line 2859 "y.tab.c"
    break;

  case 127:
#line 764 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2869 "y.tab.c"
    break;

  case 128:
#line 769 "gram.y"
              {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2879 "y.tab.c"
    break;

  case 129:
#line 774 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2887 "y.tab.c"
    break;

  case 130:
#line 779 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2896 "y.tab.c"
    break;

  case 131:
#line 784 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2905 "y.tab.c"
    break;

  case 132:
#line 789 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2914 "y.tab.c"
    break;

  case 133:
#line 793 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2923 "y.tab.c"
    break;

  case 134:
#line 797 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2932 "y.tab.c"
    break;

  case 135:
#line 801 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2941 "y.tab.c"
    break;

  case 136:
#line 805 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2950 "y.tab.c"
    break;

  case 137:
#line 809 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2959 "y.tab.c"
    break;

  case 138:
#line 813 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2968 "y.tab.c"
    break;

  case 139:
#line 817 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2977 "y.tab.c"
    break;

  case 140:
#line 821 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2986 "y.tab.c"
    break;

  case 141:
#line 825 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2995 "y.tab.c"
    break;

  case 142:
#line 829 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3004 "y.tab.c"
    break;

  case 143:
#line 833 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3013 "y.tab.c"
    break;

  case 144:
#line 837 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3022 "y.tab.c"
    break;

  case 145:
#line 841 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3031 "y.tab.c"
    break;

  case 146:
#line 845 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3040 "y.tab.c"
    break;

  case 147:
#line 849 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3049 "y.tab.c"
    break;

  case 148:
#line 853 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3058 "y.tab.c"
    break;

  case 149:
#line 857 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3067 "y.tab.c"
    break;

  case 150:
#line 861 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3076 "y.tab.c"
    break;

  case 151:
#line 865 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3085 "y.tab.c"
    break;

  case 152:
#line 869 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3094 "y.tab.c"
    break;

  case 153:
#line 873 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3103 "y.tab.c"
    break;

  case 154:
#line 877 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3112 "y.tab.c"
    break;

  case 155:
#line 881 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3121 "y.tab.c"
    break;

  case 156:
#line 885 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3130 "y.tab.c"
    break;


#line 3134 "y.tab.c"

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
#line 890 "gram.y"


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

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, const char *prompt) {
    char lineBuffer[256];

    ParsedFile = "stdin";

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    printf("%s", prompt);
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

        printf("%s", prompt);
        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}


void runCommand(int argc, char *argv[], interactiveInterpreterFunc func, char *command) {
    YY_BUFFER_STATE buffer;
    ParsedFile = "stdin";

    /* Parse from provided command line */
    buffer = yy_scan_string(command);
    yyparse();
    yy_delete_buffer(buffer);

    if ( root != NULL ) {
        func(argc, argv, root, 0);
    }
}
