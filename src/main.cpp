//
// Created by Apple on 2018/12/14.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <functional>

#include "Util.h"

#include "Anim.h"
#include "Book.h"
#include "Student.h"
#include <A.h>
#include "B.h"

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

void Test11() {
    Student ss(22, "C++ Dev");
    Student s2 = std::move(ss);

    std::cout << s2.age << "  " << s2.name << std::endl;

    std::cout << ss.age << "  " << ss.name << std::endl;
}

void Test12() {
    Book b1(11, "hello book");
    Book b2 = std::move(b1);

    std::cout << "*************" << std::endl;

    std::cout << b1.name << "  " << b1.price << std::endl;

    std::cout << "=============" << std::endl;

    std::cout << b2.name << "  " << b2.price << std::endl;
}

void Test13() {
    std::shared_ptr<Book> b1(new Book());
    std::shared_ptr<Book> b2 = b1;

    std::cout << "+++++++++++++++++" << std::endl;
}

void Test14() {
    Student s;
    std::cout << s.isP << std::endl;
}

void Test15() {
    Anim anim;
    anim.age = 11;
}

void Test16(Book &b) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << &b << std::endl;
    std::cout << b.price << std::endl;
    std::cout << "Test16 stop" << std::endl;
}

void Test17() {
    Book b;
    std::cout << " main " << &b << std::endl;
    b.price = 99;

    std::thread th(Test16, std::ref(b));
    th.detach();
    std::cout << " main detach()" << &b << std::endl;

}

void sysName(int i, int j) {
    std::cout << "i: " << i << " j: " << j << std::endl;
}

void Test18() {
    Book b;
    std::function<void(int, int)> fun = sysName;
    b.sysName(fun, "main sysName pointer");
}

void Test19() {
    Book b;
    std::shared_ptr<Book> sb(&b);

    std::cout << sb->price << std::endl;
}

void Test_Thread() {
    std::cout << "hello exception" << std::endl;

    throw "hello throw";
}

void Test20() {
    try {
        std::thread th(Test_Thread);
        th.join();
    } catch (char const *e) {
        std::cout << e << std::endl;
    }
}

int *Test21() {
    int arr[] = {1, 2, 3};

    return arr;// 在栈上分配的内存，函数结束之后，内存被自动回收 收据就不可预测了
}

void Test22() {
    A *a = new B();
    a->sys();
}

int main() {
    std::cout << "------- main -------" << std::endl;

    // Test22();
    log("hello C");

    std::cout << age << std::endl;


    // int arr[] = {1,2,3};
    // std::cout << sizeof(arr) << std::endl;
//    int *arr = Test21();
//    for (int i = 0; i < 3; ++i) {
//        std::cout << arr[i] << std::endl;
//    }

    std::cout << "*******************************************************" << std::endl;

    // 通过cmakelist添加的宏
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif

    getchar();
    return 0;
}