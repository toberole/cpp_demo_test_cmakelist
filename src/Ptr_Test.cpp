//
// Created by Apple on 2019/7/12.
//

#include "Ptr_Test.h"


#include <iostream>

Ptr_Test::Ptr_Test() {
    std::cout << "Ptr_Test 无参构造函数" << std::endl;
}

Ptr_Test::Ptr_Test(const Ptr_Test &prt_test) {
    std::cout << "Ptr_Test 拷贝构造函数" << std::endl;
}

Ptr_Test::~Ptr_Test() {
    std::cout << "Ptr_Test 析构函数" << std::endl;
}

void Ptr_Test::sys() {
    std::cout << "Ptr_Test sys" << std::endl;
}