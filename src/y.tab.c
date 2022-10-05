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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "gram.y"
 int val_int; double val_double; char id[256]; void *data; 

#line 181 "y.tab.c"

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
#define YYFINAL  112
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   712

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  280

#define YYUNDEFTOK  2
#define YYMAXUTOK   264


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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   114,   119,   123,   126,   129,   132,   135,
     138,   141,   144,   147,   150,   153,   157,   159,   164,   169,
     173,   177,   181,   186,   189,   195,   201,   207,   213,   221,
     224,   227,   230,   233,   236,   239,   242,   245,   250,   255,
     258,   265,   273,   282,   285,   292,   300,   309,   316,   321,
     328,   334,   337,   342,   345,   350,   353,   358,   363,   366,
     369,   372,   375,   378,   381,   385,   419,   422,   427,   430,
     433,   439,   443,   447,   450,   454,   460,   466,   480,   485,
     492,   499,   506,   513,   519,   525,   531,   537,   542,   545,
     550,   555,   562,   565,   570,   581,   586,   591,   595,   600,
     604,   609,   614,   620,   623,   627,   630,   636,   642,   648,
     653,   656,   659,   662,   665,   668,   671,   674,   677,   682,
     695,   700,   703,   706,   710,   716,   744,   749,   752,   759,
     776,   781,   786,   791,   796,   801,   805,   809,   813,   817,
     821,   825,   829,   833,   837,   841,   845,   849,   853,   857,
     861,   865,   869,   873,   877,   881,   885,   889,   893,   897,
     901
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "DOUBLE", "ID", "RETURN",
  "FOREACH", "COMMENT", "NEWLINE", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'$'", "'.'", "'('", "')'", "'@'", "'!'", "'?'", "'['", "']'",
  "'~'", "'|'", "'&'", "'<'", "'>'", "';'", "':'", "'{'", "'}'", "','",
  "'\\''", "'\"'", "' '", "'\\\\'", "'^'", "'_'", "$accept", "program",
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
  "stringEditions", "stringEdition", "otherChar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,    43,    45,    42,    47,    37,    36,    46,    40,    41,
      64,    33,    63,    91,    93,   126,   124,    38,    60,    62,
      59,    58,   123,   125,    44,    39,    34,    32,    92,    94,
      95
};
# endif

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-149)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,  -228,  -228,   675,   612,   119,     5,    88,   612,     8,
      24,    -7,   164,    38,    53,   241,   279,    50,  -228,    49,
    -228,  -228,  -228,  -228,  -228,   697,    20,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,    84,  -228,
    -228,  -228,   622,    46,    64,   103,   110,   121,   393,    92,
     697,   117,  -228,  -228,  -228,  -228,  -228,   612,   403,  -228,
     683,   124,  -228,   403,   612,  -228,   113,   697,   -12,   165,
     132,  -228,   140,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   152,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,   317,  -228,  -228,  -228,
     176,   355,  -228,  -228,   612,   612,   612,   612,   612,   428,
     147,   622,   175,   184,   185,   187,   438,   612,   622,   389,
    -228,   612,   612,   612,   612,   168,  -228,    -8,   692,   612,
     389,    77,   131,   171,  -228,  -228,  -228,    18,   136,   665,
    -228,  -228,   612,   177,  -228,    53,   612,   152,  -228,   176,
     190,   190,  -228,  -228,  -228,   463,   489,    68,   196,   203,
     389,  -228,   612,   612,   612,   612,  -228,    -5,   651,   135,
     192,   212,   213,   473,   507,   697,   697,   697,   697,   517,
    -228,   219,    20,   198,   205,   206,  -228,   198,    -4,   198,
     697,   202,  -228,    20,   612,   128,  -228,   542,  -228,   217,
     697,   697,   697,   697,  -228,  -228,  -228,   612,   612,   612,
     697,   612,   697,  -228,    -1,   218,    49,   211,   403,   403,
    -228,   198,   233,   211,   198,    20,   552,   638,   130,   577,
     697,   697,   697,   697,  -228,   198,   207,    55,   211,  -228,
    -228,   171,  -228,  -228,  -228,   211,  -228,  -228,    20,    59,
      20,   552,  -228,    13,  -228,  -228,   403,  -228,  -228,  -228,
    -228,   587,    20,  -228,   155,  -228,    26,   198,  -228,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   119,   120,    36,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,    93,     0,     0,     0,     2,     4,
      14,     7,    13,    11,    12,     8,    23,     9,    10,    15,
       6,    34,    33,    73,     5,    31,    32,    30,    29,   105,
     103,    35,     0,     0,     0,     0,     0,     0,     0,    36,
      20,    29,    37,   106,   104,    16,    17,     0,     0,    18,
       0,     0,    22,     0,     0,    98,     0,   100,     0,     0,
       0,    92,     0,   127,   130,   131,   159,   133,   138,   152,
     139,   154,   149,   143,   144,   145,   135,   150,   151,   156,
     155,   136,   137,   142,   141,   157,   158,   146,   124,   148,
     134,   140,   153,   160,   129,   128,     0,   126,   132,   147,
     123,     0,     1,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      87,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,    23,     0,    52,    54,    55,    38,     0,     0,     0,
      97,    96,     0,     0,    90,     0,     0,   121,   125,   122,
      24,    26,    25,    28,    27,   113,     0,    23,     0,     0,
      88,    89,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
      71,     0,    56,     0,     0,     0,   102,     0,     0,     0,
      99,     0,    91,    94,   118,   111,   107,   112,   108,    70,
      83,    84,    85,    86,    74,   109,    64,     0,     0,     0,
      62,     0,    63,    76,     0,     0,     4,    43,     0,     0,
      67,     0,     0,    39,     0,   117,     0,     0,   110,     0,
      58,    59,    60,    61,    77,     0,     0,     0,    44,    48,
      46,    51,    53,    66,   101,    40,    42,    65,   115,    70,
     116,     0,    69,     0,    19,    95,     0,    50,    47,    45,
      41,     0,   114,    68,     0,    69,     0,     0,    68,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,   -14,  -228,  -228,  -228,   229,  -228,  -228,  -228,
       0,   -27,  -228,  -228,     9,  -209,  -227,   -60,    15,    21,
     -35,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,    94,
    -172,  -228,   -46,  -228,  -228,     1,  -228,    19,    33,     3,
     240,    30,  -228
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    59,    22,    23,    24,
      67,    26,    27,    28,   248,   249,   250,   142,   143,   144,
     145,    29,    30,    31,    32,    33,    34,    35,    70,    71,
     227,    36,    68,   198,    37,    51,   168,    39,    40,    41,
     106,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    38,   137,   148,    50,   113,   256,   130,    60,    56,
      55,   190,   151,    61,   214,   231,    63,    72,   244,    25,
      38,   269,   152,   196,    53,   230,   152,   233,   270,   152,
     232,   141,   273,   152,   104,   104,   141,   197,    54,   268,
      15,    16,   129,   119,    62,   278,   268,   152,   105,   105,
     112,   120,     1,     2,     3,     4,   131,   138,   140,   253,
     152,     5,   257,   140,   149,     6,     7,     8,    69,     9,
      10,    11,    12,   264,   132,   267,    47,   271,   266,    13,
     177,    14,   -36,   -36,    15,    16,   171,   226,    15,    16,
     -36,   119,   167,   180,   121,   122,   123,   124,   125,   207,
     119,   -57,   126,   -57,   -57,   279,    57,   127,   120,    47,
      48,    58,   192,   133,   160,   161,   162,   163,   164,   166,
     134,   170,     1,     2,    52,   104,   135,   178,   179,   203,
     104,   185,   186,   187,   188,   126,   158,   150,   205,   105,
     127,   158,   147,   224,   105,   181,   114,   115,   116,   117,
     118,   119,   200,   119,   146,   193,   182,   194,    72,   236,
     199,   261,   194,   183,   184,   154,   155,     1,     2,    49,
     153,   156,   210,   211,   212,   213,     5,   235,   169,   277,
     238,   194,    64,   220,   222,   172,   189,    12,    65,  -147,
    -147,  -147,  -147,   263,   173,   174,    14,   175,   195,    15,
      16,   141,   141,   116,   117,   118,   274,   201,   209,   258,
     260,   216,   246,  -148,  -148,  -148,  -148,   240,   241,   242,
     208,   243,   217,   218,   225,   276,    25,    38,   140,   140,
     226,   228,   234,   229,   272,   239,   247,   245,   254,   141,
     265,    66,   255,   251,     1,     2,    73,    74,    75,   202,
     252,    76,    77,    78,    79,    80,   111,    81,    82,    83,
      84,     0,    85,    86,    87,    88,   140,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     1,     2,    73,    74,    75,     0,     0,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,     0,
      85,    86,    87,    88,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   109,   110,   100,   101,   102,   103,
       1,     2,    73,    74,    75,     0,     0,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,     0,    85,    86,
      87,    88,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   157,    99,   100,   101,   102,   103,     1,     2,
      73,    74,    75,     0,     0,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,     0,    85,    86,    87,    88,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     109,   159,   100,   101,   102,   103,     1,     2,    49,   181,
     114,   115,   116,   117,   118,     5,     1,     2,    49,     0,
     182,     8,   136,     0,     0,     5,    12,   183,   184,     0,
       0,   128,     0,     0,   139,    14,    12,     0,    15,    16,
       0,     1,     2,    49,     0,    14,     0,     0,    15,    16,
       5,     1,     2,    49,     0,     0,     8,     0,     0,     0,
       5,    12,     0,     0,     0,     0,     8,   176,     0,   165,
      14,    12,     0,    15,    16,     0,     1,     2,    49,     0,
      14,     0,     0,    15,    16,     5,     1,     2,    49,     0,
       0,     8,     0,   219,     0,     5,    12,     0,     0,     0,
       0,     8,     0,     0,   204,    14,    12,     0,    15,    16,
     114,   115,   116,   117,   118,    14,     0,     0,    15,    16,
       1,     2,    49,   206,     0,     0,     0,   221,     0,     5,
       1,     2,    49,     0,     0,     8,     0,     0,     0,     5,
      12,     0,     0,     0,     0,     8,   223,     0,     0,    14,
      12,     0,    15,    16,     0,     1,     2,    49,     0,    14,
       0,     0,    15,    16,     5,     1,     2,    49,     0,     0,
       8,     0,     0,     0,     5,    12,     0,     0,     0,     0,
       8,     0,     0,   237,    14,    12,     0,    15,    16,     0,
       1,     2,    49,   169,    14,     0,     0,    15,    16,     5,
       1,     2,    49,     0,     0,     8,   262,     0,     0,     5,
      12,     0,     0,     0,     0,     8,   275,     0,     0,    14,
      12,     0,    15,    16,     0,     1,     2,    49,     0,    14,
       0,     0,    15,    16,     5,     1,     2,    49,     0,     0,
       8,     0,     0,     0,     5,    12,     0,     0,     0,     0,
     128,     1,     2,   259,    14,    12,     0,    15,    16,     0,
       5,     0,     0,     0,    14,     0,     8,    15,    16,     0,
       0,    12,   114,   115,   116,   117,   118,     0,     0,     0,
      14,     0,   191,    15,    16,   215,   114,   115,   116,   117,
     118,     0,     0,     0,   146,    42,    43,    44,    45,    46,
       0,     0,    47,    48,   114,   115,   116,   117,   118,   191,
       0,     0,   146,   114,   115,   116,   117,   118,   114,   115,
     116,   117,   118
};

static const yytype_int16 yycheck[] =
{
       0,     0,    48,    63,     4,    19,   233,    42,     8,     6,
       5,    19,    24,     5,    19,    19,    23,    14,    19,    19,
      19,   248,    34,     5,     5,   197,    34,   199,   255,    34,
      34,    58,    19,    34,    15,    16,    63,    19,     5,   248,
      35,    36,    42,    23,    20,    19,   255,    34,    15,    16,
       0,    31,     3,     4,     5,     6,    10,    57,    58,   231,
      34,    12,   234,    63,    64,    16,    17,    18,    30,    20,
      21,    22,    23,   245,    10,   247,    17,    18,    23,    30,
     126,    32,    23,    24,    35,    36,   121,    32,    35,    36,
      31,    23,   119,   128,    10,    11,    12,    13,    14,    31,
      23,    24,    18,    26,    27,   277,    18,    23,    31,    17,
      18,    23,   139,    10,   114,   115,   116,   117,   118,   119,
      10,   121,     3,     4,     5,   106,     5,   127,   128,   156,
     111,   131,   132,   133,   134,    18,   106,    24,   165,   106,
      23,   111,    18,   189,   111,    10,    11,    12,    13,    14,
      15,    23,   152,    23,    19,    24,    21,    26,   155,    31,
      24,    31,    26,    28,    29,    33,    34,     3,     4,     5,
       5,    31,   172,   173,   174,   175,    12,   204,    31,    24,
     207,    26,    18,   183,   184,    10,    18,    23,    24,    37,
      38,    39,    40,   239,    10,    10,    32,    10,    27,    35,
      36,   228,   229,    13,    14,    15,   266,    30,     5,   236,
     237,    19,   226,    37,    38,    39,    40,   217,   218,   219,
      24,   221,    10,    10,     5,   271,   226,   226,   228,   229,
      32,    26,    30,    27,   261,    18,    25,    19,     5,   266,
      33,    12,   233,   228,     3,     4,     5,     6,     7,   155,
     229,    10,    11,    12,    13,    14,    16,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,   266,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     3,     4,     5,    10,
      11,    12,    13,    14,    15,    12,     3,     4,     5,    -1,
      21,    18,    19,    -1,    -1,    12,    23,    28,    29,    -1,
      -1,    18,    -1,    -1,    21,    32,    23,    -1,    35,    36,
      -1,     3,     4,     5,    -1,    32,    -1,    -1,    35,    36,
      12,     3,     4,     5,    -1,    -1,    18,    -1,    -1,    -1,
      12,    23,    -1,    -1,    -1,    -1,    18,    19,    -1,    31,
      32,    23,    -1,    35,    36,    -1,     3,     4,     5,    -1,
      32,    -1,    -1,    35,    36,    12,     3,     4,     5,    -1,
      -1,    18,    -1,    10,    -1,    12,    23,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    31,    32,    23,    -1,    35,    36,
      11,    12,    13,    14,    15,    32,    -1,    -1,    35,    36,
       3,     4,     5,    24,    -1,    -1,    -1,    10,    -1,    12,
       3,     4,     5,    -1,    -1,    18,    -1,    -1,    -1,    12,
      23,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    32,
      23,    -1,    35,    36,    -1,     3,     4,     5,    -1,    32,
      -1,    -1,    35,    36,    12,     3,     4,     5,    -1,    -1,
      18,    -1,    -1,    -1,    12,    23,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    31,    32,    23,    -1,    35,    36,    -1,
       3,     4,     5,    31,    32,    -1,    -1,    35,    36,    12,
       3,     4,     5,    -1,    -1,    18,    19,    -1,    -1,    12,
      23,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    32,
      23,    -1,    35,    36,    -1,     3,     4,     5,    -1,    32,
      -1,    -1,    35,    36,    12,     3,     4,     5,    -1,    -1,
      18,    -1,    -1,    -1,    12,    23,    -1,    -1,    -1,    -1,
      18,     3,     4,     5,    32,    23,    -1,    35,    36,    -1,
      12,    -1,    -1,    -1,    32,    -1,    18,    35,    36,    -1,
      -1,    23,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      32,    -1,     7,    35,    36,    24,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    11,    12,    13,    14,    15,     7,
      -1,    -1,    19,    11,    12,    13,    14,    15,    11,    12,
      13,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    12,    16,    17,    18,    20,
      21,    22,    23,    30,    32,    35,    36,    42,    43,    44,
      45,    46,    48,    49,    50,    51,    52,    53,    54,    62,
      63,    64,    65,    66,    67,    68,    72,    75,    76,    78,
      79,    80,    10,    11,    12,    13,    14,    17,    18,     5,
      51,    76,     5,    78,    79,     5,    80,    18,    23,    47,
      51,     5,    20,    23,    18,    24,    47,    51,    73,    30,
      69,    70,    80,     5,     6,     7,    10,    11,    12,    13,
      14,    16,    17,    18,    19,    21,    22,    23,    24,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    78,    79,    81,    82,    83,    35,
      36,    81,     0,    43,    11,    12,    13,    14,    15,    23,
      31,    10,    11,    12,    13,    14,    18,    23,    18,    51,
      61,    10,    10,    10,    10,     5,    19,    73,    51,    21,
      51,    52,    58,    59,    60,    61,    19,    18,    58,    51,
      24,    24,    34,     5,    33,    34,    31,    35,    82,    36,
      51,    51,    51,    51,    51,    31,    51,    52,    77,    31,
      51,    61,    10,    10,    10,    10,    19,    73,    51,    51,
      61,    10,    21,    28,    29,    51,    51,    51,    51,    18,
      19,     7,    52,    24,    26,    27,     5,    19,    74,    24,
      51,    30,    70,    52,    31,    52,    24,    31,    24,     5,
      51,    51,    51,    51,    19,    24,    19,    10,    10,    10,
      51,    10,    51,    19,    73,     5,    32,    71,    26,    27,
      71,    19,    34,    71,    30,    52,    31,    31,    52,    18,
      51,    51,    51,    51,    19,    19,    43,    25,    55,    56,
      57,    59,    60,    71,     5,    55,    57,    71,    52,     5,
      52,    31,    19,    73,    71,    33,    23,    71,    56,    57,
      57,    18,    52,    19,    58,    19,    73,    24,    19,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    46,    47,
      48,    49,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    69,    69,    69,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    80,    80,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     6,
       2,     1,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       6,     7,     6,     5,     6,     7,     6,     2,     1,     5,
       2,     4,     1,     4,     1,     1,     2,     1,     4,     4,
       4,     4,     3,     3,     3,     6,     6,     5,     7,     6,
       4,     4,     3,     1,     4,     3,     5,     6,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     1,     0,     3,     3,     3,     3,     2,     3,
       1,     3,     1,     1,     2,     1,     2,     4,     4,     4,
       3,     2,     2,     1,     5,     4,     4,     3,     2,     1,
       1,     3,     3,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 1655 "y.tab.c"
    break;

  case 3:
#line 114 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1665 "y.tab.c"
    break;

  case 4:
#line 119 "gram.y"
      { (yyval.data) = NULL; }
#line 1671 "y.tab.c"
    break;

  case 5:
#line 123 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1679 "y.tab.c"
    break;

  case 6:
#line 126 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1687 "y.tab.c"
    break;

  case 7:
#line 129 "gram.y"
                           {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1695 "y.tab.c"
    break;

  case 8:
#line 132 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1703 "y.tab.c"
    break;

  case 9:
#line 135 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1711 "y.tab.c"
    break;

  case 10:
#line 138 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1719 "y.tab.c"
    break;

  case 11:
#line 141 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1727 "y.tab.c"
    break;

  case 12:
#line 144 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1735 "y.tab.c"
    break;

  case 13:
#line 147 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1743 "y.tab.c"
    break;

  case 14:
#line 150 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1751 "y.tab.c"
    break;

  case 15:
#line 153 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1759 "y.tab.c"
    break;

  case 16:
#line 157 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1767 "y.tab.c"
    break;

  case 17:
#line 159 "gram.y"
                      {
    (yyval.data) = (yyvsp[0].data);
}
#line 1775 "y.tab.c"
    break;

  case 18:
#line 164 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1783 "y.tab.c"
    break;

  case 19:
#line 169 "gram.y"
                                        {
    (yyval.data) = newForEach((yyvsp[-4].data), (yyvsp[-2].id), (yyvsp[0].data));
}
#line 1791 "y.tab.c"
    break;

  case 20:
#line 173 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1799 "y.tab.c"
    break;

  case 21:
#line 177 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1807 "y.tab.c"
    break;

  case 22:
#line 181 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1815 "y.tab.c"
    break;

  case 23:
#line 186 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1823 "y.tab.c"
    break;

  case 24:
#line 189 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1834 "y.tab.c"
    break;

  case 25:
#line 195 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1845 "y.tab.c"
    break;

  case 26:
#line 201 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1856 "y.tab.c"
    break;

  case 27:
#line 207 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1867 "y.tab.c"
    break;

  case 28:
#line 213 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1878 "y.tab.c"
    break;

  case 29:
#line 221 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1886 "y.tab.c"
    break;

  case 30:
#line 224 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1894 "y.tab.c"
    break;

  case 31:
#line 227 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1902 "y.tab.c"
    break;

  case 32:
#line 230 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1910 "y.tab.c"
    break;

  case 33:
#line 233 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1918 "y.tab.c"
    break;

  case 34:
#line 236 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1926 "y.tab.c"
    break;

  case 35:
#line 239 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1934 "y.tab.c"
    break;

  case 36:
#line 242 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1942 "y.tab.c"
    break;

  case 37:
#line 245 "gram.y"
             {
      expr_t *id = newExpr_ID((yyvsp[0].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
    }
#line 1952 "y.tab.c"
    break;

  case 38:
#line 250 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1960 "y.tab.c"
    break;

  case 39:
#line 255 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1968 "y.tab.c"
    break;

  case 40:
#line 258 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1980 "y.tab.c"
    break;

  case 41:
#line 265 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1993 "y.tab.c"
    break;

  case 42:
#line 273 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2005 "y.tab.c"
    break;

  case 43:
#line 282 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2013 "y.tab.c"
    break;

  case 44:
#line 285 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2025 "y.tab.c"
    break;

  case 45:
#line 292 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2038 "y.tab.c"
    break;

  case 46:
#line 300 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2050 "y.tab.c"
    break;

  case 47:
#line 309 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2062 "y.tab.c"
    break;

  case 48:
#line 316 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2070 "y.tab.c"
    break;

  case 49:
#line 321 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2080 "y.tab.c"
    break;

  case 50:
#line 328 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2089 "y.tab.c"
    break;

  case 51:
#line 334 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2097 "y.tab.c"
    break;

  case 52:
#line 337 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2105 "y.tab.c"
    break;

  case 53:
#line 342 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2113 "y.tab.c"
    break;

  case 54:
#line 345 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2121 "y.tab.c"
    break;

  case 55:
#line 350 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2129 "y.tab.c"
    break;

  case 56:
#line 353 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2139 "y.tab.c"
    break;

  case 57:
#line 358 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2147 "y.tab.c"
    break;

  case 58:
#line 363 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2155 "y.tab.c"
    break;

  case 59:
#line 366 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2163 "y.tab.c"
    break;

  case 60:
#line 369 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2171 "y.tab.c"
    break;

  case 61:
#line 372 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2179 "y.tab.c"
    break;

  case 62:
#line 375 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2187 "y.tab.c"
    break;

  case 63:
#line 378 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2195 "y.tab.c"
    break;

  case 64:
#line 381 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2203 "y.tab.c"
    break;

  case 65:
#line 385 "gram.y"
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
#line 2240 "y.tab.c"
    break;

  case 66:
#line 419 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2248 "y.tab.c"
    break;

  case 67:
#line 422 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2256 "y.tab.c"
    break;

  case 68:
#line 427 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2264 "y.tab.c"
    break;

  case 69:
#line 430 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2272 "y.tab.c"
    break;

  case 70:
#line 433 "gram.y"
                            {
        (yyval.data) = newClassAccesser((yyvsp[-3].data), (yyvsp[0].id));
    }
#line 2280 "y.tab.c"
    break;

  case 71:
#line 439 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2289 "y.tab.c"
    break;

  case 72:
#line 443 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2298 "y.tab.c"
    break;

  case 73:
#line 447 "gram.y"
                             {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2306 "y.tab.c"
    break;

  case 74:
#line 450 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2315 "y.tab.c"
    break;

  case 75:
#line 454 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2324 "y.tab.c"
    break;

  case 76:
#line 460 "gram.y"
                      {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        expr_t *expr = newExpr_ID((yyvsp[-4].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
#line 2335 "y.tab.c"
    break;

  case 77:
#line 466 "gram.y"
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
#line 2352 "y.tab.c"
    break;

  case 78:
#line 480 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2362 "y.tab.c"
    break;

  case 79:
#line 485 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2374 "y.tab.c"
    break;

  case 80:
#line 492 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2386 "y.tab.c"
    break;

  case 81:
#line 499 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2398 "y.tab.c"
    break;

  case 82:
#line 506 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2410 "y.tab.c"
    break;

  case 83:
#line 513 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2421 "y.tab.c"
    break;

  case 84:
#line 519 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2432 "y.tab.c"
    break;

  case 85:
#line 525 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2443 "y.tab.c"
    break;

  case 86:
#line 531 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2454 "y.tab.c"
    break;

  case 87:
#line 537 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2464 "y.tab.c"
    break;

  case 88:
#line 542 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2472 "y.tab.c"
    break;

  case 89:
#line 545 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2480 "y.tab.c"
    break;

  case 90:
#line 550 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2488 "y.tab.c"
    break;

  case 91:
#line 555 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2500 "y.tab.c"
    break;

  case 92:
#line 562 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2508 "y.tab.c"
    break;

  case 93:
#line 565 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2516 "y.tab.c"
    break;

  case 94:
#line 570 "gram.y"
                                 {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2530 "y.tab.c"
    break;

  case 95:
#line 581 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2538 "y.tab.c"
    break;

  case 96:
#line 586 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2547 "y.tab.c"
    break;

  case 97:
#line 591 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2556 "y.tab.c"
    break;

  case 98:
#line 595 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2564 "y.tab.c"
    break;

  case 99:
#line 600 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2573 "y.tab.c"
    break;

  case 100:
#line 604 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2581 "y.tab.c"
    break;

  case 101:
#line 609 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2591 "y.tab.c"
    break;

  case 102:
#line 614 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2600 "y.tab.c"
    break;

  case 103:
#line 620 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2608 "y.tab.c"
    break;

  case 104:
#line 623 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2617 "y.tab.c"
    break;

  case 105:
#line 627 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2625 "y.tab.c"
    break;

  case 106:
#line 630 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2634 "y.tab.c"
    break;

  case 107:
#line 636 "gram.y"
                                   {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2645 "y.tab.c"
    break;

  case 108:
#line 642 "gram.y"
                                 {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2656 "y.tab.c"
    break;

  case 109:
#line 648 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2664 "y.tab.c"
    break;

  case 110:
#line 653 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2672 "y.tab.c"
    break;

  case 111:
#line 656 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2680 "y.tab.c"
    break;

  case 112:
#line 659 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2688 "y.tab.c"
    break;

  case 113:
#line 662 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2696 "y.tab.c"
    break;

  case 114:
#line 665 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2704 "y.tab.c"
    break;

  case 115:
#line 668 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2712 "y.tab.c"
    break;

  case 116:
#line 671 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2720 "y.tab.c"
    break;

  case 117:
#line 674 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2728 "y.tab.c"
    break;

  case 118:
#line 677 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2736 "y.tab.c"
    break;

  case 119:
#line 682 "gram.y"
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
#line 2752 "y.tab.c"
    break;

  case 120:
#line 695 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2760 "y.tab.c"
    break;

  case 121:
#line 700 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2768 "y.tab.c"
    break;

  case 122:
#line 703 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2776 "y.tab.c"
    break;

  case 123:
#line 706 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2785 "y.tab.c"
    break;

  case 124:
#line 710 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2794 "y.tab.c"
    break;

  case 125:
#line 716 "gram.y"
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
#line 2827 "y.tab.c"
    break;

  case 126:
#line 744 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2835 "y.tab.c"
    break;

  case 127:
#line 749 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2843 "y.tab.c"
    break;

  case 128:
#line 752 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2855 "y.tab.c"
    break;

  case 129:
#line 759 "gram.y"
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
        } else if ( d->type == EXPR_TYPE_TEXT ) {
          snprintf(buffer, sizeof(buffer), "%s", d->text);
        }
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2877 "y.tab.c"
    break;

  case 130:
#line 776 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2887 "y.tab.c"
    break;

  case 131:
#line 781 "gram.y"
              {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2897 "y.tab.c"
    break;

  case 132:
#line 786 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2905 "y.tab.c"
    break;

  case 133:
#line 791 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2914 "y.tab.c"
    break;

  case 134:
#line 796 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2923 "y.tab.c"
    break;

  case 135:
#line 801 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2932 "y.tab.c"
    break;

  case 136:
#line 805 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2941 "y.tab.c"
    break;

  case 137:
#line 809 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2950 "y.tab.c"
    break;

  case 138:
#line 813 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2959 "y.tab.c"
    break;

  case 139:
#line 817 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2968 "y.tab.c"
    break;

  case 140:
#line 821 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2977 "y.tab.c"
    break;

  case 141:
#line 825 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2986 "y.tab.c"
    break;

  case 142:
#line 829 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2995 "y.tab.c"
    break;

  case 143:
#line 833 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3004 "y.tab.c"
    break;

  case 144:
#line 837 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3013 "y.tab.c"
    break;

  case 145:
#line 841 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3022 "y.tab.c"
    break;

  case 146:
#line 845 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3031 "y.tab.c"
    break;

  case 147:
#line 849 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3040 "y.tab.c"
    break;

  case 148:
#line 853 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3049 "y.tab.c"
    break;

  case 149:
#line 857 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3058 "y.tab.c"
    break;

  case 150:
#line 861 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3067 "y.tab.c"
    break;

  case 151:
#line 865 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3076 "y.tab.c"
    break;

  case 152:
#line 869 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3085 "y.tab.c"
    break;

  case 153:
#line 873 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3094 "y.tab.c"
    break;

  case 154:
#line 877 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3103 "y.tab.c"
    break;

  case 155:
#line 881 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3112 "y.tab.c"
    break;

  case 156:
#line 885 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3121 "y.tab.c"
    break;

  case 157:
#line 889 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3130 "y.tab.c"
    break;

  case 158:
#line 893 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3139 "y.tab.c"
    break;

  case 159:
#line 897 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3148 "y.tab.c"
    break;

  case 160:
#line 901 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3157 "y.tab.c"
    break;


#line 3161 "y.tab.c"

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
#line 906 "gram.y"


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
