#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pyinteger.h"

void plusplus(pyinteger *p) {
    for (int i = p->size - 1; i >= 0; i--) {
        if (p->value[i] != 9) {
            p->value[i]++;
            break;
        } else {
            p->value[i] = 0;
            if (i == 0) {
                p->capacity = p->capacity*2 + 1;
                p->size++;
                p->value = (int *) realloc (p->value, p->capacity * sizeof(int));
                memmove(p->value + 1, p->value, (p->size * sizeof(int)));
                p->value[0] = 1;
            }
        }
    }
}

void add(pyinteger *p1, pyinteger *p2) {
    int power = 1;
    for (int i = p2->size-1; i >= 0; i--) {
        int loop_times = (p2->value[i]) * power;
        for (int k = 0; k < loop_times; k++) {
            plusplus(p1);
        }
        power = power * 10;
    }
}



