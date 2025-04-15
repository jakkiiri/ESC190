#include <stdio.h>
#include <stdlib.h>

typedef struct M {
    int **arr;
    int rows;
    int cols;

} M;

M *create_matrix(int rows, int cols) {
    M *matrix = (M *)malloc(sizeof(M));
    if (!matrix) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->arr = (int **)malloc(rows * sizeof(int *));
    if (!matrix->arr) {
        fprintf(stderr, "Memory allocation failed\n");
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->arr[i] = (int *)malloc(cols * sizeof(int));
        if (!matrix->arr[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(matrix->arr[j]);
            }
            free(matrix->arr);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}
