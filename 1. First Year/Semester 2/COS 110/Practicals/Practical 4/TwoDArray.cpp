#ifndef TWODARRAY_CPP
#define TWODARRAY_CPP

#include "TwoDArray.h"
#include <iostream>

using namespace std;

TwoDArray::TwoDArray(int** array, int* sizes, int baseSize)
{
    this->baseSize = baseSize;

    this->array = new int*[this->baseSize];
	this->sizes = new int[this->baseSize];

    for (int i = 0; i < this->baseSize; i++)
	{
		this->sizes[i] = sizes[i];
		this->array[i] = new int[sizes[i]];

		for (int k = 0 ; k < this->sizes[i]; k++)
		{
			this->array[i][k] = array[i][k];
		}
	}
}

TwoDArray::~TwoDArray()
{
	for (int i=0;i<baseSize;i++)
		{
			delete [] array[i];
		}
		delete [] array;
		delete [] sizes;
}

int** TwoDArray::getArray()
{    
	int** array2 = new int*[baseSize];
	for (int i = 0; i < baseSize; i++)
	{
		array2[i] = new int[sizes[i]];
		for (int j = 0; j < sizes[i]; j++)
		{
			array2[i][j] = array[i][j];
		}
		
	}
    return array2;
}

int* TwoDArray::getSizes()
{
	int* sizes2 = new int[baseSize];
	for (int i = 0; i < baseSize; i++)
	{
		sizes2[i] = sizes[i];
	}
    return sizes2;
}

int TwoDArray::getBaseSize()
{
	return baseSize;
}

TwoDArray::operator int()
{
	return getBaseSize();
}

TwoDArray::operator int*()
{
	return getSizes();
}

TwoDArray::operator int**()
{
	return getArray();
}

std::ostream& operator<<(std::ostream& os, TwoDArray& tda)
{
	for (int i = 0; i < tda.baseSize; i++)
	{
		for (int k = 0 ; k < tda.sizes[i]; k++)
		{
			if (k < tda.sizes[i]-1)
			{
				os << tda.array[i][k] << " ";
			}
			else
			{
				os << tda.array[i][k] << endl;
			}
		}
	}
	return os;
}

#endif