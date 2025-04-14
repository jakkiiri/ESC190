#include <stdio.h>
#include <stdlib.h>

void swap (int *list, int i, int j) {
    int t = list[i];
    list[i] = list[j];
    list[j] = t;
}

void dutch (int *list, int size) {
    // insertion sort 
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (list[i] > list[j]) {
                swap(list, i, j); 
            }
        }
    }
}

int main() {
    int list[] = {2, 1, 0, 1, 1, 2, 1, 0, 0};
    dutch(list, 9);
    for (int i = 0; i < 9; i++) {
        printf("%d ", list[i]);
    }
}