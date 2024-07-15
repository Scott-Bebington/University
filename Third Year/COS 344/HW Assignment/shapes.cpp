#include "shapes.h"

Shape::~Shape()
{
}

int Shape::numPoints()
{
    int count = 0;
    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numPoints();
    }
    return count;
}

GLfloat *Shape::toVertexArray()
{
    int n = numVertices();
    GLfloat *result = new GLfloat[numVertices()];
    if (numShapes > 0)
    {
        int count = 0;
        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toVertexArray();
            for (int j = 0; j < shapes[i]->numVertices(); j++)
            {
                result[count++] = temp[j];
            }
            delete[] temp;
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < numPoints(); i++)
        {
            result[count++] = (*vertices[i])[0];
            result[count++] = (*vertices[i])[1];
            result[count++] = (*vertices[i])[2];
        }
    }

    return result;
}

GLfloat *Shape::toColorArray()
{
    GLfloat *result = new GLfloat[numColors()];
    if (numShapes > 0)
    {
        int count = 0;
        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toColorArray();
            for (int j = 0; j < shapes[i]->numColors(); j++)
            {
                result[count++] = temp[j];
            }
            delete[] temp;
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < numPoints(); i++)
        {
            result[count++] = colors[i][0];
            result[count++] = colors[i][1];
            result[count++] = colors[i][2];
        }
    }
    return result;
}

void Shape::applyMatrix(mat4x4 m)
{
    if (numShapes > 0)
    {
        for (int i = 0; i < numShapes; i++)
        {
            shapes[i]->applyMatrix(m);
        }
    }
    else
    {
        for (int i = 0; i < numPoints(); i++)
        {
            vec4 temp = vec4((*vertices[i]), 1);
            vec3 result = multiplyMatrixVector(m, temp);
            (*vertices[i]) = result;
        }
    }
}

vec3 Shape::multiplyMatrixVector(mat4x4 m, vec4 v)
{
    vec4 result;

    for (int i = 0; i < 4; i++)
    {
        result[i] = 0;
        for (int j = 0; j < 4; j++)
        {
            result[i] += (v[j] * m[j][i]);
        }
    }
    return vec3(result);
}

vec3 Shape::multiplyColourVector(vec3 v, float f)
{

    return vec3(v[0] * f, v[1] * f, v[2] * f);
}

vec3 Shape::addVectors(vec3 v1, vec3 v2, vec3 v3)
{
    return vec3(v1[0] + v2[0] + v3[0], v1[1] + v2[1] + v3[1], v1[2] + v2[2] + v3[2]);
}

vec3 Shape::subtractVectors(vec3 v1, vec3 v2, vec3 v3)
{
    return vec3(v1[0] - v2[0] - v3[0], v1[1] - v2[1] - v3[1], v1[2] - v2[2] - v3[2]);
}

int Shape::numVertices()
{
    int count = 0;
    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numVertices();
    }
    return count;
}

int Shape::numColors()
{
    int count = 0;
    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numColors();
    }
    return count;
}

Triangle::Triangle(vec3 point1, vec3 point2, vec3 point3, vec3 color)
{
    numShapes = 0;
    shapes = new Shape *[0];

    int n = numPoints();
    vertices = new vec3 *[n];
    vertices[0] = new vec3(point1);
    vertices[1] = new vec3(point2);
    vertices[2] = new vec3(point3);

    colors = new vec3[n];
    for (int i = 0; i < 3; i++)
    {
        colors[i] = color;
    }
}

int Triangle::numVertices()
{
    return 9;
}

int Triangle::numColors()
{
    return 9;
}

int Triangle::numPoints()
{
    return 3;
}

Rectangle::Rectangle(vec3 ul, vec3 ur, vec3 ll, vec3 lr, vec3 color)
{
    numShapes = 2;
    shapes = new Shape *[numShapes];
    shapes[0] = new Triangle(ur, ul, ll, color);
    shapes[1] = new Triangle(ll, lr, ur, color);
    int n = numPoints();
    vertices = new vec3 *[n];
    int count = 0;
    for (int i = 0; i < numShapes; i++)
    {
        for (int j = 0; j < shapes[i]->numPoints(); j++)
        {
            vertices[count++] = shapes[i]->vertices[j];
        }
    }

    colors = new vec3[n];

    for (int i = 0; i < n; i++)
    {
        colors[i] = color;
    }
}

Box::Box(vec3 center, double height, double width, double length, vec3 color)
{
    vec3 topPlane = this->addVectors(center, vec3(0, height / 2, 0), vec3(0, 0, 0));
    vec3 bottomPlane = this->subtractVectors(center, vec3(0, height / 2, 0), vec3(0, 0, 0));
    vec3 leftPlane = this->subtractVectors(center, vec3(width / 2, 0, 0), vec3(0, 0, 0));
    vec3 rightPlane = this->addVectors(center, vec3(width / 2, 0, 0), vec3(0, 0, 0));
    vec3 nearPlane = this->subtractVectors(center, vec3(0, 0, length / 2), vec3(0, 0, 0));
    vec3 farPlane = this->addVectors(center, vec3(0, 0, length / 2), vec3(0, 0, 0));

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Rectangle *front = new Rectangle(nearLeftTop, nearRightTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Rectangle *back = new Rectangle(farRightTop, farLeftTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Rectangle *left = new Rectangle(farLeftTop, nearLeftTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Rectangle *right = new Rectangle(nearRightTop, farRightTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));
    Rectangle *top = new Rectangle(nearLeftTop, nearRightTop, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[5]));

    numShapes = 6;
    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom, top
    };
}

Boxes::Boxes(int numBoxes, vec3 *centers, double *heights, double *widths, double *lengths, vec3 *colors)
{
    numShapes = numBoxes;
    shapes = new Shape *[numShapes];
    for (int i = 0; i < numShapes; i++)
    {
        shapes[i] = new Box(centers[i], heights[i], widths[i], lengths[i], colors[i]);
    }
}

Pyramid::Pyramid(vec3 *vertices, vec3 color)
{
    // The first vertice is the top of the pyramid.
    vec3 top = vertices[0];
    // The rest of the vertices are the base of the pyramid.

    // Create the rectangle: nearLeft, nearRight, farLeft, farRight
    Rectangle *base = new Rectangle(vertices[1], vertices[2], vertices[4], vertices[3], this->multiplyColourVector(color, coloursChange[4]));

    // Create the triangles for the sides of the pyramid
    numShapes = 5;
    shapes = new Shape *[numShapes];
    shapes[0] = new Triangle(top, vertices[1], vertices[2], this->multiplyColourVector(color, coloursChange[2])); // left facing
    shapes[1] = new Triangle(top, vertices[2], vertices[3], this->multiplyColourVector(color, coloursChange[0])); // front facing
    shapes[2] = new Triangle(top, vertices[3], vertices[4], this->multiplyColourVector(color, coloursChange[3])); // right facing
    shapes[3] = new Triangle(top, vertices[4], vertices[1], this->multiplyColourVector(color, coloursChange[1])); // back facing
    shapes[4] = base;
}

Halfbox::Halfbox(vec3 center, double height, double width, double length, vec3 color, string direction)
{
    this->topPlane = this->addVectors(center, vec3(0, height / 2, 0), vec3(0, 0, 0));
    this->bottomPlane = this->subtractVectors(center, vec3(0, height / 2, 0), vec3(0, 0, 0));
    this->leftPlane = this->subtractVectors(center, vec3(width / 2, 0, 0), vec3(0, 0, 0));
    this->rightPlane = this->addVectors(center, vec3(width / 2, 0, 0), vec3(0, 0, 0));
    this->nearPlane = this->subtractVectors(center, vec3(0, 0, length / 2), vec3(0, 0, 0));
    this->farPlane = this->addVectors(center, vec3(0, 0, length / 2), vec3(0, 0, 0));

    if (direction == "BL")
    {
        halfboxBottomLeft(center, height, width, length, color);
    }
    else if (direction == "BR")
    {
        halfboxBottomRight(center, height, width, length, color);
    }
    else if (direction == "TL")
    {
        halfboxTopLeft(center, height, width, length, color);
    }
    else if (direction == "TR")
    {
        halfboxTopRight(center, height, width, length, color);
    }
    else if (direction == "TF")
    {
        halfboxTopFront(center, height, width, length, color);
    }
    else if (direction == "TB")
    {
        halfboxTopBack(center, height, width, length, color);
    }
    else if (direction == "BF")
    {
        halfboxBottomFront(center, height, width, length, color);
    }
    else if (direction == "BB")
    {
        halfboxBottomBack(center, height, width, length, color);
    }
    else
    {
        cout << "Invalid direction" << endl;
    }
}

void Halfbox::halfboxBottomLeft(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Triangle *front = new Triangle(nearLeftTop, nearRightTop, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Triangle *back = new Triangle(farRightTop, farLeftTop, farRightBottom, this->multiplyColourVector(color, coloursChange[1]));
    Rectangle *right = new Rectangle(nearRightTop, farRightTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftTop, nearRightBottom, farLeftTop, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));
    Rectangle *top = new Rectangle(nearLeftTop, nearRightTop, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[5]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, right, bottom, top
    };
}

void Halfbox::halfboxBottomRight(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);

    Triangle *front = new Triangle(nearLeftTop, nearRightTop, nearLeftBottom, this->multiplyColourVector(color, coloursChange[0]));
    Triangle *back = new Triangle(farRightTop, farLeftTop, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Rectangle *left = new Rectangle(farLeftTop, nearLeftTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightTop, farLeftBottom, farRightTop, this->multiplyColourVector(color, coloursChange[4]));
    Rectangle *top = new Rectangle(nearLeftTop, nearRightTop, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[5]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, left, bottom, top
    };
}

void Halfbox::halfboxTopLeft(vec3 center, double height, double width, double length, vec3 color)
{

    // vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    // vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Triangle *front = new Triangle(nearRightTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Triangle *back = new Triangle(farRightTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Rectangle *left = new Rectangle(farRightTop, nearRightTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Rectangle *right = new Rectangle(nearRightTop, farRightTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom
    };
}

void Halfbox::halfboxTopRight(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Triangle *front = new Triangle(nearLeftTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Triangle *back = new Triangle(farLeftTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Rectangle *left = new Rectangle(farLeftTop, nearLeftTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Rectangle *right = new Rectangle(nearLeftTop, farLeftTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom
    };
}

void Halfbox::halfboxTopFront(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Rectangle *front = new Rectangle(farLeftTop, farRightTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Rectangle *back = new Rectangle(farRightTop, farLeftTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Triangle *left = new Triangle(farLeftTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Triangle *right = new Triangle(farRightTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom // , top
    };
}

void Halfbox::halfboxTopBack(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Rectangle *front = new Rectangle(nearLeftTop, nearRightTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Rectangle *back = new Rectangle(nearRightTop, nearLeftTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Triangle *left = new Triangle(nearLeftTop, farLeftBottom, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Triangle *right = new Triangle(nearRightTop, nearRightBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom // , top
    };
}

void Halfbox::halfboxBottomFront(vec3 center, double height, double width, double length, vec3 color)
{

    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);
    vec3 farLeftBottom = this->addVectors(farPlane, leftPlane, bottomPlane);
    vec3 farRightBottom = this->addVectors(farPlane, rightPlane, bottomPlane);

    Rectangle *back = new Rectangle(farRightTop, farLeftTop, farRightBottom, farLeftBottom, this->multiplyColourVector(color, coloursChange[1]));
    Triangle *left = new Triangle(farLeftTop, nearLeftTop, farLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Triangle *right = new Triangle(nearRightTop, farRightTop, farRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftTop, nearRightTop, farLeftBottom, farRightBottom, this->multiplyColourVector(color, coloursChange[4]));
    Rectangle *top = new Rectangle(nearLeftTop, nearRightTop, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[5]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        back, left, right, bottom, top
    };
}

void Halfbox::halfboxBottomBack(vec3 center, double height, double width, double length, vec3 color)
{
    vec3 nearLeftTop = this->addVectors(nearPlane, leftPlane, topPlane);
    vec3 nearRightTop = this->addVectors(nearPlane, rightPlane, topPlane);
    vec3 nearLeftBottom = this->addVectors(nearPlane, leftPlane, bottomPlane);
    vec3 nearRightBottom = this->addVectors(nearPlane, rightPlane, bottomPlane);

    vec3 farLeftTop = this->addVectors(farPlane, leftPlane, topPlane);
    vec3 farRightTop = this->addVectors(farPlane, rightPlane, topPlane);

    Rectangle *front = new Rectangle(nearLeftTop, nearRightTop, nearLeftBottom, nearRightBottom, this->multiplyColourVector(color, coloursChange[0]));
    Triangle *left = new Triangle(farLeftTop, nearLeftTop, nearLeftBottom, this->multiplyColourVector(color, coloursChange[2]));
    Triangle *right = new Triangle(nearRightTop, farRightTop, nearRightBottom, this->multiplyColourVector(color, coloursChange[3]));
    Rectangle *bottom = new Rectangle(nearLeftBottom, nearRightBottom, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[4]));
    Rectangle *top = new Rectangle(nearLeftTop, nearRightTop, farLeftTop, farRightTop, this->multiplyColourVector(color, coloursChange[5]));

    numShapes = 5;
    shapes = new Shape *[numShapes]
    {
        front, left, right, bottom, top
    };
}

Cone::Cone(vec3 center, int numSidesOnBase, float height, float radius, vec3 color)
{
    // take the center point and move it left by the radius
    vec3 top = vec3(center.x - height, center.y, center.z);

    vec3 *vertices = new vec3[numSidesOnBase + 1];
    vertices[0] = top;
    for (int i = 1; i <= numSidesOnBase; i++)
    {
        float angle = 2 * M_PI * i / numSidesOnBase;
        vertices[i] = this->addVectors(center, vec3(0, radius * sin(angle), radius * cos(angle)), vec3(0, 0, 0));
    }

    numShapes = numSidesOnBase + 1; // Adding one for the extra triangle
    shapes = new Shape *[numShapes];
    for (int i = 0; i < numSidesOnBase; i++)
    {
        shapes[i] = new Triangle(vertices[0], vertices[i + 1], vertices[i], color); // Notice the order change here
    }

    // Join the last triangle with the first triangle
    shapes[numShapes - 1] = new Triangle(vertices[0], vertices[1], vertices[numSidesOnBase], color);
}

Cylinder::Cylinder()
{
}

Cylinder::Cylinder(vec3 center, int numSidesOnBase, float height, float radius, vec3 color)
{
    // Calculate the angle between each side of the base
    float angle = 2 * M_PI / numSidesOnBase;

    // Create an array to store the vertices of the cylinder
    vec3 *vertices = new vec3[2 * numSidesOnBase];

    // Calculate the vertices for the top base
    for (int i = 0; i < numSidesOnBase; i++)
    {
        float x = center.x + radius * cos(i * angle);
        float y = center.y + radius * sin(i * angle);
        float z = center.z + height / 2;
        vertices[i] = vec3(x, y, z);
    }

    // Calculate the vertices for the bottom base
    for (int i = 0; i < numSidesOnBase; i++)
    {
        float x = center.x + radius * cos(i * angle);
        float y = center.y + radius * sin(i * angle);
        float z = center.z - height / 2;
        vertices[numSidesOnBase + i] = vec3(x, y, z);
    }

    // Create the triangles for the sides of the cylinder
    numShapes = 2 * numSidesOnBase;
    shapes = new Shape *[numShapes];
    for (int i = 0; i < numSidesOnBase; i++)
    {
        int nextIndex = (i + 1) % numSidesOnBase;
        shapes[i] = new Triangle(vertices[i], vertices[nextIndex], vertices[numSidesOnBase + i], color);
        shapes[numSidesOnBase + i] = new Triangle(vertices[nextIndex], vertices[numSidesOnBase + nextIndex], vertices[numSidesOnBase + i], color);
    }

    // -------------------------------------------------- //
    // Drawing the Back face of the cylinder
    // -------------------------------------------------- //
    
    // numShapes = numSidesOnBase * 2;
    // shapes = new Shape *[numShapes];

    // int numberOfVertices = numSidesOnBase + 2;

    // GLfloat twicePi = 2.0f * M_PI;

    // GLfloat backWheel[(numberOfVertices) * 3];

    // backWheel[0] = center.x;
    // backWheel[1] = center.y;
    // backWheel[2] = (center.z - (height / 2));
    
    // GLfloat frontWheel[(numberOfVertices) * 3];

    // frontWheel[0] = center.x;
    // frontWheel[1] = center.y;
    // frontWheel[2] = (center.z + (height / 2));

    // for (int i = 1; i < numberOfVertices; i++)
    // {
    //     float angle = (i * twicePi / numSidesOnBase);
    //     float cosAngle = cos(angle);
    //     float sinAngle = sin(angle);

    //     backWheel[i * 3] = center.x + (radius * cosAngle);
    //     backWheel[(i * 3) + 1] = center.y + (radius * sinAngle);
    //     backWheel[(i * 3) + 2] = backWheel[2];

    //     frontWheel[i * 3] = center.x + (radius * cosAngle);
    //     frontWheel[(i * 3) + 1] = center.y + (radius * sinAngle);
    //     frontWheel[(i * 3) + 2] = frontWheel[2];
    // }

    // for (int i = 0; i < numSidesOnBase; i++)
    // {
    //     shapes[i] = new Triangle(vec3(backWheel[0], backWheel[1], backWheel[2]), vec3(backWheel[(i + 1) * 3], backWheel[((i + 1) * 3) + 1], backWheel[((i + 1) * 3) + 2]), vec3(backWheel[(i + 2) * 3], backWheel[((i + 2) * 3) + 1], backWheel[((i + 2) * 3) + 2]), color);
    // }
    // for (int i = numSidesOnBase; i < (numSidesOnBase * 2); i++)
    // {
    //     shapes[i] = new Triangle(vec3(frontWheel[0], frontWheel[1], frontWheel[2]), vec3(frontWheel[(i - numSidesOnBase + 1) * 3], frontWheel[((i - numSidesOnBase + 1) * 3) + 1], frontWheel[((i - numSidesOnBase + 1) * 3) + 2]), vec3(frontWheel[(i - numSidesOnBase + 2) * 3], frontWheel[((i - numSidesOnBase + 2) * 3) + 1], frontWheel[((i - numSidesOnBase + 2) * 3) + 2]), color);
    // }

    
    

    // -------------------------------------------------- //
    // Drawing the Front face of the cylinder
    // -------------------------------------------------- //

}

void Cylinder::Circles(vec3 center, int numSidesOnBase, float height, float radius, vec3 color)
{
    // -------------------------------------------------- //
    // Drawing the Back face of the cylinder
    // -------------------------------------------------- //
    
    numShapes = numSidesOnBase * 2;
    shapes = new Shape *[numShapes];

    int numberOfVertices = numSidesOnBase + 2;

    GLfloat twicePi = 2.0f * M_PI;

    GLfloat backWheel[(numberOfVertices) * 3];

    backWheel[0] = center.x;
    backWheel[1] = center.y;
    backWheel[2] = (center.z - (height / 2));
    
    GLfloat frontWheel[(numberOfVertices) * 3];

    frontWheel[0] = center.x;
    frontWheel[1] = center.y;
    frontWheel[2] = (center.z + (height / 2));

    for (int i = 1; i < numberOfVertices; i++)
    {
        float angle = (i * twicePi / numSidesOnBase);
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);

        backWheel[i * 3] = center.x + (radius * cosAngle);
        backWheel[(i * 3) + 1] = center.y + (radius * sinAngle);
        backWheel[(i * 3) + 2] = backWheel[2];

        frontWheel[i * 3] = center.x + (radius * cosAngle);
        frontWheel[(i * 3) + 1] = center.y + (radius * sinAngle);
        frontWheel[(i * 3) + 2] = frontWheel[2];
    }

    for (int i = 0; i < numSidesOnBase; i++)
    {
        shapes[i] = new Triangle(vec3(backWheel[0], backWheel[1], backWheel[2]), vec3(backWheel[(i + 1) * 3], backWheel[((i + 1) * 3) + 1], backWheel[((i + 1) * 3) + 2]), vec3(backWheel[(i + 2) * 3], backWheel[((i + 2) * 3) + 1], backWheel[((i + 2) * 3) + 2]), color);
    }
    for (int i = numSidesOnBase; i < (numSidesOnBase * 2); i++)
    {
        shapes[i] = new Triangle(vec3(frontWheel[0], frontWheel[1], frontWheel[2]), vec3(frontWheel[(i - numSidesOnBase + 1) * 3], frontWheel[((i - numSidesOnBase + 1) * 3) + 1], frontWheel[((i - numSidesOnBase + 1) * 3) + 2]), vec3(frontWheel[(i - numSidesOnBase + 2) * 3], frontWheel[((i - numSidesOnBase + 2) * 3) + 1], frontWheel[((i - numSidesOnBase + 2) * 3) + 2]), color);
    }
}
