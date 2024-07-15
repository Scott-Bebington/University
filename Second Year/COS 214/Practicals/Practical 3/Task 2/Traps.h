#ifndef TRAPS_H
#define TRAPS_H

#include <iostream>
#include <string>

using namespace std;

class Traps
{
public:
    Traps(string Type, int Damage, int Cost);
    string getType();
    int getDamage();
    int getCost();

private:
    string Type;
    int Damage;
    int Cost;
};

#endif