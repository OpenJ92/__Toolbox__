# -*- Makefile -*-
linkedlists: main.o linkedlist.o stack.o queue.o
	gcc main.o linkedlist.o stack.o queue.o -o LL

main.o:
	gcc main.c -c

linkedlist.o:
	gcc src/LinkedLists/LinkedList/linkedlist.c -c

stack.o: linkedlist.o
	gcc src/StacksQueues/Stack/stack.c -c

queue.o: linkedlist.o
	gcc src/StacksQueues/Queue/queue.c -c

set.o: linkedlist.o
	gcc src/Sets/set.c -c

clean:
	rm *.o
