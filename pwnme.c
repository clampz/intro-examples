/* pwn me 
 * gcc -m32 -fno-stack-protector pwnme.c -o pwnme
 * */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void runme() {
    puts("party like it's '96\n");
    system("/bin/sh");
}

int main() {
    int  i;
    char buf[10];
    i = 0xd3ad;

    fgets(buf, 0x10, stdin);
    printf("k you wrote %s\nnow ... ", buf);
    fflush(stdout);
    sleep(1);
    if (0 == (0x1337 ^ i)) {
         runme();
    } else {
         puts("eat my shorts!\n");
    }
}
