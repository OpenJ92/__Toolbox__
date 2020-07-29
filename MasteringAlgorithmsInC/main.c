#include "test/LinkedLists/test_linkedlist.h"

#include <stdio.h>

int test_data_structures(void);

void __destroy__(void* data){ return; }
int __match__(const void* key1, const void* key2){ return 0;}

int main(int argc, char* argv[])
{
	int retval;
	if ((retval = test_data_structures()) == 0) { printf("All tests passed!"); };
	return 0;
}

int test_data_structures(void) 
{ 
	linkedlist_run_all();
	return 0; 
}
