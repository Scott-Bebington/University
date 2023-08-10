 #include "Rectangle.h"
 #include "Box.h"
 #include "Cube.h"
 
template <class TEMPLATE>
TEMPLATE& maximum(TEMPLATE& x, TEMPLATE& y); // Why T& and not just T?

template <class M, class N>
Rectangle& maximum(M& x, N& y); 

 int main() 
 {	
	 Cube cube1;
	 Cube cube2;
	 
	 double x;
	 cout << "Enter the side of the first cube: ";
	 cin >> x;
	 
	 double y;
	 cout << "Enter the side of the second cube: ";
	 cin >> y;
	 
	 bool sideSet = false;
	 
	 while(!sideSet) {
		 try {
			 cube1.setSide(x);
			 cube2.setSide(y);			 
			 sideSet = true;
		 }
		 catch(Cube::NegativeSide e) 
		 {
			 if(e.getValue() == x) {
				cout << "Negative value provided for the first cube. Please try again: " ;
				cin >> x;
			 } else {
				cout << "Negative value provided for the second cube. Please try again: " ;
				cin >> y;
			 }
		 }
	 }
	 
	 cout << "Area of the first cube: " << cube1.getArea() << endl;
	 cout << "Area of the second cube: " << cube2.getArea() << endl;
	 
	 cout << "The largest of the two cubes has the area of: ";
	 cout << maximum(cube1, cube2).getArea() << endl;
	 
	 Box box;
	 double z;
	 cout << "Enter the dimensions of the box: ";
	 cin >> x >> y >> z;
	 box.setLength(x);
	 box.setWidth(y);
	 box.setHeight(z);
	 cout << "Area of the box: " << box.getArea() << endl;
	 
	 cout << "Between the box and the cube, the larger has the area of: ";
	 cout << maximum(cube1, box).getArea() << endl;
	 // Will this work?
	 
	 
	 cout << "Out of the two cubes and one box, the largest one has the area of: ";
	 cout << maximum(maximum(cube1, cube2), box).getArea() << endl;
	 	 
	 
	 return 0;
 }

template <class T>
T& maximum(T& x, T& y)
{
	if(x >= y) { // what if we changed >= to > ? Would the code still compile?
		return x;
	}
	else return y;
}

template <class M, class N>
Rectangle& maximum(M& x, N& y)
{
	if(x >= y) { 
		return x;
	}
	else return y;
}
