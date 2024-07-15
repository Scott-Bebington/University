#ifndef OPENGLFACTORY_H
#define OPENGLFACTORY_H

#include <iostream>
#include "Window.h"
#include "Primitive.h"
#include "openGLPrimitive.h"

using namespace std;

class openGLFactory : public Window
{

public:

    openGLFactory();

    Window* createWindow();
    Primitive* createPrimitive();

    virtual void setScreenHeight(int height) = 0;
    virtual void setScreenWidth(int width) = 0;

};

#endif // !OPENGLFACTORY_H