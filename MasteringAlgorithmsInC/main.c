#include "src/LinkedLists/LinkedList/linkedlist.h"
#include "src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.h"

int main(int argc, char* argv[]) 
{ 
	CList clist; clist_init(&clist, NULL); clist_destroy(&clist);
	List list; list_init(&list, NULL); list_destroy(&list);
	return 0; 
}
