#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int first_occurrence(char *str1, char *str2, int i, int j) {
    if (j == strlen(str2)) {
        return i;
    }
    if (i == (strlen(str1) - strlen(str2) + 1)) {
        return -1;
    }
    if (str1[i+j] == str2[j]) {
        return first_occurrence(str1, str2, i, j+1);
    } else{
        return first_occurrence(str1, str2, i+1, 0);
    }
}

int main() {
    char str1[] = "aEngSci EngSci Trackone";
    char str2[] = "EngSci";
    printf("%d\n", first_occurrence(str1, str2, 0, 0));
    return 0;
}