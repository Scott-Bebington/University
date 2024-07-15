#include <iostream>
#include <string>
#include "Menu.h"
#include "lair.h"
#include "bank.h"
#include "engine.h"

using namespace std;

lair* createTile(lair*);

int main() {
    engine *myEngine = new engine();

    // lair *myLair = new lair();
    // myLair = createTile(myLair);

    // bank *myBank = new bank(20);

    // Menu *menu = new Menu(myLair, myBank);
    // menu->displayMenu();
    return 0;
}

lair* createTile(lair *myLair) {
    myLair->createTile(0,1);
    myLair->createTile(0,2);
    myLair->createTile(0,3);
    myLair->createTile(0,4);
    myLair->createTile(0,5);
    myLair->createTile(1,5);
    myLair->createTile(2,5);
    myLair->createTile(3,5);
    myLair->createTile(4,5);
    myLair->createTile(5,5);

    myLair->AddTrap(0, 3 , "FT", 10, 10);
    myLair->AddTrap(2, 5, "PT", 2, 5);

    myLair->AddTreasure(5, 5);

    return myLair;
}
