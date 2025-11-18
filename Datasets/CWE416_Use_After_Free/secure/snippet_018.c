#include <stdlib.h>
#include <stdio.h>
char *duplicate(const char *s){
    size_t len = 0;
    while(s[len]) len++;
    char *r = malloc(len+1);
    if(!r) return NULL;
    for(size_t i=0;i<=len;i++) r[i]=s[i];
    return r;
}
int main(void){
    char *s = duplicate("data");
    if(!s) return 1;
    printf("%s\n", s);
    free(s);
    s = NULL;
    return 0;
}
