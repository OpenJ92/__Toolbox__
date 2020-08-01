#include "linkedlist.h"

#include <stdio.h>

void list_init(List* list, void (*destroy)(void* data))
{ 	
	list->size    = 0;
	list->destroy = destroy;
	list->head    = NULL;
	list->tail    = NULL;
}

int list_remove_next(List* list, ListElmt* element, void** data)
/* The list_remove_next operation removes from a linked list the element
 * just after the provided ListElmt element. As with inserting into the 
 * list in the following function list_insert_next, the call must consider
 * two cases: removal of an element from the head and removing an element 
 * from elsewhere.
 *
 * Generally, to remove an element from a linked list, we set the next pointer
 * of the element preceding the one being removed to the element which follows.
 * When removing an element from the head of a list, there is no elememt which 
 * preceeds the element being removed. In addition, whenever we remove the element
 * at the tail of the list, we must update the tail member of the list data 
 * structure to point to the new tail or to null if removing the element has 
 * caused the list to become empty.
 * */
{
	ListElmt* old_element;

	if (list_size(list) == 0) { return -1; }
	if (element == NULL)
	{
		*data = list->head->data;
		old_element = list->head;
		list->head = old_element->next;

		if (list_size(list) == 1) { list->tail = NULL; }
	}
	else
	{
		if (element->next == NULL) { return -1; }

		*data = element->next->data;
		old_element = element->next;
		element->next = old_element->next;

		if (element->next == NULL) { list->tail = element; }
	}

	free(old_element); list->size--; return 0;
}

int list_insert_next(List* list, ListElmt* element, const void* data)
/* The list_insert_next operation inserts an element into a linked list 
 * just after the provided element. The call sets the new element to 
 * point to the data passed by the caller.
 *
 * Generally, to insert an element into a linked list, we set the next
 * pointer of the new element to point to the element it is going to 
 * preceed, and we set the next pointer of the element provided to the 
 * caller to the new element. When inserting an element at the head of
 * the list, there is no element that will preceed the new element. In
 * this case, we set the next pointer of the new element to the current
 * head of the list, then reset the head of the list to point to the 
 * new elememt. Additionally, when we insert an element at the tail of
 * the list, we must update the tail member of the list structure to
 * point to the new tail.
 *
 * */
{
	ListElmt* new_element;
	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL){ return -1; }
	new_element->data = (void*)data;

	if (element == NULL)
	{
		if (list_size(list) == 0){ list->tail = new_element; }
		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		if (element->next == NULL) { list->tail = new_element; }
		new_element->next = element->next;
		element->next = new_element;
	}

	list->size++; return 0;
}

void list_destroy(List* list)
/* The list_destroy operation destroys a linked list. Primarily this means
 * removing all elements from the list. The function passed as destroy to
 * the list_init operation is called on the extracted data provided that 
 * destroy was not set to null.
 *
 * */
{
	void* data;

	while (list_size(list) > 0)
	{
		if (list_remove_next(list, NULL, (void**)&data) == 0 && list->destroy != NULL) 
		{ list->destroy(data); }
	}

	memset(list, 0, sizeof(List)); return;
}
