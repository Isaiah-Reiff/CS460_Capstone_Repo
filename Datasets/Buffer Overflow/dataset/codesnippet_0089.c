#include <stdio.h>
#include <string.h>

int shift_right(char *buf, size_t buf_size, size_t data_len, size_t shift) {
    if (data_len + shift >= buf_size) {
        return -1;
    }
    memmove(buf + shift, buf, data_len);
    memset(buf, ' ', shift);
    return 0;
}

int main(void) {
    char buffer[32] = "ABCDE";
    size_t len = strlen(buffer);

    if (shift_right(buffer, sizeof(buffer), len, 3) != 0) {
        fprintf(stderr, "Shift would exceed buffer\n");
        return 1;
    }

    buffer[sizeof(buffer) - 1] = '\0';
    printf("'%s'\n", buffer);
    return 0;
}
