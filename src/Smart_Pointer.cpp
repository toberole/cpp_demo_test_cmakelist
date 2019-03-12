//
// Created by Apple on 2019/3/12.
//
#include <iostream>


class SmartPointer {
public:
    std::string name;
    int age;

public:
    SmartPointer(std::string name, int age) {
        this->name = name;
        this->age = age;

        std::cout << "SmartPointer()构造函数" << std::endl;
    }

    SmartPointer() {
        std::cout << "SmartPointer()构造函数" << std::endl;
    }

    ~SmartPointer() {
        std::cout << "~SmartPointer()析构函数" << std::endl;
    }
};

