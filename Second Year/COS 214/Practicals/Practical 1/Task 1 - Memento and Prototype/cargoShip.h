#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include <iostream>
#include "ship.h"
#include "cargoMemento.h"

using namespace std;

class cargoShip : public cargoMemento, public ship {
public:

    // Constructors
    cargoShip();
    cargoShip(cargoShip*);
    ~cargoShip();
    
    // Variables
    int capacity;
    string* items;
    int currentLoad;

    // Methods
    string toString();
    cargoMemento save(int saveId);
    void restore(cargoMemento restorePoint);
    ship* clone();

    // Getters and Setters
    int getCapacity();
    string* getItems();
    int getCurrentLoad();

    void setCapacity(int capacity);
    void setItems(string* items);
    void setCurrentLoad(int currentLoad);

    void insertItem(string item);
    void deleteItem(string item);

private:
    int findItem(string);

};

#endif // CARGOSHIP_H
