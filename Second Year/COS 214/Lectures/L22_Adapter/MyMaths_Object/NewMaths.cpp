#include <iostream>

#include "MyMaths.h"
#include "NewMaths.h"

using namespace std;

NewMaths::NewMaths()
{
    adaptee = new MyMaths<int>(0,0);
    
}

NewMaths::NewMaths(int v)
{
    adaptee = new MyMaths<int>(v,0);
}

int NewMaths::operator+(int i)
{
    adaptee->setY(i);
    return adaptee->add();
}

int NewMaths::operator*(int){
    
}

int NewMaths::operator=(int v){
    adaptee->setX(v);
    return v;
    
}

NewMaths::~NewMaths()
{
    delete adaptee;
}