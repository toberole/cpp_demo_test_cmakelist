//
// Created by Apple on 2019/7/9.
//

#ifndef DEMO_TEST_ABSTRACT_P_H
#define DEMO_TEST_ABSTRACT_P_H


class Abstract_P {
public:
    // 虚函数
    virtual void eat();

    // 纯虚函数
    // 类中由纯虚函数 那么类就是抽象类
    // 子类继承父类 必须实现父类的纯虚函数 否则子类就是抽象类
    virtual void sys() = 0;

};


#endif //DEMO_TEST_ABSTRACT_P_H
