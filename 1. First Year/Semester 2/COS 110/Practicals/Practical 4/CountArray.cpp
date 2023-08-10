#ifndef COUNTARRAY_CPP
#define COUNTARRAY_CPP

#include "CountArray.h"

using namespace std;

    CountArray::CountArray(int** array, int* sizes, int baseSize) : TwoDArray(array, sizes, baseSize){
    }

    int* CountArray::operator[](int value) 
    {
        int* tempsize = getSizes();
        int* temp = &value; // returns array column number
        int* returnvalue = new int(tempsize[*temp]);
        
        return returnvalue;
    }

#endif