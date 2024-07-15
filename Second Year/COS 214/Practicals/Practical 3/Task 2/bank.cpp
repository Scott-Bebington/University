#include "bank.h"

bank::bank(int startMoney)
{
    Money = startMoney;
}

int bank::getMoney()
{
    return this->Money;
}

void bank::setMoney(int M)
{
    this->Money = M;
}

void bank::displayMoney()
{
    cout << endl;
    cout << "You have " << Money << " gold coins." << endl;
    cout << endl;
}
