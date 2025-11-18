#include <stdlib.h>
#include <stdio.h>
int main(void){
    char *p = malloc(64);
    if(!p) return 1;
    for(int i=0;i<63;i++) p[i]='A';
    p[63]='\0';
    printf("%s\n",p);
    free(p);
    p = NULL;
    return 0;
}
