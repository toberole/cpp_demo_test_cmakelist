#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <array>
#include <string>

#include "Vptr_Impl.h"
#include "Data.h"

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

int main() {
    test_main18();

    std::cout << "press any key to exit ..." << std::endl;
    getchar();
    return 0;
}