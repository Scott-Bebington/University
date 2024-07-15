#include <iostream>
#include "Vector.h"
// import the math library
// #include <cmath>

using namespace std;

Vector::Vector(int size)
{
    if (size < 0)
    {
        throw MathExceptions::InvalidVectorSize;
    }
    this->n = size;
    this->arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = 0;
    }
}

Vector::Vector(int size, double *inArr)
{
    this->n = size;
    this->arr = inArr;
}

Vector::~Vector()
{
    // delete[] this->arr;
}

Vector::Vector(const Vector &inVector)
{
    this->n = inVector.n;
    this->arr = new double[inVector.n];
    for (int i = 0; i < inVector.n; i++)
    {
        this->arr[i] = inVector[i];
    }
}

Vector Vector::operator+(const Vector inVector) const
{
    if (inVector.n != this->n)
    {
        throw MathExceptions::InvalidVectorSize;
    }

    double *newArr = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = this->arr[i] + inVector[i];
    }

    return Vector(this->n, newArr);
}

Vector Vector::operator-(const Vector inVector) const
{
    if (inVector.n != this->n)
    {
        throw MathExceptions::InvalidVectorSize;
    }

    double *newArr = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = this->arr[i] - inVector[i];
    }

    return Vector(this->n, newArr);
}

Vector Vector::operator*(const double inScalar) const
{
    double *newArr = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = this->arr[i] * inScalar;
    }

    return Vector(this->n, newArr);
}

double Vector::operator*(const Vector inVector) const
{
    if (inVector.n != this->n)
    {
        throw MathExceptions::InvalidVectorSize;
    }
    double sum = 0;
    for (int i = 0; i < this->n; i++)
    {
        sum += this->arr[i] * inVector[i];
    }
    return sum;
}

double Vector::magnitude() const
{
    // sum the absolute value of each element in the vector
    double sum = 0;
    for (int i = 0; i < this->n; i++)
    {
        sum += pow(abs(this->arr[i]), 2);
    }
    return sqrt(sum);
}

Vector::operator Matrix() const
{
    // This is a conversion operator3 which will return a N ×1 Matrix, populated with the values
    // in the vector.
    // cout << "Method invoked\n";
    double **newArr = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = new double[1];
        newArr[i][0] = this->arr[i];
    }
    // cout << "Method finished\n";
    return Matrix(this->n, 1, newArr);
}

Vector Vector::crossProduct(const Vector inVector) const
{
    if (this->n != 3 || inVector.n != 3)
    {
        throw MathExceptions::InvalidCrossProduct;
    }

    // create a new vector with the cross product of the two vectors
    double *newArr = new double[3];

    newArr[0] = this->arr[1] * inVector[2] - this->arr[2] * inVector[1];
    newArr[1] = this->arr[2] * inVector[0] - this->arr[0] * inVector[2];
    newArr[2] = this->arr[0] * inVector[1] - this->arr[1] * inVector[0];

    return Vector(3, newArr);
}

Vector Vector::unitVector() const
{
    // create a new vector with the unit vector of the current vector
    double *newArr = new double[this->n];
    double mag = this->magnitude();
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = this->arr[i] / mag;
    }
    return Vector(this->n, newArr);
}

int Vector::getN() const
{
    return this->n;
}
