#ifndef DEMO_TEST_USELESS_H
#define DEMO_TEST_USELESS_H

#include <string>

class Useless {
private:
    std::string name;
    char *p;
public:
    //默认构造函数
    Useless();

    //构造函数
    Useless(std::string name);

    //复制构造函数 如果不自己实现，则浅复制
    Useless(const Useless &f);

    // 编译器默认会实现移动构造函数
    // 禁止了移动构造函数 则外部就不能使用
    // Useless(Useless &&useless) = delete;
    Useless(Useless &&useless);

    //复制赋值运算符
    Useless operator+(const Useless &f) const;

    //析构函数
    ~Useless();

    void showData() const;

};


#endif //DEMO_TEST_USELESS_H
