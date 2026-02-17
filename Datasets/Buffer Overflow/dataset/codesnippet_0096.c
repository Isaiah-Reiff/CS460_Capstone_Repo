#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 32

typedef struct {
    unsigned char key[KEY_LEN];
    size_t        key_len;
} KeyStore;

void keystore_destroy(KeyStore *ks) {
    memset(ks->key, 0, sizeof(ks->key));
    ks->key_len = 0;
}

int keystore_load(KeyStore *ks, const unsigned char *src, size_t src_len) {
    if (src_len > KEY_LEN) {
        return -1;
    }
    memset(ks->key, 0, KEY_LEN);
    memcpy(ks->key, src, src_len);
    ks->key_len = src_len;
    return 0;
}

int main(void) {
    KeyStore ks;
    memset(&ks, 0, sizeof(ks));

    unsigned char raw[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    if (keystore_load(&ks, raw, sizeof(raw)) != 0) {
        fprintf(stderr, "Key too long\n");
        return 1;
    }

    printf("Loaded %zu-byte key\n", ks.key_len);
    for (size_t i = 0; i < ks.key_len; i++) {
        printf("%02x ", ks.key[i]);
    }
    printf("\n");

    keystore_destroy(&ks);
    return 0;
}
