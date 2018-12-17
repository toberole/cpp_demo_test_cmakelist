//
// Created by Apple on 2018/12/14.
//
#include <iostream>
#include <string>

#include "Util.h"
#include "Student.h"

Student getStudent() {
    Student s;
    s.age = 22;
    s.name = "============";

    std::cout << "s addr: " << &s << std::endl;
    return s;
}

char *GetString(void) {

    char *p = "hello world";

    return p; // 编译器将提出警告

}

void Test4(void) {

    char *str = NULL;

    str = GetString(); // str 的内容是垃圾

    std::cout << str << std::endl;
}

void Test5() {
    Student s(11, "xiaohong");
    s.sysHello();

    std::cout << "main s addr: " << &s << std::endl;

    Student ss = s;
    std::cout << "main ss addr: " << &ss << std::endl;
}

void Test6() {
    std::string s1("hello"), s2;
    // 从一个右值移动数据
    s2 = std::move(std::string("world"));

    // 从一个左值移动数据 操作完成之后 s1的值就不确定了
    s2 = std::move(s1);

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
}


int main() {
    std::cout << std::endl << "==== main start ====" << std::endl;
    log("hello Cmakelist");

    Test6();

    // 通过cmakelist添加的宏
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif


    getchar();
    return 0;
}