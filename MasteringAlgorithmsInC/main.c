#include <stdio.h>

#include "src/LinkedLists/LinkedList/linkedlist.h"
#include "src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.h"

int main(int argc, char* argv[]) 
{ 
	CList clist; clist_init(&clist, NULL); 
	int i = 10; int* ptr1 = &i; clist_insert_next(&clist, NULL, (const void*) ptr1);
	int j = 11; int* ptr2 = &i; clist_insert_next(&clist, NULL, (const void*) ptr2);
	int k = 12; int* ptr3 = &i; clist_insert_next(&clist, NULL, (const void*) ptr3);
	int l = 13; int* ptr4 = &i; clist_insert_next(&clist, NULL, (const void*) ptr4);
	int m = 14; int* ptr5 = &i; clist_insert_next(&clist, NULL, (const void*) ptr5);
	printf("Hello there! How's it going? I'm having a lot of fun with this!\n");
	clist_destroy(&clist); // bugged! we don't iter the size of the list!
	List list; list_init(&list, NULL); list_destroy(&list);
	return 0; 
}
