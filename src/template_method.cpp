//
// Created by Apple on 2019/3/12.
//


template<typename T>
void swap_(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}