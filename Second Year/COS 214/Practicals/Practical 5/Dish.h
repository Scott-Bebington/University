#pragma once
using namespace std;
#include "Ingredients.h"

class Dish : public Meal{
private:
    Meal* thisMeal;
    Meal* next;
    int category;
    string name ;
    int min;
    int max;
    int cost;
    int amountIngredients;
public:
	Dish(string dis);
    void setNext(Meal* nextMeal);
    Meal* getNext();
    void removeNext();
    Meal* getMeal();
    // void addIngredient(Meal* m);
    // void removeIngredient(Meal* m);
    Meal* getChild(int child);
    string getName();
    int getCategory();
    int getMin();
    int getMax();
    int getCost();
    int getAmountIngredients();
    Meal* getThisMeal();
	~Dish();
};