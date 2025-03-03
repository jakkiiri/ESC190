#include <stdio.h>
#include <stdlib.h>
#include "pyinteger.h"
#include "pyint.c"

int main() {
    int *values = (int *) malloc (sizeof(int) * 3);
    values[0] = 9;
    values[1] = 9;
    values[2] = 9;
    int *values1 = (int *) malloc (sizeof(int) * 3);
    values1[0] = 9;
    values1[1] = 9;
    values1[2] = 9;
    pyinteger pyint = {values, 3, 6};
    pyinteger pyint1 = {values1, 3, 6};
    for (int i = 0; i < pyint.size; i++) {
        printf("%d", pyint.value[i]);
    }
    printf("\n");
    plusplus(&pyint);
    for (int i = 0; i < pyint.size; i++) {
        printf("%d", pyint.value[i]);
    }
    printf("\n");
    add(&pyint, &pyint1);
    for (int i = 0; i < pyint.size; i++) {
        printf("%d", pyint.value[i]);
    }
    return 0;
}