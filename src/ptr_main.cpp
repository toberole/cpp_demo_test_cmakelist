#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>// 算法

#include "Ptr_Test.h"

void test_ptr_11(std::shared_ptr<Ptr_Test> ptr);

void foreach_(int k);

//
void test_ptr_1() {
    // auto_ptr
    std::cout << "-------- auto_ptr --------" << std::endl;
    std::auto_ptr<Ptr_Test> auto_ptr0(new Ptr_Test);
    // 赋值将导致auto_ptr0失去其指针指向对象的所有权
    std::auto_ptr<Ptr_Test> auto_ptr1 = auto_ptr0;
    auto_ptr1->sys();
    // TODO 错误用法：auto_ptr0失去了所有权 继续使用会不稳定 导致异常
    //auto_ptr0->sys();
    // TODO 错误用法 std::auto_ptr不能用于数组
    // std::auto_ptr<int[]> auto_ptr1(new int[10]);

    std::cout << "-------- unique_ptr --------" << std::endl;
    // unique_ptr
    std::unique_ptr<Ptr_Test> unique_ptr1(new Ptr_Test);
    // TODO 错误用法
    // std::unique_ptr<Ptr_Test> unique_ptr2 = unique_ptr1;
    // 使用move unique_ptr1失去所有权
    std::unique_ptr<Ptr_Test> unique_ptr2 = std::move(unique_ptr1);
    // 用右值赋值 正确 分清左右值
    std::unique_ptr<Ptr_Test> unique_ptr3 = std::unique_ptr<Ptr_Test>(new Ptr_Test);
    // 用于数组
    std::unique_ptr<int[]> unique_ptr4(new int[10]);

    std::cout << "-------- shared_ptr --------" << std::endl;
    // shared_ptr
    std::shared_ptr<Ptr_Test> shared_ptr2(new Ptr_Test);
    // unique_ptr为右值时 可以赋值给std::shared_ptr
    std::shared_ptr<Ptr_Test> shared_ptr3(std::unique_ptr<Ptr_Test>(new Ptr_Test));

    std::cout << "cout: " << shared_ptr2.use_count() << std::endl;
    std::shared_ptr<Ptr_Test> shared_ptr4 = shared_ptr2;
    // 赋值后引用计数+1
    std::cout << "赋值后 cout: " << shared_ptr2.use_count() << std::endl;
    // 函数调用 +1
    test_ptr_11(shared_ptr2);
    std::cout << "函数调用后 cout: " << shared_ptr2.use_count() << std::endl;

}

// STL
void test_ptr_2() {
    std::vector<int> arr(10);// 10个元素
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    std::cout << "arr size: " << arr.size() << std::endl;

    std::vector<int>::iterator begin = arr.begin();
    arr.erase(begin + 2, begin + 5);
    std::vector<int>::iterator end = arr.end();

    for (std::vector<int>::iterator i = begin; i != end; i++) {
        std::cout << *i << "  ";
    }
}

void test_ptr_3() {
    std::vector<int> arr(10);// 10个元素
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }


    for_each(arr.begin(),arr.end(),foreach_);

}

int main() {

    test_ptr_3();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}


void test_ptr_11(std::shared_ptr<Ptr_Test> ptr) {
    std::cout << "test_ptr_11 count: " << ptr.use_count() << std::endl;
}

void foreach_(int k) {
    std::cout << "foreach_ k: " << k << std::endl;
}