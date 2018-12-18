//
// Created by Apple on 2018/12/14.
//
#include <iostream>
#include <string>

#include "Util.h"
#include "Book.h"
#include "Student.h"

Student getStudent() {
    Student s;
    s.age = 22;
    s.name = "============";

    std::cout << "s addr: " << &s << std::endl;
    return s;
}

char *GetString(void) {

    return nullptr;

}

void Test4(void) {

    char *str = NULL;

    str = GetString(); // str 的内容是垃圾

    // std::cout << str << std::endl;
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

void Test7() {
    std::shared_ptr<Student> ss_ptr = std::make_shared<Student>();
    std::shared_ptr<Student> sss_ptr = ss_ptr;
    std::cout << "ss_ptr = " << ss_ptr.use_count() << std::endl;
    std::cout << "sss_ptr = " << sss_ptr.use_count() << std::endl;
}


void Test8() {
    // 用 "&&" 定义右值引用
    int a = 10;

    // 左值引用 只能用变量赋值
    int &aa = a;

    // 右值引用 可以用右值赋值
    int &&kk = 10;

    std::cout << "aa = " << aa << " kk= " << kk << std::endl;

    std::cout << "aa address = " << &aa << " kk address = " << &kk << std::endl;
}

void Test9() {
    std::string str = "hello";
    std::string str_moved = std::move(str);

    std::cout << "str_moved = " << str_moved << " str = " << str << std::endl;
}

void Test10(Student student) {
    std::cout << "Test10 book address: " << &student.book << std::endl;

    std::cout << "price: " << student.book.price << std::endl;
}


int main() {
    std::cout << std::endl << "==== main start ====" << std::endl;
    log("hello Cmakelist");

    Student student(22,"c++ dev");
    std::cout << "book address: " << &student.book << std::endl;
    Test10(student);
    std::cout << "==============" << std::endl;
    student.book.price = 20;


    // 通过cmakelist添加的宏
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif

    getchar();
    return 0;
}