#include <vector>
#include <iostream>
int sum(const std::vector<int>&v){
    int s=0;
    for(int x:v) s+=x;
    return s;
}
int main(){
    std::vector<int> v(5,1);
    std::cout<<sum(v)<<std::endl;
    return 0;
}
