#ifndef __STACK_H__
#define __STACK_H__

#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
    for (int i = 0; i < size(); i++)
    {
        top = top->getNext();
    }
}

template <class T>
void Stack<T>::push(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (!top)
    {
        top = newNode;
        return;
    }
    newNode->setNext(top);
    top = newNode;
}

template <class T>
Node<T> *Stack<T>::pop()
{
    if (!top)
    {
        return NULL;
    }
    Node<T> *temp;
    temp = top;
    top = top->getNext();
    return temp;
}

template <class T>
Node<T> *Stack<T>::getTop()
{
    return top;
}

template <class T>
int Stack<T>::size()
{
    Node<T> *nodePtr = top;
    int count = 0;
    if (!nodePtr)
    {
        return count;
    }
    while (nodePtr)
    {
        count++;
        nodePtr = nodePtr->getNext();
    }
    return count;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (!top)
    {
        return true;
    }
    return false;
}

template <class T>
Stack<T> *Stack<T>::reverse()
{
    Stack<T> *tempstack = new Stack<T>();
    if (!top)
    {
        return tempstack;
    }
    Node<T> *nodePtr = top;
    while (nodePtr)
    {
        tempstack->push(nodePtr->getData());
        nodePtr = nodePtr->getNext();
    }
    return tempstack;
}

template <class T>
bool Stack<T>::contains(T data)
{
    Node<T> *nodePtr = top;
    if (!nodePtr)
    {
        return false;
    }
    while (nodePtr)
    {
        if (nodePtr->getData() == data)
        {
            return true;
        }
        nodePtr = nodePtr->getNext();
    }
    return false;
}
#endif // __STACK_H__