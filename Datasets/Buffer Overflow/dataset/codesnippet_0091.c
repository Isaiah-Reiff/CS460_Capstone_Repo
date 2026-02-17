#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t size = 16;
    unsigned char *buf = (unsigned char *)malloc(size);

    if (buf == NULL) {
        return 1;
    }

    memset(buf, 0, size);

    unsigned char *ptr = buf;
    unsigned char *end = buf + size;

    for (unsigned char val = 1; ptr < end; ptr++, val++) {
        *ptr = val;
    }

    for (size_t i = 0; i < size; i++) {
        printf("%3u", buf[i]);
    }
    printf("\n");

    free(buf);
    buf = NULL;
    return 0;
}
