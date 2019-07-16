#include <iostream>
#include <PA.h>

// 倒三角继承
void test_extend1() {
    PA pa;
    // 错误写法
    // pa.sys();
    // 正确写法
    pa.PA_1::sys();
    pa.PA_2::sys();
}

int main() {
    std::cout << "extend main" << std::endl;
    test_extend1();
    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}