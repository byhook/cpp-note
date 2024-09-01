#include <iostream>
#include <memory>
#include "cat.h"

int main() {
    std::cout << "================smart_pointer start================" << std::endl;
    Cat cat("Num1");
    cat.hello();
    {
        Cat cat2("Num2");
        cat2.hello();
    }
    //unique_ptr的创建方式
    //1、基于裸指针
    Cat *cat_1 = new Cat("cat_1");
    std::unique_ptr<Cat> unique_ptr_1(cat_1);
    /*
    delete cat_1;
    cat_1 = nullptr;
    */
    //悬空指针-会报错
    unique_ptr_1->hello();
    //2、通过new的方式
    std::unique_ptr<Cat> unique_ptr_2(new Cat("cat_2"));
    unique_ptr_2->hello();
    //3、通过std::make_unique创建(推荐)
    std::unique_ptr<Cat> unique_ptr_3 = std::make_unique<Cat>("cat_3");
    unique_ptr_3->set_age(9);
    unique_ptr_3->hello();
    std::cout << "address " << unique_ptr_3.get() << std::endl;

    std::cout << "================smart_pointer end================" << std::endl;
    return 0;
}
