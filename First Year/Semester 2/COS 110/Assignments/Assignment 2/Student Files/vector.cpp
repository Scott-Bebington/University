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
    delete[] vector1;
    vector1 = new double(rhs.size);
    vector1 = rhs.vector1;
    size = rhs.size;

    for (int i = 0; i < size; i++)
    {
        vector1[i] = rhs.vector1[i];
    }
    return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector &rhs) // doesnt work
{
    if (rhs.size == size)
    {
        Vector vec(rhs);
        for (int i = 0; i < rhs.size; i++)
        {
            vec[i] = vector1[i] + rhs.vector1[i];
        }
        return vec;
    }
    else
    {
        throw "Error: adding matrices of differentdimensionality";
    }
}

Vector &Vector::operator+=(const Vector &rhs) // works
{
    if (rhs.size == size)
    {
        for (int i = 0; i < rhs.size; i++)
        {
            vector1[i] += rhs.vector1[i];
        }
        return *this;
    }
    else
    {
        throw "Error: adding matrices of differentdimensionality";
    }
}

Vector Vector::operator-(const Vector &rhs) // doesnt work
{
    if (rhs.size == size)
    {
        Vector vec(rhs.size);
        for (int i = 0; i < rhs.size; i++)
        {
            vec[i] = vector1[i] - rhs.vector1[i];
        }
        return vec;
    }
    else
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
}

Vector &Vector::operator-=(const Vector &rhs) // works
{
    if (rhs.size == size)
    {
        for (int i = 0; i < rhs.size; i++)
        {
            vector1[i] -= rhs.vector1[i];
        }
        return *this;
    }
    else
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
}

Vector Vector::operator^(int pow) // works
{
    if (pow >= 0)
    {
        if (pow == 0)
        {
            Vector vec1(size);
            for (int i = 0; i < size; i++)
            {
                vec1[i] = 1;
            }
            return vec1;
        }
        else
        {
            Vector vec1(size);
            for (int i = 0; i < size; i++)
            {
                vec1[i] = vector1[i];
                for (int j = 1; j < pow; j++)
                {
                    vec1[i] = vec1[i] * vector1[i];
                }
            }
            return vec1;
        }
    }
    else
    {
        throw "Error: negative power is not supported";
    }
}

Vector &Vector::operator^=(int pow) // works
{
    if (pow >= 0)
    {
        if (pow == 0)
        {
            for (int i = 0; i < size; i++)
            {
                vector1[i] = 1;
            }
            return *this;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                double temp = vector1[i];
                for (int j = 1; j < pow; j++)
                {
                    vector1[i] = vector1[i] * temp;
                }
            }
            return *this;
        }
    }
    else
    {
        throw "Error: negative power is not supported";
    }
}

Vector Vector::operator~() // reverse - works
{
    Vector vec1(size);
    int count = 0;
    for (int i = (size - 1); i >= 0; i--)
    {
        vec1[i] = vector1[count];
        count++;
    }
    return vec1;
}

Vector operator* (const double&, const Vector&)
{
    
}

// Vector/scalar operations
Vector Vector::operator*(const double &rhs)
{
    Vector vec1(size);
    for (int i = 0; i < size; i++)
    {
        vec1[i] = vector1[i] * rhs;
    }
    return vec1;
}

Vector &Vector::operator*=(const double &rhs) // works
{
    for (int i = 0; i < size; i++)
    {
        vector1[i] *= rhs;
    }
    return *this;
}

Vector Vector::operator/(const double &rhs) // works
{
    if (rhs != 0)
    {
        Vector vec1(size);
        for (int i = 0; i < size; i++)
        {
            vec1[i] = vector1[i] / rhs;
        }
        return vec1;
    }
    else
    {
        throw "Error: division by zero";
    }
}

#endif
