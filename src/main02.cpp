#include <iostream>

#include "Mem_StringBad.h"

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

int main() {
    test_main2_3();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}