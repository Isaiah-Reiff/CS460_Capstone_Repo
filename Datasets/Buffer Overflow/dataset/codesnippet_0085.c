#include <stdio.h>

#define ARRAY_LEN 10

int get_element(const int *arr, size_t arr_len, size_t index, int *out) {
    if (index >= arr_len) {
        return -1;
    }
    *out = arr[index];
    return 0;
}

int main(void) {
    int data[ARRAY_LEN] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int value;
    size_t idx = 5;

    if (get_element(data, ARRAY_LEN, idx, &value) != 0) {
        fprintf(stderr, "Index %zu out of bounds\n", idx);
        return 1;
    }

    printf("data[%zu] = %d\n", idx, value);
    return 0;
}
