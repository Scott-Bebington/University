#ifndef BOOLEANCALCULATOR_H
#define BOOLEANCALCULATOR_H
#include "calculator.h"
using namespace std;
class BooleanCalculator : public Calculator
{
    private:
        string inputString;
    public:
        BooleanCalculator();
        int performCalculation();
};
#endif