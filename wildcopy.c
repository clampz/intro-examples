/* wild copy
 * gcc -m32 -fno-stack-protector -o wildcopy wildcopy.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define disable_buffering(_fd) setvbuf(_fd, NULL, _IONBF, 0)

struct message {
    char buf[24];
    int len;
    void (* result)();
};

void lose() {
    puts("loser\n");
}

void win() {
    system("/bin/bash");
}

void main() {
    struct message *msg;
    disable_buffering(stdout);
    msg = malloc(sizeof(struct message));
    msg->len = 24;
    msg->result = lose;
    while (msg->len >= 24) {
        printf("What is your length? ");
        scanf("%d", &msg->len);
        getc(stdin); // eat up newline
    }
    printf("OK, what is your buf? ");
    read(0, msg->buf, msg->len);
    msg->result();
    free(msg);
}
