#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void display(queue_node_t *node) {
    printf("%d\n", node->data);
}

int main(int argc, const char * argv[]) {
     queue_queue_t *queue = (queue_queue_t*)malloc(sizeof(queue_queue_t));
     queue_initialize(queue);
     queue_push(queue, 1);
     queue_push(queue, 2);
     queue_push(queue, 3);
     display(queue_front(queue));
     queue_pop(queue);
     display(queue_front(queue));
     queue_pop(queue);
     display(queue_front(queue));

}
