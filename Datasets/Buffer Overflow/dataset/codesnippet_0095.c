#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void *alloc_matrix(size_t rows, size_t cols, size_t elem_size) {
    if (cols != 0 && rows > SIZE_MAX / cols) {
        return NULL;
    }
    size_t total = rows * cols;
    if (elem_size != 0 && total > SIZE_MAX / elem_size) {
        return NULL;
    }
    return calloc(total, elem_size);
}

int main(void) {
    size_t rows = 10, cols = 10;
    int *matrix = (int *)alloc_matrix(rows, cols, sizeof(int));

    if (matrix == NULL) {
        fprintf(stderr, "Allocation failed or overflow detected\n");
        return 1;
    }

    for (size_t i = 0; i < rows * cols; i++) {
        matrix[i] = (int)i;
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%3d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
