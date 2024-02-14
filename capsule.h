#pragma once
#include "shape.h"
#include <math.h>

class Capsule : public Shape
{
public:
	Capsule(const Point& center1, double radius1, const Point& center2, double radius2, double theta, const std::vector<double>& orientation);

	Point GetCenter() override;
	Point Center() override;
	Point GetCenter1() const;
	Point GetCenter2() const;

	bool isInside(const Point& point) override;

	double Length() const;
	double Radius() const;

	double GetRadius() const;
	double GetSurfaceArea() override;
	double GetVolume()  override;

	double GetRadius1() const;
	double GetRadius2() const;
	double GetTheta() const;

	std::vector<double> GetOrientation() const;
	std::vector<double> Orientation() const;

private:
	Point center1_;
	double radius1_;
	Point center2_;
	double radius2_;
	double theta_;
	std::vector<double> orientation_;
};
