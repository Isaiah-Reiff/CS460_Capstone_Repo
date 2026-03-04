#include <stdlib.h>
#include <stdio.h>
void safe_free(char **pp){
    if(pp && *pp){
        free(*pp);
        *pp = NULL;
    }
}
int main(void){
    char *p = malloc(10);
    if(!p) return 1;
    safe_free(&p);
    return 0;
}
