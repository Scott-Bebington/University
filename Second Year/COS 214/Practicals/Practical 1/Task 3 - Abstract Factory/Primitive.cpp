#include "Primitive.h"

Primitive::Primitive()
{
}

string Primitive::getShape()
{
    return this->shape;
}

void Primitive::setShape(string s)
{
    this->shape = s;
}
