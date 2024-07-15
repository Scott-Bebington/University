#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

// Function to rotate the matrix around the y-axis
void rotateMatrixY(double **matrix, int size, double angle)
{
    // Convert the angle from degrees to radians
    double radianAngle = angle * M_PI / 180.0;

    // Create a temporary matrix to store the rotated values
    double **rotatedMatrix = new double *[size];
    for (int i = 0; i < size; i++)
    {
        rotatedMatrix[i] = new double[size];
    }

    // Create the rotation matrix
    double rotationMatrix[3][3] = {
        {cos(radianAngle), 0, sin(radianAngle)},
        {0, 1, 0},
        {-sin(radianAngle), 0, cos(radianAngle)}
    };

    // Apply the rotation to each row of the matrix
    for (int i = 0; i < size; i++)
    {
        double x = matrix[i][0];
        double y = matrix[i][1];
        double z = matrix[i][2];

        rotatedMatrix[i][0] = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y + rotationMatrix[0][2] * z;
        rotatedMatrix[i][1] = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y + rotationMatrix[1][2] * z;
        rotatedMatrix[i][2] = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y + rotationMatrix[2][2] * z;
    }

    // Copy the rotated values back to the original matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rotatedMatrix[i][j];
        }
    }

    // Clean up the temporary matrix
    for (int i = 0; i < size; i++)
    {
        delete[] rotatedMatrix[i];
    }
    delete[] rotatedMatrix;
}

int main()
{
    int size = 3;
    double **matrix = new double *[size];
    matrix[0] = new double[size]{0, 0, 0};
    matrix[1] = new double[size]{-1, -1, 1};
    matrix[2] = new double[size]{1, -1, 1};

    // Rotate the matrix around the y-axis by 45 degrees
    rotateMatrixY(matrix, size, 45);

    // Print the rotated matrix
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Matrix m = Matrix(size, size, matrix);
    m.print();
    cout << endl;
    m = ~m;
    m.print();

    return 0;
}
