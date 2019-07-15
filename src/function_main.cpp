#include <functional>
#include <iostream>

using namespace std;

/**
    类模版std::function是一种通用、多态的函数封装。std::function可以对任何可以调用的实体进行封装，
    这些目标实体包括普通函数、Lambda表达式、函数指针、以及其它函数对象等。std::function对象是对
    C++中现有的可调用实体的一种类型安全的包裹（我们知道像函数指针这类可调用实体，是类型不安全的）。
    通常std::function是一个函数对象类，它包装其它任意的函数对象，被包装的函数对象具有类型为
    T1, …,TN的N个参数，并且返回一个可转换到R类型的值。std::function使用 模板转换构造函数接收被包装
    的函数对象；特别是，闭包类型可以隐式地转换为std::function。也就是说，通过std::function对C++中
    各种可调用实体（普通函数、Lambda表达式、函数指针、以及其它函数对象等）的封装，形成一个新的可调用
    的std::function对象；让我们不再纠结那么多的可调用实体。
 */

/**
 * 关于可调用实体转换为std::function对象需要遵守以下两条原则：
(1)转换后的std::function对象的参数能转换为可调用实体的参数；
(2)可调用实体的返回值能转换为std::function对象的返回值。
std::function对象最大的用处就是在实现函数回调，使用者需要注意，它不能被用来检查相等或者不相等，但是可以与NULL或者nullptr进行比较。

function对象好处

        std::function实现了一套类型消除机制，可以统一处理不同的函数对象类型。以前我们使用函数指针来完成这些；现在我们可以使用更安全的std::function来完成这些任务。

 */


std::function<int(int)> Functional;

// 普通函数
int TestFunc(int a) {
    return a;
}

// Lambda表达式
auto lambda = [](int a) -> int { return a; };

// 仿函数(functor)
class Functor {
public:
    int operator()(int a) {
        return a;
    }
};

// 1.类成员函数
// 2.类静态函数
class TestClass {
public:
    int ClassMember(int a) { return a; }

    static int StaticMember(int a) { return a; }
};

int main() {
    // 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数：" << result << endl;

    // Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "Lambda表达式：" << result << endl;

    // 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数：" << result << endl;

    // 类成员函数
    TestClass testObj;
    Functional = std::bind(&TestClass::ClassMember, testObj, std::placeholders::_1);
    result = Functional(40);
    cout << "类成员函数：" << result << endl;

    // 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数：" << result << endl;

    return 0;
}