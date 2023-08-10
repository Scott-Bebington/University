#ifndef CUBE_H
#define CUBE_H

#include "Box.h"

class Cube : public Box
{
	public:
		Cube(double);
		~Cube() {}
		
		void setSide(double);
		double getSide() const;
			
		double getArea() const; // redefined!
};

#endif
