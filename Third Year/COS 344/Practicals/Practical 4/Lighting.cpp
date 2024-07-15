#include "Lighting.h"

Lighting::Lighting(int Size)
{
    cout << "Creating Plane 1" << endl;
    this->numShapes = Size;
    this->shapes = new Shape *[Size];
    this->currentXPos = 0;
    this->currentYPos = 0;
    this->currentZPos = 0;
    this->wireframe = false;
}

Lighting::~Lighting()
{
    for (int i = 0; i < this->numShapes; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;
}

void Lighting::CreateSheets()
{
    Shape *shp1 = new Triangle(
        vec3(-0.5, -0.5, 0), 
        vec3(0.5, -0.5, 0), 
        vec3(0.0, 0.5, 0), 
        vec4(1.0f, 0.0f, 0.0f, 0.5f));

    Shape *shp2 = new Triangle(
        vec3(-1, -1, 0.5), 
        vec3(1, -1, 0.5), 
        vec3(0.0, 1, 0.5), 
        vec4(0.0f, 1.0f, 0.0f, 1.0f));
    
    shapes[0] = shp1;
    shapes[1] = shp2;

}

void Lighting::DrawSheets(Shape *shp)
{
    // Here we create two VBOs
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    GLfloat *vertices = shp->toVertexArray();
    GLfloat *colors = shp->toColorArray();

    cout << "Colours: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << colors[i * 4 + j] << " ";
        }
        cout << endl;
    }
    

    cout << endl;

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
        1,           // location 1 in the vertex shader.
        4,           // size (including the A value)
        GL_FLOAT,    // type
        GL_FALSE,    // normalized?
        0,           // stride
        (void *)0    // array buffer offset
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

void Lighting::RotateX(float angle)
{
    // this->currentXRot += angle;
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

void Lighting::RotateY(float angle)
{
    // this->currentYRot += angle;
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

void Lighting::RotateZ(float angle)
{
    // this->currentZRot += angle;
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

void Lighting::TranslateX(float distance)
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

void Lighting::TranslateY(float distance)
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



void Lighting::TranslateZ(float distance)
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

void Lighting::MoveToOrigin()
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

void Lighting::MoveBack()
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

void Lighting::ToggleWireframe()
{
    wireframe = !wireframe;
}

mat4x4 Lighting::Transpose(mat4x4 matrix)
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

void Lighting::Scale(float factor)
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

void Lighting::rotateArbitraryAngle(float RotationDegree, int num) {


}