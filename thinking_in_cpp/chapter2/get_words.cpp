#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::ifstream in("../res/main.txt");
    std::string line;
    while (in >> line){
        words.push_back(line);
    }
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << std::endl;
    }
    in.close();
    return 0;
}