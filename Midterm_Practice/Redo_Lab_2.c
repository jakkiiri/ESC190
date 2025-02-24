#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Q1
void set_even_to_zero (int *block, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            block[i] = 0;
        }
    }
}

// Q2
void str_cat1 (char *str1, char *str2) {
    // using index
    int i;
    for (i = 0; str1[i] != '\0'; i++) {

    }
    int j;
    for (j = 0; str2[j] != '\0'; i++, j++) {
        str1[i] = str2[j];
    }
    str1[i] = '\0';
}

void str_cat2 (char *str1, char *str2) {
    // loop str1 to the null character
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int binary_search_low (int *arr, int size, int target) {
    int result = -1;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int binary_search_high (int *arr, int size, int target) {
    int result = -1;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int my_atoi(char *str) {
    int result = 0;
    // need to reverse the string (cooked)
    int i;
    for (i = 0; str[i] != '\0'; i++) {

    }
    // new string
    char *new_str = (char *) malloc ((i + 1) * sizeof(char));
    int j;
    for (j = 0, i--; i >= 0; j++, i--) {
        new_str[j] = str[i];
    }
    new_str[j] = '\0';
    int multiplier = 1;
    for (int k = 0; k < j; k++) {
        result += (int) (new_str[k]-'0') * multiplier;
        multiplier *= 10;
    }
    free(new_str);
    return result;

}

int main() {

    int input[] = {5, 6, 7, 8};
    set_even_to_zero(input, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    char str1[] = "Hello";
    char str2[] = " World";
    str_cat1(str1, str2);
    printf("%s\n", str1);

    char str3[] = "Hello";
    char str4[] = " World";
    str_cat2(str3, str4);
    printf("%s\n", str3);

    int arr[] = {1, 4, 5, 5, 5, 5, 6, 7, 9};
    printf("%d\n", binary_search_low(arr, 9, 5));
    printf("%d\n", binary_search_high(arr, 9, 5));

    char *my_str = "46920";
    printf("%d\n", my_atoi(my_str));

    

    return 0;
}