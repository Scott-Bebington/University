#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"
#include "Lighting.h"

using namespace glm;
using namespace std;

const char *getError()
{
    const char *errorDescription;
    glfwGetError(&errorDescription);
    return errorDescription;
}

inline void startUpGLFW()
{
    glewExperimental = true; // Needed for core profile
    if (!glfwInit())
    {
        throw getError();
    }
}

inline void startUpGLEW()
{
    glewExperimental = true; // Needed in core profile
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw getError();
    }
}

inline GLFWwindow *setUp()
{
    startUpGLFW();
    glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    GLFWwindow *window;                                            // (In the accompanying source code, this variable is global for simplicity)
    window = glfwCreateWindow(1000, 1000, "Experiment", NULL, NULL);
    if (window == NULL)
    {
        cout << getError() << endl;
        glfwTerminate();
        throw "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    startUpGLEW();
    return window;
}

void drawTriangle(GLfloat triangle[], GLuint colourbuffer, size_t triangleSize)
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

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

int main()
{
    // This is the normal setup function calls.
    GLFWwindow *window;
    try
    {
        window = setUp();
    }
    catch (const char *e)
    {
        cout << e << endl;
        throw;
    }


    // Here we set the background color to a shade of gray.
    glClearColor(1, 1, 1, 1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEAREST);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // link the shader program
    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");

    // Define vertex data
    GLfloat vertices1[] = {
        -0.5f, -0.5f, 0.0f, // front triangle
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    GLfloat vertices2[] = {
        -0.8f, -0.8f, 0.5f, // back triangle
        0.8f, -0.8f, 0.5f,
        0.0f, 0.8f, 0.5f};

    // Define color data
    GLfloat colors1[] = {
        1.0f, 0.0f, 0.0f, 0.5f, // red with alpha 0.5 (transparent)
        1.0f, 0.0f, 0.0f, 0.5f,
        1.0f, 0.0f, 0.0f, 0.5f};

    GLfloat colors2[] = {
        0.0f, 1.0f, 0.0f, 1.0f, // green
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f};

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw triangles
        drawTriangle(vertices1, 0, sizeof(vertices1)); // front triangle
        drawTriangle(vertices2, 1, sizeof(vertices2)); // back triangle

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
