#ifndef VALUEINDEPENDANTTESTER_H
#define VALUEINDEPENDANTTESTER_H

#include <iostream>
#include <cstddef>
#include "NumberTester.h"


using namespace std;

class  ValueIndependantTester : public NumberTester
{
    private:

        static int numAliveObjects;

    public:

        ValueIndependantTester();

        ~ValueIndependantTester();

        virtual bool evaluate(int val) = 0;

        virtual NumberTester* clone() = 0;

        int getNumAliveObjects();

};
#endif