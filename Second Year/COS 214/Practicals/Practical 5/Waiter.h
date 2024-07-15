#pragma once
#include "HeadChef.h"
#include <iostream>
// #include "Order.h"
// #include "Table.h"
#include "Database.h"
#include "Customer.h"

class Waiter : public Employee {
private:
    HeadChef* headChef;
    Database* database;
public:
    Waiter(Database* db);
    ~Waiter();
    void takeOrder(Order* o);
    void deliverOrder(Order* o);
    void notify(Order* o);
    void notifyTableAvailable();
    void notify(bool method, Order* o);
    void addToTab(Order* o);
    void payTab(Order* o);
    void createOrder(Customer* c);
    void handleRequest(Order*);
	int getID();
    
    
};

