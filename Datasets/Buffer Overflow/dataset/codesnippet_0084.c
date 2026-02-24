#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t n = 100;
    char *buf = (char *)malloc(n * sizeof(char));

    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    memset(buf, 0, n);
    strncpy(buf, "hello world", n - 1);

    printf("%s\n", buf);

    free(buf);
    buf = NULL;
    return 0;
}
