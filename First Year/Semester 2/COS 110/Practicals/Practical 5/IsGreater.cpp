#ifndef ISGREATER_CPP
#define ISGREATER_CPP

#include <iostream>
#include "IsGreater.h"


using namespace std;

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value)
{
    IsGreater::numAliveObjects ++; // do this for all
}

IsGreater::~IsGreater()
{
    IsGreater::numAliveObjects --;
}

bool IsGreater::evaluate(int val)
{
    if (val > value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int IsGreater::getNumAliveObjects()
{
    return IsGreater::numAliveObjects;
}
  
NumberTester* IsGreater::clone()
{
    IsGreater* ptr = new IsGreater(value);
    return ptr;
}

#endif