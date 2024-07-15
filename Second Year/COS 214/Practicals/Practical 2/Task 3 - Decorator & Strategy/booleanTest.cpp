#include "booleanTest.h"
BooleanTest::BooleanTest(string inputString, int out): Test(inputString, out)
{
    calculator = new BooleanCalculator();
}