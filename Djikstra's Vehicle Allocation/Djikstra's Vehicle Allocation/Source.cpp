#include <iostream>
#include "Graph.h"
#include <time.h>

void main()
{
	srand(time(NULL));
	int vertices = 11;
	Graph graph(vertices);
	graph.addEdge(0, 2, 3);
	graph.addEdge(0, 4, 5);
	graph.addEdge(0, 5, 1);
	graph.addEdge(0, 6, 5);
	graph.addEdge(0, 8, 5);
	graph.addEdge(2, 7, 4);
	graph.addEdge(3, 5, 2);
	graph.addEdge(5, 1, 6);
	graph.addEdge(1, 9, 2);
	graph.addEdge(1, 6, 10);
	graph.addEdge(4, 10, 7);
	graph.addEdge(8, 10, 2);
	graph.createRequests(10);
	while (graph.isQueueEmpty() != true)
	{
		Request request = graph.getRequest();
		graph.shortestPath(request.getVertex(), request.getRequestType());
	}
}