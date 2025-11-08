#include <iostream>
#include <string>
int main(){
  std::string cmd = "count"; // from user
  if (cmd == "count") {
    std::cout << 3 << std::endl;
  } else {
    std::cout << "unknown" << std::endl;
  }
}

