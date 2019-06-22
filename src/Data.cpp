//
// Created by Apple on 2019/3/12.
//

#include "Data.h"

#include <iostream>

Data::Data() {
    std::cout << "Data::Data()" << std::endl;
}

Data::Data(const Data &data) {
    std::cout << "拷贝构造" << std::endl;
}

Data::Data(const Data &&data) {
    std::cout << "移动构造" << std::endl;
}

Data &Data::operator=(const Data &data) {
    std::cout << "赋值运算" << std::endl;
}

Data &Data::operator=(const Data &&data) {
    std::cout << "Move assignment operator" << std::endl;
}

Data::~Data() {
    std::cout << "Data::~Data()" << std::endl;
}
