#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include "Operator.h"

template <class T>
class PlusOperator : public Operator<T>
{
    T operator()(T lhs, T rhs);
    Operator<T>* clone();
};
#endif