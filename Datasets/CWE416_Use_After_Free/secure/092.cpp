#include <iostream>
#include <memory>
int main(){
    std::unique_ptr<char[]> buf(new char[16]);
    buf[0]='A';
    buf[1]='\0';
    std::cout<<buf.get()<<std::endl;
    return 0;
}
