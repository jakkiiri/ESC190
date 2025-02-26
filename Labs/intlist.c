#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intlist.h"

// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    IntList *new_list = (IntList *) malloc(sizeof(IntList));
    new_list->data = (int*) malloc(sizeof(int) * 100);
    memmove(new_list->data, data_arr, sizeof(int) * size);
    new_list->size = size;
    new_list->capacity = size;
    *p_IntList = new_list;
};


// Append new_elem to the end of list
void list_append(IntList *list, int new_elem) {
    if (list->capacity < sizeof(list->data) + sizeof(new_elem)) {
        int new_capacity = (list->capacity + 1) * 2;
        list->data = (int*) realloc(list->data, new_capacity*sizeof(int));
        if (list->data == NULL) {
            printf("ERROR : realloc failed");
            exit(1);
        }
        list->capacity = new_capacity;
        list->size = list->size + 1;
    }
    list->data[list->size-1] = new_elem;
};


// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index) {
    if (list->capacity <= list->size) {
        int new_capacity = (list->capacity + 1) * 2;
        list->data = (int*) realloc(list->data, new_capacity * sizeof(int));
        if (list->data == NULL) {
            printf("ERROR : realloc failed");
            exit(1);
        }
        list->capacity = new_capacity;
    }
    if (index > list->size || index < 0) {
        printf("ERROR : index %d is out of bounds", index);
        exit(1);
    }
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int));
    list->data[index] = new_elem;
    list->size = list->size + 1;
};

// Delete the element at index index

void list_delete(IntList *list, int index) {
    if (index >= list->size || index < 0) {
        printf("ERROR : index %d is out of bounds", index);
        exit(1);
    }
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int));
    list->size = list->size - 1;
};

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list) {
    free(list->data);
    free(list);
};

// Return the element at index index in list
int list_get(IntList *list, int index) {
    if (index + 1 > list->size || index < 0) {
        printf("ERROR : index %d is out of bounds", index);
        exit(1);
    }
    return list->data[index];
};