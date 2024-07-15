#ifndef REJECTED_H
#define REJECTED_H

#include "State.h"
#include "Negotiation.h"
#include "Completed.h"

class Rejected : public State {
public:

    Rejected();
    virtual void handleChange(Context* c) override;
    virtual void update() override;
    virtual std::string getState() override;
};

#endif  // REJECTED_H
