#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H

#include "Operator.h"

template <class T>
class MultiplyOperator : public Operator<T>
{
    T operator()(T lhs, T rhs);
    Operator<T>* clone();
};
#endif