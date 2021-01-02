#include <stdio.h>
#include <lzma.h> /* size_t */

int hamming_weight(const uint32_t n) {
    size_t input = (size_t) n;
    size_t output;

    asm("popcnt %1, %0"
    : "=r" (output)
    : "r" (input));

    printf("popcnt = %zu\n", output);
    return (int)output;
}

int main() {
    const size_t input = 1;
    size_t output;

    // 别名是__asm__()函数
    // 看来Rust的asm!宏的参数顺序是先output后in也是参考了gcc inline asm的顺序，或者说Rust的asm!就是gcc asm函数的wrapper/binding?
    // 根据gcc官网的例子，最后一个汇编指令的输出寄存器%1要写成$1(但是)
    asm("rol $1, %0"
    : "=r" (output)
    : "r" (input));

    printf("rol_output = %zu\n", output);
    hamming_weight(3);
    return 0;
}
