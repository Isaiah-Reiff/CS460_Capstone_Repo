#include <iostream>
#include <sstream>
#include <vector>
int main() {
  std::string line; std::getline(std::cin, line);
  std::istringstream iss(line);
  int x; long long sum=0;
  while (iss >> x) sum += x;
  std::cout << sum << "\n";
}