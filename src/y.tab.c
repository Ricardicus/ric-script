/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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


#line 109 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DIGIT = 258,                   /* DIGIT  */
    DOUBLE = 259,                  /* DOUBLE  */
    ID = 260,                      /* ID  */
    RETURN = 261,                  /* RETURN  */
    FOREACH = 262,                 /* FOREACH  */
    COMMENT = 263,                 /* COMMENT  */
    NEWLINE = 264                  /* NEWLINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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

#line 183 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DIGIT = 3,                      /* DIGIT  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_FOREACH = 7,                    /* FOREACH  */
  YYSYMBOL_COMMENT = 8,                    /* COMMENT  */
  YYSYMBOL_NEWLINE = 9,                    /* NEWLINE  */
  YYSYMBOL_10_ = 10,                       /* '='  */
  YYSYMBOL_11_ = 11,                       /* '+'  */
  YYSYMBOL_12_ = 12,                       /* '-'  */
  YYSYMBOL_13_ = 13,                       /* '*'  */
  YYSYMBOL_14_ = 14,                       /* '/'  */
  YYSYMBOL_15_ = 15,                       /* '%'  */
  YYSYMBOL_16_ = 16,                       /* '$'  */
  YYSYMBOL_17_ = 17,                       /* '.'  */
  YYSYMBOL_18_ = 18,                       /* '('  */
  YYSYMBOL_19_ = 19,                       /* ')'  */
  YYSYMBOL_20_ = 20,                       /* '@'  */
  YYSYMBOL_21_ = 21,                       /* '!'  */
  YYSYMBOL_22_ = 22,                       /* '?'  */
  YYSYMBOL_23_ = 23,                       /* '['  */
  YYSYMBOL_24_ = 24,                       /* ']'  */
  YYSYMBOL_25_ = 25,                       /* '~'  */
  YYSYMBOL_26_ = 26,                       /* '|'  */
  YYSYMBOL_27_ = 27,                       /* '&'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* ':'  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '\''  */
  YYSYMBOL_36_ = 36,                       /* '"'  */
  YYSYMBOL_37_ = 37,                       /* ' '  */
  YYSYMBOL_38_ = 38,                       /* '\\'  */
  YYSYMBOL_39_ = 39,                       /* '^'  */
  YYSYMBOL_40___ = 40,                     /* '_'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_statements = 43,                /* statements  */
  YYSYMBOL_statement_ = 44,                /* statement_  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL__ = 46,                         /* _  */
  YYSYMBOL_systemStatement = 47,           /* systemStatement  */
  YYSYMBOL_forEachStatementFull = 48,      /* forEachStatementFull  */
  YYSYMBOL_forEachStatement = 49,          /* forEachStatement  */
  YYSYMBOL_returnStatement = 50,           /* returnStatement  */
  YYSYMBOL_continueStatement = 51,         /* continueStatement  */
  YYSYMBOL_breakStatement = 52,            /* breakStatement  */
  YYSYMBOL_expressions = 53,               /* expressions  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_ifStatement = 55,               /* ifStatement  */
  YYSYMBOL_loopStatement = 56,             /* loopStatement  */
  YYSYMBOL_middleIfs = 57,                 /* middleIfs  */
  YYSYMBOL_middleIf = 58,                  /* middleIf  */
  YYSYMBOL_endIf = 59,                     /* endIf  */
  YYSYMBOL_logical_a = 60,                 /* logical_a  */
  YYSYMBOL_logical_b = 61,                 /* logical_b  */
  YYSYMBOL_logical_expression = 62,        /* logical_expression  */
  YYSYMBOL_condition = 63,                 /* condition  */
  YYSYMBOL_class = 64,                     /* class  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_classFunctionCall = 66,         /* classFunctionCall  */
  YYSYMBOL_functionCall = 67,              /* functionCall  */
  YYSYMBOL_namespacedFunctionCall = 68,    /* namespacedFunctionCall  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_dictionary = 70,                /* dictionary  */
  YYSYMBOL_dictionary_keys_vals = 71,      /* dictionary_keys_vals  */
  YYSYMBOL_dictionary_key_val = 72,        /* dictionary_key_val  */
  YYSYMBOL_body = 73,                      /* body  */
  YYSYMBOL_vector = 74,                    /* vector  */
  YYSYMBOL_arguments_list = 75,            /* arguments_list  */
  YYSYMBOL_parameters_list = 76,           /* parameters_list  */
  YYSYMBOL_mathContent = 77,               /* mathContent  */
  YYSYMBOL_indexedVector = 78,             /* indexedVector  */
  YYSYMBOL_indexer = 79,                   /* indexer  */
  YYSYMBOL_mathContentDigit = 80,          /* mathContentDigit  */
  YYSYMBOL_mathContentDouble = 81,         /* mathContentDouble  */
  YYSYMBOL_stringContent = 82,             /* stringContent  */
  YYSYMBOL_stringEditions = 83,            /* stringEditions  */
  YYSYMBOL_stringEdition = 84,             /* stringEdition  */
  YYSYMBOL_otherChar = 85                  /* otherChar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   264


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DIGIT", "DOUBLE",
  "ID", "RETURN", "FOREACH", "COMMENT", "NEWLINE", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'$'", "'.'", "'('", "')'", "'@'", "'!'", "'?'",
  "'['", "']'", "'~'", "'|'", "'&'", "'<'", "'>'", "';'", "':'", "'{'",
  "'}'", "','", "'\\''", "'\"'", "' '", "'\\\\'", "'^'", "'_'", "$accept",
  "program", "statements", "statement_", "statement", "_",
  "systemStatement", "forEachStatementFull", "forEachStatement",
  "returnStatement", "continueStatement", "breakStatement", "expressions",
  "expression", "ifStatement", "loopStatement", "middleIfs", "middleIf",
  "endIf", "logical_a", "logical_b", "logical_expression", "condition",
  "class", "function", "classFunctionCall", "functionCall",
  "namespacedFunctionCall", "declaration", "dictionary",
  "dictionary_keys_vals", "dictionary_key_val", "body", "vector",
  "arguments_list", "parameters_list", "mathContent", "indexedVector",
  "indexer", "mathContentDigit", "mathContentDouble", "stringContent",
  "stringEditions", "stringEdition", "otherChar", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
       0,     1,     2,    22,    23,   194,    24,    25,    63,    26,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: statements  */
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
#line 1566 "y.tab.c"
    break;

  case 3: /* statements: _ statement_ statements  */
#line 114 "gram.y"
                            {
        statement_t *stmt = (statement_t*)(yyvsp[-1].data);
        stmt->next = (statement_t*)(yyvsp[0].data);
        (yyval.data) = (yyvsp[-1].data);
    }
#line 1576 "y.tab.c"
    break;

  case 4: /* statements: _  */
#line 119 "gram.y"
        { (yyval.data) = NULL; }
#line 1582 "y.tab.c"
    break;

  case 5: /* statements: %empty  */
#line 120 "gram.y"
      { (yyval.data) = NULL; }
#line 1588 "y.tab.c"
    break;

  case 6: /* statement_: statement _  */
#line 123 "gram.y"
                        {
	(yyval.data) = (yyvsp[-1].data);
}
#line 1596 "y.tab.c"
    break;

  case 7: /* statement: declaration  */
#line 128 "gram.y"
                {
        (yyval.data) = newStatement(LANG_ENTITY_DECL, (yyvsp[0].data));
    }
#line 1604 "y.tab.c"
    break;

  case 8: /* statement: function  */
#line 131 "gram.y"
               {
        (yyval.data) = newStatement(LANG_ENTITY_FUNCDECL, (yyvsp[0].data));
    }
#line 1612 "y.tab.c"
    break;

  case 9: /* statement: forEachStatementFull  */
#line 134 "gram.y"
                           {
        (yyval.data) = newStatement(LANG_ENTITY_FOREACH, (yyvsp[0].data));
    }
#line 1620 "y.tab.c"
    break;

  case 10: /* statement: expressions  */
#line 137 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_EXPR, (yyvsp[0].data));
    }
#line 1628 "y.tab.c"
    break;

  case 11: /* statement: ifStatement  */
#line 140 "gram.y"
                  {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1636 "y.tab.c"
    break;

  case 12: /* statement: loopStatement  */
#line 143 "gram.y"
                    {
        (yyval.data) = newStatement(LANG_ENTITY_CONDITIONAL, (yyvsp[0].data));
    }
#line 1644 "y.tab.c"
    break;

  case 13: /* statement: continueStatement  */
#line 146 "gram.y"
                        {
        (yyval.data) = newStatement(LANG_ENTITY_CONTINUE, (yyvsp[0].data));
    }
#line 1652 "y.tab.c"
    break;

  case 14: /* statement: breakStatement  */
#line 149 "gram.y"
                     {
        (yyval.data) = newStatement(LANG_ENTITY_BREAK, (yyvsp[0].data));
    }
#line 1660 "y.tab.c"
    break;

  case 15: /* statement: returnStatement  */
#line 152 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_RETURN, (yyvsp[0].data));
    }
#line 1668 "y.tab.c"
    break;

  case 16: /* statement: systemStatement  */
#line 155 "gram.y"
                      {
        (yyval.data) = newStatement(LANG_ENTITY_SYSTEM, (yyvsp[0].data));
    }
#line 1676 "y.tab.c"
    break;

  case 17: /* statement: class  */
#line 158 "gram.y"
            {
        (yyval.data) = newStatement(LANG_ENTITY_CLASSDECL, (yyvsp[0].data));
    }
#line 1684 "y.tab.c"
    break;

  case 18: /* _: _ NEWLINE  */
#line 162 "gram.y"
             {}
#line 1690 "y.tab.c"
    break;

  case 19: /* _: %empty  */
#line 162 "gram.y"
                  {}
#line 1696 "y.tab.c"
    break;

  case 20: /* systemStatement: '$' ID  */
#line 164 "gram.y"
                        {
    (yyval.data) = newExpr_ID((yyvsp[0].id));
}
#line 1704 "y.tab.c"
    break;

  case 21: /* systemStatement: '$' stringContent  */
#line 166 "gram.y"
                      {
    (yyval.data) = (yyvsp[0].data);
}
#line 1712 "y.tab.c"
    break;

  case 22: /* forEachStatementFull: '.' forEachStatement  */
#line 171 "gram.y"
                       {
    (yyval.data) = (yyvsp[0].data);
}
#line 1720 "y.tab.c"
    break;

  case 23: /* forEachStatement: '(' expressions FOREACH ID _ ')' body  */
#line 176 "gram.y"
                                          {
    (yyval.data) = newForEach((yyvsp[-5].data), (yyvsp[-3].id), (yyvsp[0].data));
}
#line 1728 "y.tab.c"
    break;

  case 24: /* forEachStatement: '(' _ expressions FOREACH ID _ ')' body  */
#line 178 "gram.y"
                                            {
    (yyval.data) = newForEach((yyvsp[-5].data), (yyvsp[-3].id), (yyvsp[0].data));
}
#line 1736 "y.tab.c"
    break;

  case 25: /* returnStatement: RETURN expressions  */
#line 182 "gram.y"
                                    {
    (yyval.data) = (yyvsp[0].data);
}
#line 1744 "y.tab.c"
    break;

  case 26: /* continueStatement: '@'  */
#line 186 "gram.y"
                       {
    (yyval.data) = NULL;
}
#line 1752 "y.tab.c"
    break;

  case 27: /* breakStatement: '!' '@'  */
#line 190 "gram.y"
                        {
    (yyval.data) = NULL;
}
#line 1760 "y.tab.c"
    break;

  case 28: /* expressions: expression  */
#line 195 "gram.y"
               {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1768 "y.tab.c"
    break;

  case 29: /* expressions: expressions '+' _ expressions  */
#line 198 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPAdd(e1,e2);
    }
#line 1779 "y.tab.c"
    break;

  case 30: /* expressions: expressions '*' _ expressions  */
#line 204 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMul(e1,e2);
    }
#line 1790 "y.tab.c"
    break;

  case 31: /* expressions: expressions '-' _ expressions  */
#line 210 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPSub(e1,e2);
    }
#line 1801 "y.tab.c"
    break;

  case 32: /* expressions: expressions '%' _ expressions  */
#line 216 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPMod(e1,e2);
    }
#line 1812 "y.tab.c"
    break;

  case 33: /* expressions: expressions '/' _ expressions  */
#line 222 "gram.y"
                                    {
      expr_t *e1 = (expr_t*)(yyvsp[-3].data);
      expr_t *e2 = (expr_t*)(yyvsp[0].data);

      (yyval.data) = newExpr_OPDiv(e1,e2);
    }
#line 1823 "y.tab.c"
    break;

  case 34: /* expression: indexedVector  */
#line 230 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1831 "y.tab.c"
    break;

  case 35: /* expression: mathContent  */
#line 233 "gram.y"
                  {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1839 "y.tab.c"
    break;

  case 36: /* expression: dictionary  */
#line 236 "gram.y"
                 {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1847 "y.tab.c"
    break;

  case 37: /* expression: vector  */
#line 239 "gram.y"
             {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1855 "y.tab.c"
    break;

  case 38: /* expression: functionCall  */
#line 242 "gram.y"
                   {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1863 "y.tab.c"
    break;

  case 39: /* expression: classFunctionCall  */
#line 245 "gram.y"
                        {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1871 "y.tab.c"
    break;

  case 40: /* expression: stringContent  */
#line 248 "gram.y"
                    {
      (yyval.data) = (yyvsp[0].data);
    }
#line 1879 "y.tab.c"
    break;

  case 41: /* expression: ID  */
#line 251 "gram.y"
         {
      (yyval.data) = newExpr_ID((yyvsp[0].id));
    }
#line 1887 "y.tab.c"
    break;

  case 42: /* expression: '-' ID  */
#line 254 "gram.y"
             {
      expr_t *id = newExpr_ID((yyvsp[0].id));
      expr_t *neg = newExpr_Ival(-1);
      (yyval.data) = newExpr_OPMul(neg, id);
    }
#line 1897 "y.tab.c"
    break;

  case 43: /* expression: '(' expressions ')'  */
#line 259 "gram.y"
                          {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 1905 "y.tab.c"
    break;

  case 44: /* ifStatement: '?' '[' logical_a ']' body  */
#line 264 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1913 "y.tab.c"
    break;

  case 45: /* ifStatement: '?' '[' logical_a ']' body middleIfs  */
#line 267 "gram.y"
                                         {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1925 "y.tab.c"
    break;

  case 46: /* ifStatement: '?' '[' logical_a ']' body middleIfs endIf  */
#line 274 "gram.y"
                                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1938 "y.tab.c"
    break;

  case 47: /* ifStatement: '?' '[' logical_a ']' body endIf  */
#line 282 "gram.y"
                                     {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1950 "y.tab.c"
    break;

  case 48: /* loopStatement: '.' '[' logical_a ']' body  */
#line 291 "gram.y"
                               {
        (yyval.data) = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 1958 "y.tab.c"
    break;

  case 49: /* loopStatement: '.' '[' logical_a ']' body middleIfs  */
#line 294 "gram.y"
                                           {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->elif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1970 "y.tab.c"
    break;

  case 50: /* loopStatement: '.' '[' logical_a ']' body middleIfs endIf  */
#line 301 "gram.y"
                                                 {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-4].data), (yyvsp[-2].data));

        ifs->elif = (yyvsp[-1].data);
        ifs->endif = (yyvsp[0].data);
        
        (yyval.data) = ifs;
    }
#line 1983 "y.tab.c"
    break;

  case 51: /* loopStatement: '.' '[' logical_a ']' body endIf  */
#line 309 "gram.y"
                                       {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, (yyvsp[-3].data), (yyvsp[-1].data));

        ifs->endif = (yyvsp[0].data);

        (yyval.data) = ifs;
    }
#line 1995 "y.tab.c"
    break;

  case 52: /* middleIfs: middleIfs middleIf  */
#line 318 "gram.y"
                       {
        ifStmt_t *ifs1 = (ifStmt_t *) (yyvsp[-1].data);
        ifStmt_t *ifs2 = (ifStmt_t *) (yyvsp[0].data);

        ifs2->elif = ifs1;
        (yyval.data) = ifs2;
    }
#line 2007 "y.tab.c"
    break;

  case 53: /* middleIfs: middleIf  */
#line 325 "gram.y"
               {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2015 "y.tab.c"
    break;

  case 54: /* middleIf: '~' '[' logical_a ']' body  */
#line 330 "gram.y"
                               {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, (yyvsp[-2].data), (yyvsp[0].data));
       
        (yyval.data) = ifs;
    }
#line 2025 "y.tab.c"
    break;

  case 55: /* endIf: '~' body  */
#line 337 "gram.y"
             {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, (yyvsp[0].data));
        (yyval.data) = ifs;
    }
#line 2034 "y.tab.c"
    break;

  case 56: /* logical_a: logical_a '|' '|' _ logical_b  */
#line 343 "gram.y"
                                  {
      (yyval.data) = newExpr_Logical((yyvsp[-4].data), NULL, (yyvsp[0].data));
    }
#line 2042 "y.tab.c"
    break;

  case 57: /* logical_a: logical_b  */
#line 346 "gram.y"
                {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2050 "y.tab.c"
    break;

  case 58: /* logical_b: logical_b '&' '&' _ logical_expression  */
#line 351 "gram.y"
                                           {
      (yyval.data) = newExpr_Logical((yyvsp[0].data), (yyvsp[-4].data), NULL);
    }
#line 2058 "y.tab.c"
    break;

  case 59: /* logical_b: logical_expression  */
#line 354 "gram.y"
                         {
      (yyval.data) = (yyvsp[0].data);
    }
#line 2066 "y.tab.c"
    break;

  case 60: /* logical_expression: condition  */
#line 359 "gram.y"
              {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2074 "y.tab.c"
    break;

  case 61: /* logical_expression: '!' expression  */
#line 362 "gram.y"
                     {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, (yyvsp[0].data));
        (yyval.data) = cond;
    }
#line 2084 "y.tab.c"
    break;

  case 62: /* logical_expression: expression  */
#line 367 "gram.y"
                 {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2092 "y.tab.c"
    break;

  case 63: /* condition: expressions '=' '=' expressions  */
#line 372 "gram.y"
                                    {
        (yyval.data) = newConditional(CONDITION_EQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2100 "y.tab.c"
    break;

  case 64: /* condition: expressions '!' '=' expressions  */
#line 375 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_NEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2108 "y.tab.c"
    break;

  case 65: /* condition: expressions '<' '=' expressions  */
#line 378 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_LEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2116 "y.tab.c"
    break;

  case 66: /* condition: expressions '>' '=' expressions  */
#line 381 "gram.y"
                                      {
        (yyval.data) = newConditional(CONDITION_GEQ, (yyvsp[-3].data), (yyvsp[0].data));
    }
#line 2124 "y.tab.c"
    break;

  case 67: /* condition: expressions '<' expressions  */
#line 384 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_LE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2132 "y.tab.c"
    break;

  case 68: /* condition: expressions '>' expressions  */
#line 387 "gram.y"
                                  {
        (yyval.data) = newConditional(CONDITION_GE, (yyvsp[-2].data), (yyvsp[0].data));
    }
#line 2140 "y.tab.c"
    break;

  case 69: /* condition: '(' condition ')'  */
#line 390 "gram.y"
                        {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2148 "y.tab.c"
    break;

  case 70: /* class: ';' ';' ID ';' ';' body  */
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
#line 2185 "y.tab.c"
    break;

  case 71: /* function: '@' ID '(' parameters_list ')' body  */
#line 428 "gram.y"
                                        {
        (yyval.data) = newFunc((yyvsp[-4].id),(yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2193 "y.tab.c"
    break;

  case 72: /* function: '@' ID '(' ')' body  */
#line 431 "gram.y"
                        {
        (yyval.data) = newFunc((yyvsp[-3].id),NULL,(yyvsp[0].data));
    }
#line 2201 "y.tab.c"
    break;

  case 73: /* classFunctionCall: expression ':' ':' ID '(' arguments_list ')'  */
#line 436 "gram.y"
                                                 {
        (yyval.data) = newClassFunCall((yyvsp[-6].data), (yyvsp[-3].id), (yyvsp[-1].data));
    }
#line 2209 "y.tab.c"
    break;

  case 74: /* classFunctionCall: expression ':' ':' ID '(' ')'  */
#line 439 "gram.y"
                                    {
        (yyval.data) = newClassFunCall((yyvsp[-5].data), (yyvsp[-2].id), NULL);
    }
#line 2217 "y.tab.c"
    break;

  case 75: /* classFunctionCall: expression ':' ':' ID  */
#line 442 "gram.y"
                            {
        (yyval.data) = newClassAccesser((yyvsp[-3].data), (yyvsp[0].id));
    }
#line 2225 "y.tab.c"
    break;

  case 76: /* functionCall: ID '(' arguments_list ')'  */
#line 448 "gram.y"
                              {
        expr_t *id = newExpr_ID((yyvsp[-3].id));
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2234 "y.tab.c"
    break;

  case 77: /* functionCall: ID '(' ')'  */
#line 452 "gram.y"
                 {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2243 "y.tab.c"
    break;

  case 78: /* functionCall: namespacedFunctionCall  */
#line 456 "gram.y"
                             {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2251 "y.tab.c"
    break;

  case 79: /* functionCall: indexedVector '(' arguments_list ')'  */
#line 459 "gram.y"
                                           {
        expr_t *id = (expr_t*)(yyvsp[-3].data);
        (yyval.data) = newFunCall(id,(yyvsp[-1].data));
    }
#line 2260 "y.tab.c"
    break;

  case 80: /* functionCall: indexedVector '(' ')'  */
#line 463 "gram.y"
                            {
        expr_t *id = (expr_t*)(yyvsp[-2].data);
        (yyval.data) = newFunCall(id,NULL);
    }
#line 2269 "y.tab.c"
    break;

  case 81: /* namespacedFunctionCall: ID '.' ID '(' ')'  */
#line 469 "gram.y"
                      {
        expr_t *id = newExpr_ID((yyvsp[-2].id));
        expr_t *expr = newExpr_ID((yyvsp[-4].id));
        argsList_t *args = newArgument(expr, NULL);
        (yyval.data) = newFunCall(id, args);
    }
#line 2280 "y.tab.c"
    break;

  case 82: /* namespacedFunctionCall: ID '.' ID '(' arguments_list ')'  */
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
#line 2297 "y.tab.c"
    break;

  case 83: /* declaration: ID '=' expressions  */
#line 489 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2307 "y.tab.c"
    break;

  case 84: /* declaration: ID '+' '=' expressions  */
#line 494 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2319 "y.tab.c"
    break;

  case 85: /* declaration: ID '-' '=' expressions  */
#line 501 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2331 "y.tab.c"
    break;

  case 86: /* declaration: ID '*' '=' expressions  */
#line 508 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2343 "y.tab.c"
    break;

  case 87: /* declaration: ID '/' '=' expressions  */
#line 515 "gram.y"
                             {
        expr_t *idexpr = newExpr_ID((yyvsp[-3].id));
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        (yyval.data) = newDeclaration(idexpr,opadd);
    }
#line 2355 "y.tab.c"
    break;

  case 88: /* declaration: indexedVector '+' '=' expressions  */
#line 522 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPAdd((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2366 "y.tab.c"
    break;

  case 89: /* declaration: indexedVector '-' '=' expressions  */
#line 528 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPSub((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2377 "y.tab.c"
    break;

  case 90: /* declaration: indexedVector '*' '=' expressions  */
#line 534 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPMul((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2388 "y.tab.c"
    break;

  case 91: /* declaration: indexedVector '/' '=' expressions  */
#line 540 "gram.y"
                                        {
        expr_t *valexpr = (yyvsp[0].data);
        expr_t *opadd = newExpr_OPDiv((yyvsp[-3].data), valexpr);

        (yyval.data) = newDeclaration((yyvsp[-3].data),opadd);
    }
#line 2399 "y.tab.c"
    break;

  case 92: /* declaration: ID '=' condition  */
#line 546 "gram.y"
                       {
        expr_t *idexpr = newExpr_ID((yyvsp[-2].id));

        (yyval.data) = newDeclaration(idexpr,(yyvsp[0].data));
    }
#line 2409 "y.tab.c"
    break;

  case 93: /* declaration: indexedVector '=' expressions  */
#line 551 "gram.y"
                                    {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2417 "y.tab.c"
    break;

  case 94: /* declaration: indexedVector '=' condition  */
#line 554 "gram.y"
                                  {
        (yyval.data) = newDeclaration((yyvsp[-2].data),(yyvsp[0].data));
    }
#line 2425 "y.tab.c"
    break;

  case 95: /* dictionary: '{' dictionary_keys_vals _ '}'  */
#line 559 "gram.y"
                                   {
      (yyval.data) = newExpr_Dictionary((yyvsp[-2].data));
    }
#line 2433 "y.tab.c"
    break;

  case 96: /* dictionary_keys_vals: dictionary_keys_vals ',' _ dictionary_key_val  */
#line 564 "gram.y"
                                                  {
      keyValList_t *left = (keyValList_t*)(yyvsp[-3].data);
      keyValList_t *right = (keyValList_t*)(yyvsp[0].data);

      right->next = left;
      (yyval.data) = right;
    }
#line 2445 "y.tab.c"
    break;

  case 97: /* dictionary_keys_vals: _ dictionary_key_val _  */
#line 571 "gram.y"
                             {
      (yyval.data) = (yyvsp[-1].data);
    }
#line 2453 "y.tab.c"
    break;

  case 98: /* dictionary_keys_vals: %empty  */
#line 574 "gram.y"
      {
        (yyval.data) = NULL;
    }
#line 2461 "y.tab.c"
    break;

  case 99: /* dictionary_key_val: stringContent ':' expression  */
#line 579 "gram.y"
                                 {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = (yyvsp[-2].data);
      keyVal->val = (yyvsp[0].data);
      keyVal->next = NULL;

      (yyval.data) = keyVal;
    }
#line 2475 "y.tab.c"
    break;

  case 100: /* body: '{' statements '}'  */
#line 590 "gram.y"
                       {
        (yyval.data) = newBody((yyvsp[-1].data));
    }
#line 2483 "y.tab.c"
    break;

  case 101: /* vector: '[' _ arguments_list _ ']'  */
#line 595 "gram.y"
                               {
      argsList_t *args = (argsList_t*) (yyvsp[-2].data);
      (yyval.data) = newExpr_Vector(args);
    }
#line 2492 "y.tab.c"
    break;

  case 102: /* vector: '[' _ forEachStatement _ ']'  */
#line 600 "gram.y"
                                 {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, (yyvsp[-2].data));
      (yyval.data) = newExpr_VectorFromForEach(stmt);
    }
#line 2501 "y.tab.c"
    break;

  case 103: /* vector: '[' _ ']'  */
#line 604 "gram.y"
                {
      (yyval.data) = newExpr_Vector(NULL);
    }
#line 2509 "y.tab.c"
    break;

  case 104: /* arguments_list: arguments_list _ ',' _ expressions  */
#line 609 "gram.y"
                                       {
        expr_t *expr = (yyvsp[0].data);
        (yyval.data) = newArgument(expr, (yyvsp[-4].data));
    }
#line 2518 "y.tab.c"
    break;

  case 105: /* arguments_list: expressions  */
#line 613 "gram.y"
                  {
        (yyval.data) = newArgument((yyvsp[0].data), NULL);
    }
#line 2526 "y.tab.c"
    break;

  case 106: /* parameters_list: parameters_list ',' ID  */
#line 618 "gram.y"
                           {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, (yyvsp[-2].data));
    }
#line 2536 "y.tab.c"
    break;

  case 107: /* parameters_list: ID  */
#line 623 "gram.y"
         {
        expr_t *expr = newExpr_ID((yyvsp[0].id));
        (yyval.data) = newArgument(expr, NULL);
    }
#line 2545 "y.tab.c"
    break;

  case 108: /* mathContent: mathContentDouble  */
#line 629 "gram.y"
                      {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2553 "y.tab.c"
    break;

  case 109: /* mathContent: '-' mathContentDouble  */
#line 632 "gram.y"
                            {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2562 "y.tab.c"
    break;

  case 110: /* mathContent: mathContentDigit  */
#line 636 "gram.y"
                       {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2570 "y.tab.c"
    break;

  case 111: /* mathContent: '-' mathContentDigit  */
#line 639 "gram.y"
                           {
        expr_t *neg = newExpr_Ival(-1);
        (yyval.data) = newExpr_OPMul(neg, (yyvsp[0].data));
    }
#line 2579 "y.tab.c"
    break;

  case 112: /* indexedVector: expression '[' expressions ']'  */
#line 645 "gram.y"
                                   {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2590 "y.tab.c"
    break;

  case 113: /* indexedVector: expression '[' indexer ']'  */
#line 651 "gram.y"
                                 {
        expr_t *id = (yyvsp[-3].data);
        expr_t *index = (yyvsp[-1].data);

        (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2601 "y.tab.c"
    break;

  case 114: /* indexedVector: indexedVector '[' expressions ']'  */
#line 657 "gram.y"
                                        {
      (yyval.data) = newExpr_VectorIndex((yyvsp[-3].data), (yyvsp[-1].data));
    }
#line 2609 "y.tab.c"
    break;

  case 115: /* indexedVector: indexedVector '[' indexer ']'  */
#line 660 "gram.y"
                                    {
      expr_t *id = (yyvsp[-3].data);
      expr_t *index = (yyvsp[-1].data);
      (yyval.data) = newExpr_VectorIndex(id, index);
    }
#line 2619 "y.tab.c"
    break;

  case 116: /* indexer: expression ':' expression  */
#line 667 "gram.y"
                            {
    (yyval.data) = newExpr_Indexer((yyvsp[-2].data), (yyvsp[0].data), NULL);
  }
#line 2627 "y.tab.c"
    break;

  case 117: /* indexer: ':' expression  */
#line 670 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[0].data), NULL);
  }
#line 2635 "y.tab.c"
    break;

  case 118: /* indexer: expression ':'  */
#line 673 "gram.y"
                   {
    (yyval.data) = newExpr_Indexer((yyvsp[-1].data), NULL, NULL);
  }
#line 2643 "y.tab.c"
    break;

  case 119: /* indexer: ':'  */
#line 676 "gram.y"
        {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2651 "y.tab.c"
    break;

  case 120: /* indexer: expression ':' expression ':' expression  */
#line 679 "gram.y"
                                             {
    (yyval.data) = newExpr_Indexer((yyvsp[-4].data), (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2659 "y.tab.c"
    break;

  case 121: /* indexer: ':' expression ':' expression  */
#line 682 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer(NULL, (yyvsp[-2].data), (yyvsp[0].data));
  }
#line 2667 "y.tab.c"
    break;

  case 122: /* indexer: expression ':' ':' expression  */
#line 685 "gram.y"
                                  {
    (yyval.data) = newExpr_Indexer((yyvsp[-3].data), NULL, (yyvsp[0].data));
  }
#line 2675 "y.tab.c"
    break;

  case 123: /* indexer: ':' ':' expression  */
#line 688 "gram.y"
                       {
    (yyval.data) = newExpr_Indexer(NULL, NULL, (yyvsp[0].data));
  }
#line 2683 "y.tab.c"
    break;

  case 124: /* indexer: ':' ':'  */
#line 691 "gram.y"
             {
    (yyval.data) = newExpr_Indexer(NULL, NULL, NULL);
  }
#line 2691 "y.tab.c"
    break;

  case 125: /* mathContentDigit: DIGIT  */
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
#line 2707 "y.tab.c"
    break;

  case 126: /* mathContentDouble: DOUBLE  */
#line 709 "gram.y"
           {
        (yyval.data) = newExpr_Float(yyval.val_double);
    }
#line 2715 "y.tab.c"
    break;

  case 127: /* stringContent: '\'' stringEditions '\''  */
#line 714 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2723 "y.tab.c"
    break;

  case 128: /* stringContent: '"' stringEditions '"'  */
#line 717 "gram.y"
                             {
        (yyval.data) = (yyvsp[-1].data);
    }
#line 2731 "y.tab.c"
    break;

  case 129: /* stringContent: '"' '"'  */
#line 720 "gram.y"
              {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2740 "y.tab.c"
    break;

  case 130: /* stringContent: '\'' '\''  */
#line 724 "gram.y"
                {
        /* Empty text */
        (yyval.data) = newExpr_Text("");
    }
#line 2749 "y.tab.c"
    break;

  case 131: /* stringEditions: stringEditions stringEdition  */
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
#line 2782 "y.tab.c"
    break;

  case 132: /* stringEditions: stringEdition  */
#line 758 "gram.y"
                    {
        (yyval.data) = (yyvsp[0].data);
    }
#line 2790 "y.tab.c"
    break;

  case 133: /* stringEdition: ID  */
#line 763 "gram.y"
       {
        (yyval.data) = newExpr_Text(yyval.id);
    }
#line 2798 "y.tab.c"
    break;

  case 134: /* stringEdition: mathContentDouble  */
#line 766 "gram.y"
                        {
        char buffer[256];
        expr_t *e = (expr_t*)(yyvsp[0].data);
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        (yyval.data) = newExpr_Text(buffer);
        free((yyvsp[0].data));
    }
#line 2810 "y.tab.c"
    break;

  case 135: /* stringEdition: mathContentDigit  */
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
#line 2832 "y.tab.c"
    break;

  case 136: /* stringEdition: RETURN  */
#line 790 "gram.y"
             {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2842 "y.tab.c"
    break;

  case 137: /* stringEdition: FOREACH  */
#line 795 "gram.y"
              {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        (yyval.data) = newExpr_Text(buffer);
    }
#line 2852 "y.tab.c"
    break;

  case 138: /* stringEdition: otherChar  */
#line 800 "gram.y"
                {
        (yyval.data) = newExpr_Text((yyvsp[0].id));
    }
#line 2860 "y.tab.c"
    break;

  case 139: /* otherChar: '+'  */
#line 805 "gram.y"
        {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2869 "y.tab.c"
    break;

  case 140: /* otherChar: ' '  */
#line 810 "gram.y"
        {
        (yyval.id)[0] = ' ';
        (yyval.id)[1] = 0;
    }
#line 2878 "y.tab.c"
    break;

  case 141: /* otherChar: '?'  */
#line 815 "gram.y"
        {
        (yyval.id)[0] = '?';
        (yyval.id)[1] = 0;
    }
#line 2887 "y.tab.c"
    break;

  case 142: /* otherChar: '<'  */
#line 819 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2896 "y.tab.c"
    break;

  case 143: /* otherChar: '>'  */
#line 823 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2905 "y.tab.c"
    break;

  case 144: /* otherChar: '-'  */
#line 827 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2914 "y.tab.c"
    break;

  case 145: /* otherChar: '/'  */
#line 831 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2923 "y.tab.c"
    break;

  case 146: /* otherChar: '\\'  */
#line 835 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2932 "y.tab.c"
    break;

  case 147: /* otherChar: ':'  */
#line 839 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2941 "y.tab.c"
    break;

  case 148: /* otherChar: ';'  */
#line 843 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2950 "y.tab.c"
    break;

  case 149: /* otherChar: '('  */
#line 847 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2959 "y.tab.c"
    break;

  case 150: /* otherChar: ')'  */
#line 851 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2968 "y.tab.c"
    break;

  case 151: /* otherChar: '!'  */
#line 855 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2977 "y.tab.c"
    break;

  case 152: /* otherChar: ','  */
#line 859 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2986 "y.tab.c"
    break;

  case 153: /* otherChar: '\''  */
#line 863 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 2995 "y.tab.c"
    break;

  case 154: /* otherChar: '"'  */
#line 867 "gram.y"
           {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3004 "y.tab.c"
    break;

  case 155: /* otherChar: '.'  */
#line 871 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3013 "y.tab.c"
    break;

  case 156: /* otherChar: '['  */
#line 875 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3022 "y.tab.c"
    break;

  case 157: /* otherChar: ']'  */
#line 879 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3031 "y.tab.c"
    break;

  case 158: /* otherChar: '*'  */
#line 883 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3040 "y.tab.c"
    break;

  case 159: /* otherChar: '^'  */
#line 887 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3049 "y.tab.c"
    break;

  case 160: /* otherChar: '$'  */
#line 891 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3058 "y.tab.c"
    break;

  case 161: /* otherChar: '&'  */
#line 895 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3067 "y.tab.c"
    break;

  case 162: /* otherChar: '|'  */
#line 899 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3076 "y.tab.c"
    break;

  case 163: /* otherChar: '{'  */
#line 903 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3085 "y.tab.c"
    break;

  case 164: /* otherChar: '}'  */
#line 907 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3094 "y.tab.c"
    break;

  case 165: /* otherChar: '='  */
#line 911 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3103 "y.tab.c"
    break;

  case 166: /* otherChar: '_'  */
#line 915 "gram.y"
          {
        (yyval.id)[0] = yyval.id[0];
        (yyval.id)[1] = 0;
    }
#line 3112 "y.tab.c"
    break;


#line 3116 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 920 "gram.y"


#include <stdlib.h>
#include <string.h>
#include "hooks.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse(void);
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void initParser(void) {
    setParser(yyparse);
    setRoot(&root);
}

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, int stacksize, int heapsize, const char *prompt) {
    char lineBuffer[256];

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    while ( readCommand(lineBuffer, sizeof(lineBuffer), prompt) != NULL ) {
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
