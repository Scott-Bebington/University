#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "shapes.h"
#include "Car.h"

using namespace std;

const char *getError()
{
  const char *errorDescription;
  glfwGetError(&errorDescription);
  return errorDescription;
}

inline GLFWwindow *setUp(int width = 900, int height = 900)
{
  glewExperimental = true; // Needed for core profile
  if (!glfwInit())
  {
    throw getError();
  }
  glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE,
                 GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
  GLFWwindow *window;                       // (In the accompanying source code, this variable is
                                            // global for simplicity)
  window = glfwCreateWindow(width, height, "u21546216 Practical 2", NULL, NULL);
  if (window == NULL)
  {
    cout << getError() << endl;
    glfwTerminate();
    throw "Failed to open GLFW window. If you have an Intel GPU, they are not "
          "3.3 compatible. Try the 2.1 version of the tutorials.\n";
  }
  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental = true;        // Needed in core profile
  if (glewInit() != GLEW_OK)
  {
    glfwTerminate();
    throw getError();
  }
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Set clear color to green for grass
  return window;
}


int main()
{
  GLFWwindow *window = setUp();
  GLuint programID = LoadShaders("vertex.glsl", "fragment.glsl");

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(programID);

  Car car = Car();
  car.createCar();

  // Check for errors
  GLenum error = glGetError();
  if (error != GL_NO_ERROR)
  {
    std::cerr << "OpenGL error: " << error << std::endl;
  }
  bool spacePressed = false;
  do
  {
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
      car.moveDown();
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
      car.moveUp();
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
      car.moveRight();
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
      car.moveLeft();
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS && !spacePressed)
    {
      car.toggleWireframe();
      spacePressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_RELEASE)
    {
      spacePressed = false;
    }

    car.rotateWheels();

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}