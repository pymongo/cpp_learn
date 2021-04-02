#include <iostream> // cout
#include <cstdarg> // va_list, va_start, va_arg, va_end
#include <cassert> // assert

using std::cout;

template<typename T>
void swap(T &a, T &b) { // a and b is a reference not a raw_pointer(T* a)
    T temp = a;
    a = b;
    b = temp;
}

// variadic_templates/parameter_pack
template <typename ... Ts>
auto sum_parameter_pack(Ts...args) {
    // https://en.cppreference.com/w/cpp/language/fold
    return (0 + ... + args);
}

int sum_va_list(int len, ...) {
    va_list valist;
    va_start(valist, len);
    int sum = 0;
    for (int i=0; i<len; i++) {
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum;
}

int main() {
    assert(sum_parameter_pack(0) == 0);
    assert(sum_parameter_pack(1,2,3) == 6);
    assert(sum_va_list(3, 1, 2, 3) == 6);
    return 0;
}
