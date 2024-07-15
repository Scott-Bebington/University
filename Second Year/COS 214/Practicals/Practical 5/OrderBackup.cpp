#include "OrderBackup.h"

OrderBackup::OrderBackup(Meal* meals, string state, Customer* customer, int price) 
{
    this->meals = meals;
    this->state = state;
    this->customer = customer;
    this->price = price;
    this->next = nullptr;
}

OrderBackup::~OrderBackup() {

}

Meal* OrderBackup::getMeals() {
    return meals;
}

string OrderBackup::getState() {
    return state;
}

Customer* OrderBackup::getCustomer() {
    return customer;
}

int OrderBackup::getPrice() {
    return this->price;
}

OrderBackup* OrderBackup::getNext() {
    return next;
}

void OrderBackup::setNext(OrderBackup* ob) {
    next = ob;
}