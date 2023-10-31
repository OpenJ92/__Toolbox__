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
