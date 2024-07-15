using namespace std;
#include "Tab.h"

Tab::Tab(int cId) {
	customerId = cId;
	total = 0;
	next = nullptr;
}

void Tab::addToTab(OrderBackup* ob) {
	//if Tab empty -> add new order to head of orders
	if (orders == nullptr) {
        orders = ob;
		total += ob->getPrice();	//Add price of new order to total
		return;
    }

	//Tab not empty -> go to last order
	OrderBackup* orderPtr = orders;
	while (orderPtr->getNext() != nullptr) {
        orderPtr = orderPtr->getNext();
    }
    orderPtr->setNext(ob);		//Add new order to tail of orders in tab
	total += ob->getPrice();	//Add price of new order to total
}

int Tab::getTotal() {
	return total;
}

Tab* Tab::getNext() {
	return next;
}

void Tab::setNext(Tab* t) {
	next = t;
}

int Tab::getCustId() {
	return customerId;
}

Tab::~Tab() {
	//if Tab empty -> just delete tab
	if (orders == nullptr) {
        delete orders;
        return;
    }

	//Tab not empty -> delete each order
	OrderBackup* temp = nullptr;
	while (orders->getNext() != nullptr) {
        temp = orders;
		orders = orders->getNext();
		delete temp;
    }

	//delete orders pointer
    delete orders;
}

