#pragma once
using namespace std;
class Customer;
#include "Dish.h"

class OrderBackup {
private:
        Meal* meals;		//head
        string state;
        Customer* customer;
        OrderBackup* next;
        int price;
public:
        OrderBackup(Meal* meals, string state, Customer* customer, int price);
        ~OrderBackup();

        Meal* getMeals();
        string getState();
        Customer* getCustomer();
        int getPrice();

        OrderBackup* getNext();
        void setNext(OrderBackup* ob);
};