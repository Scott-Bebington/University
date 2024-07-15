#include "openGLPrimitive.h"

using namespace std;

string openGLPrimitive::toString()
{
    string str = "";
    str += "OpenGL " + shape + ":\n";
    str += "\tX coordinate: " + to_string(xcoord) + "\n";
    str += "\tY coordinate: " + to_string(ycoord) + "\n";
    return str;
}

float openGLPrimitive::getXcoord()
{
    return xcoord;
}

float openGLPrimitive::getYcoord()
{
    return ycoord;
}

void openGLPrimitive::setXcoord(float x)
{
    xcoord = x;
}

void openGLPrimitive::setYcoord(float y)
{
    ycoord = y;
}