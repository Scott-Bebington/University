#ifndef BOX_H
#define BOX_H

#include "Rectangle.h"

class Box : public Rectangle
{
	public:
		Box();
		Box(double, double, double);
		~Box() {
			cout << "Box destroyed!\n";
		}
		
		void setHeight(double);
		double getHeight() const;
			
		double getVolume() const;
			
		double getArea() const; // redefined function
			
	protected:
		double height;
};

#endif

