#ifndef EVAL_H
#define EVAL_H

#include <setjmp.h>

#include "ast.h"
#include "hashtable.h"
#include "garbage.h"
#include "lib.h"
#include "sync.h"

#define JMP_CODE_INITIAL 0
#define JMP_CODE_CONTINUE 1
#define JMP_CODE_TEARDOWN 2

typedef enum {
  CONTINUE,
  RETURN
} interpret_state_t;

int evaluate_condition(ifCondition_t *cond, void *stmt, void *next, PROVIDE_CONTEXT_ARGS(),
                       argsList_t *args, hashtable_t *argVals);
void evaluate_expression(expr_t *expr, void *stmt, void *next, PROVIDE_CONTEXT_ARGS(),
                         argsList_t *args, hashtable_t *argVals);
int evaluate_id_valid(char *id, void *stmt, void *next, PROVIDE_CONTEXT_ARGS(), argsList_t *args,
                      hashtable_t *argVals);
int evaluate_indexer(indexer_t *indexer, int max, int *idxStart, int *idxEnd, int *offset,
                     EXPRESSION_PARAMS());

void print_statements(statement_t *stmt);
void print_statements_(void *stmt, int indent);

interpret_state_t interpret_statements_(void *stmt, PROVIDE_CONTEXT_ARGS(), argsList_t *args,
                           hashtable_t *argVals);

void interpret_statements(int argc, char *argv[], statement_t *stmt);
void interpret_statements_interactive(int argc, char *argv[], statement_t *stmt, int teardown);

void print_condition(ifCondition_t *cond);
void print_expr(expr_t *expr);
void print_indents(int indent);
int print_args(argsList_t *args);
int print_vector(vector_t *vec, EXPRESSION_PARAMS());
int snprint_vector(char **buf, size_t *bufSize, size_t *pos, vector_t *vec, EXPRESSION_PARAMS());
void free_vector(vector_t *vec);

expr_t *copy_vector(vector_t *vec, EXPRESSION_PARAMS());

void check_buf_size(char **buf, size_t *bufSize, size_t *pos, size_t require);

int print_dictionary(dictionary_t *dict, EXPRESSION_PARAMS());
int snprint_dictionary(char **buf, size_t *bufSize, size_t *pos, dictionary_t *dict,
                       EXPRESSION_PARAMS());
void setup_namespaces(PROVIDE_CONTEXT_ARGS());
void close_namespaces(PROVIDE_CONTEXT_ARGS());
void flush_arguments(hashtable_t *args);
void flush_heapval(void *key, void *val);

void arguments_to_variables(PROVIDE_CONTEXT_ARGS(), int argc, char *argv[], void *hp);

void call_func(functionCallContainer_t *funcCall, void *stmt, void *next, PROVIDE_CONTEXT_ARGS(),
               argsList_t *args, hashtable_t *argVals);

void initClass(class_t *cls, EXPRESSION_PARAMS());

hashtable_t *new_argstable();
hashtable_t *hashtable_heapvals_copy(hashtable_t *hash, EXPRESSION_PARAMS());

dictionary_t *allocNewDictionary(dictionary_t *, EXPRESSION_PARAMS());

typedef struct ctx_table_t {
  void *stmt;
  argsList_t *args;
  hashtable_t *argVals;
  int depth;
  int sp[MAX_BODY_LEVELS];
  int sb[MAX_BODY_LEVELS];
  int ctxDepth[MAX_BODY_LEVELS];
  statement_t *bodyEnd[MAX_BODY_LEVELS]; // Where to go after end of body
  statement_t *start[MAX_BODY_LEVELS];
  statement_t *end[MAX_BODY_LEVELS];
} ctx_table_t;

heapval_t *locals_lookup(locals_stack_t *stack, char *id);
void locals_push(locals_stack_t *stack, char *id, heapval_t *hpv);
void locals_remove(locals_stack_t *stack, char *id);
void locals_print(locals_stack_t *stack);

expr_t *stackval_to_expression(stackval_t *sv, EXPRESSION_PARAMS());

#define ERROR_PRINT_LOCATION ((statement_t *)stmt)->file, ((statement_t *)stmt)->line

#endif
