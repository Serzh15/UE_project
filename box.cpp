#include "box.h"

Box::Box(const Point& min, const Point& max) : min_(min), max_(max) {}

Point Box::GetMin() const
{
	return min_;
}
Point Box::GetMax() const
{
	return max_;
}

Point Box::Center() 
{
	Point center = (min_ + max_) / 2;
	return center / 2.0;
}

double Box::GetSurfaceArea() 
{
	double dx = max_.x - min_.x;
	double dy = max_.y - min_.y;
	double dz = max_.z - min_.z;
	return 2 * (dx * dy + dy * dz + dz * dx);
}

double Box::GetVolume() 
{
	double dx = max_.x - min_.x;
	double dy = max_.y - min_.y;
	double dz = max_.z - min_.z;
	return dx * dy * dz;
}

bool Box::isInside(const Point& point)
{
	return (point.x >= min_.x && point.x <= max_.x) &&
		   (point.y >= min_.y && point.y <= max_.y) &&
		   (point.z >= min_.z && point.z <= max_.z);
}

Size Box::GetSize() const
{
	return Size(max_.x - min_.x, max_.y - min_.y, max_.z - min_.z);
}

std::vector<Point> Box::GetVertices() const
{
	std::vector<Point> vertices(8);
	
	// bottom edge

	vertices[0] = min_;
	vertices[1] = Point(max_.x, min_.y, min_.z);
	vertices[2] = Point(max_.x, max_.y, min_.z);
	vertices[3] = Point(min_.x, max_.y, min_.z);

	// top edge

	vertices[4] = Point(min_.x, min_.y, max_.z);
	vertices[5] = Point(max_.x, min_.y, max_.z);
	vertices[6] = Point(max_.x, max_.y, max_.z);
	vertices[7] = Point(min_.x, max_.y, max_.z);
	return vertices;
}


