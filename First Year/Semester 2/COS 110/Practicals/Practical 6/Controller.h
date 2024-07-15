//The Controller class
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"

//See spec for inclusion strategy for templates
template <typename T>
class Controller
{
    private:
        Plane<T>* plane;
    public:
        Controller(Plane<T>*);
        string loadOnPlane(T*);
        double getTotalValue();
        string getPlaneContents();
};
#endif