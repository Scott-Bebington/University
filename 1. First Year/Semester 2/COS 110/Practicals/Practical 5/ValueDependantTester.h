#ifndef VALUEDEPENDANTTESTER_H
#define VALUEDEPENDANTTESTER_H

#include <iostream>
#include <cstddef>
#include "NumberTester.h"


using namespace std;

class  ValueDependantTester : public NumberTester
{
    private:

        static int numAliveObjects;

    protected:

        int value;

    public:

        ValueDependantTester();
        ValueDependantTester(int val);

        ~ValueDependantTester();

        virtual bool evaluate(int val) = 0;

        virtual NumberTester* clone() = 0;

        int getNumAliveObjects();

};
#endif