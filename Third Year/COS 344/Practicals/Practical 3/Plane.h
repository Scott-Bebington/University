#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "shapes.h"
// #include "main.cpp"

using namespace glm;
using namespace std;

class Plane{
public:
    Shape** shapes;
    float currentXPos;
    float currentYPos;
    float currentZPos;
    float currentXRot;
    float currentYRot;
    float currentZRot;
    int numShapes;
    bool wireframe;

    vec3 blue = vec3(0, 0, 1);
    vec3 lightblue = vec3(0.7, 0.7, 1);
    vec3 red = vec3(1, 0, 0);
    vec3 brown = vec3(0.5, 0.2, 0.1);
    vec3 darkgreen = vec3(0.05, 0.25, 0.05);
    vec3 sand = vec3(0.9, 0.85, 0.7);
    vec3 white = vec3(1, 1, 1);
    vec3 black = vec3(0, 0, 0);
    
    Plane(int Size);
    ~Plane();
    void CreatePlane();
    void DrawPlane(Shape*);
    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void rotateArbitraryAngle(float RotationDegree, int num);
    void TranslateX(float distance);
    void TranslateY(float distance);
    void TranslateZ(float distance);
    void Scale(float factor);
    void MoveToOrigin();
    void MoveBack();
    void ToggleWireframe();
    mat4x4 Transpose(mat4x4 matrix);

};