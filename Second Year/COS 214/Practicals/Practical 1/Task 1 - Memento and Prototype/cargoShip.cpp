#include "cargoShip.h"
#include <string>
#include <iostream>

using namespace std;

cargoShip::cargoShip() {}

cargoShip::cargoShip(cargoShip *ship) {
    this->capacity      = ship->capacity;
    this->currentLoad   = ship->currentLoad;
    this->items         = ship->items;
    this->shipid        = ship->shipid;
}

cargoShip::~cargoShip()
{
    delete[] this->items;
}

string cargoShip::toString()
{
    string str = "Ship " + to_string(ship::getShipId()) + ": " + ship::getShipName() + "\n";
    str += "load: " + to_string(this->currentLoad) + "/" + to_string(this->capacity) + "\n";
    str += "Items: \n";
    for (int i = 0; i < cargoShip::getCurrentLoad(); i++)
    {
        str += "item " + to_string(i + 1) + ": " + this->items[i] + "\n";
    }

    return str;
}

cargoMemento cargoShip::save(int saveId)
{
    return cargoMemento(
        ship::getShipName(),
        ship::getShipId(),
        this->capacity,
        this->currentLoad,
        this->items,
        saveId
    );
}

void cargoShip::restore(cargoMemento restorePoint)
{
    this->capacity = restorePoint.getCapacity();
    this->currentLoad = restorePoint.getCurrentLoad();
    this->items = restorePoint.getItems();
}

ship *cargoShip::clone()
{
    return new cargoShip(*this);
}

int cargoShip::getCapacity()
{
    return this->capacity;
}

string *cargoShip::getItems()
{
    return this->items;
}

int cargoShip::getCurrentLoad()
{
    return this->currentLoad;
}

void cargoShip::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void cargoShip::setItems(string *items)
{
    this->items = items;
    setCurrentLoad(this->capacity); // Set the currentLoad to the capacity

    for (int i = 0; i < this->capacity; i++) {
        if (items[i] != "") { // Check if the item slot is not empty
            this->currentLoad = i + 1; // Update currentLoad based on the items present
        }
    }
}

void cargoShip::setCurrentLoad(int CurrentLoad)
{
    this->currentLoad = CurrentLoad;
}

void cargoShip::insertItem(string item)
{
    if (getCapacity() != getCurrentLoad())
    {
        int flag = findItem(item);
        if (flag == -1)
        {
            this->items[this->currentLoad] = item;
            setItems(this->items);
        }
        else 
        {
            cout << "Item: '" + item + "' is already in your inventory, cannot insert" << endl;
        }
    }
    else
    {
        cout << "Cannot insert: " + item + " as the inverntory is full" << endl;
    }
}

void cargoShip::deleteItem(string item)
{
    int index = findItem(item);
    string * newItems = new string[this->currentLoad];
    int count = 0;
    if (index != -1)
    {
        for (int i = 0; i < this->currentLoad; i++)
        {
            if (i != index)
            {
                newItems[count] = this->items[i];
                count++;
            }
        }
        setItems(newItems);
    }
    else
    {
        cout << "Item: '" + item + "' not found in inventory, cannot delete" << endl;
    }
}

int cargoShip::findItem(string item)
{
    for (int i = 0; i < this->currentLoad; i++)
    {
        if (item == this->items[i])
        {
            return i;
        }
    }
    return -1;
}
