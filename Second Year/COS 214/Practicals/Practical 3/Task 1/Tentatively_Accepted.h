#ifndef TENTATIVELY_ACCEPTED_H
#define TENTATIVELY_ACCEPTED_H

#include "State.h"
#include "Negotiation.h"
#include "Accepted.h"
#include "Rejected.h"

class Tentatively_Accepted : public State {
public:

    Tentatively_Accepted();
    virtual void handleChange(Context* c) override;
    virtual void update() override;
    virtual std::string getState() override;
};

#endif  // TENTATIVELY_ACCEPTED_H
