#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "lair.h"
#include "bank.h"

using namespace std;

class Menu {
public:
    Menu();
    void displayMenu();
    bool TrapList();
    void incrementTrapsEnabled();
private:
    int trapsEnabled;
};

#endif  // Menu_H
