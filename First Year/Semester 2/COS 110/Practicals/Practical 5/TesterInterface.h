#ifndef TESTERINTERFACE_H
#define TESTERINTERFACE_H

#include <iostream>
#include <cstddef>
#include "NumberTester.h"


using namespace std;

class  TesterInterface
{
    private:

        int maxNumTesters;
        int currNumTesters;
        NumberTester** testers;

    public:

        TesterInterface(int maxNumTests);
        TesterInterface(TesterInterface* other);
        TesterInterface(TesterInterface& other);

        ~TesterInterface();

        int addTester(NumberTester* tester);

        bool removeTester(int pos);

        bool evaluate(int num);

        int* failedTests(int num);

        int numberOfFailedTests(int num);

        NumberTester* operator[](int pos);

        int getCurrNumTesters() const;

        int getMaxNumTesters() const;

};
#endif