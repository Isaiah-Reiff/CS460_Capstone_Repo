#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bounded_copy(void *dst, size_t dst_size, const void *src, size_t src_size) {
    if (src_size > dst_size) {
        return -1;
    }
    memcpy(dst, src, src_size);
    return 0;
}

int main(void) {
    char source[] = "hello";
    char destination[32];

    memset(destination, 0, sizeof(destination));

    if (bounded_copy(destination, sizeof(destination), source, strlen(source) + 1) != 0) {
        fprintf(stderr, "Copy would overflow destination\n");
        return 1;
    }

    printf("Destination: %s\n", destination);
    return 0;
}
