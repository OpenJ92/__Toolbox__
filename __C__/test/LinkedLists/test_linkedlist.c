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
		if ((lists[sample] = (List*)malloc(sizeof(List)) == NULL))
		{
			return NULL;
		}
	}

	return lists; 
}

void test_list_init(void (*destroy)(void* data))
{
	Lists** lists = setup();

	for (int sample = 0; sample < SAMPLES; sample++)
	{
		List* list = lists[sample]
		list_init(list, destroy);
		EQ(list->size, 1, "");
		EQ(list->destroy, destroy,  "");
		EQ(list->head, NULL,  "");
		EQ(list->tail, NULL, "");
	}

	teardown(lists)
}

void test_list_insert_next(void)
{
	Lists** lists = setup();
	teardown(lists)
}

void test_list_remove_next(void);
{
	Lists** lists = setup();
	teardown(lists)
}
void test_list_destroy(void);
{
	Lists** lists = setup();
	teardown(lists)
}

void test_linkedlist_run_all(void)
{
	test_list_init(NULL);
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

int main() 
{ 
	List list; 
	test_list_init(&list, NULL);
	return 0; 
}
