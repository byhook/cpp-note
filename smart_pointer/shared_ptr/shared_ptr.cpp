
#include <iostream>
#include <memory>
#include "shared_ptr.h"
#include "../cat.h"

/**
 * Copy
 * 函数内部计数器+1
 * @param ptr
 */
void do_with_pass_value(std::shared_ptr<Cat> ptr) {
    ptr->set_age(20);
    std::cout << "Cat do_with_pass_value " << ptr.get() << std::endl;
    std::cout << "Cat do_with_pass_value use_count " << ptr.use_count() << std::endl;
}

void do_with_pass_ref(std::shared_ptr<Cat> &ptr) {
    ptr->set_age(21);
    std::cout << "Cat do_with_pass_ref " << ptr.get() << std::endl;
    std::cout << "Cat do_with_pass_value use_count " << ptr.use_count() << std::endl;
}

std::shared_ptr<Cat> get_shared_ptr() {
    std::shared_ptr<Cat> pCat = std::make_shared<Cat>("local_cat");
    std::cout << "unique address " << pCat.get() << std::endl;
    std::cout << "unique address & " << &pCat << std::endl;
    return pCat;
}

void shared_ptr::main() {

    std::cout << "================shared_ptr start================" << std::endl;

    std::shared_ptr<int> shared_ptr_1 = std::make_shared<int>(10);
    std::cout << "value " << *shared_ptr_1 << std::endl;
    std::cout << "use count " << shared_ptr_1.use_count() << std::endl;

    std::shared_ptr<int> shared_ptr_2 = shared_ptr_1;
    //这里引用计数会+1
    std::cout << "shared_ptr_1 use count " << shared_ptr_1.use_count() << std::endl;
    std::cout << "shared_ptr_2 use count " << shared_ptr_2.use_count() << std::endl;

    *shared_ptr_1 = 20;
    //这里的值都会变成20
    std::cout << "shared_ptr_1 value " << *shared_ptr_1 << std::endl;
    std::cout << "shared_ptr_2 value " << *shared_ptr_2 << std::endl;

    std::shared_ptr<int> shared_ptr_3 = shared_ptr_1;
    shared_ptr_1 = nullptr;
    //shared_ptr_1的会清理，其余的计数会-1，都是2
    std::cout << "shared_ptr_1 use count " << shared_ptr_1.use_count() << std::endl;
    std::cout << "shared_ptr_2 use count " << shared_ptr_2.use_count() << std::endl;
    std::cout << "shared_ptr_3 use count " << shared_ptr_3.use_count() << std::endl;


    std::shared_ptr<Cat> shared_ptr_cat_1 = std::make_shared<Cat>("cat_1");
    std::shared_ptr<Cat> shared_ptr_cat_2 = shared_ptr_cat_1;
    std::shared_ptr<Cat> shared_ptr_cat_3 = shared_ptr_cat_1;
    std::cout << "shared_ptr_cat_1 use count " << shared_ptr_cat_1.use_count() << std::endl;
    std::cout << "shared_ptr_cat_2 use count " << shared_ptr_cat_2.use_count() << std::endl;
    std::cout << "shared_ptr_cat_3 use count " << shared_ptr_cat_3.use_count() << std::endl;

    shared_ptr_cat_1.reset();
    //这里仅仅只是shared_ptr_cat_1重置了，为0，其余两个仍有引用计数，为2
    std::cout << "shared_ptr_cat_1 use count " << shared_ptr_cat_1.use_count() << std::endl;
    std::cout << "shared_ptr_cat_2 use count " << shared_ptr_cat_2.use_count() << std::endl;
    std::cout << "shared_ptr_cat_3 use count " << shared_ptr_cat_3.use_count() << std::endl;

    //unique_ptr与函数调用
    //内部引用计数会+1，内部计数会变成3
    do_with_pass_value(shared_ptr_cat_2);
    //执行结束后之后引用计数会-1，这里计数会变成2
    std::cout << "shared_ptr_cat_2 use count " << shared_ptr_cat_2.use_count() << std::endl;

    //内部计数仍然是2
    do_with_pass_ref(shared_ptr_cat_3);
    std::cout << "shared_ptr_cat_3 use count " << shared_ptr_cat_3.use_count() << std::endl;

    std::shared_ptr<Cat> fun_cat_ptr = get_shared_ptr();
    std::cout << fun_cat_ptr.get() << std::endl;

    //unique_ptr可以转换为shared_ptr
    std::unique_ptr<Cat> unique_ptr_2(new Cat("cat_2"));
    std::shared_ptr<Cat> shared_ptr_cat = std::move(unique_ptr_2);
    //转换之后unique_ptr_2失效了

    std::cout << "================shared_ptr end================" << std::endl;
}
