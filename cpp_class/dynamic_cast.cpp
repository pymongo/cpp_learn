#include <iostream>
using namespace std;

void temp() {}

struct Base {
    // 基类的虚函数不能写成`print();`
    // 否则会报错: Undefined Reference to Typeinfo 或 vtable报错
    // 原因是基类未实现虚函数
    virtual void print() {}
};

struct Derived : Base {
    void print() {
        cout << "Derived\n";
    }
};

int main() {
    Derived* d1 = new Derived();
    d1->print();

    Base* bd1 = (Base*) d1;
    bd1->print(); // C's type convert, unsafe: if Base doesn't have print() and Derived has print()

    // C++'s dynamic_cast is a safe type convert
    // if bd1 is not a instance of Derived by RTTI(Run-Time Type Information)
    // d2 would be a NULL(C++通过RTTI探测instance的类型，如果不能安全的通过dynamic_cast去转换，则会返回NULL)
    Derived* d2 = dynamic_cast<Derived*>(bd1);
    if (d2 != nullptr) {
        d2->print();
    }
    return 0;
}
