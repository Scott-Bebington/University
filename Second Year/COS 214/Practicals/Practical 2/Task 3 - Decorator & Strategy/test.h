#ifndef TEST_H
#define TEST_H
#include <string>
#include <iostream>
#include "calculator.h"
using namespace std;
class Test
{
    protected:
        string inputString;
        int output;
        Calculator* calculator;
    public:
        Test(string, int);
        bool executeTest();
};
#endif