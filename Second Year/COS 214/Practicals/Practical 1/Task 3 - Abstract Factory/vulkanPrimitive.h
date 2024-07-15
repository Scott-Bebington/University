#ifndef VULKANPRIMITIVE_H
#define VULKANPRIMITIVE_H

#include <iostream>
#include "Primitive.h"

using namespace std;

class vulkanPrimitive : public Primitive
{
    
public:
    float xcoord;
    float ycoord;

    string toString();

    float getXcoord();
    float getYcoord();

    void setXcoord(float x);
    void setYcoord(float y);

};

#endif // VULKANPRIMITIVE_H