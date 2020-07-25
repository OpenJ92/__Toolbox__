#include "graph.h"

void graph_init
(
 	Graph* graph, 
	int (*match)(const void* key1, const void* key2),
	void (*destroy)(void* data)
)
{
	graph->vcount = 0; graph->ecount = 0;
	graph->match = match;
	graph->destroy = destroy;

	List* list;
	if ((list = (List*)malloc(sizeof(List))) == NULL) { return; }
	list_init(list, destroy);

	graph->adjlists = list;
	return;
}
