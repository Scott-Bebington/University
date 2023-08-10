#ifndef __OBJECTLIST_CPP__
#define __OBJECTLIST_CPP__

#include "ObjectList.h"

using namespace std;

ObjectList::ObjectList(bool dim)
{
    dimension = dim;
    head = NULL;
    current = NULL;
}

void ObjectList::add(Object *obj)
{
    Object *newNode;
    Object *nodePtr = head;
    Object *prevNode = NULL;

    newNode = obj;
    if (!head) // test whether head is null
    {
        head = newNode; // make the new node the head of the list
        current = newNode;
    }
    else if (dimension) // false = horizontal, true = vertical
    {
        while(nodePtr && obj->getCoord(dimension) <= nodePtr->getCoord(dimension)) 
        {// test to see if new nodes coords are less than the current
            
        }
    }
    // insert at the end of the list
    {
        nodePtr = head;
        prevNode = NULL;
        while (nodePtr && nodePtr->getCoord(dimension) <= newNode->getCoord(dimension))
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->nextHoriz;
        }
        if (!prevNode)
        {
            head = newNode;
            newNode->nextHoriz = nodePtr;
        }
    }
}

Object *ObjectList::getHead()
{
    return head;
}

string ObjectList::print()
{
    if (head)
    {
        string temp = "";
        Object *nodePtr;
        nodePtr = head; 
        while (nodePtr) // traversing the list
        {
            temp += nodePtr->getIcon();
            nodePtr = nodePtr->nextHoriz;
        }
    }
    return "";
}

#endif
