#pragma once
class Edge
{
public:
	Edge();
	Edge(int s, int d, int w) { source = s; dest = d; weight = w; };
	int getWeight() { return weight; };
	int getDest() { return dest; };
	void setWeight(int w) { weight = w; };
	void setDest(int d) { dest = d; };
	~Edge();
private:
	int source;
	int dest;
	int weight;
};

