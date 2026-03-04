#include <array>
#include <iostream>
int main(){
    std::array<int,4> a{{1,2,3,4}};
    for(int x:a) std::cout<<x<<" ";
    std::cout<<"
";
    return 0;
}
