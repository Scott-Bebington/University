#ifndef CHESSBOARD_CPP
#define CHESSBOARD_CPP

#include "chessboard.h"
#include <iostream>

using namespace std;

// Task 1

Chessboard::Chessboard(Chessboard &obj)
{
    this->rows = obj.rows;
    this->columns = obj.columns;
    this->board = new Chesspiece**[this->rows]; //rows
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new Chesspiece *[this->columns]; //columns
        for (int j = 0; j < this->columns; j++)
        {
            if (obj.board[i][j] == NULL)
            {
                this->board[i][j] = NULL;
                continue; // goes back to for loop
            }
            this->board[i][j] = new Chesspiece(*obj.board[i][j]);
        }
    }
}

Chessboard::Chessboard(int in_rows, int in_columns)
{

    this->rows = in_rows;
    this->columns = in_columns;
    this->board = new Chesspiece** [rows]; //rows
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece *[columns]; //columns
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = NULL;
        }
    }
}

Chessboard::~Chessboard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete board[i][j];
        }
        delete [] board[i];
    }
    delete [] board;
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{
    board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column)
{
    if (board[row][column] != NULL)
    {
        delete board[row][column];
    }
    board[row][column] = NULL;
}

Chesspiece &Chessboard::at(int row, int column) const
{
    return *board[row][column];
}

//    Task 2


Chessboard &Chessboard::operator=(const Chessboard &other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    this->board = new Chesspiece**[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new Chesspiece *[this->columns]; //columns
        for (int j = 0; j < this->columns; j++)
        {
            if (other.board[i][j] == NULL)
            {
                this->board[i][j] = NULL;
                continue; // goes back to for loop
            }
            
            this->board[i][j] = new Chesspiece(*other.board[i][j]); // change to 1
        }
    }
    return *this;
}

Chessboard &Chessboard::operator+=(const Chessboard &rhs)
{
    for (int i = 0; i < rhs.rows; i++)
    {
        for (int j = 0; j < rhs.columns; j++)
        {
            if (rhs.board[i][j] != this->board[i][j])
            {
                this->board[i][j] = rhs.board[i][j];
            }
        }
    }
    return *this;
}
#endif