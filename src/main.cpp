//
// Created by Apple on 2018/12/14.
//
#include <iostream>
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

    char p[] = "hello world";

    return p; // 编译器将提出警告

}

void Test4(void) {

    char *str = NULL;

    str = GetString(); // str 的内容是垃圾

    std::cout << str << std::endl;

}


int main() {

    Test4();


    std::cout << std::endl << "==== main start ====" << std::endl;

    // 通过cmakelist添加的宏
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif

    log("hello Cmakelist");

    Student s(11, "xiaohong");
    s.sysHello();

    Student ss = getStudent();
    std::cout << "main ss addr: " << &ss << std::endl;

    return 0;
}