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
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

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
       0,   103,   103,   120,   125,   129,   132,   135,   138,   141,
     144,   147,   150,   153,   156,   159,   163,   165,   170,   185,
     189,   193,   198,   201,   207,   213,   219,   225,   233,   236,
     239,   242,   245,   248,   251,   254,   257,   262,   265,   272,
     280,   289,   292,   299,   307,   316,   323,   328,   335,   341,
     344,   349,   352,   357,   360,   365,   370,   373,   376,   379,
     382,   385,   389,   426,   429,   434,   437,   442,   446,   450,
     454,   460,   465,   470,   473,   478,   483,   490,   493,   498,
     508,   520,   525,   530,   534,   539,   543,   548,   553,   559,
     562,   566,   569,   575,   581,   586,   591,   596,   602,   608,
     618,   628,   634,   640,   645,   648,   651,   655,   661,   689,
     694,   697,   704,   711,   716,   721,   726,   731,   735,   739,
     743,   747,   751,   755,   759,   763,   767,   771,   775,   779,
     783,   787,   791,   795,   799,   803,   807,   811,   815,   819
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
  "mathContentDigit", "mathContentDouble", "stringContents",
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

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     356,  -171,  -171,    97,   504,   115,     6,   504,    32,    29,
      62,    99,    49,   105,   128,   176,   221,   147,  -171,   356,
    -171,  -171,  -171,  -171,  -171,   155,   122,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   120,  -171,  -171,
    -171,   504,   370,   504,    48,   504,   155,    66,  -171,  -171,
    -171,     2,  -171,   137,   399,   164,  -171,   399,  -171,   130,
     155,    -7,   199,   151,  -171,    19,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,    53,  -171,
    -171,  -171,  -171,  -171,  -171,   266,  -171,  -171,  -171,   121,
     311,  -171,  -171,   504,   504,   504,   504,   504,   170,   504,
     413,   504,    65,  -171,  -171,   -12,    45,   209,    52,   111,
     190,  -171,   504,    65,   114,   118,   182,  -171,  -171,     9,
     154,  -171,  -171,   504,   200,  -171,   128,   504,    53,  -171,
     121,   212,   212,  -171,  -171,  -171,   232,    65,  -171,  -171,
     -11,   104,   226,   231,   442,   471,  -171,  -171,  -171,  -171,
    -171,  -171,   223,   230,  -171,   236,   122,   234,   242,   243,
    -171,   234,    20,   234,   155,   239,  -171,   155,     2,  -171,
     254,  -171,  -171,   504,   504,   504,   155,   504,   155,   275,
     356,   248,   399,   399,  -171,   234,   277,   248,   234,   496,
     155,   155,   155,   155,   256,   253,    30,   248,  -171,  -171,
     182,  -171,  -171,  -171,   248,  -171,  -171,  -171,    33,   234,
    -171,   399,  -171,  -171,  -171,  -171,  -171,  -171,   241,   234,
    -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    95,    96,    35,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    78,     0,     0,     0,     2,     4,
      14,    10,    13,    11,    12,     7,    22,     8,     9,    15,
       6,    33,    32,     5,    30,    31,    29,    28,    91,    89,
      34,     0,     0,     0,    35,     0,    19,    28,    92,    90,
      16,    17,   103,     0,     0,     0,    21,     0,    84,     0,
      86,     0,     0,     0,    77,     0,   110,   113,   139,   115,
     120,   134,   121,   136,   125,   131,   126,   127,   117,   132,
     133,   138,   137,   118,   119,   124,   123,   128,   107,   130,
     116,   122,   135,   112,   111,     0,   109,   114,   129,   106,
       0,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    68,     0,     0,     0,     0,     0,
       0,    36,     0,     0,    22,     0,    50,    52,    53,     0,
       0,    83,    82,     0,     0,    75,     0,     0,   104,   108,
     105,    23,    25,    24,    27,    26,     0,    73,    74,    70,
       0,     0,     0,     0,     0,     0,    67,    93,    98,   100,
      99,    97,     0,   102,   101,     0,    54,     0,     0,     0,
      88,     0,     0,     0,    85,     0,    76,    79,    80,    34,
       0,    69,    94,     0,     0,     0,    60,     0,    61,     0,
       4,    41,     0,     0,    64,     0,     0,    37,     0,     0,
      56,    57,    58,    59,     0,     0,     0,    42,    46,    44,
      49,    51,    63,    87,    38,    40,    62,    66,     0,     0,
      81,     0,    48,    45,    43,    39,    65,    18,     0,     0,
      47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,   -17,  -171,  -171,   287,  -171,  -171,  -171,     0,
     -51,  -171,  -171,    92,  -168,  -170,   -52,   126,   113,   -31,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   171,  -147,  -171,
     -34,  -171,  -171,     1,    13,    17,     7,     3,   303,    34,
    -171
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,   123,
      26,    27,    28,   207,   208,   209,   125,   126,   127,   128,
      29,    30,    31,    32,    33,    34,    63,    64,   191,    35,
      61,   172,    36,    47,    38,    39,    65,    40,    95,    96,
      97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    37,   102,   124,    46,   130,   124,    53,   115,    52,
     113,    50,    60,    51,   170,   156,   181,    52,    48,    25,
      37,   118,    49,   119,   194,   132,   197,   215,    93,    93,
     133,   133,    94,    94,    55,   133,   171,   224,   118,   223,
     119,   112,    60,   116,   225,   117,   223,   195,   212,    15,
      16,   216,     1,     2,    44,     1,     2,   158,   137,   222,
     226,   221,   196,    54,   103,   104,   105,   106,   107,     5,
     190,   166,   227,    42,     7,   133,   150,   157,   148,    43,
      12,    58,   230,   152,   103,   104,   105,   106,   107,    14,
      56,   110,    15,    16,   153,    15,    16,   111,  -129,  -129,
    -129,   154,   155,   141,   142,   143,   144,   145,    93,   147,
      60,   151,    94,    93,     1,    41,   162,    94,     1,     2,
     163,   161,    42,   103,   104,   105,   106,   107,    43,   139,
      57,   159,   164,   174,   139,   160,   182,   177,   109,    52,
     179,   124,   124,    62,   178,   110,   -55,   101,   -55,   -55,
     167,   111,   168,   108,   186,   188,   103,   104,   105,   106,
     107,   108,   131,   120,   121,   218,  -130,  -130,  -130,   228,
     124,    15,    16,   205,   103,   104,   105,   106,   107,     1,
       2,    66,    67,   200,   201,   202,   173,   203,   168,   129,
      25,    37,   135,   136,    68,    69,    70,    71,    72,    60,
      73,    74,    75,    76,   134,    77,    78,    79,    80,   146,
      81,    82,    83,    84,    85,    86,   165,   169,    87,    88,
      89,    90,    91,    92,     1,     2,    66,    67,   103,   104,
     105,   106,   107,   105,   106,   107,   121,   180,   175,    68,
      69,    70,    71,    72,   183,    73,    74,    75,    76,   184,
      77,    78,    79,    80,    43,    81,    82,    83,    84,    85,
      86,   111,   189,    87,    98,    99,    90,    91,    92,     1,
       2,    66,    67,   229,   190,   168,   192,   198,   193,   199,
     204,   206,   213,   219,    68,    69,    70,    71,    72,   214,
      73,    74,    75,    76,   220,    77,    78,    79,    80,    59,
      81,    82,    83,    84,    85,    86,   211,   176,    87,   138,
      89,    90,    91,    92,     1,     2,    66,    67,   210,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    73,    74,    75,    76,     0,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,     0,     0,    87,    98,   140,    90,    91,    92,     1,
       2,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,    44,     5,     0,     0,     0,
       6,     7,     8,     0,     9,    10,    11,    12,     0,     0,
       5,     0,     0,     0,    13,    45,    14,   114,     0,    15,
      16,    12,     1,     2,    44,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,     1,     2,    44,     5,
       0,     0,     0,     0,    45,     0,     0,     0,   122,     0,
      12,     0,     0,     5,     0,     0,     0,     0,    45,    14,
     149,     0,    15,    16,    12,     1,     2,    44,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,     0,
     185,     0,     5,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    12,     1,     2,    44,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,     0,   187,
       0,     5,     0,     0,     0,     0,    45,     0,     0,     1,
       2,    44,    12,     0,     0,     0,     0,     1,     2,    44,
       0,    14,     0,     0,    15,    16,     5,     0,     0,     0,
       0,    45,     0,   217,     5,     0,     0,    12,     0,    45,
       0,     0,     0,     0,     0,    12,    14,     0,     0,    15,
      16,     0,     0,     0,    14,     0,     0,    15,    16
};

static const yytype_int16 yycheck[] =
{
       0,     0,    19,    54,     4,    57,    57,     7,    42,     6,
      41,     5,    12,     6,     5,    27,    27,    14,     5,    19,
      19,    19,     5,    21,   171,    32,   173,   197,    15,    16,
      42,    42,    15,    16,     5,    42,    27,   207,    19,   207,
      21,    41,    42,    43,   214,    45,   214,    27,   195,    43,
      44,   198,     3,     4,     5,     3,     4,     5,    39,   206,
      27,    31,    42,    31,    19,    20,    21,    22,    23,    20,
      40,   122,   219,    25,    25,    42,   110,    32,   109,    31,
      31,    32,   229,    18,    19,    20,    21,    22,    23,    40,
      28,    25,    43,    44,    29,    43,    44,    31,    45,    46,
      47,    36,    37,   103,   104,   105,   106,   107,    95,   109,
     110,   111,    95,   100,     3,    18,     5,   100,     3,     4,
     119,   118,    25,    19,    20,    21,    22,    23,    31,    95,
      31,   118,   119,   133,   100,   118,    32,   137,    18,   136,
     137,   192,   193,    38,   137,    25,    32,     0,    34,    35,
      32,    31,    34,    39,   154,   155,    19,    20,    21,    22,
      23,    39,    32,    26,    27,   199,    45,    46,    47,   221,
     221,    43,    44,   190,    19,    20,    21,    22,    23,     3,
       4,     5,     6,   183,   184,   185,    32,   187,    34,    25,
     190,   190,    41,    42,    18,    19,    20,    21,    22,   199,
      24,    25,    26,    27,     5,    29,    30,    31,    32,    39,
      34,    35,    36,    37,    38,    39,    26,    35,    42,    43,
      44,    45,    46,    47,     3,     4,     5,     6,    19,    20,
      21,    22,    23,    21,    22,    23,    27,     5,    38,    18,
      19,    20,    21,    22,    18,    24,    25,    26,    27,    18,
      29,    30,    31,    32,    31,    34,    35,    36,    37,    38,
      39,    31,    26,    42,    43,    44,    45,    46,    47,     3,
       4,     5,     6,    32,    40,    34,    34,    38,    35,    25,
       5,    33,     5,    27,    18,    19,    20,    21,    22,   197,
      24,    25,    26,    27,    41,    29,    30,    31,    32,    12,
      34,    35,    36,    37,    38,    39,   193,   136,    42,    43,
      44,    45,    46,    47,     3,     4,     5,     6,   192,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    44,    45,    46,    47,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    20,    -1,    -1,    -1,
      24,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      20,    -1,    -1,    -1,    38,    25,    40,    27,    -1,    43,
      44,    31,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    44,    -1,     3,     4,     5,    20,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    40,
      27,    -1,    43,    44,    31,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    31,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    44,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,     3,
       4,     5,    31,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    40,    -1,    -1,    43,    44,    20,    -1,    -1,    -1,
      -1,    25,    -1,    27,    20,    -1,    -1,    31,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    40,    -1,    -1,    43,
      44,    -1,    -1,    -1,    40,    -1,    -1,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    24,    25,    26,    28,
      29,    30,    31,    38,    40,    43,    44,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    68,
      69,    70,    71,    72,    73,    77,    80,    81,    82,    83,
      85,    18,    25,    31,     5,    25,    57,    81,    82,    83,
       5,    84,    85,    57,    31,     5,    28,    31,    32,    53,
      57,    78,    38,    74,    75,    84,     5,     6,    18,    19,
      20,    21,    22,    24,    25,    26,    27,    29,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    42,    43,    44,
      45,    46,    47,    82,    83,    86,    87,    88,    43,    44,
      86,     0,    50,    19,    20,    21,    22,    23,    39,    18,
      25,    31,    57,    67,    27,    78,    57,    57,    19,    21,
      26,    27,    29,    57,    58,    64,    65,    66,    67,    25,
      64,    32,    32,    42,     5,    41,    42,    39,    43,    87,
      44,    57,    57,    57,    57,    57,    39,    57,    67,    27,
      78,    57,    18,    29,    36,    37,    27,    32,     5,    82,
      83,    85,     5,    81,    82,    26,    58,    32,    34,    35,
       5,    27,    79,    32,    57,    38,    75,    57,    84,    85,
       5,    27,    32,    18,    18,    18,    57,    18,    57,    26,
      40,    76,    34,    35,    76,    27,    42,    76,    38,    25,
      57,    57,    57,    57,     5,    50,    33,    61,    62,    63,
      65,    66,    76,     5,    61,    63,    76,    27,    78,    27,
      41,    31,    76,    62,    63,    63,    27,    76,    64,    32,
      76
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
      67,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    74,    74,    74,    75,
      75,    76,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    83,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88
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
       3,     3,     6,     6,     5,     7,     6,     4,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     0,     3,
       3,     3,     3,     3,     2,     3,     1,     3,     1,     1,
       2,     1,     2,     4,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 103 "gram.y"
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
#line 1617 "y.tab.c"
    break;

  case 3:
#line 120 "gram.y"
                         {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1627 "y.tab.c"
    break;

  case 4:
#line 125 "gram.y"
      { (yyval.data) = NULL; }
#line 1633 "y.tab.c"
    break;

  case 5:
#line 129 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1641 "y.tab.c"
    break;

  case 6:
#line 132 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1649 "y.tab.c"
    break;

  case 7:
#line 135 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1657 "y.tab.c"
    break;

  case 8:
#line 138 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1665 "y.tab.c"
    break;

  case 9:
#line 141 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1673 "y.tab.c"
    break;

  case 10:
#line 144 "gram.y"
                       {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1681 "y.tab.c"
    break;

  case 11:
#line 147 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1689 "y.tab.c"
    break;

  case 12:
#line 150 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1697 "y.tab.c"
    break;

  case 13:
#line 153 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1705 "y.tab.c"
    break;

  case 14:
#line 156 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1713 "y.tab.c"
    break;

  case 15:
#line 159 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1721 "y.tab.c"
    break;

  case 16:
#line 163 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1729 "y.tab.c"
    break;

  case 17:
#line 165 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1737 "y.tab.c"
    break;

  case 18:
#line 170 "gram.y"
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
#line 1756 "y.tab.c"
    break;

  case 19:
#line 185 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1764 "y.tab.c"
    break;

  case 20:
#line 189 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1772 "y.tab.c"
    break;

  case 21:
#line 193 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1780 "y.tab.c"
    break;

  case 22:
#line 198 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1788 "y.tab.c"
    break;

  case 23:
#line 201 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1799 "y.tab.c"
    break;

  case 24:
#line 207 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1810 "y.tab.c"
    break;

  case 25:
#line 213 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1821 "y.tab.c"
    break;

  case 26:
#line 219 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1832 "y.tab.c"
    break;

  case 27:
#line 225 "gram.y"
                                  {
      expr_t *e1 = (expr_t*)(yyvsp[-2].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1843 "y.tab.c"
    break;

  case 28:
#line 233 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1851 "y.tab.c"
    break;

  case 29:
#line 236 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1859 "y.tab.c"
    break;

  case 30:
#line 239 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1867 "y.tab.c"
    break;

  case 31:
#line 242 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1875 "y.tab.c"
    break;

  case 32:
#line 245 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1883 "y.tab.c"
    break;

  case 33:
#line 248 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1891 "y.tab.c"
    break;

  case 34:
#line 251 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1899 "y.tab.c"
    break;

  case 35:
#line 254 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1907 "y.tab.c"
    break;

  case 36:
#line 257 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1915 "y.tab.c"
    break;

  case 37:
#line 262 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1923 "y.tab.c"
    break;

  case 38:
#line 265 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1935 "y.tab.c"
    break;

  case 39:
#line 272 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1948 "y.tab.c"
    break;

  case 40:
#line 280 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1960 "y.tab.c"
    break;

  case 41:
#line 289 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1968 "y.tab.c"
    break;

  case 42:
#line 292 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1980 "y.tab.c"
    break;

  case 43:
#line 299 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1993 "y.tab.c"
    break;

  case 44:
#line 307 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 2005 "y.tab.c"
    break;

  case 45:
#line 316 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2017 "y.tab.c"
    break;

  case 46:
#line 323 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2025 "y.tab.c"
    break;

  case 47:
#line 328 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2035 "y.tab.c"
    break;

  case 48:
#line 335 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2044 "y.tab.c"
    break;

  case 49:
#line 341 "gram.y"
                                {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), NULL, (yyvsp[0].data));
    }
#line 2052 "y.tab.c"
    break;

  case 50:
#line 344 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2060 "y.tab.c"
    break;

  case 51:
#line 349 "gram.y"
                                         {
      (yyval.data) = newExpr_Logical((yyvsp[-3].data), (yyvsp[0].data), NULL);
    }
#line 2068 "y.tab.c"
    break;

  case 52:
#line 352 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2076 "y.tab.c"
    break;

  case 53:
#line 357 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2084 "y.tab.c"
    break;

  case 54:
#line 360 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2094 "y.tab.c"
    break;

  case 55:
#line 365 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2102 "y.tab.c"
    break;

  case 56:
#line 370 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2110 "y.tab.c"
    break;

  case 57:
#line 373 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2118 "y.tab.c"
    break;

  case 58:
#line 376 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2126 "y.tab.c"
    break;

  case 59:
#line 379 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2134 "y.tab.c"
    break;

  case 60:
#line 382 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2142 "y.tab.c"
    break;

  case 61:
#line 385 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2150 "y.tab.c"
    break;

  case 62:
#line 389 "gram.y"
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
#line 2190 "y.tab.c"
    break;

  case 63:
#line 426 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2198 "y.tab.c"
    break;

  case 64:
#line 429 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2206 "y.tab.c"
    break;

  case 65:
#line 434 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2214 "y.tab.c"
    break;

  case 66:
#line 437 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2222 "y.tab.c"
    break;

  case 67:
#line 442 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2231 "y.tab.c"
    break;

  case 68:
#line 446 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2240 "y.tab.c"
    break;

  case 69:
#line 450 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2249 "y.tab.c"
    break;

  case 70:
#line 454 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2258 "y.tab.c"
    break;

  case 71:
#line 460 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2268 "y.tab.c"
    break;

  case 72:
#line 465 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2278 "y.tab.c"
    break;

  case 73:
#line 470 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2286 "y.tab.c"
    break;

  case 74:
#line 473 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2294 "y.tab.c"
    break;

  case 75:
#line 478 "gram.y"
                                 {
      (yyval.data) = newExpr_Dictionary((yyvsp[-1].data));
    }
#line 2302 "y.tab.c"
    break;

  case 76:
#line 483 "gram.y"
                                                {
      keyValList_t *left = (keyValList_t*)(yyvsp[-2].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2314 "y.tab.c"
    break;

  case 77:
#line 490 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2322 "y.tab.c"
    break;

  case 78:
#line 493 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2330 "y.tab.c"
    break;

  case 79:
#line 498 "gram.y"
                                   {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2345 "y.tab.c"
    break;

  case 80:
#line 508 "gram.y"
                                        {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->entity = EXPR_TYPE_DICT;
      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2360 "y.tab.c"
    break;

  case 81:
#line 520 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2368 "y.tab.c"
    break;

  case 82:
#line 525 "gram.y"
                           {
      argsList_t *args = (argsList_t*) (yyvsp[-1].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2377 "y.tab.c"
    break;

  case 83:
#line 530 "gram.y"
                             {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-1].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2386 "y.tab.c"
    break;

  case 84:
#line 534 "gram.y"
              {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2394 "y.tab.c"
    break;

  case 85:
#line 539 "gram.y"
                                   {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2403 "y.tab.c"
    break;

  case 86:
#line 543 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2411 "y.tab.c"
    break;

  case 87:
#line 548 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2421 "y.tab.c"
    break;

  case 88:
#line 553 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2430 "y.tab.c"
    break;

  case 89:
#line 559 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2438 "y.tab.c"
    break;

  case 90:
#line 562 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2447 "y.tab.c"
    break;

  case 91:
#line 566 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2455 "y.tab.c"
    break;

  case 92:
#line 569 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2464 "y.tab.c"
    break;

  case 93:
#line 575 "gram.y"
                           {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2475 "y.tab.c"
    break;

  case 94:
#line 581 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2483 "y.tab.c"
    break;

  case 95:
#line 586 "gram.y"
          {
        (yyval.data) = newExpr_Ival(yyval.val_int);
    }
#line 2491 "y.tab.c"
    break;

  case 96:
#line 591 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2499 "y.tab.c"
    break;

  case 97:
#line 596 "gram.y"
                                     {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2510 "y.tab.c"
    break;

  case 98:
#line 602 "gram.y"
                             {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = newExpr_ID((yyvsp[0].id));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2521 "y.tab.c"
    break;

  case 99:
#line 608 "gram.y"
                                            {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.4f", d->fval);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2536 "y.tab.c"
    break;

  case 100:
#line 618 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *d = (expr_t*)(yyvsp[0].data);
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", d->ival);
        expr_t *e2 = newExpr_Text(buffer);
        free((yyvsp[0].data));

        (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 2551 "y.tab.c"
    break;

  case 101:
#line 628 "gram.y"
                                           {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2562 "y.tab.c"
    break;

  case 102:
#line 634 "gram.y"
                                        {
        expr_t *e1 = (expr_t*)(yyvsp[-2].data);
        expr_t *e2 = (expr_t*)(yyvsp[0].data);

        (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 2573 "y.tab.c"
    break;

  case 103:
#line 640 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2581 "y.tab.c"
    break;

  case 104:
#line 645 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2589 "y.tab.c"
    break;

  case 105:
#line 648 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2597 "y.tab.c"
    break;

  case 106:
#line 651 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2606 "y.tab.c"
    break;

  case 107:
#line 655 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2615 "y.tab.c"
    break;

  case 108:
#line 661 "gram.y"
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
#line 2648 "y.tab.c"
    break;

  case 109:
#line 689 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2656 "y.tab.c"
    break;

  case 110:
#line 694 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2664 "y.tab.c"
    break;

  case 111:
#line 697 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2676 "y.tab.c"
    break;

  case 112:
#line 704 "gram.y"
                       {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%d", e->ival);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2688 "y.tab.c"
    break;

  case 113:
#line 711 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2698 "y.tab.c"
    break;

  case 114:
#line 716 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2706 "y.tab.c"
    break;

  case 115:
#line 721 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2715 "y.tab.c"
    break;

  case 116:
#line 726 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2724 "y.tab.c"
    break;

  case 117:
#line 731 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2733 "y.tab.c"
    break;

  case 118:
#line 735 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2742 "y.tab.c"
    break;

  case 119:
#line 739 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2751 "y.tab.c"
    break;

  case 120:
#line 743 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2760 "y.tab.c"
    break;

  case 121:
#line 747 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2769 "y.tab.c"
    break;

  case 122:
#line 751 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2778 "y.tab.c"
    break;

  case 123:
#line 755 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2787 "y.tab.c"
    break;

  case 124:
#line 759 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2796 "y.tab.c"
    break;

  case 125:
#line 763 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2805 "y.tab.c"
    break;

  case 126:
#line 767 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2814 "y.tab.c"
    break;

  case 127:
#line 771 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2823 "y.tab.c"
    break;

  case 128:
#line 775 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2832 "y.tab.c"
    break;

  case 129:
#line 779 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2841 "y.tab.c"
    break;

  case 130:
#line 783 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2850 "y.tab.c"
    break;

  case 131:
#line 787 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2859 "y.tab.c"
    break;

  case 132:
#line 791 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2868 "y.tab.c"
    break;

  case 133:
#line 795 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2877 "y.tab.c"
    break;

  case 134:
#line 799 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2886 "y.tab.c"
    break;

  case 135:
#line 803 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2895 "y.tab.c"
    break;

  case 136:
#line 807 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2904 "y.tab.c"
    break;

  case 137:
#line 811 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2913 "y.tab.c"
    break;

  case 138:
#line 815 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2922 "y.tab.c"
    break;

  case 139:
#line 819 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2931 "y.tab.c"
    break;


#line 2935 "y.tab.c"

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
#line 824 "gram.y"


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
