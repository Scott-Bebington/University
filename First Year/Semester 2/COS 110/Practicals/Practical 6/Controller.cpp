// The Controller implementation file
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include "Controller.h"

// See spec for inclusion strategy for templates
template <typename T>
Controller<T>::Controller(Plane<T> *p)
{
    plane = p;
}

template <typename T>
string Controller<T>::loadOnPlane(T *t)
{
    return "Success";
}

template <typename T>
double Controller<T>::getTotalValue()
{
    return 500;
}

template <typename T>
string Controller<T>::getPlaneContents()
{
    string temp = "";
    if (plane == NULL)
    {
        return "Nothing to report";
    }
    else
    {
        for (int i = 0; i < plane->cargo.size(); i++)
        {
            temp += plane->getDescription();
        }
    }
}

#endif