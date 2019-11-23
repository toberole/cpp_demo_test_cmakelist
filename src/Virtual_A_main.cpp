#include "Virtual_A.h"
#include "Test_A1.h"

void test_va_1() {
    Virtual_A virtual_a;
    virtual_a.n = 100;
    virtual_a.sys();
    std::cout << "变量N的偏移量：" << offsetof(Virtual_A, n) << std::endl;
}

void test_va_2() {
    std::cout << "test_a：" << test_a << std::endl;
}

int main_virtual_a_main() {
    test_va_2();

    getchar();
    return 0;
}