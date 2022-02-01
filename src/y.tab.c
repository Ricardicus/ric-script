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
#define YYFINAL  106
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

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
       2,     2,    46,    29,    45,     2,    25,    24,    36,    44,
      26,    27,    22,    20,    43,    21,    33,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    39,
      37,    19,    38,    30,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,    47,    32,    48,     2,     2,     2,     2,     2,
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
       0,   104,   104,   121,   126,   130,   133,   136,   139,   142,
     145,   148,   151,   154,   157,   160,   164,   166,   171,   175,
     179,   183,   188,   191,   197,   203,   209,   215,   223,   226,
     229,   232,   235,   238,   241,   244,   247,   252,   255,   262,
     270,   279,   282,   289,   297,   306,   313,   318,   325,   331,
     334,   339,   342,   347,   350,   355,   360,   363,   366,   369,
     372,   375,   378,   382,   419,   422,   427,   430,   435,   439,
     443,   447,   453,   458,   465,   472,   479,   486,   492,   498,
     504,   510,   515,   518,   523,   528,   535,   538,   543,   554,
     559,   564,   568,   573,   577,   582,   587,   593,   596,   600,
     603,   609,   615,   621,   626,   629,   632,   635,   638,   641,
     644,   647,   650,   655,   664,   669,   672,   675,   679,   685,
     713,   718,   721,   728,   743,   748,   753,   758,   763,   768,
     772,   776,   780,   784,   788,   792,   796,   800,   804,   808,
     812,   816,   820,   824,   828,   832,   836,   840,   844,   848,
     852,   856,   860,   864
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
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'$'", "'('", "')'", "'@'",
  "'!'", "'?'", "'['", "']'", "'.'", "'~'", "'|'", "'&'", "'<'", "'>'",
  "';'", "':'", "'{'", "'}'", "','", "'\\''", "'\"'", "' '", "'\\\\'",
  "'^'", "$accept", "program", "statements", "statement",
  "systemStatement", "forEachStatement", "returnStatement",
  "continueStatement", "breakStatement", "expressions", "expression",
  "ifStatement", "loopStatement", "middleIfs", "middleIf", "endIf",
  "logical_a", "logical_b", "logical_expression", "condition", "class",
  "function", "classFunctionCall", "functionCall", "declaration",
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
      43,    45,    42,    47,    37,    36,    40,    41,    64,    33,
      63,    91,    93,    46,   126,   124,    38,    60,    62,    59,
      58,   123,   125,    44,    39,    34,    32,    92,    94
};
# endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,  -213,  -213,   274,   650,   116,     5,   650,    40,    28,
      42,    33,    76,    78,   174,   239,   285,    79,  -213,   153,
    -213,  -213,  -213,  -213,  -213,   167,    12,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   111,  -213,  -213,
    -213,   675,   128,   143,   145,   154,   423,   117,   650,   167,
      64,  -213,  -213,  -213,  -213,    48,   149,  -213,   430,  -213,
     148,   167,   -19,   430,   188,   185,  -213,   155,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,   124,  -213,  -213,  -213,  -213,  -213,  -213,
     331,  -213,  -213,  -213,   157,   377,  -213,  -213,   650,   650,
     650,   650,   650,   473,   161,   675,   193,   195,   201,   204,
     479,   650,   675,   212,  -213,   650,   650,   650,   650,  -213,
     -15,   319,   221,  -213,     4,   650,   212,    61,   -17,   202,
    -213,  -213,  -213,  -213,   650,   -10,   198,  -213,   174,   650,
     124,  -213,   157,   184,   184,  -213,  -213,  -213,   504,    82,
     105,   207,   235,   212,  -213,   650,   650,   650,   650,  -213,
     -13,   131,    62,   220,   229,   232,   533,   562,   167,   167,
     167,   167,  -213,   225,  -213,   214,    -1,    12,   214,   228,
     231,   167,   214,   217,  -213,   167,   650,   108,  -213,   568,
    -213,   247,   167,   167,   167,   167,  -213,  -213,  -213,   650,
     650,   650,   167,   650,   167,   214,   153,  -213,   214,   293,
     265,   430,   430,   265,   214,    12,   593,   681,   129,   618,
     167,   167,   167,   167,  -213,   259,  -213,  -213,    57,   265,
    -213,  -213,   202,  -213,   265,  -213,  -213,    12,   276,    12,
     593,  -213,     8,  -213,   430,  -213,  -213,  -213,  -213,   625,
      12,  -213,    25,  -213,    19,   214,  -213,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   113,   114,    35,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     2,     4,
      14,     7,    13,    11,    12,     8,    22,     9,    10,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    99,    97,
      34,     0,     0,     0,     0,     0,     0,    35,     0,    19,
      28,   100,    98,    16,    17,     0,     0,    21,     0,    92,
       0,    94,     0,     0,     0,     0,    86,     0,   121,   124,
     125,   153,   127,   132,   146,   133,   148,   137,   138,   139,
     129,   144,   145,   143,   150,   149,   130,   131,   136,   135,
     151,   152,   140,   118,   142,   128,   134,   147,   123,   122,
       0,   120,   126,   141,   117,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    81,     0,     0,     0,     0,    69,
       0,     0,     0,    36,     0,     0,     0,    22,     0,    50,
      52,    53,    91,    90,     0,     0,     0,    84,     0,     0,
     115,   119,   116,    23,    25,    24,    27,    26,   107,     0,
      22,     0,     0,    82,    83,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    68,     0,    96,     0,     0,    54,     0,     0,
       0,    93,     0,     0,    85,    88,   112,   105,   101,   106,
     102,     0,    77,    78,    79,    80,    70,   103,    62,     0,
       0,     0,    60,     0,    61,     0,     4,    65,     0,     0,
      37,     0,     0,    41,     0,   111,     0,     0,   104,     0,
      56,    57,    58,    59,    18,     0,    64,    95,     0,    38,
      46,    40,    49,    51,    42,    44,    63,   109,    35,   110,
       0,    67,     0,    89,     0,    48,    45,    39,    43,     0,
     108,    66,     0,    67,     0,     0,    66,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,   -16,  -213,  -213,   292,  -213,  -213,  -213,     0,
       3,  -213,  -213,    86,  -104,  -212,   -58,    92,    97,   -35,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   196,  -171,  -213,
     -44,  -213,  -213,     1,  -213,    18,    24,     2,   329,    41,
    -213
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    61,
      26,    27,    28,   239,   240,   241,   138,   139,   140,   141,
      29,    30,    31,    32,    33,    34,    65,    66,   217,    35,
      62,   186,    36,    50,   161,    38,    39,    40,   100,   101,
     102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,   130,   107,    49,   145,   124,    55,    54,   184,
      53,   245,   182,   143,   206,   188,    67,   220,   189,    25,
      37,   223,   192,    51,   144,   189,   218,   257,   144,    52,
     144,   185,   258,    98,    98,   261,     1,     2,    47,    99,
      99,   123,   219,   113,   234,    56,   266,   236,   131,    15,
      16,   144,   114,   246,     5,   132,    57,   265,   136,     7,
     189,   137,   144,   136,    11,    59,   137,   255,   108,   109,
     110,   111,   112,    58,    14,   133,   170,    15,    16,   106,
     164,   174,   108,   109,   110,   111,   112,   173,   254,   133,
     120,   175,   113,   -55,   267,   121,   -55,   -55,   216,   176,
     177,   114,   108,   109,   110,   111,   112,    63,   153,   154,
     155,   156,   157,   159,   198,   163,   160,    64,    98,     1,
       2,   171,   172,    98,    99,   178,   179,   180,   181,    99,
     115,   116,   117,   118,   119,   256,   113,   120,   187,   113,
     256,   151,   121,    46,   191,   199,   151,   125,   226,   195,
      67,   108,   109,   110,   111,   112,     1,     2,     3,     4,
     113,   197,   126,   207,   127,   202,   203,   204,   205,   250,
    -141,  -141,  -141,   128,     5,   134,   212,   214,     6,     7,
     142,     8,     9,    10,    11,   252,    12,   108,   109,   110,
     111,   112,    13,   146,    14,   149,   262,    15,    16,   225,
     235,   162,   228,  -142,  -142,  -142,   110,   111,   112,   230,
     231,   232,   165,   233,   166,   264,    25,    37,    15,    16,
     167,   136,   136,   168,   137,   137,   183,   147,   148,   247,
     249,   174,   108,   109,   110,   111,   112,   193,   190,   200,
     201,   175,     1,     2,    68,    69,    70,   208,   209,   176,
     177,   210,   215,   260,   136,   216,   224,   137,    71,    72,
      73,    74,    75,   221,    76,    77,    78,   222,    79,    80,
      81,    82,    83,   229,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     1,     2,
      68,    69,    70,    41,    42,    43,    44,    45,   237,   238,
      46,   253,   259,    60,    71,    72,    73,    74,    75,   244,
      76,    77,    78,   242,    79,    80,    81,    82,    83,   243,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   103,
     104,    95,    96,    97,     1,     2,    68,    69,    70,   108,
     109,   110,   111,   112,   194,   105,   133,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   150,    94,    95,    96,    97,
       1,     2,    68,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   103,   152,    95,    96,    97,     1,     2,    47,     0,
       0,     0,     0,     1,     2,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,    48,
     129,     5,     0,     0,    11,     0,   122,     0,     0,   135,
       0,    11,     0,     0,    14,     0,     0,    15,    16,     0,
       0,    14,     0,     0,    15,    16,     1,     2,    47,     0,
       0,     0,     1,     2,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,    48,
       5,     0,     0,     0,    11,    48,   169,     1,     2,    47,
      11,     0,     0,   158,    14,     0,     0,    15,    16,     0,
      14,     0,     0,    15,    16,     5,     0,     0,     0,     0,
      48,     0,     0,     0,     0,    11,     1,     2,    47,     0,
       0,     0,     0,     0,   196,    14,     0,     0,    15,    16,
       0,     0,   211,     0,     5,     0,     0,     0,     0,    48,
       0,     0,     0,     0,    11,     1,     2,    47,     0,     0,
       0,     1,     2,    47,    14,     0,     0,    15,    16,     0,
       0,   213,     0,     5,     0,     0,     0,     0,    48,     5,
       0,     0,     0,    11,    48,     0,     1,     2,    47,    11,
       0,     0,     0,    14,     0,     0,    15,    16,   227,    14,
       0,     0,    15,    16,     5,     0,     0,     0,     0,    48,
       0,     1,     2,    47,    11,     0,     0,     0,     1,     2,
      47,     0,     0,   162,    14,     0,     0,    15,    16,     5,
       0,     0,     0,     0,    48,   251,     5,     0,     0,    11,
       0,    48,   263,     1,     2,    47,    11,     0,     0,    14,
       0,     0,    15,    16,     0,     0,    14,     0,     0,    15,
      16,     5,     0,     0,     0,     0,    48,     0,     1,     2,
      47,    11,     0,     0,     1,     2,   248,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     5,     0,     0,     0,
       0,   122,     5,     0,     0,     0,    11,    48,     0,     0,
       0,     0,    11,     0,     0,     0,    14,     0,     0,    15,
      16,     0,    14,     0,     0,    15,    16
};

static const yytype_int16 yycheck[] =
{
       0,     0,    46,    19,     4,    63,    41,     7,     6,     5,
       5,   223,    27,    32,    27,    32,    14,   188,    35,    19,
      19,   192,    32,     5,    43,    35,    27,   239,    43,     5,
      43,    27,   244,    15,    16,    27,     3,     4,     5,    15,
      16,    41,    43,    31,   215,     5,    27,   218,    48,    44,
      45,    43,    40,   224,    21,     7,    28,    32,    58,    26,
      35,    58,    43,    63,    31,    32,    63,   238,    20,    21,
      22,    23,    24,    31,    41,    27,   120,    44,    45,     0,
     115,    19,    20,    21,    22,    23,    24,   122,    31,    27,
      26,    29,    31,    32,   265,    31,    35,    36,    41,    37,
      38,    40,    20,    21,    22,    23,    24,    31,   108,   109,
     110,   111,   112,   113,    32,   115,   113,    39,   100,     3,
       4,   121,   122,   105,   100,   125,   126,   127,   128,   105,
      19,    20,    21,    22,    23,   239,    31,    26,   135,    31,
     244,   100,    31,    26,   144,    40,   105,    19,    40,   149,
     148,    20,    21,    22,    23,    24,     3,     4,     5,     6,
      31,   158,    19,    32,    19,   165,   166,   167,   168,    40,
      46,    47,    48,    19,    21,    26,   176,   177,    25,    26,
      32,    28,    29,    30,    31,   229,    33,    20,    21,    22,
      23,    24,    39,     5,    41,    40,   254,    44,    45,   196,
     216,    40,   199,    46,    47,    48,    22,    23,    24,   209,
     210,   211,    19,   213,    19,   259,   216,   216,    44,    45,
      19,   221,   222,    19,   221,   222,     5,    42,    43,   226,
     227,    19,    20,    21,    22,    23,    24,    39,    36,    32,
       5,    29,     3,     4,     5,     6,     7,    27,    19,    37,
      38,    19,    27,   250,   254,    41,    39,   254,    19,    20,
      21,    22,    23,    35,    25,    26,    27,    36,    29,    30,
      31,    32,    33,    26,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     3,     4,
       5,     6,     7,    19,    20,    21,    22,    23,     5,    34,
      26,    42,    26,    11,    19,    20,    21,    22,    23,   223,
      25,    26,    27,   221,    29,    30,    31,    32,    33,   222,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,     4,     5,     6,     7,    20,
      21,    22,    23,    24,   148,    16,    27,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     3,     4,     5,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,
      27,    21,    -1,    -1,    31,    -1,    26,    -1,    -1,    29,
      -1,    31,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      -1,    41,    -1,    -1,    44,    45,     3,     4,     5,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,
      21,    -1,    -1,    -1,    31,    26,    27,     3,     4,     5,
      31,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    -1,
      41,    -1,    -1,    44,    45,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    31,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    31,     3,     4,     5,    -1,    -1,
      -1,     3,     4,     5,    41,    -1,    -1,    44,    45,    -1,
      -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,    21,
      -1,    -1,    -1,    31,    26,    -1,     3,     4,     5,    31,
      -1,    -1,    -1,    41,    -1,    -1,    44,    45,    40,    41,
      -1,    -1,    44,    45,    21,    -1,    -1,    -1,    -1,    26,
      -1,     3,     4,     5,    31,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    21,
      -1,    -1,    -1,    -1,    26,    27,    21,    -1,    -1,    31,
      -1,    26,    27,     3,     4,     5,    31,    -1,    -1,    41,
      -1,    -1,    44,    45,    -1,    -1,    41,    -1,    -1,    44,
      45,    21,    -1,    -1,    -1,    -1,    26,    -1,     3,     4,
       5,    31,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    45,    21,    -1,    -1,    -1,
      -1,    26,    21,    -1,    -1,    -1,    31,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    41,    -1,    -1,    44,
      45,    -1,    41,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    25,    26,    28,    29,
      30,    31,    33,    39,    41,    44,    45,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    69,
      70,    71,    72,    73,    74,    78,    81,    82,    84,    85,
      86,    19,    20,    21,    22,    23,    26,     5,    26,    58,
      82,    84,    85,     5,    86,    58,     5,    28,    31,    32,
      54,    58,    79,    31,    39,    75,    76,    86,     5,     6,
       7,    19,    20,    21,    22,    23,    25,    26,    27,    29,
      30,    31,    32,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    84,    85,
      87,    88,    89,    44,    45,    87,     0,    51,    20,    21,
      22,    23,    24,    31,    40,    19,    20,    21,    22,    23,
      26,    31,    26,    58,    68,    19,    19,    19,    19,    27,
      79,    58,     7,    27,    26,    29,    58,    59,    65,    66,
      67,    68,    32,    32,    43,    65,     5,    42,    43,    40,
      44,    88,    45,    58,    58,    58,    58,    58,    40,    58,
      59,    83,    40,    58,    68,    19,    19,    19,    19,    27,
      79,    58,    58,    68,    19,    29,    37,    38,    58,    58,
      58,    58,    27,     5,     5,    27,    80,    59,    32,    35,
      36,    58,    32,    39,    76,    58,    40,    59,    32,    40,
      32,     5,    58,    58,    58,    58,    27,    32,    27,    19,
      19,    19,    58,    19,    58,    27,    41,    77,    27,    43,
      77,    35,    36,    77,    39,    59,    40,    40,    59,    26,
      58,    58,    58,    58,    77,    51,    77,     5,    34,    62,
      63,    64,    66,    67,    62,    64,    77,    59,     5,    59,
      40,    27,    79,    42,    31,    77,    63,    64,    64,    26,
      59,    27,    65,    27,    79,    32,    27,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    75,    75,    76,    77,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    85,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     6,     2,
       1,     2,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     6,     7,
       6,     5,     6,     7,     6,     2,     1,     5,     2,     4,
       1,     4,     1,     1,     2,     1,     4,     4,     4,     4,
       3,     3,     3,     6,     6,     5,     7,     6,     4,     3,
       4,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       3,     3,     2,     3,     1,     3,     1,     1,     2,     1,
       2,     4,     4,     4,     3,     2,     2,     1,     5,     4,
       4,     3,     2,     1,     1,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 1670 "y.tab.c"
    break;

  case 3:
#line 121 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1680 "y.tab.c"
    break;

  case 4:
#line 126 "gram.y"
      { (yyval.data) = NULL; }
#line 1686 "y.tab.c"
    break;

  case 5:
#line 130 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1694 "y.tab.c"
    break;

  case 6:
#line 133 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1702 "y.tab.c"
    break;

  case 7:
#line 136 "gram.y"
                       {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1710 "y.tab.c"
    break;

  case 8:
#line 139 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1718 "y.tab.c"
    break;

  case 9:
#line 142 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1726 "y.tab.c"
    break;

  case 10:
#line 145 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1734 "y.tab.c"
    break;

  case 11:
#line 148 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1742 "y.tab.c"
    break;

  case 12:
#line 151 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1750 "y.tab.c"
    break;

  case 13:
#line 154 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1758 "y.tab.c"
    break;

  case 14:
#line 157 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1766 "y.tab.c"
    break;

  case 15:
#line 160 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1774 "y.tab.c"
    break;

  case 16:
#line 164 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1782 "y.tab.c"
    break;

  case 17:
#line 166 "gram.y"
                      {
    (yyval.data) = (yyvsp[0].data);
}
#line 1790 "y.tab.c"
    break;

  case 18:
#line 171 "gram.y"
                                        {
    (yyval.data) = newForEach((yyvsp[-4].data), (yyvsp[-2].id), (yyvsp[0].data));
}
#line 1798 "y.tab.c"
    break;

  case 19:
#line 175 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1806 "y.tab.c"
    break;

  case 20:
#line 179 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1814 "y.tab.c"
    break;

  case 21:
#line 183 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1822 "y.tab.c"
    break;

  case 22:
#line 188 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1830 "y.tab.c"
    break;

  case 23:
#line 191 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1841 "y.tab.c"
    break;

  case 24:
#line 197 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1852 "y.tab.c"
    break;

  case 25:
#line 203 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1863 "y.tab.c"
    break;

  case 26:
#line 209 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1874 "y.tab.c"
    break;

  case 27:
#line 215 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1885 "y.tab.c"
    break;

  case 28:
#line 223 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1893 "y.tab.c"
    break;

  case 29:
#line 226 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1901 "y.tab.c"
    break;

  case 30:
#line 229 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1909 "y.tab.c"
    break;

  case 31:
#line 232 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1917 "y.tab.c"
    break;

  case 32:
#line 235 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1925 "y.tab.c"
    break;

  case 33:
#line 238 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1933 "y.tab.c"
    break;

  case 34:
#line 241 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1941 "y.tab.c"
    break;

  case 35:
#line 244 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1949 "y.tab.c"
    break;

  case 36:
#line 247 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1957 "y.tab.c"
    break;

  case 37:
#line 252 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1965 "y.tab.c"
    break;

  case 38:
#line 255 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1977 "y.tab.c"
    break;

  case 39:
#line 262 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1990 "y.tab.c"
    break;

  case 40:
#line 270 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2002 "y.tab.c"
    break;

  case 41:
#line 279 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2010 "y.tab.c"
    break;

  case 42:
#line 282 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2022 "y.tab.c"
    break;

  case 43:
#line 289 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 2035 "y.tab.c"
    break;

  case 44:
#line 297 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2047 "y.tab.c"
    break;

  case 45:
#line 306 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2059 "y.tab.c"
    break;

  case 46:
#line 313 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2067 "y.tab.c"
    break;

  case 47:
#line 318 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2077 "y.tab.c"
    break;

  case 48:
#line 325 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2086 "y.tab.c"
    break;

  case 49:
#line 331 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2094 "y.tab.c"
    break;

  case 50:
#line 334 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2102 "y.tab.c"
    break;

  case 51:
#line 339 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2110 "y.tab.c"
    break;

  case 52:
#line 342 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2118 "y.tab.c"
    break;

  case 53:
#line 347 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2126 "y.tab.c"
    break;

  case 54:
#line 350 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2136 "y.tab.c"
    break;

  case 55:
#line 355 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2144 "y.tab.c"
    break;

  case 56:
#line 360 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2152 "y.tab.c"
    break;

  case 57:
#line 363 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2160 "y.tab.c"
    break;

  case 58:
#line 366 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2168 "y.tab.c"
    break;

  case 59:
#line 369 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2176 "y.tab.c"
    break;

  case 60:
#line 372 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2184 "y.tab.c"
    break;

  case 61:
#line 375 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2192 "y.tab.c"
    break;

  case 62:
#line 378 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2200 "y.tab.c"
    break;

  case 63:
#line 382 "gram.y"
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
#line 2240 "y.tab.c"
    break;

  case 64:
#line 419 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2248 "y.tab.c"
    break;

  case 65:
#line 422 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2256 "y.tab.c"
    break;

  case 66:
#line 427 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2264 "y.tab.c"
    break;

  case 67:
#line 430 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2272 "y.tab.c"
    break;

  case 68:
#line 435 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2281 "y.tab.c"
    break;

  case 69:
#line 439 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2290 "y.tab.c"
    break;

  case 70:
#line 443 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2299 "y.tab.c"
    break;

  case 71:
#line 447 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2308 "y.tab.c"
    break;

  case 72:
#line 453 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2318 "y.tab.c"
    break;

  case 73:
#line 458 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2330 "y.tab.c"
    break;

  case 74:
#line 465 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2342 "y.tab.c"
    break;

  case 75:
#line 472 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2354 "y.tab.c"
    break;

  case 76:
#line 479 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2366 "y.tab.c"
    break;

  case 77:
#line 486 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2377 "y.tab.c"
    break;

  case 78:
#line 492 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2388 "y.tab.c"
    break;

  case 79:
#line 498 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2399 "y.tab.c"
    break;

  case 80:
#line 504 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2410 "y.tab.c"
    break;

  case 81:
#line 510 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2420 "y.tab.c"
    break;

  case 82:
#line 515 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2428 "y.tab.c"
    break;

  case 83:
#line 518 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2436 "y.tab.c"
    break;

  case 84:
#line 523 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2444 "y.tab.c"
    break;

  case 85:
#line 528 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2456 "y.tab.c"
    break;

  case 86:
#line 535 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2464 "y.tab.c"
    break;

  case 87:
#line 538 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2472 "y.tab.c"
    break;

  case 88:
#line 543 "gram.y"
                                  {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2486 "y.tab.c"
    break;

  case 89:
#line 554 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2494 "y.tab.c"
    break;

  case 90:
#line 559 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2503 "y.tab.c"
    break;

  case 91:
#line 564 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2512 "y.tab.c"
    break;

  case 92:
#line 568 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2520 "y.tab.c"
    break;

  case 93:
#line 573 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2529 "y.tab.c"
    break;

  case 94:
#line 577 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2537 "y.tab.c"
    break;

  case 95:
#line 582 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2547 "y.tab.c"
    break;

  case 96:
#line 587 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2556 "y.tab.c"
    break;

  case 97:
#line 593 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2564 "y.tab.c"
    break;

  case 98:
#line 596 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2573 "y.tab.c"
    break;

  case 99:
#line 600 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2581 "y.tab.c"
    break;

  case 100:
#line 603 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2590 "y.tab.c"
    break;

  case 101:
#line 609 "gram.y"
                                   {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2601 "y.tab.c"
    break;

  case 102:
#line 615 "gram.y"
                                 {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2612 "y.tab.c"
    break;

  case 103:
#line 621 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2620 "y.tab.c"
    break;

  case 104:
#line 626 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2628 "y.tab.c"
    break;

  case 105:
#line 629 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2636 "y.tab.c"
    break;

  case 106:
#line 632 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2644 "y.tab.c"
    break;

  case 107:
#line 635 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2652 "y.tab.c"
    break;

  case 108:
#line 638 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2660 "y.tab.c"
    break;

  case 109:
#line 641 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2668 "y.tab.c"
    break;

  case 110:
#line 644 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2676 "y.tab.c"
    break;

  case 111:
#line 647 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2684 "y.tab.c"
    break;

  case 112:
#line 650 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2692 "y.tab.c"
    break;

  case 113:
#line 655 "gram.y"
          {
      if ( strlen(yyval.id) >= 10 ) {
        (yyval.data) = newExpr_BigIntFromStr(yyval.id);
      } else {
        (yyval.data) = newExpr_Ival(atoi(yyval.id));
      }
    }
#line 2704 "y.tab.c"
    break;

  case 114:
#line 664 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2712 "y.tab.c"
    break;

  case 115:
#line 669 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2720 "y.tab.c"
    break;

  case 116:
#line 672 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2728 "y.tab.c"
    break;

  case 117:
#line 675 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2737 "y.tab.c"
    break;

  case 118:
#line 679 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2746 "y.tab.c"
    break;

  case 119:
#line 685 "gram.y"
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
#line 2779 "y.tab.c"
    break;

  case 120:
#line 713 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2787 "y.tab.c"
    break;

  case 121:
#line 718 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2795 "y.tab.c"
    break;

  case 122:
#line 721 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2807 "y.tab.c"
    break;

  case 123:
#line 728 "gram.y"
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
#line 2827 "y.tab.c"
    break;

  case 124:
#line 743 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2837 "y.tab.c"
    break;

  case 125:
#line 748 "gram.y"
              {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2847 "y.tab.c"
    break;

  case 126:
#line 753 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2855 "y.tab.c"
    break;

  case 127:
#line 758 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2864 "y.tab.c"
    break;

  case 128:
#line 763 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2873 "y.tab.c"
    break;

  case 129:
#line 768 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2882 "y.tab.c"
    break;

  case 130:
#line 772 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2891 "y.tab.c"
    break;

  case 131:
#line 776 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2900 "y.tab.c"
    break;

  case 132:
#line 780 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2909 "y.tab.c"
    break;

  case 133:
#line 784 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2918 "y.tab.c"
    break;

  case 134:
#line 788 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2927 "y.tab.c"
    break;

  case 135:
#line 792 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2936 "y.tab.c"
    break;

  case 136:
#line 796 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2945 "y.tab.c"
    break;

  case 137:
#line 800 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2954 "y.tab.c"
    break;

  case 138:
#line 804 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2963 "y.tab.c"
    break;

  case 139:
#line 808 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2972 "y.tab.c"
    break;

  case 140:
#line 812 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2981 "y.tab.c"
    break;

  case 141:
#line 816 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2990 "y.tab.c"
    break;

  case 142:
#line 820 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2999 "y.tab.c"
    break;

  case 143:
#line 824 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3008 "y.tab.c"
    break;

  case 144:
#line 828 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3017 "y.tab.c"
    break;

  case 145:
#line 832 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3026 "y.tab.c"
    break;

  case 146:
#line 836 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3035 "y.tab.c"
    break;

  case 147:
#line 840 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3044 "y.tab.c"
    break;

  case 148:
#line 844 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3053 "y.tab.c"
    break;

  case 149:
#line 848 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3062 "y.tab.c"
    break;

  case 150:
#line 852 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3071 "y.tab.c"
    break;

  case 151:
#line 856 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3080 "y.tab.c"
    break;

  case 152:
#line 860 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3089 "y.tab.c"
    break;

  case 153:
#line 864 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3098 "y.tab.c"
    break;


#line 3102 "y.tab.c"

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
#line 869 "gram.y"


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
