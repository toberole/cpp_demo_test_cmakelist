#include "P.h"

#include <iostream>

P::P() {
    std::cout << "P 默认构造函数" << std::endl;
}

P::P(const P &p) {
    std::cout << "P 拷贝构造函数" << std::endl;
}

P &P::operator=(P &p) {
    std::cout << "P 赋值运算符" << std::endl;
    return *this;
}

P::~P() {
    std::cout << "~P 析构函数" << std::endl;
}

P::P(int age, std::string name) {
    std::cout << "P 有参构造函数" << std::endl;
    this->age = age;
    this->name = name;
}