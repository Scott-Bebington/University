#include "test.h"
Test::Test(string inputString, int output)
{
    this->inputString = inputString;
    this->output = output;
}
bool Test::executeTest()
{
    calculator->setInputString(inputString);
    int answer = calculator->performCalculation();
    cout << "Input: " << inputString << endl;
    cout << "Expected output: " << output << endl;
    cout << "Actual output: " << answer << endl;
    if (answer == output)
    {
        return true;
    }
    else
    {
        return false;
    }
}