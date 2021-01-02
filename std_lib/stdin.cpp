#include <iostream>

using namespace std;

void get_stdin_10_20() {
    // 实际上只能存19个字符，因为最后一个是'\0'
    char buffer[20];
    cin.ignore(10);
    cin.getline(buffer, 10);
    /*
    stdin:  1234567890asdfg
    output: 0asdfg
    */
    cout << buffer << endl;
}

void print_in_ladder_shape() {
    int width = 4;
    char str[20];
    // 考虑结尾有'\0'
    cin.width(width + 1);

    while (cin >> str) {
        cout.width(width++);
        cout << str << endl;
        cin.width(width + 1);
    }
}

int main() {
//    print_in_ladder_shape();
//    exit(0);
    int sum = 0;
    int num;
    while (cin >> num) {
        sum += num;
        while (cin.peek() == ' ') {
            // 消耗掉cin流中的空格
            cin.get();
        }
        if (cin.peek() == '\n') {
            break;
        }
    }
    cout << "sum = " << sum << endl;

//    get_stdin_10_20();
    return 0;
}
