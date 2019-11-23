#include <iostream>
#include <string>

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

int main(int argc, char *args[]) {
    std::cout << "stl1_main.cpp" << std::endl;

    test_exeception1();
    return 0;
}