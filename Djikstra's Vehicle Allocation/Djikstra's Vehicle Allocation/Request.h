#pragma once
class Request
{
public:
	Request();
	Request(int _id, int _requestType, int _vertex);
	~Request();
	int getid() { return id; };
	int getRequestType() { return requestType; };
	int getVertex() { return vertex; };
	void setid(int _id) { id = _id; };
	void setRequestType(int t) { requestType = t; };
	void setVertex(int v) { vertex = v; };
private:
	int id;
	int requestType;
	int vertex;
};

