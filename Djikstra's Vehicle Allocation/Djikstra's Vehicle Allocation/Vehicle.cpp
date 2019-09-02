#include "Vehicle.h"



Vehicle::Vehicle()
{
}

Vehicle::Vehicle(int _id, int _type, int _vertex)
{
	id = _id;
	type = _type;
	vertex = _vertex;
	available = true;
}


Vehicle::~Vehicle()
{
}
