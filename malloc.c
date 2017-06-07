/* malloc example
 * gcc -m32 malloc.c -o malloc
 * */

#include <stdio.h>
#include <stdlib.h>

#define SZ1 20
#define SZ2 15

void main() {
    unsigned int *ptr;
    printf("mallocing a chunk\n");
    ptr = malloc(SZ1);
    printf("malloced chunk at: 0x%08x\n", (unsigned int)ptr);
    printf("freeing chunk\n");
    free(ptr);
    printf("mallocing chunk again\n");
    ptr = malloc(SZ2);
    printf("malloced chunk at: 0x%08x\n", (unsigned int)ptr);
    free(ptr);
}
