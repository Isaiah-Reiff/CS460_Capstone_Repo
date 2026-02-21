#include <vector>
#include <iostream>
int main(){
    std::vector<int> v{1,2,3,4,5};
    for(int x:v) std::cout<<x<<" ";
    std::cout<<"
";
    return 0;
}
