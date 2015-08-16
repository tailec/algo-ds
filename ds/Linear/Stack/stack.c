#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void st_initialize(st_stack_t *stack) {
    stack->top = NULL;
}

bool st_is_empty(st_stack_t *stack) {
    return !stack->top;
}

st_node_t * st_top(st_stack_t *stack) {
    return stack->top;
}

void st_push(st_stack_t *stack, int data) {
    st_node_t *n = (st_node_t*)malloc(sizeof(st_node_t));
    n->data = data;
    n->next = stack->top;
    stack->top = n;

}

void st_pop(st_stack_t* stack) {
    if (stack->top) {
        st_node_t *n = stack->top;
        stack->top = n->next;
        free(n);
    }
}