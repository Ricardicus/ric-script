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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   791

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  310

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
       0,    97,    97,   114,   119,   120,   123,   128,   131,   134,
     137,   140,   143,   146,   149,   152,   155,   158,   162,   162,
     164,   166,   171,   176,   178,   182,   186,   190,   195,   198,
     204,   210,   216,   222,   230,   233,   236,   239,   242,   245,
     248,   251,   254,   259,   264,   267,   274,   282,   291,   294,
     301,   309,   318,   325,   330,   337,   343,   346,   351,   354,
     359,   362,   367,   372,   375,   378,   381,   384,   387,   390,
     394,   428,   431,   436,   439,   442,   448,   452,   456,   459,
     463,   469,   475,   489,   494,   501,   508,   515,   522,   528,
     534,   540,   546,   551,   554,   559,   564,   571,   574,   579,
     590,   595,   600,   604,   609,   613,   618,   623,   629,   632,
     636,   639,   645,   651,   657,   660,   667,   670,   673,   676,
     679,   682,   685,   688,   691,   696,   709,   714,   717,   720,
     724,   730,   758,   763,   766,   773,   790,   795,   800,   805,
     810,   815,   819,   823,   827,   831,   835,   839,   843,   847,
     851,   855,   859,   863,   867,   871,   875,   879,   883,   887,
     891,   895,   899,   903,   907,   911,   915
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

#define YYPACT_NINF (-244)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    30,  -244,   238,  -244,  -244,  -244,   532,   724,  -244,
     177,     6,    13,   724,    43,    82,    93,  -244,   101,    -1,
     307,   345,     4,  -244,  -244,  -244,  -244,  -244,  -244,   698,
      58,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,   127,  -244,  -244,  -244,   740,   123,   124,   136,
     156,   163,   494,    69,   698,    49,  -244,  -244,  -244,  -244,
    -244,   724,   504,  -244,   207,   152,  -244,   504,   459,   171,
       9,   153,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,   227,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,   383,  -244,  -244,  -244,   481,
     421,  -244,   180,  -244,  -244,  -244,  -244,  -244,   174,   165,
     740,   184,   188,   189,   191,   529,   174,   740,    83,  -244,
     724,   724,   724,   724,   186,  -244,   698,   183,   550,   580,
     724,    83,   222,    44,   181,  -244,  -244,  -244,    21,    79,
     724,  -244,  -244,  -244,   187,  -244,   176,  -244,    16,   227,
    -244,   481,   550,   550,   550,   550,   550,   566,    39,    95,
     192,   229,    83,  -244,   724,   724,   724,   724,  -244,   208,
     200,   211,    63,   213,   230,   241,   600,   610,   698,   698,
     698,   698,   635,  -244,    12,   776,   232,    58,   220,   231,
     235,  -244,   220,    -7,   220,   284,    10,     5,   239,   180,
     724,     9,  -244,   272,   272,  -244,  -244,  -244,   724,   134,
    -244,   645,  -244,   259,   698,   698,   698,   698,  -244,  -244,
    -244,  -244,   724,   724,   724,   698,   724,   698,  -244,   260,
    -244,   277,  -244,   256,   265,  -244,  -244,  -244,   220,   289,
     265,  -244,  -244,   220,    58,  -244,    58,   661,   750,   144,
     682,   698,   698,   698,   698,  -244,   550,  -244,    60,   267,
      24,   265,  -244,  -244,   469,   469,  -244,  -244,   265,  -244,
    -244,    58,   125,    58,   661,  -244,   282,   698,    91,   220,
    -244,   504,  -244,  -244,  -244,   181,  -244,  -244,   703,    58,
    -244,   220,  -244,    96,  -244,   285,  -244,   220,  -244,  -244
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      19,     0,     2,     4,     1,   125,   126,    41,     0,    18,
       0,     0,     0,     0,    26,     0,     0,    19,     0,    19,
       0,     0,    19,    19,    16,     9,    15,    13,    14,    10,
      28,    11,    12,    17,     8,    39,    38,    78,     7,    36,
      37,    35,    34,   110,   108,    40,     0,     0,     0,     0,
       0,     0,     0,    41,    25,    34,    42,   111,   109,    20,
      21,    19,     0,    22,     0,     0,    27,     0,     0,     0,
       0,    19,   133,   136,   137,   165,   139,   144,   158,   145,
     160,   155,   149,   150,   151,   141,   156,   157,   162,   161,
     142,   143,   148,   147,   163,   164,   152,   130,   154,   140,
     146,   159,   166,   135,   134,     0,   132,   138,   153,   129,
       0,     3,     6,    19,    19,    19,    19,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    92,
       0,     0,     0,     0,     0,    77,   105,    19,     0,     0,
       0,     0,    28,     0,    57,    59,    60,    43,     0,     0,
      19,   103,    19,    19,     0,    19,     0,    19,     0,   127,
     131,   128,     0,     0,     0,     0,     0,   119,     0,    28,
       0,     0,    93,    94,     0,     0,     0,     0,    80,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,     0,    76,     0,     0,     0,    61,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,    95,    29,    31,    30,    33,    32,   124,   117,
     112,   118,   113,    75,    88,    89,    90,    91,    79,   114,
     115,    69,     0,     0,     0,    67,     0,    68,    81,    19,
      19,     0,    19,    19,    48,    19,    19,    72,     0,     0,
      44,   102,   101,     0,    99,    96,   123,     0,     0,   116,
       0,    63,    64,    65,    66,    82,     0,    19,     0,     0,
       0,    49,    53,    51,     0,     0,    71,   106,    45,    47,
      70,   121,    75,   122,     0,    74,    19,   104,     0,     0,
     100,     0,    55,    52,    50,    56,    58,    46,     0,   120,
      73,     0,    23,     0,    74,    19,    24,     0,    73,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -244,  -244,   -20,  -244,  -244,    38,  -244,  -244,   240,  -244,
    -244,  -244,    -3,    18,  -244,  -244,    56,  -157,  -243,   -66,
      33,    40,   -37,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,   105,  -182,  -244,   -60,  -244,  -244,   319,   201,    -4,
       3,    -8,   311,    59,  -244
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    22,    23,   194,    24,    25,    63,    26,
      27,    28,   136,    30,    31,    32,   271,   272,   273,   143,
     144,   145,   146,    33,    34,    35,    36,    37,    38,    39,
      71,   155,   244,    40,   137,   203,    41,    55,   170,    43,
      44,    45,   105,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   149,   111,    60,    -5,    54,    57,   279,   153,   129,
      64,    59,   248,    58,     9,    -5,   103,   103,     9,     9,
     247,     9,   250,   104,   104,     9,   201,   249,   294,   252,
       4,    61,   -98,   -98,   251,   297,    62,    -5,     3,   240,
     202,    20,    21,   128,    20,    21,   240,   291,    65,   212,
     113,   114,   115,   116,   117,    68,   243,    70,   139,   141,
       3,   112,   156,   220,   141,   179,   276,   125,   198,     9,
     199,   280,   126,   184,   113,   114,   115,   116,   117,   289,
     142,   118,   147,   173,   185,   142,    51,    52,   292,   119,
     183,   186,   187,   184,   113,   114,   115,   116,   117,   138,
       9,   103,    66,   204,   185,   199,   103,   302,   104,   158,
     301,   186,   187,   104,   293,   168,    67,   172,   118,   306,
     307,   293,   199,   180,   182,   309,   221,   188,   189,   190,
     191,    69,   239,   130,   131,   195,   169,   120,   121,   122,
     123,   124,    51,   298,   169,   125,   132,   205,   -41,   -41,
     126,   162,   163,   164,   165,   166,   -41,   118,   197,   213,
     214,   215,   216,   217,   160,   257,   133,   118,   134,   160,
     148,   224,   225,   226,   227,   284,   154,     5,     6,    53,
       5,     6,    56,   235,   237,   219,    10,   157,   138,     9,
     206,   207,    13,   209,   174,   211,   171,    17,   175,   176,
     286,   177,   193,   156,   192,   167,    19,   210,   200,    20,
      21,   113,   114,   115,   116,   117,   222,   208,   113,   114,
     115,   116,   117,   269,   229,   303,   147,   228,   254,   261,
     262,   263,   231,   264,   223,   230,   256,   242,   305,   259,
     232,     5,     6,     7,     8,   118,   -62,     9,   -62,   -62,
      10,   233,   243,   119,    11,    12,    13,   245,    14,    15,
      16,    17,   246,   287,  -153,  -153,  -153,  -153,    18,   253,
      19,   141,   141,    20,    21,   281,   283,   260,   266,   265,
     268,     3,   267,   274,   275,   115,   116,   117,   141,    -5,
     270,   196,   142,   142,   277,   113,   114,   115,   116,   117,
     290,   300,   299,   147,   308,   288,   278,   295,   152,   142,
       5,     6,    72,    73,    74,   296,   255,    75,    76,    77,
      78,    79,    42,    80,    81,    82,    83,   181,    84,    85,
      86,    87,   110,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     5,     6,
      72,    73,    74,     0,     0,    75,    76,    77,    78,    79,
       0,    80,    81,    82,    83,     0,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     108,   109,    99,   100,   101,   102,     5,     6,    72,    73,
      74,     0,     0,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,     0,    84,    85,    86,    87,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   159,    98,
      99,   100,   101,   102,     5,     6,    72,    73,    74,     0,
       0,    75,    76,    77,    78,    79,     0,    80,    81,    82,
      83,     0,    84,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   108,   161,    99,   100,
     101,   102,     5,     6,    53,     0,     0,     0,     9,     0,
       0,    10,     5,     6,    53,     0,     0,   150,     9,     0,
       0,    10,    17,   151,     0,     0,     0,   127,     0,     0,
     140,    19,    17,     0,    20,    21,     0,     5,     6,    53,
       0,    19,     0,     0,    20,    21,    10,     5,     6,    53,
       0,     0,    13,   135,     0,     0,    10,    17,  -154,  -154,
    -154,  -154,   127,     0,     0,   140,    19,    17,     0,    20,
      21,     0,     5,     6,    53,     0,    19,     0,     0,    20,
      21,    10,    46,    47,    48,    49,    50,    13,   178,    51,
      52,     0,    17,     5,     6,    53,     0,     0,     0,     9,
       0,    19,    10,     0,    20,    21,     0,     0,    13,     5,
       6,    53,     0,    17,     0,     0,     0,     0,    10,     0,
       0,     0,    19,     0,    13,    20,    21,   196,     0,    17,
       0,   113,   114,   115,   116,   117,     0,   218,    19,     0,
       0,    20,    21,     5,     6,    53,     0,     0,     0,     0,
     234,     0,    10,     5,     6,    53,     0,     0,    13,     0,
     236,     0,    10,    17,     0,     0,     0,     0,    13,     0,
       0,     0,    19,    17,     0,    20,    21,     0,     5,     6,
      53,     0,    19,     0,     0,    20,    21,    10,     5,     6,
      53,     0,     0,    13,   238,     0,     0,    10,    17,     0,
       0,     0,     0,    13,     5,     6,    53,    19,    17,     0,
      20,    21,     0,    10,     0,     0,   258,    19,     0,    13,
      20,    21,     0,     0,    17,     5,     6,    53,     0,     0,
       0,     0,   171,    19,    10,     0,    20,    21,     0,     0,
      13,   285,     0,     0,     0,    17,     5,     6,    53,   113,
     114,   115,   116,   117,    19,    10,     0,    20,    21,     0,
       0,    13,   304,     0,     0,     0,    17,     5,     6,    53,
       0,     0,     0,     0,     0,    19,    10,     0,    20,    21,
       0,     0,    13,     5,     6,    53,     0,    17,     0,     0,
       0,     0,    10,     5,     6,   282,    19,     0,   127,    20,
      21,     0,    10,    17,     0,     0,     0,     0,    13,     0,
       0,     0,    19,    17,     0,    20,    21,     0,     0,     0,
       0,     0,    19,   241,     0,    20,    21,   113,   114,   115,
     116,   117
};

static const yytype_int16 yycheck[] =
{
       3,    67,    22,    11,     0,     8,    10,   250,    68,    46,
      13,     5,    19,    10,     9,     0,    20,    21,     9,     9,
     202,     9,   204,    20,    21,     9,     5,    34,   271,    24,
       0,    18,    33,    34,    24,   278,    23,    33,     0,    34,
      19,    35,    36,    46,    35,    36,    34,    23,     5,    33,
      11,    12,    13,    14,    15,    17,    32,    19,    61,    62,
      22,    23,    70,    24,    67,   125,   248,    18,    24,     9,
      26,   253,    23,    10,    11,    12,    13,    14,    15,    19,
      62,    23,    19,   120,    21,    67,    17,    18,   270,    31,
     127,    28,    29,    10,    11,    12,    13,    14,    15,    61,
       9,   105,    20,    24,    21,    26,   110,   289,   105,    71,
      19,    28,    29,   110,   271,   118,    23,   120,    23,   301,
      24,   278,    26,   126,   127,   307,    31,   130,   131,   132,
     133,    30,   192,    10,    10,   138,   118,    10,    11,    12,
      13,    14,    17,    18,   126,    18,    10,   150,    23,    24,
      23,   113,   114,   115,   116,   117,    31,    23,   140,   162,
     163,   164,   165,   166,   105,    31,    10,    23,     5,   110,
      18,   174,   175,   176,   177,    31,     5,     3,     4,     5,
       3,     4,     5,   186,   187,   167,    12,    34,   150,     9,
     152,   153,    18,   155,    10,   157,    31,    23,    10,    10,
     260,    10,    19,   211,    18,    31,    32,    31,    27,    35,
      36,    11,    12,    13,    14,    15,    24,    30,    11,    12,
      13,    14,    15,   243,    24,   291,    19,    19,   210,   232,
     233,   234,    19,   236,     5,    24,   218,     5,   298,   221,
      10,     3,     4,     5,     6,    23,    24,     9,    26,    27,
      12,    10,    32,    31,    16,    17,    18,    26,    20,    21,
      22,    23,    27,   266,    37,    38,    39,    40,    30,    30,
      32,   274,   275,    35,    36,   257,   258,    18,   240,    19,
     242,   243,     5,   245,   246,    13,    14,    15,   291,    33,
      25,     7,   274,   275,     5,    11,    12,    13,    14,    15,
      33,    19,   284,    19,    19,   267,   250,   274,    68,   291,
       3,     4,     5,     6,     7,   275,   211,    10,    11,    12,
      13,    14,     3,    16,    17,    18,    19,   126,    21,    22,
      23,    24,    21,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    12,     3,     4,     5,    -1,    -1,    18,     9,    -1,
      -1,    12,    23,    24,    -1,    -1,    -1,    18,    -1,    -1,
      21,    32,    23,    -1,    35,    36,    -1,     3,     4,     5,
      -1,    32,    -1,    -1,    35,    36,    12,     3,     4,     5,
      -1,    -1,    18,    19,    -1,    -1,    12,    23,    37,    38,
      39,    40,    18,    -1,    -1,    21,    32,    23,    -1,    35,
      36,    -1,     3,     4,     5,    -1,    32,    -1,    -1,    35,
      36,    12,    10,    11,    12,    13,    14,    18,    19,    17,
      18,    -1,    23,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    32,    12,    -1,    35,    36,    -1,    -1,    18,     3,
       4,     5,    -1,    23,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    32,    -1,    18,    35,    36,     7,    -1,    23,
      -1,    11,    12,    13,    14,    15,    -1,    31,    32,    -1,
      -1,    35,    36,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    -1,    12,     3,     4,     5,    -1,    -1,    18,    -1,
      10,    -1,    12,    23,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    32,    23,    -1,    35,    36,    -1,     3,     4,
       5,    -1,    32,    -1,    -1,    35,    36,    12,     3,     4,
       5,    -1,    -1,    18,    19,    -1,    -1,    12,    23,    -1,
      -1,    -1,    -1,    18,     3,     4,     5,    32,    23,    -1,
      35,    36,    -1,    12,    -1,    -1,    31,    32,    -1,    18,
      35,    36,    -1,    -1,    23,     3,     4,     5,    -1,    -1,
      -1,    -1,    31,    32,    12,    -1,    35,    36,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,     3,     4,     5,    11,
      12,    13,    14,    15,    32,    12,    -1,    35,    36,    -1,
      -1,    18,    19,    -1,    -1,    -1,    23,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    32,    12,    -1,    35,    36,
      -1,    -1,    18,     3,     4,     5,    -1,    23,    -1,    -1,
      -1,    -1,    12,     3,     4,     5,    32,    -1,    18,    35,
      36,    -1,    12,    23,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    32,    23,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    32,     7,    -1,    35,    36,    11,    12,    13,
      14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,    46,     0,     3,     4,     5,     6,     9,
      12,    16,    17,    18,    20,    21,    22,    23,    30,    32,
      35,    36,    44,    45,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    64,    65,    66,    67,    68,    69,    70,
      74,    77,    78,    80,    81,    82,    10,    11,    12,    13,
      14,    17,    18,     5,    53,    78,     5,    80,    81,     5,
      82,    18,    23,    49,    53,     5,    20,    23,    46,    30,
      46,    71,     5,     6,     7,    10,    11,    12,    13,    14,
      16,    17,    18,    19,    21,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    80,    81,    83,    84,    85,    35,    36,
      83,    43,    46,    11,    12,    13,    14,    15,    23,    31,
      10,    11,    12,    13,    14,    18,    23,    18,    53,    63,
      10,    10,    10,    10,     5,    19,    53,    75,    46,    53,
      21,    53,    54,    60,    61,    62,    63,    19,    18,    60,
      18,    24,    49,    75,     5,    72,    82,    34,    46,    35,
      84,    36,    46,    46,    46,    46,    46,    31,    53,    54,
      79,    31,    53,    63,    10,    10,    10,    10,    19,    75,
      53,    79,    53,    63,    10,    21,    28,    29,    53,    53,
      53,    53,    18,    19,    46,    53,     7,    54,    24,    26,
      27,     5,    19,    76,    24,    53,    46,    46,    30,    46,
      31,    46,    33,    53,    53,    53,    53,    53,    31,    54,
      24,    31,    24,     5,    53,    53,    53,    53,    19,    24,
      24,    19,    10,    10,    10,    53,    10,    53,    19,    75,
      34,     7,     5,    32,    73,    26,    27,    73,    19,    34,
      73,    24,    24,    30,    54,    72,    54,    31,    31,    54,
      18,    53,    53,    53,    53,    19,    46,     5,    46,    43,
      25,    57,    58,    59,    46,    46,    73,     5,    57,    59,
      73,    54,     5,    54,    31,    19,    75,    53,    46,    19,
      33,    23,    73,    58,    59,    61,    62,    59,    18,    54,
      19,    19,    73,    60,    19,    75,    73,    24,    19,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    51,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    71,    71,    72,
      73,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    81,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     2,     2,     7,     8,     2,     1,     2,     1,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     5,     6,     7,     6,     5,     6,
       7,     6,     2,     1,     5,     2,     5,     1,     5,     1,
       1,     2,     1,     4,     4,     4,     4,     3,     3,     3,
       6,     6,     5,     7,     6,     4,     4,     3,     1,     4,
       3,     5,     6,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     4,     4,     3,     0,     3,
       3,     5,     5,     3,     5,     1,     3,     1,     1,     2,
       1,     2,     4,     4,     4,     4,     3,     2,     2,     1,
       5,     4,     4,     3,     2,     1,     1,     3,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 1680 "y.tab.c"
    break;

  case 3:
#line 114 "gram.y"
                            {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1690 "y.tab.c"
    break;

  case 4:
#line 119 "gram.y"
        { (yyval.data) = NULL; }
#line 1696 "y.tab.c"
    break;

  case 5:
#line 120 "gram.y"
      { (yyval.data) = NULL; }
#line 1702 "y.tab.c"
    break;

  case 6:
#line 123 "gram.y"
                        {
	(yyval.data) = (yyvsp[-1].data);
}
#line 1710 "y.tab.c"
    break;

  case 7:
#line 128 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1718 "y.tab.c"
    break;

  case 8:
#line 131 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1726 "y.tab.c"
    break;

  case 9:
#line 134 "gram.y"
                           {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1734 "y.tab.c"
    break;

  case 10:
#line 137 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1742 "y.tab.c"
    break;

  case 11:
#line 140 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1750 "y.tab.c"
    break;

  case 12:
#line 143 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1758 "y.tab.c"
    break;

  case 13:
#line 146 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1766 "y.tab.c"
    break;

  case 14:
#line 149 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1774 "y.tab.c"
    break;

  case 15:
#line 152 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1782 "y.tab.c"
    break;

  case 16:
#line 155 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1790 "y.tab.c"
    break;

  case 17:
#line 158 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1798 "y.tab.c"
    break;

  case 18:
#line 162 "gram.y"
             {}
#line 1804 "y.tab.c"
    break;

  case 19:
#line 162 "gram.y"
                  {}
#line 1810 "y.tab.c"
    break;

  case 20:
#line 164 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1818 "y.tab.c"
    break;

  case 21:
#line 166 "gram.y"
                      {
    (yyval.data) = (yyvsp[0].data);
}
#line 1826 "y.tab.c"
    break;

  case 22:
#line 171 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1834 "y.tab.c"
    break;

  case 23:
#line 176 "gram.y"
                                          {
    (yyval.data) = newForEach((yyvsp[-5].data), (yyvsp[-3].id), (yyvsp[0].data));
}
#line 1842 "y.tab.c"
    break;

  case 24:
#line 178 "gram.y"
                                            {
    (yyval.data) = newForEach((yyvsp[-5].data), (yyvsp[-3].id), (yyvsp[0].data));
}
#line 1850 "y.tab.c"
    break;

  case 25:
#line 182 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1858 "y.tab.c"
    break;

  case 26:
#line 186 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1866 "y.tab.c"
    break;

  case 27:
#line 190 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1874 "y.tab.c"
    break;

  case 28:
#line 195 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1882 "y.tab.c"
    break;

  case 29:
#line 198 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1893 "y.tab.c"
    break;

  case 30:
#line 204 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1904 "y.tab.c"
    break;

  case 31:
#line 210 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1915 "y.tab.c"
    break;

  case 32:
#line 216 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1926 "y.tab.c"
    break;

  case 33:
#line 222 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1937 "y.tab.c"
    break;

  case 34:
#line 230 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1945 "y.tab.c"
    break;

  case 35:
#line 233 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1953 "y.tab.c"
    break;

  case 36:
#line 236 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1961 "y.tab.c"
    break;

  case 37:
#line 239 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1969 "y.tab.c"
    break;

  case 38:
#line 242 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1977 "y.tab.c"
    break;

  case 39:
#line 245 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1985 "y.tab.c"
    break;

  case 40:
#line 248 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1993 "y.tab.c"
    break;

  case 41:
#line 251 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 2001 "y.tab.c"
    break;

  case 42:
#line 254 "gram.y"
             {
      expr_t *id = newExpr_ID((yyvsp[0].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
    }
#line 2011 "y.tab.c"
    break;

  case 43:
#line 259 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 2019 "y.tab.c"
    break;

  case 44:
#line 264 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2027 "y.tab.c"
    break;

  case 45:
#line 267 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2039 "y.tab.c"
    break;

  case 46:
#line 274 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2052 "y.tab.c"
    break;

  case 47:
#line 282 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2064 "y.tab.c"
    break;

  case 48:
#line 291 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2072 "y.tab.c"
    break;

  case 49:
#line 294 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2084 "y.tab.c"
    break;

  case 50:
#line 301 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2097 "y.tab.c"
    break;

  case 51:
#line 309 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2109 "y.tab.c"
    break;

  case 52:
#line 318 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2121 "y.tab.c"
    break;

  case 53:
#line 325 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2129 "y.tab.c"
    break;

  case 54:
#line 330 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2139 "y.tab.c"
    break;

  case 55:
#line 337 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2148 "y.tab.c"
    break;

  case 56:
#line 343 "gram.y"
                                  {
      (yyval.data) = newExpr_Logical((yyvsp[-4].data), NULL, (yyvsp[0].data));
    }
#line 2156 "y.tab.c"
    break;

  case 57:
#line 346 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2164 "y.tab.c"
    break;

  case 58:
#line 351 "gram.y"
                                           {
      (yyval.data) = newExpr_Logical((yyvsp[0].data), (yyvsp[-4].data), NULL);
    }
#line 2172 "y.tab.c"
    break;

  case 59:
#line 354 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2180 "y.tab.c"
    break;

  case 60:
#line 359 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2188 "y.tab.c"
    break;

  case 61:
#line 362 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2198 "y.tab.c"
    break;

  case 62:
#line 367 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2206 "y.tab.c"
    break;

  case 63:
#line 372 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2214 "y.tab.c"
    break;

  case 64:
#line 375 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2222 "y.tab.c"
    break;

  case 65:
#line 378 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2230 "y.tab.c"
    break;

  case 66:
#line 381 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2238 "y.tab.c"
    break;

  case 67:
#line 384 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2246 "y.tab.c"
    break;

  case 68:
#line 387 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2254 "y.tab.c"
    break;

  case 69:
#line 390 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2262 "y.tab.c"
    break;

  case 70:
#line 394 "gram.y"
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
#line 2299 "y.tab.c"
    break;

  case 71:
#line 428 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2307 "y.tab.c"
    break;

  case 72:
#line 431 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2315 "y.tab.c"
    break;

  case 73:
#line 436 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2323 "y.tab.c"
    break;

  case 74:
#line 439 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2331 "y.tab.c"
    break;

  case 75:
#line 442 "gram.y"
                            {
        (yyval.data) = newClassAccesser((yyvsp[-3].data), (yyvsp[0].id));
    }
#line 2339 "y.tab.c"
    break;

  case 76:
#line 448 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2348 "y.tab.c"
    break;

  case 77:
#line 452 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2357 "y.tab.c"
    break;

  case 78:
#line 456 "gram.y"
                             {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2365 "y.tab.c"
    break;

  case 79:
#line 459 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2374 "y.tab.c"
    break;

  case 80:
#line 463 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2383 "y.tab.c"
    break;

  case 81:
#line 469 "gram.y"
                      {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        expr_t *expr = newExpr_ID((yyvsp[-4].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
#line 2394 "y.tab.c"
    break;

  case 82:
#line 475 "gram.y"
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
#line 2411 "y.tab.c"
    break;

  case 83:
#line 489 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2421 "y.tab.c"
    break;

  case 84:
#line 494 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2433 "y.tab.c"
    break;

  case 85:
#line 501 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2445 "y.tab.c"
    break;

  case 86:
#line 508 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2457 "y.tab.c"
    break;

  case 87:
#line 515 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2469 "y.tab.c"
    break;

  case 88:
#line 522 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2480 "y.tab.c"
    break;

  case 89:
#line 528 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2491 "y.tab.c"
    break;

  case 90:
#line 534 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2502 "y.tab.c"
    break;

  case 91:
#line 540 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2513 "y.tab.c"
    break;

  case 92:
#line 546 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2523 "y.tab.c"
    break;

  case 93:
#line 551 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2531 "y.tab.c"
    break;

  case 94:
#line 554 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2539 "y.tab.c"
    break;

  case 95:
#line 559 "gram.y"
                                   {
      (yyval.data) = newExpr_Dictionary((yyvsp[-2].data));
    }
#line 2547 "y.tab.c"
    break;

  case 96:
#line 564 "gram.y"
                                                  {
      keyValList_t *left = (keyValList_t*)(yyvsp[-3].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2559 "y.tab.c"
    break;

  case 97:
#line 571 "gram.y"
                             {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 2567 "y.tab.c"
    break;

  case 98:
#line 574 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2575 "y.tab.c"
    break;

  case 99:
#line 579 "gram.y"
                                 {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2589 "y.tab.c"
    break;

  case 100:
#line 590 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2597 "y.tab.c"
    break;

  case 101:
#line 595 "gram.y"
                               {
      argsList_t *args = (argsList_t*) (yyvsp[-2].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2606 "y.tab.c"
    break;

  case 102:
#line 600 "gram.y"
                                 {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-2].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2615 "y.tab.c"
    break;

  case 103:
#line 604 "gram.y"
                {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2623 "y.tab.c"
    break;

  case 104:
#line 609 "gram.y"
                                       {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-4].data));
    }
#line 2632 "y.tab.c"
    break;

  case 105:
#line 613 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2640 "y.tab.c"
    break;

  case 106:
#line 618 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2650 "y.tab.c"
    break;

  case 107:
#line 623 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2659 "y.tab.c"
    break;

  case 108:
#line 629 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2667 "y.tab.c"
    break;

  case 109:
#line 632 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2676 "y.tab.c"
    break;

  case 110:
#line 636 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2684 "y.tab.c"
    break;

  case 111:
#line 639 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2693 "y.tab.c"
    break;

  case 112:
#line 645 "gram.y"
                                   {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2704 "y.tab.c"
    break;

  case 113:
#line 651 "gram.y"
                                 {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2715 "y.tab.c"
    break;

  case 114:
#line 657 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2723 "y.tab.c"
    break;

  case 115:
#line 660 "gram.y"
                                    {
      expr_t *id = (yyvsp[-3].data);
      expr_t *index = (yyvsp[-1].data);
      (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2733 "y.tab.c"
    break;

  case 116:
#line 667 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2741 "y.tab.c"
    break;

  case 117:
#line 670 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2749 "y.tab.c"
    break;

  case 118:
#line 673 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2757 "y.tab.c"
    break;

  case 119:
#line 676 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2765 "y.tab.c"
    break;

  case 120:
#line 679 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2773 "y.tab.c"
    break;

  case 121:
#line 682 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2781 "y.tab.c"
    break;

  case 122:
#line 685 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2789 "y.tab.c"
    break;

  case 123:
#line 688 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2797 "y.tab.c"
    break;

  case 124:
#line 691 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2805 "y.tab.c"
    break;

  case 125:
#line 696 "gram.y"
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
#line 2821 "y.tab.c"
    break;

  case 126:
#line 709 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2829 "y.tab.c"
    break;

  case 127:
#line 714 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2837 "y.tab.c"
    break;

  case 128:
#line 717 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2845 "y.tab.c"
    break;

  case 129:
#line 720 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2854 "y.tab.c"
    break;

  case 130:
#line 724 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2863 "y.tab.c"
    break;

  case 131:
#line 730 "gram.y"
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
#line 2896 "y.tab.c"
    break;

  case 132:
#line 758 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2904 "y.tab.c"
    break;

  case 133:
#line 763 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2912 "y.tab.c"
    break;

  case 134:
#line 766 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2924 "y.tab.c"
    break;

  case 135:
#line 773 "gram.y"
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
#line 2946 "y.tab.c"
    break;

  case 136:
#line 790 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2956 "y.tab.c"
    break;

  case 137:
#line 795 "gram.y"
              {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2966 "y.tab.c"
    break;

  case 138:
#line 800 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2974 "y.tab.c"
    break;

  case 139:
#line 805 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2983 "y.tab.c"
    break;

  case 140:
#line 810 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2992 "y.tab.c"
    break;

  case 141:
#line 815 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 3001 "y.tab.c"
    break;

  case 142:
#line 819 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3010 "y.tab.c"
    break;

  case 143:
#line 823 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3019 "y.tab.c"
    break;

  case 144:
#line 827 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3028 "y.tab.c"
    break;

  case 145:
#line 831 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3037 "y.tab.c"
    break;

  case 146:
#line 835 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3046 "y.tab.c"
    break;

  case 147:
#line 839 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3055 "y.tab.c"
    break;

  case 148:
#line 843 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3064 "y.tab.c"
    break;

  case 149:
#line 847 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3073 "y.tab.c"
    break;

  case 150:
#line 851 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3082 "y.tab.c"
    break;

  case 151:
#line 855 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3091 "y.tab.c"
    break;

  case 152:
#line 859 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3100 "y.tab.c"
    break;

  case 153:
#line 863 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3109 "y.tab.c"
    break;

  case 154:
#line 867 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3118 "y.tab.c"
    break;

  case 155:
#line 871 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3127 "y.tab.c"
    break;

  case 156:
#line 875 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3136 "y.tab.c"
    break;

  case 157:
#line 879 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3145 "y.tab.c"
    break;

  case 158:
#line 883 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3154 "y.tab.c"
    break;

  case 159:
#line 887 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3163 "y.tab.c"
    break;

  case 160:
#line 891 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3172 "y.tab.c"
    break;

  case 161:
#line 895 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3181 "y.tab.c"
    break;

  case 162:
#line 899 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3190 "y.tab.c"
    break;

  case 163:
#line 903 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3199 "y.tab.c"
    break;

  case 164:
#line 907 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3208 "y.tab.c"
    break;

  case 165:
#line 911 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3217 "y.tab.c"
    break;

  case 166:
#line 915 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3226 "y.tab.c"
    break;


#line 3230 "y.tab.c"

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
#line 920 "gram.y"


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

    /* Parse from provided command line */
    buffer = yy_scan_string(command);
    yyparse();
    yy_delete_buffer(buffer);

    if ( root != NULL ) {
        func(argc, argv, root, 0, stacksize, heapsize);
    }
}
