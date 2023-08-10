#ifndef ASSIGNMENT2TEST_MATRIX_CPP
#define ASSIGNMENT2TEST_MATRIX_CPP

#include "matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(unsigned r, unsigned c) // dynamic matrix full of 0's
{
    rows = r;
    cols = c;
    matrix = new double *[rows]; // rows
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols]; // columns
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &rhs) // works
{
    this->cols = rhs.cols;
    this->rows = rhs.rows;

    double **matrix2 = new double *[this->rows]; // rows
    for (int i = 0; i < this->rows; i++)
    {
        matrix2[i] = new double[this->cols]; // columns
        for (int j = 0; j < this->cols; j++)
        {
            matrix2[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
        }
    }
    delete[] matrix;
}

void Matrix::print() // works
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(10) << setprecision(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Matrix::readFile(istream &infile) // works
{
    bool flagrows = true, flagcols = true;
    int countrows = 0, countcols = 0;
    for (int i = 0; i < rows; i++)
    {
        Vector *tempvec = new Vector(cols);
        tempvec->readFile(infile);
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = tempvec->operator[](j);
        }
    }
}

const Matrix &Matrix::operator=(const Matrix &rhs) // works
{
    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs) // doesnt work
{
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &rhs) // works
{
    return *this;
}

Matrix Matrix::operator-(const Matrix &rhs) // doesnt work
{
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs) // works
{
    return *this;
}

Matrix Matrix::operator*(const Matrix &rhs)
{
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
    return *this;
}

Matrix Matrix::operator^(int pow)
{
    return *this;
}

Matrix &Matrix::operator^=(int pow)
{
    return *this;
}

Matrix Matrix::operator~() // transpose
{
    return *this;
}

Matrix Matrix::operator*(const double &rhs) // doesnt work
{
    return *this;
}
Matrix &Matrix::operator*=(const double &rhs)
{
    return *this;
}
Matrix Matrix::operator/(const double &rhs)
{
    return *this;
}

double &Matrix::operator()(const unsigned r, const unsigned c)
{
    if (r >= 0 && r < rows)
    {
        if (c >= 0 && c < cols)
        {
            return matrix[r][c];
        }
        else
        {
            throw "Error: invalid column index";
        }
    }
    else
    {
        throw "Error: invalid row index";
    }
}

const double &Matrix::operator()(const unsigned r, const unsigned c) const
{
    if (r >= 0 && r < rows)
    {
        if (c >= 0 && c < cols)
        {
            return matrix[r][c];
        }
        else
        {
            throw "Error: invalid column index";
        }
    }
    else
    {
        throw "Error: invalid row index";
    }
}

Vector Matrix::operator[](const unsigned r) const
{
    Vector tempvec(cols);
    for (int i = 0; i < this->cols; i++)
    {
        tempvec[i] = this->matrix[r][i];
    }
    return tempvec;
}

Matrix Matrix::operator|(const Matrix &rhs)
{
    return *this;
}

Matrix &Matrix::operator|=(Matrix &rhs)
{
    return *this;
}

unsigned Matrix::getRows() const // Return number of rows
{
    return rows;
}
unsigned Matrix::getCols() const // Return number of columns
{
    return cols;
}
#endif
