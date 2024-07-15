#ifndef SORTARRAY_H
#define SORTARRAY_H

#include "TwoDArray.h"
#include <iostream>


using namespace std;

class  SortArray : public TwoDArray
{
    public:

        SortArray(int** array, int* sizes, int baseSize);

        int* operator[](int);

};
#endif