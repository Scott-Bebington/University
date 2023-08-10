#include "Rectangle.h" // Needed for the Rectangle class
#include <iostream> // Needed for cout
#include <cstdlib> // Needed for the exit function

using namespace std;
//***********************************************************
// setWidth sets the value of the member variable
//width.***********************************************************
void Rectangle::setWidth(double w)
{
    if (w >= 0)
    {
       width = w; 
    }
    else
    {
        cout << "Invalid width\n";
        exit(EXIT_FAILURE);
    }
}
void Rectangle::setLength(double l)
{
    if (l >= 0)
    {
       length = l; 
    }
    else
    {
        cout << "Invalid Length\n";
        exit(EXIT_FAILURE);
    }
}
double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getLength() const
{
    return length;
}