#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person
{
	public:
		Person(string);
		~Person() { cout << "Person " << name << " destroyed\n"; }
		void setName(string);
		string getName() const;
		void sayHello() const;
	protected:
		string name;
};
#endif
