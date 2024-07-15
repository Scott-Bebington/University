//Exception implementations
#ifndef EXCEPTIONS_CPP
#define EXCEPTIONS_CPP

#include "Exceptions.h"

using namespace std;

// AboveWeight class
AboveWeightEx::AboveWeightEx(double wd)
{
    weightDiff = wd;
}
double AboveWeightEx::getDifference() const
{
    return weightDiff;
}

// Undervalued class
template <typename E>
UndervaluedEx<E>::UndervaluedEx(E* uv, double s)
{
    sum = s;
    underVal = uv;
}

template <typename E>
E* UndervaluedEx<E>::getUndervalued() const
{
    return underVal;
}

template <typename E>
double UndervaluedEx<E>::getSum() const
{
    return sum;
}

//notfound class
template <typename E>
NotFoundEx<E>::NotFoundEx(E* nf)
{
    missing = nf;
}

template <typename E>
E* NotFoundEx<E>::getNotFound() const
{
    return missing;
}


EmptyEx::EmptyEx()
{
    throw "Plane is empty";
}

UnauthorisedEx::UnauthorisedEx()
{
    throw " Not permitted";
}
#endif