#include "circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cll_initialize(cll_list_t *list) {
    list->head = NULL;
}

void cll_display(cll_list_t *list) {
    cll_node_t *l = list->head;
    if (list->head) {
        do {
            printf("%d ", l->data);
            l = l->next;
        } while (l != list->head);
        printf("\n");
    }
}

void cll_insert(cll_list_t *list, int data) {
    cll_node_t *n = (cll_node_t*)malloc(sizeof(cll_node_t));
    n->data = data;
    if (list->head) {
        n->next = list->head->next;
        list->head->next = n;
    } else {
        n->next = n;
    }
    list->head = n;
}

void cll_remove(cll_list_t* list) {
    if (list->head) {
        cll_node_t *n = list->head->next;
        list->head->next = n->next;
        if (n->next == n) {
            list->head = NULL;
        }
        free(n);
    }
}
