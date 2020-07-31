#ifndef events_h
#define events_h

#include "event.h"
#include "../../src/StacksQueues/Queue/queue.h"

int recieve_event(Queue* events, const Event* event);
int process_event(Queue* events, int (*dispatch)(Event* event));

#endif
