#pragma once

#include <iostream>
#include <GL/glew.h>
#include "shapes.h"
#include "Background.h"

using namespace std;

class Car
{
protected:
    GLfloat carLength, carHeight, windowHeightBack, windowHeightFront, wheelRadius;
    GLfloat bottomLeft[2];
    Shapes shapes;
    Background road;
    float startingAngle = 0.0f;

public:
    Car();
    void createCar();

    // Car Parts
    void drawBody();
    void drawRoof();
    void drawWindows();
    void drawWheels();
    void drawHubCaps();

    // Movements
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    // toggle wireframe
    void toggleWireframe();

    // Rotate Wheels
    void rotateWheels();
};