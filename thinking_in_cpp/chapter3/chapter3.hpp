#ifndef CPP_NOTE_CHAPTER3_HPP
#define CPP_NOTE_CHAPTER3_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "../base/chapter.hpp"

class chapter3 : public chapter {

public:

    chapter3();

    ~chapter3();

    void main();

private:

    void static_value();

    //3.7.11转换运算符
    void cast_value();

};


#endif //CPP_NOTE_CHAPTER3_HPP
