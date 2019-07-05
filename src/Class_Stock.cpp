#include "Class_Stock.h"

#include <iostream>

Stock::Stock() {
    std::cout << "无参构造 hello stock" << std::endl;
}

Stock::Stock(int n) {
    this->n = n;
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

void Stock::operator+(Stock &stock) {
    this->n = this->n + stock.n;
}

// 友元函数
Stock operator*(int n, const Stock &stock) {
    Stock s;
    s.n = n * stock.n;
    return s;
}

void friend_method(Stock &stock) {
    std::cout << "friend_method " << stock.i << std::endl;
}

Stock Stock::operator*(const Stock &stock) {
    Stock s;
    s.n = n * stock.n;
    return s;
}

std::ostream &operator<<(std::ostream &os, const Stock &s) {
    os << s.n;
    return os;
}

// 类型转化函数
Stock::operator int() {
    return this->n;
}