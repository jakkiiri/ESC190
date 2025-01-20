#include <stdio.h>
#include <stdlib.h>

// string length function
int my_strlen(char *s) {
    int cur_i = 0;
    while (s[cur_i] != '\0') {
        cur_i++;
    }
    return cur_i;
}

// recursive string length function
int recursive_my_strlen(char *s) {
    if (s[0] == '\0') {
        return 0;
    }

    return 1 + my_strlen(s+1);
}

// example of passing array into function
// 8 is returned, which is the size of the pointer
// address of arrays are in 4 increments
void sz(int *a) {
    printf("%d\n", sizeof(a));
}

int main() {
    // example
    char s[] = "abc";
    printf("%d\n", my_strlen(s));
    printf("%d\n", recursive_my_strlen(s));

    // malloc: allocating memory 
    // local arrays disappear once a function has finished running
    // cannot return local arrays
    // arrays in C are not resizable
    // malloc allocates space in the memory table to store a block of values

    // allocates space for 150 integers
    // malloc returns the address of element 0
    // cast the address to int *
    int *block_int = (int *)malloc(sizeof(int)*150);
    block_int[0] = 5;
    block_int[1] = 7;
    printf("%d%d\n", block_int[0], block_int[1]);

    // sizeof
    // sizeof(int) usually 4 bytes
    // sizeof(char) // always 1 byte
    // sizeof(char*) // usually addresses take up 8 bytes
    // NOT the length of a string/length
    // sizeof(int*) same thing

    int arr[] = {1,2,3};
    printf("%d\n", sizeof(arr)/sizeof(arr[0])); // sizeof(arr) is the amount of space in memory the entire array takes
    // dividing the size of an individual element gives the number of elements
    // note: if arr is passed to a function, it is converted to a pointer
    sz(arr);


    return 0;
}