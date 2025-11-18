#include <stdlib.h>
#include <stdio.h>
typedef struct Node{int v;struct Node*next;}Node;
Node* new_node(int v){
    Node*n = malloc(sizeof(Node));
    if(!n) return NULL;
    n->v=v;
    n->next=NULL;
    return n;
}
void cleanup(Node*n){
    while(n){
        Node*t=n->next;
        free(n);
        n=t;
    }
}
int main(void){
    Node*a=new_node(1);
    Node*b=new_node(2);
    a->next=b;
    printf("%d %d\n",a->v,a->next->v);
    cleanup(a);
    a=NULL;
    return 0;
}
