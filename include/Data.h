//
// Created by Apple on 2019/3/12.
//

#ifndef DEMO_TEST_DATA_H
#define DEMO_TEST_DATA_H

// 自定义类对象支持moved from 操作
// 需要实现 Move Constructors and Move Assignment Operators
class Data {
public:
    /**
     * 默认的无参构造函数
     */
    Data();

    /**
     * 默认的拷贝构造函数
     */
    Data(const Data &data);

    /**
     * 移动构造函数
     */
    Data(const Data &&data);

    /**
     * Move assignment operator
     */
    Data &operator=(const Data &&data);

    /**
     * 赋值函数
     */
    Data &operator=(const Data &data);

    /**
     * 析构函数
     */
    ~Data();

};


#endif //DEMO_TEST_DATA_H
