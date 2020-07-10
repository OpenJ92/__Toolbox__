#include "linkedlist.h"

int main(int argc, char* argv[]) { return 0; }


void list_init(List* list, void (*destroy)(void* data));
void list_destroy(List* list);
int list_insert_next(List* list, ListElem* element, const void* data);
int list_remove_next(List* list, ListElem* element, void** data);
