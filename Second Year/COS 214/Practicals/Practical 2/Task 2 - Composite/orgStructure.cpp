#include "orgStructure.h"

using namespace std;

orgStructure::orgStructure() : _list() {}

void orgStructure::addIndividual(org *i)
{
    _list.push_back(i);
}

int orgStructure::getTotalExpenditure()
{
    return _list.front()->getTotalExpenditure();
}

int orgStructure::getExpenditureByCostCenter()
{
    int total = 0;
    for (list<org *>::iterator it = _list.begin(); it != _list.end(); ++it)
    {
        total += (*it)->getExpenditureByCostCenter();
    }
    return total;
}

void orgStructure::print()
{
    for (list<org *>::iterator it = _list.begin(); it != _list.end(); ++it)
    {
        (*it)->print();
    }
}
