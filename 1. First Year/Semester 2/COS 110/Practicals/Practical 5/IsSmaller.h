#ifndef ISSMALLER_H
#define ISSMALLER_H

#include <iostream>
#include <cstddef>
#include "ValueDependantTester.h"


using namespace std;

class  IsSmaller : public ValueDependantTester
{
    private:

        static int numAliveObjects;

    public:

        IsSmaller(int value);

        ~IsSmaller();

        bool evaluate(int val);

        int getNumAliveObjects();
        
        NumberTester* clone();

};
#endif