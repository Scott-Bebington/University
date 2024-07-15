#include "Plane.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Plane::Plane(int Size)
{
    cout << "Creating Plane 1" << endl;
    this->numShapes = Size;
    this->shapes = new Shape *[Size];
    this->currentXPos = 0;
    this->currentYPos = 0;
    this->currentZPos = 0;
    this->currentXRot = 0;
    this->currentYRot = 0;
    this->currentZRot = 0;
    this->wireframe = false;
}

Plane::~Plane()
{
    for (int i = 0; i < this->numShapes; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;
}

void Plane::CreatePlane()
{
    bool texturedFaces[6] = {true, false, false, false, false, true};
    // Shape *cube = new ImageCube(vec3(0.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f, "adobetexture.jpg", vec4(0.0f, 0.0f, 0.1f, 0.5f), texturedFaces);
    // Shape *shp1 = new Box(vec3(0.2, 0, 0.0), 0.8, 0.5, 1.0, sand);
    // Shape *shp2 = new Box(vec3(-0.2, 0, 0.0), 0.8, 0.5, 1.0, sand);
    // Shape *windowCenterLeft = new Halfbox(vec3(-0.0325, 0.05, 0), 0.1, 0.1, 0.1, lightblue, "TL");
    // shapes[0] = shp1;
    // shapes[1] = shp2;
    // shapes[2] = windowCenterLeft;
}

void Plane::DrawImageCube(Shape *shp, string imagename, string sides)
{

    // Indices for drawing the rectangle (cube)
    GLuint indices[] = {
        0, 1, 2, 2, 3, 0,       // Back face
        4, 5, 6, 6, 7, 4,       // Front face
        8, 9, 10, 10, 11, 8,    // Left face
        12, 13, 14, 14, 15, 12, // Right face
        16, 17, 18, 18, 19, 16, // Bottom face
        20, 21, 22, 22, 23, 20  // Top face
    };

    GLfloat *vertices = shp->toVertexArray();

    GLfloat FrontFace[] = {
        vertices[6], vertices[7], vertices[8], 0.0f, 0.0f,    // Bottom-left
        vertices[12], vertices[13], vertices[14], 1.0f, 0.0f, // Bottom-right
        vertices[15], vertices[16], vertices[17], 1.0f, 1.0f, // Top-right
        vertices[3], vertices[4], vertices[5], 0.0f, 1.0f     // Top-left
    };

    GLfloat BackFace[] = {
        vertices[30], vertices[31], vertices[32], 1.0f, 1.0f, // Bottom-left
        vertices[24], vertices[25], vertices[26], 0.0f, 1.0f, // Bottom-right
        vertices[21], vertices[22], vertices[23], 0.0f, 0.0f, // Top-right
        vertices[33], vertices[34], vertices[35], 1.0f, 0.0f  // Top-left
    };

    GLfloat LeftFace[] = {
        vertices[51], vertices[52], vertices[53], 1.0f, 0.0f, // Top-right
        vertices[39], vertices[40], vertices[41], 0.0f, 0.0f, // Top-left
        vertices[42], vertices[43], vertices[44], 0.0f, 1.0f, // Bottom-left
        vertices[48], vertices[49], vertices[50], 1.0f, 1.0f  // Bottom-right
    };

    GLfloat RightFace[] = {
        vertices[69], vertices[70], vertices[71], 1.0f, 0.0f, // Top-left
        vertices[57], vertices[58], vertices[59], 0.0f, 0.0f, // Top-right
        vertices[60], vertices[61], vertices[62], 0.0f, 1.0f, // Bottom-right
        vertices[66], vertices[67], vertices[68], 1.0f, 1.0f  // Bottom-left
    };

    GLfloat BottomFace[] = {
        vertices[87], vertices[88], vertices[89], 1.0f, 0.0f, // Top-right
        vertices[75], vertices[76], vertices[77], 0.0f, 0.0f, // Top-left
        vertices[78], vertices[79], vertices[80], 0.0f, 1.0f, // Bottom-left
        vertices[84], vertices[85], vertices[86], 1.0f, 1.0f  // Bottom-right
    };

    GLfloat TopFace[] = {
        vertices[105], vertices[106], vertices[107], 1.0f, 0.0f, // Top-left
        vertices[93], vertices[94], vertices[95], 0.0f, 0.0f,   // Top-right
        vertices[96], vertices[97], vertices[98], 0.0f, 1.0f,   // Bottom-right
        vertices[102], vertices[103], vertices[104], 1.0f, 1.0f // Bottom-left
    };

    // get the length of the sides string
    int length = sides.length() * 20;
    GLfloat newVertices[length];

    // sides string may contain any combination of the following characters: F, N, L, R, T, B
    // N = Front face, F = Back face, L = Left face, R = Right face, T = Top face, B = Bottom face
    for (int i = 0; i < sides.length(); i++)
    {
        switch (sides[i])
        {
        case 'N':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = FrontFace[j];
            }
            break;
        case 'F':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = BackFace[j];
            }
            break;
        case 'L':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = LeftFace[j];
            }
            break;
        case 'R':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = RightFace[j];
            }
            break;
        case 'T':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = TopFace[j];
            }
            break;
        case 'B':
            for (int j = 0; j < 20; j++)
            {
                newVertices[i * 20 + j] = BottomFace[j];
            }
            break;
        default:
            break;
        }
    }

    // Generate texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Load image using stb_image
    int width, height, nrChannels;
    unsigned char *data = stbi_load(imagename.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        // Flip image vertically
        stbi_set_flip_vertically_on_load(true);

        // Upload image data to the texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        cout << "Failed to load texture" << endl;
    }
    stbi_image_free(data);

    // Create VAO, VBO, EBO
    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind VBO and copy data to GPU
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(newVertices), newVertices, GL_STATIC_DRAW);

    // Bind EBO and copy data to GPU
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Set attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent unwanted changes)
    glBindVertexArray(0);

    // Generate texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Draw the shape
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

}

void Plane::DrawPlane(Shape *shp)
{
    // Here we create two VBOs
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    GLfloat *vertices = shp->toVertexArray();
    GLfloat *colors = shp->toColorArray();

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numVertices()]), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[shp->numColors()]), colors, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,        // location 0 in the vertex shader.
        3,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void *)0 // array buffer offset
    );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,        // location 1 in the vertex shader.
        3,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void *)0 // array buffer offset
    );

    if (wireframe)
    {
        glDrawArrays(GL_LINE_LOOP, 0, shp->numPoints()); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, shp->numPoints()); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Plane::RotateX(float angle)
{
    this->currentXRot += angle;
    this->MoveToOrigin();

    mat4x4 rotationX = mat4x4(0.0f);

    rotationX[0].x = 1;
    rotationX[1].y = cos(angle);
    rotationX[1].z = -sin(angle);
    rotationX[2].y = sin(angle);
    rotationX[2].z = cos(angle);
    rotationX[3].w = 1;

    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(rotationX));
    }

    this->MoveBack();
}

void Plane::RotateY(float angle)
{
    this->currentYRot += angle;
    this->MoveToOrigin();

    mat4x4 rotationY = mat4x4(0.0f);

    rotationY[0].x = cos(angle);
    rotationY[0].z = -sin(angle);
    rotationY[1].y = 1;
    rotationY[2].x = sin(angle);
    rotationY[2].z = cos(angle);
    rotationY[3].w = 1;

    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(rotationY));
    }

    this->MoveBack();
}

void Plane::RotateZ(float angle)
{
    this->currentZRot += angle;
    this->MoveToOrigin();

    mat4x4 rotationZ = mat4x4(0.0f);

    rotationZ[0].x = cos(angle);
    rotationZ[0].y = -sin(angle);
    rotationZ[1].x = sin(angle);
    rotationZ[1].y = cos(angle);
    rotationZ[2].z = 1;
    rotationZ[3].w = 1;

    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(rotationZ));
    }

    this->MoveBack();
}

void Plane::TranslateX(float distance)
{
    mat4x4 translationX = mat4x4(0.0f);

    translationX[0].x = 1;
    translationX[1].y = 1;
    translationX[2].z = 1;
    translationX[0].w = distance;
    translationX[3].w = 1;
    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(translationX));
    }
    currentXPos += 0.01;
}

void Plane::TranslateY(float distance)
{
    mat4x4 translationY = mat4x4(0.0f);

    translationY[0].x = 1;
    translationY[1].y = 1;
    translationY[2].z = 1;
    translationY[1].w = distance;
    translationY[3].w = 1;
    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(translationY));
    }
    currentYPos += 0.01;
}

void Plane::TranslateZ(float distance)
{
    mat4x4 translationZ = mat4x4(0.0f);

    translationZ[0].x = 1;
    translationZ[1].y = 1;
    translationZ[2].z = 1;
    translationZ[2].w = distance;
    translationZ[3].w = 1;
    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(translationZ));
    }
    currentZPos -= 0.01;
}

void Plane::MoveToOrigin()
{
    mat4x4 translationToOrigin = mat4x4(0.0f);

    translationToOrigin[0].x = 1;
    translationToOrigin[0].w = -currentXPos;
    translationToOrigin[1].y = 1;
    translationToOrigin[1].w = -currentYPos;
    translationToOrigin[2].z = 1;
    translationToOrigin[2].w = -currentZPos;
    translationToOrigin[3].w = 1;
    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(translationToOrigin));
    }
}

void Plane::MoveBack()
{
    mat4x4 translationBack = mat4x4(0.0f);

    translationBack[0].x = 1;
    translationBack[0].w = currentXPos;
    translationBack[1].y = 1;
    translationBack[1].w = currentYPos;
    translationBack[2].z = 1;
    translationBack[2].w = currentZPos;
    translationBack[3].w = 1;
    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(translationBack));
    }
}

void Plane::ToggleWireframe()
{
    wireframe = !wireframe;
}

mat4x4 Plane::Transpose(mat4x4 matrix)
{
    mat4x4 transposedMatrix;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
}

void Plane::Scale(float factor)
{
    mat4x4 scale = mat4x4(0.0f);

    scale[0].x = factor;
    scale[1].y = factor;
    scale[2].z = factor;
    scale[3].w = 1;

    for (int i = 0; i < this->numShapes; i++)
    {
        shapes[i]->applyMatrix(this->Transpose(scale));
    }
}
