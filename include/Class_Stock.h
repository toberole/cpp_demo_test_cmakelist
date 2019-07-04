//
// Created by Apple on 2019/7/3.
//

#ifndef DEMO_TEST_STOCK_H
#define DEMO_TEST_STOCK_H

#include <iostream>
#include <string>

class Stock {
public:
    int n;

private:
    int i;
    std::string name;
public:
    // 默认构造函数农户
    Stock();

    // 设置默认值的 默认构造函数 等同于Stock() 两者只能定义一个
    // Stock(int i = 1, std::string name = "hello");

    Stock(std::string name);

    // 析构函数
    ~Stock();

public:
    void sys();

    // 调用该方法不会改变任何值
    /**
     * const Stock s;
     * s.sys_const();// 如果没有在方法声明的后面加上const 此方法调用就报错
     */
    void sys_const() const;

    void update();

    /**
     * 定义在类的声明文件中 自动成为内联函数
     */
    void test() {
        std::cout << "Stock test" << std::endl;
    }

    void test_inline();

    // 'static' can only be specified inside the class definition
    // 声明的时候 需要加static 在cpp文件中定义的时候不需要加static
    static void test_static();
};


#endif //DEMO_TEST_STOCK_H
