#ifndef LIBPRIOQUEUE_H
#define LIBPRIOQUEUE_H

#include "ast.h"
#include "prioqueue.h"

#define PRIO_QUEUE_DEFAULT_CAP 1024

int ric_new_priority_queue(LIBRARY_PARAMS());
int ric_priority_queue_insert(LIBRARY_PARAMS());
int ric_priority_queue_pop_max(LIBRARY_PARAMS());
int ric_free_priority_queue(LIBRARY_PARAMS());
int ric_priority_queue_peek(LIBRARY_PARAMS());

#endif
