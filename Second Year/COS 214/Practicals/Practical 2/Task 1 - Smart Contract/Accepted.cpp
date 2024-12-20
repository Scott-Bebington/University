#include "Accepted.h"
#include "Context.h"

#include <iostream>

using namespace std;

Accepted::Accepted() 
{

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
}
