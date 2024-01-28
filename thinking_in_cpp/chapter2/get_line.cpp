#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("../res/main.txt");
    std::string line;
    while (std::getline(in,line)){
        std::cout << line << std::endl;
    }
    in.close();
    return 0;
}