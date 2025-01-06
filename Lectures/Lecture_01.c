#include <stdio.h>

// function named main, returns a value of type int
// no parameters
int main() {
    int n; // declare variable n, type int
    n = 25; // set n to 25
    printf("%d\n", n);
    char c = '@';
    int *p_a = 0; // p_a is type int *, address of int

    p_a = &n; // & means "address of"
    // RHS: the address where the variable n is stored
    // put the RHS in the LHS

    int m = *p_a; // when on the RHS, * means get the value at the address
    // *p_a is the value at the address p_a
    // m is now 25

    char *s = "abc"; // s is the address where 'a' is
    // s+1 is the address where 'b' is
    // etc
    // s_3 is the address where '\0' is (null)
    // C strings always have null at the end

    printf("The string is: %s\n", s); // print abc
    printf("The NULL is %c", s[3]); // print the NULL
    return 0;
}