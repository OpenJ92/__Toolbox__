#ifndef SET_H
#define SET_H

#include "../LinkedLists/LinkedList/linkedlist.h"

typedef List Set;

void set_init(
		Set* set, 
		int (*match)(const void* key1, const void* key2),
		void (*destroy)(void *data)
	     );
int set_insert(Set* set, const void* data);
int set_remove(Set* set, void** data);
int set_union(Set* setu, Set* set1, Set* set2);
int set_intersection(Set* seti, Set* set1, Set* set2);
int set_difference(Set* setd, Set* set1, Set* set2);
int set_is_member(Set* set, const void* data);
int set_is_subset(const Set* set1, const Set* set2);
int set_is_equal(const Set* set1, const Set* set2);

#define set_destroy list_destroy
#define set_size(set) ((set)->size)

#endif
