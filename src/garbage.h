#ifndef GARBAGE_H
#define GARBAGE_H
/*
 * Garbage collection
 */
#include "ast.h"
#include "eval.h"
#include "hashtable.h"
#include <time.h>

#define GARBAGE_COLLECTION_PILEUP_FACTOR 20

void mark_and_sweep(hashtable_t *varDecs, EXPRESSION_PARAMS());

void mark(hashtable_t *varDecs, uint32_t markVal, EXPRESSION_PARAMS());
void free_heap(void *hp, void *hbp);

uint32_t set_mark_value(void);

#endif
