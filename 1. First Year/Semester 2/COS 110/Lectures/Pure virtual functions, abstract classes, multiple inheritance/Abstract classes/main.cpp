#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"


int main () {
  
	Rectangle rect;
  Triangle trgl;
	
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
	
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
	
  cout<<ppoly1->area()<< '\n';
  cout<<ppoly2->area()<<'\n';
	
  return 0;
}