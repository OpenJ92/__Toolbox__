#include "src/LinkedLists/LinkedList/linkedlist.h"
#include "src/LinkedLists/DoublyLinkedList/doublylinkedlist.h"
#include "src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.h"
#include "src/StacksQueues/Stack/stack.h"
#include "src/StacksQueues/Queue/queue.h"
#include "src/Sets/set.h"
#include "src/HashTables/Chained/chainedhashtable.h"
#include "src/HashTables/OpenAddressed/openaddressedhashtable.h"
#include "src/Trees/BinaryTree/binarytree.h"
#include "src/Graph/graph.h"

#include <stdio.h>

void __destroy__(void* data){ return; }
int __match__(const void* key1, const void* key2){ return 0;}

int main(int argc, char* argv[])
{

	List* list = (List*)malloc(sizeof(List)); 
	list_init(list, NULL);
	list_destroy(list);
	return 0;
}
