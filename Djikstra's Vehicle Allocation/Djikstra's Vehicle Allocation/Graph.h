#pragma once
#include <vector>
#include <list>
#include <queue>
#include "Edge.h"
#include "Request.h"
#include "Vehicle.h"
#include "Node.h"
using std::vector;
using std::list;
using std::queue;
using std::priority_queue;
class Graph
{
public:
	Graph();
	Graph(int v);
	void addEdge(int s, int d, int w);
	void createRequests(int n);
	Request getRequest();
	bool isQueueEmpty();
	bool hasIt(int s, int v);
	void popQueue();
	void shortestPath(int source, int type);
	~Graph();
private:
	int vertices;
	vector<vector<Edge>> adjList;
	queue<Request> requests;
	vector<vector<Vehicle>> vehicles;
};


