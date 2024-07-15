#include <iostream>
#include <vector>
#include "Window.h"
#include "Primitive.h"
#include "openGLFactory.h"
#include "vulkanFactory.h"
#include "openGLWindow.h"
#include "vulkanWindow.h"

using namespace std;

int main() {
    cout << endl;

    cout << "\033[32mCreating openGLPrimitive\033[0m" << endl;
    openGLPrimitive openPrimitive1;
    openPrimitive1.setShape("Rectangle");
    openPrimitive1.setXcoord(10);
    openPrimitive1.setYcoord(20);

    cout << openPrimitive1.toString() << endl;
    
    cout << "\033[38;2;255;165;0mCreating vulkanPrimitive\033[0m" << endl;
    vulkanPrimitive vulkanPrimitive1;
    vulkanPrimitive1.setShape("Circle");
    vulkanPrimitive1.setXcoord(30);
    vulkanPrimitive1.setYcoord(40);

    cout << vulkanPrimitive1.toString() << endl;

    cout << "\033[34mCreating openGLWindow\033[0m" << endl;
    openGLWindow* openGLWindow1 = new openGLWindow();
    openGLWindow1->setPrimitiveCapacity(3);
    openGLWindow1->setScreenHeight(1000);
    openGLWindow1->setScreenWidth(2000);

    openGLWindow1->addPrimitive(openPrimitive1);
    openGLWindow1->addPrimitive(openPrimitive1);

    cout << openGLWindow1->toString() << endl;

    cout << "\033[31mCreating vulkanWindow\033[0m" << endl;
    vulkanWindow* vulkanWindow1 = new vulkanWindow();
    vulkanWindow1->setPrimitiveCapacity(3);
    vulkanWindow1->setScreenHeight(1000);
    vulkanWindow1->setScreenWidth(2000);

    vulkanWindow1->addPrimitive(vulkanPrimitive1);
    vulkanWindow1->addPrimitive(vulkanPrimitive1);

    cout << vulkanWindow1->toString() << endl;


    cout << endl;

    return 0;
}
