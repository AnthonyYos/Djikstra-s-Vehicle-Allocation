#pragma once
class Vehicle
{
public:
	Vehicle();
	Vehicle(int _id, int _type, int _vertex);
	~Vehicle();
	int getid() { return id; };
	int getType() { return type; };
	int getVertex() { return vertex; };
	bool checkAvailable() { return available; };
	void setUnavailable() { available = false; };
private:
	int id;
	int type;
	int vertex;
	bool available;
};

