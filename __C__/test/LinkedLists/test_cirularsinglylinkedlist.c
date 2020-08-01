#include "test_cirularsinglylinkedlist.h"
#include <stdio.h>

#define SAMPLES 3

CList** setup(void) 
{ 
	CList** lists; 
	if ((lists = (CList**)malloc(SAMPLES*sizeof(CList*))) == NULL)
	{ 
		return NULL; 
	}

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		if ((lists[sample] = (CList*)malloc(sizeof(CList))) == NULL)
		{
			return NULL;
		}
	}

	return lists; 
}

void teardown(CList** lists)
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		clist_destroy(lists[sample]);
		free(lists[sample]);
	}
	free(lists); return;
}

void initialize(CList** lists, void (*destroy)(void* data))
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		CList* list = lists[sample];
		clist_init(list, destroy);
	}
	return;
}

void populate(CList* list, const void** data, int data_size)
{
	if (data == NULL) { return; }
	for (int element = data_size-1; element >= 0; element = element - 1)
	{
		clist_insert_next(list, NULL, data[element]);
	}
}

void test_clist_init(void (*destroy)(void *data))
{
	CList** lists = setup();

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		CList* list = lists[sample];
		clist_init(list, destroy);
		EQ(list->size, 0, "");
		EQ(list->destroy, destroy,  "");
		EQ(list->head, NULL,  "");
	}

	teardown(lists);
	printf("\ttest_clist_init: complete\n");
}

void test_clist_insert_next()
{
	CList** lists = setup();
	initialize(lists, NULL);
	CList* list = lists[0];
	int data[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int retvals[4]; 

	retvals[0] = clist_insert_next(list, NULL, (const void*)&data[0]);
	EQ(list->head->data, (void*)&data[0], "");
	EQ(list->head->next, list->head, "");
	EQ(list->size, 1, "");

	retvals[1] = clist_insert_next(list, list->head, (const void*)&data[1]);
	printf("\t%p : %p\n", list->head->next->data, (void*)&data[1]);
	//EQ(list->head->next->data, (void*)&data[1], "");
	EQ(list->head->next->next, list->head, "");
	EQ(list->size, 2, "");

	teardown(lists);
	printf("\ttest_clist_insert_next: complete\n");
}

int test_clist_remove_next(CList* list, CListElmt* element, void** data);
void test_clist_destroy(CList* list);


int main() 
{ 
	printf("TEST: Circular Linked Lists\n");
	test_clist_init(NULL);
	test_clist_insert_next();
	printf("\n");

	return 0; 
}
