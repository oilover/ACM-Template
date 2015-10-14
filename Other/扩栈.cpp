Linux 64位gcc 4.8.1环境
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int main2(void) __asm__ ("main2");

int main2() {
    char test[255 << 20];
    memset(test, 42, sizeof(test));
    printf(":)\n");
    exit(0);
}

int main() {
    int size = 256 << 20;  // 256Mb
    char *p = (char *)malloc(size) + size;
    __asm__ __volatile__(
        "movq  %0, %%rsp\n"
        "pushq $exit\n" 
        "jmp main2\n"
        :: "r"(p));
}
