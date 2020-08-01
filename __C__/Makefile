# -*- Makefile -*-
test: libraries
	gcc libHT.a libSQ.a libLL.a libHQ.a libTR.a main.c -o run.o

## TESTS ##
TESTALL: TESTLL TESTCLL
	./TESTCLL
	./TESTLL

TESTLL: test_linkedlist.o
	gcc -g -o TESTLL linkedlist.o test_linkedlist.o 

TESTCLL: test_cirularsinglylinkedlist.o
	gcc -g -o TESTCLL cirularsinglylinkedlist.o test_cirularsinglylinkedlist.o

## LIBRARIES ##
libraries: StacksQueues LinkedLists HashTables Trees HeapsPriorityQueues Graph

LinkedLists: linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o
	ar -cvq libLL.a linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o

StacksQueues: linkedlist.o stack.o queue.o
	ar -cvq libSQ.a linkedlist.o stack.o queue.o


HashTables: linkedlist.o chainedhashtable.o openaddressedhashtable.o
	ar -cvq libHT.a linkedlist.o chainedhashtable.o openaddressedhashtable.o

Trees: binarytree.o bistree.o traverse.o
	ar -cvq libTR.a binarytree.o bistree.o traverse.o

HeapsPriorityQueues: heap.o # priorityqueue.o
	ar -cvq libHQ.a heap.o # priorityqueue.o

Graph: graph.o bfs.o
	ar -cvq libGR.a graph.o bfs.o

## IMPLEMENTATION LEAVES ##
bfs.o: graph.o linkedlist.o
	gcc src/Graph/bfs.c -c

graph.o: linkedlist.o set.o
	gcc src/Graph/graph.c -c

traverse.o: binarytree.o
	gcc src/Trees/BinaryTree/traverse.c -c

bistree.o: binarytree.o
	gcc src/Trees/BinarySearchTree/bistree.c -c

chainedhashtable.o: linkedlist.o
	gcc src/HashTables/Chained/chainedhashtable.c -c

stack.o: linkedlist.o
	gcc src/StacksQueues/Stack/stack.c -c

queue.o: linkedlist.o
	gcc src/StacksQueues/Queue/queue.c -c

set.o: linkedlist.o
	gcc src/Sets/set.c -c

# I'm not sure how to include this definition as the data structure 
# is completely defined thorugh "inheritance" from the heap.
# priorityqueue.o: heap.o
# 	gcc src/HeapsPriorityQueues/priorityqueue.c -c

heap.o:
	gcc src/HeapsPriorityQueues/heap.c -c

binarytree.o: 
	gcc src/Trees/BinaryTree/binarytree.c -c

openaddressedhashtable.o:
	gcc src/HashTables/OpenAddressed/openaddressedhashtable.c -c

linkedlist.o:
	gcc src/LinkedLists/LinkedList/linkedlist.c -c

cirularsinglylinkedlist.o:
	gcc src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.c -c

doublylinkedlist.o:
	gcc src/LinkedLists/DoublyLinkedList/doublylinkedlist.c -c

## TEST LEAVES ##

test_linkedlist.o: linkedlist.o
	gcc test/LinkedLists/test_linkedlist.c -c

test_cirularsinglylinkedlist.o: cirularsinglylinkedlist.o
	gcc test/LinkedLists/test_cirularsinglylinkedlist.c -c

## UTILITY ##
clean:
	rm *.o; rm *.a
