#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
	public:
		//Exception class:
		class NegativeSize{};	
	
		Rectangle();
		~Rectangle() {}
		
		virtual void setLength(double);
		virtual void setWidth(double);
		
		double getLength() const;
		double getWidth() const;
			
		virtual double getArea() const;
			
		void printArea() const;
			
	protected:
		double length;
		double width;
};

#endif
