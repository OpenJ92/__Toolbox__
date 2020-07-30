#ifndef TEST_LL_H
#define TEST_LL_H

#include "../assertions.h"
#include "../../src/LinkedLists/LinkedList/linkedlist.h"

List** init(List** lists);
void cleanup(List** lists);
void linkedlist_run_all(void);

#endif
