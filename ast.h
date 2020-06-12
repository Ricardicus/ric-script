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

#define EXPR_TYPE_ID    1
#define EXPR_TYPE_FVAL  2
#define EXPR_TYPE_IVAL  3
#define EXPR_TYPE_UVAL  4
#define EXPR_TYPE_TEXT  5
#define EXPR_TYPE_EMPTY 6
#define EXPR_TYPE_OPADD 7
#define EXPR_TYPE_OPSUB 8
#define EXPR_TYPE_OPDIV 9
#define EXPR_TYPE_OPMOD 10
#define EXPR_TYPE_OPMUL 11
#define EXPR_TYPE_COND  12

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

#define LANG_CONDITIONAL_IF      0
#define LANG_CONDITIONAL_ELIF    1
#define LANG_CONDITIONAL_ELSE    2

#define CONDITION_EQ             0
#define CONDITION_NEQ            1
#define CONDITION_LEQ            2
#define CONDITION_GEQ            3
#define CONDITION_GE             4
#define CONDITION_LE             5

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
	};
} expr_t;

typedef struct declaration_s {
	int entity;
	ID_t   id;
	expr_t *val;
} declaration_t;

typedef struct argsList {
	int entity;
	expr_t *arg;
	struct argsList *next;
} argsList_t;

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
	argsList_t *args;
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
expr_t* newExpr_OPAdd(expr_t *left, expr_t *right);
expr_t* newExpr_OPSub(expr_t *left, expr_t *right);
expr_t* newExpr_OPMul(expr_t *left, expr_t *right);
expr_t* newExpr_OPMod(expr_t *left, expr_t *right);
expr_t* newExpr_OPDiv(expr_t *left, expr_t *right);
expr_t* newExpr_Cond(ifCondition_t *cond);

ifCondition_t*  newConditional(int type, expr_t *left, expr_t *right);
declaration_t*  newDeclaration(const char *id, expr_t *exp);
statement_t*    newStatement(int type, void *content);
argsList_t*     newArgument(expr_t *exp, void *next);
ifStmt_t*       newIfStatement(int ifType, ifCondition_t *cond, void *body);
functionDef_t*  newFunc(const char *id, void *args, void *body);
functionCall_t* newFunCall(const char *id, void *args);
body_t*         newBody(void *body);

void print_statements(statement_t *root);
void interpret_statements(statement_t *stmt);

typedef enum stackvaltypes {
	INT32TYPE = 1,
	DOUBLETYPE,
	TEXT,
	POINTERTYPE
} stackvaltypes_t;

typedef struct stackval {
	int32_t type;
	union {
		double d;
		int32_t i;
		char *t;
	};
} stackval_t;

typedef struct heapval {
	stackval_t sv;
	bool occupied;
	bool toFree;
} heapval_t;

#define DEFAULT_STACKSIZE 256 * sizeof(int32_t)
#define DEFAULT_HEAPSIZE  4096 * sizeof(int32_t)

#define DEF_NEW_CONTEXT() int32_t r0, r1, r2, ax; void *sp, *sb, *hp, *hb; double f0, f1, f2; void *st, *ed;
#define PROVIDE_CONTEXT_INIT() &r0, &r1, &r2, &ax, &f0, &f1, &f2, &sp, hp, &st, &ed
#define PROVIDE_CONTEXT() r0, r1, r2, ax, f0, f1, f2, sp, hp, st, ed
#define PROVIDE_CONTEXT_ARGS() int32_t *r0, int32_t *r1, int32_t *r2, \
int32_t *ax, double *f0, double *f1, double *f2, void *sp, void *hp, void **st, void **ed
#define SETUP_STACK(sp, sb, sz) do {\
	intptr_t p;\
	*sb = calloc(sz+1, sizeof(stackval_t));\
	assert(*sb != NULL);\
	p = ((intptr_t)*sb) % sizeof(stackval_t);\
	if ( p != 0 ) {\
		p = (sizeof(stackval_t) - ( p % sizeof(stackval_t) ));\
	}\
	*(intptr_t*)sp = *(intptr_t*)sb + p;\
} while ( 0 )

#define SETUP_HEAP(hp, hb, hz) do {\
	intptr_t p;\
	heapval_t hpbv;\
	*hb = calloc(hz+1, sizeof(heapval_t));\
	assert(*hb != NULL);\
	p = ((intptr_t)*hb) % sizeof(heapval_t);\
	if ( p != 0 ) {\
		p = (sizeof(heapval_t) - ( p % sizeof(heapval_t) ));\
	}\
	hpbv.sv.type = INT32TYPE;\
	hpbv.sv.i = (int32_t)hz;\
	hpbv.occupied = true;\
	hpbv.toFree = false;\
	*(intptr_t*)hp = *(intptr_t*)hb + p;\
	**(heapval_t**) hp = hpbv;\
} while ( 0 )

#define PUSH_DOUBLE(a, sp) do { stackval_t stackval; stackval.type = DOUBLETYPE; stackval.d = a; **((stackval_t**)sp) = stackval; *((stackval_t**) sp) += 1; } while(0)
#define PUSH_INT(a, sp) do { stackval_t stackval; stackval.type = INT32TYPE;  stackval.i = a; **((stackval_t**) sp) = stackval; *((stackval_t**) sp) += 1; } while(0)
#define PUSH_STRING(a, sp) do { stackval_t stackval; stackval.type = TEXT;  stackval.t = a; **((stackval_t**) sp) = stackval; *((stackval_t**) sp) += 1;} while(0)
#define POP_VAL(a, sp) do { *((stackval_t**) sp) -= 1; *a = **((stackval_t**) sp); } while (0)

#define ALLOC_HEAP(a, hp, hpv) do { \
int32_t size = (*(heapval_t*)hp).sv.i;\
int32_t i = 0;\
heapval_t hv;\
hv.sv = *a;\
if (hv.sv.type == TEXT) {\
	hv.toFree = true;\
} else {\
  hv.toFree = false;\
}\
hv.occupied = true;\
while( i < size ) {\
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

#define FREE_HEAP(hp, hpb) do { \
int32_t size = (*(heapval_t*)hp).sv.i;\
int32_t i = 0;\
while( i < size ) {\
	if ( ((heapval_t*) hp)[i].occupied &&\
   ((heapval_t*) hp)[i].toFree ) {\
		free(((heapval_t*) hp)[i].sv.t);\
	}\
	++i;\
}\
free(hpb);\
} while (0);

#define FREE_STACK(sp, spb) do { \
free(spb);\
} while (0);

void free_ast(statement_t *stmt);

#endif

