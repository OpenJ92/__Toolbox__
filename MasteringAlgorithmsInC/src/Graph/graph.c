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
	list_init(&graph->adjlists, NULL);
	return;
}

void graph_destroy(Graph* graph)
{
	AdjList* adjlist;

	while (list_size(&graph->adjlists) > 0)
	{
		if (list_remove_next(&graph->adjlists, NULL, (void**)&adjlist) == 0)
		{
			set_destroy(&adjlist->adjacent);

			if (graph->destroy != NULL)
			{
				graph->destroy(&adjlist->adjacent);
			}
			free(adjlist);
		}
	}
	list_destroy(&graph->adjlists);
	memset(graph, 0, sizeof(Graph));
	return;
}

int graph_insert_vertex(Graph* graph, const void* data)
{
	ListElmt* element;
	AdjList* adjlist;
	int retval;

	for (element = list_head(graph->adjlists); element != NULL; element = list_next(element))
	{
		if (graph->match(data, ((AdjList*)list_data(element))->vertex))
		{
			return 1;
		}

		if ((adjlist = (AdjList*)malloc(sizeof(AdjList))) == NULL){ return -1; }

		adjlist->vertex = (void*)data;
		set_init(&adjlist->adjacent, graph_match, NULL);

		if ((retval = list_insert_next(&graph->adjlists, list_tail(&graph->adjlists), adjlist)) != 0)
		{
			return retval;
		}

		graph->vcount++; return 0;
	}
}

int graph_insert_edge(Graph* graph, const void* data1, const void* data2)
{
	ListElmt* element;
	int retval;

	for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
	{
		if (graph->match(data2, ((AdjList*)list_data(element))->vertex))
		{
			break;
		}

	}

	if (element == NULL){ return -1; }

	for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
	{
		if (graph->match(data1, ((AdjList*)list_data(element))->vertex))
		{
			break;
		}
	}

	if (element == NULL){ return -1; }

	if ((retval = set_insert(&(AdjList*)list_data(element)->adjacent, data2)) != 0)
	{
		return retval;
	}

	graph->ecount++; return 0;
}
