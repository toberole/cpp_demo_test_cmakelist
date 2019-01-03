//
// Created by Apple on 2018/12/20.
//

#include "B.h"

#include <iostream>

B::~B() {
    std::cout << "B::~B()" << std::endl;
}

void B::sys() {
    std::cout << " B::sys" << std::endl;
}