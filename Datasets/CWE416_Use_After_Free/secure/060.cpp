#include <iostream>
#include <memory>
struct Holder{
    std::unique_ptr<int> v;
    Holder(int x):v(new int(x)){}
    int get()const{return *v;}
};
int main(){
    Holder h(7);
    std::cout<<h.get()<<std::endl;
    return 0;
}
