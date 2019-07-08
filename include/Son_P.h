#ifndef DEMO_TEST_SON_P_H
#define DEMO_TEST_SON_P_H

#include <iostream>
#include <string>
#include "P.h"

/**
 * 子类 = 父类全部[包括父类的私有部分，只是私有部分不能直接方法，需要通过父类的public接口和protected接口] + 子类自身
 * "+" 工作只能由编译器完成
 */
class Son_P : public P {
private:
    std::string son_name;
public:
    int key;

public:
    Son_P();

    Son_P(const Son_P &son_p);

    Son_P &operator=(Son_P &son_p);

    virtual ~Son_P();

    virtual void print() {
        std::cout << "子类的print" << std::endl;
    }

    Son_P(std::string &name, int age);

    Son_P(std::string &name, int key, int age);

    Son_P(std::string &son_name, int key, int age, std::string name);
};


#endif //DEMO_TEST_SON_P_H
