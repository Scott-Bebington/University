#ifndef ISPRIMENUMBER_H
#define ISPRIMENUMBER_H

#include <iostream>
#include <cstddef>
#include "ValueIndependantTester.h"


using namespace std;

class  IsPrimeNumber : public ValueIndependantTester
{
    private:

        static int numAliveObjects;

    public:

        IsPrimeNumber();

        ~IsPrimeNumber();

        bool evaluate(int val);

        int getNumAliveObjects();
        
        NumberTester* clone();

};
#endif