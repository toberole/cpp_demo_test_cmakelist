//
// Created by Apple on 2018/12/14.
//
#include <iostream>

#include "Util.h"
#include "config.h"

void log(std::string logStr) {
    // 通过cmakelist脚本控制该宏
#ifdef SWI_ENABLE_MAX
    std::cout << "moudle1 SWI_ENABLE_MAX" << std::endl;
#endif


    std::cout << logStr << std::endl;
}