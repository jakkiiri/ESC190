#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	int data; 
	struct Node* next; 
} Node;

typedef struct Queue {
    struct Node* start;
} Queue;

struct Queue *initQueue() {
    struct Queue* q = (Queue *) malloc (sizeof(Queue));
    q->start = NULL;
    return q;
}

int dequeue (struct Queue *q) {
    if (q->start == NULL) {
        fprintf(stderr, "Error: Attempt to dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *start = q->start;
    q->start = start->next;
    int num = start->data;
    free(start);
    return num;
}

void enqueue (struct Queue *q, int data) {
    struct Node *cur = q->start;
    if (cur == NULL) {
        q->start = (struct Node *) malloc (sizeof(Node));
        q->start->data = data;
        q->start->next = NULL;  
    } else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = (struct Node *) malloc (sizeof(Node));
        cur->next->data = data;
        cur->next->next = NULL;
    }
}

int isEmpty(struct Queue *q) {
    if (q->start = NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct adjMatrix{ int aM[5][5]; };

int isConnected(struct adjMatrix *aM, int m) {
    // Assume N is known (e.g., as a macro or global constant)
    int *visited = (int *)calloc(5, sizeof(int));
    if (!visited) return 0; // Allocation failure
    
    struct Queue *q = initQueue();
    enqueue(q, m);
    visited[m] = 1;
    
    while (!isEmpty(q)) {
        int u = dequeue(q);
        for (int v = 0; v < 5; v++) {
            // Check both directions for weak connectivity
            if ((aM->aM[u][v] || aM->aM[v][u]) && !visited[v]) {
                visited[v] = 1;
                enqueue(q, v);
            }
        }
    }
    
    // Check if all nodes are visited
    for (int i = 0; i < 5; i++) {
        if (!visited[i]) {
            free(visited);
            return 0;
        }
    }
    
    free(visited);
    return 1;
}

void test_enqueue_and_dequeue() {
    struct Queue *q = initQueue();

    // Test enqueue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Test dequeue
    assert(dequeue(q) == 10);
    assert(dequeue(q) == 20);
    assert(dequeue(q) == 30);

    // Test dequeue from empty queue
    if (q->start == NULL) {
        fprintf(stderr, "Error: Attempt to dequeue from an empty queue.\n");
    }

    free(q);
}

void test_empty_queue() {
    struct Queue *q = initQueue();

    // Test dequeue from an empty queue
    if (q->start == NULL) {
        fprintf(stderr, "Error: Attempt to dequeue from an empty queue.\n");
    }

    free(q);
}

void bubbleSort(struct Node ** l1) {
    Node * cur = *l1;
    int n = 0;
    while (cur->next != NULL) {
        cur = cur->next;
        n++;
    }

    for (int i = 0; i < n; i++) {
        Node *new_cur = *l1;
        if (new_cur != NULL && new_cur->next != NULL) {
            if (new_cur->data > new_cur->next->data) {
                Node *temp = new_cur->next;
                new_cur->next = temp->next;
                temp->next = new_cur;
                *l1 = temp;
            }
        }
        new_cur = (*l1)->next;
        Node *prev = (*l1);
        while (new_cur->next != NULL) {
            if (new_cur->data > new_cur->next->data) {
                Node *temp = new_cur->next;
                new_cur->next = temp->next;
                temp->next = new_cur;
                prev->next = temp;
            } else {
                new_cur = new_cur->next;
            }
        } 
    }
}

void test_bubbleSort() {
    // Create a linked list
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 3;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 1;
    head->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->data = 2;
    head->next->next->next = NULL;

    // Apply bubbleSort
    bubbleSort(&head);

    // Verify the list is sorted
    Node *cur = head;
    assert(cur->data == 1);
    cur = cur->next;
    assert(cur->data == 2);
    cur = cur->next;
    assert(cur->data == 3);
    cur = cur->next;
    assert(cur == NULL);

    // Free the list
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    test_enqueue_and_dequeue();
    test_empty_queue();

    printf("All tests passed!\n");

    test_bubbleSort();
    printf("Bubble sort test passed!\n");

    return 0;
}
