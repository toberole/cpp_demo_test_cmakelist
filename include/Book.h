//
// Created by Apple on 2018/12/18.
//

#ifndef DEMO_TEST_BOOK_H
#define DEMO_TEST_BOOK_H

#include <functional>
#include <string>

/**
 * 注意要实现 move的功能
 */
class Book {
public:
    Book();

    ~Book();

    // move 构造函数
    // Book(Book &&book);

    Book(int _price, std::string _name);

    // 拷贝构造函数
    // Book &operator=(const Book &other);

    void sysName(std::function<void(int i, int j)> fun, std::string ls);

public:
    int price;
    std::string name;
};


#endif //DEMO_TEST_BOOK_H
