#include <stdio.h>

#define MSG_SIZE 128

int build_message(char *buf, size_t buf_len, const char *user, int code) {
    int written = snprintf(buf, buf_len, "User: %s | Code: %d", user, code);
    if (written < 0 || (size_t)written >= buf_len) {
        return -1;
    }
    return written;
}

int main(void) {
    char message[MSG_SIZE];

    if (build_message(message, sizeof(message), "alice", 42) < 0) {
        fprintf(stderr, "Message truncated or encoding error\n");
        return 1;
    }

    printf("%s\n", message);
    return 0;
}
