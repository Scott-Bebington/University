#ifndef SORTARRAY_CPP
#define SORTARRAY_CPP

#include "SortArray.h"

using namespace std;

    SortArray::SortArray(int** array, int* sizes, int baseSize) : TwoDArray(array, sizes, baseSize){
    }

    int* SortArray::operator[](int value) // address, send back entire array
    {
        int temp = 0;
        //int* tempvalue = &value;
        int* sizes = getSizes();
        int** array = getArray();
        for (int i = 0; i < sizes[value]; i++)
        {
            for (int j = 0; j < sizes[value]; j++)
            {
                if (array[value][j] > array[value][i])
                {
                    temp = array[value][j];
                    array[value][j] = array[value][i];
                    array[value][i] = temp;
                }
            }
        }
        int* returnarray = array[value];
        return returnarray; // return sorted array
    }

#endif