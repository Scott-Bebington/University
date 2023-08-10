#ifndef CHESSPIECE_CPP
#define CHESSPIECE_CPP

#include "chesspiece.h"
#include <iostream>

using namespace std;
int Chesspiece::numberOfPieces = 0;
Chesspiece::Chesspiece()
{
    name = "";
    numberOfPieces++;
    type = true;
}

Chesspiece::Chesspiece(Chesspiece &obj)
{
    this->name = obj.name;
    this->numberOfPieces = obj.numberOfPieces;
    this->type = obj.type;
    Chesspiece::numberOfPieces++;
}

Chesspiece::Chesspiece(string in_name)
{
    name = in_name;
    numberOfPieces++;
}

Chesspiece::~Chesspiece()
{
    numberOfPieces--;
}

string Chesspiece::getName() const
{
    return name;
}

bool Chesspiece::getType() const
{
    return type;
}

int Chesspiece::getNumberOfPieces() const
{
    return numberOfPieces;
}

Chesspiece::Chesspiece(string in_name, bool in_type)
{
    type = in_type;
    name = in_name;
}
#endif