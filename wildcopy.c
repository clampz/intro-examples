/* wild copy
 * clampz
 * gcc -m32 -fno-stack-protector -o wildcopy wildcopy.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define disable_buffering(_fd) setvbuf(_fd, NULL, _IONBF, 0)

void win() {
    system("/bin/bash");
}

void main() {
    char buf[20];
    int len = 20;
    disable_buffering(stdout);
    while (len >= 20) {
        printf("What is your length? ");
        scanf("%d", &len);
        getc(stdin); // eat up newline
    }
    printf("OK, what is your buf? ");
    read(0, buf, len);
}
