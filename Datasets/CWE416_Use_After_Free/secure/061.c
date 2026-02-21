#include <stdio.h>
int main(void){
    char buffer[32];
    for(int i=0;i<31;i++) buffer[i]='a';
    buffer[31]='\0';
    puts(buffer);
    return 0;
}
