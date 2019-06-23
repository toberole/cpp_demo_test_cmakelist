#include <iostream>
#include "Vptr_Impl.h"

int main() {
//    Vptr_Impl vptr;
//    std::cout << "vptr.n: " << &vptr.n << std::endl;
//    std::cout << "vptr: " << &vptr.n << std::endl;

    std::cout << "main()" << std::endl;
    Vptr *p = new Vptr_Impl();
    delete (p);

    std::cout << "press any key to exit ..." << std::endl;
    getchar();
    return 0;
}