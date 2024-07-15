#ifndef ISGREATER_H
#define ISGREATER_H

#include <iostream>
#include <cstddef>
#include "ValueDependantTester.h"


using namespace std;

class  IsGreater : public ValueDependantTester
{
    private:

        static int numAliveObjects;

    public:

        IsGreater(int value);

        ~IsGreater();

        bool evaluate(int val);

        int getNumAliveObjects();
        
        NumberTester* clone();

};
#endif