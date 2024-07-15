#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"
#include "Plane.h"

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
    glClearColor(0.7, 0.7, 0.7, 1.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEAREST);

    // Here we create a VAO
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // This is needed for sticky keys
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Here we compile and load the shaders. First we pass the vertex shader then the fragment shader.
    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");

    Plane *plane = new Plane(41);
    plane->CreatePlane();
    // plane->RotateX(-0.5);
    // plane->RotateY(0.5);
    // plane->RotateZ(0.25);
    // plane->Scale(0.75);

    bool spacePressed = false;
    int count = 1;
    do
    {
        // Here we clear the color and depth buffer bits.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        for (int i = 0; i < plane->numShapes; i++)
        {
            // drawShape(shapes[i]);
            plane->DrawPlane(plane->shapes[i]);
        }

        // Here we swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            plane->RotateX(0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            plane->RotateX(-0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            plane->RotateY(0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            plane->RotateY(-0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            plane->RotateZ(0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            plane->RotateZ(-0.05);
        }
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        {
            plane->TranslateY(0.025);
        }
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        {
            plane->TranslateY(-0.025);
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        {
            plane->TranslateX(0.025);
        }
        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        {
            plane->TranslateX(-0.025);
        }
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        {
            plane->TranslateZ(0.025);
            // plane->Scale(1.03);
        }
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        {
            plane->TranslateZ(-0.025);
            // plane->Scale(0.97);
        }
        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS && !spacePressed)
        {
            plane->ToggleWireframe();
            spacePressed = true;
        }
        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_RELEASE)
        {
            spacePressed = false;
        }

    } while (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}
