#ifndef CPP_NOTE_CAT_H
#define CPP_NOTE_CAT_H

#include <iostream>

class Cat {

private:
    std::string name;
    int age = 5;

public:

    explicit Cat(std::string name);
    ~Cat();

    void set_age(int age);
    void hello();

};


#endif //CPP_NOTE_CAT_H
