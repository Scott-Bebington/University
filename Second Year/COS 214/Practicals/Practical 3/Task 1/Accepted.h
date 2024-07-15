#ifndef ACCEPTED_H
#define ACCEPTED_H

#include "State.h"
#include "Negotiation.h"
#include "Completed.h"

using namespace std;

class Accepted : public State {
public:

    Accepted();
    virtual void handleChange(Context* c) override;
    virtual void update() override;
    virtual string getState() override;
};

#endif  // ACCEPTED_H
