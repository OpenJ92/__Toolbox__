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
	for (int index = 0; index < ohtbl->positions; index++)
	{
		int position =
		(ohtbl->h1(data) + (index + ohtbl->h2(data))) % ohtbl->positions;

		if (ohtbl->table[position] == NULL){ return -1; }
		else if (ohtbl->match(*data, ohtbl->table[position]))
		{
			*data = ohtbl->table[position]; return 0;
		}
	}
	return -1;
}

int ohtbl_insert(OHTbl* ohtbl, const void* data)
{
	if (ohtbl->size == ohtbl->positions){ return -1; }
	if (ohtbl_lookup(ohtbl, (void**)&data) == 0){ return -1; }

	for (int index = 0; index < ohtbl->positions; index++)
	{
		int position = 
		(ohtbl->h1(data) + (index + ohtbl->h2(data))) % ohtbl->positions;

		if (ohtbl->table[position] == NULL
			|| ohtbl->table[position] == ohtbl->vacated)
		{
			ohtbl->table[position] = (void*)data;
			ohtbl->size++; return 0;
		}
	}
	return -1;
}

int ohtbl_remove(OHTbl* ohtbl, void** data)
{
	for (int index = 0; index < ohtbl->positions; index++)
	{
		if (ohtbl->table[index] == NULL){ return -1; }
		else if (ohtbl->table[index] == ohtbl->vacated){ return -1; }
		else if (ohtbl->match(&data, ohtbl->table[index]))
		{
			*data = ohtbl->table[index];
			ohtbl->table[index] = ohtbl->vacated;
			ohtbl->size--; return 0;
		}
	}
	return -1;
}

void ohtbl_destroy(OHTbl* ohtbl)
{
	if (ohtbl->destroy != NULL)
	{
		for (int index = 0; index < ohtbl->positions; index++)
		{
			if (ohtbl->table[index] != NULL 
				&& ohtbl->table[index] != ohtbl->vacated)
			{
				ohtbl->destroy(ohtbl->table[index]);
			}
		}
	}
	free(ohtbl->table); memset(ohtbl, 0, sizeof(OHTbl)); return;
}
