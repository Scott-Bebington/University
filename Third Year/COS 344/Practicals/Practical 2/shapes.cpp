#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"
#include "shapes.h"

using namespace std;
using namespace glm;

Shapes::Shapes()
{
    this->toggle = true;
}

void Shapes::toggleWireframe()
{
    this->toggle = !this->toggle;
}

void Shapes::drawStrip(GLfloat strip[], GLuint colourbuffer, size_t Size)
{
    size_t numElements = (Size / sizeof(strip[0])) / 3;

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, Size, strip, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colourbuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    if (this->toggle)
    {
        glDrawArrays(GL_TRIANGLE_STRIP, 0, numElements);
    }
    else
    {
        glDrawArrays(GL_LINE_LOOP, 0, numElements);
    }

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Shapes::drawTriangle(GLfloat triangle[], GLuint colourbuffer, size_t triangleSize)
{
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, triangleSize, triangle, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colourbuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    if (this->toggle)
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    else
    {
        glDrawArrays(GL_LINE_LOOP, 0, 3);
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Shapes::drawCircle(GLfloat x, GLfloat y, GLfloat radius, size_t vertices, GLuint colourbuffer, float startingAngle)
{
    int numberOfVertices = vertices + 2;

    GLfloat twicePi = 2.0f * M_PI;

    GLfloat backWheel[(numberOfVertices) * 3];

    backWheel[0] = x;
    backWheel[1] = y;
    backWheel[2] = 0.0;

    for (int i = 1; i < numberOfVertices; i++)
    {
        float angle = (i * twicePi / vertices) + startingAngle;
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);

        backWheel[i * 3] = x + (radius * cosAngle);
        backWheel[(i * 3) + 1] = y + (radius * sinAngle);
        backWheel[(i * 3) + 2] = 0.0;
    }

    size_t Size = sizeof(backWheel);

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, Size, backWheel, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colourbuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    if (this->toggle)
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
    }
    else
    {
        glDrawArrays(GL_LINE_LOOP, 0, numberOfVertices);
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
