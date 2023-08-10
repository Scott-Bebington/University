#include <iostream>
#include <cstddef>
#include "TesterInterface.h"
#include "NumberTester.h"
#include "IsDivisible.h"
#include "IsEvenOdd.h"
#include "IsGreater.h"
#include "IsSmaller.h"
#include "IsPrimeNumber.h"

using namespace std;

int main()
{
    cout << "Runs" << endl;
    TesterInterface test1(10);
    cout << "Maximum Number of testers are: " << test1.getMaxNumTesters() << endl;

    cout << endl;

    NumberTester* add = NULL;
    IsDivisible divis(15);
    add = &divis;
    cout << "Tester IsDivisible: value of 16 is at position: " << test1.addTester(add) << endl;

    // IsGreater great(5);
    // add = &great;
    // cout << "Tester IsGreater:   value of 5 is at position: " << test1.addTester(add) << endl;

    // IsSmaller small(5);
    // add = &small;
    // cout << "Tester IsSmaller:   value of 5 is at position: " << test1.addTester(add) << endl;

    cout << endl;

    cout << "Current Number of testers are: " << test1.getCurrNumTesters() << endl;

    // test1.removeTester(0);
    // cout << "Successfully removed tester at position 0" << endl;
    // cout << "Current Number of testers are: " << test1.getCurrNumTesters() << endl;

    cout << endl;

    cout << "Code 1 if all evaluates are true, code 0 if at least 1 is false: " <<test1.evaluate(5) << endl; 

    cout << endl;

    int* array = test1.failedTests(5);
    for (int i = 0; i < test1.numberOfFailedTests(5); i++)
    {
        cout << array[i] << endl;
    }
    cout << endl;

    cout << test1.operator[](2) << endl;
    return 0;
}
