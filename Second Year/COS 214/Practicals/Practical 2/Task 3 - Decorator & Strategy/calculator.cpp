#include "calculator.h"
Calculator::Calculator()
{
    inputString = "";
}
string Calculator::getInputString()
{
    return inputString;
}
void Calculator::setInputString(string inputString)
{
    this->inputString = inputString;
}
int Calculator::performCalculation()
{
    return 0;
}