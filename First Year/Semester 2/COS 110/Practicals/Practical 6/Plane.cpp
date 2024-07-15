// The Plane implementation file
#ifndef PLANE_CPP
#define PLANE_CPP

#include "Plane.h"

// See spec on inclusion strategy for templates

using namespace std;

template <typename T>
Plane<T>::Plane(double max)
{
    maxWeight = max;
    cargo = 0;
}

template <typename T>
Plane<T>::~Plane()
{
    for (int i = 0; i < cargo.size(); i++)
    {
        if (cargo[i] != NULL)
        {
            cargo.erase(cargo.begin() + i);
        }
    }
}

template <typename T>
void Plane<T>::add(T *item)
{
    int weight = 0;
    for (int i = 0; i < cargo.size(); i++)
    {
        weight += cargo[i].getWeight();
    }
    weight += item.getWeight();
    if (weight > maxWeight)
    {
        //AboveWeightEx::AboveWeightEx();
    }
    else
    {
        cargo.push_back(item);
    }
}

template <typename T>
void Plane<T>::remove(T *item)
{
    bool flag = true;
    for (int i = 0; i < cargo.size(); i++)
    {
        if (cargo[i] == item)
        {
            flag = false;
            for (int j = i + 1; j < cargo.size(); j++)
            {
                if (cargo[i] == cargo[j])
                {
                    delete cargo[i];
                }
            }
        }
    }
    if (flag)
    {
        //return NotFoundEx::NotFoundEx(item);
    }
    
}

template <typename T>
string Plane<T>::getDescription()
{
    string temp = "";
    if (cargo == NULL)
    {
        //return EmptyEx::EmptyEx();
    }
    else
    {
        for (int i = 0; i < cargo.size(); i++)
        {
            temp += cargo[i].describe() + "\n";
        }
        return temp;
    }
}

template <>
string Plane<SecretCargo>::getDescription()
{
    return "Unauthorised";
}

template <typename T>
double Plane<T>::calculateValue()
{
    double leastvalue = 0, secondleast = 0 , value = 0;
    if (cargo == NULL)
    {
        //return EmptyEx::EmptyEx();
    }
    else
    {
        for (int i = 0; i < cargo.size(); i++)
        {
            for (int j = 0 + 1; j < cargo.size(); j++)
            {
                if (cargo[i] < cargo[j])
                {
                    leastvalue = cargo[i].getValue();
                }
                
            }
        }
        
    }
    return value;
}

template <>
double Plane<SecretCargo>::calculateValue()
{
    return 500.25;
}
#endif