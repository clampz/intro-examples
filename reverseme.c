/* reverse me
 * gcc -m32 reverseme.c -o reverseme
 * */

#include <stdio.h>

void isawinner(char *arg) {
    !strcmp(arg, "23ea5") ? puts("!! you win") : puts(":C fail\n");
}

void main(int argc, char ** argv) {
    char buf[10];
    char buf2[10];
    char *endptr;
    printf("enter an input: ");
    fgets(buf, 10, stdin);
    printf("enter a second input: ");
    fgets(buf2, 10, stdin);
    buf2[strcspn(buf2, "\n")] = (char)0;
    (strtol(buf, &endptr, 10) == 1337) ? isawinner(buf2) : puts(":C fail\n");
}
