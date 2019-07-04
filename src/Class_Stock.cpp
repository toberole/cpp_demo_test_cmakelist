#include "Class_Stock.h"

#include <iostream>

Stock::Stock() {
    std::cout << "无参构造 hello stock" << std::endl;
}

//Stock::Stock(int i = 1, std::string name = "hello") {
//    this->name = name;
//    this->i = i;
//}

Stock::Stock(std::string name) {
    this->name = name;

    std::cout << "有参构造 hello stock" << std::endl;
}

Stock::~Stock() {
    std::cout << "析构函数stock" << std::endl;
}

void Stock::sys() {
    std::cout << name << std::endl;
}

void Stock::sys_const() const {
    std::cout << "sys_const" << std::endl;
}

void Stock::update() {
    std::cout << "hello stock" << std::endl;
}

/**
 * 定义为内联函数
 */
inline void Stock::test_inline() {
    std::cout << "inline Stock::test_inline" << std::endl;
}

/**
 * 定义的时候不能加static关键字
 */
void Stock::test_static() {
    std::cout << "inline Stock::test_static" << std::endl;
}