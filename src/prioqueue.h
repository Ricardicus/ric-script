#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

typedef struct priority_queue_item {
  expr_t *value;
  int priority;
} priority_queue_item_t;

typedef struct priority_queue {
  priority_queue_item *items;
  int capacity;
  int size;
} priority_queue_t;

priority_queue_t *new_priority_queue(int capacity);
void priority_queue_insert(priority_queue_t *pq, expr_t *value, int priority);
expr_t *priority_queue_pop_max(priority_queue_t *pq);
void free_priority_queue(priority_queue_t *pq);
void priority_queue_double_capacity(priority_queue_t *pq);
expr_t *priority_queue_peep_max(priority_queue_t *pq);

#endif
