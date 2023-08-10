#ifndef SUMARRAY_CPP
#define SUMARRAY_CPP

#include "SumArray.h"

using namespace std;

    SumArray::SumArray(int** array, int* sizes, int baseSize) : TwoDArray(array, sizes, baseSize){
    }

    int* SumArray::operator[](int value)
    {
        int tempsum = 0;
        int* temp = &value;
        int* sizes = getSizes();
        int** array = getArray();
        for (int i = 0; i < sizes[*temp]; i++)
        {
            tempsum += array[*temp][i];
        }
        int* sum = new int(tempsum);
        return sum;
    }

#endif