#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

int main(void) {
    int **matrix = (int **)calloc(ROWS, sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Row allocation failed\n");
        return 1;
    }

    for (size_t i = 0; i < ROWS; i++) {
        matrix[i] = (int *)calloc(COLS, sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Column allocation failed at row %zu\n", i);
            for (size_t k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }

    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            matrix[i][j] = (int)(i * COLS + j);
        }
    }

    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    return 0;
}
