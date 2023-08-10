//The base 2D array class

//# directives....
#ifndef TWODARRAY_H
#define TWODARRAY_H

//Do not add any more #includes
#include <iostream>
#include <string>

//Define class below

using namespace std;
class TwoDArray;
std::ostream& operator<<(std::ostream& os, TwoDArray& tda);
class  TwoDArray
{
private:
    int** array;
    int* sizes;
    int baseSize;
public:

    TwoDArray(int** array, int* sizes, int baseSize);

    ~TwoDArray();

    virtual int* operator[](int) = 0;

    operator int();

    operator int*();

    operator int**();

    friend std::ostream& operator<<(std::ostream& os, TwoDArray& tda);

protected:

    int** getArray();

    int* getSizes();

    int getBaseSize();
};
#endif