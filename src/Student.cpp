//
// Created by Apple on 2018/11/15.
//
#include <iostream>
#include "Student.h"

Student::Student() {

}

Student::~Student() {
    std::cout << "析构函数" << std::endl;
}

Student::Student(std::string name_, int age_) {
    age = age_;
    name = name_;
}

void Student::add(int &count) {
    count++;
}

std::string Student::toString() {
    std::string res = "name: ";
    res += name;
    res += " age: ";
    res += std::to_string(age);
    return res;
}

int getAge(Student &stu) {
    return stu.age;
}