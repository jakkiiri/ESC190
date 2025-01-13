#include <stdio.h>

// exercises

// this changes the value of a
// a is passed by reference(address of a is passed)
void change_a(int* p_a){
    *p_a = 43;
}

// this creates a local a which is not associated with the a in main
// a is passed by value
void dont_change_a (int a) {
    a = 40;
}

void change_arr0(int *p_a) {
    *p_a = 43;
}

int main() {
    int a = 5;
    change_a(&a);
    printf("%d\n", a); // 43

    dont_change_a(a);
    printf("%d\n", a); // still 43

    int arr[3] = {5, 6, 7};
    change_arr0(arr); // changes the first element (address of first element passed in)
    change_arr0(&(arr[0])); // same thing, the address of the first element is passed in 
    return 0;
}