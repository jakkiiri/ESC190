#if !defined(PYINTEGER_H)
#define PYINTEGER_H

typedef struct pyinteger {
    int *value;
    int size;
    int capacity;
} pyinteger;

void plusplus(pyinteger *p);
void add(pyinteger *p1, pyinteger *p2);
#endif

