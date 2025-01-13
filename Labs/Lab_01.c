#include <stdio.h>

// Question 2
// set value of an integer to 10
void set_to_10 (int* p_a) {
    *p_a = 10;
}

// Question 3
// this function changes the content of the array
void change_array (char* arr) {
    for (int i = 0; i < 100; i++) {
        *(arr + i) = 'a';
    }
}

// Question 4
// insertion sort
void insertion_sort (int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Question 5
// string length
// complexity of O(n)
int str_len (char* str) {
    int len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

// Question 6
void seq_replace (int* arr1, unsigned long arr1_sz, int* arr2, unsigned long arr2_sz) {
    int j = 0;
    int* current = 0;
    for (int i = 0; i < arr1_sz - arr2_sz + 2; i++) {
        if (*(arr1 + i) == *(arr2 + j)) {
            if (j == 0) {
                current = arr1 + i;
            }
            j++;
        } else {
            j = 0;
        }
        if (j == arr2_sz) {
            for (int k = 0; k < arr2_sz; k++) {
                *(current + k) = 0;
            }
        }
    }
}

int main() {
    // Question 2
    int b = 5;
    set_to_10(&b);
    printf("%d\n", b); // 10

    // Question 3
    char arr[100];
    change_array(arr);
    printf("%c\n", arr[0]); // a

    // Question 4
    int i = 0;
    int a[5] = {2, 4, 5, 1, 3};
    for (i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    insertion_sort(a, *(&a+1)-a);
    for (i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    // Question 5
    char* str = "Spontaneous";
    int len = str_len(str);
    printf("%d\n", len);

    // Question 6
    int g[] = {5,6,7,8,6,7};
    int h[] = {6,7};
    seq_replace(g,6,h,2);
    for (i = 0; i < 6; i++) {
        printf("%d", g[i]);
    }

    return 0;
    
}