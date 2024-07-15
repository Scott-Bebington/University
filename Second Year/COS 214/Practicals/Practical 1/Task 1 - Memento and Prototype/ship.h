#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>

using namespace std;

class ship {
public:

    ship();
    string shipName;
    int shipid;

    string getShipName();
    int getShipId();

    void setShipName(string);
    void setShipId(int);

    virtual void insertItem(string item) = 0;
    virtual void deleteItem(string item) = 0;;

    virtual string toString() = 0;

protected:
    virtual ship* clone() = 0;
};

#endif // SHIP_H
