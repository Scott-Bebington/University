#include "Cube.h"
#include "Rectangle.h"

Cube::Cube()
{
}

void Cube::setSide(double side)
{
	if(side < 0) throw NegativeSide(side);
	height = side;
	width = side;
	length = side;
}

double Cube::getSide() const
{
	return height; // or width, or length - they are all equal in cube!
}
			
double Cube::getArea() const // redefined!
{
	return 6 * Rectangle::getArea();
}