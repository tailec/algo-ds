#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display(st_node_t *node) {
    printf("%d\n", node->data);
}

int main(int argc, const char * argv[]) {
     st_stack_t *stack = (st_stack_t*)malloc(sizeof(st_stack_t));
     st_initialize(stack);
     st_push(stack, 1);
     st_push(stack, 2);
     st_push(stack, 3);
     display(st_top(stack));
     st_pop(stack);
     display(st_top(stack));
}
