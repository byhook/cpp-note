#include <iostream>
#include "base/chapter.hpp"
#include "chapter2/chapter2.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    {
        std::shared_ptr<chapter> target = std::make_shared<chapter2>();
        target->main();
    }
    return 0;
}
