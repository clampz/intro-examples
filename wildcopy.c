/* wild copy
 * clampz
 * gcc -m32 -fno-stack-protector -o wildcopy wildcopy.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void win() {
    system("/bin/bash");
}

void main() {
    char buf[20];
    int len = 20;
    while (len >= 20) {
        printf("What is your length? ");
        scanf("%d", &len);
        getc(stdin); // eat up newline
    }
    printf("OK, what is your buf? ");
    fflush(stdout);
    read(0, buf, len);
}
