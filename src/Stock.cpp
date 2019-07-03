//
// Created by Apple on 2019/7/3.
//

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