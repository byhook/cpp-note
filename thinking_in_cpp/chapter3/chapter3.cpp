#include <vector>
#include "chapter3.hpp"

//使用extern关键字来声明另一个文件中存在的全局变量
extern int global_value;

chapter3::chapter3() {
    std::cout << "chapter3" << std::endl;
}

chapter3::~chapter3() {
    std::cout << "~chapter3" << std::endl;
}

void chapter3::main() {
    std::cout << "main global_value:" << global_value << std::endl;
    for (int i = 0; i < 5; i++) {
        static_value();
    }
}

/**
 * 当应用static于函数名和所有函数外部的变量时，
 * 它的意思是：在文件的外部不可以使用这个名字
 */
void chapter3::static_value() {
    //static变量的优点是在函数范围之外它是不可用的
    static int static_value = 100;
    std::cout << static_value++ << std::endl;
}