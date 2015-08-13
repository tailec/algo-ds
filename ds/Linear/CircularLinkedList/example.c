#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

int main(int argc, const char * argv[]) {
    cll_list_t *list = (cll_list_t*)malloc(sizeof(cll_list_t));
    cll_initialize(list);

    cll_insert(list, 1);
    cll_insert(list, 2);
    cll_insert(list, 3);
    cll_display(list);

    cll_remove(list);
    cll_display(list);

}
