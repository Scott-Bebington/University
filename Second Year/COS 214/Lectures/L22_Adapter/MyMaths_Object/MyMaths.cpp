#include "MyMaths.h"

template <typename T>
MyMaths<T>::MyMaths(T v1, T v2)
{
    x = v1;
    y = v2;
}

template <typename T>
T MyMaths<T>::add() 
{
    return x + y;
}


template <typename T>
T MyMaths<T>::multiply() 
{
    return x * y;
}

template <typename T>
void MyMaths<T>::setX(T object)
{
    x = object;
}

template <typename T>
void MyMaths<T>::setY(T object)
{
    y = object;
}
