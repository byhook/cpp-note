#include <iostream>
#include <array>
#include <vector>

int main() {

    std::cout << "Hello, World!" << std::endl;

    //8.2引用变量-必须在声明引用变量时进行初始化
    int rats = 100;
    int &rodents = rats;
    //int * const ptr = &rats;  //更接近于const指针

    std::cout << &rats << std::endl;
    std::cout << &rodents << std::endl;

    rodents = 200;

    std::cout << "rats:" << rats << std::endl;
    std::cout << "rodents:" << rodents << std::endl;

    return 0;
}
