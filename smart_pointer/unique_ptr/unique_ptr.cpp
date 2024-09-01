
#include <iostream>
#include <memory>
#include "unique_ptr.h"
#include "../cat.h"

void do_with_pass_value(std::unique_ptr<Cat> ptr) {
    ptr->set_age(20);
    std::cout << "Cat do_with_pass_value " << ptr.get() << std::endl;
}

void do_with_pass_ref(std::unique_ptr<Cat> &ptr) {
    ptr->set_age(21);
    std::cout << "Cat do_with_pass_ref " << ptr.get() << std::endl;
}


std::unique_ptr<Cat> get_unique_ptr() {
    std::unique_ptr<Cat> pCat = std::make_unique<Cat>("local_cat");
    std::cout << "unique address " << pCat.get() << std::endl;
    std::cout << "unique address & " << &pCat << std::endl;
    return pCat;
}

void unique_ptr::main() {

    std::cout << "================unique_ptr start================" << std::endl;
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

    //unique_ptr与函数调用
    //1、传值(需要std::move)
    std::unique_ptr<Cat> unique_ptr_fun_1 = std::make_unique<Cat>("cat_4");
    do_with_pass_value(std::move(unique_ptr_fun_1));
    //会报错，因为所有权已经转移了
    //unique_ptr_3->hello();

    //2、传址
    std::unique_ptr<Cat> unique_ptr_fun_2 = std::make_unique<Cat>("cat_5");
    do_with_pass_ref(unique_ptr_fun_2);
    //正常执行-所有权还在
    unique_ptr_fun_2->hello();

    std::unique_ptr<Cat> fun_cat_ptr = get_unique_ptr();
    std::cout << fun_cat_ptr.get() << std::endl;

    std::cout << "================unique_ptr end================" << std::endl;
}
