# -*- Makefile -*-
test: libraries
	gcc libHT.a libSQ.a libLL.a libHQ.a libTR.a main.c -o run.o

libraries: StacksQueues LinkedLists HashTables Trees HeapsPriorityQueues Graph

StacksQueues: linkedlist.o stack.o queue.o
	ar -cvq libSQ.a linkedlist.o stack.o queue.o

LinkedLists: linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o
	ar -cvq libLL.a linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o

HashTables: linkedlist.o chainedhashtable.o openaddressedhashtable.o
	ar -cvq libHT.a linkedlist.o chainedhashtable.o openaddressedhashtable.o

Trees: binarytree.o bistree.o traverse.o
	ar -cvq libTR.a binarytree.o bistree.o traverse.o

HeapsPriorityQueues: heap.o # priorityqueue.o
	ar -cvq libHQ.a heap.o # priorityqueue.o

Graph: graph.o bfs.o
	ar -cvq libGR.a graph.o bfs.o

bfs.o: graph.o linkedlist.o
	gcc src/Graph/bfs.c -c

graph.o: linkedlist.o set.o
	gcc src/Graph/graph.c -c

# I'm not sure how to include this definition as the data structure 
# is completely defined thorugh "inheritance" from the heap.
# priorityqueue.o: heap.o
# 	gcc src/HeapsPriorityQueues/priorityqueue.c -c

heap.o:
	gcc src/HeapsPriorityQueues/heap.c -c

traverse.o: binarytree.o
	gcc src/Trees/BinaryTree/traverse.c -c

bistree.o: binarytree.o
	gcc src/Trees/BinarySearchTree/bistree.c -c

binarytree.o: 
	gcc src/Trees/BinaryTree/binarytree.c -c

openaddressedhashtable.o:
	gcc src/HashTables/OpenAddressed/openaddressedhashtable.c -c

chainedhashtable.o: linkedlist.o
	gcc src/HashTables/Chained/chainedhashtable.c -c

stack.o: linkedlist.o
	gcc src/StacksQueues/Stack/stack.c -c

queue.o: linkedlist.o
	gcc src/StacksQueues/Queue/queue.c -c

set.o: linkedlist.o
	gcc src/Sets/set.c -c

linkedlist.o:
	gcc src/LinkedLists/LinkedList/linkedlist.c -c

cirularsinglylinkedlist.o:
	gcc src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.c -c

doublylinkedlist.o:
	gcc src/LinkedLists/DoublyLinkedList/doublylinkedlist.c -c

clean:
	rm *.o; rm *.a
