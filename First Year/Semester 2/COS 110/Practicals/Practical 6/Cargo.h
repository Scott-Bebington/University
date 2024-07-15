//The Cargo class
#ifndef CARGO_H
#define CARGO_H

#include <string>
#include <sstream>

using namespace std;

class Cargo
{
    private:
        double weight;
        double value;
    public:
        Cargo(double, double);
        string describe();
        double getWeight() const;
        double getValue() const;
};
#endif