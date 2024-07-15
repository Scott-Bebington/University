#ifndef NUMERICTEST_H
#define NUMERICTEST_H
#include <string>
#include <iostream>
#include "test.h"
#include "numericCalculator.h"
using namespace std;
class NumericTest : public Test
{
    public:
        NumericTest(string, int);
        bool executeTest();
};
#endif