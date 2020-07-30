#include "test_linkedlist.h"

#include <stdio.h>

#define SAMPLES 3 

int init(List** lists)
{
	if ((lists = (List**)malloc(SAMPLES*sizeof(List*))) == NULL){ return -1;}
	for (int sample = 0; sample < SAMPLES; sample++) 
	{ 
		lists[sample] = (List*)malloc(sizeof(List));
		list_init(lists[sample], NULL); 
		printf("%p\n", lists[sample]);
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
	if ((retval = list_insert_next(list, NULL, data)) == -1){ return -1; }
	return 0;
}

int create_many_list(List* list, const void** data, int data_size, void (*destroy)(void* data))
{
	list->destroy = destroy; int retval;
	for (int i = 0; i < data_size; i++)
	{
		if ((retval = list_insert_next(list, NULL, (*data + i))) == -1){ return -1 ; }
	}
	return 0;
}

void cleanup(List** lists)
{
	return;
}

void linkedlist_run_all(void)
{
	List** lists = NULL; init(lists);
	int data[10] = {0,1,2,3,4,5,6,7,8,9};
	return;
}
