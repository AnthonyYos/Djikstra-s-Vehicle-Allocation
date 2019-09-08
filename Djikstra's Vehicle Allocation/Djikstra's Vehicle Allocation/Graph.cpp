#include "Graph.h"
#include <iostream>
#include "compare.h"


Graph::Graph()
{
}

Graph::Graph(int v)
{
	vertices = v;
	adjList.resize(v);
}

Graph::~Graph()
{
}
//Assumed undirected graph; for every edge pushed in adjlist[s] to d, there is an exact edge in adjlist[d] to s
void Graph::addEdge(int s, int d, int w)

{
	if ((s >= 0 && s < vertices) && (d >= 0 && d < vertices) && s != d && w > 0)
	{

		adjList[s].push_back(Edge(s, d, w));
		adjList[d].push_back(Edge(d, s, w));
	}
	else
		std::cout << "Selected an invalid value for at least one of the following source/destination/weight, edge was not added";
}

//Generates a n number of requests and vehicles; O(n)
void Graph::createRequests(int n)
{
	vehicles.resize(vertices);
	int vVertex; int type; int id = 1;
	for (int i = 0; i < n; i++)
	{
		vVertex = rand() % vertices;
		type = rand() % 3 + 1;
		requests.push(Request(id, type, rand() % vertices)); //For every request with requestType type, there is a vehicle pushed that could fulfill it
		vehicles[vVertex].push_back(Vehicle(id, type, vVertex));
		id++;
	}
}

//Getter to get a front element's data in a queue
Request Graph::getRequest()
{
	return requests.front();
}

//Boolean function to set while loop condition in source.cpp
bool Graph::isQueueEmpty()
{
	if (requests.empty())
		return true;
	else
		return false;
}

//Iterates through vehicles[v] to see if there is an available vehicle that meets a requests requirements; O(n)
bool Graph::hasIt(int source, int type)
{
	for (int j = 0; j < vehicles[source].size(); j++)
	{
		Vehicle vehicle = vehicles[source][j];
		if (vehicle.getVertex() == source && vehicle.getType() == type && vehicle.checkAvailable() == true)
		{
			vehicles[source][j].setUnavailable();
			std::cout << "Vehicle of type " << type << " at vertex " << vehicle.getVertex();
			return true;
		}
	}
	return false;
}

void Graph::popQueue()
{
	requests.pop();
}

//Request request = graph.getData(); request = queue.getFront();
//Initially at source (the request location)
void Graph::shortestPath(int source, int type)
{

	if (hasIt(source, type) == true)
	{
		popQueue();
		std::cout << " shortest distance was 0" << "\n""\n";
		return;
	}

	vector <int> dist(vertices);
	priority_queue<Node, vector<Node>, Compare> unvisited;
	vector<bool> hasVisited(vertices);

	//Initialize all elements in dist, except for the source, to infinity and pushes the source node into queue
	for (int i = 0; i < vertices; i++)
	{
		if (i == source)
		{
			unvisited.push(Node(i, 0));
			dist[source] = 0;
			hasVisited[source] = true;
		}
		else
		{
			dist[i] = INT_MAX;
			hasVisited[i] = false;
		}
	}

	while (!unvisited.empty())
	{
		Node current = unvisited.top(); //Current is the lowest weighted node in queue
		int currentNode = current.getid();
		unvisited.pop();
		hasVisited[currentNode] = true;

		//Call hasit function to check if the node has a vehicle to fulfill request
		if (hasIt(currentNode, type) == true)
		{
			popQueue();
			std::cout << " responded to request at vertex " << source << " shortest distance is " << dist[currentNode] << "\n""\n";
			return;
		}
		//If node didn't have vehicle to fullfill request move through adjList, relax edges, and add nodes that haven't been visited
		else
		{
			for (int i = 0; i < adjList[currentNode].size(); i++)
			{
				int currentWeight = dist[currentNode];
				int destination = adjList[currentNode][i].getDest();

				if (dist[destination] > (adjList[currentNode][i].getWeight() + dist[currentNode]))
				{
					dist[destination] = (adjList[currentNode][i].getWeight() + dist[currentNode]);
					//Check if we have visited this node before
					if (hasVisited[destination] == false)
						unvisited.push((Node(destination, dist[destination])));
				}
			}
		}
	}
}




