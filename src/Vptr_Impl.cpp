#include "Vptr_Impl.h"
#include <iostream>

void Vptr_Impl::test() {
    std::cout << "hello vptr" << std::endl;
}

Vptr_Impl::~Vptr_Impl() {
    std::cout << "~Vptr_Impl()" << std::endl;
}