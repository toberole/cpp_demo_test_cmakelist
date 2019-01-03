//
// Created by Apple on 2018/12/14.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <functional>
#include <future>

#include <cstring>

#include "Util.h"

#include "Anim.h"
#include "Book.h"
#include "Student.h"
#include <A.h>
#include "B.h"

#include "Singleton.h"

#include <cassert>

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

void Test23() {
    Book b;
    std::cout << b.price << std::endl;

    std::cout << std::boolalpha;
}

void Test24() {
    char cstr[] = "hello world Tom ";
    char cstr1[] = "hello kit ";
    strcat(cstr, cstr1);

    std::cout << cstr << strlen(cstr) << std::endl;
}

void Test25() {
    Singleton *instance = Singleton::getInstance();
    instance->sysHello();
}

void Test26() {
    int i = 0;

    std::cout << sizeof(i) << std::endl;

    char arr[] = {'a', 'b', 'c'};

    std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;

    char *p = "hello world";

    std::cout << "p len: " << strlen(p) << std::endl;

    std::cout << "arr len: " << strlen(arr) << std::endl;

    assert(0);

    std::cout << " after assert " << std::endl;
}

void Test27() {
    std::error_code ec(-1, std::generic_category());
    // std::system_error se;
    std::cout << "value: " << ec.value() << " message: " << ec.message() << std::endl;
}

enum Data {
    DATA1, DATA2, DATA3, DATA4
};

void Test28() {
    Data d(DATA2);

    size_t t;
    std::cout << "Data: " << d << std::endl;
}

struct TT {
    std::string name;
};

#include <ctype.h>


void Test29() {
    std::string str = "hello world";

}


// std::async
void Test30() {
    std::future<int> res = std::async(std::launch::async, []() {
        // std::cout << "" << std::endl;
        return 1;
    });

    //std::future_status rr = res.wait_for(std::chrono::milliseconds(1000*2));

    //std::cout << "res_i: " << res_i << std::endl;
}

// std::bind
// std::thread th(std::bind(Test31,11));
void Test31(int n) {
    std::cout << "n: " << n << std::endl;
}

// int kk = 22;
// std::thread th1(std::bind(Test32, std::ref(kk)));
void Test32(int &n) {
    std::cout << "n: " << n << std::endl;
}

// placeholders  占位符
// auto ff = std::bind(Test35, 1,std::placeholders::_1);
// ff(33);
// 注意占位符是 传引用的
void Test35(int a, int b) {
    std::cout << "a: " << a << " b: " << b << std::endl;
}

// 动态绑定只有当通过指针或引用调用虚函数时才会发生。
void Test36() {
    B b;
    A a = b;
    // 执行A的sys方法
    a.sys();

    // 执行B的sys方法
    A &a1 = b;
    a1.sys();
}

int main() {
    std::cout << "------- main -------" << std::endl;

    std::thread th1([]() {
        std::cout << "== th1 ==" << std::endl;
    });

    std::thread th2([]() {
        std::cout << "== th2 ==" << std::endl;
    });

    th1.join();
    th2.join();

    std::cout << "*******************************************************" << std::endl;

    // 通过cmakelist添加的宏
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif

    // getchar();
    return 0;
}