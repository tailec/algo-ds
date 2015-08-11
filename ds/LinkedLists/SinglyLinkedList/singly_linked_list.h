#ifndef __singly_linked_list__
#define __singly_linked_list__

#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _linkedlist {
    Node *head;
} SinglyLinkedList;


void initialize_list(SinglyLinkedList *list);
int size(SinglyLinkedList *list);
void display(SinglyLinkedList *list);

void push_front(SinglyLinkedList *list, int data);
void push_back(SinglyLinkedList *list, int data);
void push_before(SinglyLinkedList* list, Node* before_node, int data);
void push_after(SinglyLinkedList *list, Node *after_node, int data);

void pop_front(SinglyLinkedList *list);
void pop_back(SinglyLinkedList *list);
void pop_node(SinglyLinkedList *list, Node *popn);

#endif
