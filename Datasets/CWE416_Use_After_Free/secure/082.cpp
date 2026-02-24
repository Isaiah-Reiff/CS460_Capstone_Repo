#include <iostream>
#include <string>
#include <sstream>
int main(){
    std::ostringstream out;
    out<<"value:"<<42;
    std::cout<<out.str()<<std::endl;
    return 0;
}
