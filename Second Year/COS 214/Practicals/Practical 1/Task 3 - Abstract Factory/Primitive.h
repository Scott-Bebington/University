#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <iostream>

using namespace std;

class Primitive
{
public:

    Primitive();

    string shape;
    
    string getShape();
    void setShape(string);

    virtual float getXcoord() = 0;
    virtual float getYcoord() = 0;

    virtual void setXcoord(float) = 0;
    virtual void setYcoord(float) = 0;

protected:

    virtual string toString() = 0;
};

#endif // !PRIMITIVE_H