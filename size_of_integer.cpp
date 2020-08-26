#include <iostream>

// 不写using namespace的话，有两种写法，一种是C92的iostream.h；另一种是直接写std::cout
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of short: " << sizeof(short) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    return 0;
}
