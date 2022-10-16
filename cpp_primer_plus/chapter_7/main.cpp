#include <iostream>
#include <array>

struct travel_time {
    int hours;
    int minutes;
};

/**
 * 这里局部变量返回结构体
 * 其实是另一个拷贝
 * @param t1
 * @param t2
 * @return
 */
travel_time sum(travel_time t1, travel_time t2) {
    travel_time total;
    total.hours = t1.hours + t2.hours;
    total.minutes = t1.minutes + t2.minutes;
    //获取当前局部变量结构体地址
    std::cout << "total:" << &total << std::endl;
    return total;
}

/**
 * 7.10 函数指针
 */
int think(int value){
    return value + 100;
}

//声明函数指针
int (*funPtr)(int value);

void process(int value, int (*funPtr)(int )){
    //int result = (*funPtr)(value); //和下面的等价
    int result = funPtr(value);
    std::cout << "funPtr:" << result << std::endl;
}

void thought(int value){
    std::cout << "thought:" << value << std::endl;
}

int main() {

    //7.3
    std::cout << "Hello, World!" << std::endl;
    travel_time day1 = {1, 10};
    travel_time day2 = {2, 20};
    travel_time result = sum(day1, day2);

    std::cout << "result.hours:" << result.hours << std::endl;
    //获取返回的结构体地址
    std::cout << "total:" << &result << std::endl;

    //7.3.5-指针和const
    int target = 99;
    int age = 30;
    //这里的&取地址
    const int *const_ptr = &age;
    std::cout << "const_ptr age address:" << const_ptr << std::endl;
    const_ptr = &target; //合法
    //*const_ptr = target; //非法
    std::cout << "const_ptr age address:" << const_ptr << std::endl;
    //const int * pt 是常量指针((const int)(* pt)): 可以改指针的地址,不能改内容

    int *const ptr_const = &age;
    std::cout << "ptr_const age address:" << ptr_const << std::endl;
    //ptr_const = &target; 　//非法
    *ptr_const = target;   //合法
    std::cout << "ptr_const age value:" << *ptr_const << std::endl;
    //int * const pt 是指针常量((int *)(const pt)): 可以改内容,不能改指针的地址

    //7.10 函数指针
    process(10,think);
    thought(think(100));
    return 0;
}
