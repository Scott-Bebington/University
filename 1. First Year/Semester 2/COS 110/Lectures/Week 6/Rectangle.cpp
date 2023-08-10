#include "Rectangle.h"
 
 Rectangle::Rectangle()
 {
	 length = width = 1;
	 cout << "Default rectangle created\n";
 }
 
Rectangle::Rectangle(double l, double w) : length(l), width(w)
{
	cout << "Rectangle created, ";
	cout << "length: " << length;
	cout << " width: " << width << endl;
}
		
void Rectangle::setLength(double l)
{
	length = l;
}

void Rectangle::setWidth(double w)
{
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
	return length * width;
}

void Rectangle::printArea() const
{
	cout << "The surface area of this rectangle-like object is ";
	cout << getArea() << endl;
}