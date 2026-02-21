#include <stdlib.h>
#include <stdio.h>
void process(char *p){
    if(!p) return;
    printf("%c\n",p[0]);
}
int main(void){
    char *a = malloc(8);
    if(!a) return 1;
    a[0]='X';
    a[1]='\0';
    process(a);
    free(a);
    a = NULL;
    return 0;
}
