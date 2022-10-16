#include <iostream>


void handleValue(int value[], int n) {
    //这里获取的是指针的长度-32位系统为4字节-64位为8字节
    std::cout << sizeof(value) << std::endl;
}

int main() {

    int tempValue[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //这里获取的大小实际是 sizeof(int) * 9
    std::cout << sizeof(tempValue) << std::endl;
    handleValue(tempValue, sizeof(tempValue) / sizeof(int));

    //4.7.6
    //动态分配数组
    int *value = new int[10];

    //释放
    delete[] value;

    return 0;
}