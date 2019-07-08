#ifndef DEMO_TEST_STOCK_H
#define DEMO_TEST_STOCK_H

#include <iostream>
#include <string>

class Stock {
public:
    // C11可以在类中初始化，会被初始化列表初始化的值覆盖
    int n = 1000;

private:
    int i;
    std::string name;
public:
    // 默认构造函数农户
    Stock();

    // 成员初始化列表语法
    // 如果初始化列表包含了所有的成员，那么会于默认构造函数冲突
    // 必须用这种语法来初始化非静态const数据成员
    // 必须用这种语法初始化const引用数据成员
    // 成员初始化的顺序与他们在类中声明顺序相同
    Stock(int n, int i);

    // explicit 可以禁止使用此构造函数作为默认的类型转换函数
    explicit Stock(int n);

    // 设置默认值的 默认构造函数 等同于Stock() 类中只能有一个默认构造函数
    // 两者只能定义一个
    // 默认构造函数 由默认参数值时 必须给所有参数提供默认值
    // Stock(int i = 1, std::string name = "hello");

    Stock(std::string name);

    // 析构函数
    ~Stock();

    // 类型转换函数
    // 将Stock对象转换为int
    // explicit operator int (); explicit 关键字指明该转换函数必须为显示调用
    operator int();

public:
    void sys();

    static void sys_static();

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

    // 注意参数列表中一般会有一个引用类型的形参
    friend void friend_method(Stock &stock);

    // 友元函数 不是类的成员函数 但是可以访问类的所有成员
    friend Stock operator*(int n, const Stock &stock);

    Stock operator*(const Stock &stock);

    // 重载输出流 << 运算符
    friend std::ostream &operator<<(std::ostream &os, const Stock &s);
};


#endif //DEMO_TEST_STOCK_H
