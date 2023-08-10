#ifndef ARCHENEMY_H
#define ARCHENEMY_H

#include <string>
#include <iostream>

#include "Superhero.h"

using namespace std;

class Archenemy : private Superhero
{
	public:
		Archenemy(string n, string sp);
		~Archenemy() {cout << "Archenemy " << getName() << " destroyed\n"; }
		void ruinTheWorld() const;
};

#endif
