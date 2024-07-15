#ifndef OPENGLPRIMITIVE_H
#define OPENGLPRIMITIVE_H

#include <iostream>
#include "Primitive.h"

using namespace std;

class openGLPrimitive : public Primitive
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

#endif // OPENGLPRIMITIVE_H