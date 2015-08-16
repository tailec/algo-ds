#include "queue.h"
#include <stdlib.h>

void queue_initialize(queue_queue_t *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

bool queue_is_empty(queue_queue_t *queue) {
    return !queue->head;
}

queue_node_t * queue_front(queue_queue_t *queue) {
    return queue->head;
}

void queue_push(queue_queue_t *queue, int data) {
    queue_node_t *n = (queue_node_t*)malloc(sizeof(queue_node_t));
    n->data = data;
    n->next = NULL;
    if (queue->head) {
        queue->tail->next = n;
    } else {
        queue->head = n;
    }
    queue->tail = n;

}

void queue_pop(queue_queue_t* queue) {
    queue_node_t *n = queue->head;
    queue->head = n->next;
    if (!queue->head) queue->tail = NULL;
    free(n);
}