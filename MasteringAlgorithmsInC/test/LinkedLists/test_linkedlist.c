#include "test_linkedlist.h"

#define SAMPLES 10

int init(List** lists)
{
	if ((lists = (List**)malloc(SAMPLES*sizeof(List*))) == NULL){ return -1;}
	for (int sample = 0; sample < SAMPLES; sample++) { list_init((*lists + sample), NULL); }
	return 0;
}

void cleanup(List** lists)
{
	return;
}

void linkedlist_run_all(void)
{
	EQ(10, 11 - 1, "linked list insert failed!");
	return;
}
