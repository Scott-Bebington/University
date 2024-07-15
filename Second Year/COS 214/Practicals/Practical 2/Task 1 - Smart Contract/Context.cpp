#include "Context.h"
#include "State.h"
#include <iostream>
#include <string>

using namespace std;

Context::Context(string* People_, string contractName_, string* conditions_, int numPeople_, int numConditions_) {
    this->People = People_;
    this->contractName = contractName_;
    this->PeopleStatus = new string[People_->size()];

    for (size_t i = 0; i < People_->size(); i++) {
        this->PeopleStatus[i] = "Negotiation";
    }

    this->conditions = conditions_;
    this->numPeople = numPeople_;
    this->numConditions = numConditions_;
    this->state = new Negotiation();
}

void Context::castVote(string name, string vote)
{
    if (vote == "Complete" && 
    (this->state->getState() == "Negotiation" || this->state->getState() == "Tentatively Accepted"))
    {
        cout << "\033[31mError: cannot complete contract until all parties have agreed to the contract\033[0m" << endl;
        return;
    }

    if (this->state->getState() == "Accepted" && vote != "Complete")
    {
        cout << "\033[31mError: cannot change vote once contract has been accepted\033[0m" << endl;
        return;
    }

    if (this->state->getState() == "Completed")
    {
        cout << "\033[31mError: cannot change vote once contract has been completed\033[0m" << endl;
        return;
    }

    if (this->state->getState() == "Rejected")
    {
        cout << "\033[31mError: cannot change vote once contract has been rejected\033[0m" << endl;
        return;
    }

    for (int i = 0; i < this->numPeople; i++)
    {
        if (People[i] == name)
        {
            PeopleStatus[i] = vote;
        }
    }
    change();
}

void Context::addCondition(string newCondition)
{
    // Check to see if the contract is in a state that allows for the addition of a condition
    if (this->state->getState() == "Accepted" || this->state->getState() == "Completed" || this->state->getState() == "Rejected")
    {
        cout << "\033[31mError: cannot add condition to contract that has been accepted / rejected or completed\033[0m" << endl;
        return;
    }


    string* temp = new string[this->numConditions + 1];
    for (int i = 0; i < this->numConditions; i++)
    {
        temp[i] = this->conditions[i];
    }
    temp[this->numConditions] = newCondition;
    this->numConditions++;
    this->conditions = temp;

    if(this->state->getState() == "Tentatively Accepted")
    {
        this->resetAcceptingParties();
        this->change();
    }
}

void Context::removeCondition(string removeCondition)
{
    // Check to see if the contract is in a state that allows for the removal of a condition
    if (this->state->getState() == "Accepted" || this->state->getState() == "Completed" || this->state->getState() == "Rejected")
    {
        cout << "\033[31mError: cannot add condition to contract that has been accepted / rejected or completed\033[0m" << endl;
        return;
    }

    // Check to see if the condition exists
    int index = -1;
    for (int i = 0; i < this->numConditions; i++)
    {
        if (this->conditions[i] == removeCondition)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "Condition: '" + removeCondition + "' not found" << endl;
        return;
    }
    
    // Remove the condition
    string* temp = new string[this->numConditions - 1];
    for (int i = 0; i < this->numConditions; i++)
    {
        if (i < index)
        {
            temp[i] = this->conditions[i];
        }
        else if (i > index)
        {
            temp[i - 1] = this->conditions[i];
        }
    }
    this->numConditions--;
    this->conditions = temp;

    // Check to see if the contract is in a state that requires a change
    if(this->state->getState() == "Tentatively Accepted")
    {
        this->resetAcceptingParties();
        this->change();
    }
}

void Context::resetAcceptingParties()
{
    for (int i = 0; i < this->numPeople; i++)
    {
        this->PeopleStatus[i] = "Negotiation";
    }
}

string *Context::getPeople()
{
    return this->People;
}

string *Context::getPeopleStatus()
{
    return this->PeopleStatus;
}

string *Context::getConditions()
{
    return this->conditions;
}

int Context::getNumPeople()
{
    return this->numPeople;
}

int Context::getNumConditions()
{
    return this->numConditions;
}

string Context::toString()
{
    string str = "Contract " + this->contractName + ":\n";
    str += "\tState: " + this->state->getState() + "\n";

    if (this->state->getState() == "Tentatively Accepted" || this->state->getState() == "Accepted")
    {
        str += "\tvotes:\n";
        for (int i = 0; i < this->numPeople; i++)
        {
            str += "\t\t" + this->People[i] + ":\t" + this->PeopleStatus[i] + "\n";
        }
    }

    str += "\tConditions:\n";
    for (int i = 0; i < this->numConditions; i++)
    {
        str += "\t\t" + this->conditions[i] + "\n";
    }

    return str;
}

Context::~Context() {
    delete state;
    state = nullptr;
}

void Context::setState(State* state_) {
    delete state;
    state = state_;
}

void Context::change() {
    state->handleChange(this);
}

