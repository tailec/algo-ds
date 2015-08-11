#ifndef __ds__doubly_linked_list__
#define __ds__doubly_linked_list__

#include <stdio.h>

typedef struct _dll_node {
    int data;
    struct _dll_node *prev;
    struct _dll_node *next;
} dll_node_t;

typedef struct _doublylinkedlist {
    dll_node_t *head;
    dll_node_t *tail;
} dll_list_t;

void dll_initialize(dll_list_t *list);
void dll_display_forwards(dll_list_t *list);
void dll_display_backwards(dll_list_t *list);

void dll_insert_beginning(dll_list_t *list, int data);
void dll_insert_end(dll_list_t *list, int data);
void dll_insert_after(dll_list_t *list, dll_node_t *node, int data);
void dll_insert_before(dll_list_t *list, dll_node_t *node, int data);

void dll_remove_node(dll_list_t *list, dll_node_t *node);
void dll_remove_front(dll_list_t *list);
void dll_remove_back(dll_list_t *list);

#endif /* defined(__ds__doubly_linked_list__) */
