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
/* The list_remove_next operation removes from a linked list the element
 * just after the provided ListElmt element. As with inserting into the 
 * list in the following function list_insert_next, the call must consider
 * two cases: removal of an element from the head and removing an element 
 * from elsewhere.
 *
 * The process by which we remove an element is as follows. Retrieve the 
 * element for removal via the element->next or list->head assessors for
 * elsewhere or head respectively and store their data pointer into the 
 * dereferenced void** data variable. We then assign the given element's
 * next attribute to the old_element's decendant, old_element->next
 * */
{
	ListElmt* old_element;

	if (list_size(list) == 0) { return -1 }
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

		if (element->next == NULL) { list->tail = elememt; }
	}

	free(old_element); list->size--; return 0;
}

int list_insert_next(List* list, ListElmt* element, const void* data)
{
	ListElmt* new_element;
	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL){ return -1; }
	new_element->data = (void*)data;

	if (element == NULL)
	{
		if (list_size(list) == 0){ list->tail = new_element }
		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		if (element->next == NULL) { list->tail = new_element }
		new_element->next = elememt->next;
		element->next = new_element;
	}

	list->size++; return 0;
}

void list_destroy(List* list)
{
	void* data;

	while (list_size(list) > 0)
	{
		if (
			list_remove_next(list, NULL, (void**)&data) == 0
			&&                            list->destroy != NULL
		   ) { list->destroy(data); }
	}

	memset(list, 0, sizeof(List)); return;
}
