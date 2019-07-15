//
// Created by Apple on 2019/7/15.
//

#include "Useless.h"
#include <iostream>

Useless::Useless() {
    std::cout << "默认构造函数" << std::endl;
}

Useless::Useless(std::string name) : name(name) {
    std::cout << "构造函数 Useless(std::string name)" << std::endl;
}

Useless::Useless(const Useless &f) : name(f.name) {
    std::cout << "拷贝构造函数" << std::endl;
}

Useless::Useless(Useless &&useless) {
    std::cout << "移动拷贝构造函数" << std::endl;
    this->name = useless.name;
}

Useless Useless::operator+(const Useless &f) const {
    std::cout << "operator+" << std::endl;
    Useless useless;
    useless.name = this->name + f.name;
    return useless;
}

void Useless::showData() const {
    std::cout << "showData: " << name << std::endl;
}

Useless::~Useless() {
    std::cout << " ~Useless " << std::endl;
}