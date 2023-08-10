//The Passenger class
#ifndef PASSENGER_H
#define PASSENGER_H

#include <sstream>
#include <string>

using namespace std;

class Passenger
{
    private:
        string ID;
        double weight;
        double ticketPrice;
    
    public:
        Passenger(string, double, double);
        double getWeight() const;
        double getValue() const;
        string describe();
};
#endif