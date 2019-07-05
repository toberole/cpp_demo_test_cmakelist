#include "Mem_StringBad.h"

#include <iostream>
#include <cstring>

// 初始化num_strings = 0
// 注意不需要关键字static
int StringBad::num_strings = 0;

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "cpp");
    num_strings++;
    std::cout << "---- StringBad 无参构造函数 num_strings: " << num_strings << std::endl;
}

StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << "**** StringBad 有参构造函数 num_strings: " << num_strings << std::endl;
}

StringBad::~StringBad() {
    std::cout << "StringBad 析构函数" << std::endl;

    delete[]str;
    --num_strings;
}

std::ostream &operator<<(std::ostream &os, const StringBad &s) {
    os << s.str;
    return os;
}