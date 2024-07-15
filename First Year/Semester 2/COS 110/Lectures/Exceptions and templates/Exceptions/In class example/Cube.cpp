#include "Cube.h"
#include "Rectangle.h"

Cube::Cube()
{
	cout << "Cube with side " << length << " created" << endl;
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
			
double Cube::getArea() const 
{
	return 6 * Rectangle::getArea();
}