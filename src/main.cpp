#include <iostream>
#include <thread>
#include <vector>
#include <string>

#include "util.h"
#include "Student.h"

#include "Singleton.h"
#include "Bus.h"

#include "test_extern.h"

Student getS() {
    Student s;
    s.name = "*** getS ***";
    std::cout << "sp getS: " << &s << std::endl;
    return s;
}

void _print(Student &s) {
    std::cout << "name: " << s.name << std::endl;
}

int main() {
    std::cout << "Hello World!" << std::endl;

    std::cout << "a+b = " << add(1, 3) << std::endl;

#ifdef ADD_DEFINE
    std::cout << "== cmakelist ADD_DEFINE ==" << std::endl;
#endif

    int i = 8;
    int *p = &i;
    SogouEngine sp = p;
    std::cout << *((int *) sp) << std::endl;

    std::vector<int> v;
    v.insert(v.begin(), 11);
    v.insert(v.begin(), 22);
    v.insert(v.begin(), 33);
    v.insert(v.begin(), 44);
    v.insert(v.begin(), 55);

    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        std::cout << "value: " << *it << std::endl;
    }

    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    //std::thread th1(sysHello, 1);

    std::string str = "";
    if (str.empty()) {
        std::cout << "str.empty()" << std::endl;
    }

    std::cout << __FILE__ << std::endl;
    std::cout << __DATE__ << std::endl;

    Student s = getS();
    std::cout << "main sp getS: " << &s << std::endl;
    _print(s);
    s.name = "xiaohong===";
    _print(s);


    std::string s1 = "hello move";
    std::string s2 = std::move(s1);
    std::cout << "s1 ========= " << s1 << std::endl;
    std::cout << "s2 ========= " << s2 << std::endl;


    std::cout << s.toString() << std::endl;

    sysHello();

    int *arr = retArray();

    int *arr_p = nullptr;

    if (nullptr != (arr_p = new int[10])) {
        std::cout << "arr_p: " << arr_p << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    Student student("xiaohong", 11);
    int c = 22;
    int &cc = c;
    student.add(c);
    std::cout << "c: " << cc << std::endl;

    Student *stu = new Student("xiaoming", 21);

    if (nullptr != stu) {
        std::cout << stu->toString() << std::endl;
    }

    std::cout << "name: " << student.name << " age: " << student.age << std::endl;

    delete (stu);

    return 0;
}