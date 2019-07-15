#include <iostream>
#include <thread>
#include <functional>
#include <Useless.h>

void test_lambda() {
    auto func = []() {
        std::cout << "test_lambda" << std::endl;
    };

    func();
}

//  引用useless 超出作用域 会导致不可控异常
void test_lambda1() {
    Useless useless;

    // 引用捕获
    auto func = [&useless]() {
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        useless.showData();
        std::cout << "test_lambda: " << std::endl;
    };

    std::thread th(func);
    th.detach();
}

void test_lambda2() {
    Useless useless;

    // 值捕获
    auto func = [useless]() {
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        useless.showData();
        std::cout << "test_lambda: " << std::endl;
    };

    // auto func1 =  std::bind(func,useless);

    std::thread th(func);
    th.detach();
}

void test_lambda_func() {
    test_lambda1();
}

void test_lambda_func1() {
    test_lambda2();
}

class Foo {
public:
    void print_info(int i) const {
        std::cout << "print_info: " << i << std::endl;
    }

    void print_info_x(int i) {
        std::cout << "print_info: " << i << std::endl;
    }
};

// function
void test_lambda3() {
    std::function<void(const Foo &, int)> func = &Foo::print_info;
    Foo foo;
    func(foo, 100);
}

// function
void test_lambda4() {
    std::function<void(Foo &, int)> func = &Foo::print_info_x;
    Foo foo;
    func(foo, 200);
}

int main_lambda() {
    test_lambda3();
    test_lambda4();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}