#ifndef GARBAGE_H
#define GARBAGE_H
/*
* Garbage collection
*/
#include "ast.h"
#include "eval.h"
#include "hashtable.h"
#include <time.h>

void mark_and_sweep(
  hashtable_t *varDecs,
  void *varLocals,
  EXPRESSION_PARAMS());

void free_heap(void *hp, void *hbp);

uint32_t set_mark_value();

#endif
