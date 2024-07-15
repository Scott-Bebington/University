#ifndef ISSMALLER_CPP
#define ISSMALLER_CPP

#include <iostream>
#include <cstddef>
#include "IsSmaller.h"


using namespace std;

int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{
    IsSmaller::numAliveObjects ++;
}

IsSmaller::~IsSmaller()
{
    IsSmaller::numAliveObjects --;
}

bool IsSmaller::evaluate(int val)
{
    if (val < value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int IsSmaller::getNumAliveObjects()
{
    return IsSmaller::numAliveObjects;
}

NumberTester* IsSmaller::clone()
{
    IsSmaller* ptr = new IsSmaller(value);
    return ptr;
}

#endif