#ifndef SUMARRAY_H
#define SUMARRAY_H

#include "TwoDArray.h"
#include <iostream>


using namespace std;

class  SumArray : public TwoDArray
{
    public:

        SumArray(int** array, int* sizes, int baseSize);

        int* operator[](int);

};
#endif