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
*/
void openssl_md5_hash(const char *input_str) {
    unsigned char md5_output[16];
    MD5((unsigned char *)input_str, strlen(input_str), md5_output);

    // print output
    // for (int i=0; i<16; i++) printf("%02x", md5_output[i]); printf("\n");

    // storage output
    char output[32]; // stack memory can't return
    for (int i=0; i<16; i++) {
        sprintf(output+2*i, "%02x", md5_output[i]);
    }
    printf("%s\n", output);
}

int main() {
    //char openssl_md5_hash[32];
    openssl_md5_hash("");
    return 0;
}
