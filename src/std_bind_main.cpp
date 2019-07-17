#include <iostream>
#include <functional>

using namespace std;
/**
    关于bind的用法：
        可将bind函数看作是一个通用的函数适配器，它接受一个可调用对象，
    生成一个新的可调用对象来“适应”原对象的参数列表。

    调用bind的一般形式：auto newCallable = bind(callable,arg_list);
    其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。
    即，当我们调用newCallable时，newCallable会调用callable,并传给它arg_list中的参数。
    arg_list中的参数可能包含形如_n的名字，其中n是一个整数，这些参数是“占位符”，
    表示newCallable的参数，它们占据了传递给newCallable的参数的“位置”。
    数值n表示生成的可调用对象中参数的位置：_1为newCallable的第一个参数，_2为第二个参数，以此类推。
 */
namespace test_std_bind {
    class A {
    public:
        void fun_3(int k, int m) {
            cout << k << " " << m << endl;
        }
    };
}


void fun(int x, int y, int z) {
    cout << x << "  " << y << "  " << z << endl;
}

void fun_2(int &a, int &b) {
    a++;
    b++;
    cout << a << "  " << b << endl;
}

int main_std_bind() {
//f1的类型为 function<void(int, int, int)>
    auto f1 = std::bind(fun, 1, 2, 3); //表示绑定函数 fun 的第一，二，三个参数值为： 1 2 3
    f1(); //print:1  2  3

    auto f2 = std::bind(fun, placeholders::_1, placeholders::_2, 3);
    //表示绑定函数 fun 的第三个参数为 3，而fun 的第一，二个参数分别由调用 f2 的第一，二个参数指定
    f2(1, 2);//print:1  2  3

    auto f3 = std::bind(fun, placeholders::_2, placeholders::_1, 3);
    //表示绑定函数 fun 的第三个参数为 3，而fun 的第一，二个参数分别由调用 f3 的第二，一个参数指定
    //注意： f2  和  f3 的区别。
    f3(1, 2);//print:2  1  3

    int n = 2;
    int m = 3;

    auto f4 = std::bind(fun_2, n, placeholders::_1); //表示绑定fun_2的第一个参数为n, fun_2的第二个参数由调用f4的第一个参数（_1）指定。
    f4(m); //print:3  4

    cout << m << endl;//print:4  说明：bind对于不事先绑定的参数，通过std::placeholders传递的参数是通过引用传递的,如m
    cout << n << endl;//print:2  说明：bind对于预先绑定的函数参数是通过值传递的，如n

    test_std_bind::A a;
    //f5的类型为 function<void(int, int)>
    auto f5 = std::bind(&test_std_bind::A::fun_3, a, placeholders::_1, placeholders::_2); //使用auto关键字
    f5(10, 20);//调用a.fun_3(10,20),print:10 20

    std::function<void(int, int)> fc = std::bind(&test_std_bind::A::fun_3, a, std::placeholders::_1,
                                                 std::placeholders::_2);
    fc(10, 20);//调用a.fun_3(10,20) print:10 20

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}

