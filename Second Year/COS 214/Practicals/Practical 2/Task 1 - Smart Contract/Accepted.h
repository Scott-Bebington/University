#ifndef ACCEPTED_H
#define ACCEPTED_H

#include "State.h"
#include "Negotiation.h"
#include "Completed.h"

class Accepted : public State {
public:

    Accepted();
    virtual void handleChange(Context* c) override;
    virtual std::string getState() override;
};

#endif  // ACCEPTED_H
