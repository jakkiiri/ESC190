#if !defined(Q)
#include "ArrayList.h"
#define Q
typedef struct queue {
    int *list;
    int size;
    int start;
    int num_elems;
} queue;

void create_queue(queue ** p_q);
void destroy_queue(queue q);
void enqueue(queue q, int data);
int dequeue(queue *q);

#endif