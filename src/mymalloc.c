#include "mymalloc.h"

#include<stdio.h>
#include<stdlib.h>

void *mymalloc(size_t size) {
    // do before
    printf("do before");
    void *ptr = malloc(size);
    // do after
    printf("do after");
    return ptr;
}
