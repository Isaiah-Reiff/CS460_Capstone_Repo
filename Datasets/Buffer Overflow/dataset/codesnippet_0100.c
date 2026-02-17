#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RING_SIZE 8

typedef struct {
    unsigned char buf[RING_SIZE];
    size_t        head;
    size_t        tail;
    size_t        count;
} RingBuffer;

void ring_init(RingBuffer *rb) {
    memset(rb->buf, 0, RING_SIZE);
    rb->head  = 0;
    rb->tail  = 0;
    rb->count = 0;
}

int ring_write(RingBuffer *rb, unsigned char byte) {
    if (rb->count == RING_SIZE) {
        return -1;
    }
    rb->buf[rb->tail] = byte;
    rb->tail = (rb->tail + 1) % RING_SIZE;
    rb->count++;
    return 0;
}

int ring_read(RingBuffer *rb, unsigned char *out) {
    if (rb->count == 0) {
        return -1;
    }
    *out = rb->buf[rb->head];
    rb->head = (rb->head + 1) % RING_SIZE;
    rb->count--;
    return 0;
}

int main(void) {
    RingBuffer rb;
    ring_init(&rb);

    for (unsigned char i = 1; i <= 5; i++) {
        if (ring_write(&rb, i) != 0) {
            fprintf(stderr, "Buffer full\n");
            return 1;
        }
    }

    unsigned char val;
    while (ring_read(&rb, &val) == 0) {
        printf("%u\n", val);
    }

    return 0;
}
