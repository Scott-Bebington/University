#pragma once

#include <iostream>
#include <GL/glew.h>
#include "shapes.h"

// using namespace glm;
using namespace std;

class Background
{
public:
Shapes shapes;
    Background();
    void createRoad();
    void createBuilding(GLfloat height, GLfloat width, GLfloat x, GLfloat y, GLuint colourbuffer);
    void drawBackground();
};