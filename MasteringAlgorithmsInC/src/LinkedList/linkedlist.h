#ifndef LIST_H
#define LIST_H

typedef struct ListElem_
{
	void* 			data;
	struct ListElem_* 	next;
} ListElem;

typedef struct List_
{
	int size;

	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	ListElem* head;
	ListElem* tail;
} List;

// Interface
void list_init(List* list, void (*destroy)(void* data))
void list_destroy(List* list);
int insert_next(List* list, ListElem* element, const void* data);
int remove_next(List* list, ListElem* element, void** data)

#endif
