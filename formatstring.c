/* format string
 * gcc -m32 -o formatstring formatstring.c
 * */

#include <stdio.h>
#include <stdlib.h>

void main() {
    int i = 0;
    char buf[64];
    printf("format string playground, enter buf: ");
    fgets(buf, 64, stdin);
    printf("check out the buf you entered: ");
    printf(buf);
    if (i) {
        printf("congratz u win!\n");
        system("/bin/bash");
    }
}
