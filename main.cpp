#include <iostream>
#include "shape.h"
#include "box.h"
#include "sphere.h"
#include "capsule.h"


int main()
{
	Sphere sp(39, { 3,5,1 });
	double area = sp.GetSurfaceArea();
	std::cout << "Area of sphere: " << area << std::endl;

	Capsule cap({ 1,2,3 }, 25, { 5,6,7 }, 75, 15,{2,3,1});
	double length = cap.Length();
	std::cout << "Length of capsule: " << length << std::endl;

	double volume = cap.GetVolume();
	std::cout << "Volume of capsule: " << volume << std::endl;

	

	return 0;
}