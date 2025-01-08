#include <stdio.h>

// functions

int add (int a, int b) {
    return a+b;
}

// function with pointers (similar to python)
void f (int* p_a){
    *p_a = 43;
}
// changes the int value at the address p_a to 43

int main() {
    // variable declaration in C
    int a = 42;
    long int la = 2103984203L; // can store more than int
    char c = '@'; // character

    char* s = "abs"; // "string": the address of the first character in the sequence
    // 'a', 'b', 's', '\0' last character null

    char* p_c = &c; //& "address of"

    // don't change address manually like p_c = 123458920;
    // make sure the RHS is a valid address
    *p_c; // get the value at address p_c (automatically type char unless converted)
    //*c: ERROR, c is not an address
    // **p_c;

    // arrays
    int arr[] = {5, 10, 2};
    printf("%d\n", arr[1]);  

    // more pointers
    /*
    int a = 42;
    int *p_a = &a; // p_a is the address of a

    char *s = "abc"; // s is the address where the 'a' is

    *p_a = 43; // 43 is now in the address p_a
    
    */

    // testing pointer funciton
    printf("%d\n", a);
    // change the int value
    f (&a);
    printf("%d\n", a);

    // arrays and pointers
    printf("%d\n", *arr); // prints first index
    // array identifier is the address of the first element
    printf("%d\n", arr[0]);
    // a[0] is converted to *(a+0), the first element of a
    printf("%d\n", *(arr+1)); // calling the second index by calling the second consecutive index

    return 0;
}

