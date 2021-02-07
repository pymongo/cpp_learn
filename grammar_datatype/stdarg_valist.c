#include <stdio.h>
#include <stdarg.h>

/* 看libc源码时发现`fn printf(format: *const c_char, ...) -> c_int;`
 * 查阅资料后发现C语言的...是函数任意个入参的意思，like Python's *args(Arbitrary Arguments)
 * 通过宏在编译时展开实现任意个参数的效果，个人感觉跟C语言用宏文本替换或void*实现"泛型"一样，也是个没有强约束和静态检查的东西
 * 这种写法就像void*实现的swap要传参类型大小，或者sum要传入元素个数，为什么不直接入参传数组呢?这样写没有将sum()输入个数和入参的元素的实际个数强约束起来
 * */
int sum(int len, ...) {
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
    printf("sum = %d\n", sum(4, 1, 2, 3, 4));
    return 0;
}
