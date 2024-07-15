#ifndef NEGOTIATION_H
#define NEGOTIATION_H

#include "State.h"
#include "Tentatively_Accepted.h"
#include "Rejected.h"

using namespace std;

class Negotiation : public State {
public:
    Negotiation();
    virtual void handleChange(Context* c);
    virtual string getState();
};

#endif  // NEGOTIATION_H
