#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // C++代码里，想在某个参数中启用多个选项，基本都是通过位运算的或
    // 例如我想设置只读和在末尾打开的模式，就写成ios::in | ios::ate
    // 这是因为这些FLAG都是仅有一位是1，从1、2、4、8..往后排列，所以或运算不会互相干扰
    // 想判断某个mode是否开启，就用(mode && ios::in) == 1 去判断
    // ios::ate: ate aka at the end, 表示打开时文件指针定位到末尾
    ifstream f = ifstream(".gitignore", ios::in | ios::ate);
    f.seekg(ios::beg);
    char buff;
    while (f >> buff) {
        cout << buff;
    }
//    string line;
//    while (getline(f, line)) {
//        cout << line << endl;
//    }
    f.close();
    return 0;
}