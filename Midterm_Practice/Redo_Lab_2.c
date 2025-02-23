#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Q1
void set_even_to_zero (int *block, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            block[i] = 0;
        }
    }
}

// Q2


int main() {

    int input[] = {5, 6, 7, 8};
    set_even_to_zero(input, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}