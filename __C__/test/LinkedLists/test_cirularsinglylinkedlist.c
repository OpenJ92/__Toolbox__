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

void populate(CList* list, int data[], int data_size)
{
	if (data == NULL) { return; }
	for (int element = data_size-1; element >= 0; element = element - 1)
	{
		clist_insert_next(list, list->head, (const void*)&data[element]);
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
	printf("\ttest_clist_init:\tcomplete\n");
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
	EQ(list->head->next->data, (void*)&data[1], "");
	EQ(list->head->next->next, list->head, "");
	EQ(list->size, 2, "");

	teardown(lists);
	printf("\ttest_clist_insert_next:\tcomplete\n");
}

void test_clist_remove_next()
{
	CList** lists = setup();
	initialize(lists, NULL);

	void* container = NULL;
	int data[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int data2[1] = {1};

	populate(lists[1], data, 10);
	populate(lists[2], data2, 1);

	EQ(clist_remove_next(lists[0], lists[0]->head, &container), -1, "");
	EQ(clist_remove_next(lists[1], lists[1]->head, &container), 0, "");
	EQ(clist_remove_next(lists[1], lists[1]->head, &container), 0, "");

	teardown(lists);
	printf("\ttest_clist_remove_next:\tcomplete\n");
}
void test_clist_destroy()
{
	CList** lists = setup();
	initialize(lists, NULL);

	void* container = NULL;
	int data[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int data2[1] = {1};

	populate(lists[1], data, 10);
	populate(lists[2], data2, 1);

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		clist_destroy(lists[sample]);	

		EQ(lists[sample]->size, 0, "");
		EQ(lists[sample]->head, NULL, "");
	}

	teardown(lists);
	printf("\ttest_clist_remove_next:\tcomplete\n");
}


int main() 
{ 
	printf("TEST: Circular Linked Lists\n");
	test_clist_init(NULL);
	test_clist_insert_next();
	test_clist_remove_next();
	test_clist_destroy();
	printf("\n");

	return 0; 
}
