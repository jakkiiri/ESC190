#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct list_node {
    long value;
    struct list_node *prev;
    struct list_node *next;
} list_node_t;

bool find(long elem, list_node_t **first) {
    // address start case
    if ((*first)->value == elem) {
        return true;
    }
    list_node_t *cur = (*first)->next;
    while (cur != NULL) {
        if (cur->value == elem) {
            // elem has been found
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            cur->prev = NULL;
            cur->next = *first;
            (*first)->prev = cur;
            *first = cur;
            return true;
        }
        cur = cur->next;
    }
    return false;
}


void test_find() {
    // Create nodes for testing
    list_node_t node3 = {3, NULL, NULL};
    list_node_t node2 = {2, NULL, &node3};
    list_node_t node1 = {1, NULL, &node2};
    node3.prev = &node2;
    node2.prev = &node1;

    list_node_t *head = &node1;

    // Test case 1: Element is the first node
    assert(find(1, &head) == true);
    assert(head->value == 1);

    // Test case 2: Element is in the middle
    assert(find(2, &head) == true);
    assert(head->value == 2);

    // Test case 3: Element is the last node
    assert(find(3, &head) == true);
    assert(head->value == 3);

    // Test case 4: Element is not in the list
    assert(find(4, &head) == false);

    printf("All tests passed!\n");
}

int main() {
    test_find();
    return 0;
}