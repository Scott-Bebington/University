 #include "Rectangle.h"
 #include "Box.h"
 #include "Cube.h"
 
 int main() 
 {
	 Rectangle rectangle;
	 double x, y;
	
	 cout << "Enter length and width of the rectangle: ";
	 cin >> x >> y;
	 
	 try 
	 {
		 rectangle.setLength(x);
		 rectangle.setWidth(y);
	 }
	 catch(Rectangle::NegativeSize) 
	 {
		 cout << "Negative size entered! Please try again: ";
		 cin >> x >> y;
		 rectangle.setLength(x);
		 rectangle.setWidth(y);
	 }
	 
	 rectangle.printArea();	
	 
	 Box box;
	 double z;
	
	 cout << "\nEnter length, width, and height of a box: ";
	 cin >> x >> y >> z;
	 bool allPositive = false;
	 
	 while(!allPositive) {	 
		 try 
		 {
			 box.setLength(x); 
			 box.setWidth(y); 
			 box.setHeight(z); 
			 allPositive = true;
		 }
		 catch(Box::NegativeLength) 
		 {
			 cout << "Negative length entered! Please try again: " ;
			 cin >> x ;
		 }
		 catch(Box::NegativeWidth) 
		 {
			 cout << "Negative width entered! Please try again: " ;
			 cin >> y ;
		}	 
		catch(Box::NegativeHeight) 
		{
			 cout << "Negative height entered! Please try again: ";
			 cin >> z ;
		}
	}
	 box.printArea();
	
	 
	 Cube cube;
	 
	 cout << "\nEnter the side of a cube: ";
	 cin >> x;
	 
	 bool sideSet = false;
	 
	 while(!sideSet) {
		 try {
			 cube.setSide(x);
			 
			 sideSet = true;
		 }
		 catch(Cube::NegativeSide e) 
		 {
			 cout << e.getValue() ;
			 cout << " is a negative value! Please try again: " ;
			 cin >> x;
		 }
	 }
	 cout << "Area of the cube is " << cube.getArea() << endl;
	 
 }