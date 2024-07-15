#include "Matrix.h"
#include <cmath>

using namespace std;

Matrix::Matrix(int n, int m) : n(n), m(m)
{
    if (n < 0 || m < 0)
    {
        throw MathExceptions::InvalidMatrixSize;
    }
    this->arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        this->arr[i] = new double[m];
        for (int j = 0; j < m; j++)
        {
            this->arr[i][j] = 0;
        }
    }
}

Matrix::Matrix(int n, int m, double **inMatrix)
{
    this->n = n;
    this->m = m;
    this->arr = inMatrix;
}

Matrix::Matrix(const Matrix &inMatrix)
{
    this->n = inMatrix.n;
    this->m = inMatrix.m;
    this->arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        this->arr[i] = new double[m];
        for (int j = 0; j < m; j++)
        {
            this->arr[i][j] = inMatrix.arr[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; i++)
    {
        // delete[] this->arr[i];
    }
    // delete[] this->arr;
}

Matrix Matrix::operator*(const Matrix inMatrix) const
{
    if (this->m != inMatrix.n)
    {
        throw MathExceptions::InvalidMatrixMultiplication;
    }

    Matrix result(this->n, inMatrix.m);

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < inMatrix.m; j++)
        {
            double sum = 0;
            for (int k = 0; k < this->m; k++)
            {
                sum += this->arr[i][k] * inMatrix.arr[k][j];
            }
            result.arr[i][j] = sum;
        }
    }

    return result;
}

Matrix Matrix::operator*(const double inScalar) const
{
    double **newArr = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = new double[this->m];
        for (int j = 0; j < this->m; j++)
        {
            newArr[i][j] = this->arr[i][j] * inScalar;
        }
    }
    return Matrix(this->n, this->m, newArr);
}

Matrix Matrix::operator+(const Matrix inMatrix) const
{
    if (this->n != inMatrix.n || this->m != inMatrix.m)
    {
        throw MathExceptions::InvalidMatrixAddition;
    }

    double **newArr = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        newArr[i] = new double[this->m];
        for (int j = 0; j < this->m; j++)
        {
            newArr[i][j] = this->arr[i][j] + inMatrix.arr[i][j];
        }
    }
    return Matrix(this->n, this->m, newArr);
    // return Matrix();
}

Matrix Matrix::operator~() const
{
    double **newArr = new double *[this->m];
    for (int i = 0; i < this->m; i++)
    {
        newArr[i] = new double[this->n];
        for (int j = 0; j < this->n; j++)
        {
            newArr[i][j] = this->arr[j][i];
        }
    }
    return Matrix(this->m, this->n, newArr);
}

int Matrix::getM() const
{
    return this->m;
}

int Matrix::getN() const
{
    return this->n;
}

SquareMatrix::SquareMatrix(int inN) : Matrix(inN, inN)
{
}

SquareMatrix::SquareMatrix(int inN, double **inMatrix) : Matrix(inN, inN, inMatrix)
{
}

SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] this->arr[i];
    }
    delete[] this->arr;
}

Vector SquareMatrix::solve(const Vector inVector) const
{
    // return Vector();
    Matrix constantsMatrix = inVector;
    
    SquareMatrix inverseMatrix = !(*this);

    Matrix resultMatrix = inverseMatrix * constantsMatrix;
    double *resultArr = new double[resultMatrix.getN()];
    for (int i = 0; i < resultMatrix.getN(); i++)
    {
        resultArr[i] = resultMatrix[i][0];
    }
    return Vector(resultMatrix.getN(), resultArr);
}

double SquareMatrix::determinant() const
{
    //    return determinantHelper(this->arr, this->n);
    double det = 0.0;
    double sign = 1.0;

    // Base Case
    if (this->n == 1)
    {
        det = this->arr[0][0];
    }
    else if (this->n == 2)
    {
        det = (this->arr[0][0] * this->arr[1][1]) - (this->arr[0][1] * this->arr[1][0]);
    }

    // Perform the Laplace Expansion
    else
    {
        for (int i = 0; i < this->n; i++)
        {

            // Stores the cofactor matrix
            double **cofactor = new double *[this->n - 1];
            for (int j = 0; j < this->n - 1; j++)
            {
                cofactor[j] = new double[this->n - 1];
            }
            int sub_i = 0, sub_j = 0;
            for (int j = 1; j < this->n; j++)
            {
                for (int k = 0; k < this->n; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    cofactor[sub_i][sub_j] = this->arr[j][k];
                    sub_j++;
                }
                sub_i++;
                sub_j = 0;
            }

            // Update the determinant value
            SquareMatrix *temp = new SquareMatrix(this->n - 1, cofactor);
            det += sign * this->arr[0][i] * temp->determinant();
            sign = -sign;
            for (int j = 0; j < this->n - 1; j++)
            {
                delete[] cofactor[j];
            }
            delete[] cofactor;
        }
    }

    // Return the final determinant value
    return det;
}

SquareMatrix SquareMatrix::operator!() const
{

    if (this->n == 1)
    {
        return SquareMatrix(1, new double *[1]{new double[1]{1 / this->arr[0][0]}});
    }

    // Check if the matrix is invertible
    double determinant = this->determinant();

    // Create a matrix of cofactors
    double **cofactors = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        cofactors[i] = new double[this->n];
        for (int j = 0; j < this->n; j++)
        {
            // Calculate the minor
            double **minorArr = new double *[this->n - 1];
            for (int k = 0; k < this->n - 1; k++)
            {
                minorArr[k] = new double[this->n - 1];
                for (int l = 0; l < this->n - 1; l++)
                {
                    minorArr[k][l] = this->arr[(k < i) ? k : k + 1][(l < j) ? l : l + 1];
                }
            }

            // Calculate the cofactor
            cofactors[i][j] = pow(-1, i + j) * SquareMatrix(this->n - 1, minorArr).determinant();
        }
    }

    // Transpose the matrix of cofactors
    Matrix transposedCofactors(this->n, this->n, cofactors);
    transposedCofactors = ~transposedCofactors;

    delete cofactors;

    // Calculate the inverse matrix
    double **inverseArr = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        inverseArr[i] = new double[this->n];
        for (int j = 0; j < this->n; j++)
        {
            inverseArr[i][j] = transposedCofactors[i][j] / determinant;
        }
    }

    // Create and return the inverse matrix
    return SquareMatrix(this->n, inverseArr);
}

IdentityMatrix::IdentityMatrix(int inN) : SquareMatrix(inN)
{
}

IdentityMatrix::~IdentityMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] this->arr[i];
    }
    delete[] this->arr;
}
