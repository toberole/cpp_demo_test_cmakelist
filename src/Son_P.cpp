#include "Son_P.h"
#include <iostream>

Son_P::Son_P() {
    std::cout << "Son_P 默认构造函数" << std::endl;
}

Son_P::Son_P(const Son_P &son_p) {
    std::cout << "Son_P 拷贝构造函数" << std::endl;
}

Son_P &Son_P::operator=(Son_P &son_p) {
    std::cout << "Son_P 赋值运算符函数" << std::endl;
    return *this;
}


Son_P::~Son_P() {
    std::cout << "~Son_P 析构函数" << std::endl;
}

// 成员初始化列表的形式来调用父类的构造函数[否则编译器调用父类的默认构造函数]
// 同时初始化列表中初始化子类的数据成员
Son_P::Son_P(std::string &son_name, int key, int age, std::string name) : P(age, name), key(key) {
    std::cout << "Son_P 有参构造函数 4" << std::endl;
    this->son_name = son_name;
}

/**
 * 错误写法
 *
 * 如果没有在初始化列表中调用父类的构造方法，
 * 那么编译器会调用父类的默认构造方法 以此来为父类部分分配内存
 */
Son_P::Son_P(std::string &name, int key, int age) {
    // 此语句之前 隐藏了编译器调用父类的默认构造函数
    // 这样会导致生成一个临时的父类对象 效率不高
    P(age, name);

    std::cout << "Son_P 有参构造函数 3" << std::endl;

    this->key = key;
    this->son_name = name;
}

/**
 * 正确写法
 *
 * 由编译器调用父类的默认构造函数
 */
Son_P::Son_P(std::string &name, int age) {
    std::cout << "Son_P 有参构造函数 2" << std::endl;
    P::name = name;

    this->son_name = name;
}