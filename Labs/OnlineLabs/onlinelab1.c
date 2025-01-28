#include <stdio.h>

// Q1
// The function returns the index of the first occurrence of the element elem 
// in a block of ints a of size sz. Assume elem occurs in a.
int linear_search(int *a, int sz, int elem) {
    for (int i = 0; i < sz; i++) {
        if (a[i] == elem) {
            return i; 
        }
    }
}

// Q2
// Write the following function, which reverses the block of ints arr, which is of size sz. 
// For example, if arr starts out as {5, 6, 7, 8}, it should become {8, 7, 6, 5}
void reverse_arr(int *arr, int sz) {
    int temp;
    for (int i = 0; i < sz/2; i++) {
        temp = arr[i];
        arr[i] = arr[sz-i-1];
        arr[sz-i-1] = temp;
    }
}

int main () {

    // Question 0: Compile Hello World
    printf("%s\n", "Hello World");

    // Question 1: Test Linear Search
    int arr[8] = {1, 5, 7, 2, 4, 3, 10, 39};
    printf("Index of 3: %d\n", linear_search(arr, 8, 3));

    // Question 2: Test Reverse Array
    reverse_arr(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}