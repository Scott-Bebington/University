#include "Box.h"

Box::Box()  
{
	height = 0; 
	cout << "Box created, ";
	cout << "length: " << length;
	cout << " width: " << width; 
	cout << " height: " << height << endl;
}

void Box::setLength(double l)
{
	if(l < 0) throw NegativeLength();
	length = l;
}

void Box::setWidth(double w)
{
	if(w < 0) throw NegativeWidth();
	width= w;
}		

void Box::setHeight(double h)
{
	if(h < 0) throw NegativeHeight();
	height = h;
}

double Box::getHeight() const
{
	return height;
}
			
double Box::getArea() const
{
	double area = 0;
	area += 2 * height * width;
	area += 2 * height * length;
	area += 2 * Rectangle::getArea();
	return area;
}

double Box::getVolume() const
{
	return height * width * length;
}