#include <iostream>
#include <utility>
#include "cat.h"

Cat::Cat(std::string value) {
    this->name = std::move(value);
    std::cout << "Cat invoke " << this->name << " age " << this->age << std::endl;
}

Cat::~Cat() {
    std::cout << "~Cat invoke " << this->name << " age " << this->age << std::endl;
}

void Cat::hello() {
    std::cout << "Cat hello " << this->name << " age " << this->age << std::endl;
}

void Cat::set_age(int age) {
    this->age = age;
}
