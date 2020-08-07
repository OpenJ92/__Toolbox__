#include "test_doublylinkedlist.h"

#include <stdio.h>

#define SAMPLES 3

DList** setup(void) 
{
	DList** lists;
	if ((lists = (DList**)malloc(SAMPLES*sizeof(DList*))) == NULL)
	{
		return NULL;
	}

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		if ((lists[sample] = (DList*)malloc(sizeof(DList))) == NULL)
		{
			return NULL;
		}
	}

	return lists;
}
void teardown(DList** lists)
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		dlist_destroy(lists[sample]);
		free(lists[sample]);
	}
	free(lists); return;
}
void initialize(DList** lists, void (*destroy)(void* data))
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		dlist_init(lists[sample], destroy);
	}
	return;
}

void populate(DList* list, int data[], int data_size)
{
	if (data == NULL){ return; }
	for (int element = data_size-1; element >= 0; element--)
	{
		dlist_insert_next(list, list->head, (const void*)&data[element]);
	}
	return;
}

int main()
{
	printf("TEST: Doubly Linked Lists\n");
	return 0;
}
