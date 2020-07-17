#ifndef CHTBL_H 
#define CHTBL_H

#include <stdlib.h>

#include "../LinkedLists/LinkedList/linkedlist.h"

typedef struct CHTbl_
{
	int buckets;
	int (*h)(const void* key);
	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);
	int size;
	List* table;
} CHTbl;

int chtbl_init(CHTbl* chtbl, int buckets, int (*h)(const void* key),
		int (*match)(const void* key1, const void* key2), 
		void (*destroy)(void* data));

void chtbl_destroy(CHTbl* chtbl);
int chtbl_insert(CHTbl* chtbl, const void* data);
int chtbl_remove(CHTbl* chtbl, void** data);
int chtbl_lookup(CHTbl* chtbl, void** data);

#define chtbl_size(chtbl) ((chtbl)->size)

#endif
