//
// Created by Apple on 2019/3/12.
//

#include "Data.h"

#include <iostream>

Data::Data() {
    std::cout << "Data 默认构造" << std::endl;
}

Data::Data(const Data &data) {
    std::cout << "Data 拷贝构造" << std::endl;
}

Data::Data(const Data &&data) {
    std::cout << "Data 移动构造" << std::endl;
}

Data &Data::operator=(const Data &data) {
    std::cout << "Data 赋值运算" << std::endl;
}

Data &Data::operator=(const Data &&data) {
    std::cout << "Data Move assignment operator" << std::endl;
}

Data::~Data() {
    std::cout << "Data 析构函数" << std::endl;
}
