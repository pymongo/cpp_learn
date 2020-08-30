#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// EOF就结束，遇到'\n'就echo
/*
1 2 3
1 2 34 5^D

Process finished with exit code 0
*/
#if 0
void read_stdin_1() {
    char* buffer = (char*)malloc(128);

    // FIXME warning: this program uses gets(), which is unsafe.
    while(NULL != gets(buffer)){
        printf("%s", buffer);
    }

    free(buffer);
//    system("ls");
}
#endif

// C does not support default arguments, C++支持像Python一样参数能有默认值
void read_stdin_sum_of_input() {
    // 从stdin中读取最长为128个字符的内容，遇到\n或EOF就停止
    // 相比scanf和fgets能完整读完一行
    const int BUFFER_SIZE = 128;
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    // 获取buffer中有效的字符数量，要去掉末尾的\n
    int n = (int) strlen(buffer) - 1;
    printf("Input: %s", buffer);

    int sum = 0;
    int i = 0;
    while (i < n) {
        int num = 0;
        while (i < n && buffer[i] != ' ') {
            num = num * 10 + buffer[i] - '0';
            i++;
        }
        sum += num;

        while (i < n && buffer[i] == ' ') {
            i++;
        }
    }
    printf("Sum of input: %d\n", sum);
}

int main() {
    read_stdin_sum_of_input();
}
