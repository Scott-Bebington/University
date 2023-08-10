#ifndef ISEVENODD_H
#define ISEVENODD_H

#include <iostream>
#include <cstddef>
#include "ValueIndependantTester.h"


using namespace std;

class  IsEvenOdd : public ValueIndependantTester
{
    private:

        static int numAliveObjects;

    public:

        IsEvenOdd();

        ~IsEvenOdd();

        bool evaluate(int val);

        int getNumAliveObjects();
        
        NumberTester* clone();

};
#endif