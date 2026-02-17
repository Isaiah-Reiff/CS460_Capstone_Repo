#include <stdio.h>
#include <string.h>

#define NAME_LEN  32
#define EMAIL_LEN 64

typedef struct {
    char name[NAME_LEN];
    char email[EMAIL_LEN];
    int  age;
} Record;

int record_set_name(Record *r, const char *name) {
    if (strlen(name) >= NAME_LEN) {
        return -1;
    }
    strncpy(r->name, name, NAME_LEN - 1);
    r->name[NAME_LEN - 1] = '\0';
    return 0;
}

int record_set_email(Record *r, const char *email) {
    if (strlen(email) >= EMAIL_LEN) {
        return -1;
    }
    strncpy(r->email, email, EMAIL_LEN - 1);
    r->email[EMAIL_LEN - 1] = '\0';
    return 0;
}

int main(void) {
    Record r;
    memset(&r, 0, sizeof(r));

    if (record_set_name(&r, "Alice") != 0 ||
        record_set_email(&r, "alice@example.com") != 0) {
        fprintf(stderr, "Field too long\n");
        return 1;
    }
    r.age = 30;

    printf("Name : %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Age  : %d\n", r.age);
    return 0;
}
