//
// Created by Apple on 2018/12/14.
//

#ifndef DEMO_TEST_STUDENT_H
#define DEMO_TEST_STUDENT_H

#include <string>
#include "Book.h"

class Student {
public:
    Student();

    Student(int _age, std::string _name);

    ~Student();

public:
    void sysHello();

public:
    Book book;
    int age;
    std::string name;
};

#endif //DEMO_TEST_STUDENT_H
