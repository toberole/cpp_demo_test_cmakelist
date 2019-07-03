//
// Created by Apple on 2019/7/3.
//

#ifndef DEMO_TEST_STOCK_H
#define DEMO_TEST_STOCK_H

#include <iostream>
#include <string>

class Stock {
private:
    std::string name;
public:
    void update();

    /**
     * 定义在类的声明文件中 自动成为内联函数
     */
    void test() {
        std::cout << "Stock test" << std::endl;
    }

    void test_inline();
};


#endif //DEMO_TEST_STOCK_H
