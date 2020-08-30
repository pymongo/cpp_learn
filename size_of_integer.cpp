#include <iostream>

// 不写using namespace的话，有两种写法，一种是C92的iostream.h；另一种是直接写std::cout
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Size of bool: " << sizeof(bool) << '\n'
         << "Size of char: " << sizeof(char) << '\n'
         << "Size of short: " << sizeof(short) << '\n'
         << "Size of int: " << sizeof(int) << '\n'
         << "Size of long: " << sizeof(long) << '\n'
         << "Size of long long: " << sizeof(long long) << endl;
    return 0;
}
