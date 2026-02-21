#include <iostream>
#include <memory>
std::shared_ptr<int> make(int x){
    return std::make_shared<int>(x);
}
int main(){
    auto a = make(10);
    auto b = a;
    std::cout<<*a<<" "<<*b<<std::endl;
    return 0;
}
