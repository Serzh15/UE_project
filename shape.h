#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

struct Point
{
	Point() {}
	Point(double) {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	double x = 0.0, y = 0.0, z = 0.0;

	double Distance(const Point& point) const {
		double distanceSquared = (x - point.x) * (x - point.x) +
			(y - point.y) * (y - point.y) +
			(z - point.z) * (z - point.z);

		return std::sqrt(distanceSquared);
	}
	const Point operator+(const Point& point) 
	{
		return Point(x + point.x, y + point.y, z + point.z);
	}
	Point operator/(double scalar) const {
		return Point( x / scalar, y / scalar, z / scalar );
	}
	
};

struct Size
{
	Size(double x, double y, double z) : x(x), y(y), z(z) {}

	double x = 0.0, y = 0.0, z = 0.0;
	double width = 0.0, height = 0.0, depth = 0.0;
};

class Shape
{
public:
	virtual ~Shape() {};

	virtual Point Center() = 0;
	virtual Point GetCenter() = 0;
	virtual double GetSurfaceArea() = 0;
	virtual double GetVolume() = 0;
	virtual bool isInside(const Point& point) = 0;

private:
	double x_;
	double y_;
	double z_;
};