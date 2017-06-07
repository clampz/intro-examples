/* reverse me
 * gcc -m32 reverseme.c -o reverseme
 * */

#include <stdio.h>

void isawinner(char *arg) {
    !strcmp(arg, "23ea5") ? puts("!! you win") : puts(":C fail\n");
}

void main(int argc, char ** argv) {
    char *endptr;
    (strtol(argv[1], &endptr, 10) == 1337) ? isawinner(argv[2]) : puts(":C fail\n");
}
