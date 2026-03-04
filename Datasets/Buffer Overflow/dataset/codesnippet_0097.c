#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAL_LEN 32

typedef struct Node {
    char         value[VAL_LEN];
    struct Node *next;
} Node;

Node *node_create(const char *val) {
    if (val == NULL || strlen(val) >= VAL_LEN) {
        return NULL;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }
    strncpy(n->value, val, VAL_LEN - 1);
    n->value[VAL_LEN - 1] = '\0';
    n->next = NULL;
    return n;
}

void list_free(Node *head) {
    while (head != NULL) {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(void) {
    const char *items[] = {"alpha", "beta", "gamma"};
    Node *head = NULL;
    Node *tail = NULL;

    for (size_t i = 0; i < 3; i++) {
        Node *n = node_create(items[i]);
        if (n == NULL) {
            fprintf(stderr, "Node creation failed\n");
            list_free(head);
            return 1;
        }
        if (tail == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%s\n", cur->value);
    }

    list_free(head);
    return 0;
}
