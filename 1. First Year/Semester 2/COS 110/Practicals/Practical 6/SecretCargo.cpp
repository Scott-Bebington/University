//The SecretCargo implementation file
#ifndef SECRETCARGO_CPP
#define SECRETCARGO_CPP

#include "SecretCargo.h"

using namespace std;

SecretCargo::SecretCargo(double w)
{
    weight = w;
}
double SecretCargo::getWeight() const
{
    return weight;
}
#endif