#ifndef ISEVENODD_CPP
#define ISEVENODD_CPP

#include <iostream>
#include <cstddef>
#include "IsEvenOdd.h"


using namespace std;

int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd()
{
    IsEvenOdd::numAliveObjects ++;
}

IsEvenOdd::~IsEvenOdd()
{
    IsEvenOdd::numAliveObjects --;
}

bool IsEvenOdd::evaluate(int val)
{
    int temp = val % 2;
    if (temp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int IsEvenOdd::getNumAliveObjects()
{
    return IsEvenOdd::numAliveObjects;
}

NumberTester* IsEvenOdd::clone()
{
    IsEvenOdd* ptr = new IsEvenOdd();
    return ptr;
}

#endif