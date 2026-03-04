#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

int main(void) {
    char result[BUF_SIZE] = "Hello, ";
    const char *suffix = "World!";

    size_t current_len = strlen(result);
    size_t remaining   = BUF_SIZE - current_len - 1;

    strncat(result, suffix, remaining);

    printf("%s\n", result);
    return 0;
}
