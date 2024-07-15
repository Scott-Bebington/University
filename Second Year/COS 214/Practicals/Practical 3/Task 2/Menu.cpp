#include "Menu.h"
#include <iostream>
#include <string>

Menu::Menu()
{
    trapsEnabled = 0;
}

void Menu::displayMenu()
{
    cout << endl;
    cout << "Pick an option:" << endl;
    cout << "1. Add a tile" << endl;
    cout << "2. Remove a tile" << endl;
    cout << "3. Add a trap" << endl;
    cout << "4. Research new traps" << endl;
    cout << "5. Manage research queue" << endl;
    cout << "6. Display wealth" << endl;
    cout << "7. Display Board" << endl;
    cout << "8. Play" << endl;
    cout << endl;
}

bool Menu::TrapList()
{
    cout << endl;
    cout << "Trap List:" << endl;
    if (trapsEnabled == 0)
    {
        cout << "No traps available, please research some" << endl;
        return false;
    }
    if (trapsEnabled > 0)
        cout << "1. Poison Trap: 10 coins" << endl;
    if (trapsEnabled > 1)
        cout << "2. Fire Trap : 5 coins" << endl;
    cout << endl;
    return true;
}

void Menu::incrementTrapsEnabled()
{
    this->trapsEnabled++;
}
