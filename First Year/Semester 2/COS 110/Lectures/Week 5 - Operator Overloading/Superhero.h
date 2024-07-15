#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

class Superhero : public Person
{
	public:
		Superhero(string n, string sp);
		~Superhero() {cout << "Superhero " << name << " destroyed\n"; }
		void saveTheWorld() const;
	protected:
		string superPower;
};

#endif
