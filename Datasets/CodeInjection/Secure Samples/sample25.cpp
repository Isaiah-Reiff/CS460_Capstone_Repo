#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int sum(const std::vector<int>& v) {
    int s = 0; for (int x : v) s += x; return s;
}
int product(const std::vector<int>& v) {
    int p = 1; for (int x : v) p *= x; return p;
}

int main() {
    std::cout << "Enter command and numbers, e.g. \"sum 1 2 3\": ";
    std::string line;
    if (!std::getline(std::cin, line)) return 0;
    std::istringstream iss(line);

    std::string cmd;
    iss >> cmd;
    // Normalize command
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    std::vector<int> nums;
    int n;
    while (iss >> n) nums.push_back(n);

    if (cmd == "sum") {
        std::cout << "Sum = " << sum(nums) << std::endl;
    } else if (cmd == "product") {
        std::cout << "Product = " << product(nums) << std::endl;
    } else {
        std::cout << "Unknown or disallowed command." << std::endl;
    }
    return 0;
}