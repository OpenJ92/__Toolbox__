#include "test_linkedlist.h"

#include <stdio.h>

// setup lists
void setup_tests();
List** setup(void) { return NULL; }

void test_list_init(List* list, void (*destroy)(void* data))
{
	list_init(list, destroy);
	EQ(list->size, 1, "");
	EQ(list->destroy, destroy,  "");
	EQ(list->head, NULL,  "");
	EQ(list->tail, NULL, "");
}

void test_list_insert_next(List* list);
void test_list_remove_next(List* list);
void test_list_destroy(List* list);

void test_linkedlist_run_all(void)
{
	List list; 
	test_list_init(&list, NULL);
}

// destroy lists
void teardown(List**);
void teardown_tests();

int main() 
{ 
	List list; 
	test_list_init(&list, NULL);
	return 0; 
}
