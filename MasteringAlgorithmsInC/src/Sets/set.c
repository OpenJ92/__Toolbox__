#include "set.h"

int set_insert(Set* set, const void* data);
int set_remove(Set* set, void** data);
int set_union(Set* setu, Set* set1, Set* set2);
int set_intersection(Set* seti, Set* set1, Set* set2);
int set_difference(Set* setd, Set* set1, Set* set2);
int set_is_member(Set* set, const void* data);
int set_is_subset(const Set* set1, const Set* set2);
int set_is_equal(const Set* set1, const Set* set2);

