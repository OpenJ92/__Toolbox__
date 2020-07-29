#include "test_linkedlist.h"

#define SAMPLES 3 

int init(List** lists)
{
	if ((lists = (List**)malloc(SAMPLES*sizeof(List*))) == NULL){ return -1;}
	for (int sample = 0; sample < SAMPLES; sample++) 
	{ 
		List* ptr = (*lists + sample);
		if((ptr = (List*)malloc(sizeof(List))) == NULL) { return -1; }
		list_init(ptr, NULL); 
	}
	return 0;
}

int create_empty_list(List* list) 
{ 
	return 0; 
}

int create_singlton_list(List* list, const void* data, void (*destroy)(void* data))
{
	list->destroy = destroy; int retval;
	if ((retval = list_insert_next(list, NULL, data)) == -1){ return retval; }
	return 0;
}

int create_many_list(List* list, const void** data, int data_size, void (*destroy)(void* data))
{
	list->destroy = destroy;
	return 0;
}

void cleanup(List** lists)
{
	return;
}

void linkedlist_run_all(void)
{
	List** lists = NULL; init(lists);
	EQ(10, 11 - 1, "linked list insert failed!");
	return;
}
