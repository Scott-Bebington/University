#ifndef COUNTARRAY_H
#define COUNTARRAY_H

#include "TwoDArray.h"
#include <iostream>


using namespace std;

class  CountArray : public TwoDArray
{
    public:

        CountArray(int** array, int* sizes, int baseSize);

        int* operator[](int);

};
#endif