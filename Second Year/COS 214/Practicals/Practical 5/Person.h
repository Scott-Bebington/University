#pragma once
// #include "Waiter.h"
class Order;
class Waiter;

class Person{
private:
    Waiter *mediator;
protected:
    static int maxId;
    int id;
    Person();
    ~Person();
public:
    Waiter* getMediator();
    void setMediator(Waiter* w);
    int getID() { return id; }
};
