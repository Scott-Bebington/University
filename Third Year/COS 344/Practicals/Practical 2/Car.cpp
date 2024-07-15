#include "Car.h"

Car::Car()
{
    this->carLength = 0.6;
    this->carHeight = 0.3;
    this->windowHeightBack = 0.126667;
    this->windowHeightFront = 0.126667;
    this->wheelRadius = 0.05;
    this->bottomLeft[0] = -0.3;
    this->bottomLeft[1] = -0.35;
    this->shapes = Shapes();
    this->road = Background();
}

void Car::createCar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    this->road.drawBackground();
    this->drawBody();
    this->drawRoof();
    this->drawWindows();
    this->drawWheels();
    this->drawHubCaps();
}

void Car::rotateWheels()
{
    this->startingAngle += 2.0f;
    this->createCar();
}

void Car::drawBody()
{
    GLfloat carBody[] = {
        // Car body
        this->bottomLeft[0], this->bottomLeft[1] + (carHeight * 2 / 3), 0,                       // top left
        this->bottomLeft[0], this->bottomLeft[1], 0,                                             // bottom left
        this->bottomLeft[0] + (carLength * 2 / 3), this->bottomLeft[1] + (carHeight * 2 / 3), 0, // top right
        this->bottomLeft[0] + (carLength * 2 / 3), this->bottomLeft[1], 0,                       // bottom right
        // Car Bonnet
        this->bottomLeft[0] + carLength, this->bottomLeft[1] + (carHeight / 2), 0, // top right
        this->bottomLeft[0] + carLength, this->bottomLeft[1], 0                    // bottom right
    };

    GLuint carColourbufferPurple;
    GLfloat carBodyColour[] = {
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.0f, 0.0f, 0.2f,
        0.0f, 0.0f, 0.2f,
        0.0f, 0.0f, 0.2f};
    glGenBuffers(1, &carColourbufferPurple);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferPurple);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carBodyColour), carBodyColour, GL_STATIC_DRAW);

    this->shapes.drawStrip(carBody, carColourbufferPurple, sizeof(carBody));
}

void Car::drawRoof()
{
    GLfloat backRightIndent = (carLength * 2 / 3) / 4;
    GLfloat middleRightIndent = (carLength * 2 / 3) / 4 * 3;
    GLfloat frontRightIndent = (carLength * 2 / 3);
    GLfloat carRoof[] = {
        // Back Section
        this->bottomLeft[0], this->bottomLeft[1] + (carHeight * 2 / 3), 0,                   // bottom left
        this->bottomLeft[0] + backRightIndent, this->bottomLeft[1] + carHeight, 0,           // top right
        this->bottomLeft[0] + backRightIndent, this->bottomLeft[1] + (carHeight * 2 / 3), 0, // bottom right
        // Middle Section
        this->bottomLeft[0] + middleRightIndent, this->bottomLeft[1] + carHeight, 0,           // top right
        this->bottomLeft[0] + middleRightIndent, this->bottomLeft[1] + (carHeight * 2 / 3), 0, // bottom right
        // Front Section
        this->bottomLeft[0] + frontRightIndent, this->bottomLeft[1] + (carHeight * 2 / 3), 0}; // bottom right

    GLuint carColourbufferRoof;
    GLfloat carRoofColour[] = {
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f,
        0.3f, 0.0f, 0.3f};
    glGenBuffers(1, &carColourbufferRoof);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferRoof);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carRoofColour), carRoofColour, GL_STATIC_DRAW);

    this->shapes.drawStrip(carRoof, carColourbufferRoof, sizeof(carRoof));
}

void Car::drawWindows()
{
    GLfloat backRightIndent = (carLength * 2 / 3) / 4;
    GLfloat middleRightIndent = (carLength * 2 / 3) / 4 * 3;
    GLfloat frontRightIndent = (carLength * 2 / 3);
    GLfloat padding = 0.01;
    GLfloat carWindowBack[] = {
        this->bottomLeft[0] + padding, this->bottomLeft[1] + (carHeight * 2 / 3), 0,          // bottom left
        this->bottomLeft[0] + backRightIndent, this->bottomLeft[1] + (carHeight * 2 / 3), 0,  // bottom right
        this->bottomLeft[0] + backRightIndent, this->bottomLeft[1] + carHeight - padding, 0}; // top right

    GLuint carColourbufferWindow;
    GLfloat carColourWindow[] = {
        0.7f, 0.7f, 1.0f, // ultra light blue
        0.7f, 0.7f, 1.0f, // ultra light blue
        0.7f, 0.7f, 1.0f  // slightly more blue
    };
    glGenBuffers(1, &carColourbufferWindow);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferWindow);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carColourWindow), carColourWindow, GL_STATIC_DRAW);

    this->shapes.drawTriangle(carWindowBack, carColourbufferWindow, sizeof(carWindowBack));

    GLfloat carWindowMiddle[] = {
        carWindowBack[3] + padding, carWindowBack[4], 0,                                                 // bottom left
        carWindowBack[6] + padding, carWindowBack[7], 0,                                                 // top left
        this->bottomLeft[0] + middleRightIndent - padding, this->bottomLeft[1] + (carHeight * 2 / 3), 0, // bottom right
        this->bottomLeft[0] + middleRightIndent - padding, this->bottomLeft[1] + carHeight - padding, 0  // top right
    };

    GLuint carColourbufferWindowMiddle;
    GLfloat carColourWindowMiddle[] = {
        0.7f, 0.7f, 1.0f, // ultra light blue
        0.7f, 0.7f, 1.0f, // ultra light blue
        0.7f, 0.7f, 1.0f, // slightly more blue
        0.7f, 0.7f, 1.0f};
    glGenBuffers(1, &carColourbufferWindowMiddle);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferWindowMiddle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carColourWindowMiddle), carColourWindowMiddle, GL_STATIC_DRAW);

    this->shapes.drawStrip(carWindowMiddle, carColourbufferWindowMiddle, sizeof(carWindowMiddle));

    GLfloat carWindowFront[] = {
        this->bottomLeft[0] + middleRightIndent, this->bottomLeft[1] + (carHeight * 2 / 3), 0,         // bottom left
        this->bottomLeft[0] + middleRightIndent, this->bottomLeft[1] + carHeight - padding, 0,         // top left
        this->bottomLeft[0] + frontRightIndent - padding, this->bottomLeft[1] + (carHeight * 2 / 3), 0 // bottom right
    };

    this->shapes.drawTriangle(carWindowFront, carColourbufferWindow, sizeof(carWindowFront));
}

void Car::drawWheels()
{
    GLuint carColourbufferWheel;
    GLfloat carColourWheel[] = {
        0.0f, 0.0f, 0.0f, // black
        0.0f, 0.0f, 0.0f, // black
        0.0f, 0.0f, 0.0f, // black
        0.0f, 0.0f, 0.0f  // black
    };

    glGenBuffers(1, &carColourbufferWheel);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferWheel);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carColourWheel), carColourWheel, GL_STATIC_DRAW);

    // Draw the back wheel
    GLint numberOfSides = 50;
    GLfloat x = this->bottomLeft[0] + (wheelRadius * 1.2);
    GLfloat y = this->bottomLeft[1];

    this->shapes.drawCircle(x, y, wheelRadius, 50, carColourbufferWheel, (this->startingAngle * this->startingAngle));

    // Draw the front wheel
    x = this->bottomLeft[0] + (carLength * 0.8);
    this->shapes.drawCircle(x, y, wheelRadius, 50, carColourbufferWheel, (this->startingAngle * this->startingAngle));
}

void Car::drawHubCaps()
{
    size_t vertices = 6;

    GLuint carColourbufferWheel;
    GLfloat carColourWheel[] = {
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f, // white
        1.0f, 1.0f, 1.0f  // white
    };

    glGenBuffers(1, &carColourbufferWheel);
    glBindBuffer(GL_ARRAY_BUFFER, carColourbufferWheel);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carColourWheel), carColourWheel, GL_STATIC_DRAW);

    // Draw the back wheel
    GLfloat x = this->bottomLeft[0] + (wheelRadius * 1.2);
    GLfloat y = this->bottomLeft[1];

    this->shapes.drawCircle(x, y, (wheelRadius / 2), vertices, carColourbufferWheel, (this->startingAngle * this->startingAngle));

    // Draw the front wheel
    x = this->bottomLeft[0] + (carLength * 0.8);
    this->shapes.drawCircle(x, y, (wheelRadius / 2), vertices, carColourbufferWheel, (this->startingAngle * this->startingAngle));
}

void Car::moveUp()
{
    if (this->bottomLeft[1] > 0.5 - (this->carHeight * 1.1))
    {
        return;
    }
    this->bottomLeft[1] += 0.01;
    this->carHeight -= 0.002;
    this->carLength -= 0.002;
    this->wheelRadius -= 0.0003;
    // this->createCar();
}

void Car::moveDown()
{
    if (this->bottomLeft[1] < -1.0 + (this->wheelRadius * 1.1))
    {
        return;
    }

    this->bottomLeft[1] -= 0.01;
    this->carHeight += 0.002;
    this->carLength += 0.002;
    this->wheelRadius += 0.0003;
    // this->createCar();
}

void Car::moveLeft()
{
    if (this->bottomLeft[0] < -1.0)
    {
        return;
    }

    this->bottomLeft[0] -= 0.01;
    this->startingAngle -= 5.0f;
    // this->createCar();
}

void Car::moveRight()
{
    if (this->bottomLeft[0] > 1.0 - this->carLength)
    {
        return;
    }
    this->bottomLeft[0] += 0.01;
    this->startingAngle += 5.0f;
    // this->createCar();
}

void Car::toggleWireframe()
{
    this->shapes.toggleWireframe();
    this->road.shapes.toggleWireframe();
    // this->createCar();
}