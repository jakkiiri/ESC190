#include <stdlib.h>
#include <stdio.h>
#ifndef NODE_H
#define NODE_H


typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct LL {
    node *head;
    int size;
} LL;

#endif