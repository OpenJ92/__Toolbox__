#include <stdio.h>
#include "cirularsinglylinkedlist.h"

void clist_init(CList* list, void (*destroy)(void *data))
{ 	
	// initialize list
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
}


void clist_destroy(CList* list)
{ 	
	void* data;
	// Provided there are contents in the list
	while (list->size > 0)
	{ 
		// and we've successfully removed that which follows
		// from the head
		if (clist_remove_next(list, list->head, (void**)&data))
		{ 

			// and we've specified a routine to destroy the 
			// encapsulated data
			if (list->destroy != NULL)
			{ 
				list->destroy(data); 
			}
		} 
	}
	// we've successfully destroy the list.
	memset(list, 0, sizeof(CList)); return;
}

int clist_insert_next(CList* list, CListElmt* element, const void* data)
{ 
	CListElmt* new_element;

	// Conditioned on successfully allocating memory 
	// for the new node
	if ((new_element = (CListElmt*)malloc(sizeof(CListElmt))) == NULL)
	{ 
		return -1; 
	}

	// and passed the ambiguous contents of data into
	// this nodes data capsule
	new_element->data = (void*)data;


	// if the list is empty
	if (clist_size(list) == 0)
	{
		// assign next to self
		new_element->next = new_element;
		// indicate to list object that this
		// is the head.
		list->head = new_element;
	}
	else
	// otherwise
	{
		// assign self next to what follow element
		new_element->next = element->next;
		// assign what follows element to be self
		element->next = new_element;
	}
	// update size and indicate sucess to caller
	list->size++; return 0;
}

int clist_remove_next(CList* list, CListElmt* element, void** data)
{ 	
	CListElmt* old_element;
	if (clist_size(list) == 0){ return -1; }

	*data = element->next->data;
	if (element->next == element)
	{
		old_element = element;
		list->head = NULL;
	}
	else
	{
		old_element = element->next;
		element->next = old_element->next;
		if (old_element == clist_head(list))
		{ 
			list->head = old_element->next; 
		}
	}
	free(old_element); list->size--; return 0;
}

int main(){ return 0; }
