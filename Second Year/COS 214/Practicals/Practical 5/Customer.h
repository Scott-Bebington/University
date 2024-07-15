#pragma once

// #include "Person.h"
#include "Table.h"
// #include "Order.h"
// #include "Tab.h"

#include "Waiter.h"

// Included for now, lets see later

#include <thread>  
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>

using namespace std;

class Customer:public Person{
private:
	int cusId;
	int size;
	Table *table;
	void displayMenu();
	// Tab tab;

public:
	Customer(int size);
	void eat(Order* o);
	int getId();
	void enterRestaurant();
	void setTable(Table *t);
	void setSize(int s);
	int getSize();
	~Customer();
};