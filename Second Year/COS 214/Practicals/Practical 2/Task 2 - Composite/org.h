#ifndef ORG_H
#define ORG_H

class org
{
public:
    org();
    virtual int getTotalExpenditure() = 0;
    virtual int getExpenditureByCostCenter() = 0;
    virtual void print() = 0;

    virtual ~org();

};

#endif
