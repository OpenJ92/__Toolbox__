#include "doublylinkedlist.h"

void dlist_init(DList* list, void (*destroy)(void* data))
/*
 * */
{ list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

void dlist_destroy(DList* list)
/*
 * */
{ void* data;
	while (dlist_size(list) > 0)
	{ if ( dlist_remove(list, NULL, (void**)&data) == 0 && list->destroy != NULL ) { list->destroy(data); } }
	memset(list, 0, sizeof(DList)); return;
}

int dlist_insert_next(DList* list, DListElmt* element, const void* data)
/* The dlist_insert_next operation inserts an element into a doubly-linked list just
 * after the specified element. Inserting an element in a doublly-linked list is 
 * similar to inserting one in a singly-linked list. The primary difference is that
 * in addition to managing the next pointers, we must manage the prev pointers to 
 * keep the list linked properly in the reverse direction. 
 * */
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
		new_element->next = element->next;
		new_element->prev = element;

		if (element->next == NULL) { list->tail = new_element; }
		else { element->next->prev = new_element; }
		element->next = new_element;
	}
	list->size++; return 0;
}

int dlist_insert_prev(DList* list, DListElmt* element, const void* data)
/* see dlist_insert_next docs for description.
 * */
{ DListElmt* new_element;
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
		else { element->prev->next = new_element; }

		element->prev = new_element;
	}

	list->size++; return 0;
}
int dlist_remove(DList* list, DListElmt* element, void** data)
/* The dlist_remove operation removes a specified element from a DLL. The primary
 * difference from an SLL is that in addtion to managing the next pointers during
 * deletion, one must also consider the prev pointers to maintain order in the reverse
 * dirention. Another difference is that in a DLL, it is possible to remove the specified
 * element, rather than the one just after it because there is a pointer back to the 
 * previous element.
 * */
{ if (element == NULL || dlist_size(list) == 0){ return -1; }
	*data = element->data;

	if (element == list->head)
	{
		list->head = element->next;
		if (list->head == NULL) { list->tail = NULL; }
		else { element->next->prev = NULL; }
	}
	else
	{
		element->prev->next = element->next;
		if (element->next == NULL){ list->tail = element->prev; }
		else { element->prev->next = element->prev; }
	}
	free(element); list->size--; return 0;
}
