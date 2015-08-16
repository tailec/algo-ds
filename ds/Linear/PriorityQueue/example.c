#include <stdio.h>
#include <stdlib.h>
#include "p_queue.h"

void display(p_queue_node_t *node) {
    printf("%d\n", node->data);
}

int main(int argc, const char * argv[]) {
  p_queue_queue_t *queue = (p_queue_queue_t*)malloc(sizeof(p_queue_queue_t));
  p_queue_initialize(queue);
  p_queue_push(queue, 1, 1);
  p_queue_push(queue, 2, 3);
  p_queue_push(queue, 3, 2);
  p_queue_pop(queue);
  display(p_queue_front(queue));
}
