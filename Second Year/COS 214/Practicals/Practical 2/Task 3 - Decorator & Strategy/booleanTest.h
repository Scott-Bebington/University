#ifndef BOOLTEST_H
#define BOOLTEST_H
#include <string>
#include <iostream>
#include "test.h"
#include "booleanCalculator.h"
using namespace std;
class BooleanTest : public Test
{
    public:
        BooleanTest(string, int);
        bool executeTest();
};
#endif