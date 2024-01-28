#include <vector>
#include "chapter2.hpp"

chapter2::chapter2() {
    std::cout << "chapter2" << std::endl;
}

chapter2::~chapter2() {
    std::cout << "~chapter2" << std::endl;
}

void chapter2::main() {
    std::cout << "get_line start" << std::endl;
    get_line();
    std::cout << "get_line end" << std::endl;
    std::cout << "get_words start" << std::endl;
    get_words();
    std::cout << "get_words end" << std::endl;
}

void chapter2::get_line() {
    std::ifstream in("../res/main.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << std::endl;
    }
    in.close();
}

void chapter2::get_words() {
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
}