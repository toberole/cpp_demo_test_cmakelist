//
// Created by Apple on 2018/12/14.
//

#include "Student.h"
#include <iostream>

Student::Student() {

}

Student::Student(int _age, std::string _name) :
        age(_age),
        name(_name) {
}

Student::~Student() {

}

void Student::sysHello() {
    std::cout << "name: " << name << " age: " << age << std::endl;
}