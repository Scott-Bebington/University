#ifndef CARGOMEMENTO_H
#define CARGOMEMENTO_H

#include <string>
#include <iostream>
#include "ship.h"

using namespace std;

class cargoMemento {
public:
    // Variables
    int shipId;
    int version;
    cargoMemento();
    cargoMemento(string, int, int, int, string*, int);
    

    // Methods
    string getShipName();
    string* getItems();
    int getCurrentLoad();
    int getCapacity();
    int getShipId();
    int getVersion();
    
private:
    // Variables
    string shipName;
    string* items;
    int currentLoad;
    int capacity;

};

#endif // CARGOMEMENTO_H
