#include "cargoMemento.h"
#include <iostream>
#include <string>

cargoMemento::cargoMemento()
{
}

cargoMemento::cargoMemento(string shipName, int shipId, int capacity, int currentLoad, string *items, int version)
{
    this->shipName = shipName;
    this->shipId = shipId;
    this->capacity = capacity;
    this->currentLoad = currentLoad;
    this->items = items;
    this->version = version;
}

string cargoMemento::getShipName()
{
    cout << "getShipName" << endl;
    return this->shipName;
}

string *cargoMemento::getItems()
{
    return this->items;
}

int cargoMemento::getCurrentLoad()
{
    return this->currentLoad;
}

int cargoMemento::getCapacity()
{
    return this->capacity;
}

int cargoMemento::getShipId()
{
    return this->shipId;
}

int cargoMemento::getVersion()
{
    return this->version;
}
