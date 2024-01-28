#include <iostream>
#include "chapter.hpp"

chapter::chapter() {
    std::cout << "chapter" << std::endl;
}

chapter::~chapter() {
    std::cout << "~chapter" << std::endl;
}
