 #include "Rectangle.h"
 #include "Box.h"
 #include "Cube.h"
 
 int main() 
 {
	 Rectangle r(2,2); // Area = 4
	 cout << "-------------------------\n";
	 Box b(1,1,1); // Area = 6
	 cout << "-------------------------\n";
	 
	 // Default constructors:
	 Rectangle r2;
	 cout << "-------------------------\n";
	 Box b2;
	 cout << "-------------------------\n";
	 
	 cout << "Rectangle's area: " << r.getArea() << endl;
	 cout << "Box's area: " <<  b.getArea() << endl;
	 
	 r.printArea();
	 b.printArea();
	
	 // Box destroyed
	 // ~Box
	 // ~Rectangle
	 // Rectange destroyed
	 // ~Rectangle
 }