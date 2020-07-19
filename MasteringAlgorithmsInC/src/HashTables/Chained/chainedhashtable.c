#include "chainedhashtable.h"

int chtbl_init(CHTbl* chtbl, int buckets, int (*h)(const void* key),
		int (*match)(const void* key1, const void* key2), 
		void (*destroy)(void* data))
{ 	
	chtbl->buckets = buckets;
	chtbl->size = 0;
	chtbl->h = h;
	chtbl->match = match;
	chtbl->destroy = destroy;
	chtbl->table = NULL;

	if ((chtbl->table = (List*)malloc(sizeof(List) * buckets)) != 0){ return -1; }

	for (int key = 0; key < buckets; key++)
	{ list_init(&chtbl->table[key], chtbl->destroy); }

	return 0;
}

int chtbl_insert(CHTbl* chtbl, const void* data)
{ 
	int retval; void* temp = (void*)data; int key = chtbl->h(data) % chtbl->buckets;
	if (chtbl_lookup(chtbl, &temp) == 0){ return 1; }
	if ((retval = list_insert_next(&chtbl->table[key], NULL, data)) == 0 )
	{ chtbl->size++; }
	return 0;
}

int chtbl_lookup(CHTbl* chtbl, void** data)
{ 
	int key = chtbl->h(*data) % chtbl->buckets; List* local = chtbl->table + key;
	for (ListElmt* member = local->head; member != NULL; member=list_next(member))
	{
		if ((chtbl->match(member->data, *data)) == 0)
		{ 
			*data = member->data;
			return 0; 
		}
	}
	return -1;
}

int chtbl_remove(CHTbl* chtbl, void** data)
{
	int key = chtbl->h((const void*)*data) % chtbl->buckets;
	List* local = chtbl->table + key; void** temp; ListElmt* prev = NULL;
	for (ListElmt* member = local->head; member != NULL; member=list_next(member))
	{
		if ((chtbl->match(member->data, *data)) == 0)
		{ 
			if (list_remove_next(local, prev, temp) == 0)
			{
				chtbl->size--; return 0;
			}
			else
			{
				return -1;
			}
		}
		prev = member;
	}
	return -1;
}

void chtbl_destroy(CHTbl* chtbl)
{ 
	if (chtbl->destroy == NULL){ return; } 

	int bucket;
	for (bucket = 0; bucket < chtbl->buckets; bucket++)
	{ 
		list_destroy(&(chtbl->table[bucket])); 
	}
	free(chtbl->table); memset(chtbl, 0, sizeof(CHTbl)); return;
}
