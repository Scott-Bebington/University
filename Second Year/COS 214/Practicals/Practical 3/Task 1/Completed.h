#ifndef COMPLETED_H
#define COMPLETED_H

#include "State.h"
#include "Completed.h"

class Completed : public State {
public:

    Completed();
    virtual void handleChange(Context* c) override;
    virtual void update() override;
    virtual std::string getState() override;
};

#endif  // COMPLETED_H
