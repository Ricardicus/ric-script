#ifndef EVAL_H
#define EVAL_H

#include "ast.h"
#include "hashtable.h"

int evaluate_condition(ifCondition_t *cond,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args);
void evaluate_expression(
  expr_t *expr,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args);

void print_statements(statement_t *stmt);
void print_statements_(void *stmt, int indent);

void interpret_statements_(
  void *stmt,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t *args);

void interpret_statements(statement_t *stmt);

void print_condition(ifCondition_t *cond);
void print_expr(expr_t *expr);
void print_indents(int indent);

void setup_namespaces();
void close_namespaces();
void flush_parameters();

#endif