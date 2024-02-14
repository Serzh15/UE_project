#include "sphere.h"

double Sphere::GetRadius() const
{
    return radius_;
}

double Sphere::GetVolume() 
{
    double radius = GetRadius();
    double volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
    return volume;
}

bool Sphere::isInside(const Point& point)
{
    double distance = point.Distance(center_);
    return distance <= radius_;
}

Point Sphere::Center()
{
    return center_;
}

Point Sphere::GetCenter()
{
    return Center();
}

double Sphere::GetSurfaceArea()
{
    double area = 4 * M_PI * radius_ * radius_;
    return area;
}
