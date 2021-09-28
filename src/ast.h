#ifndef SCRIPT_SIMPLE_AST_H
#define SCRIPT_SIMPLE_AST_H

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/* the big integers library, mini-gmp */
#include <mini-gmp.h>

#include "hashtable.h"

#ifndef BIT
#define BIT(x) ((1)<<((x)-1))
#endif

#define xstr(s) str(s)
#define str(s) #s

#define EXPR_TYPE_ID             1
#define EXPR_TYPE_FVAL           2
#define EXPR_TYPE_IVAL           3
#define EXPR_TYPE_UVAL           4
#define EXPR_TYPE_TEXT           5
#define EXPR_TYPE_EMPTY          6
#define EXPR_TYPE_OPADD          7
#define EXPR_TYPE_OPSUB          8
#define EXPR_TYPE_OPDIV          9
#define EXPR_TYPE_OPMOD          10
#define EXPR_TYPE_OPMUL          11
#define EXPR_TYPE_COND           12
#define EXPR_TYPE_FUNCCALL       13
#define EXPR_TYPE_POINTER        14
#define EXPR_TYPE_FUNCPTR        15
#define EXPR_TYPE_VECTOR         16
#define EXPR_TYPE_VECTOR_IDX     17
#define EXPR_TYPE_LIBFUNCPTR     18
#define EXPR_TYPE_DICT           19
#define EXPR_TYPE_CLASSPTR       20
#define EXPR_TYPE_CLASSFUNCCALL  21
#define EXPR_TYPE_TIME           22
#define EXPR_TYPE_RAWDATA        23
#define EXPR_TYPE_LOGICAL        24
#define EXPR_TYPE_INDEXER        25
#define EXPR_TYPE_BIGINT         26

#define LANG_ENTITY_DECL         1
#define LANG_ENTITY_ARGS         2
#define LANG_ENTITY_FUNCDECL     3
#define LANG_ENTITY_STATEMENT    4
#define LANG_ENTITY_BODY         5
#define LANG_ENTITY_FUNCCALL     6
#define LANG_ENTITY_CONDITIONAL  7
#define LANG_ENTITY_CONDITION    8
#define LANG_ENTITY_EMPTY_MATH   9
#define LANG_ENTITY_EMPTY_STR    10
#define LANG_ENTITY_BREAK        11
#define LANG_ENTITY_CONTINUE     12
#define LANG_ENTITY_FIN          13
#define LANG_ENTITY_SYSTEM       14
#define LANG_ENTITY_RETURN       15
#define LANG_ENTITY_EXPR         16
#define LANG_ENTITY_BODY_END     17
#define LANG_ENTITY_CLASSDECL    18
#define LANG_ENTITY_FOREACH      19

#define LANG_CONDITIONAL_IF      BIT(1)
#define LANG_CONDITIONAL_ELIF    BIT(2)
#define LANG_CONDITIONAL_ELSE    BIT(3)
#define LANG_CONDITIONAL_CTX     BIT(4)

#define FUNC_CALL_TYPE_GLOBAL         0
#define FUNC_CALL_TYPE_CLASS          1

#define CONDITION_EQ             0
#define CONDITION_NEQ            1
#define CONDITION_LEQ            2
#define CONDITION_GEQ            3
#define CONDITION_GE             4
#define CONDITION_LE             5

#define DICTIONARY_STANDARD_SIZE 1024
#define DICTIONARY_STANDARD_LOAD 0.8

// Max number of input arguments
#define MAX_NBR_ARGUMENTS    10
// Max number of locals that can be defined at the same time
#define MAX_NBR_LOCALS       1000
// Maximum body depth
#define MAX_BODY_LEVELS      30  // If you need more; I am sorry.
// Number of elements on the stack of this interpreter (arbitrary number?)
#define RIC_STACKSIZE        1024
// Number of elements on the heap of this interpreter (arbitrary number?)
#define RIC_HEAPSIZE         4096
// maximum number of variables in the langauge, need to be known by current
// garbage collector algorithm (making a list of all active)
#define RIC_MAX_NBR_VARS     4096
// Big integers max size (in character width base 10)
#define RIC_BIG_INT_MAX_SIZE 4096

#define GENERAL_ERROR_ISSUE_URL  "https://github.com/Ricardicus/ric-script"
#define GENERAL_REPORT_ISSUE_MSG() do {\
        fprintf(stderr, "Please include the script and file an error report to me here:\n");\
        fprintf(stderr, "    - %s\n", GENERAL_ERROR_ISSUE_URL);\
        exit(1);\
} while (0);

#define NON_INTERACTIVE        0
#define INTERACTIVE_PRINT      BIT(1)
#define INTERACTIVE_STACK      BIT(2)

typedef struct ID_s {
  char *id;
} ID_t;

typedef struct addOP {
  void* left;
  void* right;
} addOP_t;

typedef struct subOP {
  void* left;
  void* right;
} subOP_t;

typedef struct mulOP {
  void* left;
  void* right;
} mulOP_t;

typedef struct divOP {
  void* left;
  void* right;
} divOP_t;

typedef struct modOP {
  void* left;
  void* right;
} modOP_t;

typedef struct ifCondition {
  int type;
  void *left;
  void *right;
} ifCondition_t;

// Forward declarations
struct argsList;
typedef struct argsList argsList_t;
struct expr_s;
typedef struct expr_s expr_t;
struct libFunction;
typedef struct libFunction libFunction_t;
struct keyValList;
typedef struct keyValList keyValList_t;
struct class_t;
typedef struct class_t class_t;
struct rawdata_t;
typedef struct rawdata_t rawdata_t;
struct logical_t;
typedef struct logical_t logical_t;
struct statement_s;
typedef struct statement_s statement_t;

typedef struct vector_t {
  int32_t length;
  argsList_t *content;
  statement_t *forEach;
} vector_t;

typedef struct vectorIndex {
  expr_t *id;
  expr_t *index;
} vectorIndex_t;

typedef struct indexer_t {
  expr_t *left;
  expr_t *right;
  expr_t *offset;
} indexer_t;

typedef struct logical_t {
  int32_t andsLen;
  expr_t **ands;
  int32_t orsLen;
  expr_t **ors;
} logical_t;

#define RIC_DICTIONARY_AST 0
#define RIC_DICTIONARY_DYN 1

typedef struct dictionary {
  int initialized;
  keyValList_t *keyVals;
  hashtable_t *hash;
  int type;
} dictionary_t;

typedef struct expr_s {
  int type;

  union {
    ID_t          id;
    char          *text;
    double        fval;
    int32_t       ival;
    uint32_t      uval;
    addOP_t       add;
    subOP_t       sub;
    mulOP_t       mul;
    divOP_t       div;
    modOP_t       mod;
    ifCondition_t *cond;
    void          *func;
    uintptr_t     p;
    vector_t      *vec;
    vectorIndex_t *vecIdx;
    dictionary_t  *dict;
    class_t       *classObj;
    time_t        time;
    rawdata_t     *rawdata;
    logical_t     *logical;
    indexer_t     *indexer;
    mpz_t         *bigInt;
  };
} expr_t;

typedef struct declaration_s {
	expr_t *id;
	expr_t *val;
} declaration_t;

typedef struct argsList {
  unsigned int length;
  expr_t *arg;
  struct argsList *next;
} argsList_t;

typedef struct keyValList {
  expr_t *key;
  expr_t *val;
  struct keyValList *next;
} keyValList_t;

typedef struct statement_s {
  int entity;
  int line;
  char file[25];
  void *content;
  struct statement_s *next;
} statement_t;

typedef struct class_t {
  char *id;
  int initialized;
  statement_t *defines;
  hashtable_t *funcDefs;
  hashtable_t *varMembers;
} class_t;

typedef struct body_s {
  int entity;
  struct statement_s *content;
} body_t;

typedef struct functionDef {
  int entity;
  ID_t id;
  argsList_t *params;
  statement_t *body;
} functionDef_t;

typedef struct forEachStmt {
  int entity;
  expr_t *root;
  expr_t *entry;
  body_t *body;
  char *uniqueUnfoldID;
} forEachStmt_t;

typedef struct functionCall_t {
  int entity;
  expr_t *id;
  argsList_t *args;
} functionCall_t;

typedef struct rawdata_t {
  void *data;
  size_t size;
} rawdata_t;

typedef struct classFunctionCall {
  expr_t *classID;
  char   *funcID;
  argsList_t *args;
} classFunctionCall_t;

typedef struct functionCallContainer {
  int type;
  union {
    functionCall_t *globalCall;
    classFunctionCall_t *classCall;
  };
} functionCallContainer_t;

typedef struct ifStmt {
  int ifType;
  void *elif;
  void *endif;
  body_t *body;
  expr_t *cond;
} ifStmt_t;

typedef struct entity_eval {
  int entity;
} entity_eval_t;

void* ast_emalloc(size_t size);
void* ast_ecalloc(size_t size);
void* ast_remalloc(void *mem, size_t size);

expr_t* newExpr_Text(char *text);
expr_t* newExpr_Ival(int val);
expr_t* newExpr_Time(time_t time);
expr_t* newExpr_Uval(unsigned val);
expr_t* newExpr_Float(double val);
expr_t* newExpr_ID(char *id);
expr_t* newExpr_Pointer(uintptr_t val);
expr_t* newExpr_FuncPtr(void *func);
expr_t* newExpr_RawData(size_t size);
expr_t* newExpr_Dictionary(keyValList_t *keyVals);
expr_t* newExpr_FuncCall(functionCall_t *func);
expr_t* newExpr_LibFuncPtr(libFunction_t *func);
expr_t* newExpr_OPAdd(expr_t *left, expr_t *right);
expr_t* newExpr_OPSub(expr_t *left, expr_t *right);
expr_t* newExpr_OPMul(expr_t *left, expr_t *right);
expr_t* newExpr_OPMod(expr_t *left, expr_t *right);
expr_t* newExpr_OPDiv(expr_t *left, expr_t *right);
expr_t* newExpr_Cond(ifCondition_t *cond);
expr_t* newExpr_Vector(argsList_t *args);
expr_t* newExpr_VectorFromForEach(statement_t *stmt);
expr_t* newExpr_ClassPtr(class_t *class);
expr_t* newExpr_ClassPtrCopy(class_t *class);
expr_t* newExpr_VectorIndex(expr_t *id, expr_t *index);
expr_t* newExpr_Copy(expr_t *exp);
expr_t* newExpr_Logical(expr_t *prevLogical, expr_t *newAnd, expr_t *newOr);
expr_t* newExpr_Indexer(expr_t *left, expr_t *right, expr_t *offset);
expr_t* newExpr_BigIntFromStr(const char *intStr);
expr_t* newExpr_BigIntFromInt(intptr_t val);
expr_t* newExpr_BigInt(mpz_t *n);

expr_t*         newConditional(int type, expr_t *left, expr_t *right);
declaration_t*  newDeclaration(expr_t *id, expr_t *exp);
statement_t*    newStatement(int type, void *content);
argsList_t*     newArgument(expr_t *exp, void *next);
ifStmt_t*       newIfStatement(int ifType, void *cond, void *body);
functionDef_t*  newFunc(const char *id, void *args, void *body);
forEachStmt_t*  newForEach(expr_t *root, char *entry, void *body);
expr_t*         newFunCall(expr_t *id, void *args);
expr_t*         newClassFunCall(expr_t *classID, char *funcID, void *args);
body_t*         newBody(void *body);
class_t*        newClass(char *id, body_t *body);

argsList_t*     copy_argsList(argsList_t *args);

void print_statements(statement_t *root);
void interpret_statements(int argc, char *argv[], statement_t *stmt);
void interpret_statements_interactive(int argc, char *argv[], statement_t *stmt, int teardown);
void free_expression(expr_t *expr);
void free_keyvals(dictionary_t *dict);

typedef enum stackvaltypes {
  INT32TYPE = 1,
  DOUBLETYPE,
  TEXT,
  POINTERTYPE,
  FUNCPTRTYPE,
  LIBFUNCPTRTYPE,
  VECTORTYPE,
  DICTTYPE,
  CLASSTYPE,
  TIMETYPE,
  RAWDATATYPE,
  INDEXER,
  BIGINT
} stackvaltypes_t;

typedef struct stackval {
  stackvaltypes_t type;
  union {
    double d;
    int32_t i;
    char *t;
    uintptr_t p;
    functionDef_t *func;
    vector_t *vec;
    libFunction_t *libfunc;
    dictionary_t *dict;
    class_t *classObj;
    time_t time;
    rawdata_t *rawdata;
    indexer_t *indexer;
    mpz_t *bigInt;
  };
} stackval_t;

typedef struct heapval {
  stackval_t sv;
  bool occupied;
  bool toFree;
  uint32_t mark;
} heapval_t;

typedef struct local {
  char *id;
  heapval_t *hpv;
} local_t;

typedef struct locals_stack {
  local_t stack[MAX_NBR_LOCALS];
  hashtable_t *localDecs;
  int sp;
  int sb;
} locals_stack_t;

/* Context provider/container structure */
typedef struct context_full_t {
  int32_t *r0;
  int32_t *r1;
  int32_t *r2;
  int32_t *ax;
  double *f0;
  double *f1;
  double *f2;
  void *sp;
  void *sb;
  void *hp;
  void *hb;
  void **st;
  void **ed;
  size_t *sc;
  int *depth;
  locals_stack_t *varLocals;
  int32_t *interactive;
  class_t *classCtx;
  void *syncCtx;
  hashtable_t *classDecs;
  hashtable_t *funcDecs;
  hashtable_t *varDecs;
} context_full_t;

#define DEF_NEW_CONTEXT() context_full_t exeCtx; int32_t r0, r1, r2, ax; double f0, f1, f2; void *sp, *sb, *hp, *hb; void *st, *ed; \
size_t sc; int depth; locals_stack_t *varLocals; int interactive; class_t *classCtx = NULL; void *syncCtx = NULL; hashtable_t *classDecs = NULL; \
hashtable_t *funcDecs = NULL; hashtable_t *varDecs = NULL;
#define DEF_NEW_CONTEXT_STATIC() static context_full_t exeCtx; static int32_t r0, r1, r2, ax; static double f0, f1, f2; static void *sp, *sb, *hp, *hb;\
static void *st, *ed; static size_t sc; static int depth; static locals_stack_t *varLocals; static int interactive; \
static class_t *classCtx; static void *syncCtx; static hashtable_t *classDecs; static hashtable_t *funcDecs; \
static hashtable_t *varDecs;

#define PROVIDE_CONTEXT_INIT() &exeCtx
#define PROVIDE_CONTEXT() exeCtx

#define PROVIDE_CONTEXT_INIT_MEMBERS() &r0, &r1, &r2, &ax, &f0, &f1, &f2, &sp, &sb, hp, hb, &st, &ed, &sc, &depth, varLocals, &interactive, classCtx, syncCtx,\
classDecs, funcDecs, varDecs
#define PROVIDE_CONTEXT_MEMBERS() r0, r1, r2, ax, f0, f1, f2, sp, sb, hp, hb, st, ed, sc, depth, varLocals, interactive, classCtx, syncCtx, \
classDecs, funcDecs, varDecs

#define ASSIGN_CONTEXT(ctx) ctx = (context_full_t) {PROVIDE_CONTEXT_INIT_MEMBERS()}

#define PROVIDE_CONTEXT_ARGS() context_full_t* exeCtx
#define UNPACK_CONTEXT() int32_t *r0 = PROVIDE_CONTEXT()->r0;\
int32_t *r1 = PROVIDE_CONTEXT()->r1;\
int32_t *r2 = PROVIDE_CONTEXT()->r2;\
int32_t *ax = PROVIDE_CONTEXT()->ax;\
double *f0 = PROVIDE_CONTEXT()->f0;\
double *f1 = PROVIDE_CONTEXT()->f1;\
double *f2 = PROVIDE_CONTEXT()->f2;\
void *sp = PROVIDE_CONTEXT()->sp;\
void *sb = PROVIDE_CONTEXT()->sb;\
void *hp = PROVIDE_CONTEXT()->hp;\
void *hb = PROVIDE_CONTEXT()->hb;\
void **st = PROVIDE_CONTEXT()->st;\
void **ed = PROVIDE_CONTEXT()->ed;\
size_t *sc = PROVIDE_CONTEXT()->sc;\
int *depth = PROVIDE_CONTEXT()->depth;\
locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;\
int *interactive = PROVIDE_CONTEXT()->interactive;\
class_t *classCtx = PROVIDE_CONTEXT()->classCtx;\
void *syncCtx = PROVIDE_CONTEXT()->syncCtx;

#define PROVIDE_CONTEXT_ARGS_OLD() int32_t *r0, int32_t *r1, int32_t *r2, \
int32_t *ax, double *f0, double *f1, double *f2, void *sp, void *sb, \
void *hp, void *hb, void **st, void **ed, size_t *sc, int *depth, locals_stack_t *varLocals, \
int *interactive, class_t *classCtx, void *syncCtx
#define EXPRESSION_PARAMS() void *stmt, void *next, \
PROVIDE_CONTEXT_ARGS(), argsList_t* args, hashtable_t *argVals
#define EXPRESSION_ARGS() stmt, next, PROVIDE_CONTEXT(), args, argVals
#define LIBRARY_PARAMS() char *func_name, EXPRESSION_PARAMS()
#define LIBRARY_INIT() UNPACK_CONTEXT()
#define LIBRARY_FUNC_NAME() func_name

#define DECLARE_LIB_FUNCTION(name, args, func) {name, args, func}

typedef int (*ric_lib_callback_t)(LIBRARY_PARAMS());

typedef struct libFunction {
  char *libFuncName;
  int nbrArgs;
  ric_lib_callback_t func;
} libFunction_t;

#define SETUP_STACK(sp, sb, sz, sc) do {\
  intptr_t p;\
  *sb = calloc(sz+1, sizeof(stackval_t));\
  assert(*sb != NULL);\
  p = ((intptr_t)*sb) % sizeof(stackval_t);\
  if ( p != 0 ) {\
    p = (sizeof(stackval_t) - ( p % sizeof(stackval_t) ));\
  }\
  *(intptr_t*)sp = *(intptr_t*)sb + p;\
  *(size_t*)sc = 0;\
} while ( 0 )

#define SETUP_HEAP(hp, hb, hz) do {\
  intptr_t p;\
  heapval_t hpbv;\
  *hb = calloc(hz+2, sizeof(heapval_t));\
  assert(*hb != NULL);\
  p = ((intptr_t)*hb) % sizeof(heapval_t);\
  p = (sizeof(heapval_t) - ( p % sizeof(heapval_t) ));\
  hpbv.sv.type = INT32TYPE;\
  hpbv.sv.i = (int32_t)hz;\
  hpbv.occupied = true;\
  hpbv.toFree = false;\
  *(intptr_t*)hp = *(intptr_t*)hb + p;\
  **(heapval_t**) hp = hpbv;\
} while ( 0 )

#define PUSH_DOUBLE(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
	fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix it!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = DOUBLETYPE;\
stackval.d = a;\
**((stackval_t**)sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)
#define PUSH_INT(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
	fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = INT32TYPE;\
stackval.i = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)
#define PUSH_VECTOR(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = VECTORTYPE;\
stackval.vec = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)
#define PUSH_STRING(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = TEXT;\
stackval.t = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)
#define PUSH_BIGINT(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = BIGINT;\
stackval.bigInt = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)
#define PUSH_POINTER(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
	fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = POINTERTYPE;\
stackval.p = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_FUNCPTR(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = FUNCPTRTYPE;\
stackval.func = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_LIBFUNCPTR(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = LIBFUNCPTRTYPE;\
stackval.libfunc = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_TIME(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = TIMETYPE;\
stackval.time = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_DICTIONARY(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = DICTTYPE;\
stackval.dict = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_INDEXER(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = INDEXER;\
stackval.indexer = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_CLASSREF(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = CLASSTYPE;\
stackval.classObj = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define PUSH_RAWDATA(a, sp, sc) do {\
stackval_t stackval;\
if ( *sc >= RIC_STACKSIZE ) {\
  fprintf(stderr, "Error: Intepreter stack overflow\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
stackval.type = RAWDATATYPE;\
stackval.rawdata = a;\
**((stackval_t**) sp) = stackval;\
*((stackval_t**) sp) += 1;\
*sc = *sc + 1;\
} while (0)

#define POP_VAL(a, sp, sc) do {\
if ( *sc == 0 ) {\
	fprintf(stderr, "Error: Intepreter stack corruption\n\
Please include the script and file an error report to me here:\n    %s\n\
This is not supposed to happen, I hope I can fix the intepreter!\n",\
GENERAL_ERROR_ISSUE_URL);\
  exit(1);\
}\
*((stackval_t**) sp) -= 1;\
*a = **((stackval_t**) sp);\
*sc = *sc - 1;\
} while (0)

/* Imported from sync.c */
extern void getContext(void*);
extern void releaseContext(void*);

#define ALLOC_HEAP(a, hp, hpv, upd) do { \
int32_t size = (*(heapval_t*)hp).sv.i;\
int32_t i = 0;\
heapval_t hv;\
getContext(PROVIDE_CONTEXT()->syncCtx);\
if ( upd != NULL ) {\
  *(int*)upd = 1;\
}\
hv.sv = *a;\
if ( hv.sv.type == TEXT || hv.sv.type == VECTORTYPE || \
     hv.sv.type == DICTTYPE || hv.sv.type == CLASSTYPE ||\
     hv.sv.type == RAWDATATYPE || hv.sv.type == BIGINT ) {\
  hv.toFree = true;\
} else {\
  hv.toFree = false;\
}\
hv.occupied = true;\
while ( i < size ) {\
  if ( !((heapval_t*) hp)[i].occupied ) {\
    ((heapval_t*) hp)[i] = hv;\
    *hpv = &((heapval_t*) hp)[i];\
    break;\
  }\
  ++i;\
}\
if ( i == size ) {\
  fprintf(stderr, "Error: Heap full (size: %d)\n", size);\
  exit(1);\
}\
releaseContext(PROVIDE_CONTEXT()->syncCtx);\
} while (0);

#define ALLOC_HEAP_UNSAFE(a, hp, hpv, upd) do { \
int32_t size = (*(heapval_t*)hp).sv.i;\
int32_t i = 0;\
heapval_t hv;\
if ( upd != NULL ) {\
  *(int*)upd = 1;\
}\
hv.sv = *a;\
if ( hv.sv.type == TEXT || hv.sv.type == VECTORTYPE || \
     hv.sv.type == DICTTYPE || hv.sv.type == CLASSTYPE ||\
     hv.sv.type == RAWDATATYPE || hv.sv.type == BIGINT ) {\
  hv.toFree = true;\
} else {\
  hv.toFree = false;\
}\
hv.occupied = true;\
while ( i < size ) {\
  if ( !((heapval_t*) hp)[i].occupied ) {\
    ((heapval_t*) hp)[i] = hv;\
    *hpv = &((heapval_t*) hp)[i];\
    break;\
  }\
  ++i;\
}\
if ( i == size ) {\
  fprintf(stderr, "Error: Heap full (size: %d)\n", size);\
  exit(1);\
}\
} while (0);

#define FREE_STACK(sp, spb) do { \
free(spb);\
} while (0);

void free_ast(statement_t *stmt);

#define PRINT_INTERACTIVE_BANNER() do {\
  printf("You are running in interactive mode. Stop it by typing: 'quit'.\n");\
  printf("This is in it's very early stage... it only supports one liners!\n");\
} while (0)

#endif

