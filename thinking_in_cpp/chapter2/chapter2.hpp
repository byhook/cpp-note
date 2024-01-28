#ifndef CPP_NOTE_CHAPTER2_HPP
#define CPP_NOTE_CHAPTER2_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "../base/chapter.hpp"

class chapter2 : public chapter {

public:

    chapter2();

    ~chapter2();

    void main();

private:

    void get_line();
    void get_words();
};


#endif //CPP_NOTE_CHAPTER2_HPP
