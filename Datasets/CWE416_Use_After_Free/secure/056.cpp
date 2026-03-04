#include <iostream>
#include <memory>
class RAII{
    std::unique_ptr<int> p;
public:
    RAII():p(new int(5)){}
    int val()const{return *p;}
};
int main(){
    RAII r;
    std::cout<<r.val()<<std::endl;
    return 0;
}
