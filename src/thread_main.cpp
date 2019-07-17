#include <iostream>
#include <string>
#include <thread>

class Thread_Test {
public:
    int age;
public:
    void callback() {
        std::cout << "Thread_Test callback age: " << age << std::endl;
    }

    void callback_1(int code) {
        std::cout << "Thread_Test callback_1 age: " << age << " code: " << code << std::endl;
    }

    void operator()(int code, std::string msg) {
        std::cout << "Thread_Test operator() code: " << code << " msg: " << msg << std::endl;
    }
};

void callback() {
    std::cout << "callback" << std::endl;
}

void callback_1(int code, std::string msg) {
    std::cout << "callback_1 " << "code: " << code << " msg: " << msg << std::endl;
}

void test_thread1() {

    std::thread th1(callback);
    std::thread th2(callback_1, 100, "hello");

    Thread_Test test;
    test.age = 22;
    // 调用类的对象方法 编译器会加一个this参数
    std::thread th3(&Thread_Test::callback, &test/*this参数*/);

    if (th1.joinable()) th1.join();
    if (th2.joinable()) th2.join();
    if (th3.joinable()) th3.join();

}

// lambda 表达式
void test_thread2() {
    auto f1 = []() -> void {
        std::cout << "-- f1 --" << std::endl;
    };

    std::thread th1(f1);
    if (th1.joinable()) th1.join();

    int a = 100;
    auto f2 = [a]() -> void {
        std::cout << "-- f2 -- " << a << std::endl;
    };
    std::thread th2(f2);
    if (th2.joinable()) th2.join();

    int a3 = 100;
    auto f3 = [a3](int code, std::string name) -> void {
        std::cout << "-- f3 -- code: " << code << " name: " << name << " a3: " << a3 << std::endl;
    };

    std::thread th3(f3, 666, "hello 777");
    if (th3.joinable()) th3.join();
}

// 重载了函数调用运算符()类的实例
void test_thread3() {
    Thread_Test test;
    // 正确写法
    // std::thread th1(test, 333, "hello 333");
    // 错误写法
    std::thread th1(Thread_Test(), 333, "hello 333");
    if (th1.joinable())th1.join();
}

int main() {
    std::cout << "thread main" << std::endl;

    test_thread3();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}

