#ifndef VALUEDEPENDANTTESTER_CPP
#define VALUEDEPENDANTTESTER_CPP

#include <iostream>
#include "ValueDependantTester.h"


using namespace std;

int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val)
{
    value = val;
    ValueDependantTester::numAliveObjects ++;
}

ValueDependantTester::~ValueDependantTester()
{
    ValueDependantTester::numAliveObjects --;
}

int ValueDependantTester::getNumAliveObjects()
{
    return ValueDependantTester::numAliveObjects;
}

#endif