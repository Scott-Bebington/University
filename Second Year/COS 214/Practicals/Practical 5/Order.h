#pragma once
#include <string>
#include <iostream>
#include "OrderBackup.h"
using namespace std;

class Order {
private:
	Meal* head;		//head
	string state;
	Customer* customer;
	// Meal* next;
public:
	Order();
	Order(Customer* c);				//Construct empty order & assign customer
	~Order();

	void addMeal(string mealName);		//Add a meal to list
	bool removeMeal(string mealName);	//Remove meal from list - true if it was there - false if not
	
	Meal* getMeals();				//Returns meals linked list
	Meal* getMeal();					//Returns current meal
	Meal* getNextMeal();				//Returns next meal & set curMeal to next meal
	Meal* getHead() { return head; }
	
	Customer* getCustomer();			
	void setCustomer(Customer* c);

	// void addIngredient(string to,string ingre);
	// void removeIngredient(string from,string ingre);
	
	string getState();				
	void setState(string s);
	
	Order* getNextOrder();
	void setNextOrder(Order* o);
	OrderBackup* makeBackup();
	void restore(OrderBackup* ob);
	int getCat(string meal);
	string* getDishList();
	void printOrder();
};

//Linked list of meals