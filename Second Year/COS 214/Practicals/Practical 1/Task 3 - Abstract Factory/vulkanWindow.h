#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H

#include <iostream>
#include "Window.h"
#include "Primitive.h"
#include "vulkanPrimitive.h"

using namespace std;

class vulkanWindow : public Window
{
public:

    vulkanPrimitive* primitives;

    string printAllPrimitiveToStrings();
    string toString();

    vulkanPrimitive* getVulkanPrimitives();
    void setVulkanPrimitives(vulkanPrimitive*);

    void addPrimitive(vulkanPrimitive);

};

#endif // VULKANWINDOW_H