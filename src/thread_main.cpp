#include <iostream>
#include <string>
#include <thread>
#include <mutex>

/**
 *  detach方式:
 *      启动的线程自主在后台运行，当前的代码继续往下执行，不等待新线程结束。
 *  join方式:
 *      等待启动的线程完成，才会继续往下执行。
 */

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

    void operator()() {
        std::cout << "Thread_Test operator() " << std::endl;
    }
};

void callback() {
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 3));
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
    std::thread th1(test, 333, "hello 333");
    // std::thread th1(Thread_Test(), 333, "hello 333");
    if (th1.joinable())th1.join();

}

/**
 * 异常情况下等待线程完成当决定以detach方式让线程在后台运行时
 * 可以在创建thread的实例后立即调用detach，这样线程就会后thread的实例分离
 * 即使出现了异常thread的实例被销毁，仍然能保证线程在后台运行。
 * 但线程以join方式运行时，需要在主线程的合适位置调用join方法
 * 如果调用join前出现了异常，thread被销毁，线程就会被异常所终结。
 * 为了避免异常将线程终结，或者由于某些原因，
 * 例如线程访问了局部变量，就要保证线程一定要在函数退出前完成，就要保证要在函数退出前调用join
 */



void test_thread4() {
    std::thread th1(callback);
    th1.detach();

    // 异常 th1 detach模式下，能够继续执行
    int i = 1;
    int ii = 0;
    int j = i / ii;
    std::cout << "j: " << j << std::endl;

}


void test_thread4_1() {
    std::thread th1(callback);
    //th1.join();

    // 异常 th1 detach模式下，能够继续执行
    int i = 1;
    int ii = 0;
    int j = i / ii;
    std::cout << "j: " << j << std::endl;

    // join 当宿主线程崩溃的时候 会导致启动的线程被销毁
    th1.join();
}

void callback_test_thread5(int &a) {
    a++;
    std::cout << "a: " << a << std::endl;
}

void callback_test_thread5_1(const int &a) {
    std::cout << "a: " << a << std::endl;
}

// 传递引用
void test_thread5() {
    int a = 100;
    std::thread th1(callback_test_thread5, std::ref(a));
    th1.detach();
    std::cout << "test_thread5: " << a << std::endl;
}

// 传递const引用
void test_thread6() {
    const int a = 100;
    std::thread th1(callback_test_thread5_1, std::cref(a));
    th1.detach();
    std::cout << "test_thread6: " << a << std::endl;

    int b = 200;
    std::thread th2(callback_test_thread5_1, std::cref(b));
    th2.detach();
}

/*
 线程同步
    mutex
    C++ 11的<mutex>头文件里包含了四种不同的互斥量：
    Mutex: 提供了核心函数 lock() 和 unlock()，以及非阻塞方法的try_lock()方法，一旦互斥量不可用，该方法会立即返回。
    Recursive_mutex:允许在同一个线程中对一个互斥量的多次请求。[Recursive 循环的 递归的]
    Timed_mutex:同上面的mutex类似，但它还有另外两个方法 try_lock_for() 和 try_lock_until()，分别用于在某个时间段里或者某个时刻到达之间获取该互斥量。
    Recursive_timed_mutex: 结合了timed_mutex 和recuseive_mutex的使用。


 */
int k = 0;
std::mutex lock;

void test_thread_mutex() {
    lock.lock();// 不能重复加锁
    k++;
    std::cout << std::this_thread::get_id() << " : " << k << std::endl;
    lock.unlock();
}


std::recursive_mutex recursive_mutex;

// 注意在使用recursive_mutex时，lock与unlock次数要一致
void test_thread_recursive_mutex() {
    recursive_mutex.lock();// 能重复加锁
    recursive_mutex.lock();// 能重复加锁
    k++;
    std::cout << std::this_thread::get_id() << " : " << k << std::endl;
    recursive_mutex.unlock();
    recursive_mutex.unlock();
}

void test_thread7() {
//    for (int i = 0; i < 5; ++i) {
//        std::thread th(test_thread_mutex);
//        th.detach();
//    }

    for (int i = 0; i < 5; ++i) {
        std::thread th(test_thread_recursive_mutex);
        th.detach();
    }
}

void test_thread8() {
    std::thread th(callback);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 3));

    if (th.joinable()) {
        th.join();// join后 回收资源 否则报错
        std::cout << "th.joinable" << std::endl;
    } else {
        std::cout << "not joinable" << std::endl;
    }
}

/**

 在使用std::thread的时候，对创建的线程有两种操作：等待/分离，
 也就是join/detach操作。join()操作是在std::thread t(func)
 后“某个”合适的地方调用，其作用是回收对应创建的线程的资源，避免
 造成资源的泄露。detach()操作是在std::thread t(func)后马上调用，
 用于把被创建的线程与做创建动作的线程分离，分离的线程变为后台线程,
 其后，创建的线程的“死活”就与其做创建动作的线程无关，它的资源会被
 init进程回收。

 */




int main() {
    std::cout << "thread main" << std::endl;

    test_thread8();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}

