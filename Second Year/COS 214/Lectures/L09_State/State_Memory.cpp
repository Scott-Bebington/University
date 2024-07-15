#include <iostream>
using namespace std;

class State;

class Context {
public:
    Context();
	~Context();
	void change();
  	string getColor();
	void setState(State* state);
  private: 
    State* state;
};

class State {
  public:
    virtual void handleChange(Context* c) = 0;
    virtual string getColor() = 0;
    virtual ~State();
};

State::~State() {
    cout << "State Destructor called" << endl;
}

class RedState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual string getColor();
};

class GreenState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual string getColor();
};

class AmberState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual string getColor();
};

Context::Context() {
	cout << "Constructor 1 called" << endl;
    state = new RedState();
}

Context::~Context() {
    cout << "Destructor called" << endl;
    delete state;
    state = 0;
}

void Context::setState(State* state_) {
    cout << "setState called" << endl;
    delete state;
    state = state_;
}

void Context::change() {
    state->handleChange(this);
}

string Context::getColor() {
    return state->getColor();
}

void RedState::handleChange(Context* c) {
    c->setState(new GreenState());
}

string RedState::getColor() {
    return "Red";
}

void AmberState::handleChange(Context* c) {
    c->setState(new RedState());
}

string AmberState::getColor() {
    return "Amber";
}

void GreenState::handleChange(Context* c) {
    c->setState(new AmberState());
}

string GreenState::getColor() {
    return "Green";

}

int main(){
    Context* context = new Context();
    for (int i = 0; i < 10; i++) {
        string currentTLcolour = context->getColor();
        cout << "Traffic light is currently: " << currentTLcolour << endl;
        context->change();
    }
    delete context;
    return 0; 
}
