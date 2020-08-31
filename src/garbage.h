#ifndef GARBAGE_H
#define GARBAGE_H
/*
* Garbage collection
*/
#include "ast.h"
#include "hashtable.h"
#include <time.h>

void mark_and_sweep(
  hashtable_t *varDecs,
  heapval_t* heap);

uint32_t get_mark_value();

#endif
