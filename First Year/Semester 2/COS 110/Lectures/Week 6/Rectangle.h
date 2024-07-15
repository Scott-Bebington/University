#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
	public:
		Rectangle();
		Rectangle(double, double);
		~Rectangle() { 
			cout << "Rectangle destroyed!\n";
		}
		
		void setLength(double);
		void setWidth(double);
		
		double getLength() const;
		double getWidth() const;
			
		virtual double getArea() const; 
			
		void printArea() const;
			
	protected:
		double length;
		double width;
};

#endif
