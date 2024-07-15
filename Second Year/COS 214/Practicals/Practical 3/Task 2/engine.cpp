#include "engine.h"

engine::engine()
{
    myLair = new lair();
    myLair->createTile(0, 1);
    myLair->createTile(0, 2);
    myLair->createTile(0, 3);
    myLair->createTile(0, 4);
    myLair->createTile(0, 5);
    myLair->createTile(1, 5);
    myLair->createTile(2, 5);
    myLair->createTile(3, 5);
    myLair->createTile(4, 5);
    myLair->createTile(5, 5);

    myLair->AddTrap(0, 3, "FT", 10, 10);
    myLair->AddTrap(2, 5, "PT", 2, 5);

    myLair->AddTreasure(5, 5);

    myBank = new bank(50);
    menu = new Menu();
    myStoryteller = new storyteller();
    myResearch = new research();
    setupPhase();
}

void engine::setupPhase()
{
    bool exit = false;
    int x, y, damage, cost, moneySpent;
    string type;
    while (!exit)
    {
        menu->displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter X and Y coordinates for the tile: ";
            cin >> x >> y;
            myLair->createTile(x, y);
            break;
        case 2:
            cout << "Enter X and Y coordinates to remove the tile: ";
            cin >> x >> y;
            myLair->removeTile(x, y);
            break;
        case 3:
            if (menu->TrapList())
            {
                cout << "Enter X and Y coordinates to add a trap: ";
                cin >> x >> y;
                cout << "Trap Type: ";
                cin >> type;
                if(type == "PT" && myBank->getMoney() >= 10)
                {
                    myBank->setMoney(myBank->getMoney() - 10);
                    myLair->AddTrap(x, y, type, 10, 10);
                }
                else if (myBank->getMoney() >= 5)
                {
                    myBank->setMoney(myBank->getMoney() - 5);
                    myLair->AddTrap(x, y, type, 5, 5);
                }
            }
            break;
        case 4:
            moneySpent = myResearch->researchList();
            myBank->setMoney(myBank->getMoney() - moneySpent);
            menu->incrementTrapsEnabled();
            break;
        case 5:
            cout << "Not implimented yet" << endl;
            break;
        case 6:
            this->myBank->displayMoney();
            break;
        case 7:
            myLair->displayBoard();
            break;
        case 8:
            exit = true;
            break;
        }
    }
}
