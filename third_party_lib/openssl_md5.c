#include <openssl/md5.h> // MD5
#include <stdio.h>       // sprintf, printf
#include <string.h>      // strlen

/*
## MD5的返回值的地址 跟 传入md5_output参数的地址一样
unsigned char *md5_ret = MD5((unsigned char *)input_str, strlen(input_str), md5_output);
printf("md5_output=%p, md5_ret=%p\n", md5_output, md5_ret); // same address

## 或者用md5 context相关的几个方法进行hash
MD5_CTX ctx;
MD5_Init(&ctx);
MD5_Update(&ctx, (unsigned char *)input_str, strlen(input_str));
MD5_Final(md, &ctx);

## reference:
- https://blog.csdn.net/shahongzhou/article/details/6307972
- https://stackoverflow.com/questions/41095147/converting-unsigned-char-array-to-hex

## C语言怎么返回固定长的栈上数组
不知道C语言要怎么写才能返回固定长度的栈上数组
例如Rust可以这么写:
fn md5_hash(input: &[u8]) -> [u8; 32];

我把`void md5_hash`返回值改成`char[32] md5_hash`就编译报错

我只好给函数加一个存放返回值的可变指针的作为入参
fn md5_hash(input: &[u8], output: &mut [u8; 32]);
*/
void md5_hash(const char *input_str, char md5_hash_ouput[32]) {
    unsigned char md5_output[16];
    MD5((unsigned char *)input_str, strlen(input_str), md5_output);
    // print output
    // for (int i=0; i<16; i++) printf("%02x", md5_output[i]); printf("\n");

    // storage output
    //char output[32]; // stack memory can't return
    for (int i=0; i<16; i++) {
        sprintf(md5_hash_ouput+2*i, "%02x", md5_output[i]);
    }
    //printf("%s\n", output);
}

int main() {
    const char* md5_hash_input = "The quick brown fox jumps over the lazy dog";
    char md5_hash_output[32]; // TODO add '\0' to end of str?
    md5_hash(md5_hash_input, md5_hash_output);
    printf("md5_hash_input =%s\nmd5_hash_output=%s\n", md5_hash_input, md5_hash_output);
    return 0;
}
