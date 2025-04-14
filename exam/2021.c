#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_all(char **strs, int strs_sz0) {
    // obtain entire length
    int length = 0;
    for (int i = 0; i < strs_sz0; i++) {
        length += strlen(strs[i]);
    }
    char *str = (char *) malloc(sizeof(char)*(length+1));
    str[0] = '\0'; // Initialize the string to be empty
    for (int i = 0; i < strs_sz0; i++) {
        strcat(str, strs[i]);
    }
    return str;
}

int main(void){
    char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
    char *all = concat_all(strs, 4); 
    printf("%s\n", all); //ESCMATMSECIV
    free(all);
}