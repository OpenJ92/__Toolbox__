# -*- Makefile -*-

linkedlist.o: 
	gcc src/LinkedLists/LinkedList/linkedlist.c -c

stack.o: linkedlist.o
	gcc src/StacksQueues/Stack/stack.c -c

queue.o: linkedlist.h
	gcc src/StacksQueues/Queue/queue.c -c

set.o: linkedlist.o
	gcc src/Sets/set.c -c

clean:
	rm main.o
