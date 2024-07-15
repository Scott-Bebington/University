#ifndef BEFORETEST_H
#define BEFORETEST_H
#include <string>
#include <iostream>
#include "testDecorator.h"
using namespace std;
class BeforeTest : public TestDecorator
{
    public:
        BeforeTest(Testable*);
        bool runTest();
};
#endif