#include <stdlib.h>
#include <string.h>

#include "mgsort.h"

static int merge
(
 	void* data,
	int esize,
	int i,
	int j,
	int k,
	int (*compare)(const void* key1, const void* key2)
)
{
	char *a = data; char *m;
	int ipos, jpos, mpos;

	// Initialize the cournters used in merging.
	ipos = i; jpos = j + 1; mpos = 0;

	// allocate storage for the merged elements
	if ((m = (char*)malloc(esize * ((k - i) + 1))) == NULL)
	{
		return -1;
	}

	// Continue while either division contains elements to merge.
	while (ipos <= j || jpos <= k)
	{
		break;
	}

	return 0;
}
