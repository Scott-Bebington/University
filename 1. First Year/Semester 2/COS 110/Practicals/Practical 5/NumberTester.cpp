#ifndef NUMBERTESTER_CPP
#define NUMBERTESTER_CPP

#include <iostream>
#include "NumberTester.h"

using namespace std;

int NumberTester::numAliveObjects = 0; // declaring static variable outside the class

NumberTester::NumberTester()
{
    NumberTester::numAliveObjects ++;
}

NumberTester::~NumberTester()
{
    NumberTester::numAliveObjects --;
}

int NumberTester::getNumAliveObjects()
{
    return NumberTester::numAliveObjects;
}
#endif