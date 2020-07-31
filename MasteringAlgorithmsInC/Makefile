# -*- Makefile -*-
libraries: StacksQueues LinkedLists HashTables

test:
	echo "Hello, world!"

StacksQueues: linkedlist.o stack.o queue.o
	ar -cvq libSQ.a linkedlist.o stack.o queue.o

LinkedLists: linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o
	ar -cvq libLL.a linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o

HashTables: linkedlist.o chainedhashtable.o openaddressedhashtable.o
	ar -cvq libHT.a linkedlist.o chainedhashtable.o openaddressedhashtable.o

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

obj:
	mv -v *.o build/

lib:
	mv -v *.a lib/
