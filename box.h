#pragma once
#include "shape.h"

class Box : public Shape {
public:
	
	Box(const Point& min, const Point& max);

	Point GetMin() const;
	Point GetMax() const;
	Point Center() override;

	double GetSurfaceArea() override;
	double GetVolume() override;

	bool isInside(const Point& point) override;

	Size GetSize() const;
	std::vector<Point> GetVertices() const;
	
private:
	double x, y, z;
	Point min_;
	Point max_;
	std::vector<Point> vertices;
};
