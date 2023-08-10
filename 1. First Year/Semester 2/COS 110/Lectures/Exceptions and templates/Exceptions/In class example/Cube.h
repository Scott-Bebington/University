#ifndef CUBE_H
#define CUBE_H

#include "Box.h"

class Cube : protected Box
{
	public:
		//Exception class:
		class NegativeSide{
			private:
				double value;
			public:
				NegativeSide(double v) : value(v) {}
				double getValue() { return value; }
		};	
			
		Cube();
		~Cube() {}
		
		void setSide(double);
			
		double getSide() const;
			
		virtual double getArea() const; // overridden
};

#endif
