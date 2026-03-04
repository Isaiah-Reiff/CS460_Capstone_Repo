#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
int main() {
  std::string body; std::getline(std::cin, body);
  std::ofstream out("u.cpp");
  out << "int main(){\n" << body << "\n}\n";
  out.close();
  system("g++ u.cpp -o uprog"); 
  system("./uprog");            
}