#include <iostream>

#include <Useless.h>

// c++函数返回值都是"值拷贝"，但是在返回对象时候 编译器会做优化
Useless getObject() {
    Useless useless("hello getObject");
    return useless;
}

int getInt() {
    int i = 100;
    std::cout << "getInt: " << &i << std::endl;
    return i;
}

void test_move() {
    Useless one("one");
    Useless two("two");

    // one + two  产生一个右值,编译器优化会直接把右值权限给three
    Useless three(one + two);

    std::cout << "-- test_move --" << std::endl;
}

void test_move1() {
    Useless one("one");
    //  触发移动拷贝构造函数
    Useless two = std::move(one);
}

void test_move2() {
    Useless useless(getObject());
}



int main_move() {

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}