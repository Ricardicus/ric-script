#ifndef INTERPRET_RIC_H
#define INTERPRET_RIC_H

#include "eval.h"

typedef enum { INTEPRET_CONTINUE, INTEPRET_RETURN } interpret_state_t;

interpret_state_t interpret_statements_(void *stmt, PROVIDE_CONTEXT_ARGS(), argsList_t *args,
                                        hashtable_t *argVals);
void interpret_statements(int argc, char *argv[], statement_t *stmt, int stacksize, int heapsize);
void interpret_statements_interactive(int argc, char *argv[], statement_t *stmt, int teardown, int stacksize, int heapsize);

void setup_namespaces(PROVIDE_CONTEXT_ARGS());
void close_namespaces(PROVIDE_CONTEXT_ARGS());
void flush_arguments(hashtable_t *args);

void arguments_to_variables(PROVIDE_CONTEXT_ARGS(), int argc, char *argv[], void *hp);

#endif
