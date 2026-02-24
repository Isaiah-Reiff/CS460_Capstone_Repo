#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t capacity = 8;
    size_t length = 0;
    int *arr = (int *)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Initial allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        if (length == capacity) {
            capacity *= 2;
            int *tmp = (int *)realloc(arr, capacity * sizeof(int));
            if (tmp == NULL) {
                fprintf(stderr, "Reallocation failed\n");
                free(arr);
                return 1;
            }
            arr = tmp;
        }
        arr[length++] = i * 3;
    }

    for (size_t j = 0; j < length; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
