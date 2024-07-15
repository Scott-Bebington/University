#ifndef TESTABLE_H
#define TESTABLE_H
#include <string>
#include <iostream>
#include "test.h"
using namespace std;
class Testable
{
    public:
        virtual bool runTest() = 0;
};
#endif