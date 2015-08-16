#ifndef __ds__queue__
#define __ds__queue__

#include <stdio.h>
#include <stdbool.h>

typedef struct _queue_node {
    int data;
    struct _queue_node *next;
} queue_node_t;

typedef struct _queue_queue {
    queue_node_t *head;
    queue_node_t *tail;
} queue_queue_t;

void queue_initialize(queue_queue_t *queue);
bool queue_is_empty(queue_queue_t *queue);
queue_node_t * queue_front(queue_queue_t *queue);

void queue_push(queue_queue_t *queue, int data);
void queue_pop(queue_queue_t* queue);

#endif /* defined(__ds__queue__) */
