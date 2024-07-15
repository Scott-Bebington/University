#include "Person.h"

Person::Person(string n)
{
	name = n;
	cout << "Person " << name << " created\n";
}

void Person::setName(string n)
{
	name = n;
}

string Person::getName() const
{
	return name;
}

void Person::sayHello() const
{
	cout << "Hello! My name is " << name;
	cout << ", and I am pleased to meet you." << endl;
}
