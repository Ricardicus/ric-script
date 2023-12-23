#include "prioqueue.h"

priority_queue_t *new_priority_queue(int capacity, int is_minimum) {
  priority_queue_t *pq = (priority_queue_t *)malloc(sizeof(priority_queue_t));
  int i = 0;
  pq->items = (priority_queue_item_t *)malloc(sizeof(priority_queue_item_t) * capacity);
  pq->capacity = capacity;
  pq->size = 0;
  pq->minimum = is_minimum;

  while (i < pq->capacity) {
    priority_queue_item_t *pqi = &pq->items[i];
    pqi->value = NULL;
    i++;
  }
  return pq;
}

void priority_queue_insert(priority_queue_t *pq, expr_t *value, int priority) {
  if (pq->size == pq->capacity) {
    priority_queue_double_capacity(pq);
  }

  priority_queue_item_t item;
  item.value = value;
  item.priority = priority;
  pq->items[pq->size] = item;
  pq->size++;

  // Bubble up the newly added item
  if (pq->minimum) {
    int i = pq->size - 1;
    while (i > 0 && pq->items[i].priority < pq->items[(i - 1) / 2].priority) {
      priority_queue_item_t temp = pq->items[i];
      pq->items[i] = pq->items[(i - 1) / 2];
      pq->items[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
    }
  } else {
    int i = pq->size - 1;
    while (i > 0 && pq->items[i].priority > pq->items[(i - 1) / 2].priority) {
      priority_queue_item_t temp = pq->items[i];
      pq->items[i] = pq->items[(i - 1) / 2];
      pq->items[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
    }
  }
}

expr_t *priority_queue_pop(priority_queue_t *pq) {
  if (pq->size == 0) {
    return NULL;
  }

  expr_t *max = pq->items[0].value;
  pq->items[0] = pq->items[pq->size - 1];
  pq->size--;

  // Bubble down the root item
  if (pq->minimum) {
    int i = 0;
    while (i < pq->size / 2) {
      int max_child = 2 * i + 1;
      if (max_child + 1 < pq->size
          && pq->items[max_child].priority > pq->items[max_child + 1].priority) {
        max_child++;
      }

      if (pq->items[i].priority <= pq->items[max_child].priority) {
        break;
      }

      priority_queue_item_t temp = pq->items[i];
      pq->items[i] = pq->items[max_child];
      pq->items[max_child] = temp;

      i = max_child;
    }
  } else {
    int i = 0;
    while (i < pq->size / 2) {
      int max_child = 2 * i + 1;
      if (max_child + 1 < pq->size
          && pq->items[max_child].priority < pq->items[max_child + 1].priority) {
        max_child++;
      }

      if (pq->items[i].priority >= pq->items[max_child].priority) {
        break;
      }

      priority_queue_item_t temp = pq->items[i];
      pq->items[i] = pq->items[max_child];
      pq->items[max_child] = temp;

      i = max_child;
    }
  }

  return max;
}

void free_priority_queue(priority_queue_t *pq) {
  free(pq->items);
  free(pq);
}

void priority_queue_double_capacity(priority_queue_t *pq) {
  int new_capacity = pq->capacity * 2;
  int i = 0;
  priority_queue_item_t *new_items =
      (priority_queue_item_t *)realloc(pq->items, sizeof(priority_queue_item_t) * new_capacity);

  if (new_items == NULL) {
    printf("Failed to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  i = pq->size;
  while (i < new_capacity) {
    priority_queue_item_t *pqi = &new_items[i];
    pqi->value = NULL;
    i++;
  }

  pq->items = new_items;
  pq->capacity = new_capacity;
}
