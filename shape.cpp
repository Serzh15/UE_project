#include "shape.h"

Point Shape::Center()
{
	return 0;
}

Point Shape::GetCenter()
{
	return Center();
}

double Shape::GetSurfaceArea()
{
	return 0;
}
double Shape::GetVolume()
{
	return 0;
}
bool Shape::isInside(const Point& point)
{
	return false;
}

