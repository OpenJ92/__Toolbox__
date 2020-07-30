# -*- Makefile -*-
all: StacksQueues LinkedLists HashTables

StacksQueues: main.o linkedlist.o stack.o queue.o
	ar -cvq libSQ.a linkedlist.o stack.o queue.o

LinkedLists: main.o linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o
	ar -cvq libLL.a linkedlist.o cirularsinglylinkedlist.o doublylinkedlist.o set.o

HashTables: main.o linkedlist.o chainedhashtable.o openaddressedhashtable.o
	ar -cvq libHT.a linkedlist.o chainedhashtable.o openaddressedhashtable.o

main.o:
	gcc main.c -c

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
