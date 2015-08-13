#ifndef __ds__circular_linked_list__
#define __ds__circular_linked_list__

#include <stdio.h>

typedef struct _cll_node {
    int data;
    struct _cll_node *next;
} cll_node_t;

typedef struct _circularlinkedlist {
    cll_node_t *head;
} cll_list_t;

void cll_initialize(cll_list_t *list);
void cll_display(cll_list_t *list);

void cll_insert(cll_list_t *list, int data);
void cll_remove(cll_list_t* list);

#endif /* defined(__ds__circular_linked_list__) */
