//
// Created by Apple on 2018/12/14.
//
#include <iostream>

#include "./../include/Util.h"

#include "config.h"

void log(std::string logStr) {
#ifdef SWI_ENABLE_MAX
    std::cout << "moudle1 SWI_ENABLE_MAX" << std::endl;
#endif


    std::cout << logStr << std::endl;
}