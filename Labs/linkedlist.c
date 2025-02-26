#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void print_LL(LL *my_list) {
    node *current_node = my_list->head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Q1
// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem) {
    // check if the list is empty
    if (my_list->head == NULL) {
        my_list->head = (node *) malloc(sizeof(node));
        my_list->head->data = new_elem;
        my_list->head->next = NULL;
    } else {
        // transverse mylist
        int size = my_list->size;
        node *current_node = my_list->head;

        for (int i = 0; i < size - 1; i++) {
            current_node = current_node->next;
        }
        // append the new elem after transversing the entire list
        current_node->next = (node *) malloc(sizeof(node));
        current_node->next->data = new_elem;
        current_node->next->next = NULL;
    }
    my_list->size++;
}

// Q2
int validate_list_length(LL *my_list) {
    int size = my_list->size;
    int validation;
    if (my_list->head == NULL) {
        validation = 0;
        return size == validation;
    } else {
        // loop through my_list to check for nodes
        node *current_node = my_list->head;
        for (validation = 1; current_node->next != NULL; validation++) {
            current_node = current_node->next;
        }
    }
    return size == validation;
}

// Q3 (uh oh)
void delete(LL *my_list, int index) {
    // check if index is valid
    if (index < 0 || index >= my_list->size) {
        printf("Index out of bounds\n");
        return;
    }
    // empty list skip
    if (my_list->head != NULL) {
        node *current_node = my_list->head;
        // if one element LL i will just delete whatever is there
        if (current_node->next == NULL) {
            my_list->head = NULL;
            free(current_node);
        } else if (index == 0) {
            // index 0 case
            my_list->head = current_node->next;
            free(current_node);
        } else {
            node *previous_node = NULL;
            for (int i = 0; i < index; i++) {
                previous_node = current_node;
                current_node = current_node->next;
            }
            // store the next pointer of the going to be deleted node
            node *next_node = current_node->next;
            // point the previous_node to the one after
            previous_node->next = next_node;
            free(current_node);
        }
        // update size length
        my_list->size--;
    }
}
