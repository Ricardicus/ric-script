#ifndef EVAL_H
#define EVAL_H

#include <setjmp.h>

#include "ast.h"
#include "hashtable.h"

#define JMP_CODE_INITIAL     0
#define JMP_CODE_CONTINUE    1

int evaluate_condition(ifCondition_t *cond,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals);
void evaluate_expression(
  expr_t *expr,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals);

void print_statements(statement_t *stmt);
void print_statements_(void *stmt, int indent);

void interpret_statements_(
  void *stmt,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t *args,
  hashtable_t *argVals);

void interpret_statements(statement_t *stmt);

void print_condition(ifCondition_t *cond);
void print_expr(expr_t *expr);
void print_indents(int indent);

void setup_namespaces();
void close_namespaces();
void flush_arguments(hashtable_t *args);

hashtable_t *new_argstable();

typedef struct ctx_table_t {
  void *stmt;
  argsList_t *args;
  hashtable_t *argVals;
} ctx_table_t;

#endif


