#include <stdlib.h>
#include <stdio.h>
int main(void){
    int n = 10;
    int *arr = malloc(n * sizeof *arr);
    if(!arr) return 1;
    for(int i=0;i<n;i++) arr[i]=i;
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    putchar('\n');
    free(arr);
    arr = NULL;
    return 0;
}
