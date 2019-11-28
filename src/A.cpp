#include "A.h"

#include <iostream>

A::~A() {
    std::cout << "A::~A()" << std::endl;
}

void A::sys() {
    std::cout << " A::sys " << std::endl;
}