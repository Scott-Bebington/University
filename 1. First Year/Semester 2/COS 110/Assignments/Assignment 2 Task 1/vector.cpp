#ifndef ASSIGNMENT2TEST_VECTOR_CPP
#define ASSIGNMENT2TEST_VECTOR_CPP

#include <iostream>

#include "vector.h"

using namespace std;

Vector::Vector(unsigned s) // size
{
    size = s;
    vector1 = new double[size]; // rows
    for (int i = 0; i < size; i++)
    {
        vector1[i] = 0;
    }
}

Vector::Vector(const Vector &rhs)
{
    int size2 = rhs.size;
    double *vector2 = new double[size2]; // rows
    for (int i = 0; i < size2; i++)
    {
        vector2[i] = rhs.vector1[i];
    }
}

Vector::~Vector()
{
    delete[] vector1;
    placeholder = 0;
}

void Vector::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << setprecision(4);
        cout << vector1[i];
    }
    cout << endl;
}

int Vector::countiterations = 0;
vector<double> Vector::vec;
int Vector::placeholder = 0;

void Vector::getiterations(istream &infile)
{
    string line = "", delim = "";
    while (getline(infile, line))
    {
        stringstream ss(line);
        while (getline(ss, delim, ' '))
        {
            vec.push_back(stod(delim));
            countiterations++;
        }
    }
}

void Vector::readFile(istream &infile)
{
    // should be size 50
    if (countiterations == 0)
    {
        getiterations(infile);
    }
    for (int i = 0; i < size; i++)
    {
        vector1[i] = vec[placeholder];
        placeholder++;
    }
}

double &Vector::operator[](const unsigned r)
{
    if (r > size || r < 0)
    {
        throw "Error: invalid row index";
    }
    else
    {
        return vector1[r];
    }
}

const double &Vector::operator[](const unsigned r) const
{
    if (r > size || r < 0)
    {
        throw "Error: invalid row index";
    }
    else
    {
        return vector1[r];
    }
}

unsigned Vector::getSize() const
{
    return size;
}

// Insert overloaded = operator signature
const Vector &Vector::operator=(const Vector &rhs) // works
{
    return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector &rhs) // doesnt work
{
    return *this;
}

Vector &Vector::operator+=(const Vector &rhs) // works
{
    return *this;
}

Vector Vector::operator-(const Vector &rhs) // doesnt work
{
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) // works
{
    return *this;
}

Vector Vector::operator^(int pow) // works
{
    return *this;
}

Vector &Vector::operator^=(int pow) // works
{
    return *this;
}

Vector Vector::operator~() // reverse - works
{
    return *this;
}
// Vector/scalar operations
Vector Vector::operator*(const double &rhs)
{
    return *this;
}

Vector &Vector::operator*=(const double &rhs) // works
{
    return *this;
}

Vector Vector::operator/(const double &rhs) // works
{
    return *this;
}

#endif
