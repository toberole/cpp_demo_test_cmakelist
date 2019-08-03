#ifndef DEMO_TEST_MYMALLOC_H
#define DEMO_TEST_MYMALLOC_H

#include <stddef.h>

//#define malloc(size) mymalloc(size)

void *mymalloc(size_t size);

#endif //DEMO_TEST_MYMALLOC_H
