//
// Created by Apple on 2018/12/18.
//

#ifndef DEMO_TEST_BOOK_H
#define DEMO_TEST_BOOK_H

#include <string>

class Book {
public:
    Book();

    Book(int _price, std::string _name);

public:
    int price;
    std::string name;
};


#endif //DEMO_TEST_BOOK_H
