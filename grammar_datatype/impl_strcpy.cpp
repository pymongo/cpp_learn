#include <iostream>

// 为了实现链式操作，将dest的地址也返回
char *strcpy(char *dest, const char *src) {
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    while ((*dest++ = *src++) != '\0');
    return dest;
}

int main() {
    char src[7] = "source";
    char dest[7];
    strcpy(dest, src);
    std::cout << dest << '\n';
    return 0;
}

void test() {
    // 下面这段代码的问题:
    // 1. malloc后未进行内存是否申请成功的判断
    // 2. free了str指向的堆内存后，应该将str设为NULL避免野指针
    char *str = (char *) malloc(100);
    strcpy(str, "hello");
    free(str);

    // 正确写法:
    char *s_ptr = (char *) malloc(100);
    if (s_ptr == nullptr) {
        printf("malloc堆内存申请失败\n");
        exit(-1);
    }
    strcpy(s_ptr, "hello");
    free(str);
    str = nullptr;
}