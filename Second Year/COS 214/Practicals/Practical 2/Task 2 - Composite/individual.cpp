#include "individual.h"
#include <iostream>

using namespace std;

int individual::costCompany = 0;
int individual::uniqueIDGenerator = 0;

individual::individual(int cc, int co, string _name) : costCenter(cc), individualCostCompany(co), name(_name)
{
    uniqueID = uniqueIDGenerator++;
    costCompany += co;
}

int individual::getTotalExpenditure()
{
    return costCompany;
}

int individual::getExpenditureByCostCenter()
{
    return costCenter;
}

void individual::print()
{
    cout << "{" << endl;
    cout << "\tIndividual: " << name << endl;
    cout << "\tUnique ID: " << uniqueID << endl;
    cout << "\tCost to Center: " << costCenter << endl;
    cout << "\tCost to Company: " << individualCostCompany << endl;
    cout << "}," << endl;
}
