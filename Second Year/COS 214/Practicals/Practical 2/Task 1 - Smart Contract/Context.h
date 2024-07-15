#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include "Negotiation.h"

using namespace std;

class State;

class Context {
public:
    Context(string*, string, string*, int, int);
    ~Context();
    void change();

    // Setters
    void setState(State* state);
    void castVote(string, string);
    void addCondition(string);
    void removeCondition(string);
    void resetAcceptingParties();

    // Getters
    string* getPeople();
    string* getPeopleStatus();
    string* getConditions();
    int getNumPeople();
    int getNumConditions();

    // toString Method
    string toString();
private:
    State* state;
    string* People;
    string* PeopleStatus;
    string contractName;
    string* conditions;
    int numPeople;
    int numConditions;
};

#endif  // CONTEXT_H
