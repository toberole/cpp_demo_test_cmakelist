//
// Created by Apple on 2018/11/15.
//


#include <iostream>
#include "util.h"

void sysHello(){
    std::cout<<"hello sysHello"<<std::endl;
}

int * retArray(){
    static int arr[] = {1,2,3};

    return arr;
}