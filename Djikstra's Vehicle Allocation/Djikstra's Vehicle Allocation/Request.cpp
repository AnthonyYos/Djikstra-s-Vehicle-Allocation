#include "Request.h"



Request::Request()
{
}

Request::Request(int _id, int _requestType, int _vertex)
{
	id = _id;
	requestType = _requestType;
	vertex = _vertex;
}


Request::~Request()
{
}
