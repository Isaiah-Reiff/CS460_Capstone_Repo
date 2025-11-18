#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *create_copy(const char *s){
    size_t n = strlen(s)+1;
    char *buf = malloc(n);
    if(buf) memcpy(buf,s,n);
    return buf;
}
int main(void){
    char *x = create_copy("hello");
    if(!x) return 1;
    puts(x);
    free(x);
    x = NULL;
    return 0;
}
