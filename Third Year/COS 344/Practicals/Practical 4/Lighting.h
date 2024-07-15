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

class Lighting{
public:
    Shape** shapes;
    float currentXPos;
    float currentYPos;
    float currentZPos;
    int numShapes;
    bool wireframe;

    vec4 blue = vec4(0, 0, 1, 1);
    vec4 lightblue = vec4(0.7, 0.7, 1, 1);
    vec4 red = vec4(1, 0, 0, 1);
    vec4 brown = vec4(0.5, 0.2, 0.1, 0.1);
    vec4 darkgreen = vec4(0.05, 0.25, 0.05, 1);
    vec4 sand = vec4(0.9, 0.85, 0.7, 1);
    vec4 white = vec4(1, 1, 1, 1);
    vec4 black = vec4(0, 0, 0, 1);
    
    Lighting(int Size);
    ~Lighting();
    void CreateSheets();
    void DrawSheets(Shape*);
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