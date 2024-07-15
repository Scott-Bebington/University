#include "Window.h"

#include <iostream>
#include <string>

using namespace std;

string Window::toString()
{
    return string();
}

int Window::getScreenHeight()
{
    return this->screenHeight;
}

int Window::getScreenWidth()
{
    return this->screenWidth;
}

int Window::getPrimitiveCount()
{
    return this->primitiveCount;
}

int Window::getPrimitiveCapacity()
{
    return this->primitiveCapacity;
}

void Window::setScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

void Window::setScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}

void Window::setPrimitiveCount(int primitiveCount)
{
    this->primitiveCount = primitiveCount;
}

void Window::setPrimitiveCapacity(int primitiveCapacity)
{
    this->primitiveCapacity = primitiveCapacity;
}
