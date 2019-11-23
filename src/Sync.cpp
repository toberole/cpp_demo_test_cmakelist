#include <iostream>
#include <thread>
#include <mutex>

/**
 * 1.	C++线程和基础同步原语
 *      Thread
 *      mutex, lock_guard,unique_lock, condition variable, semaphore
 * 2.	高级同步原语：future and async/packaged_task/promise
 */
void func1() {
    std::cout << "func1()" << std::endl;
}

void func2(int n) {
    std::cout << "func2() n: " << n << std::endl;
}

void sync_test1() {
    std::thread th(func1);
    th.join();
}

void sync_test2() {
    std::thread th(func2, 110);
    th.join();
}

/**
 * mutex:
 *      不可重入
 *      当mutex.lock 之后的代码发生异常 没有执行mutex.unlock
 *      将导致其他线程也无法获取到锁
 *
 *      使用Lock_guard处理
 */
std::mutex mutex;
int n = 0;

void sync_add_func() {
    mutex.lock();
    n++;
    mutex.unlock();
}

void sync_test3_func1() {
    try {
        mutex.lock();
        n++;
        mutex.unlock();
    } catch (int e) {
        std::cout << "e: " << e << std::endl;
    } catch (...) {// 捕获所有异常
        std::cout << "... 捕获所有异常" << std::endl;
        mutex.unlock();
    }
}

void sync_test3() {
    for (int i = 0; i < 10; ++i) {
        std::thread th1(sync_add_func);
        // std::thread th2(sync_test3_func);
        th1.join();
    }

//    th1.join();
//    th2.join();

    std::cout << "n: " << n << std::endl;
}

/**
 * 在线程进入临界区之前声明lock_guard变量，将mutex变量作为变量传入，
 * 在构造函数中会调用该变量的lock()，在析构函数中调用unlock()，
 * 如此无论是正常运行结束还是临界区中出现异常都会正常执行锁操作。
 * lock_guard优势是实现简单、使用方便，适用于大多数场景，
 * 但存在的问题是使用场景过于简单，无法处理一些精细操作。
 * 此时便需要使用 unique_lock。
 */

void sync_add1_func() {
    std::lock_guard<std::mutex> lock_guard(mutex);
    n++;
}

void sync_test4() {
    for (int i = 0; i < 100; ++i) {
        std::thread th(sync_add1_func);
        th.join();
    }

    std::cout << "n: " << n << std::endl;
}


void sync_test5() {
    for (int i = 0; i < 100; ++i) {
        std::thread th(sync_add1_func);
        th.join();
    }

    std::cout << "n: " << n << std::endl;
}

// 可重入锁
std::recursive_mutex recursive_mutex;
int sync_k = 0;

void sync_add_test6() {
    // 可重入
    recursive_mutex.lock();
    recursive_mutex.lock();
    sync_k++;
    // unlock 与 lock必须成对出现
    recursive_mutex.unlock();
    recursive_mutex.unlock();
}

void sync_test6() {
    for (int i = 0; i < 10; ++i) {
        std::thread th(sync_add_test6);
        th.join();
    }

    std::cout << "sync_k: " << sync_k << std::endl;
}

// mutex+condition_variable 实现生产者、消费者模式
/*
 * std::condition_variable 提供了两种 wait() 函数。
 * 当前线程调用 wait() 后将被阻塞(此时当前线程应该获得了锁（mutex），不妨设获得锁 lck)，直到另外某个线程调用 notify_* 唤醒了当前线程。
 * 在线程被阻塞时，该函数会自动调用 lck.unlock() 释放锁，使得其他被阻塞在锁竞争上的线程得以继续执行。另外，一旦当前线程获得通知(notified，通常是另外某个线程调用 notify_* 唤醒了当前线程)，wait() 函数也是自动调用 lck.lock()，使得 lck 的状态和 wait 函数被调用时相同。
 * 在第二种情况下（即设置了 Predicate），只有当 pred 条件为 false 时调用 wait() 才会阻塞当前线程，并且在收到其他线程的通知后只有当 pred 为 true 时才会被解除阻塞。因此第二种情况类似以下代码：
 *  while (!pred()) wait(lck);
 */
std::mutex sync_mutex;
int sync_source;
std::condition_variable sync_condition_v;

void p() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(sync_mutex);
        while (sync_source >= 1) {
            sync_condition_v.wait(lock);
        }
        sync_source++;
        std::cout << "生产者生产 sync_source: " << sync_source << std::endl;
        sync_condition_v.notify_all();
    }
}

void c() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(sync_mutex);
        while (sync_source < 1) {
            sync_condition_v.wait(lock);
        }
        sync_source--;
        std::cout << "消费者消费 sync_source: " << sync_source << std::endl;
        sync_condition_v.notify_all();
    }
}

void test_p_c() {
    std::thread th_p(p);
    std::thread th_c(c);
    th_p.join();
    th_c.join();
}

int main_sync(int argc, char *args[]) {
    std::cout << "sync.cpp" << std::endl;
    // sync_test1();
    // sync_test2();
    // sync_test3();
    // sync_test4();
    // sync_test6();
    test_p_c();
    return 0;
}