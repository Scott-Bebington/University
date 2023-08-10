#ifndef ISPRIMENUMBER_CPP
#define ISPRIMENUMBER_CPP

#include <iostream>
#include <cstddef>
#include "IsPrimeNumber.h"

using namespace std;

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber()
{
    IsPrimeNumber::numAliveObjects++;
}

IsPrimeNumber::~IsPrimeNumber()
{
    IsPrimeNumber::numAliveObjects--;
}

bool IsPrimeNumber::evaluate(int val)
{
    if (val > -1)
    {
        int count = 0;
        for (int i = 1; i <= val; i++)
        {
            int temp = val % i;
            if (temp == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int IsPrimeNumber::getNumAliveObjects()
{
    return IsPrimeNumber::numAliveObjects;
}

NumberTester *IsPrimeNumber::clone()
{
    IsPrimeNumber *ptr =  new IsPrimeNumber();
    return ptr;
}

#endif