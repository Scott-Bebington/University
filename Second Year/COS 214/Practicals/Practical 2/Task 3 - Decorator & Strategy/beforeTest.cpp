#include "beforeTest.h"
BeforeTest::BeforeTest(Testable* testable) : TestDecorator(testable)
{
}
bool BeforeTest::runTest()
{
    cout << "Running Test:" << endl;
    return getInternalTestBed()->runTest();
}