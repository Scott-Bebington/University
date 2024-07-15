#ifndef VALUEINDEPENDANTTESTER_CPP
#define VALUEINDEPENDANTTESTER_CPP

#include <iostream>
#include "ValueIndependantTester.h"


using namespace std;

int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester()
{
    ValueIndependantTester::numAliveObjects ++;
}

ValueIndependantTester::~ValueIndependantTester()
{
    ValueIndependantTester::numAliveObjects --;
}

int ValueIndependantTester::getNumAliveObjects()
{
    return ValueIndependantTester::numAliveObjects;
}

#endif