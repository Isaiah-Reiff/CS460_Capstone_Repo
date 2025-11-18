#include <iostream>
#include <memory>
#include <string>
int main(){
    auto p = std::make_unique<std::string>("hello");
    std::cout<<*p<<std::endl;
    return 0;
}
