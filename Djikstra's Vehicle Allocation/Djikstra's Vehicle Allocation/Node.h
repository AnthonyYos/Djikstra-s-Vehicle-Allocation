#pragma once
class Node
{
public:
	Node();
	Node(int _id, int w);
	~Node();
	void setWeight(int w) { weight = w; };
	int getWeight() { return weight; };
	int getid() { return id; };
private:
	int id;
	int weight;
};

