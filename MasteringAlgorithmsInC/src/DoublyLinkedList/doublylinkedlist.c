#include "doublylinkedlist.h"

void dlist_init(DList* list, void (*destroy)(void* data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

void dlist_destroy(DList* list);
int dlist_insert_next(DList* list, DListElmt* element, const void* data)
{
	DListElmt* new_element;
	if (element == NULL && dlist_size(list) != 0){ return -1; }
	if ((new_element = (DListElmt*)malloc(sizeof(DListElmt)) == NULL)){ return -1; }

	new_element->data = (void*)data;

	if (dlist_size(list) == 0)
	{
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		new_element->next = element->next;
		new_element->prev = element;

		if (element->next == NULL) { list->tail = new_element; }
		else { element->next->prev = new_element; }
		element->next = new_element;
	}
	list->size++; return 0;
}

int dlist_insert_prev(DList* list, DListElmt* element, const void* data)
{
	DListElmt* new_element;
	if (element == NULL && dlist_size(list) != 0){ return -1; }
	if ((new_element = (DListElmt*)malloc(sizeof(DListElmt))) == NULL){ return -1; }

	new_element->data = (void*)data;

	if (dlist_size(list) == 0)
	{
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		new_element->next = element;
		new_element->prev = element->prev;
		
		if (element->prev == NULL) { list->head = new_element; }
		else { element->prev-next = new_element; }

		element->prev = new_element;
	}

	list->size++; return 0;
}
// int dlist_remove(DList* list, DListElmt* element, void** data);
