#include <stdio.h>
#include <stdlib.h>
#include "intset.h"

// Create an intset, and place a pointer to it in *s.
void intset_create(struct intset **s) {
    *s = (struct intset *) malloc (sizeof(struct intset));
    (*s)->head = (struct node *) malloc (sizeof(struct node));
    (*s)->head->next = NULL;  // Dummy head
}

void intset_add(struct intset *s, int *elems, int num_elems) {
    for (int i = 0; i < num_elems; i++) {
        struct node *current_node = s->head;
        int duplicate_found = 0; // Flag to track duplicates

        // Check all nodes for duplicates
        while (current_node != NULL) {
            if (current_node->data == elems[i]) {
                duplicate_found = 1;
                break;
            }
            current_node = current_node->next;
        }

        // Add the element if no duplicate was found
        if (!duplicate_found) {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->data = elems[i];
            new_node->next = NULL;

            // Find the last node to append the new node
            current_node = s->head;
            if (current_node == NULL) {
                s->head = new_node; // Handle empty list
            } else {
                while (current_node->next != NULL) {
                    current_node = current_node->next;
                }
                current_node->next = new_node;
            }
        }
    }
}

// Return 1 if element elem is in intset s. Otherwise, return 0.
int intset_iselem(struct intset *s, int elem) {
    struct node *current_node = s->head;
    while (current_node != NULL) {
        if (current_node->data == elem) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

void intset_remove(struct intset *s, int elem) {
    if (s->head == NULL) return; // Handle empty list case

    struct node *current_node = s->head;
    struct node *previous_node = NULL;

    // If the element to remove is the first node
    if (current_node->data == elem) {
        s->head = current_node->next;  // Move head to the next node
        free(current_node);
        return;  // Stop after deleting the first occurrence
    }

    // Traverse the list and find the node to remove
    while (current_node != NULL) {   
        if (current_node->data == elem) {
            previous_node->next = current_node->next;
            free(current_node);
            return;  // Stop after deleting the first occurrence
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}


// Compute the union of sets s1 and s2, and place the result in a new intset *s3.
void intset_union(struct intset *s1, struct intset *s2, struct intset **s3) {
    // Allocate memory
    *s3 = (struct intset *) malloc(sizeof(struct intset)); 
    (*s3)->head = (struct node *) malloc(sizeof(struct node));
    (*s3)->head->next = NULL;

    struct node *current_node1 = s1->head;
    while (current_node1 != NULL) {
        intset_add(*s3, &(current_node1->data), 1);
        current_node1 = current_node1->next;
    }

    struct node *current_node2 = s2->head;
    while (current_node2 != NULL) {
        if (!intset_iselem(*s3, current_node2->data)) {
            intset_add(*s3, &(current_node2->data), 1);
        }
        current_node2 = current_node2->next;
    }
}
