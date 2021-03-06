#ifndef FRAMES_H
#define FRAMES_H

#include <stdlib.h>
#include <stdio.h>

#include "../../src/LinkedLists/LinkedList/linkedlist.h"

int alloc_frames(List* frames);
int free_frame(List* frames, int frame_number);

#endif
