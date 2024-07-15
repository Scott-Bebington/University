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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs) // doesnt work
{
    if (rows == rhs.rows && cols == rhs.cols)
    {
        Matrix add = rhs;
        for (int i = 0; i < rhs.rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                add[i][j] = add[i][j] + rhs.matrix[i][j];
            }
        }
        return add;
    }
    else
    {
        throw "Error: adding matrices of different dimensionality";
    }
}

Matrix &Matrix::operator+=(const Matrix &rhs) // works
{
    if (rows == rhs.rows && cols == rhs.cols)
    {
        for (int i = 0; i < rhs.rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                matrix[i][j] += rhs.matrix[i][j];
            }
        }
        return *this;
    }
    else
    {
        throw "Error: adding matrices of different dimensionality";
    }
}

Matrix Matrix::operator-(const Matrix &rhs) // doesnt work
{
    if (rows == rhs.rows && cols == rhs.cols)
    {
        Matrix minus(rhs);
        for (int i = 0; i < rhs.rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                minus[i][j] = minus[i][j] - rhs.matrix[i][j];
            }
        }
        return minus;
    }
    else
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
}

Matrix &Matrix::operator-=(const Matrix &rhs) // works
{
    if (rows == rhs.rows && cols == rhs.cols)
    {
        for (int i = 0; i < rhs.rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                matrix[i][j] -= rhs.matrix[i][j];
            }
        }
        return *this;
    }
    else
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
}

Matrix Matrix::operator*(const Matrix &rhs)
{
    if (cols == rhs.rows)
    {
        Matrix multiply(rows, rhs.cols);
        for (int i = 0; i < rows; i++)
        {
            double temp = 0.0;
            for (int j = 0; j < rhs.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    temp += matrix[j][k] * rhs.matrix[k][j];
                }
                multiply[i][j] = temp;
            }
        }
        return multiply;
    }
    else
    {
        throw "Error: invalid matrix multiplication";
    }
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
    if (cols == rhs.rows)
    {
        Matrix multiply(rows, rhs.cols);
        for (int i = 0; i < rows; i++)
        {
            double temp = 0.0;
            for (int j = 0; j < rhs.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    temp += matrix[j][k] * rhs.matrix[k][j];
                }
                multiply[i][j] = temp;
            }
        }
        return *this;
    }
    else
    {
        throw "Error: invalid matrix multiplication";
    }
}

Matrix Matrix::operator^(int pow)
{
    Matrix power(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (pow == 0)
            {
                power[i][j] = 1;
            }
            else
            {
                double temp = 1;
                for (int k = 1; k < pow; k++)
                {
                }
            }
        }
    }
    return power;
}

Matrix &Matrix::operator^=(int pow)
{
    return *this;
}

Matrix Matrix::operator~() // transpose
{
    Matrix transpose(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    return transpose;
}

Matrix operator*(const double&, const Matrix&)
{
    
}

Matrix Matrix::operator*(const double &rhs) // doesnt work
{
    Matrix mat(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat(i, j) = matrix[i][j] * rhs;
        }
    }
    return mat;
}
Matrix &Matrix::operator*=(const double &rhs)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= rhs;
        }
    }
    return *this;
}
Matrix Matrix::operator/(const double &rhs)
{
    cout << rhs << endl;
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        Matrix mat(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // cout << matrix[i][j]/rhs << " ";
                mat(i, j) = matrix[i][j]/rhs;
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return mat;
    }
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
    Matrix augment(rhs);
    double multiplier = 0.0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j <= cols; j++)
        {
            multiplier = matrix[j][i] / matrix[j][j];
            for (int k = 1; k < cols; k++)
            {
                matrix[j][k] = matrix[j][k] - multiplier * matrix[i][k];
            }
            rhs.matrix[i][j] = rhs.matrix[i][j] - multiplier * rhs.matrix[i][0];
        }
    }
    return augment;
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
