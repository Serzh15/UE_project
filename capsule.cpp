#include "capsule.h"

Capsule::Capsule(const Point& center1, double radius1, const Point& center2, double radius2, double theta, const std::vector<double>& orientation) :
	center1_(center1), radius1_(radius1), center2_(center2), radius2_(radius2), theta_(theta), orientation_(orientation) {}

double Capsule::Length() const
{
	double dx = center1_.x - center2_.x;
	double dy = center1_.y - center2_.y;
	double dz = center1_.z - center2_.z;
	double distance = sqrt(dx * dx + dy * dy + dz * dz);
	return distance + radius1_ + radius2_ - 2 * radius1_ * radius2_ * cos(theta_);
}

double Capsule::GetRadius() const
{
	return (radius1_ + radius2_) / 2;
}

Point Capsule::Center()
{
	return (center1_ + center2_) / 2;
}

Point Capsule::GetCenter1() const
{
	return center1_;
}

Point Capsule::GetCenter2() const
{
	return center2_;
}

double Capsule::GetSurfaceArea()
{
	return 2 * M_PI * (radius1_ * radius1_ + radius2_ * radius2_) - 2 * M_PI * radius1_ * radius2_ * (1 - cos(theta_));
}

double Capsule::GetVolume()
{
	return (4.0 / 3.0) * M_PI * (radius1_ * radius1_ * radius1_ + radius2_ * radius2_ * radius2_) - (4.0 / 3.0) * M_PI * radius1_ * radius1_ * radius2_ * (1 - cos(theta_));
}

bool Capsule::isInside(const Point& point)
{
		double dx1 = point.x - center1_.x;
		double dy1 = point.y - center1_.y;
		double dz1 = point.z - center1_.z;
		double distance1 = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);

		double dx2 = point.x - center2_.x;
		double dy2 = point.y - center2_.y;
		double dz2 = point.z - center2_.z;
		double distance2 = sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);

		return (distance1 <= radius1_) && (distance2 <= radius2_);
	}

Point Capsule::GetCenter()
{
	return 0;
}

double Capsule::Radius() const
{
	return GetRadius();
}

double Capsule::GetRadius1() const
{
	return radius1_;
}
double Capsule::GetRadius2() const
{
	return radius2_;
}

double Capsule::GetTheta() const
{
	return theta_;
}

std::vector<double> Capsule::GetOrientation() const
{
	 	return orientation_;
}

std::vector<double> Capsule::Orientation() const
{
	return orientation_;
}

