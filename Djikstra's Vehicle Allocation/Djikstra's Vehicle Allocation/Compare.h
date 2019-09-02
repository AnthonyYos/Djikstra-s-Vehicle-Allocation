#pragma once
#include "Node.h"

//Used for priority queue in graph.shortestPath(int,int);
class Compare
{
public:
	bool operator()(Node& a, Node& b)
	{
		return a.getWeight() > b.getWeight();
	}
};

