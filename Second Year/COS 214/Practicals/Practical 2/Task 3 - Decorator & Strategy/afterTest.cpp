#include "afterTest.h"
AfterTest::AfterTest(Testable* internalTestBed): TestDecorator(internalTestBed)
{
}
bool AfterTest::runTest()
{
    bool result = getInternalTestBed()->runTest();
    if (result)
        cout << "Test Passed" << endl;
    else
        cout << "Test Failed" << endl;
    return result;
}