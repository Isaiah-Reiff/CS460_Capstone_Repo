#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

int main(int argc, char *argv[]) {
    char destination[BUF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    strncpy(destination, argv[1], BUF_SIZE - 1);
    destination[BUF_SIZE - 1] = '\0';

    printf("Copied: %s\n", destination);
    return 0;
}
