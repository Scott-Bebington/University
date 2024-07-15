//The Plane class
#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"

//See spec on inclusion strategy for templates

using namespace std;

template <typename T>
class Plane
{
    private:
        vector<T*> cargo;
        double maxWeight;
    public:
        Plane(double);
        ~Plane();
        void add(T*);
        void remove(T*);
        string getDescription();
        double calculateValue();
};
#endif