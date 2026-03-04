#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 64

int write_record(FILE *fp, const void *data, size_t size) {
    size_t written = fwrite(data, 1, size, fp);
    if (written != size) {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    unsigned char data[DATA_SIZE];
    memset(data, 0xAB, DATA_SIZE);

    if (write_record(fp, data, DATA_SIZE) != 0) {
        fprintf(stderr, "Write failed\n");
        fclose(fp);
        return 1;
    }

    printf("Wrote %d bytes to %s\n", DATA_SIZE, argv[1]);
    fclose(fp);
    return 0;
}
