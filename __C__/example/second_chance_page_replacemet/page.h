#ifndef PAGES_H
#define PAGES_H

#include <stdlib.h>

#include "../../src/LinkedLists/CircularSinglyLinkedList/cirularsinglylinkedlist.h"

typedef struct Page_
{
	int number;
	int reference;
} Page;

int replace_page(CListElmt** current);

#endif
