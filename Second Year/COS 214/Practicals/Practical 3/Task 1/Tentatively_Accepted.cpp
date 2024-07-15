#include "Tentatively_Accepted.h"
#include "Context.h"

#include <iostream>

using namespace std;

Tentatively_Accepted::Tentatively_Accepted() 
{
    update();
}

void Tentatively_Accepted::handleChange(Context *c)
{
    int numAccepted = 0;
    int numRejected = 0;
    int numPeople = c->getNumPeople();
    string *PeopleStatus = c->getPeopleStatus();
    for (int i = 0; i < numPeople; i++)
    {
        if (PeopleStatus[i] == "Accepted")
        {
            numAccepted++;
        }
        if (PeopleStatus[i] == "Rejected")
        {
            numRejected++;
        }
    }

    if(numRejected > 0)
    {
        c->setState(new Rejected());
    }
    else if (numAccepted == numPeople)
    {
        c->setState(new Accepted());
    }
    else if(numAccepted == 0)
    {
        c->setState(new Negotiation());
    }
}

std::string Tentatively_Accepted::getState() 
{
    return "Tentatively Accepted";
}

void Tentatively_Accepted::update()
{
    cout << "Notification: State Change---------------------------------------------------" << endl;
    cout << "Contract is now in state: Tentatively Accepted" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}
