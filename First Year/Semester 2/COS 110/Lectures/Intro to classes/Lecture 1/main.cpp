#include <iostream>
#include "Rectangle.h" // Needed for Rectangle class

using namespace std;

int main()
{
    Rectangle box; // Define an instance of the Rectangle class
    double rectWidth; // Local variable for width
    double rectLength; // Local variable for length
    double area = 0.0;
    // Get the rectangle's width and length from the user. 
    cout << "This program will calculate the area of a\n"; 
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? "; 
    cin >> rectLength;
    //More program statements
    cout << "The length of the rectangle is: " << box.getLength() << endl;
    cout << "The Width of the rectangle is: " << box.getWidth() << endl;

    area = box.getLength()*box.getWidth();
    cout << "The area of the rectangle is: " << area << endl;

    Rectangle *rPtr = new Rectangle;
    // put in values:
    rPtr->setWidth(10);
    rPtr->setLength(5);
    // NB! when you’re done: delete the pointer
    delete rPtr;
    rPtr = NULL;
    
    return 0;
}