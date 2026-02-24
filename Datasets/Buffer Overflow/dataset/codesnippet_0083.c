#include <stdio.h>
#include <string.h>

#define LINE_MAX 256

int main(void) {
    char line[LINE_MAX];

    printf("Enter input: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Read error\n");
        return 1;
    }

    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    printf("You entered: %s\n", line);
    return 0;
}
