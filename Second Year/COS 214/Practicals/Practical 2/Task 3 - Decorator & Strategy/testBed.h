#ifndef TESTBED_H
#define TESTBED_H
#include <string>
#include <iostream>
#include "testable.h"
using namespace std;
class TestBed : public Testable
{
    private:
        Test* test;
    public:
        TestBed();
        Test* getTest();
        void setTest(Test* test);
        bool runTest();
};
#endif