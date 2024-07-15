#pragma once

#include <iostream>
#include <string>
#include "Chef.h"
#include "CategoryChef.h"
#include "Order.h"

using namespace std;

class HeadChef: public Chef {
private:
    CategoryChef* chefs;
public:
    static HeadChef* headChef;
    string type = "HeadChef";
    void startOrder(Order*);
    void delegateOrder(Order*);
    void plateOrder(Order*);
    void handleRequest(Order*);
    void notify(Order *o);
    static HeadChef* getHeadChef();
    HeadChef(CategoryChef*);
};


