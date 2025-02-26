#include <stdio.h>
#include <stdlib.h>
#include "intset.h"
#include "intset.c"

void test_intset_operations() {
    struct intset *s1;
    struct intset *s2;
    struct intset *s3;
    intset_create(&s1);
    intset_create(&s2);

    int to_addA[5] = {5, 4, 4, 10, 4};
    int to_addB[4] = {2, 2, 3, 4};
    int to_addC[2] = {10, 12};

    intset_add(s1, to_addA, 5);
    intset_add(s1, to_addC, 2);
    intset_add(s2, to_addB, 3);

    intset_union(s1, s2, &s3);

    printf("Is 2 in s1? %d (Expected: 0)\n", intset_iselem(s1, 2));
    printf("Is 3 in s2? %d (Expected: 1)\n", intset_iselem(s2, 3));
    printf("Is 4 in s3? %d (Expected: 1)\n", intset_iselem(s3, 4));

    intset_remove(s1, 4);
    printf("Is 4 in s1? %d (Expected: 0)\n", intset_iselem(s1, 4));
}

void test_intset_add() {
    struct intset *s;
    intset_create(&s);

    int to_add[5] = {1, 2, 3, 4, 5};
    intset_add(s, to_add, 5);

    printf("Is 1 in s? %d (Expected: 1)\n", intset_iselem(s, 1));
    printf("Is 5 in s? %d (Expected: 1)\n", intset_iselem(s, 5));
    printf("Is 6 in s? %d (Expected: 0)\n", intset_iselem(s, 6));
}

void test_intset_remove() {
    struct intset *s;
    intset_create(&s);

    int to_add[3] = {1, 2, 3};
    intset_add(s, to_add, 3);

    intset_remove(s, 2);
    printf("Is 2 in s? %d (Expected: 0)\n", intset_iselem(s, 2));
    printf("Is 3 in s? %d (Expected: 1)\n", intset_iselem(s, 3));
}

void test_intset_union() {
    struct intset *s1;
    struct intset *s2;
    struct intset *s3;
    intset_create(&s1);
    intset_create(&s2);

    int to_add1[3] = {1, 2, 3};
    int to_add2[3] = {3, 4, 5};

    intset_add(s1, to_add1, 3);
    intset_add(s2, to_add2, 3);

    intset_union(s1, s2, &s3);

    printf("Is 1 in s3? %d (Expected: 1)\n", intset_iselem(s3, 1));
    printf("Is 4 in s3? %d (Expected: 1)\n", intset_iselem(s3, 4));
    printf("Is 5 in s3? %d (Expected: 1)\n", intset_iselem(s3, 5));
    printf("Is 6 in s3? %d (Expected: 0)\n", intset_iselem(s3, 6));
}

int main(void) {
    printf("Running intset tests...\n");

    test_intset_operations();
    test_intset_add();
    test_intset_remove();
    test_intset_union();

    printf("All tests completed.\n");
    return 0;
}
