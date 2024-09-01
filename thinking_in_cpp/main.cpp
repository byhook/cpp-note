#include <iostream>
#include <memory>
#include "base/chapter.hpp"
#include "chapter2/chapter2.hpp"
#include "chapter3/chapter3.hpp"

int main() {
    std::cout << "================chapter2================" << std::endl;
    {
        std::shared_ptr<chapter> target = std::make_shared<chapter2>();
        target->main();
    }
    std::cout << "================chapter3================" << std::endl;
    {
        std::shared_ptr<chapter> target = std::make_shared<chapter3>();
        target->main();
    }
    return 0;
}
