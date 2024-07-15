#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "stb_image.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace std;
using namespace glm;

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 vertexPosition;\n"
    "layout (location = 1) in vec2 vertexUV;\n"
    "out vec2 UV;\n"
    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 viewMatrix;\n"
    "uniform mat4 modelMatrix;\n"
    "void main() {\n"
    "  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1.0);\n"
    "  UV = vertexUV;\n"
    "}\n";

const char *fragmentShaderSource =
    "#version 330 core\n"
    "in vec2 UV;\n"
    "out vec4 FragColor;\n"
    "uniform sampler2D diffuseTexture;\n"
    "void main() {\n"
    "  FragColor = texture(diffuseTexture, UV);\n"
    "}\n";

class Cube
{
public:
    Cube(vec3 center, float width, float height, float length, const string &texturePath, vec4 color, bool texturedFaces[6])
        : center(center), width(width), height(height), length(length), texturePath(texturePath), color(color)
    {
        for (int i = 0; i < 6; ++i)
        {
            this->texturedFaces[i] = texturedFaces[i];
        }
        initialize();
    }

    ~Cube()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteTextures(1, &textureID);
    }

    void draw(GLuint shaderProgram, const mat4 &projection, const mat4 &view, float rotationX, float rotationY)
    {
        glUseProgram(shaderProgram);

        // Update projection matrix
        GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
        glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, value_ptr(projection));

        // Update view matrix
        GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, value_ptr(view));

        // Update model matrix based on the center and user input
        mat4 model = mat4(1.0f);
        model = translate(model, center);
        model = rotate(model, rotationX, vec3(1.0f, 0.0f, 0.0f));
        model = rotate(model, rotationY, vec3(0.0f, 1.0f, 0.0f));
        GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, value_ptr(model));

        // Set texture unit (assuming texture is bound to unit 0)
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        GLuint diffuseTextureLocation = glGetUniformLocation(shaderProgram, "diffuseTexture");
        glUniform1i(diffuseTextureLocation, 0);

        // Set the diffuse color uniform
        GLuint diffuseColorLocation = glGetUniformLocation(shaderProgram, "diffuseColor");
        // glUniform3fv(diffuseColorLocation, 1, value_ptr(color));
        vec4 colorWithAlpha = vec4(0.0f, 0.0f, 0.1f, 0.5f); // Example RGBA color with alpha
        glUniform4fv(diffuseColorLocation, 1, value_ptr(colorWithAlpha));

        // Bind VAO
        glBindVertexArray(VAO);

        // Draw the cube
        for (int i = 0; i < 6; ++i)
        {
            glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
        }
    }

private:
    vec3 center;
    float width, height, length;
    string texturePath;
    vec4 color;
    bool texturedFaces[6];

    GLuint VAO, VBO, EBO;
    GLuint textureID;

    void initialize()
    {
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;
        float halfLength = length / 2.0f;

        float vertices[] = {
            // Positions              // Texture Coords
            -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
            halfWidth, -halfHeight, -halfLength, 1.0f, 0.0f,
            halfWidth, halfHeight, -halfLength, 1.0f, 1.0f,
            -halfWidth, halfHeight, -halfLength, 0.0f, 1.0f,

            -halfWidth, -halfHeight, halfLength, 0.0f, 0.0f,
            halfWidth, -halfHeight, halfLength, 1.0f, 0.0f,
            halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
            -halfWidth, halfHeight, halfLength, 0.0f, 1.0f,

            -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
            -halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
            -halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
            -halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

            halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
            halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
            halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
            halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

            -halfWidth, -halfHeight, -halfLength, 0.0f, 0.0f,
            halfWidth, -halfHeight, -halfLength, 1.0f, 0.0f,
            halfWidth, -halfHeight, halfLength, 1.0f, 1.0f,
            -halfWidth, -halfHeight, halfLength, 0.0f, 1.0f,

            -halfWidth, halfHeight, -halfLength, 0.0f, 0.0f,
            halfWidth, halfHeight, -halfLength, 1.0f, 0.0f,
            halfWidth, halfHeight, halfLength, 1.0f, 1.0f,
            -halfWidth, halfHeight, halfLength, 0.0f, 1.0f};

        unsigned int indices[] = {
            0, 1, 2, 2, 3, 0,       // Back face
            4, 5, 6, 6, 7, 4,       // Front face
            8, 9, 10, 10, 11, 8,    // Left face
            12, 13, 14, 14, 15, 12, // Right face
            16, 17, 18, 18, 19, 16, // Bottom face
            20, 21, 22, 22, 23, 20  // Top face
        };

        // Generate and bind a VAO (Vertex Array Object)
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        // Create a VBO (Vertex Buffer Object) and upload the vertex data
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Create an EBO (Element Buffer Object) and upload the index data
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Define vertex attribute pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Load the texture
        loadTexture();
    }

    void loadTexture()
    {
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glGenTextures(1, &textureID);
            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(data);
        }
        else
        {
            cerr << "Failed to load texture" << endl;
        }
    }
};

// Shader source code remains the same as in the original code

GLuint compileShaders()
{
    // Compile vertex and fragment shaders
    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Link shaders to create a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Clean up shaders (no longer needed after linking)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{

    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Textured Cube", NULL, NULL);
    if (window == NULL)
    {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load GLAD for OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Create and load resources (shaders, textures, etc.)
    GLuint shaderProgram = compileShaders();

    // Define view matrix (looking at the origin from a distance)
    mat4 view = lookAt(vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

    bool texturedFaces[6] = {true, false, false, false, false, true};
    // Create a cube instance
    Cube cube = Cube(vec3(0.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f, "adobetexture.jpg", vec4(0.0f, 0.0f, 0.1f, 0.5f), texturedFaces);

    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // Process input
        processInput(window);

        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Enable blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Update projection matrix with perspective correction
        mat4 projection = perspective(radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);

        // Update model matrix based on user input
        // float rotationX = radians((float)glfwGetTime() * 50.0f);
        // float rotationY = radians((float)glfwGetTime() * 30.0f);

        float rotationX = 0.0f;
        float rotationY = 0.0f;

        // Draw the cube
        cube.draw(shaderProgram, projection, view, rotationX, rotationY);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}
