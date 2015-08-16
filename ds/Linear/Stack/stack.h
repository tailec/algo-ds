#ifndef __ds__stack__
#define __ds__stack__

#include <stdio.h>
#include <stdbool.h>

typedef struct _st_node {
    int data;
    struct _st_node *next;
} st_node_t;

typedef struct _st_stack {
    st_node_t *top;
} st_stack_t;

void st_initialize(st_stack_t *stack);
bool st_is_empty(st_stack_t *stack);
st_node_t * st_top(st_stack_t *stack);

void st_push(st_stack_t *stack, int data);
void st_pop(st_stack_t* stack);

#endif /* defined(__ds__stack__) */
