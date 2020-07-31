#include "test_linkedlist.h"

#include <stdio.h>

#define SAMPLES 3

// setup lists
void setup_tests();
List** setup(void) 
{ 
	List** lists; 
	if ((lists = (List**)malloc(SAMPLES*sizeof(List*))) == NULL)
	{ 
		return NULL; 
	}

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		if ((lists[sample] = (List*)malloc(sizeof(List))) == NULL)
		{
			return NULL;
		}
	}

	return lists; 
}

// destroy lists
void teardown(List** lists)
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		list_destroy(lists[sample]);
		free(lists[sample]);
	}
	free(lists); return;
}
void teardown_tests();


void initialize(List** lists, void (*destroy)(void* data))
{
	for (int sample = 0; sample < SAMPLES; sample++)
	{
		List* list = lists[sample];
		list_init(list, destroy);
	}
	return;
}

void populate(List* list, const void** data, int data_size)
{
	if (data == NULL) { return; }
	for (int element = data_size-1; element >= 0; element = element - 1)
	{
		list_insert_next(list, NULL, data[element]);
	}
}

void test_list_init(void (*destroy)(void* data))
{
	List** lists = setup();

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		List* list = lists[sample];
		list_init(list, destroy);
		EQ(list->size, 0, "");
		EQ(list->destroy, destroy,  "");
		EQ(list->head, NULL,  "");
		EQ(list->tail, NULL, "");
	}

	teardown(lists);
}

void test_list_insert_next(void)
{
	List** lists = setup();
	initialize(lists, NULL); 
	List* list = lists[0];

	int data = 1; int* ptr = &data;
	list_insert_next(list, NULL, (const void*)ptr);
	EQ(list->head->data, (void*)ptr, "");
	EQ(list->tail->data, (void*)ptr, "");
	EQ(list->size, 1, "");

	int data2 = 2; int* ptr2 = &data2;
	list_insert_next(list, list->head, (const void*)ptr2);
	EQ(list->head->next, list->tail, "");
	EQ(list->tail->next, NULL, "");
	EQ(list->size, 2, "");

	int data3 = 3; int* ptr3 = &data;
	list_insert_next(list, list->tail, (const void*)ptr3);
	EQ(list->head->next->next, list->tail, "");
	EQ(list->tail->next, NULL, "");
	EQ(list->size, 3, "");

	teardown(lists);
}

void test_list_remove_next(void)
{
	List** lists = setup();
	initialize(lists, NULL);

	void* container = NULL;
	int data[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	populate(lists[0], NULL, 0);
	populate(lists[1], (const void**)&data, 10);

	EQ(list_remove_next(lists[0], NULL, &container), -1, "");
	EQ(list_remove_next(lists[1], NULL, &container), 0, "");
	EQ(list_remove_next(lists[1], lists[1]->head, &container), 0, "");

	teardown(lists);
}

void test_list_destroy(void)
{
	List** lists = setup();
	initialize(lists, NULL);

	int data[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int data2[1] = {1};
	populate(lists[0], NULL, 0);
	populate(lists[1], (const void**)&data, 10);
	populate(lists[2], (const void**)&data2, 1);

	teardown(lists);
}

int main() 
{ 
	test_list_init(NULL);
	test_list_insert_next();
	test_list_remove_next();

	return 0; 
}
