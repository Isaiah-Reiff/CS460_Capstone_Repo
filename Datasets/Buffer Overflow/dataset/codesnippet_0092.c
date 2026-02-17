#include <stdio.h>
#include <stdlib.h>

#define READ_BUF 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    unsigned char buf[READ_BUF];
    size_t total = 0;
    size_t n;

    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        total += n;
    }

    if (ferror(fp)) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    printf("Read %zu bytes\n", total);
    fclose(fp);
    return 0;
}
