#include "testDecorator.h"
TestDecorator::TestDecorator(Testable* internalTestBed)
{
    this->internalTestBed = internalTestBed;
}
TestBed* TestDecorator::getInternalTestBed()
{
    return (TestBed*)internalTestBed;
}
void TestDecorator::setInternalTestBed(Testable* internalTestBed)
{
    this->internalTestBed = internalTestBed;
}
bool TestDecorator::runTest()
{
    return internalTestBed->runTest();
}