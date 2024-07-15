#include <iostream>
#include <string>

#include "ship.h"
#include "cargoShip.h"
#include "cargoMemento.h"

using namespace std;

void Ships(string shipName, int shipId, string* items, int capacity);

int main() {
    cout << endl;

    string* items = new string[1];
    items[0] = "Water";
    Ships("Titanic", 1, items, 1);

    items = new string[5];
    items[0] = "Ammo";
    items[1] = "Food";
    items[2] = "Guns";
    items[3] = "Fuel";
    Ships("HMS Sandwich", 2, items, 5);

    return 0;
}

void Ships(string shipName, int shipId, string* items, int capacity) {
    cout << "\033[32mCreating Ship\033[0m" << endl << endl;
    cargoShip* ship1 = new cargoShip();
    ship1->setShipName(shipName);
    ship1->setShipId(shipId);
    ship1->setCapacity(capacity);

    // string* items = new string[capacity];
    // items = items;

    ship1->setItems(items);

    string ship1output = ship1->toString();
    cout << ship1output << endl;

    cout << "Saving ship" << endl << endl;
    cargoMemento save1 = ship1->save(1);

    cout << "Adding 'Water' to loadout" << endl;
    ship1->insertItem("Water");

    ship1output = ship1->toString();
    cout << ship1output << endl;

    cout << "Removing 'Ammo' from loadout" << endl;
    ship1->deleteItem("Ammo");

    ship1output = ship1->toString();
    cout << ship1output << endl;

    cout << "Restoring ship" << endl << endl;
    ship1->restore(save1);

    ship1output = ship1->toString();
    cout << ship1output << endl;

    cout << "\033[38;2;255;165;0mCloning Ship\033[0m" << endl << endl;
    cargoShip* ship2 = (cargoShip*)ship1->clone();

    ship2->setShipName("Cloned Ship");
    ship2->setShipId(3);
    ship2->insertItem("Blankets");

    cout << "Original Ship" << endl;
    ship1output = ship1->toString();
    cout << ship1output << endl;

    cout << "Cloned Ship" << endl;
    string ship2output = ship2->toString();
    cout << ship2output << endl;
}
