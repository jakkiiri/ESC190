#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linkedlist.c"


int main() {
    LL my_list;
    my_list.head = NULL;
    my_list.size = 0;
    LL_append(&my_list, 1);
    LL_append(&my_list, 2);
    LL_append(&my_list, 3);
    printf("Append 1, 2, 3 to Empty L\n");
    print_LL(&my_list);
    printf("Validate List Length (Correct): %d\n", validate_list_length(&my_list));
    // change list length
    my_list.size = 1;
    printf("Validate List Length (Incorrect): %d\n", validate_list_length(&my_list)); // incorrect
    // change it back
    my_list.size = 3;
    LL_append(&my_list, 4);
    print_LL(&my_list);
    delete(&my_list, 2);
    printf("Deleted Element at Index 2\n");
    print_LL(&my_list);
    delete(&my_list, 0);
    printf("Deleted Element at Index 0\n");
    print_LL(&my_list);
    printf("Deleted Element at Index 4 (will not work)\n");
    delete(&my_list, 4);
    print_LL(&my_list);
    return 0;
}