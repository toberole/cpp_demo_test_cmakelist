#include <iostream>
#include <exception>
#include <typeinfo>


#include "Class_Stock.h"
#include "Mem_StringBad.h"
#include "Son_P.h"
#include "Abstract_P.h"
#include "Abstract_Son_P.h"

void test_main2_1() {
    StringBad stringBad;
    std::cout << stringBad << std::endl;
}

void test_main2_2() {
    StringBad stringBad;
    // 触发拷贝构造函数
    StringBad stringBad1 = stringBad;
}

void test_main2_3() {
    StringBad stringBad;
    StringBad stringBad2("hello");
    stringBad = stringBad2;
}

void test_main2_4() {
    Stock stock(1, 11);
}

/**
 * 注意 子类构造函数调用父类构造函数
 * 子类 = 父类全部[包括父类的私有部分，只是私有部分不能直接方法，需要父类的public接口和protected接口] + 子类自身
 *
 */
void test_main2_5() {
    std::string name = "hello";
    std::string son_name = "son_name";
    int key = 11;
    int age = 22;

//    Son_P sp;
    Son_P sp1(son_name, key, age, name);
//    std::cout << "---------------------" << std::endl;
    // 错误写法示范
    Son_P sp2(name, key, age);
    std::cout << "2 name: " << sp2.name << std::endl;
    std::cout << "---------------------" << std::endl;
    // 正确写法示范
    Son_P sp3(name, age);
    std::cout << "3 name: " << sp3.name << std::endl;
}

/**
 * 多态
 */
void test_main2_6() {
    // 不能实现多态
    P p1;
    Son_P sp1;
    p1 = sp1;
    // 调用的是父类的print
    p1.print();
    std::cout << "-----------多态-----------" << std::endl;
    // 多态
    P *p_p = nullptr;
    Son_P *sp_p = new Son_P();
    p_p = sp_p;
    // 调用的是子类的print
    p_p->print();

    std::cout << "-----------多态-----------" << std::endl;
    // 多态
    Son_P sonP;
    P &p = sonP;
    // 调用的是子类的print
    p.print();

}

/**
 * 析构函数
 */
void test_main2_7() {
    std::cout << "----------- 析构函数 -----------" << std::endl;
    P *vp = new Son_P();
    delete (vp);
}

/**
 * 纯虚函数
 */
void test_main2_8() {
    Abstract_Son_P *son_p = new Abstract_Son_P();
    Abstract_P *abstract_p = son_p;
    abstract_p->sys();
}

/**
 * 异常处理
 *
 */
void test_main2_9() {
    int i = 1;
    int j = 2;

    if (i + j == 3) {
        throw "hello exeception";
    }
}

/**
 * 异常处理
 */
void test_main2_9_1() {
    try {
        test_main2_9();
    } catch (const char *e) {// catch只能抓住与异常类型一致的异常
        std::cout << "exception: " << e << std::endl;
    } catch (...) {// 捕获任何类型的异常

    }
}

/**
 * 异常处理[C11不建议使用throw]
 */
void test_main2_10()throw(const char*) {

}

/**
 * 异常处理[C11不建议使用]
 */
void test_main2_10_1() {
    test_main2_10();
}

void test_main2_11_1() {
    std::cout << "test_main2_11_1" << std::endl;
}

void test_main2_11() {
    std::set_unexpected(test_main2_11_1);

    throw "hello set_unexpected";
}

void test_main2_12() {
    P p;
    std::cout << "typeid: " << typeid(p).name() << std::endl;
}

void test_main2_13() {
    std::string name = "hello world";
    std::cout << "name: " << name << std::endl;
    std::wstring name1(L"我h们");
    std::cout << name1.length() << std::endl;
    std::cout << name1.size() << std::endl;
    name[0] = 'A';
    std::cout << "name: " << name << std::endl;

    std::wstring ss(L"我h们");
    // wstring 2 string

    std::wcout << "requiredSize: " << sizeof(ss) << std::endl;
}

int main02() {
    test_main2_13();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}