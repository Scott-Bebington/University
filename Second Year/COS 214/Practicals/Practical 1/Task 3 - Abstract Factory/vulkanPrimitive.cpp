#include "vulkanPrimitive.h"

using namespace std;

string vulkanPrimitive::toString()
{
    string str = "";
    str += "Vulkan " + shape + ":\n";
    str += "\tX coordinate: " + to_string(xcoord) + "\n";
    str += "\tY coordinate: " + to_string(ycoord) + "\n";
    return str;
}

float vulkanPrimitive::getXcoord()
{
    return xcoord;
}

float vulkanPrimitive::getYcoord()
{
    return ycoord;
}

void vulkanPrimitive::setXcoord(float x)
{
    xcoord = x;
}

void vulkanPrimitive::setYcoord(float y)
{
    ycoord = y;
}