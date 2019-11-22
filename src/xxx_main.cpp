#include <iostream>
#include<string>

#include <unistd.h>

//#include "memory.h"
/**
 * AOP
 * 1、编译时打桩
 * 2、链接时打桩是在链接时替换需要的函数。Linux链接器支持用—wrap,f的方式来进行打桩，链接时符号f解析成wrap_f，还会把real_f解析成f。
 * 3、运行时打桩
 */

void test_xxx_main1() {
    void *p = malloc(100);
}

int main() {
    std::cout << "xxx_main" << std::endl;

    test_xxx_main1();

    

    return 0;
}

