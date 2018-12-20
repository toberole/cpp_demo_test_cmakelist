//
// Created by Apple on 2018/12/18.
//
#include <iostream>
#include <string>
#include "Book.h"

Book::Book() {

}

Book::Book(int _price, std::string _name) :
        price(_price),
        name(_name) {
}

Book::~Book() {
    std::cout << "Book 析构函数" << std::endl;
}

void Book::sysName(std::function<void(int i, int j)> fun, std::string ls) {
    std::cout << "sysName: " << ls << std::endl;
    fun(3, 4);
}