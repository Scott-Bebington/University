#pragma once
using namespace std;
#include "FoodBank.h"
#include <array>
#include <string>
#include <iostream>

class Meal {
private:
    Meal* thisMeal;
    Meal* next;
public:
	Meal();
    void setNext(Meal* meal);
    Meal* getNext();
    virtual Meal* getMeal();
    virtual void add(Meal m);
    virtual void remove(Meal m);
    virtual Meal* getChild(int child);
    virtual string getName();
    virtual int getCategory();
    virtual int getMin();
    virtual int getMax();
    virtual int getCost();
	~Meal();
};