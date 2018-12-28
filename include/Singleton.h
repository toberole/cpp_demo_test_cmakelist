//
// Created by Apple on 2018/12/24.
//

#ifndef DEMO_TEST_SINGLETON_H
#define DEMO_TEST_SINGLETON_H


class Singleton {
public:
    static Singleton *getInstance();

private:
    static Singleton *instance;

    Singleton();

    Singleton(const Singleton &);

    Singleton &operator=(const Singleton &);

public:
    void sysHello();
};


#endif //DEMO_TEST_SINGLETON_H
