#include <stdio.h>

#include "src/LinkedLists/LinkedList/linkedlist.h"
#include "src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.h"

int main(int argc, char* argv[]) 
{ 
	List list; list_init(&list, NULL); 
	int i = 10; int* ptr1 = &i; list_insert_next(&list, NULL, (const void*) ptr1);
	int j = 11; int* ptr2 = &i; list_insert_next(&list, NULL, (const void*) ptr2);
	int k = 12; int* ptr3 = &i; list_insert_next(&list, NULL, (const void*) ptr3);
	int l = 13; int* ptr4 = &i; list_insert_next(&list, NULL, (const void*) ptr4);
	int m = 14; int* ptr5 = &i; list_insert_next(&list, NULL, (const void*) ptr5);
	printf("Hello there! How's it going? I'm having a lot of fun with this!\n");
	list_destroy(&list); // bugged! we don't iter the size of the list!
	return 0; 
}
