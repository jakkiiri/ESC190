#include <stdio.h>

// function with local variable
int f0 (int a) {
    a = 3;
}

void f (int *p_a) {
    p_a = 0;
}

void f1 (int *p_a) {
    *p_a = 0;
}

int main() {
    // literals in C
    // data inputted directly into the code

    // initialize arrays with size
    int arr2[10]; // create an empty int array with 10 elements
    
    int a = 45;
    f(&a); // copies &a to local variable p_a.  Changing p_a has not effect
    f1(&a); // same thing, but a is changed since the function accesses the address
    // and changes the value

    // storing blocks of values
    // strings and arrays are stored consecutively
    // 1032: 'h', 1033:'i', 1034:'\0'
    // 2064: 3, (2064 + 4) 4 --> {3,4}
    // integer storing can take four spaces

    // example
    char *s = "hi";
    s+1; // the next consecutive address of 'h'
    printf("%c\n", *(s+1)); // this will print 'i'

    int arr[] = {3,4};
    arr+1;
    printf("%d\n", *(arr+1));

    int arr1[] = {6, 7, 8};
    printf("%p\n", arr1 + 1); // hex code of address
    printf("%ld\n", arr1); // convert the address of arr into decimal
    printf("%ld\n", arr1 + 1); // convert the address of arr into decimal
    // they are stored 4 apart (4 bytes?)
    // arr[5] is the same as *(arr+5)
    // this explains why index start with 0.  addition 0 to the default address yields the first element
    // *(arr1[0]) // would not compile
    
    return 0;
}