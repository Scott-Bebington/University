#ifndef NEWMATHS_H
#define NEWMATHS_H

#include "Target.h"
#include "MyMaths.h"

class NewMaths : public Target
{
public:
    NewMaths();
    NewMaths(int);
    virtual int operator+(int);
    virtual int operator*(int);
    virtual int operator=(int);
    ~NewMaths();
private:
    MyMaths<int>* adaptee;
    
};

#endif
