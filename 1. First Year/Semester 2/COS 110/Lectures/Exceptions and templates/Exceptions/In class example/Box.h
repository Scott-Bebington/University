#ifndef BOX_H
#define BOX_H

#include "Rectangle.h"

class Box : public Rectangle
{
	public:
		//Exception classes:
		class NegativeWidth{};	
		class NegativeLength{};				
		class NegativeHeight{};	
			
		Box();
		~Box(){}
		
		void setLength(double);
		void setWidth(double);
		void setHeight(double);
		double getHeight() const;
			
		double getVolume() const;
			
		virtual double getArea() const; // overridden function
			
	protected:
		double height;
};

#endif

