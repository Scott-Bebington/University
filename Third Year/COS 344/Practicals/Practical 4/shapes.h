#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "MathExceptions.h"

using namespace glm;
using namespace std;


struct Shape{
    vec3** vertices;
    vec4* colors;
    Shape** shapes;
    int numShapes;

    // float *coloursChange = new float[6] {
    //     0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f
    // };

    float *coloursChange = new float[6] {
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };

    ~Shape();

    virtual void applyMatrix(mat4x4);
    virtual GLfloat* toVertexArray();
    virtual GLfloat* toColorArray();
    virtual int numPoints();

    virtual int numVertices();
    virtual int numColors();

    vec4 multiplyMatrixVector(mat4x4, vec4);
    vec4 multiplyColourVector(vec4, float);
    vec3 addVectors(vec3, vec3, vec3);
    vec3 subtractVectors(vec3, vec3, vec3);
    // vec3 addVectors(vec3, vec3);
};

struct Triangle: public Shape{
    Triangle(vec3, vec3, vec3, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    int numVertices();
    int numColors();
    int numPoints();
};

struct Rectangle: public Shape{
    Rectangle(vec3, vec3, vec3, vec3, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};

struct Box: public Shape{
    Box(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};

struct Boxes: public Shape{
    Boxes(int numBoxes, vec3* centers, double* heights, double* widths, double* lengths, vec4* colors);
};

struct Pyramid: public Shape{
    Pyramid(vec3* vertices, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};

class Cone: public Shape{
public:
    Cone(vec3 center, int numSidesOnBase, float height, float radius, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};

class Cylinder: public Shape{
public:
    Cylinder();
    Cylinder(vec3 center, int numSidesOnBase, float height, float radius, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void Circles(vec3 center, int numSidesOnBase, float height, float radius, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};

class Halfbox: public Shape{
private:
    vec3 topPlane;
    vec3 bottomPlane;
    vec3 leftPlane;
    vec3 rightPlane;
    vec3 nearPlane;
    vec3 farPlane;
public:
    Halfbox(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f), string direction = "L");
    void halfboxBottomLeft(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxBottomRight(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxTopLeft(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxTopRight(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxTopFront(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxTopBack(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxBottomFront(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
    void halfboxBottomBack(vec3 center, double height, double width, double length, vec4 = vec4(1.0f, 0.0f, 0.0f, 1.0f));
};


#endif /*SHAPES_H*/