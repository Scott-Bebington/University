#pragma once

#include <iostream>
#include <string>
class Order;
#include "Employee.h"

using namespace std;

class Chef: public Employee {
protected:
    Order *curOrder;
public:
    Chef();
    Order* getOrder();
    void setOrder(Order* order);
};





