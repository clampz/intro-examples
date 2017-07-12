/* format string
 * gcc -m32 -o formatstring formatstring.c
 * */

#include <stdio.h>
#include <stdlib.h>

#define disable_buffering(_fd) setvbuf(_fd, NULL, _IONBF, 0)

void main() {
    int i = 0;
    char buf[64];
    unsigned int iptr = (unsigned int) &i; // bypass ASLR
    disable_buffering(stdout);
    printf("format string playground, enter buf: ");
    fgets(buf, 64, stdin);
    printf("check out the buf you entered: ");
    printf(buf);
    if (i) {
        printf("congratz u win!\n");
        system("/bin/bash");
    }
}
