#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "org.h"
#include <string>

class individual : public org
{
public:
    individual(int cc, int co, std::string _name);
    int getTotalExpenditure();
    int getExpenditureByCostCenter();
    void print();

private:
    int uniqueID;
    static int uniqueIDGenerator;
    int costCenter;
    int individualCostCompany;
    static int costCompany;
    std::string name;
};

#endif
