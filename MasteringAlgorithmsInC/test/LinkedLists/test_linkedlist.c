#include "test_linkedlist.h"

#include <stdio.h>

#define SAMPLES 10


// I really want to pass an initialized List** and adjust its state
// and return an integer indicator as opposed to returning a List**
// like the examples in the text. I assume I have to pass a List***
// dereference it with the operations below.

// setup lists
void setup_tests();
List** setup();

void test_list_init(List* list, void (*destroy)(void* data))
{
	list_init(list, destroy);
	EQ(list->size, 1, "");
	EQ(list->destroy, destroy,  "");
	EQ(list->head, NULL,  "");
	EQ(list->tail, NULL, "");
}

void test_list_destroy(List* list);
void test_list_insert_next(List* list);
void test_list_remove_next(List* list);

void linkedlist_run_all(void)
{
	List** lists = NULL; lists = init(lists, NULL);

	int data_one[10] = {0,1,2,3,4,5,6,7,8,9};
	char data_two[3] = {'a', 'b', 'c'};
	char data_thr = 'z';

	create_many_list(lists[0], (const void**)&data_one, 10);
	create_many_list(lists[1], (const void**)&data_two, 3);
	create_singlton_list(lists[2], (const void*)&data_thr);

	cleanup(lists);
	return;
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
