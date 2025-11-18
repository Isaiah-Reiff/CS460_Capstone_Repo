#include <stdlib.h>
#include <stdio.h>
int main(void){
    int *p = malloc(sizeof(int));
    if(!p) return 1;
    *p = 42;
    printf("%d\n", *p);
    free(p);
    p = NULL;
    return 0;
}
