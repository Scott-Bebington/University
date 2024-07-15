#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

// SortList class Implementation here
template <class T>
class SortList
{
private:
    bool ascending;
    SortNode<T> *head;
    SortNode<T> *tail;

public:
    SortList(bool);
    void add(SortNode<T> *);
    SortNode<T> *remove(T val);
    void sort();
    std::string print();
    SortNode<T> *getHead();
    void setAsc(bool);
    std::string debug();
};

#include "SortList.cpp"

#endif
