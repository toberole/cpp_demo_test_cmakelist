#include <iostream>
#include "Class_Stock.h"
#include "Mem_StringBad.h"
#include "Son_P.h"

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
//    Son_P sp1(son_name, key, age, name);
//    std::cout << "---------------------" << std::endl;
    // 错误写法示范
    Son_P sp2(name, key, age);
    std::cout << "2 name: " << sp2.name << std::endl;
    std::cout << "---------------------" << std::endl;
    // 正确写法示范
    Son_P sp3(name, age);
    std::cout << "3 name: " << sp3.name << std::endl;
}

int main() {
    test_main2_5();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}