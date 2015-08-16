#include "p_queue.h"
#include <stdlib.h>

void p_queue_initialize(p_queue_queue_t *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

bool p_queue_is_empty(p_queue_queue_t *queue) {
    return !queue->head;
}

p_queue_node_t * p_queue_front(p_queue_queue_t *queue) {
    return queue->head;
}

void p_queue_push(p_queue_queue_t *queue, int data, int prio){
    p_queue_node_t *n = (p_queue_node_t*)malloc(sizeof(p_queue_node_t));
    n->data = data;
    n->prio = prio;
    n->next = NULL;
    if (!queue->head) {
        queue->head = n;
        queue->tail = n;
    }
    else if (queue->head->prio < n->prio) {
        n->next = queue->head;
        queue->head = n;
    } else {
        p_queue_node_t *q = queue->head;
        while (q->next != NULL && q->next->prio >= n->prio) {
            q = q->next;
        }
        n->next = q->next;
        q->next = n;
        if (!n->next)
            queue->tail = n;
    }
}

void p_queue_pop(p_queue_queue_t* queue) {
    if (queue->head) {
        p_queue_node_t *n = queue->head;
        queue->head = n->next;
        if (queue->head)
            queue->tail = n;
        free(n);
    }
}
