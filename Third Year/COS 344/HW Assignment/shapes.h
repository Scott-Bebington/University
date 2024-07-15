#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "MathExceptions.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

struct Shape
{
    vec3 **vertices;
    vec3 *colors;
    Shape **shapes;
    int numShapes;

    float *coloursChange = new float[6]{
        0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f};

    // float *coloursChange = new float[6] {
    //     1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
    // };

    ~Shape();

    virtual void applyMatrix(mat4x4);
    virtual GLfloat *toVertexArray();
    virtual GLfloat *toColorArray();
    virtual int numPoints();

    virtual int numVertices();
    virtual int numColors();

    vec3 multiplyMatrixVector(mat4x4, vec4);
    vec3 multiplyColourVector(vec3, float);
    vec3 addVectors(vec3, vec3, vec3);
    vec3 subtractVectors(vec3, vec3, vec3);
    // vec3 addVectors(vec3, vec3);
};

struct Triangle : public Shape
{
    Triangle(vec3, vec3, vec3, vec3 = vec3(1.0f, 0.0f, 0.0f));
    int numVertices();
    int numColors();
    int numPoints();
};

struct Rectangle : public Shape
{
    Rectangle(vec3, vec3, vec3, vec3, vec3 = vec3(0.0f, 1.0f, 0.0f));
};

struct Box : public Shape
{
    Box(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
};

struct Boxes : public Shape
{
    Boxes(int numBoxes, vec3 *centers, double *heights, double *widths, double *lengths, vec3 *colors);
};

struct Pyramid : public Shape
{
    Pyramid(vec3 *vertices, vec3 color = vec3(0.0f, 0.0f, 1.0f));
};

class Cone : public Shape
{
public:
    Cone(vec3 center, int numSidesOnBase, float height, float radius, vec3 color = vec3(0.0f, 0.0f, 1.0f));
};

class Cylinder : public Shape
{
public:
    Cylinder();
    Cylinder(vec3 center, int numSidesOnBase, float height, float radius, vec3 color = vec3(0.0f, 0.0f, 1.0f));
    void Circles(vec3 center, int numSidesOnBase, float height, float radius, vec3 color = vec3(0.0f, 0.0f, 1.0f));
};

class Halfbox : public Shape
{
private:
    vec3 topPlane;
    vec3 bottomPlane;
    vec3 leftPlane;
    vec3 rightPlane;
    vec3 nearPlane;
    vec3 farPlane;

public:
    Halfbox(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f), string direction = "L");
    void halfboxBottomLeft(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxBottomRight(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxTopLeft(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxTopRight(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxTopFront(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxTopBack(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxBottomFront(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
    void halfboxBottomBack(vec3 center, double height, double width, double length, vec3 = vec3(1.0f, 0.2f, 0.2f));
};

// class ImageCube : public Shape
// {
// private:
//     vec3 center;
//     float width, height, length;
//     string texturePath;
//     vec4 color;
//     bool texturedFaces[6];

//     GLuint VAO, VBO, EBO;
//     GLuint textureID;

//     void initialize()
//     {
//         float halfWidth = width / 2.0f;
//         float halfHeight = height / 2.0f;
//         float halfLength = length / 2.0f;

//         float vertices[] = {
//             // Positions              // Texture Coords
//             -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
//             halfWidth, -halfHeight, -halfLength, 1.0f, 0.0f,
//             halfWidth, halfHeight, -halfLength, 1.0f, 1.0f,
//             -halfWidth, halfHeight, -halfLength, 0.0f, 1.0f,

//             -halfWidth, -halfHeight, halfLength, 0.0f, 0.0f,
//             halfWidth, -halfHeight, halfLength, 1.0f, 0.0f,
//             halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
//             -halfWidth, halfHeight, halfLength, 0.0f, 1.0f,

//             -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
//             -halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
//             -halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
//             -halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

//             halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
//             halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
//             halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
//             halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

//             -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
//             halfWidth, -halfHeight, -halfLength, 1.0f, 0.0f,
//             halfWidth, -halfHeight, halfLength, 1.0f, 1.0f,
//             -halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

//             -halfWidth, halfHeight, -halfLength, 0.0f, 0.0f,
//             halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
//             halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
//             -halfWidth, halfHeight, halfLength, 0.0f, 1.0f};

//         unsigned int indices[] = {
//             0, 1, 2, 2, 3, 0,       // Back face
//             4, 5, 6, 6, 7, 4,       // Front face
//             8, 9, 10, 10, 11, 8,    // Left face
//             12, 13, 14, 14, 15, 12, // Right face
//             16, 17, 18, 18, 19, 16, // Bottom face
//             20, 21, 22, 22, 23, 20  // Top face
//         };

//         // Generate and bind a VAO (Vertex Array Object)
//         glGenVertexArrays(1, &VAO);
//         glBindVertexArray(VAO);

//         // Create a VBO (Vertex Buffer Object) and upload the vertex data
//         glGenBuffers(1, &VBO);
//         glBindBuffer(GL_ARRAY_BUFFER, VBO);
//         glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//         // Create an EBO (Element Buffer Object) and upload the index data
//         glGenBuffers(1, &EBO);
//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//         glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//         // Define vertex attribute pointers
//         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
//         glEnableVertexAttribArray(0);
//         glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
//         glEnableVertexAttribArray(1);

//         // Load the texture
//         loadTexture();
//     }

//     void loadTexture()
//     {
//         int width, height, nrChannels;
//         stbi_set_flip_vertically_on_load(true);
//         unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
//         if (data)
//         {
//             glGenTextures(1, &textureID);
//             glBindTexture(GL_TEXTURE_2D, textureID);
//             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//             glGenerateMipmap(GL_TEXTURE_2D);
//             stbi_image_free(data);
//         }
//         else
//         {
//             cerr << "Failed to load texture" << endl;
//         }
//     }

// public:
//     ImageCube(vec3 center, float width, float height, float length, const string &texturePath, vec4 color, bool texturedFaces[6])
//         : center(center), width(width), height(height), length(length), texturePath(texturePath), color(color)
//     {
//         for (int i = 0; i < 6; ++i)
//         {
//             this->texturedFaces[i] = texturedFaces[i];
//         }
//         initialize();
//     }

//     ~ImageCube()
//     {
//         glDeleteVertexArrays(1, &VAO);
//         glDeleteBuffers(1, &VBO);
//         glDeleteBuffers(1, &EBO);
//         glDeleteTextures(1, &textureID);
//     }

//     void draw(GLuint shaderProgram, const mat4 &projection, const mat4 &view, float rotationX, float rotationY)
//     {
//         glUseProgram(shaderProgram);

//         // Update projection matrix
//         GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
//         glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, value_ptr(projection));

//         // Update view matrix
//         GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
//         glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, value_ptr(view));

//         // Update model matrix based on the center and user input
//         mat4 model = mat4(1.0f);
//         model = translate(model, center);
//         model = rotate(model, rotationX, vec3(1.0f, 0.0f, 0.0f));
//         model = rotate(model, rotationY, vec3(0.0f, 1.0f, 0.0f));
//         GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
//         glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, value_ptr(model));

//         // Set texture unit (assuming texture is bound to unit 0)
//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, textureID);
//         GLuint diffuseTextureLocation = glGetUniformLocation(shaderProgram, "diffuseTexture");
//         glUniform1i(diffuseTextureLocation, 0);

//         // Set the diffuse color uniform
//         GLuint diffuseColorLocation = glGetUniformLocation(shaderProgram, "diffuseColor");
//         // glUniform3fv(diffuseColorLocation, 1, value_ptr(color));
//         vec4 colorWithAlpha = vec4(0.0f, 0.0f, 0.1f, 0.5f); // Example RGBA color with alpha
//         glUniform4fv(diffuseColorLocation, 1, value_ptr(colorWithAlpha));

//         // Bind VAO
//         glBindVertexArray(VAO);

//         // Draw the cube
//         for (int i = 0; i < 6; ++i)
//         {
//             // if (texturedFaces[i])
//             // {
//             //     glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
//             // }
//             // else
//             // {
//             //     glDrawArrays(GL_TRIANGLE_FAN, 24 + i * 4, 4);
//             // }
//             glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
//             // glDrawArrays(GL_TRIANGLE_FAN, 24 + i * 4, 4);
//         }
//     }
// };

#endif /*SHAPES_H*/