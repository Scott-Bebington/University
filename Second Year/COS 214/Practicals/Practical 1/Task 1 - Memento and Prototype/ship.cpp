#include "ship.h"
#include "cargoShip.h"

using namespace std;

ship::ship()
{
}

string ship::getShipName()
{
    return this->shipName;
}

int ship::getShipId()
{
    return this->shipid;
}

void ship::setShipName(string shipName)
{
    this->shipName = shipName;
}

void ship::setShipId(int shipId)
{
    this->shipid = shipId;
}

// ship *ship::clone()
// {
//     return new ship(*this);
// }
