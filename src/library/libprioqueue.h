#ifndef LIBPRIOQUEUE_H
#define LIBPRIOQUEUE_H

#include "ast.h"
#include "prioqueue.h"

#define PRIO_QUEUE_DEFAULT_CAP 1024

int ric_new_min_heap(LIBRARY_PARAMS());
int ric_new_max_heap(LIBRARY_PARAMS());
int ric_heap_insert(LIBRARY_PARAMS());
int ric_heap_pop(LIBRARY_PARAMS());
int ric_free_priority_queue(LIBRARY_PARAMS());
int ric_priority_queue_peek(LIBRARY_PARAMS());
int ric_print_stack_size(LIBRARY_PARAMS());

#endif
