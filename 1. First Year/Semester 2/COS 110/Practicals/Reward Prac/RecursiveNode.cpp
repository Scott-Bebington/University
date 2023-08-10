#ifndef RECURSIVENODE_CPP
#define RECURSIVENODE_CPP

#include "RecursiveNode.h"

using namespace std;

template <typename T>
RecursiveNode<T>::RecursiveNode(T data)
{
    this->data = data;
    next = NULL;
}

template <typename T>
T RecursiveNode<T>::getData() const
{
    return data;
}

template <typename T>
RecursiveNode<T> *RecursiveNode<T>::getNext() const
{
    return next;
}

template <typename T>
void RecursiveNode<T>::setNext(RecursiveNode<T> *next)
{
    this->next = next;
}

#endif