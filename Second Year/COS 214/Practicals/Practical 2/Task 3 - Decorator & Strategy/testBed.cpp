#include "testBed.h"
TestBed::TestBed() : Testable()
{
    test = NULL;
}
Test* TestBed::getTest()
{
    return test;
}
void TestBed::setTest(Test* test)
{
    this->test = test;
}
bool TestBed::runTest()
{
    if (test == NULL)
    {
        cout << "No test has been set." << endl;
        return false;
    }
    else
    {
        return test->executeTest();
    }
}