#ifndef ISDIVISIBLE_CPP
#define ISDIVISIBLE_CPP

#include <iostream>
#include "IsDivisible.h"


using namespace std;

int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int value) : ValueDependantTester(value)
{
    IsDivisible::numAliveObjects ++;
}

IsDivisible::~IsDivisible()
{
    IsDivisible::numAliveObjects --;
}

bool IsDivisible::evaluate(int val)
{
    int temp = val % value; // might have to swap values if incorrect
    if (temp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int IsDivisible::getNumAliveObjects()
{
    return IsDivisible::numAliveObjects;
}
       
NumberTester* IsDivisible::clone()
{
    IsDivisible* ptr = new IsDivisible(value);
    return ptr;
}

#endif