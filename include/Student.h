//
// Created by Apple on 2018/11/15.
//

#ifndef DEMO_TEST_STUDENT_H
#define DEMO_TEST_STUDENT_H

#include <string>

class Student {
public:
    ~Student();

    Student();

    Student(std::string name, int age);

    std::string toString();

    friend int getAge(Student & stu);

public:
    std::string name;
    int age;

public:
    void add(int &count);
};


#endif //DEMO_TEST_STUDENT_H
