//The Cargo implementation file
#ifndef CARGP_CPP
#define CARGO_CPP

#include "Cargo.h"

using namespace std;

Cargo::Cargo(double w, double ppw)
{
    weight = w;
    value = ppw * weight;
}

string Cargo::describe()
{
    string temp = "Generic cargo <" + to_string(value) + "> (" + to_string(weight) + ")";
    return temp;
}

double Cargo::getWeight() const
{
 return weight;
}

double Cargo::getValue() const
{
    return value;
}

#endif