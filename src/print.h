#ifndef RIC_PRINT_H
#define RIC_PRINT_H

#include "eval.h"

#define ERROR_PRINT_LOCATION ((statement_t *)stmt)->file, ((statement_t *)stmt)->line

void print_statements(statement_t *stmt);
void print_statements_(void *stmt, int indent);

void print_condition(ifCondition_t *cond);
void print_expr(expr_t *expr);
void print_indents(int indent);
int print_args(argsList_t *args);
int print_vector(vector_t *vec, EXPRESSION_PARAMS());
int snprint_vector(char **buf, size_t *bufSize, size_t *pos, vector_t *vec, EXPRESSION_PARAMS());

int print_dictionary(dictionary_t *dict, EXPRESSION_PARAMS());
int snprint_dictionary(char **buf, size_t *bufSize, size_t *pos, dictionary_t *dict,
                       EXPRESSION_PARAMS());

void locals_print(locals_stack_t *stack);

#endif