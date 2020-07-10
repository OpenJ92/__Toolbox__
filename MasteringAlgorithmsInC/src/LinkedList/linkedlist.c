#include "linkedlist.h"

int main(int argc, char* argv[]) 
{ 
	return 0; 
}

void list_init(List* list, void (*destroy)(void* data))
{
	list->size    = 0;
	list->destroy = destroy;
	list->head    = NULL;
	list->tail    = NULL;
}

int list_remove_next(List* list, ListElmt* element, void** data)
{
}

int list_insert_next(List* list, ListElmt* element, const void* data)
{
}

void list_destroy(List* list)
{
}


