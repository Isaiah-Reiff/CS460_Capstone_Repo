#include <stdlib.h>
#include <stdio.h>
int *make_array(size_t n){
    int *arr = malloc(n*sizeof(int));
    if(!arr) return NULL;
    for(size_t i=0;i<n;i++) arr[i]=(int)i;
    return arr;
}
int main(void){
    int *arr = make_array(5);
    if(!arr) return 1;
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    putchar('\n');
    free(arr);
    arr = NULL;
    return 0;
}
