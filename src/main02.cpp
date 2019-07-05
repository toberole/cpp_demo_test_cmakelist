#include <iostream>

#include "Mem_StringBad.h"

void test_main2_1() {
    StringBad stringBad;
    std::cout << stringBad << std::endl;
}

int main() {
    test_main2_1();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}