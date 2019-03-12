//
// Created by Apple on 2019/3/12.
//

#ifndef DEMO_TEST_TEMPLATE_CLASS_H
#define DEMO_TEST_TEMPLATE_CLASS_H


template<class T>
class Stack {
public:
    T arr[100];
    int cur_p = -1;
public:
    Stack();

    ~Stack();

    void push(T t);

    T pop();
};

#endif //DEMO_TEST_TEMPLATE_CLASS_H
