#include <iostream>
#include <string>
int main() {
  std::string cmd; std::cin >> cmd;
  if (cmd == "ping") std::cout << "pong\n";
  else if (cmd == "version") std::cout << "1.0\n";
  else std::cout << "not allowed\n";
}