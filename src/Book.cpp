//
// Created by Apple on 2018/12/18.
//

#include <string>
#include "Book.h"

Book::Book() {

}

Book::Book(int _price, std::string _name) :
        price(_price),
        name(_name) {
}