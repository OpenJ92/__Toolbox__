#ifndef SORT_H
#define SORT_H

int qksort(void* data, int size, int esize, int i, int k, int (*compare)(const void * key1, const void * key2))
int issort(void* data, int size, int esize, int (*compare)(const void * key1, const void * key2));

#endif
