#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main() {
    std::string userSource;
    std::getline(std::cin, userSource); // user supplies C++ function body (illustrative)
    std::ofstream out("userprog.cpp");
    out << "#include <iostream>\nint main(){\n" << userSource << "\n}\n";
    out.close();
    system("g++ userprog.cpp -o userprog"); 
    system("./userprog");                   
    return 0;
}
