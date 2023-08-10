#ifndef O_CPP
#define O_CPP

#include "Object.h"

using namespace std;

Object::Object(int x, int y)
{
    icon = '?';
    xPos = x;
    yPos = y;
    nextHoriz = NULL;
    nextVert = NULL;
    prevHoriz = NULL;
    prevVert = NULL;
    above = NULL;
    below = NULL;
}

char Object::getIcon()
{ 
    Object *nodePtr;
    nodePtr->icon = '?';
    if (above)
    {
        nodePtr = above;
    }
    while(nodePtr)
    {
        nodePtr = nodePtr->above;
    }
    return nodePtr->icon;
}

int Object::getCoord(bool dimension)
{
    if (dimension)
    {
        return yPos;
    }
    return xPos;
}

Object* Object::getNext(bool dimension)
{
    if (dimension)
    {
        return nextVert;
    }
    return nextHoriz;
}

Object* Object::getPrev(bool dimension)
{
    if (dimension)
    {
        return prevVert;
    }
    return prevHoriz;
}

void Object::setNext(Object* obj, bool dim)
{
    if (dim)
    {
        nextVert = obj;
    }
    else
    {
        nextHoriz = obj;
    }
    
}

void Object::setPrev(Object* obj, bool dim)
{
    if (dim)
    {
        prevVert = obj;
    }
    else
    {
        prevHoriz = obj;
    }
};
#endif
