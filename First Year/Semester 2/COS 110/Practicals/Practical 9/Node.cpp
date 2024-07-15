#ifndef __NODE_H__
#define __NODE_H__

#include "Node.h"
using namespace std;

template<class T>
Node<T>::Node(T data)
{
    this->data = data;
    next = NULL;
}

template<class T>
T Node<T>::getData()
{
    return data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template<class T>
void Node<T>::setNext(Node<T>* ptr)
{
    next = ptr;
}
#endif // __NODE_H__