#include <stdlib.h>
#include <string.h>

#include "sort.h"


int issort(void* data, int size, int esize, int (*compare)(const void * key1, const void * key2))
{
	char * a = (char *)data;
	void * key;

	if ((key = malloc(esize)) = NULL) { return -1; }

	for (int j = 1; j < size; j++)
	{
		memcpy(key, (a + esize * j), esize);
		int i = j - 1;

		while (i >= 0 && compare((a + esize*i), key) > 0)
		{
			memcpy((a + (i + 1) * esize), (a + i * esize), esize);
			i--;
		}
		
		memcpy((a + (i + 1) * esize), key, esize);
	}

	free(key);
	return 0;
}

// example usage:
// int compare_int(const void * key1, const void* key2)
// {
// 	return (*int)key1 > (*int)key2 ? 1 : 0;
// }
// 
// int[5] ints = {5,4,3,2,1};
// issort((void *)ints, 5, sizeof(int), compare_int);

