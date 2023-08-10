//The Passenger implementation file
#ifndef PASSENGER_CPP
#define PASSENGER_CPP

#include "Passenger.h"

using namespace std;

Passenger::Passenger(string id, double w, double t)
{
    ID = id;
    weight = w;
    ticketPrice = t;
}
double Passenger::getWeight() const
{
    return weight;
}
double Passenger::getValue() const
{
    return ticketPrice;
}
string Passenger::describe()
{
    string temp = "ID" + ID + "<" + to_string(ticketPrice) + "> (" + to_string(weight) + ")";
    return temp;
}
#endif