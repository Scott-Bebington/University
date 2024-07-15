#ifndef NUMERICCALCULATOR_H
#define NUMERICCALCULATOR_H
#include "calculator.h"
using namespace std;
class NumericCalculator : public Calculator
{
    private:
        string inputString;
    public:
        NumericCalculator();
        int performCalculation();
        
};
#endif