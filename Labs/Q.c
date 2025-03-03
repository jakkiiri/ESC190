#include <stdlib.h>
#include "Q.h"

void create_queue(queue ** p_q, int size, int start, int num_elems) {
    (*p_q) = malloc(sizeof(queue));
    (*p_q)->list = malloc(sizeof(int)*size);
    (*p_q)->size = size;
    (*p_q)->start = start;
    (*p_q)->num_elems = num_elems;
}

void destroy_queue(queue *q) {
    free(q->list);
    free(q);
}

void print_queue(queue *q) {
    printf("index\t");
    for (int i = 0; i < q->size; i++) {
        printf("%d\t", i);
    }
    printf("\n     \t");
    for (int i = 0; i < q->size; i++) {
        if (q->list[i] != 0) {
            printf("%d\t", q->list[i]);
        } else {
            printf("\t");
        }
    }
    printf("\nBegin at index: %d\n", q->start);
    int end;
    if (q->start + q->num_elems > q->size) {
        end = (q->start + q->num_elems) % q->size - 1;
    } else {
        end = q->start + q->num_elems - 1;
    }
    printf("End at index: %d\n", end);
    printf("---------------------------------------------------------------------\n");
}

void enqueue (queue *q, int data) {
    int end_index;
    if (q->start + q->num_elems >= q->size) {
        end_index = (q->start + q->num_elems) % q->size;
    } else {
        end_index = q->start + q->num_elems;
    }
    q->list[end_index] = data;
    q->num_elems++;
    printf("After enqueue %d:\n", data);
    print_queue(q);
}

int dequeue(queue *q) {
    int data = q->list[q->start];
    q->list[q->start] = NULL;
    q->start = (q->start + 1) % q->size;
    q->num_elems--;
    printf("After dequeue: \n");
    print_queue(q);
    return data;
}

