#include <iostream>


void test_char1() {
    // wchar_t 不同库实现可能会不同
    // 前缀“L”可以指示宽字符常量和宽字符串 w_char
    wchar_t wch = L'中';
    std::wcout << L"wch: " << wch << "\n";

    // u char16_t
    char16_t _16ch = u'中';
    std::cout << u"char16_t: " << _16ch << std::endl;

    char32_t _32ch = U'中';
    std::cout << U"char32_t: " << _32ch << std::endl;
}

int main_char() {
    std::cout << "char main" << std::endl;
    test_char1();
    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}

