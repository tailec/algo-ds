#ifndef __ds__p_queue__
#define __ds__p_queue__

#include <stdio.h>
#include <stdbool.h>

typedef struct _p_queue_node {
    int data;
    int prio;
    struct _p_queue_node *next;
} p_queue_node_t;

typedef struct _p_queue_queue {
    p_queue_node_t *head;
    p_queue_node_t *tail;
} p_queue_queue_t;

void p_queue_initialize(p_queue_queue_t *queue);
bool p_queue_is_empty(p_queue_queue_t *queue);
p_queue_node_t * p_queue_front(p_queue_queue_t *queue);

void p_queue_push(p_queue_queue_t *queue, int data, int prio);
void p_queue_pop(p_queue_queue_t* queue);

#endif /* defined(__ds__p_queue__) */
