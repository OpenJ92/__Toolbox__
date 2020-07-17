#include "set.h"

void set_init(
	             Set* set, 
	             int (*match)(const void* key1, const void* key2),
	             void (*destroy)(void *data)
	     )
{ list_init(set, destroy); set->match = match; return; }

int set_is_member(Set* set, const void* data)
{ ListElmt* member;

	for (member = set->head; member != NULL; member = member->next)
	{
		if (set->match(data, member->data)) { return 1; }
	}
	return 0;
}

int set_insert(Set* set, const void* data)
{ if (set_is_member(set, data)){ return 1; }
	return list_insert_next(set, set->tail, data);
}

int set_remove(Set* set, void** data)
{ ListElmt* member; ListElmt* prev;
	prev = NULL;

	for (member = set->head; member != NULL; member = member->next)
	{
		if (set->match(*data, member->data)){ break; }
		prev = member;
	}
	if (member == NULL){ return -1; }
	return list_remove_next(set, prev, data);
}

int set_union(Set* setu, Set* set1, Set* set2)
{ ListElmt* member; void* data;
	set_init(setu, set1->match, set1->destroy);

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (list_insert_next(setu, setu->tail, (void*)member->data) != 0)
		{
			set_destroy(setu);
			return -1;
		}
	}

	for (member = set2->head; member != NULL; member = member->next)
	{
		if (set_is_member(setu, member->data)) { continue; }
		else if (list_insert_next(setu, setu->tail, (void*)member->data) != 0)
		{
			set_destroy(setu);
			return -1;
		}
	}

	return 0;
}

int set_intersection(Set* seti, Set* set1, Set* set2)
{ ListElmt* member; void* data;
	set_init(seti, set1->match, set1->destroy);

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (set_is_member(set2, member->data))
		{
			if (list_insert_next(seti, seti->tail, (void*)member->data) != 0)
			{
				set_destroy(seti);
				return -1;
			}
		}
	}

	return 0;
}
int set_difference(Set* setd, Set* set1, Set* set2)
{ ListElmt* member; void* data;
	set_init(setd, set1->match, set1->destroy);

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (!set_is_member(set2, member->data))
		{
			if (list_insert_next(setd, setd->tail, (void*)member->data) != 0)
			{
				set_destroy(setd);
				return -1;
			}
		}
	}

	return 0;
}

int set_is_subset(const Set* set1, const Set* set2)
{ if (set1->size != set2->size) { return 0; }

	ListElmt* member;
	for (member = set1->head; member != NULL; member = member->next)
	{
		if (!set_is_member((Set*)set2, member->data)) { return 0; }
		else { continue; }
	}
	return 1;
}

int set_is_equal(const Set* set1, const Set* set2)
{ return set_is_subset(set1, set2) && set_is_subset(set2, set1);
}
