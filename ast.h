#ifndef SCRIPT_SIMPLE_AST_H
#define SCRIPT_SIMPLE_AST_H

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

#define LANG_ENTITY_DECL         1
#define LANG_ENTITY_ARGS         2
#define LANG_ENTITY_FUNCDECL     3
#define LANG_ENTITY_STATEMENT    4
#define LANG_ENTITY_BODY         5
#define LANG_ENTITY_FUNCCALL     6
#define LANG_ENTITY_CONDITIONAL  7

#define LANG_CONDITIONAL_IF      0
#define LANG_CONDITIONAL_ELIF    1
#define LANG_CONDITIONAL_ELSE    2

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

typedef struct expr_s {
	int      type;
	ID_t     id;
	double   fval;
	int32_t  ival;
	uint32_t uval;
	char     *text;
	size_t   textLen;
	union {
		addOP_t add;
		subOP_t sub;
		mulOP_t mul;
		divOP_t div;
		modOP_t mod;
	};
} expr_t;

typedef struct declaration_s {
	int entity;
	ID_t   id;
	expr_t *val;
} declaration_t;

typedef struct argsList {
	int entity;
	ID_t id;
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

typedef struct ifCondition {
	int entity;
	expr_t *left;
	expr_t *right;
} ifCondition_t;

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

declaration_t*  newDeclaration(const char *id, expr_t *exp);
statement_t*    newStatement(int type, void *content);
argsList_t*     newArgument(const char *id, void *next);
ifStmt_t*       newIfStatement(int ifType, ifCondition_t *cond, void *body);
functionDef_t*  newFunc(const char *id, void *args, void *body);
functionCall_t* newFunCall(const char *id, void *args);
body_t*         newBody(void *body);

void print_statements(statement_t *root);

#endif