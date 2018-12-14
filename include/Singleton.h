//
// Created by Apple on 2018/11/16.
//

#ifndef DEMO_TEST_SINGLETON_H
#define DEMO_TEST_SINGLETON_H

#include <mutex>

class Singleton {
private:
    static Singleton *instance;

public:
    Singleton();

public:
    static Singleton *getInstance();

};


#endif //DEMO_TEST_SINGLETON_H
