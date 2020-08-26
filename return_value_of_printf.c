#include <stdio.h>

int main() {
    int i = 43;
    // 输出是4321，因为printf的返回值是打印字符串的长度
    printf("%d\n", printf("%d", printf("%d", i)));
    return 0;
}