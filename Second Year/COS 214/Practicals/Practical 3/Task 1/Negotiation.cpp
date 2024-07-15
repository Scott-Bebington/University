#include "Negotiation.h"
#include "Context.h"
#include <iostream>
#include <string>

using namespace std;

Negotiation::Negotiation()
{
    update();
}

void Negotiation::handleChange(Context *c)
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
    else if (numAccepted > 0)
    {
        c->setState(new Tentatively_Accepted());
    }
}

string Negotiation::getState() {
    return "Negotiation";
}

void Negotiation::update()
{
    cout << "Notification: State Change---------------------------------------------------" << endl;
    cout << "Contract is now in state: Negotiation" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}
