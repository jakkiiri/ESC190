//
// Created by Jakkii on 2025-02-22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change_a(int *p_a) {
    *p_a = 10;
}

int str_len(char *str) {
    int i = 0;
    while (*str != '\0') {
        i++;
        str++;
    }
    return i;
}

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    int condition = 0;
    for (int i = 0; i < arr1_sz - arr2_sz + 1; i++) {
        // check segment if first character matches
        if (arr1[i] == arr2[0]) {
            condition = 1;
            for (int temp = 1; temp < arr2_sz; temp++) {
                if (arr1[i+temp] != arr2[temp]) {
                    condition = 0;
                    break;
                }
            }
        }
        if (condition) {
            for (int j = 0; j < arr2_sz; j++) {
                arr1[i+j] = 0;
            }
            i = i + arr2_sz - 1;
            condition = 0;
        }
    }
}

int main () {
    // Question 2
    int a = 5;
    change_a (&a);

    // Question 3
    char arr1[100];
    for (int i = 0; i < 100; i++) {
        arr1[i] = 'E';
    }
    printf("%s\n", arr1);

    int arr[5] = {2, 4, 5, 3, 6};

    int i = 1;
    while (i < 5) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        i++;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    char *string1 = "gjiehub";

    printf("%d\n", str_len(string1));

    int ab[] = {5, 6, 7, 8, 6, 7};
    int ba[] = {6, 7};
    seq_replace(ab, 6, ba, 2);
    for (int i = 0; i < 6; i++) {
        printf("%d ", ab[i]);
    }
    printf("\n");

    return 0;
}


