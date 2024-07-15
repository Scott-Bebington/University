#ifndef AFTERTEST_H
#define AFTERTEST_H
#include <string>
#include <iostream>
#include "testDecorator.h"
using namespace std;
class AfterTest : public TestDecorator
{
    public:
        AfterTest(Testable*);
        bool runTest();
};
#endif