#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <utility>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"

#define timeDT std::chrono::_V2::steady_clock::time_point

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

double aFPS()
{
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    double detlaTime = currentTime - lastTime;
    cout << "FPS: " << 1 / detlaTime << endl;
    lastTime = currentTime;
    return detlaTime;
}

int main()
{
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

    glClearColor(0.2, 0.2, 0.2, 0.2);
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");

    timeDT lastChanged = chrono::steady_clock::now();
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    double lastTime;
    lastTime = glfwGetTime();
    GLfloat vertices[]{
        -0.1, 0,
        0, 0.1,
        0.1, 0};
    GLfloat colors[]{
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
    };
    do
    {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            1,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glfwSwapBuffers(window);
        glfwPollEvents();

        float angle = 0.1;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            mat3x3 rotation = mat3x3(0.0f);;
            rotation[0].x = cos(angle);
            rotation[0].y = -sin(angle);
            rotation[1].x = sin(angle);
            rotation[1].y = cos(angle);
            rotation[2].z = 1;
            for(int i=0; i < (sizeof(vertices) / sizeof(GLfloat))-1; i = i+2){
                vec3 point = vec3(vertices[i], vertices[i+1], 1.0f);
                vec3 res = transpose(rotation) * point;
                vertices[i] = res.x;
                vertices[i+1] = res.y;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            mat3x3 rotation= mat3x3(0.0f);;
            rotation[0].x = cos(-angle);
            rotation[0].y = -sin(-angle);
            rotation[1].x = sin(-angle);
            rotation[1].y = cos(-angle);
            rotation[2].z = 1;
            for(int i=0; i < (sizeof(vertices) / sizeof(GLfloat))-1; i = i+2){
                vec3 point = vec3(vertices[i], vertices[i+1], 1.0f);
                vec3 res = transpose(rotation) * point;
                vertices[i] = res.x;
                vertices[i+1] = res.y;
            }
        }

        lastTime = currentTime;
        cout << "FPS: " << 1 / deltaTime << endl;

    } while (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}
