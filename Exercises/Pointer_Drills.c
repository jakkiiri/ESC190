#include <stdio.h>

// 6
void change_int (int* p_a) {
    *p_a = 69;
}

// 10 
void change_int_1 (int** p_p_a) {
    **p_p_a = 46;
}

int main () {

    // 1
    int a = 42;
    // 2
    int* p_a = &a;
    // 3
    *p_a = 43;
    // 4
    int b = 1;
    p_a = &b;
    // 6
    printf("%d\n", a);
    change_int(&a);
    printf("%d\n", a);
    // 7
    p_a = &a;
    a = 42;
    printf("%d\n", a);
    change_int(p_a);
    printf("%d\n", a);
    // 8 & 9
    int** p_p_a = &p_a;
    // 10
    change_int_1(p_p_a);
    printf("%d\n", a);




    return 0;
}