#include <stdio.h>
#include <string.h>

#define TOKEN_MAX 16
#define INPUT_MAX 256

int parse_token(const char *input, char *out, size_t out_size) {
    size_t i = 0;
    while (i < out_size - 1 && input[i] != '\0' && input[i] != ' ' && input[i] != '\n') {
        out[i] = input[i];
        i++;
    }
    out[i] = '\0';
    return (int)i;
}

int main(void) {
    char line[INPUT_MAX];
    char token[TOKEN_MAX];

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }

    int len = parse_token(line, token, sizeof(token));
    if (len == 0) {
        fprintf(stderr, "No token found\n");
        return 1;
    }

    printf("Token: '%s' (%d chars)\n", token, len);
    return 0;
}
