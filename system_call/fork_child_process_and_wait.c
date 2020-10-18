/* Rust标准库并没有提供fork系统调用创建子进程的API(需要用nix第三方库)
 * https://www.geeksforgeeks.org/fork-system-call
 * */
#include <stdio.h>
#include <unistd.h>

/* 要在terminal上运行才能看到完整的8次打印，在IDE的terminal上看不到所有进程的输出
 * 进程的所有数据都会复制一份，子进程间数据时互相独立的: A child process uses the same program counter, same CPU registers, same open files which use in the parent process.
 * 类似有丝分裂, 1->2, 2->4, 4->8
 * */
void print_8_times() {
    // We don’t know whether the OS will first give control to the parent process or the child process.
    if (fork() == 0) {
        // fork之后具体是child还是parent获得控制权由操作系统调度决定，反正最终Child和Parent都会走一遍只是先后顺序不确定
        printf("Child\n");
    } else {
        printf("Parent\n");
    }
    fork();
    fork();
    // After a new child process is created, both processes will execute the next instruction following the fork() system call
    printf("%s:%d\n", __FUNCTION__, __LINE__);
}

int main() {
    print_8_times();
    return 0;
}