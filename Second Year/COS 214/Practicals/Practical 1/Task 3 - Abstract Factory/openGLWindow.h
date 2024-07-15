#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <iostream>
#include "Window.h"
#include "Primitive.h"
#include "openGLPrimitive.h"

using namespace std;

class openGLWindow : public Window
{
public:

    openGLPrimitive* primitives;

    string printAllPrimitiveToStrings();
    string toString();

    openGLPrimitive* getOpenGLPrimitives();
    void setOpenGLPrimitives(openGLPrimitive*);

    void addPrimitive(openGLPrimitive);

};

#endif // OPENGLWINDOW_H