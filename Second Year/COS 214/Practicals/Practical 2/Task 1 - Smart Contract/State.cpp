#include "State.h"

using namespace std;

State::~State() {
}

class Negotiation : public State {
public:
    virtual void handleChange(Context* c) override;
    virtual string getState() override;
};

class Tentatively_Accepted : public State {
public:
    virtual void handleChange(Context* c) override;
    virtual string getState() override;
};
