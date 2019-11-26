#include <iostream>
#include <string>
#include "move_demo.cpp"

class Execption_Test {
public:
    std::string msg;
public:
    Execption_Test(std::string _msg) : msg(_msg) {}

    void printMsg() {
        std::cout << "Execption_Test printMsg: " << msg << std::endl;
    }
};

class Execption_Test_Extend : public Execption_Test {
public:
    std::string msgInfo;
public:
    Execption_Test_Extend(std::string _msg) : Execption_Test(_msg), msgInfo(_msg) {}

    void printMsg() {
        std::cout << "Execption_Test_Extend printMsg: " << msg << std::endl;
    }
};

void test_exeception() {
    Execption_Test e("hello execption");
    std::cout << "e addr: " << &e << std::endl;
    try {
        throw e;
    } catch (Execption_Test execption_test) {// e会被拷贝两次
        std::cout << "catch e addr: " << &execption_test << std::endl;
    }

    try {
        throw e;
    } catch (const Execption_Test &et) {// e引用只会被拷贝一次
        std::cout << "catch e addr: " << &et << std::endl;
    }
}

void test_exeception1() {
    std::string str("test e");
    Execption_Test_Extend execption_test_extend(str);
    try {
        throw execption_test_extend;
    } catch (Execption_Test e) {
        e.printMsg();// 调用的是Execption_Test.printMsg()
    }

    try {
        throw execption_test_extend;
    } catch (Execption_Test &e) {
        e.printMsg();// 调用的是Execption_Test.printMsg()
    }
}

void testx_1() {
    Move_Data move_data;
    std::cout << "*** *** ***" << std::endl;
    Move_Data m = std::move(move_data);
    std::cout << "*** *** ***" << std::endl;

    std::string str("hello move");
    std::string s1 = std::move(str);
    std::cout << "s1: " << s1 << std::endl;
    // TODO 注意被move之后的变量不能在使用了[行为不可预测]
    std::cout << "str: " << str << std::endl;
    if (str.empty()) {
        std::cout << "move str is empty" << std::endl;
    }
};

int main_stl1_main(int argc, char *args[]) {
    std::cout << "stl1_main.cpp" << std::endl;

    testx_1();
    return 0;
}