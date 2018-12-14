//
// Created by Apple on 2018/12/14.
//
#include <iostream>
#include "Util.h"

int main(){
#ifdef SWI_ENABLE_MAX
    std::cout << "main moudle SWI_ENABLE_MAX" << std::endl;
#endif
    log("hello Cmakelist");

    return 0;
}