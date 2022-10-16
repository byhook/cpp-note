#include <iostream>
#include <array>

struct travel_time {
    int hours;
    int minutes;
};

travel_time sum(travel_time t1,travel_time t2);

int main() {

    std::cout << "Hello, World!" << std::endl;
    travel_time day1 = {1,10};
    travel_time day2 = {2,20};
    travel_time result = sum(day1, day2);

    std::cout << "result.hours:" << result.hours << std::endl;
    //获取返回的结构体地址
    std::cout << "total:" << &result << std::endl;

    return 0;
}

/**
 * 这里局部变量返回结构体
 * 其实是另一个拷贝
 * @param t1
 * @param t2
 * @return
 */
travel_time sum(travel_time t1,travel_time t2){
    travel_time total;
    total.hours = t1.hours + t2.hours;
    total.minutes = t1.minutes + t2.minutes;
    //获取当前局部变量结构体地址
    std::cout << "total:" << &total << std::endl;
    return total;
}