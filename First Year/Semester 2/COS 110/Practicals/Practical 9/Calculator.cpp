#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "Calculator.h"
using namespace std;

template <class T>
Calculator<T>::Calculator()
{
    valueStack = new Stack<T>();
    operatorStack = new Stack<Operator<T> *>();
}

template <class T>
Calculator<T>::~Calculator()
{
    delete valueStack;
    delete operatorStack;
}

template <class T>
void Calculator<T>::addValue(T val)
{
    valueStack->push(val);
}

template <class T>
void Calculator<T>::addOperator(Operator<T> *op)
{
    Operator<T> *temp = op;
    operatorStack->push(temp);
}

template <class T>
T Calculator<T>::removeValue()
{
    if (!valueStack->isEmpty())
    {
        return valueStack->pop()->getData();
    }
    return NULL;
}

template <class T>
Operator<T> *Calculator<T>::removeOperator()
{
    if (!operatorStack->isEmpty())
    {
        return operatorStack->pop()->getData();
    }
    return NULL;
}

template <class T>
int Calculator<T>::numValues()
{
    return valueStack->size();
}

template <class T>
int Calculator<T>::numOperators()
{
    return operatorStack->size();
}

template <class T>
T Calculator<T>::calculate()
{
    T lhs = NULL, rhs = NULL;
    while (!operatorStack->isEmpty())
    {
        if (valueStack->isEmpty())
        {
            return NULL;
        }
        lhs = valueStack->pop()->getData();
        if (valueStack->isEmpty())
        {
            return NULL;
        }
        rhs = valueStack->pop()->getData();
        lhs = operatorStack->pop()->getData()->operator()(lhs, rhs);
        valueStack->push(lhs);
    }
    return lhs;
}

#endif // __CALCULATOR_H__