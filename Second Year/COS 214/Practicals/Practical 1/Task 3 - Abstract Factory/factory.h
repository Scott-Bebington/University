#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "Window.h"
#include "Primitive.h"

using namespace std;

class factory : public Window
{

public: 

    virtual Window* createWindow() = 0;
    virtual Primitive* createPrimitive() = 0;

};

#endif // !FACTORY_H