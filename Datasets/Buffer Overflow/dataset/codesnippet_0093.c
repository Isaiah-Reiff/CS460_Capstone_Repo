#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  *data;
    size_t length;
    size_t capacity;
} Buffer;

int buffer_append(Buffer *b, const char *src, size_t src_len) {
    if (b->length + src_len + 1 > b->capacity) {
        size_t new_cap = b->capacity * 2 + src_len + 1;
        char *tmp = (char *)realloc(b->data, new_cap);
        if (tmp == NULL) {
            return -1;
        }
        b->data     = tmp;
        b->capacity = new_cap;
    }
    memcpy(b->data + b->length, src, src_len);
    b->length += src_len;
    b->data[b->length] = '\0';
    return 0;
}

int main(void) {
    Buffer b;
    b.capacity = 32;
    b.length   = 0;
    b.data     = (char *)malloc(b.capacity);

    if (b.data == NULL) {
        return 1;
    }
    b.data[0] = '\0';

    const char *words[] = {"one ", "two ", "three"};
    for (size_t i = 0; i < 3; i++) {
        if (buffer_append(&b, words[i], strlen(words[i])) != 0) {
            fprintf(stderr, "Append failed\n");
            free(b.data);
            return 1;
        }
    }

    printf("%s\n", b.data);
    free(b.data);
    return 0;
}
