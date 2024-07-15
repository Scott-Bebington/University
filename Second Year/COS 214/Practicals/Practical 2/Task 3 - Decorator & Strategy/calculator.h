#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Calculator
{
    private:
        string inputString;
    public:
        Calculator();
        string getInputString();
        void setInputString(string inputString);
        virtual int performCalculation();
};
#endif