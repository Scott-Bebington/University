
#pragma once
using namespace std;
#include "Meal.h"

class Ingredients : public Meal{
private:

    Meal* next = nullptr;
    Meal* thisMeal = nullptr;
    string name ;
    int category;
    int min;
    int max;
    int cost;

public:
    Ingredients(string ingre);
    void setNext(Meal* nextMeal);
    Meal* getNext();
    void removeNext();
    string getName();
     Meal* getChild(int child);
    int getCategory();
    int getMin();
    int getMax();
    int getCost();
     int getAmountIngredients();
    Meal* getThisMeal();
    


    ~Ingredients ();
};
