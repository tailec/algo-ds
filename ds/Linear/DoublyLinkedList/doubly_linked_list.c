//
//  doubly_linked_list.c
//  ds
//
//  Created by Pawel Krawiec on 11/08/2015.
//  Copyright (c) 2015 rentalcars. All rights reserved.
//

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dll_initialize(dll_list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void dll_display_forwards(dll_list_t *list) {
    dll_node_t *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void dll_display_backwards(dll_list_t *list) {
    dll_node_t *node = list->tail;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void dll_insert_beginning(dll_list_t *list, int data) {
    dll_node_t *n = (dll_node_t*)malloc(sizeof(dll_node_t));
    n->data = data;
    n->prev = NULL;

    n->next = list->head;
    list->head = n;

    if (n->next != NULL) {
        n->next->prev = n;
    } else {
        list->tail = n;
    }
}

void dll_insert_end(dll_list_t *list, int data) {
    dll_node_t *n = (dll_node_t*)malloc(sizeof(dll_node_t));
    n->data = data;
    n->next = NULL;

    n->prev = list->tail;
    list->tail = n;

    if (n->prev != NULL) {
        n->prev->next = n;
    } else {
        list->tail = n;
    }
}

void dll_insert_after(dll_list_t *list, dll_node_t *node, int data) {
    if (node == list->tail) {
        dll_insert_end(list, data);
    } else {
        dll_node_t *n = (dll_node_t*)malloc(sizeof(dll_node_t));
        n->data = data;
        n->prev = node;
        n->next = node->next;

        node->next->prev = n;
        node->next = n;
    }
}

void dll_insert_before(dll_list_t *list, dll_node_t *node, int data) {
    if (node == list->head) {
        dll_insert_beginning(list, data);
    } else {
        dll_node_t *n = (dll_node_t*)malloc(sizeof(dll_node_t));
        n->data = data;
        n->next = node;
        n->prev = node->prev;

        node->prev->next = n;
        node->prev = n;
    }
}

void dll_remove_node(dll_list_t *list, dll_node_t *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
}

void dll_remove_front(dll_list_t *list) {
    dll_remove_node(list, list->head);
}

void dll_remove_back(dll_list_t *list) {
    dll_remove_node(list, list->tail);
}
