#ifndef EVAL_H
#define EVAL_H

#include <setjmp.h>

#include "ast.h"
#include "hashtable.h"
#include "garbage.h"
#include "lib.h"

#define JMP_CODE_INITIAL     0
#define JMP_CODE_CONTINUE    1
#define JMP_CODE_TEARDOWN    2

int evaluate_condition(ifCondition_t *cond,
  void *stmt, void *next,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals);
void evaluate_expression(
  expr_t *expr,
  void *stmt, void *next,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals);
int evaluate_id_valid(
  char *id,
  void *stmt, void *next,
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

void interpret_statements(int argc, char* argv[], statement_t *stmt);
void interpret_statements_interactive(int argc, char* argv[], statement_t *stmt, int teardown);

void print_condition(ifCondition_t *cond);
void print_expr(expr_t *expr);
void print_indents(int indent);
int  print_args(argsList_t *args);
int  print_vector(
  vector_t *vec,
  EXPRESSION_PARAMS()
);
void free_vector(vector_t *vec);

expr_t*  copy_vector(
  vector_t *vec,
  EXPRESSION_PARAMS()
);


int print_dictionary(dictionary_t *dict, EXPRESSION_PARAMS());
void setup_namespaces();
void close_namespaces();
void flush_arguments(hashtable_t *args);
void flush_heapval(void *key, void *val);

void arguments_to_variables(int argc, char* argv[], void *hp);

void call_func(
  functionCallContainer_t *funcCall,
  void *stmt, void *next,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t *args,
  hashtable_t *argVals);

void initClass(class_t *cls, EXPRESSION_PARAMS());

hashtable_t *new_argstable();
hashtable_t* hashtable_heapvals_copy(
  hashtable_t *hash, EXPRESSION_PARAMS());

dictionary_t *allocNewDictionary(dictionary_t *, EXPRESSION_PARAMS());

typedef struct ctx_table_t {
  void *stmt;
  argsList_t *args;
  hashtable_t *argVals;
  int depth;
  int sp[MAX_BODY_LEVELS];
  int sb[MAX_BODY_LEVELS];
  int ctxDepth[MAX_BODY_LEVELS];
  statement_t *bodyEnd[MAX_BODY_LEVELS];  // Where to go after end of body
  statement_t *start[MAX_BODY_LEVELS];
  statement_t *end[MAX_BODY_LEVELS];
} ctx_table_t;

heapval_t *locals_lookup(locals_stack_t *stack, char *id);
void locals_push(locals_stack_t *stack, char *id, heapval_t *hpv);

#endif


