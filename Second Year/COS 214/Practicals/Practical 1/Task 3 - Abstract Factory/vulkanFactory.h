#ifndef VULKANFACTORY_H
#define VULKANFACTORY_H

#include <iostream>
#include "Window.h"
#include "Primitive.h"
#include "vulkanPrimitive.h"

using namespace std;

class vulkanFactory : public Window
{
public:

    vulkanFactory() {}

    Window* createWindow();
    Primitive* createPrimitive();

    virtual void setScreenHeight(int height) = 0;
    virtual void setScreenWidth(int width) = 0;

};

#endif // VULKANFACTORY_H