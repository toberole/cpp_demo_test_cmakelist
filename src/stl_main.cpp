#include <iostream>
#include <string>
#include <vector>

class RR {
public:
    std::string hello;
public:
    // 默认构造函数
    RR() {
        std::cout << "默认构造函数 RR()" << std::endl;
    }

    // 拷贝构造函数
    RR(const RR &rr) {
        std::cout << "拷贝构造函数 RR(const RR &rr)" << std::endl;
    }

    // 移动拷贝构造函数
    RR(RR &&rr) {
        std::cout << "移动拷贝构造函数 RR(RR &&rr)" << std::endl;
    }

    RR &operator=(const RR &rr) {
        std::cout << "operator= &" << std::endl;
        return *this;
    }

    RR &operator=(const RR &&rr) {
        std::cout << "operator= &&" << std::endl;
        return *this;
    }

    void sysHello() {
        std::cout << hello << std::endl;
    }

public:
    ~RR() {
        std::cout << "~RR()" << std::endl;
    }
};

RR test_stl11() {
    std::cout << "-----test_stl11-----" << std::endl;

    RR rr;
    std::cout << &rr << std::endl;
    return rr;
}

void test_stl1() {
    char32_t ch = L'我';
    std::cout << ch << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    for (auto n:arr) {
        std::cout << "n: " << n << std::endl;
    }

    // 使用引用可以修改
    int i = 0;
    for (auto &n:arr) {
        n++;
        std::cout << "arr[" << i << "]" << arr[i] << std::endl;
        i++;
    }

    // 右值引用
    int &&k = 11;
    std::cout << "k: " << k << std::endl;
    int *p = &k;
    *p = 111;
    std::cout << "k: " << k << std::endl;

//    RR rr1;
//    RR rr2;
//    RR rr3(test_stl11());
//    RR rr3(rr1 + rr2);
//    std::cout << &rr3 << std::endl;
//    RR rr3(std::move(rr1));
//    RR rr3(rr1);

    RR rr1;
    rr1.hello = "test";
    RR rr2 = std::move(rr1);
    rr1.sysHello();
}

struct X {
    X() { std::cout << "constructed\n"; }

    X(const X &) { std::cout << "copied\n"; }

    X(X &&) { std::cout << "moved\n"; }

    ~X() { std::cout << "destructed\n"; }
};

std::vector<X> Get() {
    // copy elision from tempory object to 'temp', omit copy and move constructor
    std::vector<X> temp = std::vector<X>(1);
    return temp; // NRVO temp to returned
}

class RRR {
public:
    RRR() {
        std::cout << "RRR" << std::endl;
    }
};

RRR test_stl2_1() {
    RRR rrr;
    return rrr;
}

void test_stl2() {
    RRR r = test_stl2_1();
}


int main() {
    test_stl2();

    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}
