//
// Created by Apple on 2018/12/20.
//

#include "A.h"

#include <iostream>

A::~A() {
    std::cout << "A::~A()" << std::endl;
}

void A::sys() {
    std::cout << " A::sys " << std::endl;
}