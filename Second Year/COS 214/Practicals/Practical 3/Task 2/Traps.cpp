#include "Traps.h"

Traps::Traps(string Type, int Damage, int Cost)
{
    this->Type = Type;
    this->Damage = Damage;
    this->Cost = Cost;
}

string Traps::getType()
{
    return this->Type;
}

int Traps::getDamage()
{
    return this->Damage;
}

int Traps::getCost()
{
    return this->Cost;
}

