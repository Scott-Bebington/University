#ifndef SN_H
#define SN_H

#include <string>
#include <sstream>
#include <iostream>

//SortNode class implementation here
template <class T>
class SortNode
{
    protected:
        T value;

    public:
        SortNode<T>* next;
        SortNode<T>* prev;
        SortNode(T);
        std::string print();
        T getValue();

};

#include "SortNode.cpp"

#endif
