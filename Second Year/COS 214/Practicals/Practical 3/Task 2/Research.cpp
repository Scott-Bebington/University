#include "Research.h"

research::research()
{
    this->trapsResearched = 0;
}

int research::researchList()
{
    cout << endl;
    cout << "Trap Research:" << endl;
    if (this->trapsResearched == 2)
        cout << "All traps researched" << endl;
    if (this->trapsResearched == 0 || this->trapsResearched == 1)
        cout << "Poison Trap (PT): 10 coins" << endl;
        cout << "Fire Trap (FT) : 20 coins" << endl;
    cout << endl;
    return researchTrap();
}

int research::researchTrap()
{
    cout << "Please select the trap you wish to research: ";
    string trap;
    cin >> trap;
    if (trap == "FT")
        return 20;
    if (trap == "PT")
        return 10;
    return 0;
}
