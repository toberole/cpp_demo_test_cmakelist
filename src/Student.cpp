//
// Created by Apple on 2018/12/14.
//

#include "Student.h"
#include <iostream>

Student::Student() {
    std::cout << "Student 默认构造函数" << std::endl;
}

Student::Student(int _age, std::string _name) :
        age(_age),
        name(_name) {
}

Student::~Student() {
    std::cout << "Student 析构函数" << std::endl;
}

void Student::sysHello() {
    std::cout << "name: " << name << " age: " << age << std::endl;
}