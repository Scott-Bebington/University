#ifndef ORGSTRUCTURE_H
#define ORGSTRUCTURE_H

#include "org.h"
#include <list>

class orgStructure : public org
{
public:
    orgStructure();
    void addIndividual(org *i);
    int getTotalExpenditure();
    int getExpenditureByCostCenter();
    void print();

private:
    std::list<org *> _list;
};

#endif
