#include "Box.h"

Box::Box()
 {
	 height = 1;
	 cout << "Default box created\n";
 }

Box::Box(double l, double w, double h) : Rectangle(l,w), height(h) 
{
	cout << "Box created, ";
	cout << "length: " << length;
	cout << " width: " << width; 
	cout << " height: " << height << endl;
}
		
void Box::setHeight(double h)
{
	height = h;
}

double Box::getHeight() const
{
	return height;
}
			
double Box::getArea() const
{
	//cout << "Calculating the area of a box..." << endl;
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