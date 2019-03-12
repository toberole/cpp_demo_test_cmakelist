//
// Created by Apple on 2019/3/12.
//
#include "template_class.h"

#include <iostream>

template<class T>
Stack<T>::Stack() {
    std::cout << "Stack()" << std::endl;
}

template<class T>
Stack<T>::~Stack() {
    std::cout << "~Stack()" << std::endl;
}

template<class T>
void Stack<T>::push(T t) {
    if (cur_p < 100) {
        arr[cur_p++] = t;
    }
}

template<class T>
T Stack<T>::pop() {
    if (cur_p > 0) {
        return arr[--cur_p];
    } else {
        return 0;
    }
}