#include "Person.h"
#include "Superhero.h"
#include "Archenemy.h"

#include <iostream>
using namespace std;

int main() 
{
	Person bob("Bob");
	bob.sayHello();
	
	cout << endl;
	
	Superhero superman("Superman", "the power of flight");
	superman.sayHello();
	superman.saveTheWorld();
	
	cout << endl;
	
	Archenemy madScientist("Mad Scientist", "a massive nuclear weapon");
	//madScientist.sayHello();
	//madScientist.saveTheWorld();
	madScientist.ruinTheWorld();
	
	cout << endl;
	
	return 0;
}