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
#define EXPR_TYPE_ADDOP 6
#define EXPR_TYPE_EMPTY 7

typedef struct ID_s {
	char *ID;
} ID_t;

typedef struct addOP {
	void* left;
	void* right;
} addOP_t;

typedef struct expr_s {
	int      type;
	ID_t     id;
	double   fval;
	int32_t  ival;
	uint32_t uval;
	char     *text;
	addOP_t  add;
} expr_t;

expr_t* newExpr_Text(char *text);
expr_t* newExpr_Ival(int val);
expr_t* newExpr_Uval(unsigned val);
expr_t* newExpr_Float(double val);
expr_t* newExpr_ID(char *id);
expr_t* newExpr_OPAdd(expr_t *left, expr_t *right);

#endif