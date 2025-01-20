#include <stdio.h>
#include <ctype.h>

// Question 1
void set_even_to_zero(int *block, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            block[i] = 0;
        }
    }
}

// Question 2
// helper str len function
int str_len (char* str) {
    if (str[0] == '\0') {
        return 0;
    }
    return 1 + str_len(str+1);
}

int str_len_const(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// using index i
void strcat_index(char *destination, const char *source) {
    // find the end address of destination
    destination = destination + str_len(destination);
    for (int i = 0; i < str_len_const(source); i++) {
        destination[i] = source[i];
        if (i == str_len_const(source) - 1) {
            destination[i+1] = '\0';
        }
    }
}

// using just pointer arithmetic
void strcat_pointer(char *destination, const char *source) {
    // find the end address of destination
    destination = destination + str_len(destination);
    int len = 0;
    for (int i = 0; i < str_len_const(source); i++) {
        *(destination + i) = *(source + i);
    }
}

// Question 3
int strcmp (const char* str1, const char* str2) {
    if (str1[0] == '\0' && str2[0] == '\0') {
        return 0;
    } else if (str1[0] != str2[0]) {
        return (int) (str1[0]) - (int) (str2[0]);
    } else {
        return strcmp(str1 + 1, str2 + 1);
    }
}

// Question 5

// helper (compute 10 to whatever power)
int power_10 (int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= 10;
    }
    return result;
}

int my_atoi(char *str) {
    int len = str_len(str);
    int counter = len - 1;
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += (str[i] - '0') * power_10(counter);
        counter--;
    }
    return result;
}



int main() {
    // Question 1
    int block[] = {5, 6, 7, 8};
    set_even_to_zero(block, 4);
     for (int i = 0; i < 4; i++) {
        printf("%d", block[i]);
    }
    printf("\n");

    // Question 2
    char s1[] = "abc";
    const char *s2 = "def";
    strcat_index(s1, s2);
    printf("%s\n", s1);
    strcat_pointer(s1, s2);
    printf("%s\n", s1);
    // s1 == s2 see if the two strings have the same address
    // *s1 == *s2 see if the first character of the two strings are the same
    // strcmp(s1, s2) compares two strings, return 0 if same, other numbers if not same.

    // Question 3
    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
    printf("strcmp(str1, str3) = %d\n", strcmp(str1, str3));

    // Question 5
    char *number = "2025";
    printf("%d\n", my_atoi(number));

    return 0;
}