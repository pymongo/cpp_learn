#include <iostream>
//#include <locale>
//#include <cwchar>

int main() {
    std::cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << std::endl;
//    std::wostream::sync_with_stdio(false);
//    std::wcout.imbue(std::locale("zh_CN.UTF8"));
    wchar_t str[] = L"尽管是UTF-8编码，wchar并不能打印出中文";
    std::wcout << str << std::endl;
    return 0;
}
