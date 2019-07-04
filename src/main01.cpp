#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <array>
#include <string.h>
#include <thread>

#include "Vptr_Impl.h"
#include "Data.h"
#include "Class_Stock.h"
#include "Class_demo.h"
#include "Enum_Demo.h"

typedef struct Student {
    std::string name;
    int age;
} stu;

union DD {
    int i;
    long l;
    double d;
};

enum Day {
    F = 1, FF = 100
};

void test_main01() {
    std::cout << "-- test_main01 --" << std::endl;
}

void test_main02() {
    std::cout << "main()" << std::endl;
    Vptr *p = new Vptr_Impl();
    delete (p);

    p = NULL;
    delete (p);

    test_main01();

    int n;
    std::cout << "input n" << std::endl;
    std::cin >> n;
    std::cout << "n: " << n << std::endl;
}

void test_main03() {
    int i = INT_MAX;
    std::cout << "max int: " << i << std::endl;
    std::cout << "long size: " << sizeof(long) << std::endl;
    std::cout << "long long size: " << sizeof(long long) << std::endl;


    char *p = "hello";
    char p1[] = {'h', 'e', 'l'};

    std::cout << "p size: " << sizeof p << " p1 size: " << sizeof(p1) << std::endl;
}

void test_main04() {
    std::vector<Data> v;
    Data data;
    v.push_back(data);

    char ch;
    std::cin >> ch;
    std::cout << "ch: " << ch << std::endl;
}


void test_main05() {
    wchar_t ch;
    std::wcin >> ch;
    std::wcout << ch << std::endl;
}

void test_main06() {
    float f1 = 11.17f;
    float f2 = 50.25f;
    float f3 = f1 + f2;
    std::cout << f3 << std::endl;
}

void test_main07() {
//    char arr[100] = {0};
//    std::cin >> arr;
//    std::cout << arr << std::endl;

    char *p = "hello world";
    std::cout << "p len: " << strlen(p) << std::endl;
    std::cout << "p size: " << sizeof(p) << std::endl;

    char arr[20];
    std::cin.getline(arr, 20);
    std::cout << arr << std::endl;
}

void test_main08() {
    std::string str;
    std::cin >> str;

    std::string str2 = "hello";

    std::cout << str << std::endl;
}

/**
 * wchar_t
 * char16_t
 * char32_t
 */
void test_main09() {
    wchar_t wch[] = L"hello";
    char16_t ch_1_6[] = u"hello";
    char32_t ch_3_2[] = U"hello";
}

void test_main10() {
    stu stu0;
    stu0.name = "hello";
    stu0.age = 11;

    stu stu1 = stu0;

    std::cout << stu0.name << stu0.age << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << stu1.name << stu1.age << std::endl;

    stu s = {"hello", 22};
    std::cout << s.name << s.age << std::endl;

    struct Student ss;
}

void test_main11() {
    DD d;
    d.d = 1.0;
    std::cout << "d.d: " << d.d << std::endl;
    std::cout << "d.i: " << d.i << std::endl;

    d.i = 11;
    std::cout << "d.i: " << d.i << std::endl;

    d.l = 111;
    std::cout << "d.l: " << d.l << std::endl;

    Day day = FF;
}

void test_main12() {
    stu *p = new stu;
    p->name = "new name";
    p->age = 33;

    std::cout << "name: " << p->name << " age: " << p->age << std::endl;
}

void test_main13() {
    int *ip = new int[1];
    (*ip) = 11;
    std::cout << *ip << std::endl;

    int *p = new int[10];
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 1;
    }

    for (int j = 0; j < 10; ++j) {
        std::cout << j << " ";
    }

    delete[]p;
}

void test_main14() {
    int *p = new int[10];
    std::cout << "sizeof(p): " << sizeof(p) << std::endl;
    int arr[10];
    std::cout << "sizeof(arr): " << sizeof(arr);
}

/**
 * tell+1 加short size
 * &tell+1 加10*short size
 */
void test_main15() {
    short tell[10];
    std::cout << tell << std::endl;// display &tell[0]
    std::cout << &tell << std::endl;// display address of the whole tell

    char *chs = new char[10];
    std::cout << "*chs: " << strlen(chs) << std::endl;
    chs = "hello";
    std::cout << "*chs: " << strlen(chs) << std::endl;
}

/**
 * vector
 * array
 */
void test_main16() {
    Data data;

    std::vector<Data> datas;
    datas.push_back(data);
    std::vector<Data> datas1 = datas;
    std::cout << "+++++++++++++++" << std::endl;
    std::array<Data, 5> arr;
    arr[0] = data;
}

void test_main17() {
    char *p = "hello 你好 world";
    char *p1 = "你好";
    std::cout << strlen(p) << std::endl;
    std::cout << strlen(p1) << std::endl;
}

int *test_main18() {
    int arr[10];
    std::cout << "arr size: " << sizeof(arr) << std::endl;
    int *p = arr;
    std::cout << "p size: " << sizeof(p) << "  " << p << std::endl;
}

void test_main19() {
    stu *s = new stu();
    s->age = 11;
    s->name = "hello stu";
    std::cout << "name: " << s->name << " age: " << s->age << std::endl;
}

void test_main20() {
    int i = 20;
    int &ii = i;
    int *p = &ii;

    std::cout << p << std::endl;
}

void test_main_21(const int &a) {

}

void test_main21() {
    int i = 11;
    int *p = &i;
    int &ii = *p;

    test_main_21(11);

    std::cout << ii << "  " << *p << std::endl;
}

void test_main_22(const stu &a) {
    std::cout << a.age << std::endl;
}

void test_main22() {
    stu stu1;
    stu1.age = 11;

    test_main_22(stu1);
}

template<class T>
void swap(T &t1, T &t2) {
    T temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}

template<typename T>
void swap1(T tt);

void test_main23() {
    int n = 10;
    int m = 20;
    swap(n, m);

    std::cout << n << "  " << m << std::endl;
}

int global = 110;

void test_main24_0() {
    // 局部
    int global = 220;
    std::cout << "局部 global: " << global << std::endl;

    // 全局 "::"作用域解析运算符 该运算符表示使用全局版本
    std::cout << "全局 global: " << ::global << std::endl;
}

void test_main24() {
    // 声明使用全局global
    extern int global;
    std::cout << "全局 global: " << global << std::endl;
    test_main24_0();
}

int test = 666;

void test_main25_0() {
    std::cout << "\ntest_main25_0" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "**** test_main25_0 test: " << test << std::endl;
}

void test_main25_1(int i) {
    std::cout << "\ntest_main25_1 i: " << i << std::endl;
}

/**
 * detach模式下，主线程死了 子线程也会死掉
 */
void test_main25() {
    std::thread th(test_main25_0);
    std::thread th1(test_main25_1, 222);
    th.join();
    th1.join();
}

namespace com {
    void test_main25() {
        std::thread th(test_main25_0);
        std::thread th1(test_main25_1, 222);
        th.join();
        th1.join();
    }
}

/**
 * 枚举
 */
void test_main27() {
    enum day d = day1;
    if (d == 0) {
        std::cout << "d == 0" << std::endl;
    }

    day4 dd = day4::day31;
    std::cout << "dd: " << (int) dd << std::endl;
}

/**
 * 类
 */
void test_main26() {
    Stock stock;
    stock.update();
    stock.test_static();
    Stock::test_static();

    Stock stock1("hello1");
    Stock stock2 = Stock("hello2");
    stock1.sys();
    stock2.sys();

    Stock *stock3 = new Stock("hello3");
    stock3->sys();
    delete (stock3);

    // 注意:malloc分配的内存 只能用free释放
    std::cout << "malloc分配的内存 只能用free释放" << std::endl;
    Stock *stock4 = (Stock *) malloc(sizeof(Stock));
    stock4->sys();
    free(stock4);

    const Stock stock5;
    stock5.sys_const();
    // 错误调用 sys没有用const声明
    // stock5.sys();

    // 错误调用 sys没有用const声明
//    const Stock *stock5_p;
//    stock5_p->sys();

    // 错误调用 不能修改const对象
//    const Stock stock6;
//    stock6.n = 20;

    /**
     * 编译器首先会使用默认的构造函数来创建数组元素
     * 然后创建临时的对象 随后将临时对象的内容复制到相应的元素中
     * 因此 要创建类对象数组，那么这个类必须由默认的构造函数。
     */
    // 错误 该类没有提供默认构造函数
    // Class_demo cds[4];

    Stock stock6;
    stock6.n = 11;
    Stock stock7;
    stock7.n = 22;
    stock6 + stock7;
    std::cout << "stock6 + stock7: " << stock6.n << std::endl;

    Stock stock8;
    stock8.n = 10;
    int n = 10;
    stock8 = n * stock8;
    std::cout << "stock8.n: " << stock8.n << std::endl;
    std::cout << "hello---- " << stock8;

}

int main() {
    test_main26();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}