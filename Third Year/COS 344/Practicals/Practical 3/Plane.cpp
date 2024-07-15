#include "Plane.h"

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
    Shape *shp1 = new Box(vec3(0, 0, 0), 0.2, 1.2, 0.2, brown);
    Shape *shp2 = new Box(vec3(-0.05, -0.05, 0), 0.1, 0.5, 0.2, brown);
    Shape *shp3 = new Halfbox(vec3(-0.1665, -0.05, 0), 0.1, 0.2, 0.2, brown, "BL");
    Shape *shp4 = new Halfbox(vec3(0.1165, -0.05, 0), 0.1, 0.5, 0.2, brown, "BR");

    // The window
    Shape *windowCenter = new Box(vec3(0, 0.05, 0), 0.1, 0.1, 0.1, lightblue);
    Shape *windowCenterLeft = new Halfbox(vec3(-0.0325, 0.05, 0), 0.1, 0.1, 0.1, lightblue, "TL");
    Shape *windowFrontLeft = new Pyramid(
        new vec3[5]{
            vec3(-0.0475, 0.2, -0.05), // Top
            vec3(-0.0475, 0.1, -0.05), // fr
            vec3(-0.0475, 0.1, -0.1),  // br
            vec3(-0.1475, 0.1, -0.1),  // bl
            vec3(-0.1475, 0.1, -0.05)  // fl
        },
        lightblue);
    Shape *windowBackLeft = new Pyramid(
        new vec3[5]{
            vec3(-0.0475, 0.2, 0.05), // Top
            vec3(-0.0475, 0.1, 0.05), // fr
            vec3(-0.0475, 0.1, 0.1),  // br
            vec3(-0.1475, 0.1, 0.1),  // bl
            vec3(-0.1475, 0.1, 0.05)  // fl
        },
        lightblue);
    Shape *windowFront = new Halfbox(vec3(0.0, 0.05, -0.025), 0.1, 0.1, 0.05, lightblue, "TF");
    Shape *windowBack = new Halfbox(vec3(0.0, 0.05, 0.025), 0.1, 0.1, 0.05, lightblue, "TB");

    // Behind the window
    Shape *behindWindow = new Halfbox(vec3(0.0825, 0.05, 0), 0.1, 0.4, 0.1, sand, "TR");
    Shape *behindWindowFront = new Pyramid(
        new vec3[5]{
            vec3(0.0475, 0.2, -0.05), // Top
            vec3(0.0475, 0.1, -0.05), // fl
            vec3(0.0475, 0.1, -0.1),  // bl
            vec3(0.1475, 0.1, -0.1),  // br
            vec3(0.4375, 0.1, -0.05)  // fr
        },
        sand);
    Shape *behindWindowBack = new Pyramid(
        new vec3[5]{
            vec3(0.0475, 0.2, 0.05), // Top
            vec3(0.0475, 0.1, 0.05), // fl
            vec3(0.0475, 0.1, 0.1),  // bl
            vec3(0.1475, 0.1, 0.1),  // br
            vec3(0.4375, 0.1, 0.05)  // fr
        },
        sand);

    // aileron left
    Shape *aileronLeft = new Halfbox(vec3(0.15, 0.05, 0), 0.3, 0.15, 0.02, brown, "TL");
    Shape *aileronCenter = new Box(vec3(0.18325, 0.05825, 0), 0.15, 0.05, 0.02, brown);
    Shape *aileronTopRight = new Halfbox(vec3(0.1875, 0.09125, 0), 0.05, 0.075, 0.02, brown, "TR");
    Shape *aileronCenterRight = new Box(vec3(0.1956, 0.05825, 0), 0.15, 0.025, 0.02, darkgreen);

    // Front wing
    Shape *frontWingLeft = new Pyramid(
        new vec3[5]{
            vec3(-0.3, -0.1, -0.8), // Top
            vec3(-0.3, -0.1, -0.1), // bl
            vec3(-0.3, -0.2, -0.1), // tl
            vec3(-0.4, -0.2, -0.1), // tr
            vec3(-0.4, -0.1, -0.1)  // br
        },
        darkgreen);
    Shape *frontWingCenter = new Halfbox(vec3(-0.05825, -0.05, -0.15), 0.1, 0.25, 0.7, darkgreen, "BF");
    Shape *frontWingRight = new Pyramid(
        new vec3[5]{
            vec3(-0.05, -0.1, -0.8), // Top
            vec3(-0.05, -0.1, -0.1), // br
            vec3(-0.05, -0.2, -0.1), // tr
            vec3(0.1, -0.2, -0.1),   // tl
            vec3(0.1, -0.1, -0.1)    // bl
        },
        darkgreen);

    // Back wing
    Shape *backWingLeft = new Pyramid(
        new vec3[5]{
            vec3(-0.3, -0.1, 0.8), // Top
            vec3(-0.3, -0.1, 0.1), // bl
            vec3(-0.3, -0.2, 0.1), // tl
            vec3(-0.4, -0.2, 0.1), // tr
            vec3(-0.4, -0.1, 0.1)  // br
        },
        darkgreen);
    Shape *backWingCenter = new Halfbox(vec3(-0.05825, -0.05, 0.15), 0.1, 0.25, 0.7, darkgreen, "BB");
    Shape *backWingRight = new Pyramid(
        new vec3[5]{
            vec3(-0.05, -0.1, 0.8), // Top
            vec3(-0.05, -0.1, 0.1), // br
            vec3(-0.05, -0.2, 0.1), // tr
            vec3(0.1, -0.2, 0.1),   // tl
            vec3(0.1, -0.1, 0.1)    // bl
        },
        darkgreen);

    // Rear wing front
    Shape *rearWingFrontLeft = new Pyramid(
        new vec3[5]{
            vec3(0.45, 0.05, -0.3), // Top
            vec3(0.4, 0.05, -0.1),  // bl
            vec3(0.4, 0.03, -0.1),  // tl
            vec3(0.45, 0.03, -0.1), // tr
            vec3(0.45, 0.05, -0.1)  // br
        },
        darkgreen);
    Shape *rearWingFrontCenter = new Halfbox(vec3(0.16175, 0.0135, -0.0667), 0.02, 0.075, 0.2, darkgreen, "BF");
    Shape *rearWingFrontRight = new Pyramid(
        new vec3[5]{
            vec3(0.5225, 0.05, -0.3), // Top
            vec3(0.5225, 0.05, -0.1), // br
            vec3(0.5225, 0.03, -0.1), // tr
            vec3(0.575, 0.03, -0.1),  // bl
            vec3(0.575, 0.05, -0.1)   // tl
        },
        sand);

    // Rear wing back
    Shape *rearWingBackLeft = new Pyramid(
        new vec3[5]{
            vec3(0.45, 0.05, 0.3), // Top
            vec3(0.4, 0.05, 0.1),  // bl
            vec3(0.4, 0.03, 0.1),  // tl
            vec3(0.45, 0.03, 0.1), // tr
            vec3(0.45, 0.05, 0.1)  // br
        },
        darkgreen);
    Shape *rearWingBackCenter = new Halfbox(vec3(0.16175, 0.0135, 0.0667), 0.02, 0.075, 0.2, darkgreen, "BB");
    Shape *rearWingBackRight = new Pyramid(
        new vec3[5]{
            vec3(0.5225, 0.05, 0.3), // Top
            vec3(0.5225, 0.05, 0.1), // br
            vec3(0.5225, 0.03, 0.1), // tr
            vec3(0.575, 0.03, 0.1),  // bl
            vec3(0.575, 0.05, 0.1)   // tl
        },
        sand);

    // Propeller
    Shape *cone = new Cone(vec3(-0.6, 0, 0), 50, 0.1, 0.1, black);
    Shape *verticalPropeller = new Box(vec3(-0.2125, 0, 0), 0.5, 0.02, 0.02, black);
    Shape *horizontalPropeller = new Box(vec3(-0.2125, 0, 0), 0.02, 0.02, 0.5, black);

    // Back Wheel
    Shape *backWheelSupport = new Pyramid(
        new vec3[5]{
            vec3(-0.25, -0.3, 0.1),  // Top
            vec3(-0.25, -0.2, 0.05), // fr
            vec3(-0.25, -0.2, 0.1),  // br
            vec3(-0.3, -0.2, 0.1),   // bl
            vec3(-0.3, -0.2, 0.05)   // fl
        },
        white);
    Shape *backWheel = new Cylinder(vec3(-0.26, -0.3, 0.125), 50, 0.05, 0.05, black);
    Cylinder *backWheelCircle = new Cylinder();
    backWheelCircle->Circles(vec3(-0.26, -0.3, 0.125), 50, 0.05, 0.05, black);

    // Front Wheel
    Shape *frontWheelSupport = new Pyramid(
        new vec3[5]{
            vec3(-0.25, -0.3, -0.1),  // Top
            vec3(-0.25, -0.2, -0.05), // fr
            vec3(-0.25, -0.2, -0.1),  // br
            vec3(-0.3, -0.2, -0.1),   // bl
            vec3(-0.3, -0.2, -0.05)   // fl
        },
        white);
    Shape *frontWheel = new Cylinder(vec3(-0.26, -0.3, -0.125), 50, 0.05, 0.05, black);
    Cylinder *frontWheelCircle = new Cylinder();
    frontWheelCircle->Circles(vec3(-0.26, -0.3, -0.125), 50, 0.05, 0.05, black);

    // Rear Wheel
    Shape *rearWheelSupport = new Pyramid(
        new vec3[5]{
            vec3(0.55, -0.2, 0.025), // Top
            vec3(0.5, -0.1, 0.025),  // fr
            vec3(0.5, -0.1, 0.075),  // br
            vec3(0.55, -0.1, 0.075), // bl
            vec3(0.55, -0.1, 0.025)  // fl
        },
        white);
    Shape *rearWheel = new Cylinder(vec3(0.55, -0.2, 0), 50, 0.05, 0.05, black);
    Cylinder *rearWheelCircle = new Cylinder();
    rearWheelCircle->Circles(vec3(0.55, -0.2, 0), 50, 0.05, 0.05, black);

    shapes[0] = shp1;
    shapes[1] = shp2;
    shapes[2] = shp3;
    shapes[3] = shp4;
    shapes[4] = windowCenter;
    shapes[5] = windowCenterLeft;
    shapes[6] = windowFrontLeft;
    shapes[7] = windowBackLeft;
    shapes[8] = windowFront;
    shapes[9] = windowBack;
    shapes[10] = behindWindow;
    shapes[11] = behindWindowFront;
    shapes[12] = behindWindowBack;
    shapes[13] = aileronLeft;
    shapes[14] = aileronCenter;
    shapes[15] = aileronTopRight;
    shapes[16] = aileronCenterRight;
    shapes[17] = frontWingLeft;
    shapes[18] = frontWingCenter;
    shapes[19] = frontWingRight;
    shapes[20] = backWingLeft;
    shapes[21] = backWingCenter;
    shapes[22] = backWingRight;
    shapes[23] = rearWingFrontLeft;
    shapes[24] = rearWingFrontCenter;
    shapes[25] = rearWingFrontRight;
    shapes[26] = rearWingBackLeft;
    shapes[27] = rearWingBackCenter;
    shapes[28] = rearWingBackRight;
    shapes[29] = cone;
    shapes[30] = verticalPropeller;
    shapes[31] = horizontalPropeller;
    shapes[32] = backWheelSupport;
    shapes[33] = backWheel;
    shapes[34] = backWheelCircle;
    shapes[35] = frontWheelSupport;
    shapes[36] = frontWheel;
    shapes[37] = frontWheelCircle;
    shapes[38] = rearWheelSupport;
    shapes[39] = rearWheel;
    shapes[40] = rearWheelCircle;
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

void Plane::rotateArbitraryAngle(float RotationDegree, int num) {


}