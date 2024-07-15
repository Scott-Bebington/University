#include "Background.h"

Background::Background()
{
    this->shapes = Shapes();
}

void Background::createRoad()
{
    // ---------------------- //
    // Creating the tar
    // ---------------------- //
    GLfloat triangle1[] = {
        -1, -1, 0,
        1, -1, 0,
        1, 0.5, 0};

    GLfloat triangle2[] = {
        -1, -1, 0,
        -1, 0.5, 0,
        1, 0.5, 0};

    GLuint tarColourbuffer;
    GLfloat tarColour[] = {
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f};
    glGenBuffers(1, &tarColourbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, tarColourbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tarColour), tarColour, GL_STATIC_DRAW);

    // Creating the dark grey surface
    this->shapes.drawTriangle(triangle1, tarColourbuffer, sizeof(triangle1));
    this->shapes.drawTriangle(triangle2, tarColourbuffer, sizeof(triangle2));

    GLuint lineColourbuffer;
    GLfloat lineColour[] = {
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f};
    glGenBuffers(1, &lineColourbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, lineColourbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lineColour), lineColour, GL_STATIC_DRAW);

    // ---------------------- //
    // Creating the lines
    // ---------------------- //
    GLfloat xcoord1 = -0.9;
    GLfloat xcoord2 = -0.7;
    for (int i = 0; i < 5; i++)
    {
        GLfloat ycoord1 = -0.5;
        GLfloat ycoord2 = -0.475;
        for (int j = 0; j < 2; j++)
        {
            GLfloat line1[] = {
                xcoord1, ycoord1, 0,  // bottom left
                xcoord2, ycoord1, 0,  // bottom right
                xcoord2, ycoord2, 0}; // top right

            GLfloat line2[] = {
                xcoord1, ycoord1, 0,  // bottom left
                xcoord1, ycoord2, 0,  // bottom right
                xcoord2, ycoord2, 0}; // top righ

            this->shapes.drawTriangle(line1, lineColourbuffer, sizeof(line1));
            this->shapes.drawTriangle(line2, lineColourbuffer, sizeof(line2));
            ycoord1 += 0.5;
            ycoord2 += 0.5;
        }
        xcoord1 += 0.4;
        xcoord2 += 0.4;
    }
}

void Background::createBuilding(GLfloat height, GLfloat width, GLfloat x, GLfloat y, GLuint colourbuffer)
{
    GLfloat building[] = {
        x, y, 0,                 // bottom left
        x, y + height, 0,        // top left
        x + width, y, 0,         // bottom right
        x + width, y + height, 0 // top right
    };

    this->shapes.drawStrip(building, colourbuffer, sizeof(building));

    // 10% 35% 10% 35% 10%
    GLfloat bottomLeftX = x + (width * 0.1);

    // 6.25% 25% 6.25% 25% 6.25% 25% 6.25%
    GLfloat bottomLeftY = y + (height * 0.0625);

    for (int i = 0; i < 3; i++)
    {
        GLfloat leftWindow[] = {
            bottomLeftX, bottomLeftY, 0, // bottom left
            bottomLeftX, bottomLeftY + (height * 0.25), 0, // top left
            bottomLeftX + (width * 0.35), bottomLeftY, 0, // bottom right
            bottomLeftX + (width * 0.35), bottomLeftY + (height * 0.25), 0 // top right
        };

        bottomLeftX += width * 0.475;

        GLfloat rightWindow[] = {
            bottomLeftX, bottomLeftY, 0, // bottom left
            bottomLeftX, bottomLeftY + (height * 0.25), 0, // top left
            bottomLeftX + (width * 0.35), bottomLeftY, 0, // bottom right
            bottomLeftX + (width * 0.35), bottomLeftY + (height * 0.25), 0 // top right
        };

        GLuint windowBuffer;
        GLfloat windowColour[] = {
            0.7f, 0.7f, 1.0f, // ultra light blue
            0.7f, 0.7f, 1.0f, // ultra light blue
            0.7f, 0.7f, 1.0f, // slightly more blue
            0.7f, 0.7f, 1.0f};
        glGenBuffers(1, &windowBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, windowBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(windowColour), windowColour, GL_STATIC_DRAW);

        this->shapes.drawStrip(leftWindow, windowBuffer, sizeof(leftWindow));
        this->shapes.drawStrip(rightWindow, windowBuffer, sizeof(rightWindow));

        bottomLeftX = x + (width * 0.1);
        bottomLeftY += height * 0.3125;
    }
}

void Background::drawBackground()
{
    this->createRoad();

    GLuint colourbuffer;
    GLfloat buildingColour[] = {
        0.7f, 0.7f, 0.7f, // Light grey
        0.7f, 0.7f, 0.7f, // Light grey
        0.7f, 0.7f, 0.7f, // Light grey
        0.7f, 0.7f, 0.7f  // Light grey
    };

    glGenBuffers(1, &colourbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(buildingColour), buildingColour, GL_STATIC_DRAW);

    this->createBuilding(0.3, 0.2, -0.8, 0.6, colourbuffer);
    this->createBuilding(0.2, 0.1, -0.4, 0.6, colourbuffer);
    this->createBuilding(0.35, 0.25, 0.4, 0.6, colourbuffer);
    this->createBuilding(0.25, 0.15, 0, 0.6, colourbuffer);
}
