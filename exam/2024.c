#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int my_median(int *arr, int sz) {
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr[(sz-1)/2];
}

void count_letters(char *s, int counts[]) {
    while (*s != '\0') {
        int diff = (*s) - 'a';
        if (diff > 0 && diff < 26) {
            counts[diff]++;
        }
        s++;
    }
}

char *reverse_words(char *str) {
    int n = strlen(str);
    char *reverse = (char *) malloc(sizeof(char) * (n + 1));
    
    if (!reverse) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    reverse[0] = '\0'; // Initialize reverse as an empty string

    char *temp = (char *)malloc(strlen(str) + 1); // Allocate memory for the duplicate string
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        free(reverse);
        exit(1);
    }
    strcpy(temp, str); // Copy the input string into the allocated memory

    char *token = strtok(temp, " ");
    while (token) {
        int len = strlen(token);
        for (int i = len - 1; i >= 0; i--) {
            size_t current_len = strlen(reverse);
            if (current_len + 1 >= n + 1) { // Ensure no overflow
                fprintf(stderr, "Buffer overflow detected\n");
                free(temp);
                free(reverse);
                exit(1);
            }
            strncat(reverse, &token[i], 1);
        }
        if (strlen(reverse) + 1 < n + 1) { // Ensure space for the next space
            strcat(reverse, " "); // Add a space after each reversed word
        }
    }

    free(temp);
    if (strlen(reverse) > 0 && reverse[strlen(reverse) - 1] == ' ') {
        reverse[strlen(reverse) - 1] = '\0'; // Remove the trailing space
    }
    return reverse;
}

int is_increasing(int *arr, int sz) {
    if (sz <= 1) {
        return 1;
    } else {
        if (arr[0] >= arr[1]) {
            return 0;
        } else {
            return is_increasing(arr+1, sz - 1);
        }
    }
}

typedef struct Queue {
    char *list;
    int start;
    int end;
    int size;
} Queue;

void create_queue(Queue **q, int size) {
    *q = (Queue *) malloc(sizeof(Queue));
    (*q)->size = size;
    (*q)->list = (char *) malloc (sizeof(char) * (size + 1));
    (*q) -> start = 0;
    (*q) -> end = 0;
}

void enqueue (Queue **q, char elem) {
    int r = (*q)->end;
    int next_r = (r == (*q)->size - 1) ? 0 : r + 1;

    if (next_r == (*q)->start) { // Check if the queue is full
        fprintf(stderr, "Queue is full. Cannot enqueue '%c'.\n", elem);
        return;
    }

    (*q)->list[r] = elem;
    (*q)->end = next_r;
}

char dequeue (Queue ** q) {
    char elem = (*q) -> list[(*q)->start];
    (*q)->list[(*q)->start] = ' ';
    if ((*q)->start == ((*q)->size)-1) {
        (*q)->start = 0;
    } else {
        (*q)->start++;
    }
    return elem;
}

void test_queue() {
    Queue *q;
    create_queue(&q, 5);

    enqueue(&q, 'a');
    enqueue(&q, 'b');
    enqueue(&q, 'c');
    assert(dequeue(&q) == 'a');
    assert(dequeue(&q) == 'b');
    enqueue(&q, 'd');
    enqueue(&q, 'e');
    assert(dequeue(&q) == 'c');
    assert(dequeue(&q) == 'd');
    assert(dequeue(&q) == 'e');

    free(q->list);
    free(q);
}

int main() {
    int arr[] = {1, 6, 3, 5, 2, 4, 7};
    printf("%d\n", my_median(arr, 7));

    char str[] = "gb124&yyz_cr";
    int counts[26] = {0};
    count_letters(str, counts);
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }

    int arr1[] = {1, 5, 10, 12};
    int num1 = 4;
    int arr2[] = {1, 2, 2, 3};
    printf("%d\n", is_increasing(arr1, num1));
    printf("%d\n", is_increasing(arr2, num1));

    test_queue();

}
