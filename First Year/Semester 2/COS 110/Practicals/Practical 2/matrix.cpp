#include <iostream>

#include "matrix.h"

using namespace std;

//Do not change the displayMatrix() function
void Matrix::displayMatrix() 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {

            cout << *matrix[i][j];

            if (j != columns - 1) 
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}
Matrix::Matrix(int in_rows, int in_columns)
{
        
    rows = in_rows;
    columns = in_columns;
    int ***matrix = new int** [rows]; //rows
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int *[columns]; //columns
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = new int(1);
        }
    }
}
/*
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete matrix[rows][columns];
           }
         delete [] matrix[i];
    }
    delete [] matrix;
}

void Matrix::resizeRows(int num_rows)
{
    if(num_rows < 1)
    {
        std::cout << "Error: cannot have less than 1 row \n";
    }
    else
    {
        if(num_rows < rows)
        {
            for (int i = num_rows; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    delete matrix[i][j];
                }
                delete [] matrix[i];
            }   
        }
        else
        {
            int temp = num_rows-rows;
            int ***matrix = new int**[temp];
            for (int i = rows; i < num_rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    matrix[i][j] = new int(0);
                }
                    
            }
        }
    }
}

void Matrix::resizeColumns(int num_cols)
{
    if(num_cols < 1)
    {
        std::cout << "Error: cannot have less than 1 column \n";
    }
    else
    {
        if(num_cols < columns)
        {
            for (int i = 0; i < rows; i++)
            {
                for (size_t j = num_cols; j < columns; j++)
                {
                    delete matrix[i][j];
                }
            }   
        }
        else
        {
            int temp = num_cols-columns;
            for (int i = 0; i < rows; i++)
            {
                matrix[rows] = new int *[temp]; //columns
                for (int j = num_cols; j < columns; j++)
                {
                    matrix[i][j] = new int(0);
                }
            }
        }
    }
}

void Matrix::setMatrix()
{
    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> temp;
            matrix[i][j] = new int(temp);
        }    
    } 
}
*/