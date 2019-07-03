#include "Stock.h"

#include <iostream>

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