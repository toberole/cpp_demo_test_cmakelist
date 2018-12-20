//
// Created by Apple on 2018/12/19.
//

#include "Anim.h"

#include <iostream>

Anim::Anim() {
    b = new Book();
}

Anim::~Anim() {
    if (b) {
        std::cout << "释放Book内存" << std::endl;
        delete b;
        b = nullptr;
    }
    std::cout << "~Anim ~Anim ~Anim" << std::endl;
}