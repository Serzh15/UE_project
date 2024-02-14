#pragma once
#include "shape.h"
#include <cmath>

class Sphere : public Shape
{
public:

	Sphere() : radius_(0.0) {}
	Sphere(double radius, const Point& center) : radius_(radius), center_(center) {}

	Point Center() override;
	Point GetCenter() override;

	double GetRadius() const;
	double GetSurfaceArea() override;
	double GetVolume()  override;

	bool isInside(const Point& point) override;

private:
	double radius_;
	Point center_;
};
