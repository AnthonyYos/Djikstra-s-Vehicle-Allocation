#include "Graph.h"
#include <iostream>
#include "compare.h"


Graph::Graph()
{
}

Graph::Graph(int v)
{
	vertices = v;
	adjlist.resize(v);
}

Graph::~Graph()
{
}
//Assumed undirected graph; for every edge pushed in adjlist[s] to d, there is an exact edge in adjlist[d] to s
void Graph::addEdge(int s, int d, int w)

{
	if ((s >= 0 && s < vertices) && (d >= 0 && d < vertices) && s != d && w > 0)
	{

		adjlist[s].push_back(Edge(s, d, w));
		adjlist[d].push_back(Edge(d, s, w));
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

	//Comes here if the source didn't have a vehicle to fulfill request
	//vector<Node> nodelist;
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
			//nodelist.push_back((Node(i, INT_MAX)));
		}
	}

	while (!unvisited.empty())
	{
		Node current = unvisited.top(); //Node n is the lowest weighted node in queue
		//n has a ID and WEIGHT
		int currentNode = current.getid();
		unvisited.pop();
		hasVisited[currentNode] = true;
		//Check, call hasit function to check if node n has a vehicle to fulfill request, if not move through add nodes, relax nodes, and repeat
		if (hasIt(currentNode, type) == true)
		{
			popQueue();
			std::cout << " responded to request at vertex " << source << " shortest distance is " << dist[currentNode] << "\n""\n";
			return;
		}
		else
		{
			for (int i = 0; i < adjlist[currentNode].size(); i++)
			{
				int currentWeight = dist[currentNode];
				int pointingIndex = adjlist[currentNode][i].getDest(); //pointingIndex is the destination node
				//adjlist[current][i] points to a destination w/ a weight, where currentWeight =  & currentIndex = the local source;
				//
				//check against the edge of adjlist[current][i].getWeight() + the current weight at whatever adjlist[current] is
				if (dist[pointingIndex] > (adjlist[currentNode][i].getWeight() + dist[currentNode]))
				{
					dist[pointingIndex] = (adjlist[currentNode][i].getWeight() + dist[currentNode]);
					//dist[adjlist[s][i].getDest()] = (adjlist[s][i].getWeight() + nodelist[s].getWeight());
					//nodelist[pointingIndex].setWeight(dist[adjlist[currentNode][i].getWeight()]);
					if (hasVisited[pointingIndex] == false)
						unvisited.push((Node(pointingIndex, dist[pointingIndex])));
				}
			}
		}
	}
}




