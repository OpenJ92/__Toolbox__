#include "cirularsinglylinkedlist.h"

void clist_init(CList* list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
}


void clist_destroy(CList* list)
{
	void* data;
	while (list->size > 0)
	{ if (list->destroy != NULL && clist_remove_next(list, NULL, (void**)&data)){ list->destroy(data); } }
	memset(list, 0, sizeof(CList)); return;
}

int clist_insert_next(CList* list, CListElmt* element, const void* data)
{
	CListElmt* new_element;
	if ((new_element = (CListElmt*)malloc(sizeof(CListElmt))) == NULL){ return -1; }
	new_element->data = (void*)data;

	if (clist_size(list) == 0)
	{
		new_element->next = new_element;
		list->head = new_element;
	}
	else
	{
		new_element->next = new_element;
		element = new_element;
	}
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
		if (old_element == clist_head(list)){ list->head = old_element->next; }
	}
	free(old_element); list->size--; return 0;
}
