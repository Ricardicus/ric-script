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

#include "hashtable.h"

#ifndef BIT
#define BIT(x) ((1)<<((x)-1))
#endif

#define EXPR_TYPE_ID          1
#define EXPR_TYPE_FVAL        2
#define EXPR_TYPE_IVAL        3
#define EXPR_TYPE_UVAL        4
#define EXPR_TYPE_TEXT        5
#define EXPR_TYPE_EMPTY       6
#define EXPR_TYPE_OPADD       7
#define EXPR_TYPE_OPSUB       8
#define EXPR_TYPE_OPDIV       9
#define EXPR_TYPE_OPMOD       10
#define EXPR_TYPE_OPMUL       11
#define EXPR_TYPE_COND        12
#define EXPR_TYPE_FUNCCALL    13
#define EXPR_TYPE_POINTER     14
#define EXPR_TYPE_FUNCPTR     15
#define EXPR_TYPE_VECTOR      16
#define EXPR_TYPE_VECTOR_IDX  17
#define EXPR_TYPE_LIBFUNCPTR  18
#define EXPR_TYPE_DICT        19

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

#define LANG_CONDITIONAL_IF      BIT(1)
#define LANG_CONDITIONAL_ELIF    BIT(2)
#define LANG_CONDITIONAL_ELSE    BIT(3)
#define LANG_CONDITIONAL_CTX     BIT(4)

#define CONDITION_EQ             0
#define CONDITION_NEQ            1
#define CONDITION_LEQ            2
#define CONDITION_GEQ            3
#define CONDITION_GE             4
#define CONDITION_LE             5

#define DICTIONARY_STANDARD_SIZE 1024
#define DICTIONARY_STANDARD_LOAD 0.8

#define GENERAL_ERROR_ISSUE_URL  "https://github.com/Ricardicus/ric-script"
#define GENERAL_REPORT_ISSUE_MSG() do {\
        fprintf(stderr, "Please include the script and file an error report to me here:\n");\
        fprintf(stderr, "    - %s\n", GENERAL_ERROR_ISSUE_URL);\
        exit(1);\
} while (0);

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

typedef struct vector_t {
  int32_t length;
  argsList_t *content;
} vector_t;

typedef struct vectorIndex {
  expr_t *id;
  expr_t *index;
} vectorIndex_t;

typedef struct dictionary {
  int initialized;
  keyValList_t *keyVals;
  hashtable_t *hash;
} dictionary_t;

typedef struct expr_s {
	int      type;
	ID_t     id;

	union {
		double   fval;
		int32_t  ival;
		uint32_t uval;
	};	
	char     *text;
	size_t   textLen;

	union {
		addOP_t add;
		subOP_t sub;
		mulOP_t mul;
		divOP_t div;
		modOP_t mod;
    ifCondition_t *cond;
    void *func;
    uintptr_t p;
    vector_t *vec;
    vectorIndex_t *vecIdx;
    dictionary_t *dict;
	};
} expr_t;

typedef struct declaration_s {
	int entity;
	expr_t *id;
	expr_t *val;
} declaration_t;

typedef struct argsList {
  int entity;
  unsigned int length;
  expr_t *arg;
  struct argsList *next;
} argsList_t;

typedef struct keyValList {
  int entity;
  expr_t *key;
  expr_t *val;
  struct keyValList *next;
} keyValList_t;

typedef struct statement_s {
	int entity;
	void *content;
	struct statement_s *next;
} statement_t;

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

typedef struct functionCall {
	int entity;
	ID_t id;
	argsList_t *args;
} functionCall_t;

typedef struct ifStmt {
	int ifType;
	void *elif;
	void *endif;
	body_t *body;
	ifCondition_t *cond;
} ifStmt_t;

typedef struct entity_eval {
	int entity;
} entity_eval_t;

void* ast_emalloc(size_t size);

expr_t* newExpr_Text(char *text);
expr_t* newExpr_Ival(int val);
expr_t* newExpr_Uval(unsigned val);
expr_t* newExpr_Float(double val);
expr_t* newExpr_ID(char *id);
expr_t* newExpr_Pointer(uintptr_t val);
expr_t* newExpr_FuncPtr(void *func);
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
expr_t* newExpr_VectorIndex(expr_t *id, expr_t *index);
expr_t* newExpr_Copy(expr_t *exp);

ifCondition_t*  newConditional(int type, expr_t *left, expr_t *right);
declaration_t*  newDeclaration(expr_t *id, expr_t *exp);
statement_t*    newStatement(int type, void *content);
argsList_t*     newArgument(expr_t *exp, void *next);
ifStmt_t*       newIfStatement(int ifType, ifCondition_t *cond, void *body);
functionDef_t*  newFunc(const char *id, void *args, void *body);
functionCall_t* newFunCall(const char *id, void *args);
body_t*         newBody(void *body);

argsList_t*     copy_argsList(argsList_t *args);

void print_statements(statement_t *root);
void interpret_statements(int argc, char *argv[], statement_t *stmt);
void interpret_statements_interactive(int argc, char *argv[], statement_t *stmt, int teardown);
void free_expression(expr_t *expr);

typedef enum stackvaltypes {
	INT32TYPE = 1,
	DOUBLETYPE,
	TEXT,
	POINTERTYPE,
  FUNCPTRTYPE,
  LIBFUNCPTRTYPE,
  VECTORTYPE,
  DICTTYPE
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
	};
} stackval_t;

typedef struct heapval {
	stackval_t sv;
	bool occupied;
	bool toFree;
  uint32_t mark;
} heapval_t;

// Number of elements on the stack of this interpreter (arbitrary number?)
#define RIC_STACKSIZE 1024
// Number of elements on the heap of this interpreter (arbitrary number?)
#define RIC_HEAPSIZE  4096
// maximum number of variables in the langauge, need to be known by current
// garbage collector algorithm (making a list of all active)
#define RIC_MAX_NBR_VARS 4096

#define DEF_NEW_CONTEXT() int32_t r0, r1, r2, ax; double f0, f1, f2; void *sp, *sb, *hp, *hb; void *st, *ed; size_t sc;
#define DEF_NEW_CONTEXT_STATIC() static int32_t r0, r1, r2, ax; static double f0, f1, f2; static void *sp, *sb, *hp, *hb; static void *st, *ed; static size_t sc;
#define PROVIDE_CONTEXT_INIT() &r0, &r1, &r2, &ax, &f0, &f1, &f2, &sp, &sb, hp, hb, &st, &ed, &sc
#define PROVIDE_CONTEXT() r0, r1, r2, ax, f0, f1, f2, sp, sb, hp, hb, st, ed, sc
#define ASSIGN_CONTEXT() (context_full_t) { *r0, *r1, *r2, *ax, *f0, *f1, *f2, *(void**)sp, *(void**)sb, hp, hb, *(void**)st, *(void**)ed, *sc }
#define PROVIDE_CONTEXT_ARGS() int32_t *r0, int32_t *r1, int32_t *r2, \
int32_t *ax, double *f0, double *f1, double *f2, void *sp, void *sb, \
void *hp, void *hb, void **st, void **ed, size_t *sc
#define EXPRESSION_PARAMS() void *stmt, void *next, \
PROVIDE_CONTEXT_ARGS(), argsList_t* args, hashtable_t *argVals
#define EXPRESSION_ARGS() stmt, next, PROVIDE_CONTEXT(), args, argVals
#define LIBRARY_PARAMS() char *func_name, EXPRESSION_PARAMS()
#define LIBRARY_FUNC_NAME() func_name

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

#define ALLOC_HEAP(a, hp, hpv, upd) do { \
int32_t size = (*(heapval_t*)hp).sv.i;\
int32_t i = 0;\
heapval_t hv;\
if ( upd != NULL ) {\
  *(int*)upd = 1;\
}\
hv.sv = *a;\
if ( hv.sv.type == TEXT || hv.sv.type == VECTORTYPE ) {\
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
	fprintf(stderr, "Error: Heap full\n");\
	exit(1);\
} } while (0);

#define FREE_STACK(sp, spb) do { \
free(spb);\
} while (0);

void free_ast(statement_t *stmt);


typedef struct context_full_t {
DEF_NEW_CONTEXT()
} context_full_t;

#define PRINT_INTERACTIVE_BANNER() do {\
  printf("You are running in interactive mode. Stop it by typing: 'quit'.\n");\
  printf("This is in it's very early stage... it only supports one liners!\n");\
} while (0)

#endif

