#include "test_linkedlist.h"

#include <stdio.h>

#define SAMPLES 10

// I really want to pass an initialized List** and adjust its state
// and return an integer indicator as opposed to returning a List**
// like the examples in the text. I assume I have to pass a List***
// dereference it with the operations below.
List** init(List** lists, void (*destroy)(void* data))
{
	if ((lists = (List**)malloc(SAMPLES*sizeof(List*))) == NULL){ return NULL; }
	for (int sample = 0; sample < SAMPLES; sample++) 
	{ 
		lists[sample] = (List*)malloc(sizeof(List));
		list_init(lists[sample], destroy); 
		printf("%p\n", lists[sample]);
	}
	return lists;
}

int create_empty_list(List* list) 
{ 
	return 0; 
}

int create_singlton_list(List* list, const void* data)
{
	int retval;
	if ((retval = list_insert_next(list, NULL, data)) == -1){ return -1; }
	return 0;
}

int create_many_list(List* list, const void** data, int data_size)
{
	int retval = 0;
	for (int i = 0; i < data_size; i++)
	{
		if ((retval = list_insert_next(list, NULL, data[i])) == -1){ return -1 ; }
	}
	return 0;
}

void cleanup(List** lists)
{
	for (int i = 0; i < SAMPLES; i++)
	{
		list_destroy(lists[i]);
	}
	return;
}

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
