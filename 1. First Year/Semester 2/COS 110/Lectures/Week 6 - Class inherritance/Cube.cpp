#include "Cube.h"
#include "Rectangle.h"

Cube::Cube(double side) : Box(side, side, side)
{
	cout << "Cube with side "<< side << " created" << endl;
}

void Cube::setSide(double side)
{
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