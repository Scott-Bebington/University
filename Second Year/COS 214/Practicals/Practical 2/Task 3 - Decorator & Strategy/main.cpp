#include "test.h"
#include "testDecorator.h"
#include "testable.h"
#include "testBed.h"
#include "beforeTest.h"
#include "afterTest.h"
#include "numericTest.h"
#include "booleanTest.h"
int main()
{
    Test* test = new NumericTest("+,5,4", 9);
    Test* test2 = new BooleanTest("&,1,0", 0);
    Test* test3 = new BooleanTest("|,1,0", 1);
    Test* test4 = new NumericTest("*,12,4", 48);
    TestBed* testBed = new TestBed();
    Testable* testable = new BeforeTest(new AfterTest(testBed));
    testBed->setTest(test);
    testable->runTest();
    cout << endl;
    testBed->setTest(test2);
    testable->runTest();
    cout << endl;
    testBed->setTest(test3);
    testable->runTest();
    cout << endl;
    testBed->setTest(test4);
    testable->runTest();
    cout << endl;
    return 0;
}