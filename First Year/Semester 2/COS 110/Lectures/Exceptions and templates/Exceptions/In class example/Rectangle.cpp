#include "Rectangle.h"
 
Rectangle::Rectangle() 
{
	length = 0;
	width = 0;
	cout << "Rectangle created, ";
	cout << "length: " << length;
	cout << " width: " << width << endl;
}
		
void Rectangle::setLength(double l)
{
	if(l < 0) throw NegativeSize();
	length = l;
}

void Rectangle::setWidth(double w)
{
	if(w < 0) throw NegativeSize();
	width= w;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getWidth() const
{
	return width;
}
			
double Rectangle::getArea() const
{
	//cout << "Calculating the area of a rectangle..." << endl;
	return length * width;
}

void Rectangle::printArea() const
{
	cout << "The surface area of this rectangle-like object is ";
	cout << getArea() << endl;
}