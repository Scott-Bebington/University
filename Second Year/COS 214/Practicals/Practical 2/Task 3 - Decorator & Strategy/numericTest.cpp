#include "numericTest.h"
NumericTest::NumericTest(string inputString, int out): Test(inputString, out)
{
    calculator = new NumericCalculator();
}