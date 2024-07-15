#include "Accepted.h"
#include "Context.h"

#include <iostream>

using namespace std;

Accepted::Accepted() 
{
    update();
}

void Accepted::handleChange(Context *c)
{
    string* votes = c->getPeopleStatus();
    int numCompleted = 0;
    int countPeople = c->getNumPeople();
    for (int i = 0; i < countPeople; i++)
    {
        if (votes[i] == "Complete")
        {
            numCompleted++;
        }
    }

    if (numCompleted == countPeople)
    {
        c->setState(new Completed());
    }
}

std::string Accepted::getState() {
    return "Accepted";
}

void Accepted::update()
{
    cout << "Notification: State Change---------------------------------------------------" << endl;
    cout << "Contract is now in state: Accepted" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}
