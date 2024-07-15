#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

using namespace std;

class bank {
public:
    bank(int);
    int getMoney();
    void setMoney(int);
    void displayMoney();
private:
    int Money;
};

#endif  // BANK_H