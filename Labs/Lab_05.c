#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"



int main() {
    // Question 1
    // inappropriate as we want to completely change or add an index to memory
    // should use memmove instead of memcpy because of potential undefined behaviour
    // with copying a block of memory to another block of memory that overlaps

    int data_arr[] = {1, 2, 3, 4, 5};
    IntList *list;
    create_list_from_data(&list, data_arr, 5);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    list_insert(list, 6, 2);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    list_delete(list, 2);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    printf("%d", list_get(list, 2));
    printf("\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    list_destroy(list);

    return 0;
}