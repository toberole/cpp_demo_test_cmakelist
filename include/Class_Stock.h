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

    // explicit 可以禁止使用此构造函数作为默认的类型转换函数
    explicit Stock(int n);

    // 设置默认值的 默认构造函数 等同于Stock() 两者只能定义一个
    // 默认构造函数 由默认参数值时 必须给所有参数提供默认值
    // Stock(int i = 1, std::string name = "hello");

    Stock(std::string name);

    // 析构函数
    ~Stock();

    // 类型转换函数
    // 将Stock对象转换为int
    operator int ();
public:
    void sys();

    // 调用该方法不会改变任何值
    /**
     * const Stock s;
     * s.sys_const();// 如果没有在方法声明的后面加上const 此方法调用就报错
     */
    // 函数声明后面的const将会把this限定为const
    // 这样就不可以使用this来修改对象的值
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

    // 运算符号重载
    void operator+(Stock &stock);

    friend void friend_method();

    // 友元函数 不是类的成员函数 但是可以访问类的所有成员
    friend Stock operator*(int n, const Stock &stock);

    Stock operator*(const Stock &stock);

    friend void operator<<(std::ostream &os, const Stock &s);
};


#endif //DEMO_TEST_STOCK_H
