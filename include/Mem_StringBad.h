#ifndef DEMO_TEST_STRINGBAD_H
#define DEMO_TEST_STRINGBAD_H

#include <ostream>

class StringBad {
private:
    char *str;
    int len;
    static int num_strings;
public:
    StringBad(const char *str);

    StringBad();

    // 拷贝构造函数
    StringBad(const StringBad &s);

    // 赋值运算符
    StringBad &operator=(StringBad &stringBad);

    ~StringBad();

    friend std::ostream &operator<<(std::ostream &os, const StringBad &s);
};

#endif //DEMO_TEST_STRINGBAD_H
