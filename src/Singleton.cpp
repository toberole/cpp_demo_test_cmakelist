//
// Created by Apple on 2018/12/24.
//

#include "Singleton.h"

#include <iostream>

Singleton *Singleton::instance = new Singleton();

Singleton::Singleton() {

}

Singleton::Singleton(const Singleton &) {

}

Singleton &Singleton::operator=(const Singleton &_instance) {
	return *instance;
}

Singleton *Singleton::getInstance() {
    return Singleton::instance;
}

void Singleton::sysHello() {
    std::cout << " Singleton::sysHello " << std::endl;
}