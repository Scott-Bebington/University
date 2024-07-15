#pragma once

#include <iostream>
#include <GL/glew.h>

using namespace std;

class Shapes
{
private:
    bool toggle;
public:
    Shapes();
    void toggleWireframe();
    void drawStrip(GLfloat[], GLuint, size_t);
    void drawTriangle(GLfloat[], GLuint, size_t);
    void drawCircle(GLfloat, GLfloat, GLfloat, size_t, GLuint, float);
};