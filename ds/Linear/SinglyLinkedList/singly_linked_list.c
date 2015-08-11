#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_empty(SinglyLinkedList *list) {
    return (list->head == NULL);
}

void initialize_list(SinglyLinkedList *list) {
    list->head = NULL;
}

void push_front(SinglyLinkedList *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void push_back(SinglyLinkedList *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    
    if (!is_empty(list)) {
        Node *l = list->head;
        while (l->next != NULL) {
            l = l->next;
        }
        l->next = node;
    } else {
        list->head = node;
    }
}

void push_before(SinglyLinkedList* list, Node* node, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    if (list->head == node) {
        n->next = list->head;
        list->head = n;
        return;
    }
    
    Node *l = list->head;
    while (l->next != node) {
        l = l->next;
    }
    printf("l = %d\n", l->data);
    l->next = n;
    n->next = node;
}

void push_after(SinglyLinkedList *list, Node *node, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = node->next;
    node->next = n;
}

void pop_front(SinglyLinkedList *list) {
    if (list->head != NULL) {
        Node *node = list->head;
        list->head = node->next;
        free(node);
    }
}

void pop_back(SinglyLinkedList *list) {
    if (is_empty(list)) return;
    if (list->head->next == NULL) {
        free(list->head->next);
        list->head = NULL;
    }
    
    Node *l = list->head;
    while (l->next->next != NULL) {
        l = l->next;
    }
    free(l->next);
    l->next = NULL;
}

void pop_node(SinglyLinkedList *list, Node *node) {
    Node *l = list->head;
    while (l->next != node) {
        l = l->next;
    }
    l->next = l->next->next;
    free(node);
}

int size(SinglyLinkedList *list) {
    int counter = 0;
    Node *l = list->head;
    while(l) {
        counter++;
        l = l->next;
    }
    return counter;
}

void display(SinglyLinkedList *list) {
    Node *l = list->head;
    while(l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}
