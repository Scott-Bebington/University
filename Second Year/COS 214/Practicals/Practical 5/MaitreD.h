#pragma once

class Employee;
class Customer;
#include "Table.h"
#include "Floor.h"
#include <vector>
#include <queue>

class MaitreD : public Employee
{
	private:
		std::queue<Customer*> bookings;
		std::queue<Customer*> queue;
		std::vector<Waiter*> waiters;
		Floor* floor;
	public:
		MaitreD(Floor* f);
		~MaitreD();
		Table* seat(Customer* c);
		void addBooking(Customer* c);
		void addQueue(Customer* c);
		bool checkAvailability();
		bool removeBooking(Customer* c);
		bool combine(Table* t1, Table* t2);
		bool split(Table* t);
		void assignWaiter(Waiter* w, Table* t);
		void notify();
};
