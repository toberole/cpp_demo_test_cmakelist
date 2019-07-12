#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <memory>

// string与w_string进行互转
// C++11 gcc5以上 直接使用std::wstring_convert() 函数就可以进行互转
std::wstring s2ws(const std::string &str) {
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring &wstr) {
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.to_bytes(wstr);
}

void test_string_01() {
    std::wstring ws = L"计算机 ji";
    std::cout << "ws 长度: " << ws.length() << std::endl;
    std::string s = ws2s(ws);
    std::cout << "s: " << s << " 字节数: " << sizeof(s) << std::endl;
}

// string与w_string进行互转
// C++11 gcc4.8以上 使用wcstombs() 和 mbstowcs()
void test_string_02() {
    setlocale(LC_ALL, "");
    std::wstring ws = L"今天天气H";
    std::cout << "ws.size: " << ws.size() << std::endl;
    int len = wcslen(ws.c_str());
    std::cout << "wcslen:" << len << std::endl;
    char str_buf[100];
    int n = wcstombs(str_buf, ws.c_str(), 100);
    std::string out = std::string(str_buf, n);
    std::cout << "w > s(" << out << "):" << out.size() << std::endl;
}

void test_string_03() {
    setlocale(LC_ALL, "");
    std::string s = "今天天气123";
    std::cout << s.size() << std::endl;
    wchar_t wstr_buf[100];
    int m = mbstowcs(wstr_buf, s.c_str(), 100);
    std::wstring wout = std::wstring(wstr_buf, m);
    std::cout << "s > w:" << wout.size() << std::endl;
}

// 智能指针
void test_string_04() {
    // auto_ptr c98提供的技术，c11已经摈弃了
    std::auto_ptr<int> autoPtr((new int));
}


int main_string() {
    test_string_04();


    std::cout << "\npress any key to exit ..." << std::endl;
    getchar();
    return 0;
}