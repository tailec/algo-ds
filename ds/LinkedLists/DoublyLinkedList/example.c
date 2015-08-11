#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main(int argc, const char * argv[]) {
    dll_list_t *dll = (dll_list_t*)malloc(sizeof(dll_list_t));
    dll_initialize(dll);
    dll_insert_beginning(dll, 1);
    dll_insert_beginning(dll, 2);
    dll_insert_beginning(dll, 3);
    dll_insert_after(dll, dll->head, 10);
    dll_display_forwards(dll);
    dll_remove_node(dll, dll->head->next);
    dll_display_forwards(dll);
}
