#include "openaddressedhashtable.h"

static char vacated;

int ohtbl_init(OHTbl* ohtbl, int positions, int (*h1)(const void* key), 
		int (*h2)(const void* key), int (*match)(const void* key1,
			const void* key2), void (*destroy)(void* data))
{
	ohtbl->positions = positions;
	ohtbl->vacated = &vacated;

	ohtbl->h1 = h1;
	ohtbl->h2 = h2;
	ohtbl->match = match;
	ohtbl->destroy = destroy;

	ohtbl->size = 0;
	ohtbl->table = NULL;

	if ((ohtbl->table = (void**)malloc(sizeof(void*) * positions)) == NULL)
	{ return -1; }

	for (int i = 0; i < positions; i++) { ohtbl->table[i] = NULL; }

	return 0;
}

int ohtbl_lookup(OHTbl* ohtbl, void** data)
{
	if (ohtbl->size == 0){ return -1; }
	int hash1 = ohtbl->h1(*data); int hash2 = ohtbl->h2(*data);
	int index = 0; int double_hash = (hash1 + index*hash2) % chtbl->positions;

	while (!ohtbl->match(chtbl->table[double_hash], *data))
	{
		if (chtbl->table[double_hash] == NULL) { return -1 }
		index++; double_hash = (hash1 + index*hash2) % chtbl->positions;
	}
	*data = chtbl->table[double_hash];
}

